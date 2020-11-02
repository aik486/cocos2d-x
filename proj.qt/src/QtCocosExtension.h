#pragma once

#include "base/ccTypes.h"
#include "2d/CCSprite.h"
#include "2d/CCDrawNode.h"
#include "2d/CCClippingNode.h"
#include "ui/UIScale9Sprite.h"
#include "renderer/CCTextureAtlas.h"

#include "CCRefHolder.h"

#include <QPolygonF>
#include <QList>

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

	virtual void setAdditiveColor(const Color3B &color) = 0;
	virtual const Color3B &getAdditiveColor() = 0;
};

class CCAdditiveColor : public CCAdditiveColorProtocol
{
protected:
	CCAdditiveColor(Node *node);

public:
	inline bool isCascadeAddColor() const;
	void setCascadeAddColor(bool enabled);
	void updateCascadeAddColor();

	virtual void setAdditiveColor(const Color3B &color) override;
	virtual const Color3B &getAdditiveColor() override;

	virtual void updateAdditiveColor() = 0;

	inline const Color3B &getDisplayedAdditiveColor() const;

protected:
	void updateDisplayedAddColor(const Color3B &parentColor);

	Node *thiz;
	Color3B mAdditiveColor;
	Color3B mDisplayedAddColor;
	bool mCascadeAddColor;
};

bool CCAdditiveColor::isCascadeAddColor() const
{
	return mCascadeAddColor;
}

const Color3B &CCAdditiveColor::getDisplayedAdditiveColor() const
{
	return mDisplayedAddColor;
}

class CCNodeEx
	: public Node
	, public CCAdditiveColor
{
public:
	CCNodeEx();

	static CCNodeEx *create();

	virtual void updateAdditiveColor() override;
};

class CCCustomEffect : public Sprite
{
public:
	CCCustomEffect();

	using PreDrawCallback = std::function<void(CCCustomEffect *)>;
	using CopyCallback =
		std::function<void(const CCCustomEffect *, CCCustomEffect *)>;

	static CCCustomEffect *create();

	virtual CCCustomEffect *clone() const override;

	void clearTexturesForShader();
	void addTextureForShader(
		Texture2D *texture, const std::string &uniformName);

	void setPreDrawCallback(const PreDrawCallback &callback);
	void setCopyCallback(const CopyCallback &callback);

	virtual void draw(
		Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

	virtual void setProgramState(backend::ProgramState *state) override;
	virtual bool initWithTexture(
		Texture2D *texture, const Rect &rect, bool rotated) override;

protected:
	void updateUniforms();

private:
	struct TextureEntry
	{
		RefHolder<Texture2D *> texture;
		std::string uniformName;
	};

	QList<TextureEntry> mShaderTextures;
	PreDrawCallback mPreDrawCallback;
	CopyCallback mCopyCallback;
	bool mUniformsDirty;
};

class CCSpriteEx
	: public Sprite
	, public CCAdditiveColor
{
public:
	CCSpriteEx();

	static CCSpriteEx *create();
	static CCSpriteEx *createWithSpriteFrame(SpriteFrame *frame);

	virtual CCSpriteEx *clone() const override;
	virtual void updateAdditiveColor() override;

	using Sprite::updateBlendFunc;
	using Sprite::setProgramState;

protected:
	virtual void setProgramState(backend::ProgramType type) override;

private:
	backend::UniformLocation mAdditiveColorUniform;
};

class CCScale9SpriteEx
	: public ui::Scale9Sprite
	, public CCAdditiveColor
{
public:
	CCScale9SpriteEx();
	virtual ~CCScale9SpriteEx() override;

	static CCScale9SpriteEx *create();
	static CCScale9SpriteEx *createWithSpriteFrame(
		SpriteFrame *frame, const Rect &capInsets);

	virtual void updateAdditiveColor() override;

	using ui::Scale9Sprite::updateBlendFunc;
	using ui::Scale9Sprite::setProgramState;

protected:
	virtual void setProgramState(backend::ProgramType type) override;

private:
	backend::UniformLocation mAdditiveColorUniform;
};
}
