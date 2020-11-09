#pragma once

#include "base/ccTypes.h"
#include "math/CCGeometry.h"
#include "math/CCAffineTransform.h"

#include <QColor>
#include <QPointF>
#include <QSizeF>
#include <QRectF>
#include <QPolygonF>
#include <QVector3D>
#include <QVector4D>

namespace cocos2d
{
class Node;
using CCShape = QVector<Point>;

QPolygonF shapeFromNode(Node *node);

QPolygonF ccShapeToQPolygonF(const CCShape &shape);
CCShape qPolygonFToCCShape(const QPolygonF &poly);

void transformShape(QPolygonF &poly, const AffineTransform &t);
void transformShape(CCShape &shape, const AffineTransform &t);

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
QVector2D ccVec2ToQVector2D(const Vec2 &vec);
QVector3D ccVec3ToQVector3D(const Vec3 &vec);
QVector4D ccVec4ToQVector4D(const Vec4 &vec);

Point qPointToCCPoint(const QPoint &point);
Point qPointFToCCPoint(const QPointF &point);
Size qSizeToCCSize(const QSize &size);
Size qSizeFToCCSize(const QSizeF &size);
Rect qRectToCCRect(const QRect &rect);
Rect qRectFToCCRect(const QRectF &rect);
Vec2 qVector2DToCCVec2(const QVector2D &vec);
Vec3 qVector3DToCCVec3(const QVector3D &vec);
Vec4 qVector4DToCCVec4(const QVector4D &vec);

qreal getMinPixelWidthForNode(Node *node);
qreal getMinPixelHeightForNode(Node *node);

QPointF getGlobalScaleForNode(Node *node);

qreal getGlobalNodeRotation(Node *node);

Rect getWorldRectForNode(
	Node *node, bool *xReversePtr = nullptr, bool *yReversePtr = nullptr);
}
