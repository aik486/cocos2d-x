#include "QtCocosExtension.h"

#include "QtCocosHelper.h"

#include "renderer/backend/ProgramCache.h"
#include "renderer/backend/Device.h"
#include "renderer/ccShaders.h"

namespace cocos2d
{
using namespace backend;

static const char ccPositionTextureColor_frag[] = "\
#ifdef GL_ES															\n\
precision lowp float;													\n\
#endif																	\n\
																		\n\
varying vec4 v_fragmentColor;											\n\
varying vec2 v_texCoord;												\n\
uniform sampler2D u_texture;										    \n\
uniform vec3 u_additiveColor;											\n\
																		\n\
void main()																\n\
{																		\n\
	gl_FragColor = v_fragmentColor * texture2D(u_texture, v_texCoord);	\n\
	gl_FragColor.rgb += u_additiveColor.rgb;							\n\
}																		\n\
";

static const char kShaderPositionTextureColorEx[] =
	"ShaderPositionTextureColorEx";
static Program *getShaderPositionTextureColorEx()
{
	std::string key(kShaderPositionTextureColorEx);
	auto programCache = ProgramCache::getInstance();
	auto program = programCache->getCustomProgram(key);
	if (nullptr == program)
	{
		program = Device::getInstance()->newProgram(
			positionTextureColor_vert, ccPositionTextureColor_frag);

		programCache->addCustomProgram(key, program);
		program->release();
	}

	return program;
}

CCAdditiveColor::CCAdditiveColor(Node *node)
	: thiz(node)
	, mAdditiveColor(0, 0, 0)
	, mDisplayedAddColor(0, 0, 0)
	, mCascadeAddColor(false)
{
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
	Color3B parentAddColor(0, 0, 0);

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

		if (nullptr != thiz)
		{
			for (auto node : thiz->getChildren())
			{
				auto item = dynamic_cast<CCAdditiveColor *>(node);

				if (item)
				{
					item->updateDisplayedAddColor(parentAddColor);
				}
			}
		}
	}
}

void CCAdditiveColor::setAdditiveColor(const Color3B &color)
{
	mDisplayedAddColor = mAdditiveColor = color;

	updateCascadeAddColor();
}

const Color3B &CCAdditiveColor::getAdditiveColor()
{
	return mAdditiveColor;
}

