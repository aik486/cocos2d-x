/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "2d/CCAtlasNode.h"
#include <stddef.h> // offsetof
#include "base/ccTypes.h"
#include "renderer/CCTextureAtlas.h"
#include "base/CCDirector.h"
#include "renderer/CCTextureCache.h"
#include "base/ccUtils.h"
#include "renderer/ccShaders.h"
#include "renderer/CCRenderer.h"
#include "renderer/backend/ProgramState.h"

NS_CC_BEGIN

// implementation AtlasNode

// AtlasNode - Creation & Init

AtlasNode::AtlasNode()
{
    auto& pipelineDescriptor = _quadCommand.getPipelineDescriptor();
    auto* program = backend::Program::getBuiltinProgram(backend::ProgramType::POSITION_TEXTURE_COLOR);
    _programState = new (std::nothrow) backend::ProgramState(program);
    pipelineDescriptor.programState = _programState;
    _mvpMatrixLocation = pipelineDescriptor.programState->getUniformLocation("u_MVPMatrix");
    _textureLocation = pipelineDescriptor.programState->getUniformLocation("u_texture");
  
    auto vertexLayout = _programState->getVertexLayout();
  //a_position
    vertexLayout->setAttribute(backend::ATTRIBUTE_NAME_POSITION, 
                               _programState->getAttributeLocation(backend::Attribute::POSITION), 
                               backend::VertexFormat::FLOAT3, 
                               0, 
                               false);
   
    //a_texCoord
    vertexLayout->setAttribute(backend::ATTRIBUTE_NAME_TEXCOORD, 
                               _programState->getAttributeLocation(backend::Attribute::TEXCOORD), 
                               backend::VertexFormat::FLOAT2, offsetof(V3F_C4B_T2F, texCoords), 
                               false);
   
    //a_color
    vertexLayout->setAttribute(backend::ATTRIBUTE_NAME_COLOR, 
                               _programState->getAttributeLocation(backend::Attribute::COLOR),
                               backend::VertexFormat::UBYTE4, offsetof(V3F_C4B_T2F, colors),
                               true);
    
    vertexLayout->setLayout(sizeof(V3F_C4B_T2F));
}

AtlasNode::~AtlasNode()
{
    CC_SAFE_RELEASE(_textureAtlas);
}

AtlasNode * AtlasNode::create(const std::string& tile, int tileWidth, int tileHeight, int itemsToRender)
{
    AtlasNode * ret = new (std::nothrow) AtlasNode();
    if (ret->initWithTileFile(tile, tileWidth, tileHeight, itemsToRender))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool AtlasNode::initWithTileFile(const std::string& tile, int tileWidth, int tileHeight, int itemsToRender)
{
    CCASSERT(tile.size() > 0, "file size should not be empty");
    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(tile);
    return initWithTexture(texture, tileWidth, tileHeight, itemsToRender);
}

bool AtlasNode::initWithTexture(Texture2D* texture, int tileWidth, int tileHeight, int itemsToRender)
{
    _itemWidth  = tileWidth;
    _itemHeight = tileHeight;

    _isOpacityModifyRGB = true;

    _blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;

    _textureAtlas = new (std::nothrow) TextureAtlas();

    if (! _textureAtlas)
    {
        CCLOG("cocos2d: Could not initialize AtlasNode. Invalid Texture.");
        return false;
    }
    
    _textureAtlas->initWithTexture(texture, itemsToRender);

    this->updateBlendFunc();

    this->calculateMaxItems();

    _quadsToDraw = itemsToRender;

    return true;
}

// AtlasNode - Atlas generation

void AtlasNode::calculateMaxItems()
{
    Size s = _textureAtlas->getTexture()->getContentSize();
    
    if (_ignoreContentScaleFactor)
    {
        s = _textureAtlas->getTexture()->getContentSizeInPixels();
    }
    
    _itemsPerColumn = (int)(s.height / _itemHeight);
    _itemsPerRow = (int)(s.width / _itemWidth);
}

void AtlasNode::updateAtlasValues()
{
    CCASSERT(false, "CCAtlasNode:Abstract updateAtlasValue not overridden");
}

// AtlasNode - draw
void AtlasNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{    
    if( _textureAtlas->getTotalQuads() == 0 )
        return;
    
    auto programState = _quadCommand.getPipelineDescriptor().programState;
    programState->setTexture(_textureLocation, 0, _textureAtlas->getTexture()->getBackendTexture());
    
    const auto& projectionMat = Director::getInstance()->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    programState->setUniform(_mvpMatrixLocation, projectionMat.m, sizeof(projectionMat.m));
    
    _quadCommand.init(_globalZOrder, _textureAtlas->getTexture(), _blendFunc, _textureAtlas->getQuads(), _quadsToDraw, transform, flags);
    renderer->addCommand(&_quadCommand);
}

// AtlasNode - RGBA protocol

void AtlasNode::setOpacityModifyRGB(bool value)
{
    if (_isOpacityModifyRGB == value) {
        _isOpacityModifyRGB = value;
        updateColor();
    }
}

bool AtlasNode::isOpacityModifyRGB() const
{
    return _isOpacityModifyRGB;
}

void AtlasNode::setIgnoreContentScaleFactor(bool ignoreContentScaleFactor)
{
    _ignoreContentScaleFactor = ignoreContentScaleFactor;
}

// AtlasNode - CocosNodeTexture protocol

const BlendFunc& AtlasNode::getBlendFunc() const
{
    return _blendFunc;
}

void AtlasNode::setBlendFunc(const BlendFunc &blendFunc)
{
    _blendFunc = blendFunc;
}

void AtlasNode::updateBlendFunc()
{
    if( ! _textureAtlas->getTexture()->hasPremultipliedAlpha() )
    {
        _blendFunc = BlendFunc::ALPHA_NON_PREMULTIPLIED;
        setOpacityModifyRGB(false);
    }
    else
    {
        _blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;
        setOpacityModifyRGB(true);
    }
}

void AtlasNode::setTexture(Texture2D *texture)
{
    _textureAtlas->setTexture(texture);
    this->updateBlendFunc();
}

Texture2D * AtlasNode::getTexture() const
{
    return _textureAtlas->getTexture();
}

void AtlasNode::setTextureAtlas(TextureAtlas* textureAtlas)
{
    CC_SAFE_RETAIN(textureAtlas);
    CC_SAFE_RELEASE(_textureAtlas);
    _textureAtlas = textureAtlas;
}

TextureAtlas * AtlasNode::getTextureAtlas() const
{
    return _textureAtlas;
}

size_t AtlasNode::getQuadsToDraw() const
{
    return _quadsToDraw;
}

void AtlasNode::setQuadsToDraw(ssize_t quadsToDraw)
{
    _quadsToDraw = quadsToDraw;
}

NS_CC_END
