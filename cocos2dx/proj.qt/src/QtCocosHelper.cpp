#include "QtCocosHelper.h"

#include "cocos_warnings_off.h"
#include "base_nodes/CCNode.h"
#include "platform/platform.h"
#include "cocos_warnings_pop.h"

namespace cocos2d
{
ccColor3B qColorToCcColor3B(const QColor &color)
{
	return ccc3(
		GLubyte(color.red()), GLubyte(color.green()), GLubyte(color.blue()));
}

QColor ccColor3BToQColor(const ccColor3B &color)
{
	return QColor(color.r, color.g, color.b);
}

ccColor4B qColorToCcColor4B(const QColor &color)
{
	return ccc4(GLubyte(color.red()), GLubyte(color.green()),
		GLubyte(color.blue()), GLubyte(color.alpha()));
}

QColor ccColor4BToQColor(const ccColor4B &color)
{
	return QColor(color.r, color.g, color.b, color.a);
}

ccColor4F qColorToCcColor4F(const QColor &color)
{
	return ccc4f(GLfloat(color.redF()), GLfloat(color.greenF()),
		GLfloat(color.blueF()), GLfloat(color.alphaF()));
}

QColor ccColor4FToQColor(const ccColor4F &color)
{
	QColor result;

	result.setRedF(color.r);
	result.setGreenF(color.g);
	result.setBlueF(color.b);
	result.setAlphaF(color.a);

	return result;
}

qreal getMinPixelWidthForNode(CCNode *node)
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

qreal getMinPixelHeightForNode(CCNode *node)
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

CCRect getWorldRectForNode(CCNode *node, bool *xReversePtr, bool *yReversePtr)
{
	CCRect result;

	bool xReverse = false;
	bool yReverse = false;

	if (nullptr != node)
	{
		result.origin = node->convertToWorldSpace(CCPointZero);
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

qreal getGlobalNodeRotation(CCNode *node)
{
	qreal result = 0.0;

	while (node)
	{
		result += node->getRotation();
		node = node->getParent();
	}

	return result;
}

QPointF getGlobalScaleForNode(CCNode *node)
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
}
