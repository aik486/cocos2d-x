#pragma once

#include "cocos_warnings_off.h"
#include "include/ccTypes.h"
#include "sprite_nodes/CCSprite.h"
#include "draw_nodes/CCDrawNode.h"
#include "misc_nodes/CCClippingNode.h"
#include "extensions/GUI/CCControlExtension/CCScale9Sprite.h"
#include "textures/CCTextureAtlas.h"
#include "cocos_warnings_pop.h"

#include "CCObjectHolder.h"

#include <QPolygonF>

#include <deque>
#include <functional>

namespace cocos2d
{
enum
{
	RECT_VERTEX_COUNT = 4
};

struct ShapeProtocol
{
	virtual ~ShapeProtocol() = default;

	virtual bool hasShape() const = 0;
	virtual QPolygonF shape() const = 0;
};

struct CCAdditiveColorProtocol
{
	virtual ~CCAdditiveColorProtocol() {}

	virtual void setAdditiveColor(const ccColor3B &color) = 0;
	virtual const ccColor3B &getAdditiveColor() = 0;
};

class CCAdditiveColor : public CCAdditiveColorProtocol
{
protected:
	CCAdditiveColor(CCNode *node);

public:
	inline bool isCascadeAddColor() const;
	void setCascadeAddColor(bool enabled);
	void updateCascadeAddColor();

	virtual void setAdditiveColor(const ccColor3B &color) override;
	virtual const ccColor3B &getAdditiveColor() override;

	virtual void updateAdditiveColor() = 0;

	inline const ccColor3B &getDisplayedAdditiveColor() const;

	static void resetDisplayedAdditiveColor(ccColor4B *setTo);
	static void setAdditiveColorTo(const cocos2d::ccColor3B &color,
		ccColor4B *setTo, size_t count, bool opacityModifyRGB,
		uint8_t displayedOpacity = 255);

protected:
	void updateDisplayedAddColor(const ccColor3B &parentColor);

	CCNode *thiz;
	ccColor3B mAdditiveColor;
	ccColor3B mDisplayedAddColor;
	bool mCascadeAddColor;
};

bool CCAdditiveColor::isCascadeAddColor() const
{
	return mCascadeAddColor;
}

const ccColor3B &CCAdditiveColor::getDisplayedAdditiveColor() const
{
	return mDisplayedAddColor;
}

class CCNodeEx
	: public CCNodeRGBA
	, public CCAdditiveColor
{
public:
	CCNodeEx();

	static CCNodeEx *create();

	virtual void updateAdditiveColor() override;
};

class CCCustomEffect : public CCSprite
{
public:
	static CCCustomEffect *create();

	void addTextureForShader(
		CCTexture2D *texture, const QByteArray &uniformName);

	using PreDrawCalllback = std::function<void()>;

	void setPreDrawCallback(const PreDrawCalllback &callback);

	virtual void draw() override;

private:
	struct TextureEntry
	{
		CCObjectHolder<CCTexture2D *> texture;
		QByteArray uniformName;
		int uniformLocation = -1;
	};

