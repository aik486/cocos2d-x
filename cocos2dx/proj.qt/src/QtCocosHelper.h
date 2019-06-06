#pragma once

#include "cocos_warnings_off.h"
#include "include/ccTypes.h"
#include "cocoa/CCGeometry.h"
#include "cocos_warnings_pop.h"

#include <QColor>
#include <QPointF>

namespace cocos2d
{
class CCNode;

QColor ccColor3BToQColor(const ccColor3B &color);
QColor ccColor4BToQColor(const ccColor4B &color);
QColor ccColor4FToQColor(const ccColor4F &color);

ccColor3B qColorToCcColor3B(const QColor &color);
ccColor4B qColorToCcColor4B(const QColor &color);
ccColor4F qColorToCcColor4F(const QColor &color);

qreal getMinPixelWidthForNode(CCNode *node);
qreal getMinPixelHeightForNode(CCNode *node);

QPointF getGlobalScaleForNode(CCNode *node);

qreal getGlobalNodeRotation(CCNode *node);

CCRect getWorldRectForNode(
	CCNode *node, bool *xReversePtr = nullptr, bool *yReversePtr = nullptr);

}