void CCAdditiveColor::updateDisplayedAddColor(const Color3B &parentColor)
{
	mDisplayedAddColor.r = quint8(
		std::min(255, std::max<int>(0, mAdditiveColor.r + parentColor.r)));
	mDisplayedAddColor.g = quint8(
		std::min(255, std::max<int>(0, mAdditiveColor.g + parentColor.g)));
	mDisplayedAddColor.b = quint8(
		std::min(255, std::max<int>(0, mAdditiveColor.b + parentColor.b)));

	updateAdditiveColor();

	if (mCascadeAddColor && thiz)
	{
		for (auto node : thiz->getChildren())
		{
			auto item = dynamic_cast<CCAdditiveColor *>(node);

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
}

CCSpriteEx *CCSpriteEx::create()
{
	auto result = new CCSpriteEx;

	if (result && result->init())
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

CCSpriteEx *CCSpriteEx::createWithSpriteFrame(SpriteFrame *frame)
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

CCSpriteEx *CCSpriteEx::clone() const
{
	auto sprite = new CCSpriteEx;
	sprite->copyPropertiesFrom(this);
	sprite->setCascadeAddColor(mCascadeAddColor);
	sprite->setAdditiveColor(mAdditiveColor);
	return sprite;
}

void CCSpriteEx::updateAdditiveColor()
{
	if (mAdditiveColorUniform)
	{
		float colors[3] = { mDisplayedAddColor.r / 255.0f,
			mDisplayedAddColor.g / 255.0f, mDisplayedAddColor.b / 255.0f };
		_programState->setUniform(
			mAdditiveColorUniform, &colors, sizeof(colors));
	}
}

void CCSpriteEx::setProgramState(backend::ProgramType type)
{
	if (type == ProgramType::POSITION_TEXTURE_COLOR)
	{
		auto program = getShaderPositionTextureColorEx();
		if (_programState && _programState->getProgram() == program)
		{
			return;
		}

		auto programState = new (std::nothrow) backend::ProgramState(program);
		setProgramState(programState);
		CC_SAFE_RELEASE(programState);

		mAdditiveColorUniform =
			programState->getUniformLocation("u_additiveColor");
		updateAdditiveColor();
		return;
	}

	mAdditiveColorUniform = UniformLocation();
	Sprite::setProgramState(type);
}

CCScale9SpriteEx::CCScale9SpriteEx()
	: CCAdditiveColor(this)
{
	// do nothing
}

CCScale9SpriteEx::~CCScale9SpriteEx()
{
	// do nothing
}

CCScale9SpriteEx *CCScale9SpriteEx::create()
{
	auto result = new CCScale9SpriteEx;

	if (result && result->init())
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

CCScale9SpriteEx *CCScale9SpriteEx::createWithSpriteFrame(
	SpriteFrame *frame, const Rect &capInsets)
{
	auto result = new CCScale9SpriteEx;

	if (result && result->initWithSpriteFrame(frame, capInsets))
	{
		result->autorelease();
		return result;
	}

	delete result;
	return nullptr;
}

void CCScale9SpriteEx::updateAdditiveColor()
{
	if (mAdditiveColorUniform)
	{
		float colors[3] = { mDisplayedAddColor.r / 255.0f,
			mDisplayedAddColor.g / 255.0f, mDisplayedAddColor.b / 255.0f };
		_programState->setUniform(
			mAdditiveColorUniform, &colors, sizeof(colors));
	}
}

void CCScale9SpriteEx::setProgramState(ProgramType type)
{
	if (type == ProgramType::POSITION_TEXTURE_COLOR)
	{
		auto program = getShaderPositionTextureColorEx();
		if (_programState && _programState->getProgram() == program)
		{
			return;
		}

		auto programState = new (std::nothrow) ProgramState(program);
		setProgramState(programState);
		CC_SAFE_RELEASE(programState);

		mAdditiveColorUniform =
			programState->getUniformLocation("u_additiveColor");
		updateAdditiveColor();
		return;
	}

	mAdditiveColorUniform = UniformLocation();
	ui::Scale9Sprite::setProgramState(type);
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
	//
}

CCCustomEffect::CCCustomEffect()
	: mUniformsDirty(false)
{
}

CCCustomEffect *CCCustomEffect::create()
{
	auto result = new CCCustomEffect;
	if (result && result->init())
	{
		result->autorelease();
	} else
	{
		CC_SAFE_DELETE(result);
	}

	return result;
}

CCCustomEffect *CCCustomEffect::clone() const
{
	auto result = new CCCustomEffect;
	result->copyPropertiesFrom(this);

	result->mShaderTextures = mShaderTextures;
	result->mCopyCallback = mCopyCallback;
	result->mPreDrawCallback = mPreDrawCallback;
	result->mUniformsDirty = true;

	if (mCopyCallback)
	{
		mCopyCallback(this, result);
	}

	return result;
}

void CCCustomEffect::clearTexturesForShader()
{
	mShaderTextures.clear();
	mUniformsDirty = true;
}

void CCCustomEffect::addTextureForShader(
	Texture2D *texture, const std::string &uniformName)
{
	TextureEntry entry;
	entry.texture.setObject(texture);
	entry.uniformName = uniformName;
	mShaderTextures.append(entry);
	mUniformsDirty = true;
}

void CCCustomEffect::setPreDrawCallback(const PreDrawCallback &callback)
{
	mPreDrawCallback = callback;
}

void CCCustomEffect::setCopyCallback(const CopyCallback &callback)
{
	mCopyCallback = callback;
}

void CCCustomEffect::draw(
	Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	if (mUniformsDirty)
	{
		mUniformsDirty = false;
		updateUniforms();
	}

	if (mPreDrawCallback)
	{
		mPreDrawCallback(this);
	}

	Sprite::draw(renderer, transform, flags);
}

void CCCustomEffect::setProgramState(ProgramState *state)
{
	auto oldState = _programState;
	if (oldState == state)
	{
		return;
	}
	Sprite::setProgramState(state);

	mUniformsDirty = true;
}

bool CCCustomEffect::initWithTexture(
	Texture2D *texture, const Rect &rect, bool rotated)
{
	auto savedAnchorPoint = _anchorPoint;
	bool savedFlippedX = _flippedX;
	bool savedFlippedY = _flippedY;
	bool ok = Sprite::initWithTexture(texture, rect, rotated);
	setAnchorPoint(savedAnchorPoint);
	setFlippedX(savedFlippedX);
	setFlippedY(savedFlippedY);
	return ok;
}

void CCCustomEffect::updateUniforms()
{
	auto programState = _programState;
	if (programState)
	{
		for (int i = 0, count = mShaderTextures.count(); i < count; i++)
		{
			auto &entry = mShaderTextures[i];
			auto texture = entry.texture.object();
			if (!texture)
			{
				continue;
			}
			auto bTexture = texture->getBackendTexture();
			if (!bTexture)
			{
				continue;
			}

			auto uniformLocation =
				programState->getUniformLocation(entry.uniformName);
			programState->setTexture(uniformLocation, i, bTexture);
		}
	}
}
}
