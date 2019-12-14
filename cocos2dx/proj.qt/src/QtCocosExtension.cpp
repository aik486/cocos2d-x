#include "QtCocosExtension.h"

#include "cocos2dx_qt.h"

static const GLchar ccPositionTextureColor_frag[] = "\
#ifdef GL_ES																\n\
precision lowp float;														\n\
#endif																		\n\
																			\n\
varying vec4 v_fragmentColor;												\n\
varying vec4 v_fragmentAdditiveColor;										\n\
varying vec2 v_texCoord;													\n\
uniform sampler2D CC_Texture0;												\n\
																			\n\
void main()																	\n\
{																			\n\
	gl_FragColor = v_fragmentColor * texture2D(CC_Texture0, v_texCoord);	\n\
	gl_FragColor.rgb += v_fragmentAdditiveColor.rgb;						\n\
}																			\n\
";

static const GLchar ccPositionTextureColor_vert[] = "\
attribute vec4 a_position;											\n\
attribute vec2 a_texCoord;                                          \n\
attribute vec4 a_color;                                             \n\
attribute vec4 a_colorAdd;                                          \n\
																	\n\
#ifdef GL_ES                                                        \n\
varying lowp vec4 v_fragmentColor;                                  \n\
varying lowp vec4 v_fragmentAdditiveColor;                          \n\
varying mediump vec2 v_texCoord;                                    \n\
#else                                                               \n\
varying vec4 v_fragmentColor;                                       \n\
varying vec4 v_fragmentAdditiveColor;                               \n\
varying vec2 v_texCoord;                                            \n\
#endif                                                              \n\
																	\n\
void main()                                                         \n\
{                                                                   \n\
	gl_Position = CC_MVPMatrix * a_position;                        \n\
	v_fragmentColor = a_color;                                      \n\
	v_fragmentAdditiveColor = a_colorAdd;                           \n\
	v_texCoord = a_texCoord;                                        \n\
}                                                                   \n\
";

