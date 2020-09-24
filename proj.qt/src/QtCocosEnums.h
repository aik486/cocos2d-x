#pragma once

#include "base/ccTypes.h"
#include "base/CCDirector.h"
#include "platform/CCDevice.h"
#include "platform/CCGL.h"
#include "2d/CCNode.h"
#include "2d/CCTransition.h"
#include "2d/CCProgressTimer.h"
#include "renderer/backend/ShaderModule.h"
#include <qobjectdefs.h>

namespace cocos2d
{
Q_NAMESPACE

enum NodeEventType
{
	NodeOnEnter = kNodeOnEnter,
	NodeOnExit = kNodeOnExit,
	NodeOnEnterTransitionDidFinish = kNodeOnEnterTransitionDidFinish,
	NodeOnExitTransitionDidStart = kNodeOnExitTransitionDidStart,
	NodeOnCleanup = kNodeOnCleanup
};
Q_ENUM_NS(NodeEventType)

enum DirectorProjection
{
	Projection2D = int(Director::Projection::_2D),
	Projection3D = int(Director::Projection::_3D),
	ProjectionCustom = int(Director::Projection::CUSTOM),
	ProjectionDefault = int(Director::Projection::DEFAULT),
};
Q_ENUM_NS(DirectorProjection)

enum VerticalTextAlignment
{
	TextAlignmentVTop = int(TextVAlignment::TOP),
	TextAlignmentVCenter = int(TextVAlignment::CENTER),
	TextAlignmentVBottom = int(TextVAlignment::BOTTOM)
};
Q_ENUM_NS(VerticalTextAlignment)

enum HorizontalTextAlignment
{
	TextAlignmentHLeft = int(TextHAlignment::LEFT),
	TextAlignmentHCenter = int(TextHAlignment::CENTER),
	TextAlignmentHRight = int(TextHAlignment::RIGHT),
};
Q_ENUM_NS(HorizontalTextAlignment)

enum TransitionOrientation
{
	TransitionOrientationLeftOver =
		int(TransitionScene::Orientation::LEFT_OVER),

	TransitionOrientationRightOver =
		int(TransitionScene::Orientation::RIGHT_OVER),

	TransitionOrientationUpOver = int(TransitionScene::Orientation::UP_OVER),

	TransitionOrientationDownOver =
		int(TransitionScene::Orientation::DOWN_OVER),
};
Q_ENUM_NS(TransitionOrientation)

enum ProgressTimerType
{
	ProgressTimerTypeRadial = int(ProgressTimer::Type::RADIAL),
	ProgressTimerTypeBar = int(ProgressTimer::Type::BAR),
};
Q_ENUM_NS(ProgressTimerType)

enum AlignmentFlag
{
	AlignCenter = int(Device::TextAlign::CENTER),
	AlignTop = int(Device::TextAlign::TOP),
	AlignTopRight = int(Device::TextAlign::TOP_RIGHT),
	AlignRight = int(Device::TextAlign::RIGHT),
	AlignBottomRight = int(Device::TextAlign::BOTTOM_RIGHT),
	AlignBottom = int(Device::TextAlign::BOTTOM),
	AlignBottomLeft = int(Device::TextAlign::BOTTOM_LEFT),
	AlignLeft = int(Device::TextAlign::LEFT),
	AlignTopLeft = int(Device::TextAlign::TOP_LEFT),
};
Q_ENUM_NS(AlignmentFlag)

enum TextureFormat
{
	TextureFormat_RGBA8888 = int(backend::PixelFormat::RGBA8888),
	TextureFormat_RGB888 = int(backend::PixelFormat::RGB888),
	TextureFormat_RGB565 = int(backend::PixelFormat::RGB565),
	TextureFormat_A8 = int(backend::PixelFormat::A8),
	TextureFormat_I8 = int(backend::PixelFormat::I8),
	TextureFormat_AI88 = int(backend::PixelFormat::AI88),
	TextureFormat_RGBA4444 = int(backend::PixelFormat::RGBA4444),
	TextureFormat_RGB5A1 = int(backend::PixelFormat::RGB5A1),
	TextureFormat_Default = int(backend::PixelFormat::DEFAULT),
	TextureFormat_Auto = int(backend::PixelFormat::AUTO),
	TextureFormat_None = int(backend::PixelFormat::NONE),
};
Q_ENUM_NS(TextureFormat)

enum SamplerFilter
{
	SamplerFilter_NEAREST = int(backend::SamplerFilter::NEAREST),

	SamplerFilter_NEAREST_MIPMAP_NEAREST =
		int(backend::SamplerFilter::NEAREST_MIPMAP_NEAREST),

	SamplerFilter_NEAREST_MIPMAP_LINEAR =
		int(backend::SamplerFilter::NEAREST_MIPMAP_LINEAR),

	SamplerFilter_LINEAR = int(backend::SamplerFilter::LINEAR),

	SamplerFilter_LINEAR_MIPMAP_LINEAR =
		int(backend::SamplerFilter::LINEAR_MIPMAP_LINEAR),

	SamplerFilter_LINEAR_MIPMAP_NEAREST =
		int(backend::SamplerFilter::LINEAR_MIPMAP_NEAREST),

	SamplerFilter_DONT_CARE = int(backend::SamplerFilter::DONT_CARE),
};
Q_ENUM_NS(SamplerFilter);

enum SamplerAddressMode
{
	SamplerAddressMode_REPEAT = int(backend::SamplerAddressMode::REPEAT),

	SamplerAddressMode_MIRROR_REPEAT =
		int(backend::SamplerAddressMode::MIRROR_REPEAT),

	SamplerAddressMode_CLAMP_TO_EDGE =
		int(backend::SamplerAddressMode::CLAMP_TO_EDGE),

	SamplerAddressMode_DONT_CARE = int(backend::SamplerAddressMode::DONT_CARE),
};
Q_ENUM_NS(SamplerAddressMode);

enum BlendFactor
{
	ZERO = int(backend::BlendFactor::ZERO),

	ONE = int(backend::BlendFactor::ONE),

	SRC_COLOR = int(backend::BlendFactor::SRC_COLOR),

	ONE_MINUS_SRC_COLOR = int(backend::BlendFactor::ONE_MINUS_SRC_COLOR),

	SRC_ALPHA = int(backend::BlendFactor::SRC_ALPHA),

	ONE_MINUS_SRC_ALPHA = int(backend::BlendFactor::ONE_MINUS_SRC_ALPHA),

	DST_COLOR = int(backend::BlendFactor::DST_COLOR),

	ONE_MINUS_DST_COLOR = int(backend::BlendFactor::ONE_MINUS_DST_COLOR),

	DST_ALPHA = int(backend::BlendFactor::DST_ALPHA),

	ONE_MINUS_DST_ALPHA = int(backend::BlendFactor::ONE_MINUS_DST_ALPHA),

	CONSTANT_ALPHA = int(backend::BlendFactor::CONSTANT_ALPHA),

	SRC_ALPHA_SATURATE = int(backend::BlendFactor::SRC_ALPHA_SATURATE),

	ONE_MINUS_CONSTANT_ALPHA =
		int(backend::BlendFactor::ONE_MINUS_CONSTANT_ALPHA),
	BLEND_CLOLOR = int(backend::BlendFactor::BLEND_CLOLOR),
};
Q_ENUM_NS(BlendFactor);
}
