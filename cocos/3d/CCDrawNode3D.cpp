/****************************************************************************
 Copyright (c) 2014-2016 Chukong Technologies Inc.
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

#include "CCDrawNode3D.h"
#include "renderer/backend/Buffer.h"
#include "renderer/CCRenderer.h"
#include "base/CCDirector.h"

NS_CC_BEGIN

#define INITIAL_VERTEX_BUFFER_LENGTH 12 * 2

DrawNode3D::DrawNode3D()
{
    _blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;
}

DrawNode3D::~DrawNode3D()
{
    CC_SAFE_RELEASE_NULL(_programStateLine);
    CC_SAFE_DELETE(_depthstencilDescriptor);
}

DrawNode3D* DrawNode3D::create()
{
    DrawNode3D* ret = new (std::nothrow) DrawNode3D();
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    
    return ret;
}

void DrawNode3D::ensureCapacity(int count)
{
    CCASSERT(count>=0, "capacity must be >= 0");
    
    auto EXTENDED_SIZE = _bufferLines.size() + count;

    _bufferLines.reserve(EXTENDED_SIZE);

}

bool DrawNode3D::init()
{
    _blendFunc = BlendFunc::ALPHA_PREMULTIPLIED;
    auto &pd = _customCommand.getPipelineDescriptor();
    auto program = backend::Program::getBuiltinProgram(backend::ProgramType::LINE_COLOR_3D);
    CC_SAFE_RELEASE(_programStateLine);
    _programStateLine = new backend::ProgramState(program);
    pd.programState = _programStateLine;
    
    _locMVPMatrix = _programStateLine->getUniformLocation("u_MVPMatrix");

    _customCommand.setBeforeCallback(CC_CALLBACK_0(DrawNode3D::onBeforeDraw, this));
    _customCommand.setAfterCallback(CC_CALLBACK_0(DrawNode3D::onAfterDraw, this));

    auto layout = _programStateLine->getVertexLayout();

    ensureCapacity(INITIAL_VERTEX_BUFFER_LENGTH);

    clear();
    
    _customCommand.setDrawType(CustomCommand::DrawType::ARRAY);
    _customCommand.setPrimitiveType(CustomCommand::PrimitiveType::LINE);

    const auto& attributeInfo = _programStateLine->getProgram()->getActiveAttributes();
    auto iter = attributeInfo.find("a_position");
    if(iter != attributeInfo.end())
    {
        layout->setAttribute("a_position", iter->second.location, backend::VertexFormat::FLOAT3, 0, false);
    }
    iter = attributeInfo.find("a_color");
    if(iter != attributeInfo.end())
    {
        layout->setAttribute("a_color", iter->second.location, backend::VertexFormat::UBYTE4, sizeof(Vec3), true);
    }
    layout->setLayout(sizeof(V3F_C4B));
    
#if CC_ENABLE_CACHE_TEXTURE_DATA
    // Need to listen the event only when not use batchnode, because it will use VBO
    auto listener = EventListenerCustom::create(EVENT_COME_TO_FOREGROUND, [this](EventCustom* event){
    /** listen the event that coming to foreground on Android */
        this->init();
    });

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif
    
    return true;
}

void DrawNode3D::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder, transform, flags);

    updateCommand(transform);

    auto vertexBuffer = _customCommand.getVertexBuffer();
    size_t oldCapacity = vertexBuffer ? vertexBuffer->getSize() : 0;
    auto newCapacity = _bufferLines.capacity() * sizeof(V3F_C4B);
    if (oldCapacity != newCapacity)
    {
        if (newCapacity > 0) {
            _customCommand.createVertexBuffer(sizeof(V3F_C4B), _bufferLines.capacity(), CustomCommand::BufferUsage::DYNAMIC);
            _customCommand.updateVertexBuffer(_bufferLines.data(), newCapacity);
        } else {
            _customCommand.setVertexBuffer(nullptr);
        }
        
        oldLineCount = _bufferLines.size();
    }
        
    if (oldLineCount < _bufferLines.size()) {
        size_t count = _bufferLines.size() - oldLineCount;
        size_t bufferSize = count * sizeof(V3F_C4B);
        size_t offset = oldLineCount * sizeof(V3F_C4B);
        _customCommand.updateVertexBuffer(_bufferLines.data() + oldLineCount, offset, bufferSize);
        oldLineCount = _bufferLines.size();
    }

    _customCommand.setVertexDrawInfo(0, _bufferLines.size());
    if (!_bufferLines.empty())
    {
        renderer->addCommand(&_customCommand);
    }
}