namespace cocos2d
{
static const char kShaderPositionTextureColorEx[] =
	"ShaderPositionTextureColorEx";
static CCGLProgram *getShaderPositionTextureColorEx()
{
	auto shaderCache = CCShaderCache::sharedShaderCache();
	auto program = shaderCache->programForKey(kShaderPositionTextureColorEx);

	if (nullptr == program)
	{
		program = new CCGLProgram;

		program->initWithVertexShaderByteArray(
			::ccPositionTextureColor_vert, ::ccPositionTextureColor_frag);

		program->addAttribute(
			kCCAttributeNamePosition, kCCVertexAttrib_Position);
		program->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
		program->addAttribute(
			kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
		program->addAttribute("a_colorAdd", kCCVertexAttrib_MAX);

		program->link();
		program->updateUniforms();

		shaderCache->addProgram(program, kShaderPositionTextureColorEx);
	}

	return program;
}

CCAdditiveColor::CCAdditiveColor(CCNode *node)
	: thiz(node)
	, mCascadeAddColor(false)
{
	mAdditiveColor = { 0, 0, 0 };
	mDisplayedAddColor = { 0, 0, 0 };
}

void CCAdditiveColor::setCascadeAddColor(bool enabled)
{
	if (enabled == mCascadeAddColor)
		return;

	mCascadeAddColor = enabled;

	updateCascadeAddColor();
}

void CCAdditiveColor::updateCascadeAddColor()
{
	ccColor3B parentAddColor = { 0, 0, 0 };

	if (mCascadeAddColor)
	{
		if (thiz != nullptr)
		{
			auto parent = dynamic_cast<CCAdditiveColor *>(thiz->getParent());

			if (parent && parent->isCascadeAddColor())
			{
				parentAddColor = parent->getDisplayedAdditiveColor();
			}
		}

		updateDisplayedAddColor(parentAddColor);
	} else
	{
		mDisplayedAddColor = mAdditiveColor;
		updateAdditiveColor();

		if (nullptr != thiz)
		{
			auto children = thiz->getChildren();
			CCObject *obj = nullptr;
			CCARRAY_FOREACH(children, obj)
			{
				auto item = dynamic_cast<CCAdditiveColor *>(obj);

				if (item)
				{
					item->updateDisplayedAddColor(parentAddColor);
				}
			}
		}
	}
}

void CCAdditiveColor::setAdditiveColor(const cocos2d::ccColor3B &color)
{
	mDisplayedAddColor = mAdditiveColor = color;

	updateCascadeAddColor();
}

const ccColor3B &CCAdditiveColor::getAdditiveColor()
{
	return mAdditiveColor;
}

void CCAdditiveColor::resetDisplayedAdditiveColor(ccColor4B *setTo)
{
	memset(setTo, 0, sizeof(ccColor4B) * RECT_VERTEX_COUNT);
}

void CCAdditiveColor::setAdditiveColorTo(const ccColor3B &color,
	ccColor4B *setTo, size_t count, bool opacityModifyRGB,
	uint8_t displayedOpacity)
{
	if (count == 0)
		return;

	setTo[0] = { color.r, color.g, color.b, 0 };

	auto &cl = setTo[0];

	if (opacityModifyRGB)
	{
		cl.r = GLubyte((cl.r * displayedOpacity) / 255);
		cl.g = GLubyte((cl.g * displayedOpacity) / 255);
		cl.b = GLubyte((cl.b * displayedOpacity) / 255);
	}

	for (size_t i = 1; i < count; i++)
	{
		setTo[i] = cl;
	}
}

void CCAdditiveColor::updateDisplayedAddColor(const ccColor3B &parentColor)
{
	mDisplayedAddColor.r = uint8_t(
		std::min(255, std::max<int>(0, mAdditiveColor.r + parentColor.r)));
	mDisplayedAddColor.g = uint8_t(
		std::min(255, std::max<int>(0, mAdditiveColor.g + parentColor.g)));
	mDisplayedAddColor.b = uint8_t(
		std::min(255, std::max<int>(0, mAdditiveColor.b + parentColor.b)));

	updateAdditiveColor();

	if (mCascadeAddColor && thiz)
	{
		auto children = thiz->getChildren();
		CCObject *obj = nullptr;
		CCARRAY_FOREACH(children, obj)
		{
			auto item = dynamic_cast<CCAdditiveColor *>(obj);

			if (item)
			{
				item->updateDisplayedAddColor(mDisplayedAddColor);
			}
		}
	}
}

CCSpriteEx::CCSpriteEx()
	: CCAdditiveColor(this)
{
	resetDisplayedAdditiveColor(mDisplayedAdditiveColor);
}

CCSpriteEx *CCSpriteEx::create()
{
	auto result = new CCSpriteEx;

	if (nullptr != result)
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

CCSpriteEx *CCSpriteEx::createWithSpriteFrame(CCSpriteFrame *frame)
{
	auto sprite = new CCSpriteEx;

	if (frame && sprite && sprite->initWithSpriteFrame(frame))
	{
		sprite->autorelease();
		return sprite;
	}

	delete sprite;
	return nullptr;
}

void CCSpriteEx::updateAdditiveColor()
{
	setAdditiveColorTo(mDisplayedAddColor, mDisplayedAdditiveColor,
		RECT_VERTEX_COUNT, isOpacityModifyRGB(), _displayedOpacity);
}

void CCSpriteEx::setShaderProgram(CCGLProgram *pShaderProgram)
{
	auto program = CCShaderCache::sharedShaderCache()->programForKey(
		kCCShader_PositionTextureColor);

	if (pShaderProgram == program)
	{
		pShaderProgram = getShaderPositionTextureColorEx();
	}

	CCSprite::setShaderProgram(pShaderProgram);
}

void CCSpriteEx::updateBlendFunc()
{
	CCSprite::updateBlendFunc();
}

void CCSpriteEx::draw()
{
	CC_NODE_DRAW_SETUP();

	ccGLBlendFunc(m_sBlendFunc.src, m_sBlendFunc.dst);

	ccGLBindTexture2D(m_pobTexture->getName());
	ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);

	glEnableVertexAttribArray(kCCVertexAttrib_MAX);

#define kQuadSize sizeof(m_sQuad.bl)
#ifdef EMSCRIPTEN
	long offset = 0;
	setGLBufferData(&m_sQuad, 4 * kQuadSize, 0);
#else
	uintptr_t offset = (uintptr_t) &m_sQuad;
#endif // EMSCRIPTEN

	int diff = offsetof(ccV3F_C4B_T2F, vertices);
	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE,
		kQuadSize, (void *) (offset + diff));

	// texCoods
	diff = offsetof(ccV3F_C4B_T2F, texCoords);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE,
		kQuadSize, (void *) (offset + diff));

