#pragma once

#include "base/ccTypes.h"
#include "math/CCGeometry.h"
#include "math/CCAffineTransform.h"

#include <QColor>
#include <QPointF>
#include <QSizeF>
#include <QRectF>
#include <QPolygonF>

namespace cocos2d
{
class Node;
using CCShape = QVector<Point>;

QPolygonF shapeFromNode(Node *node);

QPolygonF ccShapeToQPolygonF(const Shape &shape);
Shape qPolygonFToShape(const QPolygonF &poly);

void transformShape(QPolygonF &poly, const AffineTransform &t);
void transformShape(Shape &shape, const AffineTransform &t);

QColor ccColor3BToQColor(const Color3B &color);
QColor ccColor4BToQColor(const Color4B &color);
QColor ccColor4FToQColor(const Color4F &color);

Color3B qColorToCcColor3B(const QColor &color);
Color4B qColorToCcColor4B(const QColor &color);
Color4F qColorToCcColor4F(const QColor &color);

QPoint ccPointToQPoint(const Point &point);
QPointF ccPointToQPointF(const Point &point);
QSize ccSizeToQSize(const Size &size);
QSizeF ccSizeToQSizeF(const Size &size);
QRect ccRectToQRect(const Rect &rect);
QRectF ccRectToQRectF(const Rect &rect);

Point qPointToPoint(const QPoint &point);
Point qPointFToPoint(const QPointF &point);
Size qSizeToSize(const QSize &size);
Size qSizeFToSize(const QSizeF &size);
Rect qRectToRect(const QRect &rect);
Rect qRectFToRect(const QRectF &rect);

qreal getMinPixelWidthForNode(Node *node);
qreal getMinPixelHeightForNode(Node *node);

QPointF getGlobalScaleForNode(Node *node);

qreal getGlobalNodeRotation(Node *node);

Rect getWorldRectForNode(
	Node *node, bool *xReversePtr = nullptr, bool *yReversePtr = nullptr);
}