	std::deque<TextureEntry> mShaderTextures;
	PreDrawCalllback mPreDrawCallback;
};

class CCSpriteEx
	: public CCSprite
	, public CCAdditiveColor
{
public:
	CCSpriteEx();

	static CCSpriteEx *create();
	static CCSpriteEx *createWithSpriteFrame(CCSpriteFrame *frame);

	virtual void updateAdditiveColor() override;
	virtual void setShaderProgram(CCGLProgram *pShaderProgram) override;
	virtual void updateBlendFunc() override;

	virtual void draw() override;

private:
	ccColor4B mDisplayedAdditiveColor[RECT_VERTEX_COUNT];
};

class CCSpriteBatchNodeEx
	: public CCSpriteBatchNode
	, public CCAdditiveColor
{
public:
	CCSpriteBatchNodeEx();

	static CCSpriteBatchNodeEx *create();

	virtual void updateAdditiveColor() override;
	bool initWithTexture(CCTexture2D *texture, unsigned int capacity);

	virtual void draw() override;
};

class CCTextureAtlasEx
	: public CCTextureAtlas
	, public CCAdditiveColor
{
public:
	CCTextureAtlasEx();

	static CCTextureAtlasEx *create();

	virtual void updateAdditiveColor() override;

	bool initWithTextureEx(CCTexture2D *texture, unsigned int capacity);

	void drawQuadsEx();

private:
	void mapBuffers();

	unsigned int mOldCapacity;
};

class CCScale9SpriteEx
	: public extension::CCScale9Sprite
	, public CCAdditiveColor
{
public:
	CCScale9SpriteEx();

	static CCScale9SpriteEx *create();

	virtual bool initWithSpriteFrame(
		CCSpriteFrame *spriteFrame, CCRect capInsets) override;
	virtual bool updateWithBatchNode(CCSpriteBatchNode *batchNode, CCRect rect,
		bool rotated, CCRect capInsets) override;

	virtual void updateAdditiveColor() override;
};

class CCDrawNodeRGBA
	: public CCDrawNode
	, public CCRGBAProtocol
{
public:
	CCDrawNodeRGBA();

	static CCDrawNodeRGBA *create();

	virtual void setColor(const ccColor3B &color) override;
	virtual const ccColor3B &getColor() override;
	virtual const ccColor3B &getDisplayedColor() override;
	virtual GLubyte getDisplayedOpacity() override;
	virtual GLubyte getOpacity() override;
	virtual void setOpacity(GLubyte opacity) override;
	virtual void setOpacityModifyRGB(bool) override;
	virtual bool isOpacityModifyRGB() override;
	virtual bool isCascadeColorEnabled() override;
	virtual void setCascadeColorEnabled(bool cascadeColorEnabled) override;
	virtual void updateDisplayedColor(const ccColor3B &parentColor) override;
	virtual bool isCascadeOpacityEnabled() override;
	virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled) override;
	virtual void updateDisplayedOpacity(GLubyte parentOpacity) override;

	virtual void draw() override;

protected:
	std::vector<ccV2F_C4B_T2F> mDisplayedBuffer;
	GLubyte mDisplayedOpacity;
	GLubyte mRealOpacity;
	ccColor3B mDisplayedColor;
	ccColor3B mRealColor;
	bool mCascadeColorEnabled;
	bool mCascadeOpacityEnabled;
};

class CCClippingNodeRGBA
	: public CCClippingNode
	, public CCRGBAProtocol
{
protected:
	CCClippingNodeRGBA();

public:
	static CCClippingNodeRGBA *create(CCNode *stencil);

	void setClearStencil(bool value);

	virtual void visit() override;
	virtual bool init(CCNode *pStencil) override;

	virtual void setColor(const ccColor3B &color) override;
	virtual const ccColor3B &getColor() override;
	virtual const ccColor3B &getDisplayedColor() override;
	virtual GLubyte getDisplayedOpacity() override;
	virtual GLubyte getOpacity() override;
	virtual void setOpacity(GLubyte opacity) override;
	virtual void setOpacityModifyRGB(bool) override;
	virtual bool isOpacityModifyRGB() override;
	virtual bool isCascadeColorEnabled() override;
	virtual void setCascadeColorEnabled(bool cascadeColorEnabled) override;
	virtual void updateDisplayedColor(const ccColor3B &parentColor) override;
	virtual bool isCascadeOpacityEnabled() override;
	virtual void setCascadeOpacityEnabled(bool cascadeOpacityEnabled) override;
	virtual void updateDisplayedOpacity(GLubyte parentOpacity) override;

protected:
	GLubyte mDisplayedOpacity;
	GLubyte mRealOpacity;
	ccColor3B mDisplayedColor;
	ccColor3B mRealColor;
	bool mCascadeColorEnabled;
	bool mCascadeOpacityEnabled;

private:
	bool mClearStencil;
};
}