	// color
	diff = offsetof(ccV3F_C4B_T2F, colors);
	glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE,
		kQuadSize, (void *) (offset + diff));

	// additive_color
	glVertexAttribPointer(kCCVertexAttrib_MAX, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0,
		(void *) &mDisplayedAdditiveColor);

#undef kQuadSize

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableVertexAttribArray(kCCVertexAttrib_MAX);

	CHECK_GL_ERROR_DEBUG();

	CC_INCREMENT_GL_DRAWS(1);
}

CCClippingNodeRGBA::CCClippingNodeRGBA()
	: mDisplayedOpacity(255)
	, mRealOpacity(255)
	, mDisplayedColor(ccWHITE)
	, mRealColor(ccWHITE)
	, mCascadeColorEnabled(false)
	, mCascadeOpacityEnabled(false)
	, mClearStencil(true)
{
}

CCClippingNodeRGBA *CCClippingNodeRGBA::create(CCNode *stencil)
{
	auto result = new CCClippingNodeRGBA;

	if (nullptr != result && result->init(stencil))
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

void CCClippingNodeRGBA::setClearStencil(bool value)
{
	mClearStencil = value;
}

void CCClippingNodeRGBA::visit()
{
	if (m_pStencil->isVisible())
	{
		if (mClearStencil)
			glClear(GL_STENCIL_BUFFER_BIT);

		CCClippingNode::visit();
	} else
	{
		CCNode::visit();
	}
}

bool CCClippingNodeRGBA::init(CCNode *pStencil)
{
	if (CCClippingNode::init(pStencil))
	{
		mDisplayedOpacity = mRealOpacity = 255;
		mDisplayedColor = mRealColor = ccWHITE;
		mCascadeOpacityEnabled = mCascadeColorEnabled = false;
		return true;
	}

	return false;
}

void CCClippingNodeRGBA::setColor(const ccColor3B &color)
{
	mDisplayedColor = mRealColor = color;

	if (mCascadeColorEnabled)
	{
		ccColor3B parentColor = ccWHITE;
		auto parentProtocol = dynamic_cast<CCRGBAProtocol *>(m_pParent);

		if (parentProtocol && parentProtocol->isCascadeColorEnabled())
		{
			parentColor = parentProtocol->getDisplayedColor();
		}

		updateDisplayedColor(parentColor);
	}
}

const ccColor3B &CCClippingNodeRGBA::getColor()
{
	return mRealColor;
}

const ccColor3B &CCClippingNodeRGBA::getDisplayedColor()
{
	return mDisplayedColor;
}

GLubyte CCClippingNodeRGBA::getDisplayedOpacity()
{
	return mDisplayedOpacity;
}

GLubyte CCClippingNodeRGBA::getOpacity()
{
	return mRealOpacity;
}

void CCClippingNodeRGBA::setOpacity(GLubyte opacity)
{
	mDisplayedOpacity = mRealOpacity = opacity;

	if (mCascadeOpacityEnabled)
	{
		GLubyte parentOpacity = 255;
		auto parentProtocol = dynamic_cast<CCRGBAProtocol *>(m_pParent);

		if (parentProtocol && parentProtocol->isCascadeOpacityEnabled())
		{
			parentOpacity = parentProtocol->getDisplayedOpacity();
		}

		this->updateDisplayedOpacity(parentOpacity);
	}
}

void CCClippingNodeRGBA::setOpacityModifyRGB(bool)
{
	// do nothing
}

bool CCClippingNodeRGBA::isOpacityModifyRGB()
{
	return false;
}

bool CCClippingNodeRGBA::isCascadeColorEnabled()
{
	return mCascadeColorEnabled;
}

void CCClippingNodeRGBA::setCascadeColorEnabled(bool cascadeColorEnabled)
{
	mCascadeColorEnabled = cascadeColorEnabled;
}

void CCClippingNodeRGBA::updateDisplayedColor(const ccColor3B &parentColor)
{
	mDisplayedColor.r = GLubyte((mRealColor.r * parentColor.r) / 255);
	mDisplayedColor.g = GLubyte((mRealColor.g * parentColor.g) / 255);
	mDisplayedColor.b = GLubyte((mRealColor.b * parentColor.b) / 255);

	if (mCascadeColorEnabled)
	{
		CCObject *obj = nullptr;
		CCARRAY_FOREACH(m_pChildren, obj)
		{
			auto item = dynamic_cast<CCRGBAProtocol *>(obj);

			if (item)
			{
				item->updateDisplayedColor(mDisplayedColor);
			}
		}
	}
}

bool CCClippingNodeRGBA::isCascadeOpacityEnabled()
{
	return mCascadeOpacityEnabled;
}

void CCClippingNodeRGBA::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{
	mCascadeOpacityEnabled = cascadeOpacityEnabled;
}

void CCClippingNodeRGBA::updateDisplayedOpacity(GLubyte parentOpacity)
{
	mDisplayedOpacity = GLubyte((mRealOpacity * parentOpacity) / 255);

	if (mCascadeOpacityEnabled)
	{
		CCObject *pObj;
		CCARRAY_FOREACH(m_pChildren, pObj)
		{
			CCRGBAProtocol *item = dynamic_cast<CCRGBAProtocol *>(pObj);

			if (item)
			{
				item->updateDisplayedOpacity(mDisplayedOpacity);
			}
		}
	}
}

CCScale9SpriteEx::CCScale9SpriteEx()
	: CCAdditiveColor(this)
{
	// do nothing
}

CCScale9SpriteEx *CCScale9SpriteEx::create()
{
	auto result = new CCScale9SpriteEx;

	if (nullptr != result)
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

bool CCScale9SpriteEx::initWithSpriteFrame(
	CCSpriteFrame *spriteFrame, CCRect capInsets)
{
	CC_ASSERT(nullptr != spriteFrame);

	auto batchNode = CCSpriteBatchNodeEx::create();
	CC_ASSERT(nullptr != batchNode);

	batchNode->setAdditiveColor(mAdditiveColor);

	return (batchNode->initWithTexture(spriteFrame->getTexture(), 9) &&
		initWithBatchNode(batchNode, spriteFrame->getRect(),
			spriteFrame->isRotated(), capInsets));
}

bool CCScale9SpriteEx::updateWithBatchNode(
	CCSpriteBatchNode *batchNode, CCRect rect, bool rotated, CCRect capInsets)
{
	if (extension::CCScale9Sprite::updateWithBatchNode(
			batchNode, rect, rotated, capInsets))
	{
		setOpacity(_opacity);
		setColor(_color);
		setAdditiveColor(mAdditiveColor);
		return true;
	}

	return false;
}

void CCScale9SpriteEx::updateAdditiveColor()
{
	auto scale9Ex = dynamic_cast<CCSpriteBatchNodeEx *>(_scale9Image);

	if (nullptr == scale9Ex)
		return;

	scale9Ex->setAdditiveColor(mAdditiveColor);
}

CCTextureAtlasEx::CCTextureAtlasEx()
	: CCAdditiveColor(nullptr)
	, mOldCapacity(0)
{
}

CCTextureAtlasEx *CCTextureAtlasEx::create()
{
	auto result = new CCTextureAtlasEx;

	if (nullptr != result)
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

bool CCTextureAtlasEx::initWithTextureEx(
	CCTexture2D *texture, unsigned int capacity)
{
	bool result = CCTextureAtlas::initWithTexture(texture, capacity);

#if CC_TEXTURE_ATLAS_USE_VAO

	if (result)
	{
		glDeleteVertexArrays(1, &m_uVAOname);

		m_uVAOname = 0;
	}

#endif

	updateAdditiveColor();

	return result;
}

void CCTextureAtlasEx::drawQuadsEx()
{
	if (0 == m_uTotalQuads)
		return;

	if (m_uCapacity != mOldCapacity)
		updateAdditiveColor();

	ccGLBindTexture2D(m_pTexture->getName());

#define kQuadSize sizeof(m_pQuads[0].bl)

	glBindBuffer(GL_ARRAY_BUFFER, m_pBuffersVBO[0]);

	if (m_bDirty)
	{
		glBufferSubData(GL_ARRAY_BUFFER, 0,
			m_uTotalQuads *
				(sizeof(m_pQuads[0]) + sizeof(ccColor4B) * RECT_VERTEX_COUNT),
			m_pQuads);
		m_bDirty = false;
	}

	ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);

	glEnableVertexAttribArray(kCCVertexAttrib_MAX);

	// vertices
	glVertexAttribPointer(kCCVertexAttrib_Position, 3, GL_FLOAT, GL_FALSE,
		kQuadSize, (GLvoid *) offsetof(ccV3F_C4B_T2F, vertices));

	// colors
	glVertexAttribPointer(kCCVertexAttrib_Color, 4, GL_UNSIGNED_BYTE, GL_TRUE,
		kQuadSize, (GLvoid *) offsetof(ccV3F_C4B_T2F, colors));

	// tex coords
	glVertexAttribPointer(kCCVertexAttrib_TexCoords, 2, GL_FLOAT, GL_FALSE,
		kQuadSize, (GLvoid *) offsetof(ccV3F_C4B_T2F, texCoords));

	// additive_color
	glVertexAttribPointer(kCCVertexAttrib_MAX, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0,
		(GLvoid *) (m_uTotalQuads * sizeof(m_pQuads[0])));

#undef kQuadSize

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pBuffersVBO[1]);

#if CC_TEXTURE_ATLAS_USE_TRIANGLE_STRIP
	glDrawElements(GL_TRIANGLE_STRIP, (GLsizei) m_uTotalQuads * 6,
		GL_UNSIGNED_SHORT, (GLvoid *) 0);
#else
	glDrawElements(GL_TRIANGLES, (GLsizei) m_uTotalQuads * 6, GL_UNSIGNED_SHORT,
		(GLvoid *) 0);
#endif // CC_TEXTURE_ATLAS_USE_TRIANGLE_STRIP

	glDisableVertexAttribArray(kCCVertexAttrib_MAX);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	CC_INCREMENT_GL_DRAWS(1);
	CHECK_GL_ERROR_DEBUG();
}

void CCTextureAtlasEx::mapBuffers()
{
	ccGLBindVAO(0);

	glBindBuffer(GL_ARRAY_BUFFER, m_pBuffersVBO[0]);
	glBufferData(GL_ARRAY_BUFFER,
		(sizeof(m_pQuads[0]) + sizeof(ccColor4B) * RECT_VERTEX_COUNT) *
			m_uCapacity,
		m_pQuads, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_pBuffersVBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		sizeof(m_pIndices[0]) * m_uCapacity * 6, m_pIndices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	CHECK_GL_ERROR_DEBUG();
}

void CCTextureAtlasEx::updateAdditiveColor()
{
	mOldCapacity = m_uCapacity;
	m_pQuads = (ccV3F_C4B_T2F_Quad *) realloc(m_pQuads,
		(sizeof(m_pQuads[0]) + sizeof(ccColor4B) * RECT_VERTEX_COUNT) *
			m_uCapacity);

	mapBuffers();

	CCAdditiveColor::setAdditiveColorTo(mAdditiveColor,
		(ccColor4B *) &m_pQuads[m_uTotalQuads],
		m_uTotalQuads * RECT_VERTEX_COUNT,
		nullptr != m_pTexture && m_pTexture->hasPremultipliedAlpha());

	m_bDirty = true;
}

CCSpriteBatchNodeEx::CCSpriteBatchNodeEx()
	: CCAdditiveColor(this)
{
}

CCSpriteBatchNodeEx *CCSpriteBatchNodeEx::create()
{
	auto result = new CCSpriteBatchNodeEx;

	if (nullptr != result)
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

void CCSpriteBatchNodeEx::updateAdditiveColor()
{
	auto atlas = dynamic_cast<CCTextureAtlasEx *>(m_pobTextureAtlas);

	if (nullptr != atlas)
		atlas->setAdditiveColor(mAdditiveColor);
}

bool CCSpriteBatchNodeEx::initWithTexture(
	CCTexture2D *texture, unsigned int capacity)
{
	CC_ASSERT(nullptr != texture);

	if (!texture->hasPremultipliedAlpha())
	{
		m_blendFunc.src = GL_SRC_ALPHA;
		m_blendFunc.dst = GL_ONE_MINUS_SRC_ALPHA;
	} else
	{
		m_blendFunc.src = CC_BLEND_SRC;
		m_blendFunc.dst = CC_BLEND_DST;
	}

	CC_SAFE_RELEASE(m_pobTextureAtlas);
	auto atlas = new CCTextureAtlasEx;
	m_pobTextureAtlas = atlas;

	if (0 == capacity)
		capacity = kDefaultSpriteBatchCapacity;

	atlas->initWithTextureEx(texture, capacity);
	atlas->setAdditiveColor(mAdditiveColor);

	CC_SAFE_RELEASE(m_pChildren);
	m_pChildren = new CCArray();
	m_pChildren->initWithCapacity(capacity);

	CC_SAFE_RELEASE(m_pobDescendants);
	m_pobDescendants = new CCArray();
	m_pobDescendants->initWithCapacity(capacity);

	setShaderProgram(getShaderPositionTextureColorEx());
	return true;
}

void CCSpriteBatchNodeEx::draw()
{
	if (m_pobTextureAtlas->getTotalQuads() == 0)
	{
		return;
	}

	CC_NODE_DRAW_SETUP();

	arrayMakeObjectsPerformSelector(m_pChildren, updateTransform, CCSprite *);

	ccGLBlendFunc(m_blendFunc.src, m_blendFunc.dst);

	CC_ASSERT(nullptr != dynamic_cast<CCTextureAtlasEx *>(m_pobTextureAtlas));
	auto atlasEx = static_cast<CCTextureAtlasEx *>(m_pobTextureAtlas);
	atlasEx->drawQuadsEx();
}

CCNodeEx::CCNodeEx()
	: CCAdditiveColor(this)
{
}

CCNodeEx *CCNodeEx::create()
{
	auto result = new CCNodeEx;

	if (nullptr != result && result->init())
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

void CCNodeEx::updateAdditiveColor()
{
	// do nothing
}

CCDrawNodeRGBA::CCDrawNodeRGBA()
	: mDisplayedOpacity(255)
	, mRealOpacity(255)
	, mDisplayedColor(ccWHITE)
	, mRealColor(ccWHITE)
	, mCascadeColorEnabled(false)
	, mCascadeOpacityEnabled(false)
{
}

CCDrawNodeRGBA *CCDrawNodeRGBA::create()
{
	auto result = new CCDrawNodeRGBA;
	if (nullptr != result && result->init())
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

void CCDrawNodeRGBA::setColor(const ccColor3B &color)
{
	mDisplayedColor = mRealColor = color;

	if (mCascadeColorEnabled)
	{
		ccColor3B parentColor = ccWHITE;
		auto parentProtocol = dynamic_cast<CCRGBAProtocol *>(m_pParent);
		if (parentProtocol && parentProtocol->isCascadeColorEnabled())
		{
			parentColor = parentProtocol->getDisplayedColor();
		}

		updateDisplayedColor(parentColor);
	}
}

const ccColor3B &CCDrawNodeRGBA::getColor()
{
	return mRealColor;
}

const ccColor3B &CCDrawNodeRGBA::getDisplayedColor()
{
	return mDisplayedColor;
}

GLubyte CCDrawNodeRGBA::getDisplayedOpacity()
{
	return mDisplayedOpacity;
}

GLubyte CCDrawNodeRGBA::getOpacity()
{
	return mRealOpacity;
}

void CCDrawNodeRGBA::setOpacity(GLubyte opacity)
{
	mDisplayedOpacity = mRealOpacity = opacity;

	if (mCascadeOpacityEnabled)
	{
		GLubyte parentOpacity = 255;
		auto parentProtocol = dynamic_cast<CCRGBAProtocol *>(m_pParent);
		if (parentProtocol && parentProtocol->isCascadeOpacityEnabled())
		{
			parentOpacity = parentProtocol->getDisplayedOpacity();
		}

		this->updateDisplayedOpacity(parentOpacity);
	}
}

void CCDrawNodeRGBA::setOpacityModifyRGB(bool)
{
	// do nothing
}

bool CCDrawNodeRGBA::isOpacityModifyRGB()
{
	return false;
}

bool CCDrawNodeRGBA::isCascadeColorEnabled()
{
	return mCascadeColorEnabled;
}

void CCDrawNodeRGBA::setCascadeColorEnabled(bool cascadeColorEnabled)
{
	mCascadeColorEnabled = cascadeColorEnabled;
}

void CCDrawNodeRGBA::updateDisplayedColor(const ccColor3B &parentColor)
{
	auto oldColor = mDisplayedColor;
	mDisplayedColor.r = GLubyte((mRealColor.r * parentColor.r) / 255);
	mDisplayedColor.g = GLubyte((mRealColor.g * parentColor.g) / 255);
	mDisplayedColor.b = GLubyte((mRealColor.b * parentColor.b) / 255);
	m_bDirty = oldColor.r != mDisplayedColor.r ||
		oldColor.g != mDisplayedColor.g || oldColor.b != mDisplayedColor.b;

	if (mCascadeColorEnabled)
	{
		CCObject *obj = nullptr;
		CCARRAY_FOREACH(m_pChildren, obj)
		{
			auto item = dynamic_cast<CCRGBAProtocol *>(obj);
			if (item)
			{
				item->updateDisplayedColor(mDisplayedColor);
			}
		}
	}
}

bool CCDrawNodeRGBA::isCascadeOpacityEnabled()
{
	return mCascadeOpacityEnabled;
}

void CCDrawNodeRGBA::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{
	mCascadeOpacityEnabled = cascadeOpacityEnabled;
}

void CCDrawNodeRGBA::updateDisplayedOpacity(GLubyte parentOpacity)
{
	auto oldOpacity = mDisplayedOpacity;
	mDisplayedOpacity = GLubyte((mRealOpacity * parentOpacity) / 255);
	m_bDirty = mDisplayedOpacity != oldOpacity;

	if (mCascadeOpacityEnabled)
	{
		CCObject *pObj;
		CCARRAY_FOREACH(m_pChildren, pObj)
		{
			CCRGBAProtocol *item = dynamic_cast<CCRGBAProtocol *>(pObj);

			if (item)
			{
				item->updateDisplayedOpacity(mDisplayedOpacity);
			}
		}
	}
}

void CCDrawNodeRGBA::draw()
{
	auto savedBuffer = m_pBuffer;
	auto savedCapacity = m_nBufferCapacity;
	if (mDisplayedColor.r != 255 || mDisplayedColor.g != 255 ||
		mDisplayedColor.b != 255 || mDisplayedOpacity != 255)
	{
		if (m_bDirty)
		{
			CC_ASSERT(m_nBufferCount >= 0);
			m_nBufferCapacity = std::max(1, m_nBufferCount);
			mDisplayedBuffer.reserve(m_nBufferCapacity);
			mDisplayedBuffer.resize(m_nBufferCount);
			memcpy(mDisplayedBuffer.data(), savedBuffer,
				m_nBufferCount * sizeof(ccV2F_C4B_T2F));

			for (auto &entry : mDisplayedBuffer)
			{
				auto &color = entry.colors;
				color.r = GLubyte((color.r * mDisplayedColor.r) / 255);
				color.g = GLubyte((color.g * mDisplayedColor.g) / 255);
				color.b = GLubyte((color.b * mDisplayedColor.b) / 255);
				color.a = GLubyte((color.a * mDisplayedOpacity) / 255);
			}
		}
		m_pBuffer = mDisplayedBuffer.data();
	} else
	{
		if (m_bDirty)
			mDisplayedBuffer.clear();
	}

	CCDrawNode::draw();
	m_pBuffer = savedBuffer;
	m_nBufferCapacity = savedCapacity;
}
}
