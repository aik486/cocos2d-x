#include "QtCocosHelper.h"

#include "QtCocosExtension.h"

#include "2d/CCNode.h"

namespace cocos2d
{
Color3B qColorToCcColor3B(const QColor &color)
{
	return Color3B(
		quint8(color.red()), quint8(color.green()), quint8(color.blue()));
}

QColor ccColor3BToQColor(const Color3B &color)
{
	return QColor(color.r, color.g, color.b);
}

Color4B qColorToCcColor4B(const QColor &color)
{
	return Color4B(quint8(color.red()), quint8(color.green()),
		quint8(color.blue()), quint8(color.alpha()));
}

QColor ccColor4BToQColor(const Color4B &color)
{
	return QColor(color.r, color.g, color.b, color.a);
}

Color4F qColorToCcColor4F(const QColor &color)
{
	return Color4F(float(color.redF()), float(color.greenF()),
		float(color.blueF()), float(color.alphaF()));
}

QColor ccColor4FToQColor(const Color4F &color)
{
	QColor result;

	result.setRedF(color.r);
	result.setGreenF(color.g);
	result.setBlueF(color.b);
	result.setAlphaF(color.a);

	return result;
}

qreal getMinPixelWidthForNode(Node *node)
{
	qreal result = 1.0;

	while (nullptr != node)
	{
		float xScale = node->getScaleX();
		if (xScale == 0.f)
		{
			result = 0.0;
			break;
		}
		result /= qAbs(xScale);
		node = node->getParent();
	}

	return result;
}

qreal getMinPixelHeightForNode(Node *node)
{
	qreal result = 1.0;

	while (nullptr != node)
	{
		float yScale = node->getScaleY();
		if (yScale == 0.f)
		{
			result = 0.0;
			break;
		}
		result /= qAbs(yScale);
		node = node->getParent();
	}

	return result;
}

Rect getWorldRectForNode(Node *node, bool *xReversePtr, bool *yReversePtr)
{
	Rect result;

	bool xReverse = false;
	bool yReverse = false;

	if (nullptr != node)
	{
		result.origin = node->convertToWorldSpace(Point::ZERO);
		auto right_top = node->convertToWorldSpace(node->getContentSize());

		if (result.origin.x > right_top.x)
		{
			std::swap(result.origin.x, right_top.x);
			xReverse = true;
		}

		if (result.origin.y > right_top.y)
		{
			std::swap(result.origin.y, right_top.y);
			yReverse = true;
		}

		result.size.width = right_top.x - result.origin.x;
		result.size.height = right_top.y - result.origin.y;
	}

	if (nullptr != xReversePtr)
		*xReversePtr = xReverse;

	if (nullptr != yReversePtr)
		*yReversePtr = yReverse;

	return result;
}

qreal getGlobalNodeRotation(Node *node)
{
	qreal result = 0.0;

	while (node)
	{
		result += node->getRotation();
		node = node->getParent();
	}

	return result;
}

QPointF getGlobalScaleForNode(Node *node)
{
	double x = 1.0;
	double y = 1.0;

	while (nullptr != node)
	{
		float xScale = node->getScaleX();
		if (xScale == 0.f)
		{
			x = 0.0;
		} else
		{
			x /= xScale;
		}

		float yScale = node->getScaleY();
		if (yScale == 0.f)
		{
			y = 0.0;
		} else
		{
			y /= yScale;
		}

		node = node->getParent();
	}

	return QPointF(x, y);
}

QPoint ccPointToQPoint(const Point &point)
{
	return QPoint(int(point.x), int(point.y));
}

QPointF ccPointToQPointF(const Point &point)
{
	return QPointF(point.x, point.y);
}

QSize ccSizeToQSize(const Size &size)
{
	return QSize(int(size.width), int(size.height));
}

QSizeF ccSizeToQSizeF(const Size &size)
{
	return QSizeF(size.width, size.height);
}

Point qPointToCCPoint(const QPoint &point)
{
	return Point(point.x(), point.y());
}

Point qPointFToCCPoint(const QPointF &point)
{
	return Point(float(point.x()), float(point.y()));
}

Size qSizeToCCSize(const QSize &size)
{
	return Size(size.width(), size.height());
}

Size qSizeFToCCSize(const QSizeF &size)
{
	return Size(size.width(), size.height());
}

Rect qRectToCCRect(const QRect &rect)
{
	return Rect(rect.x(), rect.y(), rect.width(), rect.height());
}

Rect qRectFToCCRect(const QRectF &rect)
{
	return Rect(float(rect.x()), float(rect.y()), float(rect.width()),
		float(rect.height()));
}

QRect ccRectToQRect(const Rect &rect)
{
	return QRect(int(rect.origin.x), int(rect.origin.y), int(rect.size.width),
		int(rect.size.height));
}

QRectF ccRectToQRectF(const Rect &rect)
{
	return QRectF(
		rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}

QPolygonF ccShapeToQPolygonF(const CCShape &shape)
{
	int size = shape.size();
	QPolygonF result(size);
	for (int i = 0; i < size; i++)
	{
		result[i] = ccPointToQPointF(shape.at(i));
	}
	return result;
}

CCShape qPolygonFToCCShape(const QPolygonF &poly)
{
	int size = poly.size();
	CCShape result(size);
	for (int i = 0; i < size; i++)
	{
		result[i] = qPointFToCCPoint(poly.at(i));
	}
	return result;
}

void transformShape(QPolygonF &poly, const AffineTransform &t)
{
	for (auto &p : poly)
	{
		p = QPointF(qreal(double(t.a * p.x()) + double(t.c * p.y()) + t.tx),
			qreal(double(t.b * p.x()) + double(t.d * p.y()) + t.ty));
	}
}

void transformShape(CCShape &shape, const AffineTransform &t)
{
	for (auto &p : shape)
	{
		p = PointApplyAffineTransform(p, t);
	}
}

QPolygonF shapeFromNode(Node *node)
{
	if (!node)
		return QPolygonF();

	auto shapeNode = dynamic_cast<ShapeProtocol *>(node);
	if (shapeNode)
	{
		return shapeNode->shape();
	}

	auto &size = node->getContentSize();
	return QPolygonF(QRectF(0.0, 0.0, size.width, size.height));
}

QVector3D ccVec3ToQVector3D(const Vec3 &vec)
{
	return QVector3D(vec.x, vec.y, vec.z);
}

QVector2D ccVec2ToQVector2D(const Vec2 &vec)
{
	return QVector2D(vec.x, vec.y);
}

QVector4D ccVec4ToQVector4D(const Vec4 &vec)
{
	return QVector4D(vec.x, vec.y, vec.z, vec.w);
}

Vec2 qVector2DToCCVec2(const QVector2D &vec)
{
	return Vec2(vec.x(), vec.y());
}

Vec3 qVector3DToCCVec3(const QVector3D &vec)
{
	return Vec3(vec.x(), vec.y(), vec.z());
}

Vec4 qVector4DToCCVec4(const QVector4D &vec)
{
	return Vec4(vec.x(), vec.y(), vec.z(), vec.w());
}
}
