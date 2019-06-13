#pragma once

#include "cocos_warnings_off.h"
#include "include/ccTypes.h"
#include "cocoa/CCGeometry.h"
#include "cocos_warnings_pop.h"

#include <QColor>
#include <QPointF>
#include <QSizeF>
#include <QRectF>

namespace cocos2d
{
class CCNode;

QColor ccColor3BToQColor(const ccColor3B &color);
QColor ccColor4BToQColor(const ccColor4B &color);
QColor ccColor4FToQColor(const ccColor4F &color);

ccColor3B qColorToCcColor3B(const QColor &color);
ccColor4B qColorToCcColor4B(const QColor &color);
ccColor4F qColorToCcColor4F(const QColor &color);

QPoint ccPointToQPoint(const CCPoint &point);
QPointF ccPointToQPointF(const CCPoint &point);
QSize ccSizeToQSize(const CCSize &size);
QSizeF ccSizeToQSizeF(const CCSize &size);
QRect ccRectToQRect(const CCRect &rect);
QRectF ccRectToQRectF(const CCRect &rect);

CCPoint qPointToCCPoint(const QPoint &point);
CCPoint qPointFToCCPoint(const QPointF &point);
CCSize qSizeToCCSize(const QSize &size);
CCSize qSizeFToCCSize(const QSizeF &size);
CCRect qRectToCCRect(const QRect &rect);
CCRect qRectFToCCRect(const QRectF &rect);

qreal getMinPixelWidthForNode(CCNode *node);
qreal getMinPixelHeightForNode(CCNode *node);

QPointF getGlobalScaleForNode(CCNode *node);

qreal getGlobalNodeRotation(CCNode *node);

CCRect getWorldRectForNode(
	CCNode *node, bool *xReversePtr = nullptr, bool *yReversePtr = nullptr);
}