void DrawNode3D::updateCommand(const Mat4 &transform)
{
    auto &matrixP = Director::getInstance()->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    auto mvp = matrixP * transform;

    _programStateLine->setUniform(_locMVPMatrix, mvp.m, sizeof(mvp.m));


    auto &blend = _customCommand.getPipelineDescriptor().blendDescriptor;
    blend.blendEnabled = true;
    blend.sourceRGBBlendFactor = blend.sourceAlphaBlendFactor = _blendFunc.src;
    blend.destinationRGBBlendFactor = blend.destinationAlphaBlendFactor = _blendFunc.dst;

    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, _bufferLines.size());
}

void DrawNode3D::drawLine(const Vec3 &from, const Vec3 &to, const Color4B &color)
{
    unsigned int vertex_count = 2;
    ensureCapacity(vertex_count);
    
    V3F_C4B a = {Vec3(from.x, from.y, from.z), color};
    V3F_C4B b = {Vec3(to.x, to.y, to.z), color, };

    _bufferLines.push_back(a);
    _bufferLines.push_back(b);
}

void DrawNode3D::drawCube(const AABB &aabb, const Color4B &color)
{
    if (aabb.isEmpty()) {
        return;
    }
    
    Vec3 corners[8];
    aabb.getCorners(corners);
    drawCube(corners, color);
}

void DrawNode3D::drawCube(const OBB &obb, const Color4B &color)
{
    Vec3 corners[8];
    obb.getCorners(corners);
    drawCube(corners, color);
}

void DrawNode3D::drawCube(const Vec3 &from, const Vec3 &to, const Color4B &color)
{   
    AABB aabb;
    aabb.updateMinMax(&from, 1);
    aabb.updateMinMax(&to, 1);
    drawCube(aabb, color);
}

void DrawNode3D::drawCube(Vec3* vertices, const Color4B &color)
{
    // front face
    drawLine(vertices[0], vertices[1], color);
    drawLine(vertices[1], vertices[2], color);
    drawLine(vertices[2], vertices[3], color);
    drawLine(vertices[3], vertices[0], color);
    
    // back face
    drawLine(vertices[4], vertices[5], color);
    drawLine(vertices[5], vertices[6], color);
    drawLine(vertices[6], vertices[7], color);
    drawLine(vertices[7], vertices[4], color);
    
    // edge
    drawLine(vertices[0], vertices[7], color);
    drawLine(vertices[1], vertices[6], color);
    drawLine(vertices[2], vertices[5], color);
    drawLine(vertices[3], vertices[4], color);
}

void DrawNode3D::clear()
{
    _bufferLines.clear();
    oldLineCount = 0;
}

const BlendFunc& DrawNode3D::getBlendFunc() const
{
    return _blendFunc;
}

void DrawNode3D::setBlendFunc(const BlendFunc &blendFunc)
{
    _blendFunc = blendFunc;
}


void DrawNode3D::onBeforeDraw()
{
    auto *renderer = _director->getRenderer();
    _rendererDepthTestEnabled = renderer->getDepthTest();
    renderer->setDepthTest(true);
}

void DrawNode3D::onAfterDraw()
{
    auto *renderer = _director->getRenderer();
    renderer->setDepthTest(_rendererDepthTestEnabled);
}


NS_CC_END
