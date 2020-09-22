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

namespace gl_enum
{
Q_NAMESPACE

enum Enum
{
	LINEAR = GL_LINEAR,
	NEAREST = GL_NEAREST,
	REPEAT = GL_REPEAT,
	CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
};
Q_ENUM_NS(Enum);
}
}
