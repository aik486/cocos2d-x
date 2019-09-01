#pragma once

#include "cocos2dx_qt.h"

namespace cocos2d
{
Q_NAMESPACE

enum NodeEventType
{
	NodeOnEnter = kCCNodeOnEnter,
	NodeOnExit = kCCNodeOnExit,
	NodeOnEnterTransitionDidFinish = kCCNodeOnEnterTransitionDidFinish,
	NodeOnExitTransitionDidStart = kCCNodeOnExitTransitionDidStart,
	NodeOnCleanup = kCCNodeOnCleanup
};
Q_ENUM_NS(NodeEventType)

enum DirectorProjection
{
	Projection2D = kCCDirectorProjection2D,
	Projection3D = kCCDirectorProjection3D,
	ProjectionCustom = kCCDirectorProjectionCustom,
	ProjectionDefault = kCCDirectorProjectionDefault
};
Q_ENUM_NS(DirectorProjection)

enum VerticalTextAlignment
{
	TextAlignmentVTop = kCCVerticalTextAlignmentTop,
	TextAlignmentVCenter = kCCVerticalTextAlignmentCenter,
	TextAlignmentVBottom = kCCVerticalTextAlignmentBottom
};
Q_ENUM_NS(VerticalTextAlignment)

enum HorizontalTextAlignment
{
	TextAlignmentHLeft = kCCTextAlignmentLeft,
	TextAlignmentHCenter = kCCTextAlignmentCenter,
	TextAlignmentHRight = kCCTextAlignmentRight
};
Q_ENUM_NS(HorizontalTextAlignment)

enum TransitionOrientation
{
	TransitionOrientationLeftOver = kCCTransitionOrientationLeftOver,
	TransitionOrientationRightOver = kCCTransitionOrientationRightOver,
	TransitionOrientationUpOver = kCCTransitionOrientationUpOver,
	TransitionOrientationDownOver = kCCTransitionOrientationDownOver
};
Q_ENUM_NS(TransitionOrientation)

enum ProgressTimerType
{
	ProgressTimerTypeRadial = kCCProgressTimerTypeRadial,
	ProgressTimerTypeBar = kCCProgressTimerTypeBar,
};
Q_ENUM_NS(ProgressTimerType)

enum ImageFileFormat
{
	jpeg = CCImage::kFmtJpg,
	png = CCImage::kFmtPng,
	tiff = CCImage::kFmtTiff,
	webp = CCImage::kFmtWebp,
	RawImageData = CCImage::kFmtRawData,
};
Q_ENUM_NS(ImageFileFormat)

enum AlignmentFlag
{
	AlignCenter = CCImage::ETextAlign::kAlignCenter,
	AlignTop = CCImage::ETextAlign::kAlignTop,
	AlignTopRight = CCImage::ETextAlign::kAlignTopRight,
	AlignRight = CCImage::ETextAlign::kAlignRight,
	AlignBottomRight = CCImage::ETextAlign::kAlignBottomRight,
	AlignBottom = CCImage::ETextAlign::kAlignBottom,
	AlignBottomLeft = CCImage::ETextAlign::kAlignBottomLeft,
	AlignLeft = CCImage::ETextAlign::kAlignLeft,
	AlignTopLeft = CCImage::ETextAlign::kAlignTopLeft,
};
Q_ENUM_NS(AlignmentFlag)

enum VertexAttrib
{
	VertexAttribPosition,
	VertexAttribColor,
	VertexAttribTexCoords,
};
Q_ENUM_NS(VertexAttrib)

enum UniformType
{
	UniformPMatrix,
	UniformMVMatrix,
	UniformMVPMatrix,
	UniformTime,
	UniformSinTime,
	UniformCosTime,
	UniformRandom01,
	UniformSampler,
};
Q_ENUM_NS(UniformType)

enum TextureFormat
{
	TextureFormat_RGBA8888 = kCCTexture2DPixelFormat_RGBA8888,
	TextureFormat_RGB888 = kCCTexture2DPixelFormat_RGB888,
	TextureFormat_RGB565 = kCCTexture2DPixelFormat_RGB565,
	TextureFormat_A8 = kCCTexture2DPixelFormat_A8,
	TextureFormat_I8 = kCCTexture2DPixelFormat_I8,
	TextureFormat_AI88 = kCCTexture2DPixelFormat_AI88,
	TextureFormat_RGBA4444 = kCCTexture2DPixelFormat_RGBA4444,
	TextureFormat_RGB5A1 = kCCTexture2DPixelFormat_RGB5A1,
	TextureFormat_PVRTC4 = kCCTexture2DPixelFormat_PVRTC4,
	TextureFormat_PVRTC2 = kCCTexture2DPixelFormat_PVRTC2,
	TextureFormat_Default = kCCTexture2DPixelFormat_Default
};
Q_ENUM_NS(TextureFormat)
}
