#include "qtscript_cocos2dx.hpp"
#include "QtScriptUtils.h"

namespace cocos2d {
QtScriptCCDataVisitor::QtScriptCCDataVisitor(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCDataVisitor *, false>(engine, className)
{
}

QtScriptCCDataVisitor::QtScriptCCDataVisitor(QScriptEngine *engine)
	: QtScriptCCDataVisitor(engine, "DataVisitor")
{
}

void QtScriptCCDataVisitor::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCDataVisitor, QtScriptCCDataVisitor>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCDataVisitor::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDataVisitor::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDataVisitor::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCDataVisitor");
	return false;
}

void QtScriptCCDataVisitor::visitDict(const cocos2d::CCDictionary* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitString(const cocos2d::CCString* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitDouble(const cocos2d::CCDouble* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitArray(const cocos2d::CCArray* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitSet(const cocos2d::CCSet* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitBool(const cocos2d::CCBool* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitFloat(const cocos2d::CCFloat* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

void QtScriptCCDataVisitor::visitInt(const cocos2d::CCInteger* p)
{
	auto __o = this->thiz<CCDataVisitor *>();
	if (__o)
	{
		__o->visit(p);
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCPrettyPrinter::QtScriptCCPrettyPrinter(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCDataVisitor(engine, className)
{
}

QtScriptCCPrettyPrinter::QtScriptCCPrettyPrinter(QScriptEngine *engine)
	: QtScriptCCPrettyPrinter(engine, "PrettyPrinter")
{
}

void QtScriptCCPrettyPrinter::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCDataVisitor *>());
	auto ctor = RegisterT<CCPrettyPrinter, QtScriptCCPrettyPrinter>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCPrettyPrinter::clear()
{
	auto __o = this->thiz<CCPrettyPrinter *>();
	if (__o)
	{
		__o->clear();
	}
}

void QtScriptCCPrettyPrinter::visitObject(const cocos2d::CCObject* p)
{
	auto __o = this->thiz<CCPrettyPrinter *>();
	if (__o)
	{
		__o->visitObject(p);
	}
}

QByteArray QtScriptCCPrettyPrinter::getResult()
{
	auto __o = this->thiz<CCPrettyPrinter *>();
	if (__o)
	{
		return QByteArray(__o->getResult().c_str(), int(__o->getResult().size()));
	}
	return QByteArray();
}

int QtScriptCCPrettyPrinter::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCPrettyPrinter::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCPrettyPrinter::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCPrettyPrinter();
			ok = true;
			break;
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<int>(context->argument(0));
			out = new CCPrettyPrinter(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPrettyPrinter constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCPoint::QtScriptCCPoint(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCPoint, false>(engine, className)
{
}

QtScriptCCPoint::QtScriptCCPoint(QScriptEngine *engine)
	: QtScriptCCPoint(engine, "Point")
{
}

void QtScriptCCPoint::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	QScriptValue inherit;
	auto ctor = RegisterT<CCPoint, QtScriptCCPoint>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("forAngle", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCPoint::forAngle)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCPoint::set(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		__o->operator=(other);
	}
}

float QtScriptCCPoint::getDistanceSq(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getDistanceSq(other);
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCPoint::normalize()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->normalize();
	}
	return cocos2d::CCPoint();
}

float QtScriptCCPoint::getLengthSq()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getLengthSq();
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCPoint::sub(const cocos2d::CCPoint& right)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->operator-(right);
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCPoint::neg()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->operator-();
	}
	return cocos2d::CCPoint();
}

float QtScriptCCPoint::cross(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->cross(other);
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCPoint::rotateByAngle(const cocos2d::CCPoint& pivot, float angle)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->rotateByAngle(pivot, angle);
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCPoint::add(const cocos2d::CCPoint& right)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->operator+(right);
	}
	return cocos2d::CCPoint();
}

bool QtScriptCCPoint::fuzzyEquals(const cocos2d::CCPoint& target, float variance)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->fuzzyEquals(target, variance);
	}
	return false;
}

float QtScriptCCPoint::getDistance(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getDistance(other);
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCPoint::unrotate(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->unrotate(other);
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCPoint::mul(float a)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->operator*(a);
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCPoint::lerp(const cocos2d::CCPoint& other, float alpha)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->lerp(other, alpha);
	}
	return cocos2d::CCPoint();
}

bool QtScriptCCPoint::equals(const cocos2d::CCPoint& target)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->equals(target);
	}
	return false;
}

cocos2d::CCPoint QtScriptCCPoint::getPerp()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getPerp();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCPoint::rotate(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->rotate(other);
	}
	return cocos2d::CCPoint();
}

float QtScriptCCPoint::getAngle()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getAngle();
	}
	return static_cast<float>(0);
}

float QtScriptCCPoint::getAngle(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getAngle(other);
	}
	return static_cast<float>(0);
}

void QtScriptCCPoint::setPoint(float x, float y)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		__o->setPoint(x, y);
	}
}

cocos2d::CCPoint QtScriptCCPoint::project(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->project(other);
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCPoint::getRPerp()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getRPerp();
	}
	return cocos2d::CCPoint();
}

float QtScriptCCPoint::getLength()
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->getLength();
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCPoint::div(float a)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->operator/(a);
	}
	return cocos2d::CCPoint();
}

float QtScriptCCPoint::dot(const cocos2d::CCPoint& other)
{
	auto __o = this->thiz<CCPoint *>();
	if (__o)
	{
		return __o->dot(other);
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCPoint::forAngle(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCPoint::forAngle(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPoint::forAngle");
	return __e->uncaughtException();
}

int QtScriptCCPoint::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCPoint::constructorArgumentCountMax() const
{
	return 2;
}

bool QtScriptCCPoint::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(0));
			out = CCPoint(arg0);
			ok = true;
			break;
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			out = CCPoint(arg0, arg1);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPoint constructor");
	}
	return ok;
}

float QtScriptCCPoint::_public_field_get_x() const
{
	auto object = thiz<CCPoint *>();
	if (object)
	{
		return object->x;
	}
	return static_cast<float>(0);
}

void QtScriptCCPoint::_public_field_set_x(float value)
{
	auto object = thiz<CCPoint *>();
	if (object)
	{
		object->x = value;
	}
}

float QtScriptCCPoint::_public_field_get_y() const
{
	auto object = thiz<CCPoint *>();
	if (object)
	{
		return object->y;
	}
	return static_cast<float>(0);
}

void QtScriptCCPoint::_public_field_set_y(float value)
{
	auto object = thiz<CCPoint *>();
	if (object)
	{
		object->y = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSize::QtScriptCCSize(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCSize, false>(engine, className)
{
}

QtScriptCCSize::QtScriptCCSize(QScriptEngine *engine)
	: QtScriptCCSize(engine, "Size")
{
}

void QtScriptCCSize::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCSize, QtScriptCCSize>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCSize::set(const cocos2d::CCSize& other)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		__o->operator=(other);
	}
}

cocos2d::CCSize QtScriptCCSize::sub(const cocos2d::CCSize& right)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		return __o->operator-(right);
	}
	return cocos2d::CCSize();
}

bool QtScriptCCSize::equals(const cocos2d::CCSize& target)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		return __o->equals(target);
	}
	return false;
}

cocos2d::CCSize QtScriptCCSize::add(const cocos2d::CCSize& right)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		return __o->operator+(right);
	}
	return cocos2d::CCSize();
}

cocos2d::CCSize QtScriptCCSize::mul(float a)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		return __o->operator*(a);
	}
	return cocos2d::CCSize();
}

cocos2d::CCSize QtScriptCCSize::div(float a)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		return __o->operator/(a);
	}
	return cocos2d::CCSize();
}

void QtScriptCCSize::setSize(float width, float height)
{
	auto __o = this->thiz<CCSize *>();
	if (__o)
	{
		__o->setSize(width, height);
	}
}

int QtScriptCCSize::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSize::constructorArgumentCountMax() const
{
	return 2;
}

bool QtScriptCCSize::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			out = CCSize(arg0);
			ok = true;
			break;
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			out = CCSize(arg0, arg1);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSize constructor");
	}
	return ok;
}

float QtScriptCCSize::_public_field_get_width() const
{
	auto object = thiz<CCSize *>();
	if (object)
	{
		return object->width;
	}
	return static_cast<float>(0);
}

void QtScriptCCSize::_public_field_set_width(float value)
{
	auto object = thiz<CCSize *>();
	if (object)
	{
		object->width = value;
	}
}

float QtScriptCCSize::_public_field_get_height() const
{
	auto object = thiz<CCSize *>();
	if (object)
	{
		return object->height;
	}
	return static_cast<float>(0);
}

void QtScriptCCSize::_public_field_set_height(float value)
{
	auto object = thiz<CCSize *>();
	if (object)
	{
		object->height = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRect::QtScriptCCRect(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCRect, false>(engine, className)
{
}

QtScriptCCRect::QtScriptCCRect(QScriptEngine *engine)
	: QtScriptCCRect(engine, "Rect")
{
}

void QtScriptCCRect::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCRect, QtScriptCCRect>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCRect::set(const cocos2d::CCRect& other)
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		__o->operator=(other);
	}
}

float QtScriptCCRect::getMaxY()
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->getMaxY();
	}
	return static_cast<float>(0);
}

float QtScriptCCRect::getMaxX()
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->getMaxX();
	}
	return static_cast<float>(0);
}

bool QtScriptCCRect::equals(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->equals(rect);
	}
	return false;
}

float QtScriptCCRect::getMinY()
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->getMinY();
	}
	return static_cast<float>(0);
}

float QtScriptCCRect::getMinX()
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->getMinX();
	}
	return static_cast<float>(0);
}

float QtScriptCCRect::getMidY()
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->getMidY();
	}
	return static_cast<float>(0);
}

float QtScriptCCRect::getMidX()
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->getMidX();
	}
	return static_cast<float>(0);
}

bool QtScriptCCRect::intersectsRect(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->intersectsRect(rect);
	}
	return false;
}

bool QtScriptCCRect::containsPoint(const cocos2d::CCPoint& point)
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		return __o->containsPoint(point);
	}
	return false;
}

void QtScriptCCRect::setRect(float x, float y, float width, float height)
{
	auto __o = this->thiz<CCRect *>();
	if (__o)
	{
		__o->setRect(x, y, width, height);
	}
}

int QtScriptCCRect::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRect::constructorArgumentCountMax() const
{
	return 4;
}

bool QtScriptCCRect::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(0));
			out = CCRect(arg0);
			ok = true;
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			out = CCRect(arg0, arg1, arg2, arg3);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRect constructor");
	}
	return ok;
}

cocos2d::CCPoint QtScriptCCRect::_public_field_get_origin() const
{
	auto object = thiz<CCRect *>();
	if (object)
	{
		return object->origin;
	}
	return cocos2d::CCPoint();
}

void QtScriptCCRect::_public_field_set_origin(const cocos2d::CCPoint& value)
{
	auto object = thiz<CCRect *>();
	if (object)
	{
		object->origin = value;
	}
}

cocos2d::CCSize QtScriptCCRect::_public_field_get_size() const
{
	auto object = thiz<CCRect *>();
	if (object)
	{
		return object->size;
	}
	return cocos2d::CCSize();
}

void QtScriptCCRect::_public_field_set_size(const cocos2d::CCSize& value)
{
	auto object = thiz<CCRect *>();
	if (object)
	{
		object->size = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAction::QtScriptCCAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCAction::QtScriptCCAction(QScriptEngine *engine)
	: QtScriptCCAction(engine, "Action")
{
}

void QtScriptCCAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCAction, QtScriptCCAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAction::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCAction::startWithTarget(cocos2d::CCNode* pTarget)
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		__o->startWithTarget(pTarget);
	}
}

QByteArray QtScriptCCAction::description()
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

void QtScriptCCAction::setOriginalTarget(cocos2d::CCNode* pOriginalTarget)
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		__o->setOriginalTarget(pOriginalTarget);
	}
}

void QtScriptCCAction::setTarget(cocos2d::CCNode* pTarget)
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		__o->setTarget(pTarget);
	}
}

cocos2d::CCNode* QtScriptCCAction::getOriginalTarget()
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		return __o->getOriginalTarget();
	}
	return nullptr;
}

void QtScriptCCAction::stop()
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		__o->stop();
	}
}

cocos2d::CCNode* QtScriptCCAction::getTarget()
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		return __o->getTarget();
	}
	return nullptr;
}

void QtScriptCCAction::step(float dt)
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		__o->step(dt);
	}
}

void QtScriptCCAction::setTag(int nTag)
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		__o->setTag(nTag);
	}
}

int QtScriptCCAction::getTag()
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		return __o->getTag();
	}
	return 0;
}

bool QtScriptCCAction::isDone()
{
	auto __o = this->thiz<CCAction *>();
	if (__o)
	{
		return __o->isDone();
	}
	return false;
}

QScriptValue QtScriptCCAction::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCAction::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAction::create");
	return __e->uncaughtException();
}

int QtScriptCCAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAction();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAction constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFiniteTimeAction::QtScriptCCFiniteTimeAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCAction(engine, className)
{
}

QtScriptCCFiniteTimeAction::QtScriptCCFiniteTimeAction(QScriptEngine *engine)
	: QtScriptCCFiniteTimeAction(engine, "FiniteTimeAction")
{
}

void QtScriptCCFiniteTimeAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCAction *>());
	auto ctor = RegisterT<CCFiniteTimeAction, QtScriptCCFiniteTimeAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCFiniteTimeAction::setDuration(float duration)
{
	auto __o = this->thiz<CCFiniteTimeAction *>();
	if (__o)
	{
		__o->setDuration(duration);
	}
}

cocos2d::CCFiniteTimeAction* QtScriptCCFiniteTimeAction::reverse()
{
	auto __o = this->thiz<CCFiniteTimeAction *>();
	if (__o)
	{
		return __o->reverse();
	}
	return nullptr;
}

float QtScriptCCFiniteTimeAction::getDuration()
{
	auto __o = this->thiz<CCFiniteTimeAction *>();
	if (__o)
	{
		return __o->getDuration();
	}
	return static_cast<float>(0);
}

int QtScriptCCFiniteTimeAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFiniteTimeAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFiniteTimeAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCFiniteTimeAction();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFiniteTimeAction constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSpeed::QtScriptCCSpeed(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCAction(engine, className)
{
}

QtScriptCCSpeed::QtScriptCCSpeed(QScriptEngine *engine)
	: QtScriptCCSpeed(engine, "Speed")
{
}

void QtScriptCCSpeed::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCAction *>());
	auto ctor = RegisterT<CCSpeed, QtScriptCCSpeed>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpeed::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCSpeed::setInnerAction(cocos2d::CCActionInterval* pAction)
{
	auto __o = this->thiz<CCSpeed *>();
	if (__o)
	{
		__o->setInnerAction(pAction);
	}
}

float QtScriptCCSpeed::getSpeed()
{
	auto __o = this->thiz<CCSpeed *>();
	if (__o)
	{
		return __o->getSpeed();
	}
	return static_cast<float>(0);
}

void QtScriptCCSpeed::setSpeed(float fSpeed)
{
	auto __o = this->thiz<CCSpeed *>();
	if (__o)
	{
		__o->setSpeed(fSpeed);
	}
}

bool QtScriptCCSpeed::initWithAction(cocos2d::CCActionInterval* pAction, float fSpeed)
{
	auto __o = this->thiz<CCSpeed *>();
	if (__o)
	{
		return __o->initWithAction(pAction, fSpeed);
	}
	return false;
}

cocos2d::CCActionInterval* QtScriptCCSpeed::getInnerAction()
{
	auto __o = this->thiz<CCSpeed *>();
	if (__o)
	{
		return __o->getInnerAction();
	}
	return nullptr;
}

cocos2d::CCActionInterval* QtScriptCCSpeed::reverse()
{
	auto __o = this->thiz<CCSpeed *>();
	if (__o)
	{
		return __o->reverse();
	}
	return nullptr;
}

QScriptValue QtScriptCCSpeed::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCSpeed::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpeed::create");
	return __e->uncaughtException();
}

int QtScriptCCSpeed::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSpeed::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSpeed::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCSpeed();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpeed constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFollow::QtScriptCCFollow(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCAction(engine, className)
{
}

QtScriptCCFollow::QtScriptCCFollow(QScriptEngine *engine)
	: QtScriptCCFollow(engine, "Follow")
{
}

void QtScriptCCFollow::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCAction *>());
	auto ctor = RegisterT<CCFollow, QtScriptCCFollow>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFollow::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCFollow::initWithTarget(cocos2d::CCNode* pFollowedNode)
{
	auto __o = this->thiz<CCFollow *>();
	if (__o)
	{
		return __o->initWithTarget(pFollowedNode);
	}
	return false;
}

bool QtScriptCCFollow::initWithTarget(cocos2d::CCNode* pFollowedNode, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCFollow *>();
	if (__o)
	{
		return __o->initWithTarget(pFollowedNode, rect);
	}
	return false;
}

void QtScriptCCFollow::setBoundarySet(bool bValue)
{
	auto __o = this->thiz<CCFollow *>();
	if (__o)
	{
		__o->setBoundarySet(bValue);
	}
}

bool QtScriptCCFollow::isBoundarySet()
{
	auto __o = this->thiz<CCFollow *>();
	if (__o)
	{
		return __o->isBoundarySet();
	}
	return false;
}

QScriptValue QtScriptCCFollow::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			return __e->toScriptValue(CCFollow::create(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			return __e->toScriptValue(CCFollow::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFollow::create");
	return __e->uncaughtException();
}

int QtScriptCCFollow::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFollow::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFollow::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCFollow();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFollow constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAffineTransform::QtScriptCCAffineTransform(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCAffineTransform, false>(engine, className)
{
}

QtScriptCCAffineTransform::QtScriptCCAffineTransform(QScriptEngine *engine)
	: QtScriptCCAffineTransform(engine, "AffineTransform")
{
}

void QtScriptCCAffineTransform::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCAffineTransform, QtScriptCCAffineTransform>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCAffineTransform::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAffineTransform::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAffineTransform::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCAffineTransform constructor");
	return false;
}

float QtScriptCCAffineTransform::_public_field_get_a() const
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		return object->a;
	}
	return static_cast<float>(0);
}

void QtScriptCCAffineTransform::_public_field_set_a(float value)
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		object->a = value;
	}
}

float QtScriptCCAffineTransform::_public_field_get_b() const
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		return object->b;
	}
	return static_cast<float>(0);
}

void QtScriptCCAffineTransform::_public_field_set_b(float value)
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		object->b = value;
	}
}

float QtScriptCCAffineTransform::_public_field_get_c() const
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		return object->c;
	}
	return static_cast<float>(0);
}

void QtScriptCCAffineTransform::_public_field_set_c(float value)
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		object->c = value;
	}
}

float QtScriptCCAffineTransform::_public_field_get_d() const
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		return object->d;
	}
	return static_cast<float>(0);
}

void QtScriptCCAffineTransform::_public_field_set_d(float value)
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		object->d = value;
	}
}

float QtScriptCCAffineTransform::_public_field_get_tx() const
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		return object->tx;
	}
	return static_cast<float>(0);
}

void QtScriptCCAffineTransform::_public_field_set_tx(float value)
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		object->tx = value;
	}
}

float QtScriptCCAffineTransform::_public_field_get_ty() const
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		return object->ty;
	}
	return static_cast<float>(0);
}

void QtScriptCCAffineTransform::_public_field_set_ty(float value)
{
	auto object = thiz<CCAffineTransform *>();
	if (object)
	{
		object->ty = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCArray::QtScriptCCArray(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCArray::QtScriptCCArray(QScriptEngine *engine)
	: QtScriptCCArray(engine, "Array")
{
}

void QtScriptCCArray::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCArray, QtScriptCCArray>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("createWithContentsOfFile", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCArray::createWithContentsOfFile)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithArray", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCArray::createWithArray)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithCapacity", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCArray::createWithCapacity)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithObject", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCArray::createWithObject)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithContentsOfFileThreadSafe", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCArray::createWithContentsOfFileThreadSafe)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCArray::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCArray::initWithArray(cocos2d::CCArray* otherArray)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->initWithArray(otherArray);
	}
	return false;
}

void QtScriptCCArray::reverseObjects()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->reverseObjects();
	}
}

void QtScriptCCArray::insertObject(cocos2d::CCObject* object, unsigned int index)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->insertObject(object, index);
	}
}

void QtScriptCCArray::removeAllObjects()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeAllObjects();
	}
}

void QtScriptCCArray::exchangeObjectAtIndex(unsigned int index1, unsigned int index2)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->exchangeObjectAtIndex(index1, index2);
	}
}

bool QtScriptCCArray::containsObject(cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->containsObject(object);
	}
	return false;
}

unsigned int QtScriptCCArray::capacity()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->capacity();
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCArray::initWithCapacity(unsigned int capacity)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->initWithCapacity(capacity);
	}
	return false;
}

bool QtScriptCCArray::init()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

void QtScriptCCArray::removeObjectsInArray(cocos2d::CCArray* otherArray)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeObjectsInArray(otherArray);
	}
}

void QtScriptCCArray::fastRemoveObjectAtIndex(unsigned int index)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->fastRemoveObjectAtIndex(index);
	}
}

void QtScriptCCArray::addObject(cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->addObject(object);
	}
}

unsigned int QtScriptCCArray::indexOfObject(cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->indexOfObject(object);
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCArray::addObjectsFromArray(cocos2d::CCArray* otherArray)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->addObjectsFromArray(otherArray);
	}
}

cocos2d::CCObject* QtScriptCCArray::lastObject()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->lastObject();
	}
	return nullptr;
}

void QtScriptCCArray::exchangeObject(cocos2d::CCObject* object1, cocos2d::CCObject* object2)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->exchangeObject(object1, object2);
	}
}

void QtScriptCCArray::fastRemoveObject(cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->fastRemoveObject(object);
	}
}

void QtScriptCCArray::replaceObjectAtIndex(unsigned int uIndex, cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->replaceObjectAtIndex(uIndex, pObject);
	}
}

void QtScriptCCArray::replaceObjectAtIndex(unsigned int uIndex, cocos2d::CCObject* pObject, bool bReleaseObject)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->replaceObjectAtIndex(uIndex, pObject, bReleaseObject);
	}
}

cocos2d::CCObject* QtScriptCCArray::randomObject()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->randomObject();
	}
	return nullptr;
}

void QtScriptCCArray::reduceMemoryFootprint()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->reduceMemoryFootprint();
	}
}

bool QtScriptCCArray::isEqualToArray(cocos2d::CCArray* pOtherArray)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->isEqualToArray(pOtherArray);
	}
	return false;
}

unsigned int QtScriptCCArray::count()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->count();
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCArray::initWithObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->initWithObject(pObject);
	}
	return false;
}

void QtScriptCCArray::removeObjectAtIndex(unsigned int index)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeObjectAtIndex(index);
	}
}

void QtScriptCCArray::removeObjectAtIndex(unsigned int index, bool bReleaseObj)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeObjectAtIndex(index, bReleaseObj);
	}
}

void QtScriptCCArray::removeLastObject()
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeLastObject();
	}
}

void QtScriptCCArray::removeLastObject(bool bReleaseObj)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeLastObject(bReleaseObj);
	}
}

void QtScriptCCArray::removeObject(cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeObject(object);
	}
}

void QtScriptCCArray::removeObject(cocos2d::CCObject* object, bool bReleaseObj)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		__o->removeObject(object, bReleaseObj);
	}
}

cocos2d::CCObject* QtScriptCCArray::objectAtIndex(unsigned int index)
{
	auto __o = this->thiz<CCArray *>();
	if (__o)
	{
		return __o->objectAtIndex(index);
	}
	return nullptr;
}

QScriptValue QtScriptCCArray::createWithContentsOfFile(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCArray::createWithContentsOfFile(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray::createWithContentsOfFile");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCArray::createWithArray(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			return __e->toScriptValue(CCArray::createWithArray(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray::createWithArray");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCArray::createWithCapacity(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCArray::createWithCapacity(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray::createWithCapacity");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCArray::createWithObject(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCObject*>(context->argument(0));
			return __e->toScriptValue(CCArray::createWithObject(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray::createWithObject");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCArray::createWithContentsOfFileThreadSafe(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCArray::createWithContentsOfFileThreadSafe(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray::createWithContentsOfFileThreadSafe");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCArray::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCArray::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray::create");
	return __e->uncaughtException();
}

int QtScriptCCArray::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCArray::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCArray::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCArray();
			ok = true;
			break;
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			out = new CCArray(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCArray constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCGLProgram::QtScriptCCGLProgram(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCGLProgram::QtScriptCCGLProgram(QScriptEngine *engine)
	: QtScriptCCGLProgram(engine, "GLProgram")
{
}

void QtScriptCCGLProgram::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCGLProgram, QtScriptCCGLProgram>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCGLProgram::reset()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->reset();
	}
}

void QtScriptCCGLProgram::use()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->use();
	}
}

void QtScriptCCGLProgram::setUniformLocationWith1i(int location, int i1)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith1i(location, i1);
	}
}

void QtScriptCCGLProgram::setUniformLocationWith2f(int location, float f1, float f2)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith2f(location, f1, f2);
	}
}

QByteArray QtScriptCCGLProgram::vertexShaderLog()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return QByteArray(__o->vertexShaderLog());
	}
	return QByteArray();
}

void QtScriptCCGLProgram::setUniformLocationWith1f(int location, float f1)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith1f(location, f1);
	}
}

unsigned int QtScriptCCGLProgram::getProgram()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return __o->getProgram();
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCGLProgram::initWithVertexShaderFilename(const QByteArray& vShaderFilename, const QByteArray& fShaderFilename)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return __o->initWithVertexShaderFilename(vShaderFilename.data(), fShaderFilename.data());
	}
	return false;
}

void QtScriptCCGLProgram::updateUniforms()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->updateUniforms();
	}
}

QByteArray QtScriptCCGLProgram::fragmentShaderLog()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return QByteArray(__o->fragmentShaderLog());
	}
	return QByteArray();
}

void QtScriptCCGLProgram::addAttribute(const QByteArray& attributeName, unsigned int index)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->addAttribute(attributeName.data(), index);
	}
}

QByteArray QtScriptCCGLProgram::programLog()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return QByteArray(__o->programLog());
	}
	return QByteArray();
}

bool QtScriptCCGLProgram::initWithVertexShaderByteArray(const QByteArray& vShaderByteArray, const QByteArray& fShaderByteArray)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return __o->initWithVertexShaderByteArray(vShaderByteArray.data(), fShaderByteArray.data());
	}
	return false;
}

void QtScriptCCGLProgram::setUniformLocationWith3f(int location, float f1, float f2, float f3)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith3f(location, f1, f2, f3);
	}
}

bool QtScriptCCGLProgram::link()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return __o->link();
	}
	return false;
}

void QtScriptCCGLProgram::setUniformLocationWith2i(int location, int i1, int i2)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith2i(location, i1, i2);
	}
}

void QtScriptCCGLProgram::setUniformsForBuiltins()
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformsForBuiltins();
	}
}

void QtScriptCCGLProgram::setUniformLocationWith4f(int location, float f1, float f2, float f3, float f4)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith4f(location, f1, f2, f3, f4);
	}
}

void QtScriptCCGLProgram::setUniformLocationWith4i(int location, int i1, int i2, int i3, int i4)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith4i(location, i1, i2, i3, i4);
	}
}

void QtScriptCCGLProgram::setUniformLocationWith3i(int location, int i1, int i2, int i3)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		__o->setUniformLocationWith3i(location, i1, i2, i3);
	}
}

int QtScriptCCGLProgram::getUniformLocationForName(const QByteArray& name)
{
	auto __o = this->thiz<CCGLProgram *>();
	if (__o)
	{
		return __o->getUniformLocationForName(name.data());
	}
	return 0;
}

int QtScriptCCGLProgram::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCGLProgram::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCGLProgram::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCGLProgram();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGLProgram constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAcceleration::QtScriptCCAcceleration(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCAcceleration, false>(engine, className)
{
}

QtScriptCCAcceleration::QtScriptCCAcceleration(QScriptEngine *engine)
	: QtScriptCCAcceleration(engine, "Acceleration")
{
}

void QtScriptCCAcceleration::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCAcceleration, QtScriptCCAcceleration>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCAcceleration::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAcceleration::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAcceleration::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCAcceleration constructor");
	return false;
}

double QtScriptCCAcceleration::_public_field_get_x() const
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		return object->x;
	}
	return static_cast<double>(0);
}

void QtScriptCCAcceleration::_public_field_set_x(double value)
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		object->x = value;
	}
}

double QtScriptCCAcceleration::_public_field_get_y() const
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		return object->y;
	}
	return static_cast<double>(0);
}

void QtScriptCCAcceleration::_public_field_set_y(double value)
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		object->y = value;
	}
}

double QtScriptCCAcceleration::_public_field_get_z() const
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		return object->z;
	}
	return static_cast<double>(0);
}

void QtScriptCCAcceleration::_public_field_set_z(double value)
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		object->z = value;
	}
}

double QtScriptCCAcceleration::_public_field_get_timestamp() const
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		return object->timestamp;
	}
	return static_cast<double>(0);
}

void QtScriptCCAcceleration::_public_field_set_timestamp(double value)
{
	auto object = thiz<CCAcceleration *>();
	if (object)
	{
		object->timestamp = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTouch::QtScriptCCTouch(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTouch::QtScriptCCTouch(QScriptEngine *engine)
	: QtScriptCCTouch(engine, "Touch")
{
}

void QtScriptCCTouch::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTouch, QtScriptCCTouch>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

cocos2d::CCPoint QtScriptCCTouch::getPreviousLocationInView()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getPreviousLocationInView();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCTouch::getLocation()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getLocation();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCTouch::getDelta()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getDelta();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCTouch::getStartLocationInView()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getStartLocationInView();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCTouch::getStartLocation()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getStartLocation();
	}
	return cocos2d::CCPoint();
}

int QtScriptCCTouch::getID()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getID();
	}
	return 0;
}

void QtScriptCCTouch::setTouchInfo(int id, float x, float y)
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		__o->setTouchInfo(id, x, y);
	}
}

cocos2d::CCPoint QtScriptCCTouch::getLocationInView()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getLocationInView();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCPoint QtScriptCCTouch::getPreviousLocation()
{
	auto __o = this->thiz<CCTouch *>();
	if (__o)
	{
		return __o->getPreviousLocation();
	}
	return cocos2d::CCPoint();
}

int QtScriptCCTouch::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTouch::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTouch::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTouch();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTouch constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEvent::QtScriptCCEvent(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCEvent::QtScriptCCEvent(QScriptEngine *engine)
	: QtScriptCCEvent(engine, "Event")
{
}

void QtScriptCCEvent::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCEvent, QtScriptCCEvent>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCEvent::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEvent::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEvent::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEvent;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEvent constructor");
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSet::QtScriptCCSet(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCSet::QtScriptCCSet(QScriptEngine *engine)
	: QtScriptCCSet(engine, "Set")
{
}

void QtScriptCCSet::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCSet, QtScriptCCSet>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSet::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSet::count()
{
	auto __o = this->thiz<CCSet *>();
	if (__o)
	{
		return __o->count();
	}
	return 0;
}

void QtScriptCCSet::addObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCSet *>();
	if (__o)
	{
		__o->addObject(pObject);
	}
}

cocos2d::CCObject* QtScriptCCSet::anyObject()
{
	auto __o = this->thiz<CCSet *>();
	if (__o)
	{
		return __o->anyObject();
	}
	return nullptr;
}

void QtScriptCCSet::removeAllObjects()
{
	auto __o = this->thiz<CCSet *>();
	if (__o)
	{
		__o->removeAllObjects();
	}
}

void QtScriptCCSet::removeObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCSet *>();
	if (__o)
	{
		__o->removeObject(pObject);
	}
}

bool QtScriptCCSet::containsObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCSet *>();
	if (__o)
	{
		return __o->containsObject(pObject);
	}
	return false;
}

QScriptValue QtScriptCCSet::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCSet::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSet::create");
	return __e->uncaughtException();
}

int QtScriptCCSet::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSet::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSet::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCSet();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSet constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCScriptHandlerEntry::QtScriptCCScriptHandlerEntry(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCScriptHandlerEntry::QtScriptCCScriptHandlerEntry(QScriptEngine *engine)
	: QtScriptCCScriptHandlerEntry(engine, "ScriptHandlerEntry")
{
}

void QtScriptCCScriptHandlerEntry::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCScriptHandlerEntry, QtScriptCCScriptHandlerEntry>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCScriptHandlerEntry::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCScriptHandlerEntry::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCScriptHandlerEntry::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCScriptHandlerEntry::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCScriptHandlerEntry");
	return false;
}

int64_t QtScriptCCScriptHandlerEntry::getHandler()
{
	auto __o = this->thiz<CCScriptHandlerEntry *>();
	if (__o)
	{
		return __o->getHandler();
	}
	return static_cast<int64_t>(0);
}

unsigned int QtScriptCCScriptHandlerEntry::getEntryId()
{
	auto __o = this->thiz<CCScriptHandlerEntry *>();
	if (__o)
	{
		return __o->getEntryId();
	}
	return static_cast<unsigned int>(0);
}

QScriptValue QtScriptCCScriptHandlerEntry::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<int64_t>(context->argument(0));
			return __e->toScriptValue(CCScriptHandlerEntry::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCScriptHandlerEntry::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSchedulerScriptHandlerEntry::QtScriptCCSchedulerScriptHandlerEntry(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCScriptHandlerEntry(engine, className)
{
}

QtScriptCCSchedulerScriptHandlerEntry::QtScriptCCSchedulerScriptHandlerEntry(QScriptEngine *engine)
	: QtScriptCCSchedulerScriptHandlerEntry(engine, "SchedulerScriptHandlerEntry")
{
}

void QtScriptCCSchedulerScriptHandlerEntry::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCScriptHandlerEntry *>());
	auto ctor = RegisterT<CCSchedulerScriptHandlerEntry, QtScriptCCSchedulerScriptHandlerEntry>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSchedulerScriptHandlerEntry::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSchedulerScriptHandlerEntry::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSchedulerScriptHandlerEntry::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSchedulerScriptHandlerEntry::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCSchedulerScriptHandlerEntry");
	return false;
}

bool QtScriptCCSchedulerScriptHandlerEntry::isMarkedForDeletion()
{
	auto __o = this->thiz<CCSchedulerScriptHandlerEntry *>();
	if (__o)
	{
		return __o->isMarkedForDeletion();
	}
	return false;
}

void QtScriptCCSchedulerScriptHandlerEntry::markedForDeletion()
{
	auto __o = this->thiz<CCSchedulerScriptHandlerEntry *>();
	if (__o)
	{
		__o->markedForDeletion();
	}
}

bool QtScriptCCSchedulerScriptHandlerEntry::isPaused()
{
	auto __o = this->thiz<CCSchedulerScriptHandlerEntry *>();
	if (__o)
	{
		return __o->isPaused();
	}
	return false;
}

cocos2d::CCTimer* QtScriptCCSchedulerScriptHandlerEntry::getTimer()
{
	auto __o = this->thiz<CCSchedulerScriptHandlerEntry *>();
	if (__o)
	{
		return __o->getTimer();
	}
	return nullptr;
}

QScriptValue QtScriptCCSchedulerScriptHandlerEntry::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<int64_t>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			return __e->toScriptValue(CCSchedulerScriptHandlerEntry::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSchedulerScriptHandlerEntry::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTouchScriptHandlerEntry::QtScriptCCTouchScriptHandlerEntry(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCScriptHandlerEntry(engine, className)
{
}

QtScriptCCTouchScriptHandlerEntry::QtScriptCCTouchScriptHandlerEntry(QScriptEngine *engine)
	: QtScriptCCTouchScriptHandlerEntry(engine, "TouchScriptHandlerEntry")
{
}

void QtScriptCCTouchScriptHandlerEntry::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCScriptHandlerEntry *>());
	auto ctor = RegisterT<CCTouchScriptHandlerEntry, QtScriptCCTouchScriptHandlerEntry>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTouchScriptHandlerEntry::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTouchScriptHandlerEntry::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTouchScriptHandlerEntry::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTouchScriptHandlerEntry::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCTouchScriptHandlerEntry");
	return false;
}

bool QtScriptCCTouchScriptHandlerEntry::isMultiTouches()
{
	auto __o = this->thiz<CCTouchScriptHandlerEntry *>();
	if (__o)
	{
		return __o->isMultiTouches();
	}
	return false;
}

bool QtScriptCCTouchScriptHandlerEntry::getSwallowsTouches()
{
	auto __o = this->thiz<CCTouchScriptHandlerEntry *>();
	if (__o)
	{
		return __o->getSwallowsTouches();
	}
	return false;
}

int QtScriptCCTouchScriptHandlerEntry::getPriority()
{
	auto __o = this->thiz<CCTouchScriptHandlerEntry *>();
	if (__o)
	{
		return __o->getPriority();
	}
	return 0;
}

QScriptValue QtScriptCCTouchScriptHandlerEntry::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<int64_t>(context->argument(0));
			auto arg1 = qscriptvalue_cast<bool>(context->argument(1));
			auto arg2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<bool>(context->argument(3));
			return __e->toScriptValue(CCTouchScriptHandlerEntry::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTouchScriptHandlerEntry::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccColor3B::QtScript_ccColor3B(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccColor3B, false>(engine, className)
{
}

QtScript_ccColor3B::QtScript_ccColor3B(QScriptEngine *engine)
	: QtScript_ccColor3B(engine, "Color3B")
{
}

void QtScript_ccColor3B::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccColor3B, QtScript_ccColor3B>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccColor3B::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccColor3B::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccColor3B::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccColor3B constructor");
	return false;
}

unsigned char QtScript_ccColor3B::_public_field_get_r() const
{
	auto object = thiz<_ccColor3B *>();
	if (object)
	{
		return object->r;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor3B::_public_field_set_r(unsigned char value)
{
	auto object = thiz<_ccColor3B *>();
	if (object)
	{
		object->r = value;
	}
}

unsigned char QtScript_ccColor3B::_public_field_get_g() const
{
	auto object = thiz<_ccColor3B *>();
	if (object)
	{
		return object->g;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor3B::_public_field_set_g(unsigned char value)
{
	auto object = thiz<_ccColor3B *>();
	if (object)
	{
		object->g = value;
	}
}

unsigned char QtScript_ccColor3B::_public_field_get_b() const
{
	auto object = thiz<_ccColor3B *>();
	if (object)
	{
		return object->b;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor3B::_public_field_set_b(unsigned char value)
{
	auto object = thiz<_ccColor3B *>();
	if (object)
	{
		object->b = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccColor4B::QtScript_ccColor4B(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccColor4B, false>(engine, className)
{
}

QtScript_ccColor4B::QtScript_ccColor4B(QScriptEngine *engine)
	: QtScript_ccColor4B(engine, "Color4B")
{
}

void QtScript_ccColor4B::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccColor4B, QtScript_ccColor4B>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccColor4B::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccColor4B::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccColor4B::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccColor4B constructor");
	return false;
}

unsigned char QtScript_ccColor4B::_public_field_get_r() const
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		return object->r;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor4B::_public_field_set_r(unsigned char value)
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		object->r = value;
	}
}

unsigned char QtScript_ccColor4B::_public_field_get_g() const
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		return object->g;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor4B::_public_field_set_g(unsigned char value)
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		object->g = value;
	}
}

unsigned char QtScript_ccColor4B::_public_field_get_b() const
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		return object->b;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor4B::_public_field_set_b(unsigned char value)
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		object->b = value;
	}
}

unsigned char QtScript_ccColor4B::_public_field_get_a() const
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		return object->a;
	}
	return static_cast<unsigned char>(0);
}

void QtScript_ccColor4B::_public_field_set_a(unsigned char value)
{
	auto object = thiz<_ccColor4B *>();
	if (object)
	{
		object->a = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccColor4F::QtScript_ccColor4F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccColor4F, false>(engine, className)
{
}

QtScript_ccColor4F::QtScript_ccColor4F(QScriptEngine *engine)
	: QtScript_ccColor4F(engine, "Color4F")
{
}

void QtScript_ccColor4F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccColor4F, QtScript_ccColor4F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccColor4F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccColor4F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccColor4F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccColor4F constructor");
	return false;
}

float QtScript_ccColor4F::_public_field_get_r() const
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		return object->r;
	}
	return static_cast<float>(0);
}

void QtScript_ccColor4F::_public_field_set_r(float value)
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		object->r = value;
	}
}

float QtScript_ccColor4F::_public_field_get_g() const
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		return object->g;
	}
	return static_cast<float>(0);
}

void QtScript_ccColor4F::_public_field_set_g(float value)
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		object->g = value;
	}
}

float QtScript_ccColor4F::_public_field_get_b() const
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		return object->b;
	}
	return static_cast<float>(0);
}

void QtScript_ccColor4F::_public_field_set_b(float value)
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		object->b = value;
	}
}

float QtScript_ccColor4F::_public_field_get_a() const
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		return object->a;
	}
	return static_cast<float>(0);
}

void QtScript_ccColor4F::_public_field_set_a(float value)
{
	auto object = thiz<_ccColor4F *>();
	if (object)
	{
		object->a = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccVertex2F::QtScript_ccVertex2F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccVertex2F, false>(engine, className)
{
}

QtScript_ccVertex2F::QtScript_ccVertex2F(QScriptEngine *engine)
	: QtScript_ccVertex2F(engine, "Vertex2F")
{
}

void QtScript_ccVertex2F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccVertex2F, QtScript_ccVertex2F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccVertex2F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccVertex2F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccVertex2F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccVertex2F constructor");
	return false;
}

float QtScript_ccVertex2F::_public_field_get_x() const
{
	auto object = thiz<_ccVertex2F *>();
	if (object)
	{
		return object->x;
	}
	return static_cast<float>(0);
}

void QtScript_ccVertex2F::_public_field_set_x(float value)
{
	auto object = thiz<_ccVertex2F *>();
	if (object)
	{
		object->x = value;
	}
}

float QtScript_ccVertex2F::_public_field_get_y() const
{
	auto object = thiz<_ccVertex2F *>();
	if (object)
	{
		return object->y;
	}
	return static_cast<float>(0);
}

void QtScript_ccVertex2F::_public_field_set_y(float value)
{
	auto object = thiz<_ccVertex2F *>();
	if (object)
	{
		object->y = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccVertex3F::QtScript_ccVertex3F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccVertex3F, false>(engine, className)
{
}

QtScript_ccVertex3F::QtScript_ccVertex3F(QScriptEngine *engine)
	: QtScript_ccVertex3F(engine, "Vertex3F")
{
}

void QtScript_ccVertex3F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccVertex3F, QtScript_ccVertex3F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccVertex3F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccVertex3F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccVertex3F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccVertex3F constructor");
	return false;
}

float QtScript_ccVertex3F::_public_field_get_x() const
{
	auto object = thiz<_ccVertex3F *>();
	if (object)
	{
		return object->x;
	}
	return static_cast<float>(0);
}

void QtScript_ccVertex3F::_public_field_set_x(float value)
{
	auto object = thiz<_ccVertex3F *>();
	if (object)
	{
		object->x = value;
	}
}

float QtScript_ccVertex3F::_public_field_get_y() const
{
	auto object = thiz<_ccVertex3F *>();
	if (object)
	{
		return object->y;
	}
	return static_cast<float>(0);
}

void QtScript_ccVertex3F::_public_field_set_y(float value)
{
	auto object = thiz<_ccVertex3F *>();
	if (object)
	{
		object->y = value;
	}
}

float QtScript_ccVertex3F::_public_field_get_z() const
{
	auto object = thiz<_ccVertex3F *>();
	if (object)
	{
		return object->z;
	}
	return static_cast<float>(0);
}

void QtScript_ccVertex3F::_public_field_set_z(float value)
{
	auto object = thiz<_ccVertex3F *>();
	if (object)
	{
		object->z = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccTex2F::QtScript_ccTex2F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccTex2F, false>(engine, className)
{
}

QtScript_ccTex2F::QtScript_ccTex2F(QScriptEngine *engine)
	: QtScript_ccTex2F(engine, "Tex2F")
{
}

void QtScript_ccTex2F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccTex2F, QtScript_ccTex2F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccTex2F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccTex2F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccTex2F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccTex2F constructor");
	return false;
}

float QtScript_ccTex2F::_public_field_get_u() const
{
	auto object = thiz<_ccTex2F *>();
	if (object)
	{
		return object->u;
	}
	return static_cast<float>(0);
}

void QtScript_ccTex2F::_public_field_set_u(float value)
{
	auto object = thiz<_ccTex2F *>();
	if (object)
	{
		object->u = value;
	}
}

float QtScript_ccTex2F::_public_field_get_v() const
{
	auto object = thiz<_ccTex2F *>();
	if (object)
	{
		return object->v;
	}
	return static_cast<float>(0);
}

void QtScript_ccTex2F::_public_field_set_v(float value)
{
	auto object = thiz<_ccTex2F *>();
	if (object)
	{
		object->v = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccPointSprite::QtScript_ccPointSprite(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccPointSprite, false>(engine, className)
{
}

QtScript_ccPointSprite::QtScript_ccPointSprite(QScriptEngine *engine)
	: QtScript_ccPointSprite(engine, "PointSprite")
{
}

void QtScript_ccPointSprite::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccPointSprite, QtScript_ccPointSprite>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccPointSprite::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccPointSprite::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccPointSprite::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccPointSprite constructor");
	return false;
}

cocos2d::_ccVertex2F QtScript_ccPointSprite::_public_field_get_pos() const
{
	auto object = thiz<_ccPointSprite *>();
	if (object)
	{
		return object->pos;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccPointSprite::_public_field_set_pos(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccPointSprite *>();
	if (object)
	{
		object->pos = value;
	}
}

cocos2d::_ccColor4B QtScript_ccPointSprite::_public_field_get_color() const
{
	auto object = thiz<_ccPointSprite *>();
	if (object)
	{
		return object->color;
	}
	return cocos2d::_ccColor4B();
}

void QtScript_ccPointSprite::_public_field_set_color(const cocos2d::_ccColor4B& value)
{
	auto object = thiz<_ccPointSprite *>();
	if (object)
	{
		object->color = value;
	}
}

float QtScript_ccPointSprite::_public_field_get_size() const
{
	auto object = thiz<_ccPointSprite *>();
	if (object)
	{
		return object->size;
	}
	return static_cast<float>(0);
}

void QtScript_ccPointSprite::_public_field_set_size(float value)
{
	auto object = thiz<_ccPointSprite *>();
	if (object)
	{
		object->size = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccQuad2::QtScript_ccQuad2(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccQuad2, false>(engine, className)
{
}

QtScript_ccQuad2::QtScript_ccQuad2(QScriptEngine *engine)
	: QtScript_ccQuad2(engine, "Quad2")
{
}

void QtScript_ccQuad2::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccQuad2, QtScript_ccQuad2>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccQuad2::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccQuad2::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccQuad2::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccQuad2 constructor");
	return false;
}

cocos2d::_ccVertex2F QtScript_ccQuad2::_public_field_get_tl() const
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		return object->tl;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccQuad2::_public_field_set_tl(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		object->tl = value;
	}
}

cocos2d::_ccVertex2F QtScript_ccQuad2::_public_field_get_tr() const
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		return object->tr;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccQuad2::_public_field_set_tr(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		object->tr = value;
	}
}

cocos2d::_ccVertex2F QtScript_ccQuad2::_public_field_get_bl() const
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		return object->bl;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccQuad2::_public_field_set_bl(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		object->bl = value;
	}
}

cocos2d::_ccVertex2F QtScript_ccQuad2::_public_field_get_br() const
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		return object->br;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccQuad2::_public_field_set_br(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccQuad2 *>();
	if (object)
	{
		object->br = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccQuad3::QtScript_ccQuad3(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccQuad3, false>(engine, className)
{
}

QtScript_ccQuad3::QtScript_ccQuad3(QScriptEngine *engine)
	: QtScript_ccQuad3(engine, "Quad3")
{
}

void QtScript_ccQuad3::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccQuad3, QtScript_ccQuad3>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccQuad3::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccQuad3::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccQuad3::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccQuad3 constructor");
	return false;
}

cocos2d::_ccVertex3F QtScript_ccQuad3::_public_field_get_bl() const
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		return object->bl;
	}
	return cocos2d::_ccVertex3F();
}

void QtScript_ccQuad3::_public_field_set_bl(const cocos2d::_ccVertex3F& value)
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		object->bl = value;
	}
}

cocos2d::_ccVertex3F QtScript_ccQuad3::_public_field_get_br() const
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		return object->br;
	}
	return cocos2d::_ccVertex3F();
}

void QtScript_ccQuad3::_public_field_set_br(const cocos2d::_ccVertex3F& value)
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		object->br = value;
	}
}

cocos2d::_ccVertex3F QtScript_ccQuad3::_public_field_get_tl() const
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		return object->tl;
	}
	return cocos2d::_ccVertex3F();
}

void QtScript_ccQuad3::_public_field_set_tl(const cocos2d::_ccVertex3F& value)
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		object->tl = value;
	}
}

cocos2d::_ccVertex3F QtScript_ccQuad3::_public_field_get_tr() const
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		return object->tr;
	}
	return cocos2d::_ccVertex3F();
}

void QtScript_ccQuad3::_public_field_set_tr(const cocos2d::_ccVertex3F& value)
{
	auto object = thiz<_ccQuad3 *>();
	if (object)
	{
		object->tr = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV2F_C4B_T2F::QtScript_ccV2F_C4B_T2F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV2F_C4B_T2F, false>(engine, className)
{
}

QtScript_ccV2F_C4B_T2F::QtScript_ccV2F_C4B_T2F(QScriptEngine *engine)
	: QtScript_ccV2F_C4B_T2F(engine, "V2F_C4B_T2F")
{
}

void QtScript_ccV2F_C4B_T2F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV2F_C4B_T2F, QtScript_ccV2F_C4B_T2F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV2F_C4B_T2F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV2F_C4B_T2F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV2F_C4B_T2F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV2F_C4B_T2F constructor");
	return false;
}

cocos2d::_ccVertex2F QtScript_ccV2F_C4B_T2F::_public_field_get_vertices() const
{
	auto object = thiz<_ccV2F_C4B_T2F *>();
	if (object)
	{
		return object->vertices;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccV2F_C4B_T2F::_public_field_set_vertices(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F *>();
	if (object)
	{
		object->vertices = value;
	}
}

cocos2d::_ccColor4B QtScript_ccV2F_C4B_T2F::_public_field_get_colors() const
{
	auto object = thiz<_ccV2F_C4B_T2F *>();
	if (object)
	{
		return object->colors;
	}
	return cocos2d::_ccColor4B();
}

void QtScript_ccV2F_C4B_T2F::_public_field_set_colors(const cocos2d::_ccColor4B& value)
{
	auto object = thiz<_ccV2F_C4B_T2F *>();
	if (object)
	{
		object->colors = value;
	}
}

cocos2d::_ccTex2F QtScript_ccV2F_C4B_T2F::_public_field_get_texCoords() const
{
	auto object = thiz<_ccV2F_C4B_T2F *>();
	if (object)
	{
		return object->texCoords;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccV2F_C4B_T2F::_public_field_set_texCoords(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F *>();
	if (object)
	{
		object->texCoords = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV2F_C4F_T2F::QtScript_ccV2F_C4F_T2F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV2F_C4F_T2F, false>(engine, className)
{
}

QtScript_ccV2F_C4F_T2F::QtScript_ccV2F_C4F_T2F(QScriptEngine *engine)
	: QtScript_ccV2F_C4F_T2F(engine, "V2F_C4F_T2F")
{
}

void QtScript_ccV2F_C4F_T2F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV2F_C4F_T2F, QtScript_ccV2F_C4F_T2F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV2F_C4F_T2F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV2F_C4F_T2F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV2F_C4F_T2F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV2F_C4F_T2F constructor");
	return false;
}

cocos2d::_ccVertex2F QtScript_ccV2F_C4F_T2F::_public_field_get_vertices() const
{
	auto object = thiz<_ccV2F_C4F_T2F *>();
	if (object)
	{
		return object->vertices;
	}
	return cocos2d::_ccVertex2F();
}

void QtScript_ccV2F_C4F_T2F::_public_field_set_vertices(const cocos2d::_ccVertex2F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F *>();
	if (object)
	{
		object->vertices = value;
	}
}

cocos2d::_ccColor4F QtScript_ccV2F_C4F_T2F::_public_field_get_colors() const
{
	auto object = thiz<_ccV2F_C4F_T2F *>();
	if (object)
	{
		return object->colors;
	}
	return cocos2d::_ccColor4F();
}

void QtScript_ccV2F_C4F_T2F::_public_field_set_colors(const cocos2d::_ccColor4F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F *>();
	if (object)
	{
		object->colors = value;
	}
}

cocos2d::_ccTex2F QtScript_ccV2F_C4F_T2F::_public_field_get_texCoords() const
{
	auto object = thiz<_ccV2F_C4F_T2F *>();
	if (object)
	{
		return object->texCoords;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccV2F_C4F_T2F::_public_field_set_texCoords(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F *>();
	if (object)
	{
		object->texCoords = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV3F_C4B_T2F::QtScript_ccV3F_C4B_T2F(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV3F_C4B_T2F, false>(engine, className)
{
}

QtScript_ccV3F_C4B_T2F::QtScript_ccV3F_C4B_T2F(QScriptEngine *engine)
	: QtScript_ccV3F_C4B_T2F(engine, "V3F_C4B_T2F")
{
}

void QtScript_ccV3F_C4B_T2F::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV3F_C4B_T2F, QtScript_ccV3F_C4B_T2F>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV3F_C4B_T2F::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV3F_C4B_T2F::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV3F_C4B_T2F::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV3F_C4B_T2F constructor");
	return false;
}

cocos2d::_ccVertex3F QtScript_ccV3F_C4B_T2F::_public_field_get_vertices() const
{
	auto object = thiz<_ccV3F_C4B_T2F *>();
	if (object)
	{
		return object->vertices;
	}
	return cocos2d::_ccVertex3F();
}

void QtScript_ccV3F_C4B_T2F::_public_field_set_vertices(const cocos2d::_ccVertex3F& value)
{
	auto object = thiz<_ccV3F_C4B_T2F *>();
	if (object)
	{
		object->vertices = value;
	}
}

cocos2d::_ccColor4B QtScript_ccV3F_C4B_T2F::_public_field_get_colors() const
{
	auto object = thiz<_ccV3F_C4B_T2F *>();
	if (object)
	{
		return object->colors;
	}
	return cocos2d::_ccColor4B();
}

void QtScript_ccV3F_C4B_T2F::_public_field_set_colors(const cocos2d::_ccColor4B& value)
{
	auto object = thiz<_ccV3F_C4B_T2F *>();
	if (object)
	{
		object->colors = value;
	}
}

cocos2d::_ccTex2F QtScript_ccV3F_C4B_T2F::_public_field_get_texCoords() const
{
	auto object = thiz<_ccV3F_C4B_T2F *>();
	if (object)
	{
		return object->texCoords;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccV3F_C4B_T2F::_public_field_set_texCoords(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccV3F_C4B_T2F *>();
	if (object)
	{
		object->texCoords = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV2F_C4B_T2F_Triangle::QtScript_ccV2F_C4B_T2F_Triangle(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV2F_C4B_T2F_Triangle, false>(engine, className)
{
}

QtScript_ccV2F_C4B_T2F_Triangle::QtScript_ccV2F_C4B_T2F_Triangle(QScriptEngine *engine)
	: QtScript_ccV2F_C4B_T2F_Triangle(engine, "V2F_C4B_T2F_Triangle")
{
}

void QtScript_ccV2F_C4B_T2F_Triangle::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV2F_C4B_T2F_Triangle, QtScript_ccV2F_C4B_T2F_Triangle>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV2F_C4B_T2F_Triangle::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV2F_C4B_T2F_Triangle::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV2F_C4B_T2F_Triangle::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV2F_C4B_T2F_Triangle constructor");
	return false;
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Triangle::_public_field_get_a() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Triangle *>();
	if (object)
	{
		return object->a;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Triangle::_public_field_set_a(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Triangle *>();
	if (object)
	{
		object->a = value;
	}
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Triangle::_public_field_get_b() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Triangle *>();
	if (object)
	{
		return object->b;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Triangle::_public_field_set_b(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Triangle *>();
	if (object)
	{
		object->b = value;
	}
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Triangle::_public_field_get_c() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Triangle *>();
	if (object)
	{
		return object->c;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Triangle::_public_field_set_c(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Triangle *>();
	if (object)
	{
		object->c = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV2F_C4B_T2F_Quad::QtScript_ccV2F_C4B_T2F_Quad(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV2F_C4B_T2F_Quad, false>(engine, className)
{
}

QtScript_ccV2F_C4B_T2F_Quad::QtScript_ccV2F_C4B_T2F_Quad(QScriptEngine *engine)
	: QtScript_ccV2F_C4B_T2F_Quad(engine, "V2F_C4B_T2F_Quad")
{
}

void QtScript_ccV2F_C4B_T2F_Quad::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV2F_C4B_T2F_Quad, QtScript_ccV2F_C4B_T2F_Quad>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV2F_C4B_T2F_Quad::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV2F_C4B_T2F_Quad::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV2F_C4B_T2F_Quad::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV2F_C4B_T2F_Quad constructor");
	return false;
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Quad::_public_field_get_bl() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->bl;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Quad::_public_field_set_bl(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		object->bl = value;
	}
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Quad::_public_field_get_br() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->br;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Quad::_public_field_set_br(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		object->br = value;
	}
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Quad::_public_field_get_tl() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->tl;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Quad::_public_field_set_tl(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		object->tl = value;
	}
}

cocos2d::_ccV2F_C4B_T2F QtScript_ccV2F_C4B_T2F_Quad::_public_field_get_tr() const
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->tr;
	}
	return cocos2d::_ccV2F_C4B_T2F();
}

void QtScript_ccV2F_C4B_T2F_Quad::_public_field_set_tr(const cocos2d::_ccV2F_C4B_T2F& value)
{
	auto object = thiz<_ccV2F_C4B_T2F_Quad *>();
	if (object)
	{
		object->tr = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV3F_C4B_T2F_Quad::QtScript_ccV3F_C4B_T2F_Quad(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV3F_C4B_T2F_Quad, false>(engine, className)
{
}

QtScript_ccV3F_C4B_T2F_Quad::QtScript_ccV3F_C4B_T2F_Quad(QScriptEngine *engine)
	: QtScript_ccV3F_C4B_T2F_Quad(engine, "V3F_C4B_T2F_Quad")
{
}

void QtScript_ccV3F_C4B_T2F_Quad::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV3F_C4B_T2F_Quad, QtScript_ccV3F_C4B_T2F_Quad>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV3F_C4B_T2F_Quad::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV3F_C4B_T2F_Quad::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV3F_C4B_T2F_Quad::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV3F_C4B_T2F_Quad constructor");
	return false;
}

cocos2d::_ccV3F_C4B_T2F QtScript_ccV3F_C4B_T2F_Quad::_public_field_get_tl() const
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->tl;
	}
	return cocos2d::_ccV3F_C4B_T2F();
}

void QtScript_ccV3F_C4B_T2F_Quad::_public_field_set_tl(const cocos2d::_ccV3F_C4B_T2F& value)
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		object->tl = value;
	}
}

cocos2d::_ccV3F_C4B_T2F QtScript_ccV3F_C4B_T2F_Quad::_public_field_get_bl() const
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->bl;
	}
	return cocos2d::_ccV3F_C4B_T2F();
}

void QtScript_ccV3F_C4B_T2F_Quad::_public_field_set_bl(const cocos2d::_ccV3F_C4B_T2F& value)
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		object->bl = value;
	}
}

cocos2d::_ccV3F_C4B_T2F QtScript_ccV3F_C4B_T2F_Quad::_public_field_get_tr() const
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->tr;
	}
	return cocos2d::_ccV3F_C4B_T2F();
}

void QtScript_ccV3F_C4B_T2F_Quad::_public_field_set_tr(const cocos2d::_ccV3F_C4B_T2F& value)
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		object->tr = value;
	}
}

cocos2d::_ccV3F_C4B_T2F QtScript_ccV3F_C4B_T2F_Quad::_public_field_get_br() const
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		return object->br;
	}
	return cocos2d::_ccV3F_C4B_T2F();
}

void QtScript_ccV3F_C4B_T2F_Quad::_public_field_set_br(const cocos2d::_ccV3F_C4B_T2F& value)
{
	auto object = thiz<_ccV3F_C4B_T2F_Quad *>();
	if (object)
	{
		object->br = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccV2F_C4F_T2F_Quad::QtScript_ccV2F_C4F_T2F_Quad(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccV2F_C4F_T2F_Quad, false>(engine, className)
{
}

QtScript_ccV2F_C4F_T2F_Quad::QtScript_ccV2F_C4F_T2F_Quad(QScriptEngine *engine)
	: QtScript_ccV2F_C4F_T2F_Quad(engine, "V2F_C4F_T2F_Quad")
{
}

void QtScript_ccV2F_C4F_T2F_Quad::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccV2F_C4F_T2F_Quad, QtScript_ccV2F_C4F_T2F_Quad>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccV2F_C4F_T2F_Quad::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccV2F_C4F_T2F_Quad::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccV2F_C4F_T2F_Quad::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccV2F_C4F_T2F_Quad constructor");
	return false;
}

cocos2d::_ccV2F_C4F_T2F QtScript_ccV2F_C4F_T2F_Quad::_public_field_get_bl() const
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		return object->bl;
	}
	return cocos2d::_ccV2F_C4F_T2F();
}

void QtScript_ccV2F_C4F_T2F_Quad::_public_field_set_bl(const cocos2d::_ccV2F_C4F_T2F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		object->bl = value;
	}
}

cocos2d::_ccV2F_C4F_T2F QtScript_ccV2F_C4F_T2F_Quad::_public_field_get_br() const
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		return object->br;
	}
	return cocos2d::_ccV2F_C4F_T2F();
}

void QtScript_ccV2F_C4F_T2F_Quad::_public_field_set_br(const cocos2d::_ccV2F_C4F_T2F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		object->br = value;
	}
}

cocos2d::_ccV2F_C4F_T2F QtScript_ccV2F_C4F_T2F_Quad::_public_field_get_tl() const
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		return object->tl;
	}
	return cocos2d::_ccV2F_C4F_T2F();
}

void QtScript_ccV2F_C4F_T2F_Quad::_public_field_set_tl(const cocos2d::_ccV2F_C4F_T2F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		object->tl = value;
	}
}

cocos2d::_ccV2F_C4F_T2F QtScript_ccV2F_C4F_T2F_Quad::_public_field_get_tr() const
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		return object->tr;
	}
	return cocos2d::_ccV2F_C4F_T2F();
}

void QtScript_ccV2F_C4F_T2F_Quad::_public_field_set_tr(const cocos2d::_ccV2F_C4F_T2F& value)
{
	auto object = thiz<_ccV2F_C4F_T2F_Quad *>();
	if (object)
	{
		object->tr = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccBlendFunc::QtScript_ccBlendFunc(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccBlendFunc, false>(engine, className)
{
}

QtScript_ccBlendFunc::QtScript_ccBlendFunc(QScriptEngine *engine)
	: QtScript_ccBlendFunc(engine, "BlendFunc")
{
}

void QtScript_ccBlendFunc::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccBlendFunc, QtScript_ccBlendFunc>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccBlendFunc::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccBlendFunc::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccBlendFunc::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccBlendFunc constructor");
	return false;
}

unsigned int QtScript_ccBlendFunc::_public_field_get_src() const
{
	auto object = thiz<_ccBlendFunc *>();
	if (object)
	{
		return object->src;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccBlendFunc::_public_field_set_src(unsigned int value)
{
	auto object = thiz<_ccBlendFunc *>();
	if (object)
	{
		object->src = value;
	}
}

unsigned int QtScript_ccBlendFunc::_public_field_get_dst() const
{
	auto object = thiz<_ccBlendFunc *>();
	if (object)
	{
		return object->dst;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccBlendFunc::_public_field_set_dst(unsigned int value)
{
	auto object = thiz<_ccBlendFunc *>();
	if (object)
	{
		object->dst = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccT2F_Quad::QtScript_ccT2F_Quad(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccT2F_Quad, false>(engine, className)
{
}

QtScript_ccT2F_Quad::QtScript_ccT2F_Quad(QScriptEngine *engine)
	: QtScript_ccT2F_Quad(engine, "T2F_Quad")
{
}

void QtScript_ccT2F_Quad::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccT2F_Quad, QtScript_ccT2F_Quad>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccT2F_Quad::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccT2F_Quad::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccT2F_Quad::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccT2F_Quad constructor");
	return false;
}

cocos2d::_ccTex2F QtScript_ccT2F_Quad::_public_field_get_bl() const
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		return object->bl;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccT2F_Quad::_public_field_set_bl(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		object->bl = value;
	}
}

cocos2d::_ccTex2F QtScript_ccT2F_Quad::_public_field_get_br() const
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		return object->br;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccT2F_Quad::_public_field_set_br(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		object->br = value;
	}
}

cocos2d::_ccTex2F QtScript_ccT2F_Quad::_public_field_get_tl() const
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		return object->tl;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccT2F_Quad::_public_field_set_tl(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		object->tl = value;
	}
}

cocos2d::_ccTex2F QtScript_ccT2F_Quad::_public_field_get_tr() const
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		return object->tr;
	}
	return cocos2d::_ccTex2F();
}

void QtScript_ccT2F_Quad::_public_field_set_tr(const cocos2d::_ccTex2F& value)
{
	auto object = thiz<_ccT2F_Quad *>();
	if (object)
	{
		object->tr = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptccAnimationFrameData::QtScriptccAnimationFrameData(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<ccAnimationFrameData, false>(engine, className)
{
}

QtScriptccAnimationFrameData::QtScriptccAnimationFrameData(QScriptEngine *engine)
	: QtScriptccAnimationFrameData(engine, "ccAnimationFrameData")
{
}

void QtScriptccAnimationFrameData::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<ccAnimationFrameData, QtScriptccAnimationFrameData>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptccAnimationFrameData::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptccAnimationFrameData::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptccAnimationFrameData::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::ccAnimationFrameData constructor");
	return false;
}

cocos2d::_ccT2F_Quad QtScriptccAnimationFrameData::_public_field_get_texCoords() const
{
	auto object = thiz<ccAnimationFrameData *>();
	if (object)
	{
		return object->texCoords;
	}
	return cocos2d::_ccT2F_Quad();
}

void QtScriptccAnimationFrameData::_public_field_set_texCoords(const cocos2d::_ccT2F_Quad& value)
{
	auto object = thiz<ccAnimationFrameData *>();
	if (object)
	{
		object->texCoords = value;
	}
}

float QtScriptccAnimationFrameData::_public_field_get_delay() const
{
	auto object = thiz<ccAnimationFrameData *>();
	if (object)
	{
		return object->delay;
	}
	return static_cast<float>(0);
}

void QtScriptccAnimationFrameData::_public_field_set_delay(float value)
{
	auto object = thiz<ccAnimationFrameData *>();
	if (object)
	{
		object->delay = value;
	}
}

cocos2d::CCSize QtScriptccAnimationFrameData::_public_field_get_size() const
{
	auto object = thiz<ccAnimationFrameData *>();
	if (object)
	{
		return object->size;
	}
	return cocos2d::CCSize();
}

void QtScriptccAnimationFrameData::_public_field_set_size(const cocos2d::CCSize& value)
{
	auto object = thiz<ccAnimationFrameData *>();
	if (object)
	{
		object->size = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccFontShadow::QtScript_ccFontShadow(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccFontShadow, false>(engine, className)
{
}

QtScript_ccFontShadow::QtScript_ccFontShadow(QScriptEngine *engine)
	: QtScript_ccFontShadow(engine, "FontShadow")
{
}

void QtScript_ccFontShadow::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccFontShadow, QtScript_ccFontShadow>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccFontShadow::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccFontShadow::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccFontShadow::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::_ccFontShadow constructor");
	}
	return ok;
}

bool QtScript_ccFontShadow::_public_field_get_shadowEnabled() const
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		return object->m_shadowEnabled;
	}
	return false;
}

void QtScript_ccFontShadow::_public_field_set_shadowEnabled(const bool& value)
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		object->m_shadowEnabled = value;
	}
}

cocos2d::CCSize QtScript_ccFontShadow::_public_field_get_shadowOffset() const
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		return object->m_shadowOffset;
	}
	return cocos2d::CCSize();
}

void QtScript_ccFontShadow::_public_field_set_shadowOffset(const cocos2d::CCSize& value)
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		object->m_shadowOffset = value;
	}
}

float QtScript_ccFontShadow::_public_field_get_shadowBlur() const
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		return object->m_shadowBlur;
	}
	return static_cast<float>(0);
}

void QtScript_ccFontShadow::_public_field_set_shadowBlur(float value)
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		object->m_shadowBlur = value;
	}
}

float QtScript_ccFontShadow::_public_field_get_shadowOpacity() const
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		return object->m_shadowOpacity;
	}
	return static_cast<float>(0);
}

void QtScript_ccFontShadow::_public_field_set_shadowOpacity(float value)
{
	auto object = thiz<_ccFontShadow *>();
	if (object)
	{
		object->m_shadowOpacity = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccFontStroke::QtScript_ccFontStroke(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccFontStroke, false>(engine, className)
{
}

QtScript_ccFontStroke::QtScript_ccFontStroke(QScriptEngine *engine)
	: QtScript_ccFontStroke(engine, "FontStroke")
{
}

void QtScript_ccFontStroke::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccFontStroke, QtScript_ccFontStroke>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccFontStroke::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccFontStroke::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccFontStroke::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::_ccFontStroke constructor");
	}
	return ok;
}

bool QtScript_ccFontStroke::_public_field_get_strokeEnabled() const
{
	auto object = thiz<_ccFontStroke *>();
	if (object)
	{
		return object->m_strokeEnabled;
	}
	return false;
}

void QtScript_ccFontStroke::_public_field_set_strokeEnabled(const bool& value)
{
	auto object = thiz<_ccFontStroke *>();
	if (object)
	{
		object->m_strokeEnabled = value;
	}
}

cocos2d::_ccColor3B QtScript_ccFontStroke::_public_field_get_strokeColor() const
{
	auto object = thiz<_ccFontStroke *>();
	if (object)
	{
		return object->m_strokeColor;
	}
	return cocos2d::_ccColor3B();
}

void QtScript_ccFontStroke::_public_field_set_strokeColor(const cocos2d::_ccColor3B& value)
{
	auto object = thiz<_ccFontStroke *>();
	if (object)
	{
		object->m_strokeColor = value;
	}
}

float QtScript_ccFontStroke::_public_field_get_strokeSize() const
{
	auto object = thiz<_ccFontStroke *>();
	if (object)
	{
		return object->m_strokeSize;
	}
	return static_cast<float>(0);
}

void QtScript_ccFontStroke::_public_field_set_strokeSize(float value)
{
	auto object = thiz<_ccFontStroke *>();
	if (object)
	{
		object->m_strokeSize = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccFontDefinition::QtScript_ccFontDefinition(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccFontDefinition, false>(engine, className)
{
}

QtScript_ccFontDefinition::QtScript_ccFontDefinition(QScriptEngine *engine)
	: QtScript_ccFontDefinition(engine, "FontDefinition")
{
}

void QtScript_ccFontDefinition::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccFontDefinition, QtScript_ccFontDefinition>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccFontDefinition::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccFontDefinition::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccFontDefinition::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::_ccFontDefinition constructor");
	}
	return ok;
}

QByteArray QtScript_ccFontDefinition::_public_field_get_fontName() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return QByteArray(object->m_fontName.c_str(), int(object->m_fontName.size()));
	}
	return QByteArray();
}

void QtScript_ccFontDefinition::_public_field_set_fontName(const QByteArray& value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_fontName = std::string(value.data(), size_t(value.size()));
	}
}

int QtScript_ccFontDefinition::_public_field_get_fontSize() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return object->m_fontSize;
	}
	return static_cast<int>(0);
}

void QtScript_ccFontDefinition::_public_field_set_fontSize(int value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_fontSize = value;
	}
}

int QtScript_ccFontDefinition::_public_field_get_alignment() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return int(object->m_alignment);
	}
	return static_cast<int>(0);
}

void QtScript_ccFontDefinition::_public_field_set_alignment(int value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_alignment = cocos2d::CCTextAlignment(value);
	}
}

int QtScript_ccFontDefinition::_public_field_get_vertAlignment() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return int(object->m_vertAlignment);
	}
	return static_cast<int>(0);
}

void QtScript_ccFontDefinition::_public_field_set_vertAlignment(int value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_vertAlignment = cocos2d::CCVerticalTextAlignment(value);
	}
}

cocos2d::CCSize QtScript_ccFontDefinition::_public_field_get_dimensions() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return object->m_dimensions;
	}
	return cocos2d::CCSize();
}

void QtScript_ccFontDefinition::_public_field_set_dimensions(const cocos2d::CCSize& value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_dimensions = value;
	}
}

cocos2d::_ccColor3B QtScript_ccFontDefinition::_public_field_get_fontFillColor() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return object->m_fontFillColor;
	}
	return cocos2d::_ccColor3B();
}

void QtScript_ccFontDefinition::_public_field_set_fontFillColor(const cocos2d::_ccColor3B& value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_fontFillColor = value;
	}
}

cocos2d::_ccFontShadow QtScript_ccFontDefinition::_public_field_get_shadow() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return object->m_shadow;
	}
	return cocos2d::_ccFontShadow();
}

void QtScript_ccFontDefinition::_public_field_set_shadow(const cocos2d::_ccFontShadow& value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_shadow = value;
	}
}

cocos2d::_ccFontStroke QtScript_ccFontDefinition::_public_field_get_stroke() const
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		return object->m_stroke;
	}
	return cocos2d::_ccFontStroke();
}

void QtScript_ccFontDefinition::_public_field_set_stroke(const cocos2d::_ccFontStroke& value)
{
	auto object = thiz<_ccFontDefinition *>();
	if (object)
	{
		object->m_stroke = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccPVRTexturePixelFormatInfo::QtScript_ccPVRTexturePixelFormatInfo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccPVRTexturePixelFormatInfo, false>(engine, className)
{
}

QtScript_ccPVRTexturePixelFormatInfo::QtScript_ccPVRTexturePixelFormatInfo(QScriptEngine *engine)
	: QtScript_ccPVRTexturePixelFormatInfo(engine, "PVRTexturePixelFormatInfo")
{
}

void QtScript_ccPVRTexturePixelFormatInfo::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccPVRTexturePixelFormatInfo, QtScript_ccPVRTexturePixelFormatInfo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccPVRTexturePixelFormatInfo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccPVRTexturePixelFormatInfo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccPVRTexturePixelFormatInfo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccPVRTexturePixelFormatInfo constructor");
	return false;
}

unsigned int QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_internalFormat() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return object->internalFormat;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_internalFormat(unsigned int value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->internalFormat = value;
	}
}

unsigned int QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_format() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return object->format;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_format(unsigned int value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->format = value;
	}
}

unsigned int QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_type() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return object->type;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_type(unsigned int value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->type = value;
	}
}

uint32_t QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_bpp() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return object->bpp;
	}
	return static_cast<uint32_t>(0);
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_bpp(uint32_t value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->bpp = value;
	}
}

bool QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_compressed() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return object->compressed;
	}
	return false;
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_compressed(const bool& value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->compressed = value;
	}
}

bool QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_alpha() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return object->alpha;
	}
	return false;
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_alpha(const bool& value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->alpha = value;
	}
}

int QtScript_ccPVRTexturePixelFormatInfo::_public_field_get_ccPixelFormat() const
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		return int(object->ccPixelFormat);
	}
	return static_cast<int>(0);
}

void QtScript_ccPVRTexturePixelFormatInfo::_public_field_set_ccPixelFormat(int value)
{
	auto object = thiz<_ccPVRTexturePixelFormatInfo *>();
	if (object)
	{
		object->ccPixelFormat = cocos2d::CCTexture2DPixelFormat(value);
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTexturePVR::QtScriptCCTexturePVR(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTexturePVR::QtScriptCCTexturePVR(QScriptEngine *engine)
	: QtScriptCCTexturePVR(engine, "TexturePVR")
{
}

void QtScriptCCTexturePVR::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTexturePVR, QtScriptCCTexturePVR>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTexturePVR::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCTexturePVR::initWithData(const QByteArray& data, size_t len, int compression)
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->initWithData(reinterpret_cast<const unsigned char*>(data.data()), len, cocos2d::CCTexturePVR::Compression(compression));
	}
	return false;
}

bool QtScriptCCTexturePVR::initWithContentsOfFile(const QByteArray& path)
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->initWithContentsOfFile(path.data());
	}
	return false;
}

bool QtScriptCCTexturePVR::isForcePremultipliedAlpha()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->isForcePremultipliedAlpha();
	}
	return false;
}

unsigned int QtScriptCCTexturePVR::getHeight()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->getHeight();
	}
	return static_cast<unsigned int>(0);
}

unsigned int QtScriptCCTexturePVR::getName()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->getName();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCTexturePVR::setRetainName(bool retainName)
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		__o->setRetainName(retainName);
	}
}

bool QtScriptCCTexturePVR::hasAlpha()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->hasAlpha();
	}
	return false;
}

unsigned int QtScriptCCTexturePVR::getWidth()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->getWidth();
	}
	return static_cast<unsigned int>(0);
}

unsigned int QtScriptCCTexturePVR::getNumberOfMipmaps()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->getNumberOfMipmaps();
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCTexturePVR::hasPremultipliedAlpha()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->hasPremultipliedAlpha();
	}
	return false;
}

int QtScriptCCTexturePVR::getFormat()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return int(__o->getFormat());
	}
	return 0;
}

bool QtScriptCCTexturePVR::isRetainName()
{
	auto __o = this->thiz<CCTexturePVR *>();
	if (__o)
	{
		return __o->isRetainName();
	}
	return false;
}

QScriptValue QtScriptCCTexturePVR::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCTexturePVR::create(arg0));
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = reinterpret_cast<const unsigned char*>(tmp_0.data());
			auto arg1 = qscriptvalue_cast<size_t>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::CCTexturePVR::Compression(tmp_2);
			return __e->toScriptValue(CCTexturePVR::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTexturePVR::create");
	return __e->uncaughtException();
}

int QtScriptCCTexturePVR::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTexturePVR::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTexturePVR::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTexturePVR();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTexturePVR constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccTexParams::QtScript_ccTexParams(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccTexParams, false>(engine, className)
{
}

QtScript_ccTexParams::QtScript_ccTexParams(QScriptEngine *engine)
	: QtScript_ccTexParams(engine, "TexParams")
{
}

void QtScript_ccTexParams::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccTexParams, QtScript_ccTexParams>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccTexParams::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccTexParams::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccTexParams::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccTexParams constructor");
	return false;
}

unsigned int QtScript_ccTexParams::_public_field_get_minFilter() const
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		return object->minFilter;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccTexParams::_public_field_set_minFilter(unsigned int value)
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		object->minFilter = value;
	}
}

unsigned int QtScript_ccTexParams::_public_field_get_magFilter() const
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		return object->magFilter;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccTexParams::_public_field_set_magFilter(unsigned int value)
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		object->magFilter = value;
	}
}

unsigned int QtScript_ccTexParams::_public_field_get_wrapS() const
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		return object->wrapS;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccTexParams::_public_field_set_wrapS(unsigned int value)
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		object->wrapS = value;
	}
}

unsigned int QtScript_ccTexParams::_public_field_get_wrapT() const
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		return object->wrapT;
	}
	return static_cast<unsigned int>(0);
}

void QtScript_ccTexParams::_public_field_set_wrapT(unsigned int value)
{
	auto object = thiz<_ccTexParams *>();
	if (object)
	{
		object->wrapT = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTexture2D::QtScriptCCTexture2D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTexture2D::QtScriptCCTexture2D(QScriptEngine *engine)
	: QtScriptCCTexture2D(engine, "Texture2D")
{
}

void QtScriptCCTexture2D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTexture2D, QtScriptCCTexture2D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("setDefaultAlphaPixelFormat", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTexture2D::setDefaultAlphaPixelFormat)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("defaultAlphaPixelFormat", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTexture2D::defaultAlphaPixelFormat)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("PVRImagesHavePremultipliedAlpha", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTexture2D::PVRImagesHavePremultipliedAlpha)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCGLProgram* QtScriptCCTexture2D::getShaderProgram()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getShaderProgram();
	}
	return nullptr;
}

bool QtScriptCCTexture2D::initWithETCFile(const QByteArray& file)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithETCFile(file.data());
	}
	return false;
}

QByteArray QtScriptCCTexture2D::stringForFormat()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return QByteArray(__o->stringForFormat());
	}
	return QByteArray();
}

bool QtScriptCCTexture2D::initWithImage(cocos2d::CCImage* uiImage)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithImage(uiImage);
	}
	return false;
}

void QtScriptCCTexture2D::setShaderProgram(cocos2d::CCGLProgram* var)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->setShaderProgram(var);
	}
}

float QtScriptCCTexture2D::getMaxS()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getMaxS();
	}
	return static_cast<float>(0);
}

bool QtScriptCCTexture2D::hasPremultipliedAlpha()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->hasPremultipliedAlpha();
	}
	return false;
}

unsigned int QtScriptCCTexture2D::getPixelsHigh()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getPixelsHigh();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCTexture2D::setTexParameters(cocos2d::_ccTexParams* texParams)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->setTexParameters(texParams);
	}
}

unsigned int QtScriptCCTexture2D::bitsPerPixelForFormat()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->bitsPerPixelForFormat();
	}
	return static_cast<unsigned int>(0);
}

unsigned int QtScriptCCTexture2D::bitsPerPixelForFormat(int format)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->bitsPerPixelForFormat(cocos2d::CCTexture2DPixelFormat(format));
	}
	return static_cast<unsigned int>(0);
}

unsigned int QtScriptCCTexture2D::getName()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getName();
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCTexture2D::initWithString(const QByteArray& text, cocos2d::_ccFontDefinition* textDefinition)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithString(text.data(), textDefinition);
	}
	return false;
}

bool QtScriptCCTexture2D::initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithString(text.data(), fontName.data(), fontSize);
	}
	return false;
}

bool QtScriptCCTexture2D::initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::CCSize& dimensions, int hAlignment, int vAlignment)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithString(text.data(), fontName.data(), fontSize, dimensions, cocos2d::CCTextAlignment(hAlignment), cocos2d::CCVerticalTextAlignment(vAlignment));
	}
	return false;
}

void QtScriptCCTexture2D::setMaxT(float var)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->setMaxT(var);
	}
}

void QtScriptCCTexture2D::drawInRect(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->drawInRect(rect);
	}
}

cocos2d::CCSize QtScriptCCTexture2D::getContentSize()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getContentSize();
	}
	return cocos2d::CCSize();
}

float QtScriptCCTexture2D::getMaxT()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getMaxT();
	}
	return static_cast<float>(0);
}

void QtScriptCCTexture2D::setAliasTexParameters()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->setAliasTexParameters();
	}
}

void QtScriptCCTexture2D::setAntiAliasTexParameters()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->setAntiAliasTexParameters();
	}
}

void QtScriptCCTexture2D::generateMipmap()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->generateMipmap();
	}
}

QByteArray QtScriptCCTexture2D::description()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

int QtScriptCCTexture2D::getPixelFormat()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return int(__o->getPixelFormat());
	}
	return 0;
}

void QtScriptCCTexture2D::initWithPVR(cocos2d::CCTexturePVR* pvr)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->initWithPVR(pvr);
	}
}

bool QtScriptCCTexture2D::initWithPVR(const QByteArray& data, size_t len, int compression)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithPVR(reinterpret_cast<const unsigned char*>(data.data()), len, cocos2d::CCTexturePVR::Compression(compression));
	}
	return false;
}

bool QtScriptCCTexture2D::initWithPVRFile(const QByteArray& file)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->initWithPVRFile(file.data());
	}
	return false;
}

cocos2d::CCSize QtScriptCCTexture2D::getContentSizeInPixels()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getContentSizeInPixels();
	}
	return cocos2d::CCSize();
}

unsigned int QtScriptCCTexture2D::getPixelsWide()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->getPixelsWide();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCTexture2D::drawAtPoint(const cocos2d::CCPoint& point)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->drawAtPoint(point);
	}
}

bool QtScriptCCTexture2D::hasMipmaps()
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		return __o->hasMipmaps();
	}
	return false;
}

void QtScriptCCTexture2D::setMaxS(float var)
{
	auto __o = this->thiz<CCTexture2D *>();
	if (__o)
	{
		__o->setMaxS(var);
	}
}

QScriptValue QtScriptCCTexture2D::setDefaultAlphaPixelFormat(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<int>(context->argument(0));
			auto arg0 = cocos2d::CCTexture2DPixelFormat(tmp_0);
			CCTexture2D::setDefaultAlphaPixelFormat(arg0);
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTexture2D::setDefaultAlphaPixelFormat");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTexture2D::defaultAlphaPixelFormat(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(int(CCTexture2D::defaultAlphaPixelFormat()));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTexture2D::defaultAlphaPixelFormat");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTexture2D::PVRImagesHavePremultipliedAlpha(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<bool>(context->argument(0));
			CCTexture2D::PVRImagesHavePremultipliedAlpha(arg0);
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTexture2D::PVRImagesHavePremultipliedAlpha");
	return __e->uncaughtException();
}

int QtScriptCCTexture2D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTexture2D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTexture2D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTexture2D();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTexture2D constructor");
	}
	return ok;
}

bool QtScriptCCTexture2D::_public_field_get_bHasPremultipliedAlpha() const
{
	auto object = thiz<CCTexture2D *>();
	if (object)
	{
		return object->m_bHasPremultipliedAlpha;
	}
	return false;
}

void QtScriptCCTexture2D::_public_field_set_bHasPremultipliedAlpha(const bool& value)
{
	auto object = thiz<CCTexture2D *>();
	if (object)
	{
		object->m_bHasPremultipliedAlpha = value;
	}
}

bool QtScriptCCTexture2D::_public_field_get_bHasMipmaps() const
{
	auto object = thiz<CCTexture2D *>();
	if (object)
	{
		return object->m_bHasMipmaps;
	}
	return false;
}

void QtScriptCCTexture2D::_public_field_set_bHasMipmaps(const bool& value)
{
	auto object = thiz<CCTexture2D *>();
	if (object)
	{
		object->m_bHasMipmaps = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCNode::QtScriptCCNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCNode::QtScriptCCNode(QScriptEngine *engine)
	: QtScriptCCNode(engine, "Node")
{
}

void QtScriptCCNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCNode, QtScriptCCNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCNode::addChild(cocos2d::CCNode* child)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->addChild(child);
	}
}

void QtScriptCCNode::addChild(cocos2d::CCNode* child, int zOrder)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->addChild(child, zOrder);
	}
}

void QtScriptCCNode::addChild(cocos2d::CCNode* child, int zOrder, int tag)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->addChild(child, zOrder, tag);
	}
}

bool QtScriptCCNode::removeComponent(const QByteArray& pName)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->removeComponent(pName.data());
	}
	return false;
}

cocos2d::CCAffineTransform QtScriptCCNode::nodeToWorldTransform()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->nodeToWorldTransform();
	}
	return cocos2d::CCAffineTransform();
}

cocos2d::CCGLProgram* QtScriptCCNode::getShaderProgram()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getShaderProgram();
	}
	return nullptr;
}

cocos2d::CCObject* QtScriptCCNode::getUserObject()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getUserObject();
	}
	return nullptr;
}

cocos2d::CCArray* QtScriptCCNode::getChildren()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getChildren();
	}
	return nullptr;
}

cocos2d::CCPoint QtScriptCCNode::convertToWorldSpaceAR(const cocos2d::CCPoint& nodePoint)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->convertToWorldSpaceAR(nodePoint);
	}
	return cocos2d::CCPoint();
}

bool QtScriptCCNode::isIgnoreAnchorPointForPosition()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->isIgnoreAnchorPointForPosition();
	}
	return false;
}

bool QtScriptCCNode::init()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

void QtScriptCCNode::setRotation(float fRotation)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setRotation(fRotation);
	}
}

void QtScriptCCNode::setZOrder(int zOrder)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setZOrder(zOrder);
	}
}

void QtScriptCCNode::setScaleY(float fScaleY)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setScaleY(fScaleY);
	}
}

void QtScriptCCNode::setScaleX(float fScaleX)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setScaleX(fScaleX);
	}
}

void QtScriptCCNode::scheduleUpdateWithPriority(int priority)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->scheduleUpdateWithPriority(priority);
	}
}

void QtScriptCCNode::scheduleUpdateWithPriority(const QScriptValue& arg0, int arg1)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->scheduleUpdateWithPriorityLua(QtCocosScriptEngine::instance()->retainJSObject(arg0), arg1);
	}
}

void QtScriptCCNode::removeAllComponents()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeAllComponents();
	}
}

int QtScriptCCNode::getTag()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getTag();
	}
	return 0;
}

void QtScriptCCNode::onExit()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->onExit();
	}
}

void QtScriptCCNode::removeChild(cocos2d::CCNode* child)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeChild(child);
	}
}

void QtScriptCCNode::removeChild(cocos2d::CCNode* child, bool cleanup)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeChild(child, cleanup);
	}
}

cocos2d::CCPoint QtScriptCCNode::convertToWorldSpace(const cocos2d::CCPoint& nodePoint)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->convertToWorldSpace(nodePoint);
	}
	return cocos2d::CCPoint();
}

void QtScriptCCNode::setSkewX(float fSkewX)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setSkewX(fSkewX);
	}
}

void QtScriptCCNode::setSkewY(float fSkewY)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setSkewY(fSkewY);
	}
}

void QtScriptCCNode::onEnterTransitionDidFinish()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->onEnterTransitionDidFinish();
	}
}

cocos2d::CCPoint QtScriptCCNode::convertTouchToNodeSpace(cocos2d::CCTouch* touch)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->convertTouchToNodeSpace(touch);
	}
	return cocos2d::CCPoint();
}

void QtScriptCCNode::removeAllChildren()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeAllChildren();
	}
}

float QtScriptCCNode::getRotationX()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getRotationX();
	}
	return static_cast<float>(0);
}

float QtScriptCCNode::getRotationY()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getRotationY();
	}
	return static_cast<float>(0);
}

QByteArray QtScriptCCNode::description()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

void QtScriptCCNode::unscheduleUpdate()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->unscheduleUpdate();
	}
}

cocos2d::CCAffineTransform QtScriptCCNode::nodeToParentTransform()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->nodeToParentTransform();
	}
	return cocos2d::CCAffineTransform();
}

void QtScriptCCNode::unscheduleAllSelectors()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->unscheduleAllSelectors();
	}
}

void QtScriptCCNode::removeAllChildrenWithCleanup(bool cleanup)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeAllChildrenWithCleanup(cleanup);
	}
}

cocos2d::CCGridBase* QtScriptCCNode::getGrid()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getGrid();
	}
	return nullptr;
}

unsigned int QtScriptCCNode::numberOfRunningActions()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->numberOfRunningActions();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCNode::removeFromParentAndCleanup(bool cleanup)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeFromParentAndCleanup(cleanup);
	}
}

void QtScriptCCNode::setPosition(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setPosition(position);
	}
}

void QtScriptCCNode::setPosition(float x, float y)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setPosition(x, y);
	}
}

void QtScriptCCNode::stopActionByTag(int tag)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->stopActionByTag(tag);
	}
}

void QtScriptCCNode::reorderChild(cocos2d::CCNode* child, int zOrder)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->reorderChild(child, zOrder);
	}
}

void QtScriptCCNode::setGLServerState(int glServerState)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setGLServerState(cocos2d::ccGLServerState(glServerState));
	}
}

void QtScriptCCNode::setPositionY(float y)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setPositionY(y);
	}
}

void QtScriptCCNode::setPositionX(float x)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setPositionX(x);
	}
}

cocos2d::CCPoint QtScriptCCNode::getAnchorPoint()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getAnchorPoint();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCNode::updateTransform()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->updateTransform();
	}
}

void QtScriptCCNode::registerEventHandler(const QScriptValue& arg0)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->registerScriptHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0));
	}
}

bool QtScriptCCNode::isVisible()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->isVisible();
	}
	return false;
}

unsigned int QtScriptCCNode::getChildrenCount()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getChildrenCount();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCNode::setAnchorPoint(const cocos2d::CCPoint& anchorPoint)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setAnchorPoint(anchorPoint);
	}
}

void QtScriptCCNode::onEnter()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->onEnter();
	}
}

cocos2d::CCPoint QtScriptCCNode::convertToNodeSpaceAR(const cocos2d::CCPoint& worldPoint)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->convertToNodeSpaceAR(worldPoint);
	}
	return cocos2d::CCPoint();
}

bool QtScriptCCNode::addComponent(cocos2d::CCComponent* pComponent)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->addComponent(pComponent);
	}
	return false;
}

void QtScriptCCNode::unregisterEventHandler()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->unregisterScriptHandler();
	}
}

cocos2d::CCAction* QtScriptCCNode::runAction(cocos2d::CCAction* action)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->runAction(action);
	}
	return nullptr;
}

void QtScriptCCNode::setShaderProgram(cocos2d::CCGLProgram* pShaderProgram)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setShaderProgram(pShaderProgram);
	}
}

float QtScriptCCNode::getRotation()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getRotation();
	}
	return static_cast<float>(0);
}

void QtScriptCCNode::resumeSchedulerAndActions()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->resumeSchedulerAndActions();
	}
}

int QtScriptCCNode::getZOrder()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getZOrder();
	}
	return 0;
}

cocos2d::CCPoint QtScriptCCNode::getAnchorPointInPoints()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getAnchorPointInPoints();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCNode::visit()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->visit();
	}
}

void QtScriptCCNode::transform()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->transform();
	}
}

void QtScriptCCNode::setVertexZ(float vertexZ)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setVertexZ(vertexZ);
	}
}

void QtScriptCCNode::setScheduler(cocos2d::CCScheduler* scheduler)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setScheduler(scheduler);
	}
}

void QtScriptCCNode::stopAllActions()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->stopAllActions();
	}
}

float QtScriptCCNode::getSkewX()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getSkewX();
	}
	return static_cast<float>(0);
}

float QtScriptCCNode::getSkewY()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getSkewY();
	}
	return static_cast<float>(0);
}

void QtScriptCCNode::ignoreAnchorPointForPosition(bool ignore)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->ignoreAnchorPointForPosition(ignore);
	}
}

cocos2d::CCAction* QtScriptCCNode::getActionByTag(int tag)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getActionByTag(tag);
	}
	return nullptr;
}

void QtScriptCCNode::setRotationX(float fRotaionX)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setRotationX(fRotaionX);
	}
}

void QtScriptCCNode::setRotationY(float fRotationY)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setRotationY(fRotationY);
	}
}

void QtScriptCCNode::setAdditionalTransform(const cocos2d::CCAffineTransform& additionalTransform)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setAdditionalTransform(additionalTransform);
	}
}

cocos2d::CCScheduler* QtScriptCCNode::getScheduler()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getScheduler();
	}
	return nullptr;
}

unsigned int QtScriptCCNode::getOrderOfArrival()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getOrderOfArrival();
	}
	return static_cast<unsigned int>(0);
}

cocos2d::CCRect QtScriptCCNode::boundingBox()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->boundingBox();
	}
	return cocos2d::CCRect();
}

void QtScriptCCNode::setContentSize(const cocos2d::CCSize& contentSize)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setContentSize(contentSize);
	}
}

void QtScriptCCNode::setActionManager(cocos2d::CCActionManager* actionManager)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setActionManager(actionManager);
	}
}

cocos2d::CCPoint QtScriptCCNode::getPosition()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getPosition();
	}
	return cocos2d::CCPoint();
}

bool QtScriptCCNode::isRunning()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->isRunning();
	}
	return false;
}

cocos2d::CCNode* QtScriptCCNode::getParent()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getParent();
	}
	return nullptr;
}

float QtScriptCCNode::getPositionY()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getPositionY();
	}
	return static_cast<float>(0);
}

float QtScriptCCNode::getPositionX()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getPositionX();
	}
	return static_cast<float>(0);
}

void QtScriptCCNode::removeChildByTag(int tag)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeChildByTag(tag);
	}
}

void QtScriptCCNode::removeChildByTag(int tag, bool cleanup)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeChildByTag(tag, cleanup);
	}
}

void QtScriptCCNode::setVisible(bool visible)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setVisible(visible);
	}
}

void QtScriptCCNode::pauseSchedulerAndActions()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->pauseSchedulerAndActions();
	}
}

float QtScriptCCNode::getVertexZ()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getVertexZ();
	}
	return static_cast<float>(0);
}

void QtScriptCCNode::_setZOrder(int z)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->_setZOrder(z);
	}
}

void QtScriptCCNode::setScale(float scale)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setScale(scale);
	}
}

void QtScriptCCNode::setScale(float fScaleX, float fScaleY)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setScale(fScaleX, fScaleY);
	}
}

cocos2d::CCNode* QtScriptCCNode::getChildByTag(int tag)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getChildByTag(tag);
	}
	return nullptr;
}

void QtScriptCCNode::setOrderOfArrival(unsigned int uOrderOfArrival)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setOrderOfArrival(uOrderOfArrival);
	}
}

float QtScriptCCNode::getScaleY()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getScaleY();
	}
	return static_cast<float>(0);
}

float QtScriptCCNode::getScaleX()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getScaleX();
	}
	return static_cast<float>(0);
}

void QtScriptCCNode::cleanup()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->cleanup();
	}
}

cocos2d::CCComponent* QtScriptCCNode::getComponent(const QByteArray& pName)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getComponent(pName.data());
	}
	return nullptr;
}

cocos2d::CCSize QtScriptCCNode::getContentSize()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getContentSize();
	}
	return cocos2d::CCSize();
}

void QtScriptCCNode::setGrid(cocos2d::CCGridBase* pGrid)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setGrid(pGrid);
	}
}

void QtScriptCCNode::draw()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->draw();
	}
}

void QtScriptCCNode::transformAncestors()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->transformAncestors();
	}
}

void QtScriptCCNode::setUserObject(cocos2d::CCObject* pUserObject)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setUserObject(pUserObject);
	}
}

void QtScriptCCNode::removeFromParent()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->removeFromParent();
	}
}

cocos2d::CCPoint QtScriptCCNode::convertTouchToNodeSpaceAR(cocos2d::CCTouch* touch)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->convertTouchToNodeSpaceAR(touch);
	}
	return cocos2d::CCPoint();
}

void QtScriptCCNode::sortAllChildren()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->sortAllChildren();
	}
}

cocos2d::CCPoint QtScriptCCNode::convertToNodeSpace(const cocos2d::CCPoint& worldPoint)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->convertToNodeSpace(worldPoint);
	}
	return cocos2d::CCPoint();
}

void QtScriptCCNode::onExitTransitionDidStart()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->onExitTransitionDidStart();
	}
}

float QtScriptCCNode::getScale()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getScale();
	}
	return static_cast<float>(0);
}

cocos2d::CCAffineTransform QtScriptCCNode::worldToNodeTransform()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->worldToNodeTransform();
	}
	return cocos2d::CCAffineTransform();
}

cocos2d::CCAffineTransform QtScriptCCNode::parentToNodeTransform()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->parentToNodeTransform();
	}
	return cocos2d::CCAffineTransform();
}

cocos2d::CCCamera* QtScriptCCNode::getCamera()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getCamera();
	}
	return nullptr;
}

void QtScriptCCNode::setTag(int nTag)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->setTag(nTag);
	}
}

void QtScriptCCNode::scheduleUpdate()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->scheduleUpdate();
	}
}

int QtScriptCCNode::getGLServerState()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return int(__o->getGLServerState());
	}
	return 0;
}

void QtScriptCCNode::stopAction(cocos2d::CCAction* action)
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		__o->stopAction(action);
	}
}

cocos2d::CCActionManager* QtScriptCCNode::getActionManager()
{
	auto __o = this->thiz<CCNode *>();
	if (__o)
	{
		return __o->getActionManager();
	}
	return nullptr;
}

QScriptValue QtScriptCCNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCNode::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNode::create");
	return __e->uncaughtException();
}

int QtScriptCCNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCNode();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNode constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCNodeRGBA::QtScriptCCNodeRGBA(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCNodeRGBA::QtScriptCCNodeRGBA(QScriptEngine *engine)
	: QtScriptCCNodeRGBA(engine, "NodeRGBA")
{
}

void QtScriptCCNodeRGBA::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCNodeRGBA, QtScriptCCNodeRGBA>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCNodeRGBA::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCNodeRGBA::isOpacityModifyRGB()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->isOpacityModifyRGB();
	}
	return false;
}

void QtScriptCCNodeRGBA::setColor(const cocos2d::_ccColor3B& color)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->setColor(color);
	}
}

bool QtScriptCCNodeRGBA::isCascadeOpacityEnabled()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->isCascadeOpacityEnabled();
	}
	return false;
}

cocos2d::_ccColor3B QtScriptCCNodeRGBA::getColor()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->getColor();
	}
	return cocos2d::_ccColor3B();
}

unsigned char QtScriptCCNodeRGBA::getDisplayedOpacity()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->getDisplayedOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCNodeRGBA::setCascadeColorEnabled(bool cascadeColorEnabled)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->setCascadeColorEnabled(cascadeColorEnabled);
	}
}

void QtScriptCCNodeRGBA::setOpacity(unsigned char opacity)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->setOpacity(opacity);
	}
}

void QtScriptCCNodeRGBA::setOpacityModifyRGB(bool bValue)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->setOpacityModifyRGB(bValue);
	}
}

void QtScriptCCNodeRGBA::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->setCascadeOpacityEnabled(cascadeOpacityEnabled);
	}
}

void QtScriptCCNodeRGBA::updateDisplayedOpacity(unsigned char parentOpacity)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->updateDisplayedOpacity(parentOpacity);
	}
}

bool QtScriptCCNodeRGBA::isCascadeColorEnabled()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->isCascadeColorEnabled();
	}
	return false;
}

void QtScriptCCNodeRGBA::updateDisplayedColor(const cocos2d::_ccColor3B& parentColor)
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		__o->updateDisplayedColor(parentColor);
	}
}

unsigned char QtScriptCCNodeRGBA::getOpacity()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->getOpacity();
	}
	return static_cast<unsigned char>(0);
}

cocos2d::_ccColor3B QtScriptCCNodeRGBA::getDisplayedColor()
{
	auto __o = this->thiz<CCNodeRGBA *>();
	if (__o)
	{
		return __o->getDisplayedColor();
	}
	return cocos2d::_ccColor3B();
}

QScriptValue QtScriptCCNodeRGBA::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCNodeRGBA::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNodeRGBA::create");
	return __e->uncaughtException();
}

int QtScriptCCNodeRGBA::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCNodeRGBA::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCNodeRGBA::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCNodeRGBA();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNodeRGBA constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSpriteFrame::QtScriptCCSpriteFrame(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCSpriteFrame::QtScriptCCSpriteFrame(QScriptEngine *engine)
	: QtScriptCCSpriteFrame(engine, "SpriteFrame")
{
}

void QtScriptCCSpriteFrame::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCSpriteFrame, QtScriptCCSpriteFrame>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpriteFrame::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTexture", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpriteFrame::createWithTexture)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCSpriteFrame::setRotated(bool bRotated)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setRotated(bRotated);
	}
}

void QtScriptCCSpriteFrame::setTexture(cocos2d::CCTexture2D* pobTexture)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setTexture(pobTexture);
	}
}

cocos2d::CCPoint QtScriptCCSpriteFrame::getOffset()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getOffset();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCSpriteFrame::setRectInPixels(const cocos2d::CCRect& rectInPixels)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setRectInPixels(rectInPixels);
	}
}

cocos2d::CCTexture2D* QtScriptCCSpriteFrame::getTexture()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

cocos2d::CCRect QtScriptCCSpriteFrame::getRect()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getRect();
	}
	return cocos2d::CCRect();
}

void QtScriptCCSpriteFrame::setOffsetInPixels(const cocos2d::CCPoint& offsetInPixels)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setOffsetInPixels(offsetInPixels);
	}
}

cocos2d::CCRect QtScriptCCSpriteFrame::getRectInPixels()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getRectInPixels();
	}
	return cocos2d::CCRect();
}

void QtScriptCCSpriteFrame::setOriginalSize(const cocos2d::CCSize& sizeInPixels)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setOriginalSize(sizeInPixels);
	}
}

cocos2d::CCSize QtScriptCCSpriteFrame::getOriginalSizeInPixels()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getOriginalSizeInPixels();
	}
	return cocos2d::CCSize();
}

void QtScriptCCSpriteFrame::setOriginalSizeInPixels(const cocos2d::CCSize& sizeInPixels)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setOriginalSizeInPixels(sizeInPixels);
	}
}

void QtScriptCCSpriteFrame::setOffset(const cocos2d::CCPoint& offsets)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setOffset(offsets);
	}
}

bool QtScriptCCSpriteFrame::initWithTexture(cocos2d::CCTexture2D* pobTexture, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->initWithTexture(pobTexture, rect);
	}
	return false;
}

bool QtScriptCCSpriteFrame::initWithTexture(cocos2d::CCTexture2D* pobTexture, const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCPoint& offset, const cocos2d::CCSize& originalSize)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->initWithTexture(pobTexture, rect, rotated, offset, originalSize);
	}
	return false;
}

bool QtScriptCCSpriteFrame::isRotated()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->isRotated();
	}
	return false;
}

bool QtScriptCCSpriteFrame::initWithTextureFilename(const QByteArray& filename, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->initWithTextureFilename(filename.data(), rect);
	}
	return false;
}

bool QtScriptCCSpriteFrame::initWithTextureFilename(const QByteArray& filename, const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCPoint& offset, const cocos2d::CCSize& originalSize)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->initWithTextureFilename(filename.data(), rect, rotated, offset, originalSize);
	}
	return false;
}

void QtScriptCCSpriteFrame::setRect(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		__o->setRect(rect);
	}
}

cocos2d::CCPoint QtScriptCCSpriteFrame::getOffsetInPixels()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getOffsetInPixels();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCSize QtScriptCCSpriteFrame::getOriginalSize()
{
	auto __o = this->thiz<CCSpriteFrame *>();
	if (__o)
	{
		return __o->getOriginalSize();
	}
	return cocos2d::CCSize();
}

QScriptValue QtScriptCCSpriteFrame::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			return __e->toScriptValue(CCSpriteFrame::create(arg0, arg1));
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			auto arg3 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(3));
			auto arg4 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(4));
			return __e->toScriptValue(CCSpriteFrame::create(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteFrame::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSpriteFrame::createWithTexture(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			return __e->toScriptValue(CCSpriteFrame::createWithTexture(arg0, arg1));
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			auto arg3 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(3));
			auto arg4 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(4));
			return __e->toScriptValue(CCSpriteFrame::createWithTexture(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteFrame::createWithTexture");
	return __e->uncaughtException();
}

int QtScriptCCSpriteFrame::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSpriteFrame::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSpriteFrame::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCSpriteFrame();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteFrame constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCString::QtScriptCCString(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCString::QtScriptCCString(QScriptEngine *engine)
	: QtScriptCCString(engine, "String")
{
}

void QtScriptCCString::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCString, QtScriptCCString>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCString::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithContentsOfFile", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCString::createWithContentsOfFile)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithData", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCString::createWithData)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

unsigned int QtScriptCCString::uintValue()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->uintValue();
	}
	return static_cast<unsigned int>(0);
}

int QtScriptCCString::compare(const QByteArray& arg0)
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->compare(arg0.data());
	}
	return 0;
}

QByteArray QtScriptCCString::getCString()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return QByteArray(__o->getCString());
	}
	return QByteArray();
}

float QtScriptCCString::floatValue()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->floatValue();
	}
	return static_cast<float>(0);
}

int QtScriptCCString::intValue()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->intValue();
	}
	return 0;
}

double QtScriptCCString::doubleValue()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->doubleValue();
	}
	return static_cast<double>(0);
}

bool QtScriptCCString::boolValue()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->boolValue();
	}
	return false;
}

unsigned int QtScriptCCString::length()
{
	auto __o = this->thiz<CCString *>();
	if (__o)
	{
		return __o->length();
	}
	return static_cast<unsigned int>(0);
}

QScriptValue QtScriptCCString::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = std::string(tmp_0.data(), size_t(tmp_0.size()));
			return __e->toScriptValue(CCString::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCString::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCString::createWithContentsOfFile(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCString::createWithContentsOfFile(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCString::createWithContentsOfFile");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCString::createWithData(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = reinterpret_cast<const unsigned char*>(tmp_0.data());
			auto arg1 = qscriptvalue_cast<unsigned long>(context->argument(1));
			return __e->toScriptValue(CCString::createWithData(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCString::createWithData");
	return __e->uncaughtException();
}

int QtScriptCCString::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCString::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCString::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCString();
			ok = true;
			break;
		}
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			out = new CCString(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCString constructor");
	}
	return ok;
}

QByteArray QtScriptCCString::_public_field_get_sString() const
{
	auto object = thiz<CCString *>();
	if (object)
	{
		return QByteArray(object->m_sString.c_str(), int(object->m_sString.size()));
	}
	return QByteArray();
}

void QtScriptCCString::_public_field_set_sString(const QByteArray& value)
{
	auto object = thiz<CCString *>();
	if (object)
	{
		object->m_sString = std::string(value.data(), size_t(value.size()));
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDictionary::QtScriptCCDictionary(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCDictionary::QtScriptCCDictionary(QScriptEngine *engine)
	: QtScriptCCDictionary(engine, "Dictionary")
{
}

void QtScriptCCDictionary::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCDictionary, QtScriptCCDictionary>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDictionary::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithContentsOfFile", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDictionary::createWithContentsOfFile)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithDictionary", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDictionary::createWithDictionary)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

unsigned int QtScriptCCDictionary::count()
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->count();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCDictionary::setObject(cocos2d::CCObject* pObject, const QByteArray& key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->setObject(pObject, std::string(key.data(), size_t(key.size())));
	}
}

void QtScriptCCDictionary::setObjectWithId(cocos2d::CCObject* pObject, intptr_t key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->setObject(pObject, key);
	}
}

cocos2d::CCObject* QtScriptCCDictionary::objectWithId(intptr_t key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->objectForKey(key);
	}
	return nullptr;
}

const cocos2d::CCString* QtScriptCCDictionary::valueWithId(intptr_t key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return const_cast<const cocos2d::CCString*>(__o->valueForKey(key));
	}
	return nullptr;
}

void QtScriptCCDictionary::removeObjectWithId(intptr_t key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->removeObjectForKey(key);
	}
}

cocos2d::CCObject* QtScriptCCDictionary::objectForKey(const QByteArray& key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->objectForKey(std::string(key.data(), size_t(key.size())));
	}
	return nullptr;
}

cocos2d::CCObject* QtScriptCCDictionary::randomObject()
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->randomObject();
	}
	return nullptr;
}

void QtScriptCCDictionary::removeAllObjects()
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->removeAllObjects();
	}
}

void QtScriptCCDictionary::removeObjectsForKeys(cocos2d::CCArray* pKeyArray)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->removeObjectsForKeys(pKeyArray);
	}
}

void QtScriptCCDictionary::removeObjectForKey(const QByteArray& key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->removeObjectForKey(std::string(key.data(), size_t(key.size())));
	}
}

const cocos2d::CCString* QtScriptCCDictionary::valueForKey(const QByteArray& key)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return const_cast<const cocos2d::CCString*>(__o->valueForKey(std::string(key.data(), size_t(key.size()))));
	}
	return nullptr;
}

bool QtScriptCCDictionary::writeToFile(const QByteArray& fullPath)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->writeToFile(fullPath.data());
	}
	return false;
}

void QtScriptCCDictionary::removeObjectForElememt(cocos2d::CCDictElement* pElement)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		__o->removeObjectForElememt(pElement);
	}
}

cocos2d::CCArray* QtScriptCCDictionary::allKeys()
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->allKeys();
	}
	return nullptr;
}

cocos2d::CCArray* QtScriptCCDictionary::allKeysForObject(cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCDictionary *>();
	if (__o)
	{
		return __o->allKeysForObject(object);
	}
	return nullptr;
}

QScriptValue QtScriptCCDictionary::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCDictionary::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDictionary::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCDictionary::createWithContentsOfFile(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCDictionary::createWithContentsOfFile(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDictionary::createWithContentsOfFile");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCDictionary::createWithDictionary(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCDictionary*>(context->argument(0));
			return __e->toScriptValue(CCDictionary::createWithDictionary(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDictionary::createWithDictionary");
	return __e->uncaughtException();
}

int QtScriptCCDictionary::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDictionary::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDictionary::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCDictionary();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDictionary constructor");
	}
	return ok;
}

cocos2d::CCDictElement* QtScriptCCDictionary::_public_field_get_pElements() const
{
	auto object = thiz<CCDictionary *>();
	if (object)
	{
		return object->m_pElements;
	}
	return nullptr;
}

void QtScriptCCDictionary::_public_field_set_pElements(cocos2d::CCDictElement* value)
{
	auto object = thiz<CCDictionary *>();
	if (object)
	{
		object->m_pElements = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAnimationFrame::QtScriptCCAnimationFrame(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCAnimationFrame::QtScriptCCAnimationFrame(QScriptEngine *engine)
	: QtScriptCCAnimationFrame(engine, "AnimationFrame")
{
}

void QtScriptCCAnimationFrame::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCAnimationFrame, QtScriptCCAnimationFrame>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCAnimationFrame::setSpriteFrame(cocos2d::CCSpriteFrame* var)
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		__o->setSpriteFrame(var);
	}
}

cocos2d::CCDictionary* QtScriptCCAnimationFrame::getUserInfo()
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		return __o->getUserInfo();
	}
	return nullptr;
}

void QtScriptCCAnimationFrame::setDelayUnits(float var)
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		__o->setDelayUnits(var);
	}
}

cocos2d::CCSpriteFrame* QtScriptCCAnimationFrame::getSpriteFrame()
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		return __o->getSpriteFrame();
	}
	return nullptr;
}

float QtScriptCCAnimationFrame::getDelayUnits()
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		return __o->getDelayUnits();
	}
	return static_cast<float>(0);
}

void QtScriptCCAnimationFrame::setUserInfo(cocos2d::CCDictionary* var)
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		__o->setUserInfo(var);
	}
}

bool QtScriptCCAnimationFrame::initWithSpriteFrame(cocos2d::CCSpriteFrame* spriteFrame, float delayUnits, cocos2d::CCDictionary* userInfo)
{
	auto __o = this->thiz<CCAnimationFrame *>();
	if (__o)
	{
		return __o->initWithSpriteFrame(spriteFrame, delayUnits, userInfo);
	}
	return false;
}

int QtScriptCCAnimationFrame::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAnimationFrame::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAnimationFrame::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAnimationFrame();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimationFrame constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAnimation::QtScriptCCAnimation(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCAnimation::QtScriptCCAnimation(QScriptEngine *engine)
	: QtScriptCCAnimation(engine, "Animation")
{
}

void QtScriptCCAnimation::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCAnimation, QtScriptCCAnimation>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAnimation::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithSpriteFrames", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAnimation::createWithSpriteFrames)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCAnimation::addSpriteFrameWithFileName(const QByteArray& pszFileName)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->addSpriteFrameWithFileName(pszFileName.data());
	}
}

void QtScriptCCAnimation::setFrames(cocos2d::CCArray* var)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->setFrames(var);
	}
}

unsigned int QtScriptCCAnimation::getLoops()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->getLoops();
	}
	return static_cast<unsigned int>(0);
}

cocos2d::CCArray* QtScriptCCAnimation::getFrames()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->getFrames();
	}
	return nullptr;
}

void QtScriptCCAnimation::addSpriteFrame(cocos2d::CCSpriteFrame* pFrame)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->addSpriteFrame(pFrame);
	}
}

float QtScriptCCAnimation::getDuration()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->getDuration();
	}
	return static_cast<float>(0);
}

bool QtScriptCCAnimation::initWithAnimationFrames(cocos2d::CCArray* arrayOfAnimationFrames, float delayPerUnit, unsigned int loops)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->initWithAnimationFrames(arrayOfAnimationFrames, delayPerUnit, loops);
	}
	return false;
}

bool QtScriptCCAnimation::init()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

bool QtScriptCCAnimation::initWithSpriteFrames(cocos2d::CCArray* pFrames)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->initWithSpriteFrames(pFrames);
	}
	return false;
}

bool QtScriptCCAnimation::initWithSpriteFrames(cocos2d::CCArray* pFrames, float delay)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->initWithSpriteFrames(pFrames, delay);
	}
	return false;
}

void QtScriptCCAnimation::setLoops(unsigned int var)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->setLoops(var);
	}
}

void QtScriptCCAnimation::setDelayPerUnit(float var)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->setDelayPerUnit(var);
	}
}

void QtScriptCCAnimation::setRestoreOriginalFrame(bool var)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->setRestoreOriginalFrame(var);
	}
}

float QtScriptCCAnimation::getTotalDelayUnits()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->getTotalDelayUnits();
	}
	return static_cast<float>(0);
}

float QtScriptCCAnimation::getDelayPerUnit()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->getDelayPerUnit();
	}
	return static_cast<float>(0);
}

bool QtScriptCCAnimation::getRestoreOriginalFrame()
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		return __o->getRestoreOriginalFrame();
	}
	return false;
}

void QtScriptCCAnimation::addSpriteFrameWithTexture(cocos2d::CCTexture2D* pobTexture, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCAnimation *>();
	if (__o)
	{
		__o->addSpriteFrameWithTexture(pobTexture, rect);
	}
}

QScriptValue QtScriptCCAnimation::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCAnimation::create());
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCAnimation::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			return __e->toScriptValue(CCAnimation::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimation::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCAnimation::createWithSpriteFrames(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			return __e->toScriptValue(CCAnimation::createWithSpriteFrames(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCAnimation::createWithSpriteFrames(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimation::createWithSpriteFrames");
	return __e->uncaughtException();
}

int QtScriptCCAnimation::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAnimation::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAnimation::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAnimation();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimation constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionInterval::QtScriptCCActionInterval(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCFiniteTimeAction(engine, className)
{
}

QtScriptCCActionInterval::QtScriptCCActionInterval(QScriptEngine *engine)
	: QtScriptCCActionInterval(engine, "ActionInterval")
{
}

void QtScriptCCActionInterval::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCFiniteTimeAction *>());
	auto ctor = RegisterT<CCActionInterval, QtScriptCCActionInterval>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCActionInterval::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCActionInterval::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionInterval::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionInterval::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCActionInterval;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCActionInterval constructor");
	return false;
}

void QtScriptCCActionInterval::setAmplitudeRate(float amp)
{
	auto __o = this->thiz<CCActionInterval *>();
	if (__o)
	{
		__o->setAmplitudeRate(amp);
	}
}

float QtScriptCCActionInterval::getAmplitudeRate()
{
	auto __o = this->thiz<CCActionInterval *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

bool QtScriptCCActionInterval::initWithDuration(float d)
{
	auto __o = this->thiz<CCActionInterval *>();
	if (__o)
	{
		return __o->initWithDuration(d);
	}
	return false;
}

float QtScriptCCActionInterval::getElapsed()
{
	auto __o = this->thiz<CCActionInterval *>();
	if (__o)
	{
		return __o->getElapsed();
	}
	return static_cast<float>(0);
}

cocos2d::CCActionInterval* QtScriptCCActionInterval::reverse()
{
	auto __o = this->thiz<CCActionInterval *>();
	if (__o)
	{
		return __o->reverse();
	}
	return nullptr;
}

QScriptValue QtScriptCCActionInterval::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCActionInterval::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCActionInterval::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSequence::QtScriptCCSequence(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCSequence::QtScriptCCSequence(QScriptEngine *engine)
	: QtScriptCCSequence(engine, "Sequence")
{
}

void QtScriptCCSequence::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCSequence, QtScriptCCSequence>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSequence::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTwoActions", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSequence::createWithTwoActions)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSequence::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSequence::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSequence::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCSequence;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCSequence constructor");
	return false;
}

bool QtScriptCCSequence::initWithTwoActions(cocos2d::CCFiniteTimeAction* pActionOne, cocos2d::CCFiniteTimeAction* pActionTwo)
{
	auto __o = this->thiz<CCSequence *>();
	if (__o)
	{
		return __o->initWithTwoActions(pActionOne, pActionTwo);
	}
	return false;
}

QScriptValue QtScriptCCSequence::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			return __e->toScriptValue(CCSequence::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSequence::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSequence::createWithTwoActions(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(1));
			return __e->toScriptValue(CCSequence::createWithTwoActions(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSequence::createWithTwoActions");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRepeat::QtScriptCCRepeat(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCRepeat::QtScriptCCRepeat(QScriptEngine *engine)
	: QtScriptCCRepeat(engine, "Repeat")
{
}

void QtScriptCCRepeat::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCRepeat, QtScriptCCRepeat>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRepeat::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCRepeat::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRepeat::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRepeat::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCRepeat;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCRepeat constructor");
	return false;
}

void QtScriptCCRepeat::setInnerAction(cocos2d::CCFiniteTimeAction* pAction)
{
	auto __o = this->thiz<CCRepeat *>();
	if (__o)
	{
		__o->setInnerAction(pAction);
	}
}

bool QtScriptCCRepeat::initWithAction(cocos2d::CCFiniteTimeAction* pAction, unsigned int times)
{
	auto __o = this->thiz<CCRepeat *>();
	if (__o)
	{
		return __o->initWithAction(pAction, times);
	}
	return false;
}

cocos2d::CCFiniteTimeAction* QtScriptCCRepeat::getInnerAction()
{
	auto __o = this->thiz<CCRepeat *>();
	if (__o)
	{
		return __o->getInnerAction();
	}
	return nullptr;
}

QScriptValue QtScriptCCRepeat::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCRepeat::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRepeat::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRepeatForever::QtScriptCCRepeatForever(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCRepeatForever::QtScriptCCRepeatForever(QScriptEngine *engine)
	: QtScriptCCRepeatForever(engine, "RepeatForever")
{
}

void QtScriptCCRepeatForever::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCRepeatForever, QtScriptCCRepeatForever>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRepeatForever::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCRepeatForever::setInnerAction(cocos2d::CCActionInterval* pAction)
{
	auto __o = this->thiz<CCRepeatForever *>();
	if (__o)
	{
		__o->setInnerAction(pAction);
	}
}

bool QtScriptCCRepeatForever::initWithAction(cocos2d::CCActionInterval* pAction)
{
	auto __o = this->thiz<CCRepeatForever *>();
	if (__o)
	{
		return __o->initWithAction(pAction);
	}
	return false;
}

cocos2d::CCActionInterval* QtScriptCCRepeatForever::getInnerAction()
{
	auto __o = this->thiz<CCRepeatForever *>();
	if (__o)
	{
		return __o->getInnerAction();
	}
	return nullptr;
}

QScriptValue QtScriptCCRepeatForever::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCRepeatForever::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRepeatForever::create");
	return __e->uncaughtException();
}

int QtScriptCCRepeatForever::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRepeatForever::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRepeatForever::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCRepeatForever();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRepeatForever constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSpawn::QtScriptCCSpawn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCSpawn::QtScriptCCSpawn(QScriptEngine *engine)
	: QtScriptCCSpawn(engine, "Spawn")
{
}

void QtScriptCCSpawn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCSpawn, QtScriptCCSpawn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpawn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTwoActions", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpawn::createWithTwoActions)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSpawn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSpawn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSpawn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCSpawn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCSpawn constructor");
	return false;
}

bool QtScriptCCSpawn::initWithTwoActions(cocos2d::CCFiniteTimeAction* pAction1, cocos2d::CCFiniteTimeAction* pAction2)
{
	auto __o = this->thiz<CCSpawn *>();
	if (__o)
	{
		return __o->initWithTwoActions(pAction1, pAction2);
	}
	return false;
}

QScriptValue QtScriptCCSpawn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			return __e->toScriptValue(CCSpawn::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpawn::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSpawn::createWithTwoActions(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(1));
			return __e->toScriptValue(CCSpawn::createWithTwoActions(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpawn::createWithTwoActions");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRotateTo::QtScriptCCRotateTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCRotateTo::QtScriptCCRotateTo(QScriptEngine *engine)
	: QtScriptCCRotateTo(engine, "RotateTo")
{
}

void QtScriptCCRotateTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCRotateTo, QtScriptCCRotateTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRotateTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCRotateTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRotateTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRotateTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCRotateTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCRotateTo constructor");
	return false;
}

bool QtScriptCCRotateTo::initWithDuration(float fDuration, float fDeltaAngle)
{
	auto __o = this->thiz<CCRotateTo *>();
	if (__o)
	{
		return __o->initWithDuration(fDuration, fDeltaAngle);
	}
	return false;
}

bool QtScriptCCRotateTo::initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY)
{
	auto __o = this->thiz<CCRotateTo *>();
	if (__o)
	{
		return __o->initWithDuration(fDuration, fDeltaAngleX, fDeltaAngleY);
	}
	return false;
}

QScriptValue QtScriptCCRotateTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCRotateTo::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCRotateTo::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRotateTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRotateBy::QtScriptCCRotateBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCRotateBy::QtScriptCCRotateBy(QScriptEngine *engine)
	: QtScriptCCRotateBy(engine, "RotateBy")
{
}

void QtScriptCCRotateBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCRotateBy, QtScriptCCRotateBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRotateBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCRotateBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRotateBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRotateBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCRotateBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCRotateBy constructor");
	return false;
}

bool QtScriptCCRotateBy::initWithDuration(float fDuration, float fDeltaAngle)
{
	auto __o = this->thiz<CCRotateBy *>();
	if (__o)
	{
		return __o->initWithDuration(fDuration, fDeltaAngle);
	}
	return false;
}

bool QtScriptCCRotateBy::initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY)
{
	auto __o = this->thiz<CCRotateBy *>();
	if (__o)
	{
		return __o->initWithDuration(fDuration, fDeltaAngleX, fDeltaAngleY);
	}
	return false;
}

QScriptValue QtScriptCCRotateBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCRotateBy::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCRotateBy::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRotateBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMoveBy::QtScriptCCMoveBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCMoveBy::QtScriptCCMoveBy(QScriptEngine *engine)
	: QtScriptCCMoveBy(engine, "MoveBy")
{
}

void QtScriptCCMoveBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCMoveBy, QtScriptCCMoveBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMoveBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCMoveBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMoveBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMoveBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCMoveBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCMoveBy constructor");
	return false;
}

bool QtScriptCCMoveBy::initWithDuration(float duration, const cocos2d::CCPoint& deltaPosition)
{
	auto __o = this->thiz<CCMoveBy *>();
	if (__o)
	{
		return __o->initWithDuration(duration, deltaPosition);
	}
	return false;
}

QScriptValue QtScriptCCMoveBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(1));
			return __e->toScriptValue(CCMoveBy::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMoveBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMoveTo::QtScriptCCMoveTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMoveBy(engine, className)
{
}

QtScriptCCMoveTo::QtScriptCCMoveTo(QScriptEngine *engine)
	: QtScriptCCMoveTo(engine, "MoveTo")
{
}

void QtScriptCCMoveTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMoveBy *>());
	auto ctor = RegisterT<CCMoveTo, QtScriptCCMoveTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMoveTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCMoveTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMoveTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMoveTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCMoveTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCMoveTo constructor");
	return false;
}

bool QtScriptCCMoveTo::initWithDuration(float duration, const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCMoveTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, position);
	}
	return false;
}

QScriptValue QtScriptCCMoveTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(1));
			return __e->toScriptValue(CCMoveTo::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMoveTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSkewTo::QtScriptCCSkewTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCSkewTo::QtScriptCCSkewTo(QScriptEngine *engine)
	: QtScriptCCSkewTo(engine, "SkewTo")
{
}

void QtScriptCCSkewTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCSkewTo, QtScriptCCSkewTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSkewTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCSkewTo::initWithDuration(float t, float sx, float sy)
{
	auto __o = this->thiz<CCSkewTo *>();
	if (__o)
	{
		return __o->initWithDuration(t, sx, sy);
	}
	return false;
}

QScriptValue QtScriptCCSkewTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCSkewTo::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSkewTo::create");
	return __e->uncaughtException();
}

int QtScriptCCSkewTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSkewTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSkewTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCSkewTo();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSkewTo constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSkewBy::QtScriptCCSkewBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCSkewTo(engine, className)
{
}

QtScriptCCSkewBy::QtScriptCCSkewBy(QScriptEngine *engine)
	: QtScriptCCSkewBy(engine, "SkewBy")
{
}

void QtScriptCCSkewBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCSkewTo *>());
	auto ctor = RegisterT<CCSkewBy, QtScriptCCSkewBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSkewBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSkewBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSkewBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSkewBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCSkewBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCSkewBy constructor");
	return false;
}

QScriptValue QtScriptCCSkewBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCSkewBy::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSkewBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCJumpBy::QtScriptCCJumpBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCJumpBy::QtScriptCCJumpBy(QScriptEngine *engine)
	: QtScriptCCJumpBy(engine, "JumpBy")
{
}

void QtScriptCCJumpBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCJumpBy, QtScriptCCJumpBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCJumpBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCJumpBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCJumpBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCJumpBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCJumpBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCJumpBy constructor");
	return false;
}

bool QtScriptCCJumpBy::initWithDuration(float duration, const cocos2d::CCPoint& position, float height, unsigned int jumps)
{
	auto __o = this->thiz<CCJumpBy *>();
	if (__o)
	{
		return __o->initWithDuration(duration, position, height, jumps);
	}
	return false;
}

QScriptValue QtScriptCCJumpBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<unsigned int>(context->argument(3));
			return __e->toScriptValue(CCJumpBy::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCJumpBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCJumpTo::QtScriptCCJumpTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCJumpBy(engine, className)
{
}

QtScriptCCJumpTo::QtScriptCCJumpTo(QScriptEngine *engine)
	: QtScriptCCJumpTo(engine, "JumpTo")
{
}

void QtScriptCCJumpTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCJumpBy *>());
	auto ctor = RegisterT<CCJumpTo, QtScriptCCJumpTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCJumpTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCJumpTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCJumpTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCJumpTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCJumpTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCJumpTo constructor");
	return false;
}

QScriptValue QtScriptCCJumpTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<int>(context->argument(3));
			return __e->toScriptValue(CCJumpTo::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCJumpTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScript_ccBezierConfig::QtScript_ccBezierConfig(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<_ccBezierConfig, false>(engine, className)
{
}

QtScript_ccBezierConfig::QtScript_ccBezierConfig(QScriptEngine *engine)
	: QtScript_ccBezierConfig(engine, "BezierConfig")
{
}

void QtScript_ccBezierConfig::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<_ccBezierConfig, QtScript_ccBezierConfig>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScript_ccBezierConfig::constructorArgumentCountMin() const
{
	return 0;
}

int QtScript_ccBezierConfig::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScript_ccBezierConfig::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::_ccBezierConfig constructor");
	return false;
}

cocos2d::CCPoint QtScript_ccBezierConfig::_public_field_get_endPosition() const
{
	auto object = thiz<_ccBezierConfig *>();
	if (object)
	{
		return object->endPosition;
	}
	return cocos2d::CCPoint();
}

void QtScript_ccBezierConfig::_public_field_set_endPosition(const cocos2d::CCPoint& value)
{
	auto object = thiz<_ccBezierConfig *>();
	if (object)
	{
		object->endPosition = value;
	}
}

cocos2d::CCPoint QtScript_ccBezierConfig::_public_field_get_controlPoint_1() const
{
	auto object = thiz<_ccBezierConfig *>();
	if (object)
	{
		return object->controlPoint_1;
	}
	return cocos2d::CCPoint();
}

void QtScript_ccBezierConfig::_public_field_set_controlPoint_1(const cocos2d::CCPoint& value)
{
	auto object = thiz<_ccBezierConfig *>();
	if (object)
	{
		object->controlPoint_1 = value;
	}
}

cocos2d::CCPoint QtScript_ccBezierConfig::_public_field_get_controlPoint_2() const
{
	auto object = thiz<_ccBezierConfig *>();
	if (object)
	{
		return object->controlPoint_2;
	}
	return cocos2d::CCPoint();
}

void QtScript_ccBezierConfig::_public_field_set_controlPoint_2(const cocos2d::CCPoint& value)
{
	auto object = thiz<_ccBezierConfig *>();
	if (object)
	{
		object->controlPoint_2 = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCBezierBy::QtScriptCCBezierBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCBezierBy::QtScriptCCBezierBy(QScriptEngine *engine)
	: QtScriptCCBezierBy(engine, "BezierBy")
{
}

void QtScriptCCBezierBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCBezierBy, QtScriptCCBezierBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCBezierBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCBezierBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCBezierBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCBezierBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCBezierBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCBezierBy constructor");
	return false;
}

bool QtScriptCCBezierBy::initWithDuration(float t, const cocos2d::_ccBezierConfig& c)
{
	auto __o = this->thiz<CCBezierBy *>();
	if (__o)
	{
		return __o->initWithDuration(t, c);
	}
	return false;
}

QScriptValue QtScriptCCBezierBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::_ccBezierConfig>(context->argument(1));
			return __e->toScriptValue(CCBezierBy::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBezierBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCBezierTo::QtScriptCCBezierTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCBezierBy(engine, className)
{
}

QtScriptCCBezierTo::QtScriptCCBezierTo(QScriptEngine *engine)
	: QtScriptCCBezierTo(engine, "BezierTo")
{
}

void QtScriptCCBezierTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCBezierBy *>());
	auto ctor = RegisterT<CCBezierTo, QtScriptCCBezierTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCBezierTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCBezierTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCBezierTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCBezierTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCBezierTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCBezierTo constructor");
	return false;
}

bool QtScriptCCBezierTo::initWithDuration(float t, const cocos2d::_ccBezierConfig& c)
{
	auto __o = this->thiz<CCBezierTo *>();
	if (__o)
	{
		return __o->initWithDuration(t, c);
	}
	return false;
}

QScriptValue QtScriptCCBezierTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::_ccBezierConfig>(context->argument(1));
			return __e->toScriptValue(CCBezierTo::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBezierTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCScaleTo::QtScriptCCScaleTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCScaleTo::QtScriptCCScaleTo(QScriptEngine *engine)
	: QtScriptCCScaleTo(engine, "ScaleTo")
{
}

void QtScriptCCScaleTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCScaleTo, QtScriptCCScaleTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCScaleTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCScaleTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCScaleTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCScaleTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCScaleTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCScaleTo constructor");
	return false;
}

bool QtScriptCCScaleTo::initWithDuration(float duration, float s)
{
	auto __o = this->thiz<CCScaleTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, s);
	}
	return false;
}

bool QtScriptCCScaleTo::initWithDuration(float duration, float sx, float sy)
{
	auto __o = this->thiz<CCScaleTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, sx, sy);
	}
	return false;
}

QScriptValue QtScriptCCScaleTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCScaleTo::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCScaleTo::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCScaleTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCScaleBy::QtScriptCCScaleBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCScaleTo(engine, className)
{
}

QtScriptCCScaleBy::QtScriptCCScaleBy(QScriptEngine *engine)
	: QtScriptCCScaleBy(engine, "ScaleBy")
{
}

void QtScriptCCScaleBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCScaleTo *>());
	auto ctor = RegisterT<CCScaleBy, QtScriptCCScaleBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCScaleBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCScaleBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCScaleBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCScaleBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCScaleBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCScaleBy constructor");
	return false;
}

QScriptValue QtScriptCCScaleBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCScaleBy::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCScaleBy::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCScaleBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCBlink::QtScriptCCBlink(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCBlink::QtScriptCCBlink(QScriptEngine *engine)
	: QtScriptCCBlink(engine, "Blink")
{
}

void QtScriptCCBlink::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCBlink, QtScriptCCBlink>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCBlink::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCBlink::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCBlink::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCBlink::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCBlink;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCBlink constructor");
	return false;
}

bool QtScriptCCBlink::initWithDuration(float duration, unsigned int uBlinks)
{
	auto __o = this->thiz<CCBlink *>();
	if (__o)
	{
		return __o->initWithDuration(duration, uBlinks);
	}
	return false;
}

QScriptValue QtScriptCCBlink::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCBlink::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBlink::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeIn::QtScriptCCFadeIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCFadeIn::QtScriptCCFadeIn(QScriptEngine *engine)
	: QtScriptCCFadeIn(engine, "FadeIn")
{
}

void QtScriptCCFadeIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCFadeIn, QtScriptCCFadeIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeIn constructor");
	return false;
}

QScriptValue QtScriptCCFadeIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCFadeIn::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeOut::QtScriptCCFadeOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCFadeOut::QtScriptCCFadeOut(QScriptEngine *engine)
	: QtScriptCCFadeOut(engine, "FadeOut")
{
}

void QtScriptCCFadeOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCFadeOut, QtScriptCCFadeOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeOut constructor");
	return false;
}

QScriptValue QtScriptCCFadeOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCFadeOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeTo::QtScriptCCFadeTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCFadeTo::QtScriptCCFadeTo(QScriptEngine *engine)
	: QtScriptCCFadeTo(engine, "FadeTo")
{
}

void QtScriptCCFadeTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCFadeTo, QtScriptCCFadeTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeTo constructor");
	return false;
}

bool QtScriptCCFadeTo::initWithDuration(float duration, unsigned char opacity)
{
	auto __o = this->thiz<CCFadeTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, opacity);
	}
	return false;
}

QScriptValue QtScriptCCFadeTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned char>(context->argument(1));
			return __e->toScriptValue(CCFadeTo::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTintTo::QtScriptCCTintTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCTintTo::QtScriptCCTintTo(QScriptEngine *engine)
	: QtScriptCCTintTo(engine, "TintTo")
{
}

void QtScriptCCTintTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCTintTo, QtScriptCCTintTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTintTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTintTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTintTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTintTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTintTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTintTo constructor");
	return false;
}

bool QtScriptCCTintTo::initWithDuration(float duration, unsigned char red, unsigned char green, unsigned char blue)
{
	auto __o = this->thiz<CCTintTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, red, green, blue);
	}
	return false;
}

QScriptValue QtScriptCCTintTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned char>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned char>(context->argument(2));
			auto arg3 = qscriptvalue_cast<unsigned char>(context->argument(3));
			return __e->toScriptValue(CCTintTo::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTintTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTintBy::QtScriptCCTintBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCTintBy::QtScriptCCTintBy(QScriptEngine *engine)
	: QtScriptCCTintBy(engine, "TintBy")
{
}

void QtScriptCCTintBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCTintBy, QtScriptCCTintBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTintBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTintBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTintBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTintBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTintBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTintBy constructor");
	return false;
}

bool QtScriptCCTintBy::initWithDuration(float duration, short deltaRed, short deltaGreen, short deltaBlue)
{
	auto __o = this->thiz<CCTintBy *>();
	if (__o)
	{
		return __o->initWithDuration(duration, deltaRed, deltaGreen, deltaBlue);
	}
	return false;
}

QScriptValue QtScriptCCTintBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<short>(context->argument(1));
			auto arg2 = qscriptvalue_cast<short>(context->argument(2));
			auto arg3 = qscriptvalue_cast<short>(context->argument(3));
			return __e->toScriptValue(CCTintBy::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTintBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDelayTime::QtScriptCCDelayTime(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCDelayTime::QtScriptCCDelayTime(QScriptEngine *engine)
	: QtScriptCCDelayTime(engine, "DelayTime")
{
}

void QtScriptCCDelayTime::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCDelayTime, QtScriptCCDelayTime>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDelayTime::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCDelayTime::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDelayTime::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDelayTime::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCDelayTime;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCDelayTime constructor");
	return false;
}

QScriptValue QtScriptCCDelayTime::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCDelayTime::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDelayTime::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCReverseTime::QtScriptCCReverseTime(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCReverseTime::QtScriptCCReverseTime(QScriptEngine *engine)
	: QtScriptCCReverseTime(engine, "ReverseTime")
{
}

void QtScriptCCReverseTime::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCReverseTime, QtScriptCCReverseTime>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCReverseTime::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCReverseTime::initWithAction(cocos2d::CCFiniteTimeAction* pAction)
{
	auto __o = this->thiz<CCReverseTime *>();
	if (__o)
	{
		return __o->initWithAction(pAction);
	}
	return false;
}

QScriptValue QtScriptCCReverseTime::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(0));
			return __e->toScriptValue(CCReverseTime::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCReverseTime::create");
	return __e->uncaughtException();
}

int QtScriptCCReverseTime::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCReverseTime::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCReverseTime::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCReverseTime();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCReverseTime constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAnimate::QtScriptCCAnimate(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCAnimate::QtScriptCCAnimate(QScriptEngine *engine)
	: QtScriptCCAnimate(engine, "Animate")
{
}

void QtScriptCCAnimate::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCAnimate, QtScriptCCAnimate>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAnimate::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCAnimation* QtScriptCCAnimate::getAnimation()
{
	auto __o = this->thiz<CCAnimate *>();
	if (__o)
	{
		return __o->getAnimation();
	}
	return nullptr;
}

bool QtScriptCCAnimate::initWithAnimation(cocos2d::CCAnimation* pAnimation)
{
	auto __o = this->thiz<CCAnimate *>();
	if (__o)
	{
		return __o->initWithAnimation(pAnimation);
	}
	return false;
}

void QtScriptCCAnimate::setAnimation(cocos2d::CCAnimation* var)
{
	auto __o = this->thiz<CCAnimate *>();
	if (__o)
	{
		__o->setAnimation(var);
	}
}

QScriptValue QtScriptCCAnimate::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCAnimation*>(context->argument(0));
			return __e->toScriptValue(CCAnimate::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimate::create");
	return __e->uncaughtException();
}

int QtScriptCCAnimate::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAnimate::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAnimate::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAnimate();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimate constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTargetedAction::QtScriptCCTargetedAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCTargetedAction::QtScriptCCTargetedAction(QScriptEngine *engine)
	: QtScriptCCTargetedAction(engine, "TargetedAction")
{
}

void QtScriptCCTargetedAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCTargetedAction, QtScriptCCTargetedAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTargetedAction::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCNode* QtScriptCCTargetedAction::getForcedTarget()
{
	auto __o = this->thiz<CCTargetedAction *>();
	if (__o)
	{
		return __o->getForcedTarget();
	}
	return nullptr;
}

bool QtScriptCCTargetedAction::initWithTarget(cocos2d::CCNode* pTarget, cocos2d::CCFiniteTimeAction* pAction)
{
	auto __o = this->thiz<CCTargetedAction *>();
	if (__o)
	{
		return __o->initWithTarget(pTarget, pAction);
	}
	return false;
}

void QtScriptCCTargetedAction::setForcedTarget(cocos2d::CCNode* var)
{
	auto __o = this->thiz<CCTargetedAction *>();
	if (__o)
	{
		__o->setForcedTarget(var);
	}
}

QScriptValue QtScriptCCTargetedAction::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCFiniteTimeAction*>(context->argument(1));
			return __e->toScriptValue(CCTargetedAction::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTargetedAction::create");
	return __e->uncaughtException();
}

int QtScriptCCTargetedAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTargetedAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTargetedAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTargetedAction();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTargetedAction constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionCamera::QtScriptCCActionCamera(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCActionCamera::QtScriptCCActionCamera(QScriptEngine *engine)
	: QtScriptCCActionCamera(engine, "ActionCamera")
{
}

void QtScriptCCActionCamera::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCActionCamera, QtScriptCCActionCamera>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCActionCamera::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionCamera::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionCamera::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCActionCamera();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCActionCamera constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCOrbitCamera::QtScriptCCOrbitCamera(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionCamera(engine, className)
{
}

QtScriptCCOrbitCamera::QtScriptCCOrbitCamera(QScriptEngine *engine)
	: QtScriptCCOrbitCamera(engine, "OrbitCamera")
{
}

void QtScriptCCOrbitCamera::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionCamera *>());
	auto ctor = RegisterT<CCOrbitCamera, QtScriptCCOrbitCamera>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCOrbitCamera::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCOrbitCamera::initWithDuration(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX)
{
	auto __o = this->thiz<CCOrbitCamera *>();
	if (__o)
	{
		return __o->initWithDuration(t, radius, deltaRadius, angleZ, deltaAngleZ, angleX, deltaAngleX);
	}
	return false;
}

QScriptValue QtScriptCCOrbitCamera::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 7, 7))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 7:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			auto arg4 = qscriptvalue_cast<float>(context->argument(4));
			auto arg5 = qscriptvalue_cast<float>(context->argument(5));
			auto arg6 = qscriptvalue_cast<float>(context->argument(6));
			return __e->toScriptValue(CCOrbitCamera::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCOrbitCamera::create");
	return __e->uncaughtException();
}

int QtScriptCCOrbitCamera::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCOrbitCamera::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCOrbitCamera::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCOrbitCamera();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCOrbitCamera constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionManager::QtScriptCCActionManager(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCActionManager::QtScriptCCActionManager(QScriptEngine *engine)
	: QtScriptCCActionManager(engine, "ActionManager")
{
}

void QtScriptCCActionManager::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCActionManager, QtScriptCCActionManager>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

cocos2d::CCAction* QtScriptCCActionManager::getActionByTag(unsigned int tag, cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		return __o->getActionByTag(tag, pTarget);
	}
	return nullptr;
}

void QtScriptCCActionManager::addAction(cocos2d::CCAction* pAction, cocos2d::CCNode* pTarget, bool paused)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->addAction(pAction, pTarget, paused);
	}
}

void QtScriptCCActionManager::removeAllActions()
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->removeAllActions();
	}
}

void QtScriptCCActionManager::removeActionByTag(unsigned int tag, cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->removeActionByTag(tag, pTarget);
	}
}

void QtScriptCCActionManager::resumeTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->resumeTarget(pTarget);
	}
}

void QtScriptCCActionManager::pauseTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->pauseTarget(pTarget);
	}
}

void QtScriptCCActionManager::removeAllActionsFromTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->removeAllActionsFromTarget(pTarget);
	}
}

void QtScriptCCActionManager::resumeTargets(cocos2d::CCSet* targetsToResume)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->resumeTargets(targetsToResume);
	}
}

void QtScriptCCActionManager::removeAction(cocos2d::CCAction* pAction)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		__o->removeAction(pAction);
	}
}

unsigned int QtScriptCCActionManager::numberOfRunningActionsInTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		return __o->numberOfRunningActionsInTarget(pTarget);
	}
	return static_cast<unsigned int>(0);
}

cocos2d::CCSet* QtScriptCCActionManager::pauseAllRunningActions()
{
	auto __o = this->thiz<CCActionManager *>();
	if (__o)
	{
		return __o->pauseAllRunningActions();
	}
	return nullptr;
}

int QtScriptCCActionManager::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionManager::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionManager::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCActionManager();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCActionManager constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionEase::QtScriptCCActionEase(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCActionEase::QtScriptCCActionEase(QScriptEngine *engine)
	: QtScriptCCActionEase(engine, "ActionEase")
{
}

void QtScriptCCActionEase::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCActionEase, QtScriptCCActionEase>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCActionEase::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCActionEase::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionEase::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionEase::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCActionEase;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCActionEase constructor");
	return false;
}

bool QtScriptCCActionEase::initWithAction(cocos2d::CCActionInterval* pAction)
{
	auto __o = this->thiz<CCActionEase *>();
	if (__o)
	{
		return __o->initWithAction(pAction);
	}
	return false;
}

cocos2d::CCActionInterval* QtScriptCCActionEase::getInnerAction()
{
	auto __o = this->thiz<CCActionEase *>();
	if (__o)
	{
		return __o->getInnerAction();
	}
	return nullptr;
}

QScriptValue QtScriptCCActionEase::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCActionEase::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCActionEase::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseRateAction::QtScriptCCEaseRateAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseRateAction::QtScriptCCEaseRateAction(QScriptEngine *engine)
	: QtScriptCCEaseRateAction(engine, "EaseRateAction")
{
}

void QtScriptCCEaseRateAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseRateAction, QtScriptCCEaseRateAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseRateAction::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseRateAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseRateAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseRateAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseRateAction;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseRateAction constructor");
	return false;
}

void QtScriptCCEaseRateAction::setRate(float rate)
{
	auto __o = this->thiz<CCEaseRateAction *>();
	if (__o)
	{
		__o->setRate(rate);
	}
}

bool QtScriptCCEaseRateAction::initWithAction(cocos2d::CCActionInterval* pAction, float fRate)
{
	auto __o = this->thiz<CCEaseRateAction *>();
	if (__o)
	{
		return __o->initWithAction(pAction, fRate);
	}
	return false;
}

float QtScriptCCEaseRateAction::getRate()
{
	auto __o = this->thiz<CCEaseRateAction *>();
	if (__o)
	{
		return __o->getRate();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCEaseRateAction::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseRateAction::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseRateAction::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseIn::QtScriptCCEaseIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseRateAction(engine, className)
{
}

QtScriptCCEaseIn::QtScriptCCEaseIn(QScriptEngine *engine)
	: QtScriptCCEaseIn(engine, "EaseIn")
{
}

void QtScriptCCEaseIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseRateAction *>());
	auto ctor = RegisterT<CCEaseIn, QtScriptCCEaseIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseIn constructor");
	return false;
}

QScriptValue QtScriptCCEaseIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseIn::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseOut::QtScriptCCEaseOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseRateAction(engine, className)
{
}

QtScriptCCEaseOut::QtScriptCCEaseOut(QScriptEngine *engine)
	: QtScriptCCEaseOut(engine, "EaseOut")
{
}

void QtScriptCCEaseOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseRateAction *>());
	auto ctor = RegisterT<CCEaseOut, QtScriptCCEaseOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseOut::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseInOut::QtScriptCCEaseInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseRateAction(engine, className)
{
}

QtScriptCCEaseInOut::QtScriptCCEaseInOut(QScriptEngine *engine)
	: QtScriptCCEaseInOut(engine, "EaseInOut")
{
}

void QtScriptCCEaseInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseRateAction *>());
	auto ctor = RegisterT<CCEaseInOut, QtScriptCCEaseInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseInOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseInOut::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseExponentialIn::QtScriptCCEaseExponentialIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseExponentialIn::QtScriptCCEaseExponentialIn(QScriptEngine *engine)
	: QtScriptCCEaseExponentialIn(engine, "EaseExponentialIn")
{
}

void QtScriptCCEaseExponentialIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseExponentialIn, QtScriptCCEaseExponentialIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseExponentialIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseExponentialIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseExponentialIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseExponentialIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseExponentialIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseExponentialIn constructor");
	return false;
}

QScriptValue QtScriptCCEaseExponentialIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseExponentialIn::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseExponentialIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseExponentialOut::QtScriptCCEaseExponentialOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseExponentialOut::QtScriptCCEaseExponentialOut(QScriptEngine *engine)
	: QtScriptCCEaseExponentialOut(engine, "EaseExponentialOut")
{
}

void QtScriptCCEaseExponentialOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseExponentialOut, QtScriptCCEaseExponentialOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseExponentialOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseExponentialOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseExponentialOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseExponentialOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseExponentialOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseExponentialOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseExponentialOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseExponentialOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseExponentialOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseExponentialInOut::QtScriptCCEaseExponentialInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseExponentialInOut::QtScriptCCEaseExponentialInOut(QScriptEngine *engine)
	: QtScriptCCEaseExponentialInOut(engine, "EaseExponentialInOut")
{
}

void QtScriptCCEaseExponentialInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseExponentialInOut, QtScriptCCEaseExponentialInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseExponentialInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseExponentialInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseExponentialInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseExponentialInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseExponentialInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseExponentialInOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseExponentialInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseExponentialInOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseExponentialInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseSineIn::QtScriptCCEaseSineIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseSineIn::QtScriptCCEaseSineIn(QScriptEngine *engine)
	: QtScriptCCEaseSineIn(engine, "EaseSineIn")
{
}

void QtScriptCCEaseSineIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseSineIn, QtScriptCCEaseSineIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseSineIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseSineIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseSineIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseSineIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseSineIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseSineIn constructor");
	return false;
}

QScriptValue QtScriptCCEaseSineIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseSineIn::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseSineIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseSineOut::QtScriptCCEaseSineOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseSineOut::QtScriptCCEaseSineOut(QScriptEngine *engine)
	: QtScriptCCEaseSineOut(engine, "EaseSineOut")
{
}

void QtScriptCCEaseSineOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseSineOut, QtScriptCCEaseSineOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseSineOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseSineOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseSineOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseSineOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseSineOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseSineOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseSineOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseSineOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseSineOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseSineInOut::QtScriptCCEaseSineInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseSineInOut::QtScriptCCEaseSineInOut(QScriptEngine *engine)
	: QtScriptCCEaseSineInOut(engine, "EaseSineInOut")
{
}

void QtScriptCCEaseSineInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseSineInOut, QtScriptCCEaseSineInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseSineInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseSineInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseSineInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseSineInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseSineInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseSineInOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseSineInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseSineInOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseSineInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseElastic::QtScriptCCEaseElastic(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseElastic::QtScriptCCEaseElastic(QScriptEngine *engine)
	: QtScriptCCEaseElastic(engine, "EaseElastic")
{
}

void QtScriptCCEaseElastic::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseElastic, QtScriptCCEaseElastic>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseElastic::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseElastic::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseElastic::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseElastic::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseElastic;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseElastic constructor");
	return false;
}

void QtScriptCCEaseElastic::setPeriod(float fPeriod)
{
	auto __o = this->thiz<CCEaseElastic *>();
	if (__o)
	{
		__o->setPeriod(fPeriod);
	}
}

bool QtScriptCCEaseElastic::initWithAction(cocos2d::CCActionInterval* pAction)
{
	auto __o = this->thiz<CCEaseElastic *>();
	if (__o)
	{
		return __o->initWithAction(pAction);
	}
	return false;
}

bool QtScriptCCEaseElastic::initWithAction(cocos2d::CCActionInterval* pAction, float fPeriod)
{
	auto __o = this->thiz<CCEaseElastic *>();
	if (__o)
	{
		return __o->initWithAction(pAction, fPeriod);
	}
	return false;
}

float QtScriptCCEaseElastic::getPeriod()
{
	auto __o = this->thiz<CCEaseElastic *>();
	if (__o)
	{
		return __o->getPeriod();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCEaseElastic::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseElastic::create(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseElastic::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseElastic::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseElasticIn::QtScriptCCEaseElasticIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseElastic(engine, className)
{
}

QtScriptCCEaseElasticIn::QtScriptCCEaseElasticIn(QScriptEngine *engine)
	: QtScriptCCEaseElasticIn(engine, "EaseElasticIn")
{
}

void QtScriptCCEaseElasticIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseElastic *>());
	auto ctor = RegisterT<CCEaseElasticIn, QtScriptCCEaseElasticIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseElasticIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseElasticIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseElasticIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseElasticIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseElasticIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseElasticIn constructor");
	return false;
}

QScriptValue QtScriptCCEaseElasticIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseElasticIn::create(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseElasticIn::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseElasticIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseElasticOut::QtScriptCCEaseElasticOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseElastic(engine, className)
{
}

QtScriptCCEaseElasticOut::QtScriptCCEaseElasticOut(QScriptEngine *engine)
	: QtScriptCCEaseElasticOut(engine, "EaseElasticOut")
{
}

void QtScriptCCEaseElasticOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseElastic *>());
	auto ctor = RegisterT<CCEaseElasticOut, QtScriptCCEaseElasticOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseElasticOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseElasticOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseElasticOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseElasticOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseElasticOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseElasticOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseElasticOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseElasticOut::create(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseElasticOut::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseElasticOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseElasticInOut::QtScriptCCEaseElasticInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseElastic(engine, className)
{
}

QtScriptCCEaseElasticInOut::QtScriptCCEaseElasticInOut(QScriptEngine *engine)
	: QtScriptCCEaseElasticInOut(engine, "EaseElasticInOut")
{
}

void QtScriptCCEaseElasticInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseElastic *>());
	auto ctor = RegisterT<CCEaseElasticInOut, QtScriptCCEaseElasticInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseElasticInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseElasticInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseElasticInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseElasticInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseElasticInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseElasticInOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseElasticInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseElasticInOut::create(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCEaseElasticInOut::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseElasticInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBounce::QtScriptCCEaseBounce(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseBounce::QtScriptCCEaseBounce(QScriptEngine *engine)
	: QtScriptCCEaseBounce(engine, "EaseBounce")
{
}

void QtScriptCCEaseBounce::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseBounce, QtScriptCCEaseBounce>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBounce::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBounce::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBounce::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBounce::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBounce;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBounce constructor");
	return false;
}

float QtScriptCCEaseBounce::bounceTime(float time)
{
	auto __o = this->thiz<CCEaseBounce *>();
	if (__o)
	{
		return __o->bounceTime(time);
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCEaseBounce::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBounce::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBounce::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBounceIn::QtScriptCCEaseBounceIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseBounce(engine, className)
{
}

QtScriptCCEaseBounceIn::QtScriptCCEaseBounceIn(QScriptEngine *engine)
	: QtScriptCCEaseBounceIn(engine, "EaseBounceIn")
{
}

void QtScriptCCEaseBounceIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseBounce *>());
	auto ctor = RegisterT<CCEaseBounceIn, QtScriptCCEaseBounceIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBounceIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBounceIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBounceIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBounceIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBounceIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBounceIn constructor");
	return false;
}

QScriptValue QtScriptCCEaseBounceIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBounceIn::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBounceIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBounceOut::QtScriptCCEaseBounceOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseBounce(engine, className)
{
}

QtScriptCCEaseBounceOut::QtScriptCCEaseBounceOut(QScriptEngine *engine)
	: QtScriptCCEaseBounceOut(engine, "EaseBounceOut")
{
}

void QtScriptCCEaseBounceOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseBounce *>());
	auto ctor = RegisterT<CCEaseBounceOut, QtScriptCCEaseBounceOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBounceOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBounceOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBounceOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBounceOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBounceOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBounceOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseBounceOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBounceOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBounceOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBounceInOut::QtScriptCCEaseBounceInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEaseBounce(engine, className)
{
}

QtScriptCCEaseBounceInOut::QtScriptCCEaseBounceInOut(QScriptEngine *engine)
	: QtScriptCCEaseBounceInOut(engine, "EaseBounceInOut")
{
}

void QtScriptCCEaseBounceInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEaseBounce *>());
	auto ctor = RegisterT<CCEaseBounceInOut, QtScriptCCEaseBounceInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBounceInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBounceInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBounceInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBounceInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBounceInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBounceInOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseBounceInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBounceInOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBounceInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBackIn::QtScriptCCEaseBackIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseBackIn::QtScriptCCEaseBackIn(QScriptEngine *engine)
	: QtScriptCCEaseBackIn(engine, "EaseBackIn")
{
}

void QtScriptCCEaseBackIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseBackIn, QtScriptCCEaseBackIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBackIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBackIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBackIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBackIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBackIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBackIn constructor");
	return false;
}

QScriptValue QtScriptCCEaseBackIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBackIn::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBackIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBackOut::QtScriptCCEaseBackOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseBackOut::QtScriptCCEaseBackOut(QScriptEngine *engine)
	: QtScriptCCEaseBackOut(engine, "EaseBackOut")
{
}

void QtScriptCCEaseBackOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseBackOut, QtScriptCCEaseBackOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBackOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBackOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBackOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBackOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBackOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBackOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseBackOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBackOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBackOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEaseBackInOut::QtScriptCCEaseBackInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionEase(engine, className)
{
}

QtScriptCCEaseBackInOut::QtScriptCCEaseBackInOut(QScriptEngine *engine)
	: QtScriptCCEaseBackInOut(engine, "EaseBackInOut")
{
}

void QtScriptCCEaseBackInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionEase *>());
	auto ctor = RegisterT<CCEaseBackInOut, QtScriptCCEaseBackInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEaseBackInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEaseBackInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEaseBackInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEaseBackInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCEaseBackInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCEaseBackInOut constructor");
	return false;
}

QScriptValue QtScriptCCEaseBackInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCActionInterval*>(context->argument(0));
			return __e->toScriptValue(CCEaseBackInOut::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEaseBackInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptTypeInfo::QtScriptTypeInfo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<TypeInfo *, false>(engine, className)
{
}

QtScriptTypeInfo::QtScriptTypeInfo(QScriptEngine *engine)
	: QtScriptTypeInfo(engine, "TypeInfo")
{
}

void QtScriptTypeInfo::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<TypeInfo, QtScriptTypeInfo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptTypeInfo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptTypeInfo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptTypeInfo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::TypeInfo");
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionInstant::QtScriptCCActionInstant(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCFiniteTimeAction(engine, className)
{
}

QtScriptCCActionInstant::QtScriptCCActionInstant(QScriptEngine *engine)
	: QtScriptCCActionInstant(engine, "ActionInstant")
{
}

void QtScriptCCActionInstant::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCFiniteTimeAction *>());
	auto ctor = RegisterT<CCActionInstant, QtScriptCCActionInstant>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCActionInstant::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionInstant::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionInstant::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCActionInstant();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCActionInstant constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCShow::QtScriptCCShow(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCShow::QtScriptCCShow(QScriptEngine *engine)
	: QtScriptCCShow(engine, "Show")
{
}

void QtScriptCCShow::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCShow, QtScriptCCShow>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShow::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCShow::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCShow::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShow::create");
	return __e->uncaughtException();
}

int QtScriptCCShow::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCShow::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCShow::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCShow();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShow constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCHide::QtScriptCCHide(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCHide::QtScriptCCHide(QScriptEngine *engine)
	: QtScriptCCHide(engine, "Hide")
{
}

void QtScriptCCHide::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCHide, QtScriptCCHide>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCHide::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCHide::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCHide::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCHide::create");
	return __e->uncaughtException();
}

int QtScriptCCHide::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCHide::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCHide::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCHide();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCHide constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCToggleVisibility::QtScriptCCToggleVisibility(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCToggleVisibility::QtScriptCCToggleVisibility(QScriptEngine *engine)
	: QtScriptCCToggleVisibility(engine, "ToggleVisibility")
{
}

void QtScriptCCToggleVisibility::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCToggleVisibility, QtScriptCCToggleVisibility>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCToggleVisibility::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCToggleVisibility::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCToggleVisibility::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCToggleVisibility::create");
	return __e->uncaughtException();
}

int QtScriptCCToggleVisibility::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCToggleVisibility::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCToggleVisibility::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCToggleVisibility();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCToggleVisibility constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRemoveSelf::QtScriptCCRemoveSelf(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCRemoveSelf::QtScriptCCRemoveSelf(QScriptEngine *engine)
	: QtScriptCCRemoveSelf(engine, "RemoveSelf")
{
}

void QtScriptCCRemoveSelf::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCRemoveSelf, QtScriptCCRemoveSelf>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRemoveSelf::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCRemoveSelf::init(bool isNeedCleanUp)
{
	auto __o = this->thiz<CCRemoveSelf *>();
	if (__o)
	{
		return __o->init(isNeedCleanUp);
	}
	return false;
}

QScriptValue QtScriptCCRemoveSelf::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCRemoveSelf::create());
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<bool>(context->argument(0));
			return __e->toScriptValue(CCRemoveSelf::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRemoveSelf::create");
	return __e->uncaughtException();
}

int QtScriptCCRemoveSelf::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRemoveSelf::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRemoveSelf::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCRemoveSelf();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRemoveSelf constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFlipX::QtScriptCCFlipX(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCFlipX::QtScriptCCFlipX(QScriptEngine *engine)
	: QtScriptCCFlipX(engine, "FlipX")
{
}

void QtScriptCCFlipX::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCFlipX, QtScriptCCFlipX>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFlipX::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCFlipX::initWithFlipX(bool x)
{
	auto __o = this->thiz<CCFlipX *>();
	if (__o)
	{
		return __o->initWithFlipX(x);
	}
	return false;
}

QScriptValue QtScriptCCFlipX::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<bool>(context->argument(0));
			return __e->toScriptValue(CCFlipX::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFlipX::create");
	return __e->uncaughtException();
}

int QtScriptCCFlipX::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFlipX::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFlipX::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCFlipX();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFlipX constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFlipY::QtScriptCCFlipY(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCFlipY::QtScriptCCFlipY(QScriptEngine *engine)
	: QtScriptCCFlipY(engine, "FlipY")
{
}

void QtScriptCCFlipY::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCFlipY, QtScriptCCFlipY>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFlipY::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCFlipY::initWithFlipY(bool y)
{
	auto __o = this->thiz<CCFlipY *>();
	if (__o)
	{
		return __o->initWithFlipY(y);
	}
	return false;
}

QScriptValue QtScriptCCFlipY::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<bool>(context->argument(0));
			return __e->toScriptValue(CCFlipY::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFlipY::create");
	return __e->uncaughtException();
}

int QtScriptCCFlipY::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFlipY::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFlipY::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCFlipY();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFlipY constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCPlace::QtScriptCCPlace(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCPlace::QtScriptCCPlace(QScriptEngine *engine)
	: QtScriptCCPlace(engine, "Place")
{
}

void QtScriptCCPlace::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCPlace, QtScriptCCPlace>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCPlace::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCPlace::initWithPosition(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCPlace *>();
	if (__o)
	{
		return __o->initWithPosition(pos);
	}
	return false;
}

QScriptValue QtScriptCCPlace::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(0));
			return __e->toScriptValue(CCPlace::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPlace::create");
	return __e->uncaughtException();
}

int QtScriptCCPlace::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCPlace::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCPlace::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCPlace();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPlace constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCallFunc::QtScriptCCCallFunc(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCCallFunc::QtScriptCCCallFunc(QScriptEngine *engine)
	: QtScriptCCCallFunc(engine, "CallFunc")
{
}

void QtScriptCCCallFunc::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCCallFunc, QtScriptCCCallFunc>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCallFunc::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCCallFunc::execute()
{
	auto __o = this->thiz<CCCallFunc *>();
	if (__o)
	{
		__o->execute();
	}
}

bool QtScriptCCCallFunc::initWithTarget(cocos2d::CCObject* pSelectorTarget)
{
	auto __o = this->thiz<CCCallFunc *>();
	if (__o)
	{
		return __o->initWithTarget(pSelectorTarget);
	}
	return false;
}

cocos2d::CCObject* QtScriptCCCallFunc::getTargetCallback()
{
	auto __o = this->thiz<CCCallFunc *>();
	if (__o)
	{
		return __o->getTargetCallback();
	}
	return nullptr;
}

void QtScriptCCCallFunc::setHandler(const QScriptValue& arg0)
{
	auto __o = this->thiz<CCCallFunc *>();
	if (__o)
	{
		__o->setScriptHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0));
	}
}

void QtScriptCCCallFunc::setTargetCallback(cocos2d::CCObject* pSel)
{
	auto __o = this->thiz<CCCallFunc *>();
	if (__o)
	{
		__o->setTargetCallback(pSel);
	}
}

QScriptValue QtScriptCCCallFunc::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = context->argument(0);
			return __e->toScriptValue(CCCallFunc::create(QtCocosScriptEngine::instance()->retainJSObject(arg0)));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCallFunc::create");
	return __e->uncaughtException();
}

int QtScriptCCCallFunc::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCallFunc::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCallFunc::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCallFunc();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCallFunc constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCallFuncN::QtScriptCCCallFuncN(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCCallFunc(engine, className)
{
}

QtScriptCCCallFuncN::QtScriptCCCallFuncN(QScriptEngine *engine)
	: QtScriptCCCallFuncN(engine, "CallFuncN")
{
}

void QtScriptCCCallFuncN::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCCallFunc *>());
	auto ctor = RegisterT<CCCallFuncN, QtScriptCCCallFuncN>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCallFuncN::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

long QtScriptCCCallFuncN::getClassTypeInfo()
{
	auto __o = this->thiz<CCCallFuncN *>();
	if (__o)
	{
		return __o->getClassTypeInfo();
	}
	return static_cast<long>(0);
}

QScriptValue QtScriptCCCallFuncN::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = context->argument(0);
			return __e->toScriptValue(CCCallFuncN::create(QtCocosScriptEngine::instance()->retainJSObject(arg0)));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCallFuncN::create");
	return __e->uncaughtException();
}

int QtScriptCCCallFuncN::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCallFuncN::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCallFuncN::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCallFuncN();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCallFuncN constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCallFuncND::QtScriptCCCallFuncND(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCCallFuncN(engine, className)
{
}

QtScriptCCCallFuncND::QtScriptCCCallFuncND(QScriptEngine *engine)
	: QtScriptCCCallFuncND(engine, "CallFuncND")
{
}

void QtScriptCCCallFuncND::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCCallFuncN *>());
	auto ctor = RegisterT<CCCallFuncND, QtScriptCCCallFuncND>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCCallFuncND::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCallFuncND::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCallFuncND::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCCallFuncND;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCCallFuncND constructor");
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCallFuncO::QtScriptCCCallFuncO(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCCallFunc(engine, className)
{
}

QtScriptCCCallFuncO::QtScriptCCCallFuncO(QScriptEngine *engine)
	: QtScriptCCCallFuncO(engine, "CallFuncO")
{
}

void QtScriptCCCallFuncO::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCCallFunc *>());
	auto ctor = RegisterT<CCCallFuncO, QtScriptCCCallFuncO>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

long QtScriptCCCallFuncO::getClassTypeInfo()
{
	auto __o = this->thiz<CCCallFuncO *>();
	if (__o)
	{
		return __o->getClassTypeInfo();
	}
	return static_cast<long>(0);
}

cocos2d::CCObject* QtScriptCCCallFuncO::getObject()
{
	auto __o = this->thiz<CCCallFuncO *>();
	if (__o)
	{
		return __o->getObject();
	}
	return nullptr;
}

void QtScriptCCCallFuncO::setObject(cocos2d::CCObject* pObj)
{
	auto __o = this->thiz<CCCallFuncO *>();
	if (__o)
	{
		__o->setObject(pObj);
	}
}

int QtScriptCCCallFuncO::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCallFuncO::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCallFuncO::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCallFuncO();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCallFuncO constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCGridAction::QtScriptCCGridAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCGridAction::QtScriptCCGridAction(QScriptEngine *engine)
	: QtScriptCCGridAction(engine, "GridAction")
{
}

void QtScriptCCGridAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCGridAction, QtScriptCCGridAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCGridAction::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCGridAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCGridAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCGridAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCGridAction;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCGridAction constructor");
	return false;
}

cocos2d::CCGridBase* QtScriptCCGridAction::getGrid()
{
	auto __o = this->thiz<CCGridAction *>();
	if (__o)
	{
		return __o->getGrid();
	}
	return nullptr;
}

bool QtScriptCCGridAction::initWithDuration(float duration, const cocos2d::CCSize& gridSize)
{
	auto __o = this->thiz<CCGridAction *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize);
	}
	return false;
}

QScriptValue QtScriptCCGridAction::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCGridAction::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGridAction::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCGrid3DAction::QtScriptCCGrid3DAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGridAction(engine, className)
{
}

QtScriptCCGrid3DAction::QtScriptCCGrid3DAction(QScriptEngine *engine)
	: QtScriptCCGrid3DAction(engine, "Grid3DAction")
{
}

void QtScriptCCGrid3DAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGridAction *>());
	auto ctor = RegisterT<CCGrid3DAction, QtScriptCCGrid3DAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCGrid3DAction::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCGrid3DAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCGrid3DAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCGrid3DAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCGrid3DAction;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCGrid3DAction constructor");
	return false;
}

void QtScriptCCGrid3DAction::setVertex(const cocos2d::CCPoint& position, const cocos2d::_ccVertex3F& vertex)
{
	auto __o = this->thiz<CCGrid3DAction *>();
	if (__o)
	{
		__o->setVertex(position, vertex);
	}
}

cocos2d::_ccVertex3F QtScriptCCGrid3DAction::vertex(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCGrid3DAction *>();
	if (__o)
	{
		return __o->vertex(position);
	}
	return cocos2d::_ccVertex3F();
}

cocos2d::_ccVertex3F QtScriptCCGrid3DAction::originalVertex(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCGrid3DAction *>();
	if (__o)
	{
		return __o->originalVertex(position);
	}
	return cocos2d::_ccVertex3F();
}

QScriptValue QtScriptCCGrid3DAction::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCGrid3DAction::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGrid3DAction::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTiledGrid3DAction::QtScriptCCTiledGrid3DAction(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGridAction(engine, className)
{
}

QtScriptCCTiledGrid3DAction::QtScriptCCTiledGrid3DAction(QScriptEngine *engine)
	: QtScriptCCTiledGrid3DAction(engine, "TiledGrid3DAction")
{
}

void QtScriptCCTiledGrid3DAction::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGridAction *>());
	auto ctor = RegisterT<CCTiledGrid3DAction, QtScriptCCTiledGrid3DAction>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTiledGrid3DAction::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTiledGrid3DAction::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTiledGrid3DAction::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTiledGrid3DAction::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTiledGrid3DAction;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTiledGrid3DAction constructor");
	return false;
}

cocos2d::_ccQuad3 QtScriptCCTiledGrid3DAction::tile(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCTiledGrid3DAction *>();
	if (__o)
	{
		return __o->tile(position);
	}
	return cocos2d::_ccQuad3();
}

void QtScriptCCTiledGrid3DAction::setTile(const cocos2d::CCPoint& position, const cocos2d::_ccQuad3& coords)
{
	auto __o = this->thiz<CCTiledGrid3DAction *>();
	if (__o)
	{
		__o->setTile(position, coords);
	}
}

cocos2d::_ccQuad3 QtScriptCCTiledGrid3DAction::originalTile(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCTiledGrid3DAction *>();
	if (__o)
	{
		return __o->originalTile(position);
	}
	return cocos2d::_ccQuad3();
}

QScriptValue QtScriptCCTiledGrid3DAction::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCTiledGrid3DAction::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTiledGrid3DAction::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAccelDeccelAmplitude::QtScriptCCAccelDeccelAmplitude(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCAccelDeccelAmplitude::QtScriptCCAccelDeccelAmplitude(QScriptEngine *engine)
	: QtScriptCCAccelDeccelAmplitude(engine, "AccelDeccelAmplitude")
{
}

void QtScriptCCAccelDeccelAmplitude::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCAccelDeccelAmplitude, QtScriptCCAccelDeccelAmplitude>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAccelDeccelAmplitude::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCAccelDeccelAmplitude::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAccelDeccelAmplitude::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAccelDeccelAmplitude::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCAccelDeccelAmplitude;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCAccelDeccelAmplitude constructor");
	return false;
}

void QtScriptCCAccelDeccelAmplitude::setRate(float fRate)
{
	auto __o = this->thiz<CCAccelDeccelAmplitude *>();
	if (__o)
	{
		__o->setRate(fRate);
	}
}

bool QtScriptCCAccelDeccelAmplitude::initWithAction(cocos2d::CCAction* pAction, float duration)
{
	auto __o = this->thiz<CCAccelDeccelAmplitude *>();
	if (__o)
	{
		return __o->initWithAction(pAction, duration);
	}
	return false;
}

float QtScriptCCAccelDeccelAmplitude::getRate()
{
	auto __o = this->thiz<CCAccelDeccelAmplitude *>();
	if (__o)
	{
		return __o->getRate();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCAccelDeccelAmplitude::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCAction*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCAccelDeccelAmplitude::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAccelDeccelAmplitude::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAccelAmplitude::QtScriptCCAccelAmplitude(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCAccelAmplitude::QtScriptCCAccelAmplitude(QScriptEngine *engine)
	: QtScriptCCAccelAmplitude(engine, "AccelAmplitude")
{
}

void QtScriptCCAccelAmplitude::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCAccelAmplitude, QtScriptCCAccelAmplitude>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAccelAmplitude::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCAccelAmplitude::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAccelAmplitude::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAccelAmplitude::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCAccelAmplitude;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCAccelAmplitude constructor");
	return false;
}

void QtScriptCCAccelAmplitude::setRate(float fRate)
{
	auto __o = this->thiz<CCAccelAmplitude *>();
	if (__o)
	{
		__o->setRate(fRate);
	}
}

bool QtScriptCCAccelAmplitude::initWithAction(cocos2d::CCAction* pAction, float duration)
{
	auto __o = this->thiz<CCAccelAmplitude *>();
	if (__o)
	{
		return __o->initWithAction(pAction, duration);
	}
	return false;
}

float QtScriptCCAccelAmplitude::getRate()
{
	auto __o = this->thiz<CCAccelAmplitude *>();
	if (__o)
	{
		return __o->getRate();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCAccelAmplitude::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCAction*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCAccelAmplitude::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAccelAmplitude::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDeccelAmplitude::QtScriptCCDeccelAmplitude(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCDeccelAmplitude::QtScriptCCDeccelAmplitude(QScriptEngine *engine)
	: QtScriptCCDeccelAmplitude(engine, "DeccelAmplitude")
{
}

void QtScriptCCDeccelAmplitude::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCDeccelAmplitude, QtScriptCCDeccelAmplitude>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDeccelAmplitude::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCDeccelAmplitude::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDeccelAmplitude::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDeccelAmplitude::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCDeccelAmplitude;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCDeccelAmplitude constructor");
	return false;
}

void QtScriptCCDeccelAmplitude::setRate(float fRate)
{
	auto __o = this->thiz<CCDeccelAmplitude *>();
	if (__o)
	{
		__o->setRate(fRate);
	}
}

bool QtScriptCCDeccelAmplitude::initWithAction(cocos2d::CCAction* pAction, float duration)
{
	auto __o = this->thiz<CCDeccelAmplitude *>();
	if (__o)
	{
		return __o->initWithAction(pAction, duration);
	}
	return false;
}

float QtScriptCCDeccelAmplitude::getRate()
{
	auto __o = this->thiz<CCDeccelAmplitude *>();
	if (__o)
	{
		return __o->getRate();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCDeccelAmplitude::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCAction*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCDeccelAmplitude::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDeccelAmplitude::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCStopGrid::QtScriptCCStopGrid(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCStopGrid::QtScriptCCStopGrid(QScriptEngine *engine)
	: QtScriptCCStopGrid(engine, "StopGrid")
{
}

void QtScriptCCStopGrid::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCStopGrid, QtScriptCCStopGrid>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCStopGrid::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCStopGrid::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCStopGrid::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCStopGrid::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCStopGrid;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCStopGrid constructor");
	return false;
}

QScriptValue QtScriptCCStopGrid::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCStopGrid::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCStopGrid::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCReuseGrid::QtScriptCCReuseGrid(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInstant(engine, className)
{
}

QtScriptCCReuseGrid::QtScriptCCReuseGrid(QScriptEngine *engine)
	: QtScriptCCReuseGrid(engine, "ReuseGrid")
{
}

void QtScriptCCReuseGrid::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInstant *>());
	auto ctor = RegisterT<CCReuseGrid, QtScriptCCReuseGrid>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCReuseGrid::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCReuseGrid::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCReuseGrid::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCReuseGrid::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCReuseGrid;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCReuseGrid constructor");
	return false;
}

bool QtScriptCCReuseGrid::initWithTimes(int times)
{
	auto __o = this->thiz<CCReuseGrid *>();
	if (__o)
	{
		return __o->initWithTimes(times);
	}
	return false;
}

QScriptValue QtScriptCCReuseGrid::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<int>(context->argument(0));
			return __e->toScriptValue(CCReuseGrid::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCReuseGrid::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCWaves3D::QtScriptCCWaves3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCWaves3D::QtScriptCCWaves3D(QScriptEngine *engine)
	: QtScriptCCWaves3D(engine, "Waves3D")
{
}

void QtScriptCCWaves3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCWaves3D, QtScriptCCWaves3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCWaves3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCWaves3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCWaves3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCWaves3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCWaves3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCWaves3D constructor");
	return false;
}

float QtScriptCCWaves3D::getAmplitudeRate()
{
	auto __o = this->thiz<CCWaves3D *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCWaves3D::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCWaves3D *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

void QtScriptCCWaves3D::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCWaves3D *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCWaves3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude)
{
	auto __o = this->thiz<CCWaves3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, waves, amplitude);
	}
	return false;
}

float QtScriptCCWaves3D::getAmplitude()
{
	auto __o = this->thiz<CCWaves3D *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCWaves3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			return __e->toScriptValue(CCWaves3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCWaves3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFlipX3D::QtScriptCCFlipX3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCFlipX3D::QtScriptCCFlipX3D(QScriptEngine *engine)
	: QtScriptCCFlipX3D(engine, "FlipX3D")
{
}

void QtScriptCCFlipX3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCFlipX3D, QtScriptCCFlipX3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFlipX3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFlipX3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFlipX3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFlipX3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFlipX3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFlipX3D constructor");
	return false;
}

bool QtScriptCCFlipX3D::initWithSize(const cocos2d::CCSize& gridSize, float duration)
{
	auto __o = this->thiz<CCFlipX3D *>();
	if (__o)
	{
		return __o->initWithSize(gridSize, duration);
	}
	return false;
}

bool QtScriptCCFlipX3D::initWithDuration(float duration)
{
	auto __o = this->thiz<CCFlipX3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration);
	}
	return false;
}

QScriptValue QtScriptCCFlipX3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCFlipX3D::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFlipX3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFlipY3D::QtScriptCCFlipY3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCFlipX3D(engine, className)
{
}

QtScriptCCFlipY3D::QtScriptCCFlipY3D(QScriptEngine *engine)
	: QtScriptCCFlipY3D(engine, "FlipY3D")
{
}

void QtScriptCCFlipY3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCFlipX3D *>());
	auto ctor = RegisterT<CCFlipY3D, QtScriptCCFlipY3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFlipY3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFlipY3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFlipY3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFlipY3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFlipY3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFlipY3D constructor");
	return false;
}

QScriptValue QtScriptCCFlipY3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCFlipY3D::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFlipY3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLens3D::QtScriptCCLens3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCLens3D::QtScriptCCLens3D(QScriptEngine *engine)
	: QtScriptCCLens3D(engine, "Lens3D")
{
}

void QtScriptCCLens3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCLens3D, QtScriptCCLens3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLens3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCLens3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLens3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLens3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCLens3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCLens3D constructor");
	return false;
}

void QtScriptCCLens3D::setConcave(bool bConcave)
{
	auto __o = this->thiz<CCLens3D *>();
	if (__o)
	{
		__o->setConcave(bConcave);
	}
}

bool QtScriptCCLens3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, const cocos2d::CCPoint& position, float radius)
{
	auto __o = this->thiz<CCLens3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, position, radius);
	}
	return false;
}

void QtScriptCCLens3D::setLensEffect(float fLensEffect)
{
	auto __o = this->thiz<CCLens3D *>();
	if (__o)
	{
		__o->setLensEffect(fLensEffect);
	}
}

float QtScriptCCLens3D::getLensEffect()
{
	auto __o = this->thiz<CCLens3D *>();
	if (__o)
	{
		return __o->getLensEffect();
	}
	return static_cast<float>(0);
}

void QtScriptCCLens3D::setPosition(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCLens3D *>();
	if (__o)
	{
		__o->setPosition(position);
	}
}

cocos2d::CCPoint QtScriptCCLens3D::getPosition()
{
	auto __o = this->thiz<CCLens3D *>();
	if (__o)
	{
		return __o->getPosition();
	}
	return cocos2d::CCPoint();
}

QScriptValue QtScriptCCLens3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			return __e->toScriptValue(CCLens3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLens3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRipple3D::QtScriptCCRipple3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCRipple3D::QtScriptCCRipple3D(QScriptEngine *engine)
	: QtScriptCCRipple3D(engine, "Ripple3D")
{
}

void QtScriptCCRipple3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCRipple3D, QtScriptCCRipple3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRipple3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCRipple3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRipple3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRipple3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCRipple3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCRipple3D constructor");
	return false;
}

void QtScriptCCRipple3D::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCRipple3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, const cocos2d::CCPoint& position, float radius, unsigned int waves, float amplitude)
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, position, radius, waves, amplitude);
	}
	return false;
}

float QtScriptCCRipple3D::getAmplitudeRate()
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCRipple3D::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

float QtScriptCCRipple3D::getAmplitude()
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

void QtScriptCCRipple3D::setPosition(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		__o->setPosition(position);
	}
}

cocos2d::CCPoint QtScriptCCRipple3D::getPosition()
{
	auto __o = this->thiz<CCRipple3D *>();
	if (__o)
	{
		return __o->getPosition();
	}
	return cocos2d::CCPoint();
}

QScriptValue QtScriptCCRipple3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 6, 6))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 6:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			auto arg4 = qscriptvalue_cast<unsigned int>(context->argument(4));
			auto arg5 = qscriptvalue_cast<float>(context->argument(5));
			return __e->toScriptValue(CCRipple3D::create(arg0, arg1, arg2, arg3, arg4, arg5));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRipple3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCShaky3D::QtScriptCCShaky3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCShaky3D::QtScriptCCShaky3D(QScriptEngine *engine)
	: QtScriptCCShaky3D(engine, "Shaky3D")
{
}

void QtScriptCCShaky3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCShaky3D, QtScriptCCShaky3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShaky3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCShaky3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCShaky3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCShaky3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCShaky3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCShaky3D constructor");
	return false;
}

bool QtScriptCCShaky3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, int range, bool shakeZ)
{
	auto __o = this->thiz<CCShaky3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, range, shakeZ);
	}
	return false;
}

QScriptValue QtScriptCCShaky3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<bool>(context->argument(3));
			return __e->toScriptValue(CCShaky3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShaky3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLiquid::QtScriptCCLiquid(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCLiquid::QtScriptCCLiquid(QScriptEngine *engine)
	: QtScriptCCLiquid(engine, "Liquid")
{
}

void QtScriptCCLiquid::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCLiquid, QtScriptCCLiquid>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLiquid::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCLiquid::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLiquid::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLiquid::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCLiquid;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCLiquid constructor");
	return false;
}

float QtScriptCCLiquid::getAmplitudeRate()
{
	auto __o = this->thiz<CCLiquid *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCLiquid::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCLiquid *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

void QtScriptCCLiquid::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCLiquid *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCLiquid::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude)
{
	auto __o = this->thiz<CCLiquid *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, waves, amplitude);
	}
	return false;
}

float QtScriptCCLiquid::getAmplitude()
{
	auto __o = this->thiz<CCLiquid *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCLiquid::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			return __e->toScriptValue(CCLiquid::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLiquid::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCWaves::QtScriptCCWaves(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCWaves::QtScriptCCWaves(QScriptEngine *engine)
	: QtScriptCCWaves(engine, "Waves")
{
}

void QtScriptCCWaves::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCWaves, QtScriptCCWaves>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCWaves::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCWaves::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCWaves::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCWaves::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCWaves;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCWaves constructor");
	return false;
}

float QtScriptCCWaves::getAmplitudeRate()
{
	auto __o = this->thiz<CCWaves *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCWaves::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCWaves *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

void QtScriptCCWaves::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCWaves *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCWaves::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical)
{
	auto __o = this->thiz<CCWaves *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, waves, amplitude, horizontal, vertical);
	}
	return false;
}

float QtScriptCCWaves::getAmplitude()
{
	auto __o = this->thiz<CCWaves *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCWaves::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 6, 6))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 6:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			auto arg4 = qscriptvalue_cast<bool>(context->argument(4));
			auto arg5 = qscriptvalue_cast<bool>(context->argument(5));
			return __e->toScriptValue(CCWaves::create(arg0, arg1, arg2, arg3, arg4, arg5));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCWaves::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTwirl::QtScriptCCTwirl(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCTwirl::QtScriptCCTwirl(QScriptEngine *engine)
	: QtScriptCCTwirl(engine, "Twirl")
{
}

void QtScriptCCTwirl::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCTwirl, QtScriptCCTwirl>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTwirl::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTwirl::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTwirl::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTwirl::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTwirl;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTwirl constructor");
	return false;
}

void QtScriptCCTwirl::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCTwirl::initWithDuration(float duration, const cocos2d::CCSize& gridSize, cocos2d::CCPoint position, unsigned int twirls, float amplitude)
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, position, twirls, amplitude);
	}
	return false;
}

float QtScriptCCTwirl::getAmplitudeRate()
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCTwirl::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

float QtScriptCCTwirl::getAmplitude()
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

void QtScriptCCTwirl::setPosition(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		__o->setPosition(position);
	}
}

cocos2d::CCPoint QtScriptCCTwirl::getPosition()
{
	auto __o = this->thiz<CCTwirl *>();
	if (__o)
	{
		return __o->getPosition();
	}
	return cocos2d::CCPoint();
}

QScriptValue QtScriptCCTwirl::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 5, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 5:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(2));
			auto arg3 = qscriptvalue_cast<unsigned int>(context->argument(3));
			auto arg4 = qscriptvalue_cast<float>(context->argument(4));
			return __e->toScriptValue(CCTwirl::create(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTwirl::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCPageTurn3D::QtScriptCCPageTurn3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGrid3DAction(engine, className)
{
}

QtScriptCCPageTurn3D::QtScriptCCPageTurn3D(QScriptEngine *engine)
	: QtScriptCCPageTurn3D(engine, "PageTurn3D")
{
}

void QtScriptCCPageTurn3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGrid3DAction *>());
	auto ctor = RegisterT<CCPageTurn3D, QtScriptCCPageTurn3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCPageTurn3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCPageTurn3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCPageTurn3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCPageTurn3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCPageTurn3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCPageTurn3D constructor");
	return false;
}

QScriptValue QtScriptCCPageTurn3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCPageTurn3D::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPageTurn3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCProgressTo::QtScriptCCProgressTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCProgressTo::QtScriptCCProgressTo(QScriptEngine *engine)
	: QtScriptCCProgressTo(engine, "ProgressTo")
{
}

void QtScriptCCProgressTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCProgressTo, QtScriptCCProgressTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCProgressTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCProgressTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCProgressTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCProgressTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCProgressTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCProgressTo constructor");
	return false;
}

bool QtScriptCCProgressTo::initWithDuration(float duration, float fPercent)
{
	auto __o = this->thiz<CCProgressTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, fPercent);
	}
	return false;
}

QScriptValue QtScriptCCProgressTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCProgressTo::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCProgressTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCProgressFromTo::QtScriptCCProgressFromTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCProgressFromTo::QtScriptCCProgressFromTo(QScriptEngine *engine)
	: QtScriptCCProgressFromTo(engine, "ProgressFromTo")
{
}

void QtScriptCCProgressFromTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCProgressFromTo, QtScriptCCProgressFromTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCProgressFromTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCProgressFromTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCProgressFromTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCProgressFromTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCProgressFromTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCProgressFromTo constructor");
	return false;
}

bool QtScriptCCProgressFromTo::initWithDuration(float duration, float fFromPercentage, float fToPercentage)
{
	auto __o = this->thiz<CCProgressFromTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, fFromPercentage, fToPercentage);
	}
	return false;
}

QScriptValue QtScriptCCProgressFromTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCProgressFromTo::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCProgressFromTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCShakyTiles3D::QtScriptCCShakyTiles3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCShakyTiles3D::QtScriptCCShakyTiles3D(QScriptEngine *engine)
	: QtScriptCCShakyTiles3D(engine, "ShakyTiles3D")
{
}

void QtScriptCCShakyTiles3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCShakyTiles3D, QtScriptCCShakyTiles3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShakyTiles3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCShakyTiles3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCShakyTiles3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCShakyTiles3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCShakyTiles3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCShakyTiles3D constructor");
	return false;
}

bool QtScriptCCShakyTiles3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, int nRange, bool bShakeZ)
{
	auto __o = this->thiz<CCShakyTiles3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, nRange, bShakeZ);
	}
	return false;
}

QScriptValue QtScriptCCShakyTiles3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<bool>(context->argument(3));
			return __e->toScriptValue(CCShakyTiles3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShakyTiles3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCShatteredTiles3D::QtScriptCCShatteredTiles3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCShatteredTiles3D::QtScriptCCShatteredTiles3D(QScriptEngine *engine)
	: QtScriptCCShatteredTiles3D(engine, "ShatteredTiles3D")
{
}

void QtScriptCCShatteredTiles3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCShatteredTiles3D, QtScriptCCShatteredTiles3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShatteredTiles3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCShatteredTiles3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCShatteredTiles3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCShatteredTiles3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCShatteredTiles3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCShatteredTiles3D constructor");
	return false;
}

bool QtScriptCCShatteredTiles3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, int nRange, bool bShatterZ)
{
	auto __o = this->thiz<CCShatteredTiles3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, nRange, bShatterZ);
	}
	return false;
}

QScriptValue QtScriptCCShatteredTiles3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<bool>(context->argument(3));
			return __e->toScriptValue(CCShatteredTiles3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShatteredTiles3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCShuffleTiles::QtScriptCCShuffleTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCShuffleTiles::QtScriptCCShuffleTiles(QScriptEngine *engine)
	: QtScriptCCShuffleTiles(engine, "ShuffleTiles")
{
}

void QtScriptCCShuffleTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCShuffleTiles, QtScriptCCShuffleTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShuffleTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCShuffleTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCShuffleTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCShuffleTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCShuffleTiles;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCShuffleTiles constructor");
	return false;
}

void QtScriptCCShuffleTiles::placeTile(const cocos2d::CCPoint& pos, const cocos2d::Tile& t)
{
	auto __o = this->thiz<CCShuffleTiles *>();
	if (__o)
	{
		__o->placeTile(pos, t);
	}
}

cocos2d::CCSize QtScriptCCShuffleTiles::getDelta(const cocos2d::CCSize& pos)
{
	auto __o = this->thiz<CCShuffleTiles *>();
	if (__o)
	{
		return __o->getDelta(pos);
	}
	return cocos2d::CCSize();
}

bool QtScriptCCShuffleTiles::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int seed)
{
	auto __o = this->thiz<CCShuffleTiles *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, seed);
	}
	return false;
}

QScriptValue QtScriptCCShuffleTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			return __e->toScriptValue(CCShuffleTiles::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShuffleTiles::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeOutTRTiles::QtScriptCCFadeOutTRTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCFadeOutTRTiles::QtScriptCCFadeOutTRTiles(QScriptEngine *engine)
	: QtScriptCCFadeOutTRTiles(engine, "FadeOutTRTiles")
{
}

void QtScriptCCFadeOutTRTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCFadeOutTRTiles, QtScriptCCFadeOutTRTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeOutTRTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeOutTRTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeOutTRTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeOutTRTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeOutTRTiles;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeOutTRTiles constructor");
	return false;
}

void QtScriptCCFadeOutTRTiles::turnOnTile(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCFadeOutTRTiles *>();
	if (__o)
	{
		__o->turnOnTile(pos);
	}
}

void QtScriptCCFadeOutTRTiles::turnOffTile(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCFadeOutTRTiles *>();
	if (__o)
	{
		__o->turnOffTile(pos);
	}
}

void QtScriptCCFadeOutTRTiles::transformTile(const cocos2d::CCPoint& pos, float distance)
{
	auto __o = this->thiz<CCFadeOutTRTiles *>();
	if (__o)
	{
		__o->transformTile(pos, distance);
	}
}

float QtScriptCCFadeOutTRTiles::testFunc(const cocos2d::CCSize& pos, float time)
{
	auto __o = this->thiz<CCFadeOutTRTiles *>();
	if (__o)
	{
		return __o->testFunc(pos, time);
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCFadeOutTRTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCFadeOutTRTiles::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeOutTRTiles::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeOutBLTiles::QtScriptCCFadeOutBLTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCFadeOutTRTiles(engine, className)
{
}

QtScriptCCFadeOutBLTiles::QtScriptCCFadeOutBLTiles(QScriptEngine *engine)
	: QtScriptCCFadeOutBLTiles(engine, "FadeOutBLTiles")
{
}

void QtScriptCCFadeOutBLTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCFadeOutTRTiles *>());
	auto ctor = RegisterT<CCFadeOutBLTiles, QtScriptCCFadeOutBLTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeOutBLTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeOutBLTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeOutBLTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeOutBLTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeOutBLTiles;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeOutBLTiles constructor");
	return false;
}

QScriptValue QtScriptCCFadeOutBLTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCFadeOutBLTiles::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeOutBLTiles::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeOutUpTiles::QtScriptCCFadeOutUpTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCFadeOutTRTiles(engine, className)
{
}

QtScriptCCFadeOutUpTiles::QtScriptCCFadeOutUpTiles(QScriptEngine *engine)
	: QtScriptCCFadeOutUpTiles(engine, "FadeOutUpTiles")
{
}

void QtScriptCCFadeOutUpTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCFadeOutTRTiles *>());
	auto ctor = RegisterT<CCFadeOutUpTiles, QtScriptCCFadeOutUpTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeOutUpTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeOutUpTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeOutUpTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeOutUpTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeOutUpTiles;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeOutUpTiles constructor");
	return false;
}

QScriptValue QtScriptCCFadeOutUpTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCFadeOutUpTiles::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeOutUpTiles::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFadeOutDownTiles::QtScriptCCFadeOutDownTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCFadeOutUpTiles(engine, className)
{
}

QtScriptCCFadeOutDownTiles::QtScriptCCFadeOutDownTiles(QScriptEngine *engine)
	: QtScriptCCFadeOutDownTiles(engine, "FadeOutDownTiles")
{
}

void QtScriptCCFadeOutDownTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCFadeOutUpTiles *>());
	auto ctor = RegisterT<CCFadeOutDownTiles, QtScriptCCFadeOutDownTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFadeOutDownTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFadeOutDownTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFadeOutDownTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFadeOutDownTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCFadeOutDownTiles;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCFadeOutDownTiles constructor");
	return false;
}

QScriptValue QtScriptCCFadeOutDownTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCFadeOutDownTiles::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFadeOutDownTiles::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTurnOffTiles::QtScriptCCTurnOffTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCTurnOffTiles::QtScriptCCTurnOffTiles(QScriptEngine *engine)
	: QtScriptCCTurnOffTiles(engine, "TurnOffTiles")
{
}

void QtScriptCCTurnOffTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCTurnOffTiles, QtScriptCCTurnOffTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTurnOffTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTurnOffTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTurnOffTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTurnOffTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTurnOffTiles;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTurnOffTiles constructor");
	return false;
}

void QtScriptCCTurnOffTiles::turnOnTile(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCTurnOffTiles *>();
	if (__o)
	{
		__o->turnOnTile(pos);
	}
}

void QtScriptCCTurnOffTiles::turnOffTile(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCTurnOffTiles *>();
	if (__o)
	{
		__o->turnOffTile(pos);
	}
}

bool QtScriptCCTurnOffTiles::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int seed)
{
	auto __o = this->thiz<CCTurnOffTiles *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, seed);
	}
	return false;
}

QScriptValue QtScriptCCTurnOffTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			return __e->toScriptValue(CCTurnOffTiles::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			return __e->toScriptValue(CCTurnOffTiles::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTurnOffTiles::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCWavesTiles3D::QtScriptCCWavesTiles3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCWavesTiles3D::QtScriptCCWavesTiles3D(QScriptEngine *engine)
	: QtScriptCCWavesTiles3D(engine, "WavesTiles3D")
{
}

void QtScriptCCWavesTiles3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCWavesTiles3D, QtScriptCCWavesTiles3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCWavesTiles3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCWavesTiles3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCWavesTiles3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCWavesTiles3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCWavesTiles3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCWavesTiles3D constructor");
	return false;
}

float QtScriptCCWavesTiles3D::getAmplitudeRate()
{
	auto __o = this->thiz<CCWavesTiles3D *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCWavesTiles3D::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCWavesTiles3D *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

void QtScriptCCWavesTiles3D::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCWavesTiles3D *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCWavesTiles3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude)
{
	auto __o = this->thiz<CCWavesTiles3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, waves, amplitude);
	}
	return false;
}

float QtScriptCCWavesTiles3D::getAmplitude()
{
	auto __o = this->thiz<CCWavesTiles3D *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCWavesTiles3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			return __e->toScriptValue(CCWavesTiles3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCWavesTiles3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCJumpTiles3D::QtScriptCCJumpTiles3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCJumpTiles3D::QtScriptCCJumpTiles3D(QScriptEngine *engine)
	: QtScriptCCJumpTiles3D(engine, "JumpTiles3D")
{
}

void QtScriptCCJumpTiles3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCJumpTiles3D, QtScriptCCJumpTiles3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCJumpTiles3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCJumpTiles3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCJumpTiles3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCJumpTiles3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCJumpTiles3D;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCJumpTiles3D constructor");
	return false;
}

float QtScriptCCJumpTiles3D::getAmplitudeRate()
{
	auto __o = this->thiz<CCJumpTiles3D *>();
	if (__o)
	{
		return __o->getAmplitudeRate();
	}
	return static_cast<float>(0);
}

void QtScriptCCJumpTiles3D::setAmplitude(float fAmplitude)
{
	auto __o = this->thiz<CCJumpTiles3D *>();
	if (__o)
	{
		__o->setAmplitude(fAmplitude);
	}
}

void QtScriptCCJumpTiles3D::setAmplitudeRate(float fAmplitudeRate)
{
	auto __o = this->thiz<CCJumpTiles3D *>();
	if (__o)
	{
		__o->setAmplitudeRate(fAmplitudeRate);
	}
}

bool QtScriptCCJumpTiles3D::initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int numberOfJumps, float amplitude)
{
	auto __o = this->thiz<CCJumpTiles3D *>();
	if (__o)
	{
		return __o->initWithDuration(duration, gridSize, numberOfJumps, amplitude);
	}
	return false;
}

float QtScriptCCJumpTiles3D::getAmplitude()
{
	auto __o = this->thiz<CCJumpTiles3D *>();
	if (__o)
	{
		return __o->getAmplitude();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCJumpTiles3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			return __e->toScriptValue(CCJumpTiles3D::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCJumpTiles3D::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSplitRows::QtScriptCCSplitRows(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCSplitRows::QtScriptCCSplitRows(QScriptEngine *engine)
	: QtScriptCCSplitRows(engine, "SplitRows")
{
}

void QtScriptCCSplitRows::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCSplitRows, QtScriptCCSplitRows>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSplitRows::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSplitRows::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSplitRows::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSplitRows::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCSplitRows;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCSplitRows constructor");
	return false;
}

bool QtScriptCCSplitRows::initWithDuration(float duration, unsigned int nRows)
{
	auto __o = this->thiz<CCSplitRows *>();
	if (__o)
	{
		return __o->initWithDuration(duration, nRows);
	}
	return false;
}

QScriptValue QtScriptCCSplitRows::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCSplitRows::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSplitRows::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSplitCols::QtScriptCCSplitCols(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTiledGrid3DAction(engine, className)
{
}

QtScriptCCSplitCols::QtScriptCCSplitCols(QScriptEngine *engine)
	: QtScriptCCSplitCols(engine, "SplitCols")
{
}

void QtScriptCCSplitCols::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTiledGrid3DAction *>());
	auto ctor = RegisterT<CCSplitCols, QtScriptCCSplitCols>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSplitCols::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSplitCols::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSplitCols::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSplitCols::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCSplitCols;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCSplitCols constructor");
	return false;
}

bool QtScriptCCSplitCols::initWithDuration(float duration, unsigned int nCols)
{
	auto __o = this->thiz<CCSplitCols *>();
	if (__o)
	{
		return __o->initWithDuration(duration, nCols);
	}
	return false;
}

QScriptValue QtScriptCCSplitCols::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCSplitCols::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSplitCols::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionTweenDelegate::QtScriptCCActionTweenDelegate(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCActionTweenDelegate *, false>(engine, className)
{
}

QtScriptCCActionTweenDelegate::QtScriptCCActionTweenDelegate(QScriptEngine *engine)
	: QtScriptCCActionTweenDelegate(engine, "ActionTweenDelegate")
{
}

void QtScriptCCActionTweenDelegate::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCActionTweenDelegate, QtScriptCCActionTweenDelegate>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCActionTweenDelegate::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionTweenDelegate::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionTweenDelegate::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCActionTweenDelegate");
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCActionTween::QtScriptCCActionTween(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCActionTween::QtScriptCCActionTween(QScriptEngine *engine)
	: QtScriptCCActionTween(engine, "ActionTween")
{
}

void QtScriptCCActionTween::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCActionTween, QtScriptCCActionTween>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCActionTween::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCActionTween::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCActionTween::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCActionTween::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCActionTween;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCActionTween constructor");
	return false;
}

bool QtScriptCCActionTween::initWithDuration(float aDuration, const QByteArray& key, float from, float to)
{
	auto __o = this->thiz<CCActionTween *>();
	if (__o)
	{
		return __o->initWithDuration(aDuration, key.data(), from, to);
	}
	return false;
}

QScriptValue QtScriptCCActionTween::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<float>(context->argument(3));
			return __e->toScriptValue(CCActionTween::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCActionTween::create");
	return __e->uncaughtException();
}

QByteArray QtScriptCCActionTween::_public_field_get_strKey() const
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		return QByteArray(object->m_strKey.c_str(), int(object->m_strKey.size()));
	}
	return QByteArray();
}

void QtScriptCCActionTween::_public_field_set_strKey(const QByteArray& value)
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		object->m_strKey = std::string(value.data(), size_t(value.size()));
	}
}

float QtScriptCCActionTween::_public_field_get_fFrom() const
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		return object->m_fFrom;
	}
	return static_cast<float>(0);
}

void QtScriptCCActionTween::_public_field_set_fFrom(float value)
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		object->m_fFrom = value;
	}
}

float QtScriptCCActionTween::_public_field_get_fTo() const
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		return object->m_fTo;
	}
	return static_cast<float>(0);
}

void QtScriptCCActionTween::_public_field_set_fTo(float value)
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		object->m_fTo = value;
	}
}

float QtScriptCCActionTween::_public_field_get_fDelta() const
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		return object->m_fDelta;
	}
	return static_cast<float>(0);
}

void QtScriptCCActionTween::_public_field_set_fDelta(float value)
{
	auto object = thiz<CCActionTween *>();
	if (object)
	{
		object->m_fDelta = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCPointArray::QtScriptCCPointArray(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCPointArray::QtScriptCCPointArray(QScriptEngine *engine)
	: QtScriptCCPointArray(engine, "PointArray")
{
}

void QtScriptCCPointArray::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCPointArray, QtScriptCCPointArray>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCPointArray::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

unsigned int QtScriptCCPointArray::count()
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		return __o->count();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCPointArray::insert(const cocos2d::CCPoint& controlPoint, unsigned int index)
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		__o->insertControlPoint(controlPoint, index);
	}
}

cocos2d::CCPointArray* QtScriptCCPointArray::reverse()
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		return __o->reverse();
	}
	return nullptr;
}

bool QtScriptCCPointArray::initWithCapacity(unsigned int cap)
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		return __o->initWithCapacity(cap);
	}
	return false;
}

void QtScriptCCPointArray::remove(unsigned int index)
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		__o->removeControlPointAtIndex(index);
	}
}

void QtScriptCCPointArray::replace(const cocos2d::CCPoint& controlPoint, unsigned int index)
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		__o->replaceControlPoint(controlPoint, index);
	}
}

cocos2d::CCPoint QtScriptCCPointArray::at(unsigned int index)
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		return __o->getControlPointAtIndex(index);
	}
	return cocos2d::CCPoint();
}

void QtScriptCCPointArray::reverseInline()
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		__o->reverseInline();
	}
}

void QtScriptCCPointArray::append(const cocos2d::CCPoint& controlPoint)
{
	auto __o = this->thiz<CCPointArray *>();
	if (__o)
	{
		__o->addControlPoint(controlPoint);
	}
}

QScriptValue QtScriptCCPointArray::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCPointArray::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPointArray::create");
	return __e->uncaughtException();
}

int QtScriptCCPointArray::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCPointArray::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCPointArray::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCPointArray();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPointArray constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCardinalSplineTo::QtScriptCCCardinalSplineTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCActionInterval(engine, className)
{
}

QtScriptCCCardinalSplineTo::QtScriptCCCardinalSplineTo(QScriptEngine *engine)
	: QtScriptCCCardinalSplineTo(engine, "CardinalSplineTo")
{
}

void QtScriptCCCardinalSplineTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCActionInterval *>());
	auto ctor = RegisterT<CCCardinalSplineTo, QtScriptCCCardinalSplineTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCardinalSplineTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCPointArray* QtScriptCCCardinalSplineTo::getPoints()
{
	auto __o = this->thiz<CCCardinalSplineTo *>();
	if (__o)
	{
		return __o->getPoints();
	}
	return nullptr;
}

void QtScriptCCCardinalSplineTo::setPoints(cocos2d::CCPointArray* points)
{
	auto __o = this->thiz<CCCardinalSplineTo *>();
	if (__o)
	{
		__o->setPoints(points);
	}
}

void QtScriptCCCardinalSplineTo::updatePosition(cocos2d::CCPoint& newPos)
{
	auto __o = this->thiz<CCCardinalSplineTo *>();
	if (__o)
	{
		__o->updatePosition(newPos);
	}
}

bool QtScriptCCCardinalSplineTo::initWithDuration(float duration, cocos2d::CCPointArray* points, float tension)
{
	auto __o = this->thiz<CCCardinalSplineTo *>();
	if (__o)
	{
		return __o->initWithDuration(duration, points, tension);
	}
	return false;
}

QScriptValue QtScriptCCCardinalSplineTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPointArray*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCCardinalSplineTo::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCardinalSplineTo::create");
	return __e->uncaughtException();
}

int QtScriptCCCardinalSplineTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCardinalSplineTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCardinalSplineTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCardinalSplineTo();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCardinalSplineTo constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCardinalSplineBy::QtScriptCCCardinalSplineBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCCardinalSplineTo(engine, className)
{
}

QtScriptCCCardinalSplineBy::QtScriptCCCardinalSplineBy(QScriptEngine *engine)
	: QtScriptCCCardinalSplineBy(engine, "CardinalSplineBy")
{
}

void QtScriptCCCardinalSplineBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCCardinalSplineTo *>());
	auto ctor = RegisterT<CCCardinalSplineBy, QtScriptCCCardinalSplineBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCardinalSplineBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCCardinalSplineBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPointArray*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCCardinalSplineBy::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCardinalSplineBy::create");
	return __e->uncaughtException();
}

int QtScriptCCCardinalSplineBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCardinalSplineBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCardinalSplineBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCardinalSplineBy();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCardinalSplineBy constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCatmullRomTo::QtScriptCCCatmullRomTo(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCCardinalSplineTo(engine, className)
{
}

QtScriptCCCatmullRomTo::QtScriptCCCatmullRomTo(QScriptEngine *engine)
	: QtScriptCCCatmullRomTo(engine, "CatmullRomTo")
{
}

void QtScriptCCCatmullRomTo::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCCardinalSplineTo *>());
	auto ctor = RegisterT<CCCatmullRomTo, QtScriptCCCatmullRomTo>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCatmullRomTo::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCCatmullRomTo::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCatmullRomTo::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCatmullRomTo::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCCatmullRomTo;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCCatmullRomTo constructor");
	return false;
}

bool QtScriptCCCatmullRomTo::initWithDuration(float dt, cocos2d::CCPointArray* points)
{
	auto __o = this->thiz<CCCatmullRomTo *>();
	if (__o)
	{
		return __o->initWithDuration(dt, points);
	}
	return false;
}

QScriptValue QtScriptCCCatmullRomTo::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPointArray*>(context->argument(1));
			return __e->toScriptValue(CCCatmullRomTo::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCatmullRomTo::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCatmullRomBy::QtScriptCCCatmullRomBy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCCardinalSplineBy(engine, className)
{
}

QtScriptCCCatmullRomBy::QtScriptCCCatmullRomBy(QScriptEngine *engine)
	: QtScriptCCCatmullRomBy(engine, "CatmullRomBy")
{
}

void QtScriptCCCatmullRomBy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCCardinalSplineBy *>());
	auto ctor = RegisterT<CCCatmullRomBy, QtScriptCCCatmullRomBy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCatmullRomBy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCCatmullRomBy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCatmullRomBy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCatmullRomBy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCCatmullRomBy;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCCatmullRomBy constructor");
	return false;
}

bool QtScriptCCCatmullRomBy::initWithDuration(float dt, cocos2d::CCPointArray* points)
{
	auto __o = this->thiz<CCCatmullRomBy *>();
	if (__o)
	{
		return __o->initWithDuration(dt, points);
	}
	return false;
}

QScriptValue QtScriptCCCatmullRomBy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCPointArray*>(context->argument(1));
			return __e->toScriptValue(CCCatmullRomBy::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCatmullRomBy::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAtlasNode::QtScriptCCAtlasNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNodeRGBA(engine, className)
{
}

QtScriptCCAtlasNode::QtScriptCCAtlasNode(QScriptEngine *engine)
	: QtScriptCCAtlasNode(engine, "AtlasNode")
{
}

void QtScriptCCAtlasNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNodeRGBA *>());
	auto ctor = RegisterT<CCAtlasNode, QtScriptCCAtlasNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAtlasNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCAtlasNode::setTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		__o->setTexture(texture);
	}
}

cocos2d::_ccBlendFunc QtScriptCCAtlasNode::getBlendFunc()
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

bool QtScriptCCAtlasNode::initWithTileFile(const QByteArray& tile, unsigned int tileWidth, unsigned int tileHeight, unsigned int itemsToRender)
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		return __o->initWithTileFile(tile.data(), tileWidth, tileHeight, itemsToRender);
	}
	return false;
}

void QtScriptCCAtlasNode::setBlendFunc(cocos2d::_ccBlendFunc var)
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		__o->setBlendFunc(var);
	}
}

void QtScriptCCAtlasNode::setTextureAtlas(cocos2d::CCTextureAtlas* var)
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		__o->setTextureAtlas(var);
	}
}

cocos2d::CCTexture2D* QtScriptCCAtlasNode::getTexture()
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

cocos2d::CCTextureAtlas* QtScriptCCAtlasNode::getTextureAtlas()
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		return __o->getTextureAtlas();
	}
	return nullptr;
}

unsigned int QtScriptCCAtlasNode::getQuadsToDraw()
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		return __o->getQuadsToDraw();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCAtlasNode::updateAtlasValues()
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		__o->updateAtlasValues();
	}
}

bool QtScriptCCAtlasNode::initWithTexture(cocos2d::CCTexture2D* texture, unsigned int tileWidth, unsigned int tileHeight, unsigned int itemsToRender)
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		return __o->initWithTexture(texture, tileWidth, tileHeight, itemsToRender);
	}
	return false;
}

void QtScriptCCAtlasNode::setQuadsToDraw(unsigned int var)
{
	auto __o = this->thiz<CCAtlasNode *>();
	if (__o)
	{
		__o->setQuadsToDraw(var);
	}
}

QScriptValue QtScriptCCAtlasNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<unsigned int>(context->argument(3));
			return __e->toScriptValue(CCAtlasNode::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAtlasNode::create");
	return __e->uncaughtException();
}

int QtScriptCCAtlasNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAtlasNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAtlasNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAtlasNode();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAtlasNode constructor");
	}
	return ok;
}

bool QtScriptCCAtlasNode::_public_field_get_bIsOpacityModifyRGB() const
{
	auto object = thiz<CCAtlasNode *>();
	if (object)
	{
		return object->m_bIsOpacityModifyRGB;
	}
	return false;
}

void QtScriptCCAtlasNode::_public_field_set_bIsOpacityModifyRGB(const bool& value)
{
	auto object = thiz<CCAtlasNode *>();
	if (object)
	{
		object->m_bIsOpacityModifyRGB = value;
	}
}

int QtScriptCCAtlasNode::_public_field_get_nUniformColor() const
{
	auto object = thiz<CCAtlasNode *>();
	if (object)
	{
		return object->m_nUniformColor;
	}
	return static_cast<int>(0);
}

void QtScriptCCAtlasNode::_public_field_set_nUniformColor(int value)
{
	auto object = thiz<CCAtlasNode *>();
	if (object)
	{
		object->m_nUniformColor = value;
	}
}

bool QtScriptCCAtlasNode::_public_field_get_bIgnoreContentScaleFactor() const
{
	auto object = thiz<CCAtlasNode *>();
	if (object)
	{
		return object->m_bIgnoreContentScaleFactor;
	}
	return false;
}

void QtScriptCCAtlasNode::_public_field_set_bIgnoreContentScaleFactor(const bool& value)
{
	auto object = thiz<CCAtlasNode *>();
	if (object)
	{
		object->m_bIgnoreContentScaleFactor = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAutoreleasePool::QtScriptCCAutoreleasePool(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCAutoreleasePool::QtScriptCCAutoreleasePool(QScriptEngine *engine)
	: QtScriptCCAutoreleasePool(engine, "AutoreleasePool")
{
}

void QtScriptCCAutoreleasePool::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCAutoreleasePool, QtScriptCCAutoreleasePool>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCAutoreleasePool::addObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCAutoreleasePool *>();
	if (__o)
	{
		__o->addObject(pObject);
	}
}

void QtScriptCCAutoreleasePool::clear()
{
	auto __o = this->thiz<CCAutoreleasePool *>();
	if (__o)
	{
		__o->clear();
	}
}

void QtScriptCCAutoreleasePool::removeObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCAutoreleasePool *>();
	if (__o)
	{
		__o->removeObject(pObject);
	}
}

int QtScriptCCAutoreleasePool::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAutoreleasePool::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAutoreleasePool::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAutoreleasePool();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAutoreleasePool constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCPoolManager::QtScriptCCPoolManager(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCPoolManager, false>(engine, className)
{
}

QtScriptCCPoolManager::QtScriptCCPoolManager(QScriptEngine *engine)
	: QtScriptCCPoolManager(engine, "PoolManager")
{
}

void QtScriptCCPoolManager::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	QScriptValue inherit;
	auto ctor = RegisterT<CCPoolManager, QtScriptCCPoolManager>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("purgePoolManager", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCPoolManager::purgePoolManager)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("sharedPoolManager", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCPoolManager::sharedPoolManager)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCPoolManager::push()
{
	auto __o = this->thiz<CCPoolManager *>();
	if (__o)
	{
		__o->push();
	}
}

void QtScriptCCPoolManager::removeObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCPoolManager *>();
	if (__o)
	{
		__o->removeObject(pObject);
	}
}

void QtScriptCCPoolManager::pop()
{
	auto __o = this->thiz<CCPoolManager *>();
	if (__o)
	{
		__o->pop();
	}
}

void QtScriptCCPoolManager::finalize()
{
	auto __o = this->thiz<CCPoolManager *>();
	if (__o)
	{
		__o->finalize();
	}
}

void QtScriptCCPoolManager::addObject(cocos2d::CCObject* pObject)
{
	auto __o = this->thiz<CCPoolManager *>();
	if (__o)
	{
		__o->addObject(pObject);
	}
}

QScriptValue QtScriptCCPoolManager::purgePoolManager(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCPoolManager::purgePoolManager();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPoolManager::purgePoolManager");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCPoolManager::sharedPoolManager(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCPoolManager::sharedPoolManager());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPoolManager::sharedPoolManager");
	return __e->uncaughtException();
}

int QtScriptCCPoolManager::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCPoolManager::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCPoolManager::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCPoolManager constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCInteger::QtScriptCCInteger(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCInteger::QtScriptCCInteger(QScriptEngine *engine)
	: QtScriptCCInteger(engine, "Integer")
{
}

void QtScriptCCInteger::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCInteger, QtScriptCCInteger>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCInteger::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int64_t QtScriptCCInteger::getValue()
{
	auto __o = this->thiz<CCInteger *>();
	if (__o)
	{
		return __o->getValue();
	}
	return static_cast<int64_t>(0);
}

QScriptValue QtScriptCCInteger::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<int>(context->argument(0));
			return __e->toScriptValue(CCInteger::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCInteger::create");
	return __e->uncaughtException();
}

int QtScriptCCInteger::constructorArgumentCountMin() const
{
	return 1;
}

int QtScriptCCInteger::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCInteger::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<int64_t>(context->argument(0));
			out = new CCInteger(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCInteger constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFloat::QtScriptCCFloat(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCFloat::QtScriptCCFloat(QScriptEngine *engine)
	: QtScriptCCFloat(engine, "Float")
{
}

void QtScriptCCFloat::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCFloat, QtScriptCCFloat>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFloat::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

float QtScriptCCFloat::getValue()
{
	auto __o = this->thiz<CCFloat *>();
	if (__o)
	{
		return __o->getValue();
	}
	return static_cast<float>(0);
}

QScriptValue QtScriptCCFloat::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			return __e->toScriptValue(CCFloat::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFloat::create");
	return __e->uncaughtException();
}

int QtScriptCCFloat::constructorArgumentCountMin() const
{
	return 1;
}

int QtScriptCCFloat::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCFloat::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			out = new CCFloat(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFloat constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDouble::QtScriptCCDouble(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCDouble::QtScriptCCDouble(QScriptEngine *engine)
	: QtScriptCCDouble(engine, "Double")
{
}

void QtScriptCCDouble::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCDouble, QtScriptCCDouble>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDouble::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

double QtScriptCCDouble::getValue()
{
	auto __o = this->thiz<CCDouble *>();
	if (__o)
	{
		return __o->getValue();
	}
	return static_cast<double>(0);
}

QScriptValue QtScriptCCDouble::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<double>(context->argument(0));
			return __e->toScriptValue(CCDouble::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDouble::create");
	return __e->uncaughtException();
}

int QtScriptCCDouble::constructorArgumentCountMin() const
{
	return 1;
}

int QtScriptCCDouble::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCDouble::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<double>(context->argument(0));
			out = new CCDouble(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDouble constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCBool::QtScriptCCBool(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCBool::QtScriptCCBool(QScriptEngine *engine)
	: QtScriptCCBool(engine, "Bool")
{
}

void QtScriptCCBool::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCBool, QtScriptCCBool>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCBool::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCBool::getValue()
{
	auto __o = this->thiz<CCBool *>();
	if (__o)
	{
		return __o->getValue();
	}
	return false;
}

QScriptValue QtScriptCCBool::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<bool>(context->argument(0));
			return __e->toScriptValue(CCBool::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBool::create");
	return __e->uncaughtException();
}

int QtScriptCCBool::constructorArgumentCountMin() const
{
	return 1;
}

int QtScriptCCBool::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCBool::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<bool>(context->argument(0));
			out = new CCBool(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBool constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCZone::QtScriptCCZone(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCZone, false>(engine, className)
{
}

QtScriptCCZone::QtScriptCCZone(QScriptEngine *engine)
	: QtScriptCCZone(engine, "Zone")
{
}

void QtScriptCCZone::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCZone, QtScriptCCZone>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCZone::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCZone::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCZone::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCObject*>(context->argument(0));
			out = CCZone(arg0);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCZone constructor");
	}
	return ok;
}

cocos2d::CCObject* QtScriptCCZone::_public_field_get_pCopyObject() const
{
	auto object = thiz<CCZone *>();
	if (object)
	{
		return object->m_pCopyObject;
	}
	return nullptr;
}

void QtScriptCCZone::_public_field_set_pCopyObject(cocos2d::CCObject* value)
{
	auto object = thiz<CCZone *>();
	if (object)
	{
		object->m_pCopyObject = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDrawNode::QtScriptCCDrawNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCDrawNode::QtScriptCCDrawNode(QScriptEngine *engine)
	: QtScriptCCDrawNode(engine, "DrawNode")
{
}

void QtScriptCCDrawNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCDrawNode, QtScriptCCDrawNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDrawNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::_ccBlendFunc QtScriptCCDrawNode::getBlendFunc()
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

void QtScriptCCDrawNode::setBlendFunc(const cocos2d::_ccBlendFunc& blendFunc)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->setBlendFunc(blendFunc);
	}
}

void QtScriptCCDrawNode::clear()
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->clear();
	}
}

void QtScriptCCDrawNode::drawPolygon(const QScriptValue& arg0, const cocos2d::_ccColor4F& arg1, float arg2, const cocos2d::_ccColor4F& arg3)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->drawPolygon(qscriptvalue_cast<CCPointArray*>(arg0)->getControlPoints()->data(), qscriptvalue_cast<CCPointArray*>(arg0)->count(), arg1, arg2, arg3);
	}
}

void QtScriptCCDrawNode::drawPolygon(const QScriptValue& arg0, float arg1, float arg2, const cocos2d::_ccColor4F& arg3, const cocos2d::_ccColor4F& arg4)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->drawPolygon(qscriptvalue_cast<CCPointArray*>(arg0)->getControlPoints()->data(), qscriptvalue_cast<CCPointArray*>(arg0)->count(), arg1, arg2, arg3, arg4);
	}
}

void QtScriptCCDrawNode::drawDot(const cocos2d::CCPoint& pos, float radius, const cocos2d::_ccColor4F& color)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->drawDot(pos, radius, color);
	}
}

void QtScriptCCDrawNode::drawSegment(const cocos2d::CCPoint& from, const cocos2d::CCPoint& to, float radius, const cocos2d::_ccColor4F& color)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->drawSegment(from, to, radius, color);
	}
}

void QtScriptCCDrawNode::drawSegment(const cocos2d::CCPoint& from, const cocos2d::CCPoint& to, float width, float height, const cocos2d::_ccColor4F& color)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->drawSegment(from, to, width, height, color);
	}
}

void QtScriptCCDrawNode::listenBackToForeground(cocos2d::CCObject* obj)
{
	auto __o = this->thiz<CCDrawNode *>();
	if (__o)
	{
		__o->listenBackToForeground(obj);
	}
}

QScriptValue QtScriptCCDrawNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCDrawNode::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDrawNode::create");
	return __e->uncaughtException();
}

int QtScriptCCDrawNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDrawNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDrawNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCDrawNode();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDrawNode constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCConfiguration::QtScriptCCConfiguration(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCConfiguration::QtScriptCCConfiguration(QScriptEngine *engine)
	: QtScriptCCConfiguration(engine, "Configuration")
{
}

void QtScriptCCConfiguration::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCConfiguration, QtScriptCCConfiguration>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedConfiguration", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCConfiguration::sharedConfiguration)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("purgeConfiguration", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCConfiguration::purgeConfiguration)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCConfiguration::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCConfiguration::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCConfiguration::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCConfiguration");
	return false;
}

bool QtScriptCCConfiguration::checkForGLExtension(const QByteArray& searchName)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->checkForGLExtension(std::string(searchName.data(), size_t(searchName.size())));
	}
	return false;
}

cocos2d::CCObject* QtScriptCCConfiguration::getObject(const QByteArray& key)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getObject(key.data());
	}
	return nullptr;
}

void QtScriptCCConfiguration::setObject(const QByteArray& key, cocos2d::CCObject* value)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		__o->setObject(key.data(), value);
	}
}

double QtScriptCCConfiguration::getNumber(const QByteArray& key)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getNumber(key.data());
	}
	return static_cast<double>(0);
}

double QtScriptCCConfiguration::getNumber(const QByteArray& key, double default_value)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getNumber(key.data(), default_value);
	}
	return static_cast<double>(0);
}

bool QtScriptCCConfiguration::supportsPVRTC()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->supportsPVRTC();
	}
	return false;
}

bool QtScriptCCConfiguration::supportsShareableVAO()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->supportsShareableVAO();
	}
	return false;
}

QByteArray QtScriptCCConfiguration::getCString(const QByteArray& key)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return QByteArray(__o->getCString(key.data()));
	}
	return QByteArray();
}

QByteArray QtScriptCCConfiguration::getCString(const QByteArray& key, const QByteArray& default_value)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return QByteArray(__o->getCString(key.data(), default_value.data()));
	}
	return QByteArray();
}

bool QtScriptCCConfiguration::getBool(const QByteArray& key)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getBool(key.data());
	}
	return false;
}

bool QtScriptCCConfiguration::getBool(const QByteArray& key, bool default_value)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getBool(key.data(), default_value);
	}
	return false;
}

int QtScriptCCConfiguration::getMaxTextureUnits()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getMaxTextureUnits();
	}
	return 0;
}

bool QtScriptCCConfiguration::supportsNPOT()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->supportsNPOT();
	}
	return false;
}

int QtScriptCCConfiguration::getMaxModelviewStackDepth()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getMaxModelviewStackDepth();
	}
	return 0;
}

bool QtScriptCCConfiguration::supportsDiscardFramebuffer()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->supportsDiscardFramebuffer();
	}
	return false;
}

bool QtScriptCCConfiguration::init()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

void QtScriptCCConfiguration::gatherGPUInfo()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		__o->gatherGPUInfo();
	}
}

void QtScriptCCConfiguration::dumpInfo()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		__o->dumpInfo();
	}
}

void QtScriptCCConfiguration::loadConfigFile(const QByteArray& filename)
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		__o->loadConfigFile(filename.data());
	}
}

int QtScriptCCConfiguration::getMaxTextureSize()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->getMaxTextureSize();
	}
	return 0;
}

bool QtScriptCCConfiguration::supportsBGRA8888()
{
	auto __o = this->thiz<CCConfiguration *>();
	if (__o)
	{
		return __o->supportsBGRA8888();
	}
	return false;
}

QScriptValue QtScriptCCConfiguration::sharedConfiguration(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCConfiguration::sharedConfiguration());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCConfiguration::sharedConfiguration");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCConfiguration::purgeConfiguration(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCConfiguration::purgeConfiguration();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCConfiguration::purgeConfiguration");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCGrabber::QtScriptCCGrabber(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCGrabber::QtScriptCCGrabber(QScriptEngine *engine)
	: QtScriptCCGrabber(engine, "Grabber")
{
}

void QtScriptCCGrabber::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCGrabber, QtScriptCCGrabber>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCGrabber::beforeRender(cocos2d::CCTexture2D* pTexture)
{
	auto __o = this->thiz<CCGrabber *>();
	if (__o)
	{
		__o->beforeRender(pTexture);
	}
}

void QtScriptCCGrabber::grab(cocos2d::CCTexture2D* pTexture)
{
	auto __o = this->thiz<CCGrabber *>();
	if (__o)
	{
		__o->grab(pTexture);
	}
}

void QtScriptCCGrabber::afterRender(cocos2d::CCTexture2D* pTexture)
{
	auto __o = this->thiz<CCGrabber *>();
	if (__o)
	{
		__o->afterRender(pTexture);
	}
}

int QtScriptCCGrabber::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCGrabber::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCGrabber::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCGrabber();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGrabber constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCCamera::QtScriptCCCamera(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCCamera::QtScriptCCCamera(QScriptEngine *engine)
	: QtScriptCCCamera(engine, "Camera")
{
}

void QtScriptCCCamera::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCCamera, QtScriptCCCamera>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("getZEye", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCCamera::getZEye)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCCamera::locate()
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->locate();
	}
}

void QtScriptCCCamera::restore()
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->restore();
	}
}

void QtScriptCCCamera::setUpXYZ(float fUpX, float fUpY, float fUpZ)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->setUpXYZ(fUpX, fUpY, fUpZ);
	}
}

QByteArray QtScriptCCCamera::description()
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

void QtScriptCCCamera::setCenterXYZ(float fCenterX, float fCenterY, float fCenterZ)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->setCenterXYZ(fCenterX, fCenterY, fCenterZ);
	}
}

void QtScriptCCCamera::setEyeXYZ(float fEyeX, float fEyeY, float fEyeZ)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->setEyeXYZ(fEyeX, fEyeY, fEyeZ);
	}
}

void QtScriptCCCamera::getCenterXYZ(cocos2d::_ccVertex3F* arg0)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->getCenterXYZ(&arg0->x, &arg0->y, &arg0->z);
	}
}

void QtScriptCCCamera::getEyeXYZ(cocos2d::_ccVertex3F* arg0)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->getEyeXYZ(&arg0->x, &arg0->y, &arg0->z);
	}
}

bool QtScriptCCCamera::isDirty()
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		return __o->isDirty();
	}
	return false;
}

void QtScriptCCCamera::init()
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->init();
	}
}

void QtScriptCCCamera::getUpXYZ(cocos2d::_ccVertex3F* arg0)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->getUpXYZ(&arg0->x, &arg0->y, &arg0->z);
	}
}

void QtScriptCCCamera::setDirty(bool bValue)
{
	auto __o = this->thiz<CCCamera *>();
	if (__o)
	{
		__o->setDirty(bValue);
	}
}

QScriptValue QtScriptCCCamera::getZEye(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCCamera::getZEye());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCamera::getZEye");
	return __e->uncaughtException();
}

int QtScriptCCCamera::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCamera::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCamera::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCamera();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCCamera constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLabelAtlas::QtScriptCCLabelAtlas(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCAtlasNode(engine, className)
{
}

QtScriptCCLabelAtlas::QtScriptCCLabelAtlas(QScriptEngine *engine)
	: QtScriptCCLabelAtlas(engine, "LabelAtlas")
{
}

void QtScriptCCLabelAtlas::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCAtlasNode *>());
	auto ctor = RegisterT<CCLabelAtlas, QtScriptCCLabelAtlas>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLabelAtlas::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCLabelAtlas::setString(const QByteArray& label)
{
	auto __o = this->thiz<CCLabelAtlas *>();
	if (__o)
	{
		__o->setString(label.data());
	}
}

bool QtScriptCCLabelAtlas::initWithString(const QByteArray& string, const QByteArray& fntFile)
{
	auto __o = this->thiz<CCLabelAtlas *>();
	if (__o)
	{
		return __o->initWithString(string.data(), fntFile.data());
	}
	return false;
}

bool QtScriptCCLabelAtlas::initWithString(const QByteArray& string, const QByteArray& charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap)
{
	auto __o = this->thiz<CCLabelAtlas *>();
	if (__o)
	{
		return __o->initWithString(string.data(), charMapFile.data(), itemWidth, itemHeight, startCharMap);
	}
	return false;
}

QByteArray QtScriptCCLabelAtlas::getString()
{
	auto __o = this->thiz<CCLabelAtlas *>();
	if (__o)
	{
		return QByteArray(__o->getString());
	}
	return QByteArray();
}

QScriptValue QtScriptCCLabelAtlas::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			return __e->toScriptValue(CCLabelAtlas::create(arg0, arg1));
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<unsigned int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<unsigned int>(context->argument(3));
			auto arg4 = qscriptvalue_cast<unsigned int>(context->argument(4));
			return __e->toScriptValue(CCLabelAtlas::create(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelAtlas::create");
	return __e->uncaughtException();
}

int QtScriptCCLabelAtlas::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLabelAtlas::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLabelAtlas::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLabelAtlas();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelAtlas constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDirector::QtScriptCCDirector(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCDirector::QtScriptCCDirector(QScriptEngine *engine)
	: QtScriptCCDirector(engine, "Director")
{
}

void QtScriptCCDirector::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCDirector, QtScriptCCDirector>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedDirector", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDirector::sharedDirector)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

float QtScriptCCDirector::getContentScaleFactor()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getContentScaleFactor();
	}
	return static_cast<float>(0);
}

cocos2d::CCSize QtScriptCCDirector::getWinSizeInPixels()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getWinSizeInPixels();
	}
	return cocos2d::CCSize();
}

float QtScriptCCDirector::getDeltaTime()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getDeltaTime();
	}
	return static_cast<float>(0);
}

cocos2d::CCNode* QtScriptCCDirector::getNotificationNode()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getNotificationNode();
	}
	return nullptr;
}

cocos2d::CCSize QtScriptCCDirector::getWinSize()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getWinSize();
	}
	return cocos2d::CCSize();
}

double QtScriptCCDirector::frameStartTimeSeconds()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->frameStartTimeSeconds();
	}
	return static_cast<double>(0);
}

bool QtScriptCCDirector::isSendCleanupToScene()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->isSendCleanupToScene();
	}
	return false;
}

cocos2d::CCPoint QtScriptCCDirector::getVisibleOrigin()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getVisibleOrigin();
	}
	return cocos2d::CCPoint();
}

float QtScriptCCDirector::getSecondsPerFrame()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getSecondsPerFrame();
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCDirector::convertToUI(const cocos2d::CCPoint& obPoint)
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->convertToUI(obPoint);
	}
	return cocos2d::CCPoint();
}

cocos2d::CCEGLView* QtScriptCCDirector::getOpenGLView()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getOpenGLView();
	}
	return nullptr;
}

cocos2d::CCScene* QtScriptCCDirector::getRunningScene()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getRunningScene();
	}
	return nullptr;
}

int QtScriptCCDirector::getProjection()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return int(__o->getProjection());
	}
	return 0;
}

bool QtScriptCCDirector::isNextDeltaTimeZero()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->isNextDeltaTimeZero();
	}
	return false;
}

cocos2d::CCScheduler* QtScriptCCDirector::getScheduler()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getScheduler();
	}
	return nullptr;
}

cocos2d::CCPoint QtScriptCCDirector::convertToGL(const cocos2d::CCPoint& obPoint)
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->convertToGL(obPoint);
	}
	return cocos2d::CCPoint();
}

unsigned int QtScriptCCDirector::getTotalFrames()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getTotalFrames();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCDirector::setNotificationNode(cocos2d::CCNode* node)
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		__o->setNotificationNode(node);
	}
}

bool QtScriptCCDirector::isDisplayStats()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->isDisplayStats();
	}
	return false;
}

float QtScriptCCDirector::getZEye()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getZEye();
	}
	return static_cast<float>(0);
}

cocos2d::CCSize QtScriptCCDirector::getVisibleSize()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getVisibleSize();
	}
	return cocos2d::CCSize();
}

long QtScriptCCDirector::getClassTypeInfo()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getClassTypeInfo();
	}
	return static_cast<long>(0);
}

double QtScriptCCDirector::getAnimationInterval()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getAnimationInterval();
	}
	return static_cast<double>(0);
}

bool QtScriptCCDirector::isPaused()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->isPaused();
	}
	return false;
}

void QtScriptCCDirector::setDisplayStats(bool bDisplayStats)
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		__o->setDisplayStats(bDisplayStats);
	}
}

cocos2d::CCActionManager* QtScriptCCDirector::getActionManager()
{
	auto __o = this->thiz<CCDirector *>();
	if (__o)
	{
		return __o->getActionManager();
	}
	return nullptr;
}

QScriptValue QtScriptCCDirector::sharedDirector(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCDirector::sharedDirector());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDirector::sharedDirector");
	return __e->uncaughtException();
}

int QtScriptCCDirector::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDirector::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDirector::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCDirector();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDirector constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDisplayLinkDirector::QtScriptCCDisplayLinkDirector(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCDirector(engine, className)
{
}

QtScriptCCDisplayLinkDirector::QtScriptCCDisplayLinkDirector(QScriptEngine *engine)
	: QtScriptCCDisplayLinkDirector(engine, "DisplayLinkDirector")
{
}

void QtScriptCCDisplayLinkDirector::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCDirector *>());
	auto ctor = RegisterT<CCDisplayLinkDirector, QtScriptCCDisplayLinkDirector>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCDisplayLinkDirector::startAnimation()
{
	auto __o = this->thiz<CCDisplayLinkDirector *>();
	if (__o)
	{
		__o->startAnimation();
	}
}

void QtScriptCCDisplayLinkDirector::mainLoop()
{
	auto __o = this->thiz<CCDisplayLinkDirector *>();
	if (__o)
	{
		__o->mainLoop();
	}
}

void QtScriptCCDisplayLinkDirector::setAnimationInterval(double dValue)
{
	auto __o = this->thiz<CCDisplayLinkDirector *>();
	if (__o)
	{
		__o->setAnimationInterval(dValue);
	}
}

void QtScriptCCDisplayLinkDirector::stopAnimation()
{
	auto __o = this->thiz<CCDisplayLinkDirector *>();
	if (__o)
	{
		__o->stopAnimation();
	}
}

int QtScriptCCDisplayLinkDirector::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDisplayLinkDirector::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDisplayLinkDirector::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCDisplayLinkDirector();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDisplayLinkDirector constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCGridBase::QtScriptCCGridBase(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCGridBase::QtScriptCCGridBase(QScriptEngine *engine)
	: QtScriptCCGridBase(engine, "GridBase")
{
}

void QtScriptCCGridBase::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCGridBase, QtScriptCCGridBase>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCGridBase::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCGridBase::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCGridBase::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCGridBase::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCGridBase;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCGridBase constructor");
	return false;
}

void QtScriptCCGridBase::setGridSize(const cocos2d::CCSize& gridSize)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->setGridSize(gridSize);
	}
}

void QtScriptCCGridBase::calculateVertexPoints()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->calculateVertexPoints();
	}
}

void QtScriptCCGridBase::afterDraw(cocos2d::CCNode* pTarget)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->afterDraw(pTarget);
	}
}

void QtScriptCCGridBase::beforeDraw()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->beforeDraw();
	}
}

bool QtScriptCCGridBase::isTextureFlipped()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->isTextureFlipped();
	}
	return false;
}

cocos2d::CCSize QtScriptCCGridBase::getGridSize()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->getGridSize();
	}
	return cocos2d::CCSize();
}

cocos2d::CCPoint QtScriptCCGridBase::getStep()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->getStep();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCGridBase::set2DProjection()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->set2DProjection();
	}
}

void QtScriptCCGridBase::setStep(const cocos2d::CCPoint& step)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->setStep(step);
	}
}

void QtScriptCCGridBase::setTextureFlipped(bool bFlipped)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->setTextureFlipped(bFlipped);
	}
}

void QtScriptCCGridBase::blit()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->blit();
	}
}

void QtScriptCCGridBase::setActive(bool bActive)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->setActive(bActive);
	}
}

int QtScriptCCGridBase::getReuseGrid()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->getReuseGrid();
	}
	return 0;
}

bool QtScriptCCGridBase::initWithSize(const cocos2d::CCSize& gridSize)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->initWithSize(gridSize);
	}
	return false;
}

bool QtScriptCCGridBase::initWithSize(const cocos2d::CCSize& gridSize, cocos2d::CCTexture2D* pTexture, bool bFlipped)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->initWithSize(gridSize, pTexture, bFlipped);
	}
	return false;
}

void QtScriptCCGridBase::setReuseGrid(int nReuseGrid)
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->setReuseGrid(nReuseGrid);
	}
}

bool QtScriptCCGridBase::isActive()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		return __o->isActive();
	}
	return false;
}

void QtScriptCCGridBase::reuse()
{
	auto __o = this->thiz<CCGridBase *>();
	if (__o)
	{
		__o->reuse();
	}
}

QScriptValue QtScriptCCGridBase::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			return __e->toScriptValue(CCGridBase::create(arg0));
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			return __e->toScriptValue(CCGridBase::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGridBase::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCGrid3D::QtScriptCCGrid3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGridBase(engine, className)
{
}

QtScriptCCGrid3D::QtScriptCCGrid3D(QScriptEngine *engine)
	: QtScriptCCGrid3D(engine, "Grid3D")
{
}

void QtScriptCCGrid3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGridBase *>());
	auto ctor = RegisterT<CCGrid3D, QtScriptCCGrid3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCGrid3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCGrid3D::setVertex(const cocos2d::CCPoint& pos, const cocos2d::_ccVertex3F& vertex)
{
	auto __o = this->thiz<CCGrid3D *>();
	if (__o)
	{
		__o->setVertex(pos, vertex);
	}
}

cocos2d::_ccVertex3F QtScriptCCGrid3D::vertex(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCGrid3D *>();
	if (__o)
	{
		return __o->vertex(pos);
	}
	return cocos2d::_ccVertex3F();
}

cocos2d::_ccVertex3F QtScriptCCGrid3D::originalVertex(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCGrid3D *>();
	if (__o)
	{
		return __o->originalVertex(pos);
	}
	return cocos2d::_ccVertex3F();
}

QScriptValue QtScriptCCGrid3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			return __e->toScriptValue(CCGrid3D::create(arg0));
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			return __e->toScriptValue(CCGrid3D::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGrid3D::create");
	return __e->uncaughtException();
}

int QtScriptCCGrid3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCGrid3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCGrid3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCGrid3D();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCGrid3D constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTiledGrid3D::QtScriptCCTiledGrid3D(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCGridBase(engine, className)
{
}

QtScriptCCTiledGrid3D::QtScriptCCTiledGrid3D(QScriptEngine *engine)
	: QtScriptCCTiledGrid3D(engine, "TiledGrid3D")
{
}

void QtScriptCCTiledGrid3D::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCGridBase *>());
	auto ctor = RegisterT<CCTiledGrid3D, QtScriptCCTiledGrid3D>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTiledGrid3D::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::_ccQuad3 QtScriptCCTiledGrid3D::tile(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCTiledGrid3D *>();
	if (__o)
	{
		return __o->tile(pos);
	}
	return cocos2d::_ccQuad3();
}

void QtScriptCCTiledGrid3D::setTile(const cocos2d::CCPoint& pos, const cocos2d::_ccQuad3& coords)
{
	auto __o = this->thiz<CCTiledGrid3D *>();
	if (__o)
	{
		__o->setTile(pos, coords);
	}
}

cocos2d::_ccQuad3 QtScriptCCTiledGrid3D::originalTile(const cocos2d::CCPoint& pos)
{
	auto __o = this->thiz<CCTiledGrid3D *>();
	if (__o)
	{
		return __o->originalTile(pos);
	}
	return cocos2d::_ccQuad3();
}

QScriptValue QtScriptCCTiledGrid3D::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			return __e->toScriptValue(CCTiledGrid3D::create(arg0));
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			return __e->toScriptValue(CCTiledGrid3D::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTiledGrid3D::create");
	return __e->uncaughtException();
}

int QtScriptCCTiledGrid3D::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTiledGrid3D::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTiledGrid3D::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTiledGrid3D();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTiledGrid3D constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTextureAtlas::QtScriptCCTextureAtlas(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTextureAtlas::QtScriptCCTextureAtlas(QScriptEngine *engine)
	: QtScriptCCTextureAtlas(engine, "TextureAtlas")
{
}

void QtScriptCCTextureAtlas::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTextureAtlas, QtScriptCCTextureAtlas>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTextureAtlas::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTexture", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTextureAtlas::createWithTexture)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCTextureAtlas::removeAllQuads()
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->removeAllQuads();
	}
}

bool QtScriptCCTextureAtlas::isDirty()
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->isDirty();
	}
	return false;
}

unsigned int QtScriptCCTextureAtlas::getTotalQuads()
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->getTotalQuads();
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCTextureAtlas::initWithFile(const QByteArray& file, unsigned int capacity)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->initWithFile(file.data(), capacity);
	}
	return false;
}

QByteArray QtScriptCCTextureAtlas::description()
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

cocos2d::CCTexture2D* QtScriptCCTextureAtlas::getTexture()
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

bool QtScriptCCTextureAtlas::resizeCapacity(unsigned int n)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->resizeCapacity(n);
	}
	return false;
}

void QtScriptCCTextureAtlas::moveQuadsFromIndex(unsigned int index, unsigned int newIndex)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->moveQuadsFromIndex(index, newIndex);
	}
}

void QtScriptCCTextureAtlas::moveQuadsFromIndex(unsigned int oldIndex, unsigned int amount, unsigned int newIndex)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->moveQuadsFromIndex(oldIndex, amount, newIndex);
	}
}

void QtScriptCCTextureAtlas::removeQuadsAtIndex(unsigned int index, unsigned int amount)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->removeQuadsAtIndex(index, amount);
	}
}

void QtScriptCCTextureAtlas::insertQuad(cocos2d::_ccV3F_C4B_T2F_Quad* quad, unsigned int index)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->insertQuad(quad, index);
	}
}

void QtScriptCCTextureAtlas::fillWithEmptyQuadsFromIndex(unsigned int index, unsigned int amount)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->fillWithEmptyQuadsFromIndex(index, amount);
	}
}

void QtScriptCCTextureAtlas::setTexture(cocos2d::CCTexture2D* var)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->setTexture(var);
	}
}

unsigned int QtScriptCCTextureAtlas::getCapacity()
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->getCapacity();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCTextureAtlas::insertQuadFromIndex(unsigned int fromIndex, unsigned int newIndex)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->insertQuadFromIndex(fromIndex, newIndex);
	}
}

void QtScriptCCTextureAtlas::setDirty(bool bDirty)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->setDirty(bDirty);
	}
}

bool QtScriptCCTextureAtlas::initWithTexture(cocos2d::CCTexture2D* texture, unsigned int capacity)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		return __o->initWithTexture(texture, capacity);
	}
	return false;
}

void QtScriptCCTextureAtlas::updateQuad(cocos2d::_ccV3F_C4B_T2F_Quad* quad, unsigned int index)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->updateQuad(quad, index);
	}
}

void QtScriptCCTextureAtlas::removeQuadAtIndex(unsigned int index)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->removeQuadAtIndex(index);
	}
}

void QtScriptCCTextureAtlas::increaseTotalQuadsWith(unsigned int amount)
{
	auto __o = this->thiz<CCTextureAtlas *>();
	if (__o)
	{
		__o->increaseTotalQuadsWith(amount);
	}
}

QScriptValue QtScriptCCTextureAtlas::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCTextureAtlas::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureAtlas::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTextureAtlas::createWithTexture(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCTextureAtlas::createWithTexture(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureAtlas::createWithTexture");
	return __e->uncaughtException();
}

int QtScriptCCTextureAtlas::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTextureAtlas::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTextureAtlas::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTextureAtlas();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureAtlas constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSprite::QtScriptCCSprite(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNodeRGBA(engine, className)
{
}

QtScriptCCSprite::QtScriptCCSprite(QScriptEngine *engine)
	: QtScriptCCSprite(engine, "Sprite")
{
}

void QtScriptCCSprite::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNodeRGBA *>());
	auto ctor = RegisterT<CCSprite, QtScriptCCSprite>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSprite::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTexture", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSprite::createWithTexture)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithSpriteFrameName", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSprite::createWithSpriteFrameName)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithSpriteFrame", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSprite::createWithSpriteFrame)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCSprite::setTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setTexture(texture);
	}
}

cocos2d::CCTexture2D* QtScriptCCSprite::getTexture()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

cocos2d::CCSpriteFrame* QtScriptCCSprite::displayFrame()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->displayFrame();
	}
	return nullptr;
}

cocos2d::CCSpriteBatchNode* QtScriptCCSprite::getBatchNode()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getBatchNode();
	}
	return nullptr;
}

cocos2d::CCPoint QtScriptCCSprite::getOffsetPosition()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getOffsetPosition();
	}
	return cocos2d::CCPoint();
}

bool QtScriptCCSprite::isFlipX()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->isFlipX();
	}
	return false;
}

bool QtScriptCCSprite::isFlipY()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->isFlipY();
	}
	return false;
}

void QtScriptCCSprite::setTextureRect(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setTextureRect(rect);
	}
}

void QtScriptCCSprite::setTextureRect(const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCSize& untrimmedSize)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setTextureRect(rect, rotated, untrimmedSize);
	}
}

bool QtScriptCCSprite::initWithSpriteFrameName(const QByteArray& pszSpriteFrameName)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithSpriteFrameName(pszSpriteFrameName.data());
	}
	return false;
}

bool QtScriptCCSprite::isFrameDisplayed(cocos2d::CCSpriteFrame* pFrame)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->isFrameDisplayed(pFrame);
	}
	return false;
}

unsigned int QtScriptCCSprite::getAtlasIndex()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getAtlasIndex();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCSprite::setDisplayFrame(cocos2d::CCSpriteFrame* pNewFrame)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setDisplayFrame(pNewFrame);
	}
}

void QtScriptCCSprite::setBatchNode(cocos2d::CCSpriteBatchNode* pobSpriteBatchNode)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setBatchNode(pobSpriteBatchNode);
	}
}

cocos2d::_ccBlendFunc QtScriptCCSprite::getBlendFunc()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

void QtScriptCCSprite::setDisplayFrameWithAnimationName(const QByteArray& animationName, int frameIndex)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setDisplayFrameWithAnimationName(animationName.data(), frameIndex);
	}
}

void QtScriptCCSprite::setTextureAtlas(cocos2d::CCTextureAtlas* pobTextureAtlas)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setTextureAtlas(pobTextureAtlas);
	}
}

void QtScriptCCSprite::setFlipY(bool bFlipY)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setFlipY(bFlipY);
	}
}

void QtScriptCCSprite::setFlipX(bool bFlipX)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setFlipX(bFlipX);
	}
}

bool QtScriptCCSprite::isDirty()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->isDirty();
	}
	return false;
}

void QtScriptCCSprite::setAtlasIndex(unsigned int uAtlasIndex)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setAtlasIndex(uAtlasIndex);
	}
}

bool QtScriptCCSprite::initWithTexture(cocos2d::CCTexture2D* pTexture)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithTexture(pTexture);
	}
	return false;
}

bool QtScriptCCSprite::initWithTexture(cocos2d::CCTexture2D* pTexture, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithTexture(pTexture, rect);
	}
	return false;
}

bool QtScriptCCSprite::initWithTexture(cocos2d::CCTexture2D* pTexture, const cocos2d::CCRect& rect, bool rotated)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithTexture(pTexture, rect, rotated);
	}
	return false;
}

void QtScriptCCSprite::setDirty(bool bDirty)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setDirty(bDirty);
	}
}

bool QtScriptCCSprite::isTextureRectRotated()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->isTextureRectRotated();
	}
	return false;
}

cocos2d::CCRect QtScriptCCSprite::getTextureRect()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getTextureRect();
	}
	return cocos2d::CCRect();
}

bool QtScriptCCSprite::initWithFile(const QByteArray& pszFilename)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithFile(pszFilename.data());
	}
	return false;
}

bool QtScriptCCSprite::initWithFile(const QByteArray& pszFilename, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithFile(pszFilename.data(), rect);
	}
	return false;
}

void QtScriptCCSprite::setBlendFunc(cocos2d::_ccBlendFunc blendFunc)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setBlendFunc(blendFunc);
	}
}

cocos2d::CCTextureAtlas* QtScriptCCSprite::getTextureAtlas()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getTextureAtlas();
	}
	return nullptr;
}

bool QtScriptCCSprite::initWithSpriteFrame(cocos2d::CCSpriteFrame* pSpriteFrame)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->initWithSpriteFrame(pSpriteFrame);
	}
	return false;
}

cocos2d::_ccV3F_C4B_T2F_Quad QtScriptCCSprite::getQuad()
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		return __o->getQuad();
	}
	return cocos2d::_ccV3F_C4B_T2F_Quad();
}

void QtScriptCCSprite::setVertexRect(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCSprite *>();
	if (__o)
	{
		__o->setVertexRect(rect);
	}
}

QScriptValue QtScriptCCSprite::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCSprite::create());
		}
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCSprite::create(arg0));
		}
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			return __e->toScriptValue(CCSprite::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSprite::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSprite::createWithTexture(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			return __e->toScriptValue(CCSprite::createWithTexture(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCRect>(context->argument(1));
			return __e->toScriptValue(CCSprite::createWithTexture(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSprite::createWithTexture");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSprite::createWithSpriteFrameName(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCSprite::createWithSpriteFrameName(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSprite::createWithSpriteFrameName");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSprite::createWithSpriteFrame(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSpriteFrame*>(context->argument(0));
			return __e->toScriptValue(CCSprite::createWithSpriteFrame(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSprite::createWithSpriteFrame");
	return __e->uncaughtException();
}

int QtScriptCCSprite::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSprite::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSprite::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCSprite();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSprite constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLabelTTF::QtScriptCCLabelTTF(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCSprite(engine, className)
{
}

QtScriptCCLabelTTF::QtScriptCCLabelTTF(QScriptEngine *engine)
	: QtScriptCCLabelTTF(engine, "LabelTTF")
{
}

void QtScriptCCLabelTTF::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCSprite *>());
	auto ctor = RegisterT<CCLabelTTF, QtScriptCCLabelTTF>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLabelTTF::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithFontDefinition", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLabelTTF::createWithFontDefinition)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCLabelTTF::enableShadow(const cocos2d::CCSize& shadowOffset, float shadowOpacity, float shadowBlur)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->enableShadow(shadowOffset, shadowOpacity, shadowBlur);
	}
}

void QtScriptCCLabelTTF::enableShadow(const cocos2d::CCSize& shadowOffset, float shadowOpacity, float shadowBlur, bool mustUpdateTexture)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->enableShadow(shadowOffset, shadowOpacity, shadowBlur, mustUpdateTexture);
	}
}

void QtScriptCCLabelTTF::setDimensions(const cocos2d::CCSize& dim)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setDimensions(dim);
	}
}

float QtScriptCCLabelTTF::getFontSize()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->getFontSize();
	}
	return static_cast<float>(0);
}

QByteArray QtScriptCCLabelTTF::getString()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return QByteArray(__o->getString());
	}
	return QByteArray();
}

void QtScriptCCLabelTTF::setTextDefinition(cocos2d::_ccFontDefinition* theDefinition)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setTextDefinition(theDefinition);
	}
}

void QtScriptCCLabelTTF::setFontName(const QByteArray& fontName)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setFontName(fontName.data());
	}
}

int QtScriptCCLabelTTF::getHorizontalAlignment()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return int(__o->getHorizontalAlignment());
	}
	return 0;
}

bool QtScriptCCLabelTTF::initWithStringAndTextDefinition(const QByteArray& string, cocos2d::_ccFontDefinition& textDefinition)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->initWithStringAndTextDefinition(string.data(), textDefinition);
	}
	return false;
}

void QtScriptCCLabelTTF::setString(const QByteArray& label)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setString(label.data());
	}
}

bool QtScriptCCLabelTTF::initWithString(const QByteArray& string, const QByteArray& fontName, float fontSize)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->initWithString(string.data(), fontName.data(), fontSize);
	}
	return false;
}

bool QtScriptCCLabelTTF::initWithString(const QByteArray& string, const QByteArray& fontName, float fontSize, const cocos2d::CCSize& dimensions, int hAlignment)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->initWithString(string.data(), fontName.data(), fontSize, dimensions, cocos2d::CCTextAlignment(hAlignment));
	}
	return false;
}

bool QtScriptCCLabelTTF::initWithString(const QByteArray& string, const QByteArray& fontName, float fontSize, const cocos2d::CCSize& dimensions, int hAlignment, int vAlignment)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->initWithString(string.data(), fontName.data(), fontSize, dimensions, cocos2d::CCTextAlignment(hAlignment), cocos2d::CCVerticalTextAlignment(vAlignment));
	}
	return false;
}

void QtScriptCCLabelTTF::setFontFillColor(const cocos2d::_ccColor3B& tintColor)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setFontFillColor(tintColor);
	}
}

void QtScriptCCLabelTTF::setFontFillColor(const cocos2d::_ccColor3B& tintColor, bool mustUpdateTexture)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setFontFillColor(tintColor, mustUpdateTexture);
	}
}

QByteArray QtScriptCCLabelTTF::description()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

void QtScriptCCLabelTTF::enableStroke(const cocos2d::_ccColor3B& strokeColor, float strokeSize)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->enableStroke(strokeColor, strokeSize);
	}
}

void QtScriptCCLabelTTF::enableStroke(const cocos2d::_ccColor3B& strokeColor, float strokeSize, bool mustUpdateTexture)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->enableStroke(strokeColor, strokeSize, mustUpdateTexture);
	}
}

cocos2d::CCSize QtScriptCCLabelTTF::getDimensions()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->getDimensions();
	}
	return cocos2d::CCSize();
}

void QtScriptCCLabelTTF::setVerticalAlignment(int verticalAlignment)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setVerticalAlignment(cocos2d::CCVerticalTextAlignment(verticalAlignment));
	}
}

void QtScriptCCLabelTTF::setFontSize(float fontSize)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setFontSize(fontSize);
	}
}

int QtScriptCCLabelTTF::getVerticalAlignment()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return int(__o->getVerticalAlignment());
	}
	return 0;
}

cocos2d::_ccFontDefinition* QtScriptCCLabelTTF::getTextDefinition()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return __o->getTextDefinition();
	}
	return nullptr;
}

QByteArray QtScriptCCLabelTTF::getFontName()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		return QByteArray(__o->getFontName());
	}
	return QByteArray();
}

void QtScriptCCLabelTTF::setHorizontalAlignment(int alignment)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->setHorizontalAlignment(cocos2d::CCTextAlignment(alignment));
	}
}

void QtScriptCCLabelTTF::disableShadow()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->disableShadow();
	}
}

void QtScriptCCLabelTTF::disableShadow(bool mustUpdateTexture)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->disableShadow(mustUpdateTexture);
	}
}

void QtScriptCCLabelTTF::disableStroke()
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->disableStroke();
	}
}

void QtScriptCCLabelTTF::disableStroke(bool mustUpdateTexture)
{
	auto __o = this->thiz<CCLabelTTF *>();
	if (__o)
	{
		__o->disableStroke(mustUpdateTexture);
	}
}

QScriptValue QtScriptCCLabelTTF::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 6))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLabelTTF::create());
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCLabelTTF::create(arg0, arg1, arg2));
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(3));
			auto tmp_4 = qscriptvalue_cast<int>(context->argument(4));
			auto arg4 = cocos2d::CCTextAlignment(tmp_4);
			return __e->toScriptValue(CCLabelTTF::create(arg0, arg1, arg2, arg3, arg4));
		}
		case 6:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(3));
			auto tmp_4 = qscriptvalue_cast<int>(context->argument(4));
			auto arg4 = cocos2d::CCTextAlignment(tmp_4);
			auto tmp_5 = qscriptvalue_cast<int>(context->argument(5));
			auto arg5 = cocos2d::CCVerticalTextAlignment(tmp_5);
			return __e->toScriptValue(CCLabelTTF::create(arg0, arg1, arg2, arg3, arg4, arg5));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelTTF::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCLabelTTF::createWithFontDefinition(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<cocos2d::_ccFontDefinition>(context->argument(1));
			return __e->toScriptValue(CCLabelTTF::createWithFontDefinition(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelTTF::createWithFontDefinition");
	return __e->uncaughtException();
}

int QtScriptCCLabelTTF::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLabelTTF::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLabelTTF::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLabelTTF();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelTTF constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSpriteBatchNode::QtScriptCCSpriteBatchNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCSpriteBatchNode::QtScriptCCSpriteBatchNode(QScriptEngine *engine)
	: QtScriptCCSpriteBatchNode(engine, "SpriteBatchNode")
{
}

void QtScriptCCSpriteBatchNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCSpriteBatchNode, QtScriptCCSpriteBatchNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpriteBatchNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTexture", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpriteBatchNode::createWithTexture)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCSpriteBatchNode::appendChild(cocos2d::CCSprite* sprite)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->appendChild(sprite);
	}
}

void QtScriptCCSpriteBatchNode::reorderBatch(bool reorder)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->reorderBatch(reorder);
	}
}

bool QtScriptCCSpriteBatchNode::initWithFile(const QByteArray& fileImage, unsigned int capacity)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->initWithFile(fileImage.data(), capacity);
	}
	return false;
}

cocos2d::_ccBlendFunc QtScriptCCSpriteBatchNode::getBlendFunc()
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

unsigned int QtScriptCCSpriteBatchNode::lowestAtlasIndexInChild(cocos2d::CCSprite* sprite)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->lowestAtlasIndexInChild(sprite);
	}
	return static_cast<unsigned int>(0);
}

unsigned int QtScriptCCSpriteBatchNode::atlasIndexForChild(cocos2d::CCSprite* sprite, int z)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->atlasIndexForChild(sprite, z);
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCSpriteBatchNode::setTextureAtlas(cocos2d::CCTextureAtlas* textureAtlas)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->setTextureAtlas(textureAtlas);
	}
}

unsigned int QtScriptCCSpriteBatchNode::rebuildIndexInOrder(cocos2d::CCSprite* parent, unsigned int index)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->rebuildIndexInOrder(parent, index);
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCSpriteBatchNode::increaseAtlasCapacity()
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->increaseAtlasCapacity();
	}
}

cocos2d::CCTextureAtlas* QtScriptCCSpriteBatchNode::getTextureAtlas()
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->getTextureAtlas();
	}
	return nullptr;
}

cocos2d::CCArray* QtScriptCCSpriteBatchNode::getDescendants()
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->getDescendants();
	}
	return nullptr;
}

void QtScriptCCSpriteBatchNode::setTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->setTexture(texture);
	}
}

void QtScriptCCSpriteBatchNode::insertChild(cocos2d::CCSprite* child, unsigned int index)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->insertChild(child, index);
	}
}

cocos2d::CCTexture2D* QtScriptCCSpriteBatchNode::getTexture()
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

void QtScriptCCSpriteBatchNode::removeChildAtIndex(unsigned int index, bool doCleanup)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->removeChildAtIndex(index, doCleanup);
	}
}

unsigned int QtScriptCCSpriteBatchNode::highestAtlasIndexInChild(cocos2d::CCSprite* sprite)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->highestAtlasIndexInChild(sprite);
	}
	return static_cast<unsigned int>(0);
}

bool QtScriptCCSpriteBatchNode::initWithTexture(cocos2d::CCTexture2D* tex, unsigned int capacity)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		return __o->initWithTexture(tex, capacity);
	}
	return false;
}

void QtScriptCCSpriteBatchNode::removeSpriteFromAtlas(cocos2d::CCSprite* sprite)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->removeSpriteFromAtlas(sprite);
	}
}

void QtScriptCCSpriteBatchNode::setBlendFunc(cocos2d::_ccBlendFunc blendFunc)
{
	auto __o = this->thiz<CCSpriteBatchNode *>();
	if (__o)
	{
		__o->setBlendFunc(blendFunc);
	}
}

QScriptValue QtScriptCCSpriteBatchNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCSpriteBatchNode::create(arg0));
		}
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCSpriteBatchNode::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteBatchNode::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSpriteBatchNode::createWithTexture(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			return __e->toScriptValue(CCSpriteBatchNode::createWithTexture(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCSpriteBatchNode::createWithTexture(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteBatchNode::createWithTexture");
	return __e->uncaughtException();
}

int QtScriptCCSpriteBatchNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSpriteBatchNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSpriteBatchNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCSpriteBatchNode();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteBatchNode constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCBMFontConfiguration::QtScriptCCBMFontConfiguration(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCBMFontConfiguration::QtScriptCCBMFontConfiguration(QScriptEngine *engine)
	: QtScriptCCBMFontConfiguration(engine, "BMFontConfiguration")
{
}

void QtScriptCCBMFontConfiguration::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCBMFontConfiguration, QtScriptCCBMFontConfiguration>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCBMFontConfiguration::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCBMFontConfiguration::setAtlasName(const QByteArray& atlasName)
{
	auto __o = this->thiz<CCBMFontConfiguration *>();
	if (__o)
	{
		__o->setAtlasName(atlasName.data());
	}
}

bool QtScriptCCBMFontConfiguration::initWithFNTfile(const QByteArray& FNTfile)
{
	auto __o = this->thiz<CCBMFontConfiguration *>();
	if (__o)
	{
		return __o->initWithFNTfile(FNTfile.data());
	}
	return false;
}

QByteArray QtScriptCCBMFontConfiguration::getAtlasName()
{
	auto __o = this->thiz<CCBMFontConfiguration *>();
	if (__o)
	{
		return QByteArray(__o->getAtlasName());
	}
	return QByteArray();
}

QByteArray QtScriptCCBMFontConfiguration::description()
{
	auto __o = this->thiz<CCBMFontConfiguration *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

QScriptValue QtScriptCCBMFontConfiguration::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCBMFontConfiguration::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBMFontConfiguration::create");
	return __e->uncaughtException();
}

int QtScriptCCBMFontConfiguration::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCBMFontConfiguration::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCBMFontConfiguration::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCBMFontConfiguration();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCBMFontConfiguration constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLabelBMFont::QtScriptCCLabelBMFont(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCSpriteBatchNode(engine, className)
{
}

QtScriptCCLabelBMFont::QtScriptCCLabelBMFont(QScriptEngine *engine)
	: QtScriptCCLabelBMFont(engine, "LabelBMFont")
{
}

void QtScriptCCLabelBMFont::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCSpriteBatchNode *>());
	auto ctor = RegisterT<CCLabelBMFont, QtScriptCCLabelBMFont>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("purgeCachedData", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLabelBMFont::purgeCachedData)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLabelBMFont::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCLabelBMFont::createFontChars()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->createFontChars();
	}
}

QByteArray QtScriptCCLabelBMFont::getString()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return QByteArray(__o->getString());
	}
	return QByteArray();
}

void QtScriptCCLabelBMFont::setOpacity(unsigned char opacity)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setOpacity(opacity);
	}
}

void QtScriptCCLabelBMFont::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setCascadeOpacityEnabled(cascadeOpacityEnabled);
	}
}

QByteArray QtScriptCCLabelBMFont::getFntFile()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return QByteArray(__o->getFntFile());
	}
	return QByteArray();
}

void QtScriptCCLabelBMFont::updateLabel()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->updateLabel();
	}
}

void QtScriptCCLabelBMFont::setWidth(float width)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setWidth(width);
	}
}

bool QtScriptCCLabelBMFont::isOpacityModifyRGB()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->isOpacityModifyRGB();
	}
	return false;
}

bool QtScriptCCLabelBMFont::isCascadeOpacityEnabled()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->isCascadeOpacityEnabled();
	}
	return false;
}

void QtScriptCCLabelBMFont::setString(const QByteArray& newString)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setString(newString.data());
	}
}

void QtScriptCCLabelBMFont::setString(const QByteArray& newString, bool needUpdateLabel)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setString(newString.data(), needUpdateLabel);
	}
}

bool QtScriptCCLabelBMFont::initWithString(const QByteArray& str, const QByteArray& fntFile)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->initWithString(str.data(), fntFile.data());
	}
	return false;
}

bool QtScriptCCLabelBMFont::initWithString(const QByteArray& str, const QByteArray& fntFile, float width)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->initWithString(str.data(), fntFile.data(), width);
	}
	return false;
}

bool QtScriptCCLabelBMFont::initWithString(const QByteArray& str, const QByteArray& fntFile, float width, int alignment)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->initWithString(str.data(), fntFile.data(), width, cocos2d::CCTextAlignment(alignment));
	}
	return false;
}

bool QtScriptCCLabelBMFont::initWithString(const QByteArray& str, const QByteArray& fntFile, float width, int alignment, cocos2d::CCPoint imageOffset)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->initWithString(str.data(), fntFile.data(), width, cocos2d::CCTextAlignment(alignment), imageOffset);
	}
	return false;
}

void QtScriptCCLabelBMFont::setCascadeColorEnabled(bool cascadeColorEnabled)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setCascadeColorEnabled(cascadeColorEnabled);
	}
}

void QtScriptCCLabelBMFont::setOpacityModifyRGB(bool isOpacityModifyRGB)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setOpacityModifyRGB(isOpacityModifyRGB);
	}
}

void QtScriptCCLabelBMFont::updateDisplayedOpacity(unsigned char parentOpacity)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->updateDisplayedOpacity(parentOpacity);
	}
}

void QtScriptCCLabelBMFont::setFntFile(const QByteArray& fntFile)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setFntFile(fntFile.data());
	}
}

unsigned char QtScriptCCLabelBMFont::getOpacity()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->getOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCLabelBMFont::setLineBreakWithoutSpace(bool breakWithoutSpace)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setLineBreakWithoutSpace(breakWithoutSpace);
	}
}

cocos2d::CCBMFontConfiguration* QtScriptCCLabelBMFont::getConfiguration()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->getConfiguration();
	}
	return nullptr;
}

cocos2d::_ccColor3B QtScriptCCLabelBMFont::getColor()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->getColor();
	}
	return cocos2d::_ccColor3B();
}

unsigned char QtScriptCCLabelBMFont::getDisplayedOpacity()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->getDisplayedOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCLabelBMFont::setColor(const cocos2d::_ccColor3B& color)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setColor(color);
	}
}

void QtScriptCCLabelBMFont::setCString(const QByteArray& label)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setCString(label.data());
	}
}

cocos2d::_ccColor3B QtScriptCCLabelBMFont::getDisplayedColor()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->getDisplayedColor();
	}
	return cocos2d::_ccColor3B();
}

bool QtScriptCCLabelBMFont::isCascadeColorEnabled()
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		return __o->isCascadeColorEnabled();
	}
	return false;
}

void QtScriptCCLabelBMFont::updateDisplayedColor(const cocos2d::_ccColor3B& parentColor)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->updateDisplayedColor(parentColor);
	}
}

void QtScriptCCLabelBMFont::setAlignment(int alignment)
{
	auto __o = this->thiz<CCLabelBMFont *>();
	if (__o)
	{
		__o->setAlignment(cocos2d::CCTextAlignment(alignment));
	}
}

QScriptValue QtScriptCCLabelBMFont::purgeCachedData(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCLabelBMFont::purgeCachedData();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelBMFont::purgeCachedData");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCLabelBMFont::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLabelBMFont::create());
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			return __e->toScriptValue(CCLabelBMFont::create(arg0, arg1));
		}
		case 3:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCLabelBMFont::create(arg0, arg1, arg2));
		}
		case 4:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto tmp_3 = qscriptvalue_cast<int>(context->argument(3));
			auto arg3 = cocos2d::CCTextAlignment(tmp_3);
			return __e->toScriptValue(CCLabelBMFont::create(arg0, arg1, arg2, arg3));
		}
		case 5:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto tmp_3 = qscriptvalue_cast<int>(context->argument(3));
			auto arg3 = cocos2d::CCTextAlignment(tmp_3);
			auto arg4 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(4));
			return __e->toScriptValue(CCLabelBMFont::create(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelBMFont::create");
	return __e->uncaughtException();
}

int QtScriptCCLabelBMFont::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLabelBMFont::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLabelBMFont::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLabelBMFont();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLabelBMFont constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLayer::QtScriptCCLayer(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCLayer::QtScriptCCLayer(QScriptEngine *engine)
	: QtScriptCCLayer(engine, "Layer")
{
}

void QtScriptCCLayer::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCLayer, QtScriptCCLayer>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayer::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCLayer::keyBackClicked()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->keyBackClicked();
	}
}

bool QtScriptCCLayer::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		return __o->ccTouchBegan(pTouch, pEvent);
	}
	return false;
}

bool QtScriptCCLayer::isKeypadEnabled()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		return __o->isKeypadEnabled();
	}
	return false;
}

void QtScriptCCLayer::ccTouchesCancelled(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchesCancelled(pTouches, pEvent);
	}
}

void QtScriptCCLayer::didAccelerate(cocos2d::CCAcceleration* pAccelerationValue)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->didAccelerate(pAccelerationValue);
	}
}

void QtScriptCCLayer::ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchesMoved(pTouches, pEvent);
	}
}

void QtScriptCCLayer::unregisterTouchHandler()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->unregisterScriptTouchHandler();
	}
}

void QtScriptCCLayer::registerKeypadHandler(const QScriptValue& arg0)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->registerScriptKeypadHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0));
	}
}

int QtScriptCCLayer::getTouchMode()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		return __o->getTouchMode();
	}
	return 0;
}

void QtScriptCCLayer::setAccelerometerEnabled(bool value)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->setAccelerometerEnabled(value);
	}
}

bool QtScriptCCLayer::isTouchEnabled()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		return __o->isTouchEnabled();
	}
	return false;
}

void QtScriptCCLayer::registerTouchHandler(const QScriptValue& arg0, int arg1, bool arg2, int arg3)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->registerScriptTouchHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0), arg1, arg2, arg3);
	}
}

void QtScriptCCLayer::ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchMoved(pTouch, pEvent);
	}
}

void QtScriptCCLayer::setTouchEnabled(bool value)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->setTouchEnabled(value);
	}
}

void QtScriptCCLayer::setAccelerometerInterval(double interval)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->setAccelerometerInterval(interval);
	}
}

void QtScriptCCLayer::ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchesEnded(pTouches, pEvent);
	}
}

void QtScriptCCLayer::unregisterKeypadHandler()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->unregisterScriptKeypadHandler();
	}
}

void QtScriptCCLayer::setTouchMode(int mode)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->setTouchMode(cocos2d::ccTouchesMode(mode));
	}
}

bool QtScriptCCLayer::isAccelerometerEnabled()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		return __o->isAccelerometerEnabled();
	}
	return false;
}

void QtScriptCCLayer::ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchEnded(pTouch, pEvent);
	}
}

void QtScriptCCLayer::ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchCancelled(pTouch, pEvent);
	}
}

void QtScriptCCLayer::ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->ccTouchesBegan(pTouches, pEvent);
	}
}

void QtScriptCCLayer::setTouchPriority(int priority)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->setTouchPriority(priority);
	}
}

int QtScriptCCLayer::getTouchPriority()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		return __o->getTouchPriority();
	}
	return 0;
}

void QtScriptCCLayer::setKeypadEnabled(bool value)
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->setKeypadEnabled(value);
	}
}

void QtScriptCCLayer::registerWithTouchDispatcher()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->registerWithTouchDispatcher();
	}
}

void QtScriptCCLayer::keyMenuClicked()
{
	auto __o = this->thiz<CCLayer *>();
	if (__o)
	{
		__o->keyMenuClicked();
	}
}

QScriptValue QtScriptCCLayer::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLayer::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayer::create");
	return __e->uncaughtException();
}

int QtScriptCCLayer::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLayer::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLayer::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLayer();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayer constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLayerRGBA::QtScriptCCLayerRGBA(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCLayer(engine, className)
{
}

QtScriptCCLayerRGBA::QtScriptCCLayerRGBA(QScriptEngine *engine)
	: QtScriptCCLayerRGBA(engine, "LayerRGBA")
{
}

void QtScriptCCLayerRGBA::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCLayer *>());
	auto ctor = RegisterT<CCLayerRGBA, QtScriptCCLayerRGBA>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayerRGBA::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCLayerRGBA::isOpacityModifyRGB()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->isOpacityModifyRGB();
	}
	return false;
}

void QtScriptCCLayerRGBA::setColor(const cocos2d::_ccColor3B& color)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->setColor(color);
	}
}

bool QtScriptCCLayerRGBA::isCascadeOpacityEnabled()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->isCascadeOpacityEnabled();
	}
	return false;
}

cocos2d::_ccColor3B QtScriptCCLayerRGBA::getColor()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->getColor();
	}
	return cocos2d::_ccColor3B();
}

unsigned char QtScriptCCLayerRGBA::getDisplayedOpacity()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->getDisplayedOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCLayerRGBA::setCascadeColorEnabled(bool cascadeColorEnabled)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->setCascadeColorEnabled(cascadeColorEnabled);
	}
}

void QtScriptCCLayerRGBA::setOpacity(unsigned char opacity)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->setOpacity(opacity);
	}
}

void QtScriptCCLayerRGBA::setOpacityModifyRGB(bool bValue)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->setOpacityModifyRGB(bValue);
	}
}

void QtScriptCCLayerRGBA::setCascadeOpacityEnabled(bool cascadeOpacityEnabled)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->setCascadeOpacityEnabled(cascadeOpacityEnabled);
	}
}

void QtScriptCCLayerRGBA::updateDisplayedOpacity(unsigned char parentOpacity)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->updateDisplayedOpacity(parentOpacity);
	}
}

bool QtScriptCCLayerRGBA::isCascadeColorEnabled()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->isCascadeColorEnabled();
	}
	return false;
}

void QtScriptCCLayerRGBA::updateDisplayedColor(const cocos2d::_ccColor3B& parentColor)
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		__o->updateDisplayedColor(parentColor);
	}
}

unsigned char QtScriptCCLayerRGBA::getOpacity()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->getOpacity();
	}
	return static_cast<unsigned char>(0);
}

cocos2d::_ccColor3B QtScriptCCLayerRGBA::getDisplayedColor()
{
	auto __o = this->thiz<CCLayerRGBA *>();
	if (__o)
	{
		return __o->getDisplayedColor();
	}
	return cocos2d::_ccColor3B();
}

QScriptValue QtScriptCCLayerRGBA::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLayerRGBA::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerRGBA::create");
	return __e->uncaughtException();
}

int QtScriptCCLayerRGBA::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLayerRGBA::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLayerRGBA::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLayerRGBA();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerRGBA constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLayerColor::QtScriptCCLayerColor(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCLayerRGBA(engine, className)
{
}

QtScriptCCLayerColor::QtScriptCCLayerColor(QScriptEngine *engine)
	: QtScriptCCLayerColor(engine, "LayerColor")
{
}

void QtScriptCCLayerColor::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCLayerRGBA *>());
	auto ctor = RegisterT<CCLayerColor, QtScriptCCLayerColor>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayerColor::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCLayerColor::changeWidthAndHeight(float w, float h)
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		__o->changeWidthAndHeight(w, h);
	}
}

cocos2d::_ccBlendFunc QtScriptCCLayerColor::getBlendFunc()
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

void QtScriptCCLayerColor::setBlendFunc(cocos2d::_ccBlendFunc var)
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		__o->setBlendFunc(var);
	}
}

bool QtScriptCCLayerColor::initWithColor(const cocos2d::_ccColor4B& color)
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		return __o->initWithColor(color);
	}
	return false;
}

bool QtScriptCCLayerColor::initWithColor(const cocos2d::_ccColor4B& color, float width, float height)
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		return __o->initWithColor(color, width, height);
	}
	return false;
}

void QtScriptCCLayerColor::changeWidth(float w)
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		__o->changeWidth(w);
	}
}

void QtScriptCCLayerColor::changeHeight(float h)
{
	auto __o = this->thiz<CCLayerColor *>();
	if (__o)
	{
		__o->changeHeight(h);
	}
}

QScriptValue QtScriptCCLayerColor::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLayerColor::create());
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::_ccColor4B>(context->argument(0));
			return __e->toScriptValue(CCLayerColor::create(arg0));
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::_ccColor4B>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCLayerColor::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerColor::create");
	return __e->uncaughtException();
}

int QtScriptCCLayerColor::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLayerColor::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLayerColor::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLayerColor();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerColor constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLayerGradient::QtScriptCCLayerGradient(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCLayerColor(engine, className)
{
}

QtScriptCCLayerGradient::QtScriptCCLayerGradient(QScriptEngine *engine)
	: QtScriptCCLayerGradient(engine, "LayerGradient")
{
}

void QtScriptCCLayerGradient::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCLayerColor *>());
	auto ctor = RegisterT<CCLayerGradient, QtScriptCCLayerGradient>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayerGradient::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCLayerGradient::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLayerGradient::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLayerGradient::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCLayerGradient;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCLayerGradient constructor");
	return false;
}

cocos2d::_ccColor3B QtScriptCCLayerGradient::getStartColor()
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->getStartColor();
	}
	return cocos2d::_ccColor3B();
}

bool QtScriptCCLayerGradient::isCompressedInterpolation()
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->isCompressedInterpolation();
	}
	return false;
}

unsigned char QtScriptCCLayerGradient::getStartOpacity()
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->getStartOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCLayerGradient::setVector(const cocos2d::CCPoint& var)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		__o->setVector(var);
	}
}

void QtScriptCCLayerGradient::setStartOpacity(unsigned char var)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		__o->setStartOpacity(var);
	}
}

void QtScriptCCLayerGradient::setCompressedInterpolation(bool bCompressedInterpolation)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		__o->setCompressedInterpolation(bCompressedInterpolation);
	}
}

void QtScriptCCLayerGradient::setEndOpacity(unsigned char var)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		__o->setEndOpacity(var);
	}
}

cocos2d::CCPoint QtScriptCCLayerGradient::getVector()
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->getVector();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCLayerGradient::setEndColor(const cocos2d::_ccColor3B& var)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		__o->setEndColor(var);
	}
}

bool QtScriptCCLayerGradient::initWithColor(const cocos2d::_ccColor4B& start, const cocos2d::_ccColor4B& end)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->initWithColor(start, end);
	}
	return false;
}

bool QtScriptCCLayerGradient::initWithColor(const cocos2d::_ccColor4B& start, const cocos2d::_ccColor4B& end, const cocos2d::CCPoint& v)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->initWithColor(start, end, v);
	}
	return false;
}

cocos2d::_ccColor3B QtScriptCCLayerGradient::getEndColor()
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->getEndColor();
	}
	return cocos2d::_ccColor3B();
}

unsigned char QtScriptCCLayerGradient::getEndOpacity()
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		return __o->getEndOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCLayerGradient::setStartColor(const cocos2d::_ccColor3B& var)
{
	auto __o = this->thiz<CCLayerGradient *>();
	if (__o)
	{
		__o->setStartColor(var);
	}
}

QScriptValue QtScriptCCLayerGradient::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLayerGradient::create());
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::_ccColor4B>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::_ccColor4B>(context->argument(1));
			return __e->toScriptValue(CCLayerGradient::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::_ccColor4B>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::_ccColor4B>(context->argument(1));
			auto arg2 = qscriptvalue_cast<cocos2d::CCPoint>(context->argument(2));
			return __e->toScriptValue(CCLayerGradient::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerGradient::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCLayerMultiplex::QtScriptCCLayerMultiplex(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCLayer(engine, className)
{
}

QtScriptCCLayerMultiplex::QtScriptCCLayerMultiplex(QScriptEngine *engine)
	: QtScriptCCLayerMultiplex(engine, "LayerMultiplex")
{
}

void QtScriptCCLayerMultiplex::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCLayer *>());
	auto ctor = RegisterT<CCLayerMultiplex, QtScriptCCLayerMultiplex>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("createWithLayer", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayerMultiplex::createWithLayer)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayerMultiplex::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithArray", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCLayerMultiplex::createWithArray)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCLayerMultiplex::initWithArray(cocos2d::CCArray* arrayOfLayers)
{
	auto __o = this->thiz<CCLayerMultiplex *>();
	if (__o)
	{
		return __o->initWithArray(arrayOfLayers);
	}
	return false;
}

void QtScriptCCLayerMultiplex::switchToAndReleaseMe(unsigned int n)
{
	auto __o = this->thiz<CCLayerMultiplex *>();
	if (__o)
	{
		__o->switchToAndReleaseMe(n);
	}
}

void QtScriptCCLayerMultiplex::addLayer(cocos2d::CCLayer* layer)
{
	auto __o = this->thiz<CCLayerMultiplex *>();
	if (__o)
	{
		__o->addLayer(layer);
	}
}

bool QtScriptCCLayerMultiplex::initWithLayers(cocos2d::CCLayer* layer, QByteArray* params)
{
	auto __o = this->thiz<CCLayerMultiplex *>();
	if (__o)
	{
		return __o->initWithLayers(layer, params->data());
	}
	return false;
}

void QtScriptCCLayerMultiplex::switchTo(unsigned int n)
{
	auto __o = this->thiz<CCLayerMultiplex *>();
	if (__o)
	{
		__o->switchTo(n);
	}
}

QScriptValue QtScriptCCLayerMultiplex::createWithLayer(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCLayer*>(context->argument(0));
			return __e->toScriptValue(CCLayerMultiplex::createWithLayer(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerMultiplex::createWithLayer");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCLayerMultiplex::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCLayerMultiplex::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerMultiplex::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCLayerMultiplex::createWithArray(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			return __e->toScriptValue(CCLayerMultiplex::createWithArray(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerMultiplex::createWithArray");
	return __e->uncaughtException();
}

int QtScriptCCLayerMultiplex::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCLayerMultiplex::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCLayerMultiplex::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCLayerMultiplex();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCLayerMultiplex constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCScene::QtScriptCCScene(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCScene::QtScriptCCScene(QScriptEngine *engine)
	: QtScriptCCScene(engine, "Scene")
{
}

void QtScriptCCScene::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCScene, QtScriptCCScene>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCScene::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCScene::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCScene::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCScene::create");
	return __e->uncaughtException();
}

int QtScriptCCScene::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCScene::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCScene::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCScene();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCScene constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionEaseScene::QtScriptCCTransitionEaseScene(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCTransitionEaseScene *, false>(engine, className)
{
}

QtScriptCCTransitionEaseScene::QtScriptCCTransitionEaseScene(QScriptEngine *engine)
	: QtScriptCCTransitionEaseScene(engine, "TransitionEaseScene")
{
}

void QtScriptCCTransitionEaseScene::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCTransitionEaseScene, QtScriptCCTransitionEaseScene>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCTransitionEaseScene::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionEaseScene::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionEaseScene::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCTransitionEaseScene");
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionScene::QtScriptCCTransitionScene(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCScene(engine, className)
{
}

QtScriptCCTransitionScene::QtScriptCCTransitionScene(QScriptEngine *engine)
	: QtScriptCCTransitionScene(engine, "TransitionScene")
{
}

void QtScriptCCTransitionScene::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCScene *>());
	auto ctor = RegisterT<CCTransitionScene, QtScriptCCTransitionScene>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionScene::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCTransitionScene::finish()
{
	auto __o = this->thiz<CCTransitionScene *>();
	if (__o)
	{
		__o->finish();
	}
}

bool QtScriptCCTransitionScene::initWithDuration(float t, cocos2d::CCScene* scene)
{
	auto __o = this->thiz<CCTransitionScene *>();
	if (__o)
	{
		return __o->initWithDuration(t, scene);
	}
	return false;
}

void QtScriptCCTransitionScene::hideOutShowIn()
{
	auto __o = this->thiz<CCTransitionScene *>();
	if (__o)
	{
		__o->hideOutShowIn();
	}
}

QScriptValue QtScriptCCTransitionScene::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionScene::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionScene::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionScene::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionScene::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionScene::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionScene();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionScene constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSceneOriented::QtScriptCCTransitionSceneOriented(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionSceneOriented::QtScriptCCTransitionSceneOriented(QScriptEngine *engine)
	: QtScriptCCTransitionSceneOriented(engine, "TransitionSceneOriented")
{
}

void QtScriptCCTransitionSceneOriented::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionSceneOriented, QtScriptCCTransitionSceneOriented>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSceneOriented::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCTransitionSceneOriented::initWithDuration(float t, cocos2d::CCScene* scene, int orientation)
{
	auto __o = this->thiz<CCTransitionSceneOriented *>();
	if (__o)
	{
		return __o->initWithDuration(t, scene, cocos2d::tOrientation(orientation));
	}
	return false;
}

QScriptValue QtScriptCCTransitionSceneOriented::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionSceneOriented::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSceneOriented::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSceneOriented::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSceneOriented::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSceneOriented::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSceneOriented();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSceneOriented constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionRotoZoom::QtScriptCCTransitionRotoZoom(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionRotoZoom::QtScriptCCTransitionRotoZoom(QScriptEngine *engine)
	: QtScriptCCTransitionRotoZoom(engine, "TransitionRotoZoom")
{
}

void QtScriptCCTransitionRotoZoom::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionRotoZoom, QtScriptCCTransitionRotoZoom>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionRotoZoom::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionRotoZoom::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionRotoZoom::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionRotoZoom::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionRotoZoom::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionRotoZoom::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionRotoZoom::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionRotoZoom();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionRotoZoom constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionJumpZoom::QtScriptCCTransitionJumpZoom(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionJumpZoom::QtScriptCCTransitionJumpZoom(QScriptEngine *engine)
	: QtScriptCCTransitionJumpZoom(engine, "TransitionJumpZoom")
{
}

void QtScriptCCTransitionJumpZoom::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionJumpZoom, QtScriptCCTransitionJumpZoom>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionJumpZoom::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionJumpZoom::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionJumpZoom::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionJumpZoom::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionJumpZoom::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionJumpZoom::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionJumpZoom::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionJumpZoom();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionJumpZoom constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionMoveInL::QtScriptCCTransitionMoveInL(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionMoveInL::QtScriptCCTransitionMoveInL(QScriptEngine *engine)
	: QtScriptCCTransitionMoveInL(engine, "TransitionMoveInL")
{
}

void QtScriptCCTransitionMoveInL::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionMoveInL, QtScriptCCTransitionMoveInL>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionMoveInL::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionMoveInL::action()
{
	auto __o = this->thiz<CCTransitionMoveInL *>();
	if (__o)
	{
		return __o->action();
	}
	return nullptr;
}

cocos2d::CCActionInterval* QtScriptCCTransitionMoveInL::easeActionWithAction(cocos2d::CCActionInterval* action)
{
	auto __o = this->thiz<CCTransitionMoveInL *>();
	if (__o)
	{
		return __o->easeActionWithAction(action);
	}
	return nullptr;
}

void QtScriptCCTransitionMoveInL::initScenes()
{
	auto __o = this->thiz<CCTransitionMoveInL *>();
	if (__o)
	{
		__o->initScenes();
	}
}

QScriptValue QtScriptCCTransitionMoveInL::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionMoveInL::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInL::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionMoveInL::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionMoveInL::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionMoveInL::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionMoveInL();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInL constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionMoveInR::QtScriptCCTransitionMoveInR(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionMoveInL(engine, className)
{
}

QtScriptCCTransitionMoveInR::QtScriptCCTransitionMoveInR(QScriptEngine *engine)
	: QtScriptCCTransitionMoveInR(engine, "TransitionMoveInR")
{
}

void QtScriptCCTransitionMoveInR::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionMoveInL *>());
	auto ctor = RegisterT<CCTransitionMoveInR, QtScriptCCTransitionMoveInR>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionMoveInR::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionMoveInR::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionMoveInR::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInR::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionMoveInR::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionMoveInR::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionMoveInR::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionMoveInR();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInR constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionMoveInT::QtScriptCCTransitionMoveInT(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionMoveInL(engine, className)
{
}

QtScriptCCTransitionMoveInT::QtScriptCCTransitionMoveInT(QScriptEngine *engine)
	: QtScriptCCTransitionMoveInT(engine, "TransitionMoveInT")
{
}

void QtScriptCCTransitionMoveInT::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionMoveInL *>());
	auto ctor = RegisterT<CCTransitionMoveInT, QtScriptCCTransitionMoveInT>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionMoveInT::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionMoveInT::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionMoveInT::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInT::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionMoveInT::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionMoveInT::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionMoveInT::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionMoveInT();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInT constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionMoveInB::QtScriptCCTransitionMoveInB(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionMoveInL(engine, className)
{
}

QtScriptCCTransitionMoveInB::QtScriptCCTransitionMoveInB(QScriptEngine *engine)
	: QtScriptCCTransitionMoveInB(engine, "TransitionMoveInB")
{
}

void QtScriptCCTransitionMoveInB::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionMoveInL *>());
	auto ctor = RegisterT<CCTransitionMoveInB, QtScriptCCTransitionMoveInB>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionMoveInB::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionMoveInB::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionMoveInB::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInB::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionMoveInB::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionMoveInB::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionMoveInB::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionMoveInB();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionMoveInB constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSlideInL::QtScriptCCTransitionSlideInL(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionSlideInL::QtScriptCCTransitionSlideInL(QScriptEngine *engine)
	: QtScriptCCTransitionSlideInL(engine, "TransitionSlideInL")
{
}

void QtScriptCCTransitionSlideInL::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionSlideInL, QtScriptCCTransitionSlideInL>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSlideInL::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionSlideInL::action()
{
	auto __o = this->thiz<CCTransitionSlideInL *>();
	if (__o)
	{
		return __o->action();
	}
	return nullptr;
}

cocos2d::CCActionInterval* QtScriptCCTransitionSlideInL::easeActionWithAction(cocos2d::CCActionInterval* action)
{
	auto __o = this->thiz<CCTransitionSlideInL *>();
	if (__o)
	{
		return __o->easeActionWithAction(action);
	}
	return nullptr;
}

void QtScriptCCTransitionSlideInL::initScenes()
{
	auto __o = this->thiz<CCTransitionSlideInL *>();
	if (__o)
	{
		__o->initScenes();
	}
}

QScriptValue QtScriptCCTransitionSlideInL::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionSlideInL::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInL::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSlideInL::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSlideInL::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSlideInL::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSlideInL();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInL constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSlideInR::QtScriptCCTransitionSlideInR(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSlideInL(engine, className)
{
}

QtScriptCCTransitionSlideInR::QtScriptCCTransitionSlideInR(QScriptEngine *engine)
	: QtScriptCCTransitionSlideInR(engine, "TransitionSlideInR")
{
}

void QtScriptCCTransitionSlideInR::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSlideInL *>());
	auto ctor = RegisterT<CCTransitionSlideInR, QtScriptCCTransitionSlideInR>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSlideInR::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionSlideInR::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionSlideInR::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInR::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSlideInR::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSlideInR::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSlideInR::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSlideInR();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInR constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSlideInB::QtScriptCCTransitionSlideInB(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSlideInL(engine, className)
{
}

QtScriptCCTransitionSlideInB::QtScriptCCTransitionSlideInB(QScriptEngine *engine)
	: QtScriptCCTransitionSlideInB(engine, "TransitionSlideInB")
{
}

void QtScriptCCTransitionSlideInB::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSlideInL *>());
	auto ctor = RegisterT<CCTransitionSlideInB, QtScriptCCTransitionSlideInB>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSlideInB::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionSlideInB::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionSlideInB::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInB::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSlideInB::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSlideInB::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSlideInB::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSlideInB();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInB constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSlideInT::QtScriptCCTransitionSlideInT(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSlideInL(engine, className)
{
}

QtScriptCCTransitionSlideInT::QtScriptCCTransitionSlideInT(QScriptEngine *engine)
	: QtScriptCCTransitionSlideInT(engine, "TransitionSlideInT")
{
}

void QtScriptCCTransitionSlideInT::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSlideInL *>());
	auto ctor = RegisterT<CCTransitionSlideInT, QtScriptCCTransitionSlideInT>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSlideInT::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionSlideInT::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionSlideInT::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInT::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSlideInT::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSlideInT::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSlideInT::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSlideInT();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSlideInT constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionShrinkGrow::QtScriptCCTransitionShrinkGrow(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionShrinkGrow::QtScriptCCTransitionShrinkGrow(QScriptEngine *engine)
	: QtScriptCCTransitionShrinkGrow(engine, "TransitionShrinkGrow")
{
}

void QtScriptCCTransitionShrinkGrow::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionShrinkGrow, QtScriptCCTransitionShrinkGrow>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionShrinkGrow::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionShrinkGrow::easeActionWithAction(cocos2d::CCActionInterval* action)
{
	auto __o = this->thiz<CCTransitionShrinkGrow *>();
	if (__o)
	{
		return __o->easeActionWithAction(action);
	}
	return nullptr;
}

QScriptValue QtScriptCCTransitionShrinkGrow::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionShrinkGrow::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionShrinkGrow::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionShrinkGrow::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionShrinkGrow::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionShrinkGrow::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionShrinkGrow();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionShrinkGrow constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFlipX::QtScriptCCTransitionFlipX(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSceneOriented(engine, className)
{
}

QtScriptCCTransitionFlipX::QtScriptCCTransitionFlipX(QScriptEngine *engine)
	: QtScriptCCTransitionFlipX(engine, "TransitionFlipX")
{
}

void QtScriptCCTransitionFlipX::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSceneOriented *>());
	auto ctor = RegisterT<CCTransitionFlipX, QtScriptCCTransitionFlipX>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFlipX::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionFlipX::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFlipX::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionFlipX::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFlipX::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFlipX::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFlipX::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFlipX::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFlipX();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFlipX constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFlipY::QtScriptCCTransitionFlipY(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSceneOriented(engine, className)
{
}

QtScriptCCTransitionFlipY::QtScriptCCTransitionFlipY(QScriptEngine *engine)
	: QtScriptCCTransitionFlipY(engine, "TransitionFlipY")
{
}

void QtScriptCCTransitionFlipY::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSceneOriented *>());
	auto ctor = RegisterT<CCTransitionFlipY, QtScriptCCTransitionFlipY>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFlipY::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionFlipY::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFlipY::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionFlipY::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFlipY::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFlipY::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFlipY::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFlipY::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFlipY();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFlipY constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFlipAngular::QtScriptCCTransitionFlipAngular(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSceneOriented(engine, className)
{
}

QtScriptCCTransitionFlipAngular::QtScriptCCTransitionFlipAngular(QScriptEngine *engine)
	: QtScriptCCTransitionFlipAngular(engine, "TransitionFlipAngular")
{
}

void QtScriptCCTransitionFlipAngular::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSceneOriented *>());
	auto ctor = RegisterT<CCTransitionFlipAngular, QtScriptCCTransitionFlipAngular>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFlipAngular::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionFlipAngular::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFlipAngular::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionFlipAngular::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFlipAngular::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFlipAngular::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFlipAngular::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFlipAngular::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFlipAngular();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFlipAngular constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionZoomFlipX::QtScriptCCTransitionZoomFlipX(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSceneOriented(engine, className)
{
}

QtScriptCCTransitionZoomFlipX::QtScriptCCTransitionZoomFlipX(QScriptEngine *engine)
	: QtScriptCCTransitionZoomFlipX(engine, "TransitionZoomFlipX")
{
}

void QtScriptCCTransitionZoomFlipX::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSceneOriented *>());
	auto ctor = RegisterT<CCTransitionZoomFlipX, QtScriptCCTransitionZoomFlipX>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionZoomFlipX::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionZoomFlipX::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionZoomFlipX::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionZoomFlipX::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionZoomFlipX::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionZoomFlipX::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionZoomFlipX::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionZoomFlipX::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionZoomFlipX();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionZoomFlipX constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionZoomFlipY::QtScriptCCTransitionZoomFlipY(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSceneOriented(engine, className)
{
}

QtScriptCCTransitionZoomFlipY::QtScriptCCTransitionZoomFlipY(QScriptEngine *engine)
	: QtScriptCCTransitionZoomFlipY(engine, "TransitionZoomFlipY")
{
}

void QtScriptCCTransitionZoomFlipY::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSceneOriented *>());
	auto ctor = RegisterT<CCTransitionZoomFlipY, QtScriptCCTransitionZoomFlipY>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionZoomFlipY::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionZoomFlipY::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionZoomFlipY::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionZoomFlipY::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionZoomFlipY::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionZoomFlipY::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionZoomFlipY::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionZoomFlipY::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionZoomFlipY();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionZoomFlipY constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionZoomFlipAngular::QtScriptCCTransitionZoomFlipAngular(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSceneOriented(engine, className)
{
}

QtScriptCCTransitionZoomFlipAngular::QtScriptCCTransitionZoomFlipAngular(QScriptEngine *engine)
	: QtScriptCCTransitionZoomFlipAngular(engine, "TransitionZoomFlipAngular")
{
}

void QtScriptCCTransitionZoomFlipAngular::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSceneOriented *>());
	auto ctor = RegisterT<CCTransitionZoomFlipAngular, QtScriptCCTransitionZoomFlipAngular>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionZoomFlipAngular::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionZoomFlipAngular::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionZoomFlipAngular::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::tOrientation(tmp_2);
			return __e->toScriptValue(CCTransitionZoomFlipAngular::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionZoomFlipAngular::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionZoomFlipAngular::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionZoomFlipAngular::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionZoomFlipAngular::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionZoomFlipAngular();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionZoomFlipAngular constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFade::QtScriptCCTransitionFade(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionFade::QtScriptCCTransitionFade(QScriptEngine *engine)
	: QtScriptCCTransitionFade(engine, "TransitionFade")
{
}

void QtScriptCCTransitionFade::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionFade, QtScriptCCTransitionFade>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFade::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCTransitionFade::initWithDuration(float t, cocos2d::CCScene* scene, const cocos2d::_ccColor3B& color)
{
	auto __o = this->thiz<CCTransitionFade *>();
	if (__o)
	{
		return __o->initWithDuration(t, scene, color);
	}
	return false;
}

QScriptValue QtScriptCCTransitionFade::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFade::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<cocos2d::_ccColor3B>(context->argument(2));
			return __e->toScriptValue(CCTransitionFade::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFade::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFade::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFade::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFade::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFade();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFade constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionCrossFade::QtScriptCCTransitionCrossFade(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionCrossFade::QtScriptCCTransitionCrossFade(QScriptEngine *engine)
	: QtScriptCCTransitionCrossFade(engine, "TransitionCrossFade")
{
}

void QtScriptCCTransitionCrossFade::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionCrossFade, QtScriptCCTransitionCrossFade>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionCrossFade::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionCrossFade::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionCrossFade::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionCrossFade::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionCrossFade::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionCrossFade::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionCrossFade::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionCrossFade();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionCrossFade constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionTurnOffTiles::QtScriptCCTransitionTurnOffTiles(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionTurnOffTiles::QtScriptCCTransitionTurnOffTiles(QScriptEngine *engine)
	: QtScriptCCTransitionTurnOffTiles(engine, "TransitionTurnOffTiles")
{
}

void QtScriptCCTransitionTurnOffTiles::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionTurnOffTiles, QtScriptCCTransitionTurnOffTiles>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionTurnOffTiles::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionTurnOffTiles::easeActionWithAction(cocos2d::CCActionInterval* action)
{
	auto __o = this->thiz<CCTransitionTurnOffTiles *>();
	if (__o)
	{
		return __o->easeActionWithAction(action);
	}
	return nullptr;
}

QScriptValue QtScriptCCTransitionTurnOffTiles::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionTurnOffTiles::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionTurnOffTiles::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionTurnOffTiles::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionTurnOffTiles::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionTurnOffTiles::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionTurnOffTiles();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionTurnOffTiles constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSplitCols::QtScriptCCTransitionSplitCols(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionSplitCols::QtScriptCCTransitionSplitCols(QScriptEngine *engine)
	: QtScriptCCTransitionSplitCols(engine, "TransitionSplitCols")
{
}

void QtScriptCCTransitionSplitCols::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionSplitCols, QtScriptCCTransitionSplitCols>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSplitCols::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionSplitCols::action()
{
	auto __o = this->thiz<CCTransitionSplitCols *>();
	if (__o)
	{
		return __o->action();
	}
	return nullptr;
}

cocos2d::CCActionInterval* QtScriptCCTransitionSplitCols::easeActionWithAction(cocos2d::CCActionInterval* action)
{
	auto __o = this->thiz<CCTransitionSplitCols *>();
	if (__o)
	{
		return __o->easeActionWithAction(action);
	}
	return nullptr;
}

QScriptValue QtScriptCCTransitionSplitCols::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionSplitCols::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSplitCols::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSplitCols::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSplitCols::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSplitCols::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSplitCols();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSplitCols constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionSplitRows::QtScriptCCTransitionSplitRows(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionSplitCols(engine, className)
{
}

QtScriptCCTransitionSplitRows::QtScriptCCTransitionSplitRows(QScriptEngine *engine)
	: QtScriptCCTransitionSplitRows(engine, "TransitionSplitRows")
{
}

void QtScriptCCTransitionSplitRows::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionSplitCols *>());
	auto ctor = RegisterT<CCTransitionSplitRows, QtScriptCCTransitionSplitRows>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionSplitRows::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionSplitRows::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionSplitRows::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSplitRows::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionSplitRows::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionSplitRows::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionSplitRows::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionSplitRows();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionSplitRows constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFadeTR::QtScriptCCTransitionFadeTR(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionFadeTR::QtScriptCCTransitionFadeTR(QScriptEngine *engine)
	: QtScriptCCTransitionFadeTR(engine, "TransitionFadeTR")
{
}

void QtScriptCCTransitionFadeTR::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionFadeTR, QtScriptCCTransitionFadeTR>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFadeTR::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionFadeTR::easeActionWithAction(cocos2d::CCActionInterval* action)
{
	auto __o = this->thiz<CCTransitionFadeTR *>();
	if (__o)
	{
		return __o->easeActionWithAction(action);
	}
	return nullptr;
}

cocos2d::CCActionInterval* QtScriptCCTransitionFadeTR::actionWithSize(const cocos2d::CCSize& size)
{
	auto __o = this->thiz<CCTransitionFadeTR *>();
	if (__o)
	{
		return __o->actionWithSize(size);
	}
	return nullptr;
}

QScriptValue QtScriptCCTransitionFadeTR::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFadeTR::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeTR::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFadeTR::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFadeTR::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFadeTR::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFadeTR();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeTR constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFadeBL::QtScriptCCTransitionFadeBL(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionFadeTR(engine, className)
{
}

QtScriptCCTransitionFadeBL::QtScriptCCTransitionFadeBL(QScriptEngine *engine)
	: QtScriptCCTransitionFadeBL(engine, "TransitionFadeBL")
{
}

void QtScriptCCTransitionFadeBL::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionFadeTR *>());
	auto ctor = RegisterT<CCTransitionFadeBL, QtScriptCCTransitionFadeBL>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFadeBL::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionFadeBL::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFadeBL::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeBL::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFadeBL::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFadeBL::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFadeBL::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFadeBL();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeBL constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFadeUp::QtScriptCCTransitionFadeUp(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionFadeTR(engine, className)
{
}

QtScriptCCTransitionFadeUp::QtScriptCCTransitionFadeUp(QScriptEngine *engine)
	: QtScriptCCTransitionFadeUp(engine, "TransitionFadeUp")
{
}

void QtScriptCCTransitionFadeUp::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionFadeTR *>());
	auto ctor = RegisterT<CCTransitionFadeUp, QtScriptCCTransitionFadeUp>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFadeUp::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionFadeUp::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFadeUp::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeUp::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFadeUp::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFadeUp::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFadeUp::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFadeUp();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeUp constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionFadeDown::QtScriptCCTransitionFadeDown(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionFadeTR(engine, className)
{
}

QtScriptCCTransitionFadeDown::QtScriptCCTransitionFadeDown(QScriptEngine *engine)
	: QtScriptCCTransitionFadeDown(engine, "TransitionFadeDown")
{
}

void QtScriptCCTransitionFadeDown::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionFadeTR *>());
	auto ctor = RegisterT<CCTransitionFadeDown, QtScriptCCTransitionFadeDown>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionFadeDown::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionFadeDown::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionFadeDown::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeDown::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionFadeDown::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionFadeDown::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionFadeDown::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionFadeDown();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionFadeDown constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionPageTurn::QtScriptCCTransitionPageTurn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionPageTurn::QtScriptCCTransitionPageTurn(QScriptEngine *engine)
	: QtScriptCCTransitionPageTurn(engine, "TransitionPageTurn")
{
}

void QtScriptCCTransitionPageTurn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionPageTurn, QtScriptCCTransitionPageTurn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionPageTurn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::CCActionInterval* QtScriptCCTransitionPageTurn::actionWithSize(const cocos2d::CCSize& vector)
{
	auto __o = this->thiz<CCTransitionPageTurn *>();
	if (__o)
	{
		return __o->actionWithSize(vector);
	}
	return nullptr;
}

bool QtScriptCCTransitionPageTurn::initWithDuration(float t, cocos2d::CCScene* scene, bool backwards)
{
	auto __o = this->thiz<CCTransitionPageTurn *>();
	if (__o)
	{
		return __o->initWithDuration(t, scene, backwards);
	}
	return false;
}

QScriptValue QtScriptCCTransitionPageTurn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			return __e->toScriptValue(CCTransitionPageTurn::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionPageTurn::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionPageTurn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionPageTurn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionPageTurn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionPageTurn();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionPageTurn constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgress::QtScriptCCTransitionProgress(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionScene(engine, className)
{
}

QtScriptCCTransitionProgress::QtScriptCCTransitionProgress(QScriptEngine *engine)
	: QtScriptCCTransitionProgress(engine, "TransitionProgress")
{
}

void QtScriptCCTransitionProgress::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionScene *>());
	auto ctor = RegisterT<CCTransitionProgress, QtScriptCCTransitionProgress>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgress::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCTransitionProgress::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgress::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgress::create");
	return __e->uncaughtException();
}

int QtScriptCCTransitionProgress::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgress::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgress::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTransitionProgress();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgress constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgressRadialCCW::QtScriptCCTransitionProgressRadialCCW(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionProgress(engine, className)
{
}

QtScriptCCTransitionProgressRadialCCW::QtScriptCCTransitionProgressRadialCCW(QScriptEngine *engine)
	: QtScriptCCTransitionProgressRadialCCW(engine, "TransitionProgressRadialCCW")
{
}

void QtScriptCCTransitionProgressRadialCCW::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionProgress *>());
	auto ctor = RegisterT<CCTransitionProgressRadialCCW, QtScriptCCTransitionProgressRadialCCW>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgressRadialCCW::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTransitionProgressRadialCCW::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgressRadialCCW::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgressRadialCCW::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTransitionProgressRadialCCW;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTransitionProgressRadialCCW constructor");
	return false;
}

QScriptValue QtScriptCCTransitionProgressRadialCCW::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgressRadialCCW::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgressRadialCCW::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgressRadialCW::QtScriptCCTransitionProgressRadialCW(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionProgress(engine, className)
{
}

QtScriptCCTransitionProgressRadialCW::QtScriptCCTransitionProgressRadialCW(QScriptEngine *engine)
	: QtScriptCCTransitionProgressRadialCW(engine, "TransitionProgressRadialCW")
{
}

void QtScriptCCTransitionProgressRadialCW::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionProgress *>());
	auto ctor = RegisterT<CCTransitionProgressRadialCW, QtScriptCCTransitionProgressRadialCW>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgressRadialCW::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTransitionProgressRadialCW::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgressRadialCW::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgressRadialCW::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTransitionProgressRadialCW;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTransitionProgressRadialCW constructor");
	return false;
}

QScriptValue QtScriptCCTransitionProgressRadialCW::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgressRadialCW::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgressRadialCW::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgressHorizontal::QtScriptCCTransitionProgressHorizontal(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionProgress(engine, className)
{
}

QtScriptCCTransitionProgressHorizontal::QtScriptCCTransitionProgressHorizontal(QScriptEngine *engine)
	: QtScriptCCTransitionProgressHorizontal(engine, "TransitionProgressHorizontal")
{
}

void QtScriptCCTransitionProgressHorizontal::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionProgress *>());
	auto ctor = RegisterT<CCTransitionProgressHorizontal, QtScriptCCTransitionProgressHorizontal>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgressHorizontal::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTransitionProgressHorizontal::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgressHorizontal::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgressHorizontal::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTransitionProgressHorizontal;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTransitionProgressHorizontal constructor");
	return false;
}

QScriptValue QtScriptCCTransitionProgressHorizontal::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgressHorizontal::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgressHorizontal::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgressVertical::QtScriptCCTransitionProgressVertical(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionProgress(engine, className)
{
}

QtScriptCCTransitionProgressVertical::QtScriptCCTransitionProgressVertical(QScriptEngine *engine)
	: QtScriptCCTransitionProgressVertical(engine, "TransitionProgressVertical")
{
}

void QtScriptCCTransitionProgressVertical::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionProgress *>());
	auto ctor = RegisterT<CCTransitionProgressVertical, QtScriptCCTransitionProgressVertical>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgressVertical::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTransitionProgressVertical::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgressVertical::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgressVertical::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTransitionProgressVertical;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTransitionProgressVertical constructor");
	return false;
}

QScriptValue QtScriptCCTransitionProgressVertical::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgressVertical::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgressVertical::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgressInOut::QtScriptCCTransitionProgressInOut(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionProgress(engine, className)
{
}

QtScriptCCTransitionProgressInOut::QtScriptCCTransitionProgressInOut(QScriptEngine *engine)
	: QtScriptCCTransitionProgressInOut(engine, "TransitionProgressInOut")
{
}

void QtScriptCCTransitionProgressInOut::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionProgress *>());
	auto ctor = RegisterT<CCTransitionProgressInOut, QtScriptCCTransitionProgressInOut>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgressInOut::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTransitionProgressInOut::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgressInOut::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgressInOut::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTransitionProgressInOut;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTransitionProgressInOut constructor");
	return false;
}

QScriptValue QtScriptCCTransitionProgressInOut::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgressInOut::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgressInOut::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTransitionProgressOutIn::QtScriptCCTransitionProgressOutIn(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTransitionProgress(engine, className)
{
}

QtScriptCCTransitionProgressOutIn::QtScriptCCTransitionProgressOutIn(QScriptEngine *engine)
	: QtScriptCCTransitionProgressOutIn(engine, "TransitionProgressOutIn")
{
}

void QtScriptCCTransitionProgressOutIn::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTransitionProgress *>());
	auto ctor = RegisterT<CCTransitionProgressOutIn, QtScriptCCTransitionProgressOutIn>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTransitionProgressOutIn::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTransitionProgressOutIn::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTransitionProgressOutIn::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTransitionProgressOutIn::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTransitionProgressOutIn;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTransitionProgressOutIn constructor");
	return false;
}

QScriptValue QtScriptCCTransitionProgressOutIn::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCScene*>(context->argument(1));
			return __e->toScriptValue(CCTransitionProgressOutIn::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTransitionProgressOutIn::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItem::QtScriptCCMenuItem(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNodeRGBA(engine, className)
{
}

QtScriptCCMenuItem::QtScriptCCMenuItem(QScriptEngine *engine)
	: QtScriptCCMenuItem(engine, "MenuItem")
{
}

void QtScriptCCMenuItem::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNodeRGBA *>());
	auto ctor = RegisterT<CCMenuItem, QtScriptCCMenuItem>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItem::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCMenuItem::setEnabled(bool value)
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		__o->setEnabled(value);
	}
}

void QtScriptCCMenuItem::activate()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		__o->activate();
	}
}

bool QtScriptCCMenuItem::isEnabled()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		return __o->isEnabled();
	}
	return false;
}

void QtScriptCCMenuItem::selected()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		__o->selected();
	}
}

void QtScriptCCMenuItem::registerTapHandler(const QScriptValue& arg0)
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		__o->registerScriptTapHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0));
	}
}

bool QtScriptCCMenuItem::isSelected()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		return __o->isSelected();
	}
	return false;
}

void QtScriptCCMenuItem::unregisterTapHandler()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		__o->unregisterScriptTapHandler();
	}
}

void QtScriptCCMenuItem::unselected()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		__o->unselected();
	}
}

cocos2d::CCRect QtScriptCCMenuItem::rect()
{
	auto __o = this->thiz<CCMenuItem *>();
	if (__o)
	{
		return __o->rect();
	}
	return cocos2d::CCRect();
}

QScriptValue QtScriptCCMenuItem::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCMenuItem::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItem::create");
	return __e->uncaughtException();
}

int QtScriptCCMenuItem::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItem::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItem::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItem();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItem constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItemLabel::QtScriptCCMenuItemLabel(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMenuItem(engine, className)
{
}

QtScriptCCMenuItemLabel::QtScriptCCMenuItemLabel(QScriptEngine *engine)
	: QtScriptCCMenuItemLabel(engine, "MenuItemLabel")
{
}

void QtScriptCCMenuItemLabel::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMenuItem *>());
	auto ctor = RegisterT<CCMenuItemLabel, QtScriptCCMenuItemLabel>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemLabel::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

cocos2d::_ccColor3B QtScriptCCMenuItemLabel::getDisabledColor()
{
	auto __o = this->thiz<CCMenuItemLabel *>();
	if (__o)
	{
		return __o->getDisabledColor();
	}
	return cocos2d::_ccColor3B();
}

void QtScriptCCMenuItemLabel::setLabel(cocos2d::CCNode* var)
{
	auto __o = this->thiz<CCMenuItemLabel *>();
	if (__o)
	{
		__o->setLabel(var);
	}
}

void QtScriptCCMenuItemLabel::setDisabledColor(const cocos2d::_ccColor3B& var)
{
	auto __o = this->thiz<CCMenuItemLabel *>();
	if (__o)
	{
		__o->setDisabledColor(var);
	}
}

cocos2d::CCNode* QtScriptCCMenuItemLabel::getLabel()
{
	auto __o = this->thiz<CCMenuItemLabel *>();
	if (__o)
	{
		return __o->getLabel();
	}
	return nullptr;
}

void QtScriptCCMenuItemLabel::setString(const QByteArray& label)
{
	auto __o = this->thiz<CCMenuItemLabel *>();
	if (__o)
	{
		__o->setString(label.data());
	}
}

QScriptValue QtScriptCCMenuItemLabel::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			return __e->toScriptValue(CCMenuItemLabel::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemLabel::create");
	return __e->uncaughtException();
}

int QtScriptCCMenuItemLabel::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItemLabel::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItemLabel::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItemLabel();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemLabel constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItemAtlasFont::QtScriptCCMenuItemAtlasFont(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMenuItemLabel(engine, className)
{
}

QtScriptCCMenuItemAtlasFont::QtScriptCCMenuItemAtlasFont(QScriptEngine *engine)
	: QtScriptCCMenuItemAtlasFont(engine, "MenuItemAtlasFont")
{
}

void QtScriptCCMenuItemAtlasFont::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMenuItemLabel *>());
	auto ctor = RegisterT<CCMenuItemAtlasFont, QtScriptCCMenuItemAtlasFont>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemAtlasFont::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCMenuItemAtlasFont::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 5, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 5:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<int>(context->argument(3));
			auto arg4 = qscriptvalue_cast<char>(context->argument(4));
			return __e->toScriptValue(CCMenuItemAtlasFont::create(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemAtlasFont::create");
	return __e->uncaughtException();
}

int QtScriptCCMenuItemAtlasFont::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItemAtlasFont::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItemAtlasFont::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItemAtlasFont();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemAtlasFont constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItemFont::QtScriptCCMenuItemFont(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMenuItemLabel(engine, className)
{
}

QtScriptCCMenuItemFont::QtScriptCCMenuItemFont(QScriptEngine *engine)
	: QtScriptCCMenuItemFont(engine, "MenuItemFont")
{
}

void QtScriptCCMenuItemFont::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMenuItemLabel *>());
	auto ctor = RegisterT<CCMenuItemFont, QtScriptCCMenuItemFont>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("setFontName", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemFont::setFontName)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("fontName", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemFont::fontName)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("fontSize", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemFont::fontSize)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemFont::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("setFontSize", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemFont::setFontSize)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

unsigned int QtScriptCCMenuItemFont::fontSizeObj()
{
	auto __o = this->thiz<CCMenuItemFont *>();
	if (__o)
	{
		return __o->fontSizeObj();
	}
	return static_cast<unsigned int>(0);
}

QByteArray QtScriptCCMenuItemFont::fontNameObj()
{
	auto __o = this->thiz<CCMenuItemFont *>();
	if (__o)
	{
		return QByteArray(__o->fontNameObj());
	}
	return QByteArray();
}

void QtScriptCCMenuItemFont::setFontSizeObj(unsigned int s)
{
	auto __o = this->thiz<CCMenuItemFont *>();
	if (__o)
	{
		__o->setFontSizeObj(s);
	}
}

void QtScriptCCMenuItemFont::setFontNameObj(const QByteArray& name)
{
	auto __o = this->thiz<CCMenuItemFont *>();
	if (__o)
	{
		__o->setFontNameObj(name.data());
	}
}

QScriptValue QtScriptCCMenuItemFont::setFontName(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			CCMenuItemFont::setFontName(arg0);
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemFont::setFontName");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCMenuItemFont::fontName(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(QByteArray(CCMenuItemFont::fontName()));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemFont::fontName");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCMenuItemFont::fontSize(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCMenuItemFont::fontSize());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemFont::fontSize");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCMenuItemFont::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCMenuItemFont::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemFont::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCMenuItemFont::setFontSize(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			CCMenuItemFont::setFontSize(arg0);
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemFont::setFontSize");
	return __e->uncaughtException();
}

int QtScriptCCMenuItemFont::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItemFont::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItemFont::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItemFont();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemFont constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItemSprite::QtScriptCCMenuItemSprite(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMenuItem(engine, className)
{
}

QtScriptCCMenuItemSprite::QtScriptCCMenuItemSprite(QScriptEngine *engine)
	: QtScriptCCMenuItemSprite(engine, "MenuItemSprite")
{
}

void QtScriptCCMenuItemSprite::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMenuItem *>());
	auto ctor = RegisterT<CCMenuItemSprite, QtScriptCCMenuItemSprite>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemSprite::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCMenuItemSprite::setNormalImage(cocos2d::CCNode* var)
{
	auto __o = this->thiz<CCMenuItemSprite *>();
	if (__o)
	{
		__o->setNormalImage(var);
	}
}

void QtScriptCCMenuItemSprite::setDisabledImage(cocos2d::CCNode* var)
{
	auto __o = this->thiz<CCMenuItemSprite *>();
	if (__o)
	{
		__o->setDisabledImage(var);
	}
}

void QtScriptCCMenuItemSprite::setSelectedImage(cocos2d::CCNode* var)
{
	auto __o = this->thiz<CCMenuItemSprite *>();
	if (__o)
	{
		__o->setSelectedImage(var);
	}
}

cocos2d::CCNode* QtScriptCCMenuItemSprite::getDisabledImage()
{
	auto __o = this->thiz<CCMenuItemSprite *>();
	if (__o)
	{
		return __o->getDisabledImage();
	}
	return nullptr;
}

cocos2d::CCNode* QtScriptCCMenuItemSprite::getSelectedImage()
{
	auto __o = this->thiz<CCMenuItemSprite *>();
	if (__o)
	{
		return __o->getSelectedImage();
	}
	return nullptr;
}

cocos2d::CCNode* QtScriptCCMenuItemSprite::getNormalImage()
{
	auto __o = this->thiz<CCMenuItemSprite *>();
	if (__o)
	{
		return __o->getNormalImage();
	}
	return nullptr;
}

QScriptValue QtScriptCCMenuItemSprite::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(1));
			return __e->toScriptValue(CCMenuItemSprite::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(1));
			auto arg2 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(2));
			return __e->toScriptValue(CCMenuItemSprite::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemSprite::create");
	return __e->uncaughtException();
}

int QtScriptCCMenuItemSprite::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItemSprite::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItemSprite::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItemSprite();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemSprite constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItemImage::QtScriptCCMenuItemImage(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMenuItemSprite(engine, className)
{
}

QtScriptCCMenuItemImage::QtScriptCCMenuItemImage(QScriptEngine *engine)
	: QtScriptCCMenuItemImage(engine, "MenuItemImage")
{
}

void QtScriptCCMenuItemImage::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMenuItemSprite *>());
	auto ctor = RegisterT<CCMenuItemImage, QtScriptCCMenuItemImage>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemImage::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCMenuItemImage::setDisabledSpriteFrame(cocos2d::CCSpriteFrame* frame)
{
	auto __o = this->thiz<CCMenuItemImage *>();
	if (__o)
	{
		__o->setDisabledSpriteFrame(frame);
	}
}

void QtScriptCCMenuItemImage::setSelectedSpriteFrame(cocos2d::CCSpriteFrame* frame)
{
	auto __o = this->thiz<CCMenuItemImage *>();
	if (__o)
	{
		__o->setSelectedSpriteFrame(frame);
	}
}

void QtScriptCCMenuItemImage::setNormalSpriteFrame(cocos2d::CCSpriteFrame* frame)
{
	auto __o = this->thiz<CCMenuItemImage *>();
	if (__o)
	{
		__o->setNormalSpriteFrame(frame);
	}
}

QScriptValue QtScriptCCMenuItemImage::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCMenuItemImage::create());
		}
		case 1:
		{
			break;
		}
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			return __e->toScriptValue(CCMenuItemImage::create(arg0, arg1));
		}
		case 3:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto tmp_2 = qscriptvalue_cast<QByteArray>(context->argument(2));
			auto arg2 = tmp_2.data();
			return __e->toScriptValue(CCMenuItemImage::create(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemImage::create");
	return __e->uncaughtException();
}

int QtScriptCCMenuItemImage::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItemImage::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItemImage::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItemImage();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemImage constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenuItemToggle::QtScriptCCMenuItemToggle(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCMenuItem(engine, className)
{
}

QtScriptCCMenuItemToggle::QtScriptCCMenuItemToggle(QScriptEngine *engine)
	: QtScriptCCMenuItemToggle(engine, "MenuItemToggle")
{
}

void QtScriptCCMenuItemToggle::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCMenuItem *>());
	auto ctor = RegisterT<CCMenuItemToggle, QtScriptCCMenuItemToggle>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenuItemToggle::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCMenuItemToggle::setSubItems(cocos2d::CCArray* var)
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		__o->setSubItems(var);
	}
}

bool QtScriptCCMenuItemToggle::initWithItem(cocos2d::CCMenuItem* item)
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		return __o->initWithItem(item);
	}
	return false;
}

void QtScriptCCMenuItemToggle::setSelectedIndex(unsigned int var)
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		__o->setSelectedIndex(var);
	}
}

unsigned int QtScriptCCMenuItemToggle::getSelectedIndex()
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		return __o->getSelectedIndex();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCMenuItemToggle::addSubItem(cocos2d::CCMenuItem* item)
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		__o->addSubItem(item);
	}
}

cocos2d::CCMenuItem* QtScriptCCMenuItemToggle::selectedItem()
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		return __o->selectedItem();
	}
	return nullptr;
}

cocos2d::CCArray* QtScriptCCMenuItemToggle::getSubItems()
{
	auto __o = this->thiz<CCMenuItemToggle *>();
	if (__o)
	{
		return __o->getSubItems();
	}
	return nullptr;
}

QScriptValue QtScriptCCMenuItemToggle::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCMenuItemToggle::create());
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCMenuItem*>(context->argument(0));
			return __e->toScriptValue(CCMenuItemToggle::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemToggle::create");
	return __e->uncaughtException();
}

int QtScriptCCMenuItemToggle::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenuItemToggle::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenuItemToggle::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenuItemToggle();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenuItemToggle constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMenu::QtScriptCCMenu(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCLayerRGBA(engine, className)
{
}

QtScriptCCMenu::QtScriptCCMenu(QScriptEngine *engine)
	: QtScriptCCMenu(engine, "Menu")
{
}

void QtScriptCCMenu::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCLayerRGBA *>());
	auto ctor = RegisterT<CCMenu, QtScriptCCMenu>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenu::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithArray", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenu::createWithArray)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithItem", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMenu::createWithItem)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCMenu::initWithArray(cocos2d::CCArray* pArrayOfItems)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		return __o->initWithArray(pArrayOfItems);
	}
	return false;
}

void QtScriptCCMenu::setEnabled(bool value)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->setEnabled(value);
	}
}

void QtScriptCCMenu::alignItemsVertically()
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsVertically();
	}
}

bool QtScriptCCMenu::isEnabled()
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		return __o->isEnabled();
	}
	return false;
}

void QtScriptCCMenu::alignItemsInRowsWithArray(cocos2d::CCArray* columns)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsInRowsWithArray(columns);
	}
}

void QtScriptCCMenu::setHandlerPriority(int newPriority)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->setHandlerPriority(newPriority);
	}
}

void QtScriptCCMenu::alignItemsHorizontally()
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsHorizontally();
	}
}

void QtScriptCCMenu::alignItemsHorizontallyWithPadding(float padding)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsHorizontallyWithPadding(padding);
	}
}

void QtScriptCCMenu::alignItemsInColumnsWithArray(cocos2d::CCArray* rows)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsInColumnsWithArray(rows);
	}
}

void QtScriptCCMenu::alignItemsVerticallyWithPadding(float padding)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsVerticallyWithPadding(padding);
	}
}

void QtScriptCCMenu::alignItemsInRows(unsigned int rows, QByteArray* args)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsInRows(rows, args->data());
	}
}

void QtScriptCCMenu::alignItemsInColumns(unsigned int columns, QByteArray* args)
{
	auto __o = this->thiz<CCMenu *>();
	if (__o)
	{
		__o->alignItemsInColumns(columns, args->data());
	}
}

QScriptValue QtScriptCCMenu::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCMenu::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenu::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCMenu::createWithArray(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCArray*>(context->argument(0));
			return __e->toScriptValue(CCMenu::createWithArray(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenu::createWithArray");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCMenu::createWithItem(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCMenuItem*>(context->argument(0));
			return __e->toScriptValue(CCMenu::createWithItem(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenu::createWithItem");
	return __e->uncaughtException();
}

int QtScriptCCMenu::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMenu::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMenu::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMenu();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMenu constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCClippingNode::QtScriptCCClippingNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCClippingNode::QtScriptCCClippingNode(QScriptEngine *engine)
	: QtScriptCCClippingNode(engine, "ClippingNode")
{
}

void QtScriptCCClippingNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCClippingNode, QtScriptCCClippingNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCClippingNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCClippingNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCClippingNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCClippingNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCClippingNode");
	return false;
}

bool QtScriptCCClippingNode::isInverted()
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		return __o->isInverted();
	}
	return false;
}

void QtScriptCCClippingNode::setInverted(bool bInverted)
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		__o->setInverted(bInverted);
	}
}

void QtScriptCCClippingNode::setStencil(cocos2d::CCNode* pStencil)
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		__o->setStencil(pStencil);
	}
}

float QtScriptCCClippingNode::getAlphaThreshold()
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		return __o->getAlphaThreshold();
	}
	return static_cast<float>(0);
}

bool QtScriptCCClippingNode::init(cocos2d::CCNode* pStencil)
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		return __o->init(pStencil);
	}
	return false;
}

cocos2d::CCNode* QtScriptCCClippingNode::getStencil()
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		return __o->getStencil();
	}
	return nullptr;
}

void QtScriptCCClippingNode::setAlphaThreshold(float fAlphaThreshold)
{
	auto __o = this->thiz<CCClippingNode *>();
	if (__o)
	{
		__o->setAlphaThreshold(fAlphaThreshold);
	}
}

QScriptValue QtScriptCCClippingNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCClippingNode::create());
		}
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCNode*>(context->argument(0));
			return __e->toScriptValue(CCClippingNode::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCClippingNode::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCMotionStreak::QtScriptCCMotionStreak(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNodeRGBA(engine, className)
{
}

QtScriptCCMotionStreak::QtScriptCCMotionStreak(QScriptEngine *engine)
	: QtScriptCCMotionStreak(engine, "MotionStreak")
{
}

void QtScriptCCMotionStreak::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNodeRGBA *>());
	auto ctor = RegisterT<CCMotionStreak, QtScriptCCMotionStreak>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCMotionStreak::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCMotionStreak::reset()
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		__o->reset();
	}
}

void QtScriptCCMotionStreak::setTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		__o->setTexture(texture);
	}
}

void QtScriptCCMotionStreak::setBlendFunc(cocos2d::_ccBlendFunc blendFunc)
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		__o->setBlendFunc(blendFunc);
	}
}

void QtScriptCCMotionStreak::tintWithColor(cocos2d::_ccColor3B colors)
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		__o->tintWithColor(colors);
	}
}

cocos2d::CCTexture2D* QtScriptCCMotionStreak::getTexture()
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

void QtScriptCCMotionStreak::setStartingPositionInitialized(bool bStartingPositionInitialized)
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		__o->setStartingPositionInitialized(bStartingPositionInitialized);
	}
}

cocos2d::_ccBlendFunc QtScriptCCMotionStreak::getBlendFunc()
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

bool QtScriptCCMotionStreak::initWithFade(float fade, float minSeg, float stroke, const cocos2d::_ccColor3B& color, const QByteArray& path)
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		return __o->initWithFade(fade, minSeg, stroke, color, path.data());
	}
	return false;
}

bool QtScriptCCMotionStreak::isFastMode()
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		return __o->isFastMode();
	}
	return false;
}

bool QtScriptCCMotionStreak::isStartingPositionInitialized()
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		return __o->isStartingPositionInitialized();
	}
	return false;
}

void QtScriptCCMotionStreak::setFastMode(bool bFastMode)
{
	auto __o = this->thiz<CCMotionStreak *>();
	if (__o)
	{
		__o->setFastMode(bFastMode);
	}
}

QScriptValue QtScriptCCMotionStreak::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 5, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 5:
		{
			auto arg0 = qscriptvalue_cast<float>(context->argument(0));
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			auto arg3 = qscriptvalue_cast<cocos2d::_ccColor3B>(context->argument(3));
			auto tmp_4 = qscriptvalue_cast<QByteArray>(context->argument(4));
			auto arg4 = tmp_4.data();
			return __e->toScriptValue(CCMotionStreak::create(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMotionStreak::create");
	return __e->uncaughtException();
}

int QtScriptCCMotionStreak::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCMotionStreak::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCMotionStreak::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCMotionStreak();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCMotionStreak constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCProgressTimer::QtScriptCCProgressTimer(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNodeRGBA(engine, className)
{
}

QtScriptCCProgressTimer::QtScriptCCProgressTimer(QScriptEngine *engine)
	: QtScriptCCProgressTimer(engine, "ProgressTimer")
{
}

void QtScriptCCProgressTimer::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNodeRGBA *>());
	auto ctor = RegisterT<CCProgressTimer, QtScriptCCProgressTimer>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCProgressTimer::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCProgressTimer::setReverseProgress(bool reverse)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setReverseProgress(reverse);
	}
}

bool QtScriptCCProgressTimer::isReverseDirection()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->isReverseDirection();
	}
	return false;
}

void QtScriptCCProgressTimer::setBarChangeRate(cocos2d::CCPoint var)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setBarChangeRate(var);
	}
}

void QtScriptCCProgressTimer::setAnchorPoint(cocos2d::CCPoint anchorPoint)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setAnchorPoint(anchorPoint);
	}
}

cocos2d::CCPoint QtScriptCCProgressTimer::getBarChangeRate()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->getBarChangeRate();
	}
	return cocos2d::CCPoint();
}

float QtScriptCCProgressTimer::getPercentage()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->getPercentage();
	}
	return static_cast<float>(0);
}

void QtScriptCCProgressTimer::setSprite(cocos2d::CCSprite* pSprite)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setSprite(pSprite);
	}
}

int QtScriptCCProgressTimer::getType()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return int(__o->getType());
	}
	return 0;
}

cocos2d::CCSprite* QtScriptCCProgressTimer::getSprite()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->getSprite();
	}
	return nullptr;
}

void QtScriptCCProgressTimer::setMidpoint(cocos2d::CCPoint var)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setMidpoint(var);
	}
}

cocos2d::CCPoint QtScriptCCProgressTimer::getMidpoint()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->getMidpoint();
	}
	return cocos2d::CCPoint();
}

cocos2d::_ccColor3B QtScriptCCProgressTimer::getColor()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->getColor();
	}
	return cocos2d::_ccColor3B();
}

unsigned char QtScriptCCProgressTimer::getOpacity()
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->getOpacity();
	}
	return static_cast<unsigned char>(0);
}

void QtScriptCCProgressTimer::setReverseDirection(bool value)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setReverseDirection(value);
	}
}

bool QtScriptCCProgressTimer::initWithSprite(cocos2d::CCSprite* sp)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		return __o->initWithSprite(sp);
	}
	return false;
}

void QtScriptCCProgressTimer::setPercentage(float fPercentage)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setPercentage(fPercentage);
	}
}

void QtScriptCCProgressTimer::setType(int type)
{
	auto __o = this->thiz<CCProgressTimer *>();
	if (__o)
	{
		__o->setType(cocos2d::CCProgressTimerType(type));
	}
}

QScriptValue QtScriptCCProgressTimer::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCSprite*>(context->argument(0));
			return __e->toScriptValue(CCProgressTimer::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCProgressTimer::create");
	return __e->uncaughtException();
}

int QtScriptCCProgressTimer::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCProgressTimer::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCProgressTimer::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCProgressTimer();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCProgressTimer constructor");
	}
	return ok;
}

bool QtScriptCCProgressTimer::_public_field_get_bReverseDirection() const
{
	auto object = thiz<CCProgressTimer *>();
	if (object)
	{
		return object->m_bReverseDirection;
	}
	return false;
}

void QtScriptCCProgressTimer::_public_field_set_bReverseDirection(const bool& value)
{
	auto object = thiz<CCProgressTimer *>();
	if (object)
	{
		object->m_bReverseDirection = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCRenderTexture::QtScriptCCRenderTexture(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCRenderTexture::QtScriptCCRenderTexture(QScriptEngine *engine)
	: QtScriptCCRenderTexture(engine, "RenderTexture")
{
}

void QtScriptCCRenderTexture::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCRenderTexture, QtScriptCCRenderTexture>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCRenderTexture::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCRenderTexture::clearStencil(int stencilValue)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->clearStencil(stencilValue);
	}
}

void QtScriptCCRenderTexture::listenToForeground(cocos2d::CCObject* obj)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->listenToForeground(obj);
	}
}

float QtScriptCCRenderTexture::getClearDepth()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->getClearDepth();
	}
	return static_cast<float>(0);
}

int QtScriptCCRenderTexture::getClearStencil()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->getClearStencil();
	}
	return 0;
}

void QtScriptCCRenderTexture::end()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->end();
	}
}

void QtScriptCCRenderTexture::setClearStencil(float fClearStencil)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->setClearStencil(fClearStencil);
	}
}

void QtScriptCCRenderTexture::setSprite(cocos2d::CCSprite* var)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->setSprite(var);
	}
}

cocos2d::CCSprite* QtScriptCCRenderTexture::getSprite()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->getSprite();
	}
	return nullptr;
}

bool QtScriptCCRenderTexture::isAutoDraw()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->isAutoDraw();
	}
	return false;
}

void QtScriptCCRenderTexture::setClearFlags(unsigned int uClearFlags)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->setClearFlags(uClearFlags);
	}
}

void QtScriptCCRenderTexture::begin()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->begin();
	}
}

bool QtScriptCCRenderTexture::saveToFile(const QByteArray& szFilePath)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->saveToFile(szFilePath.data());
	}
	return false;
}

bool QtScriptCCRenderTexture::saveToFile(const QByteArray& name, int format)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->saveToFile(name.data(), cocos2d::eImageFormat(format));
	}
	return false;
}

void QtScriptCCRenderTexture::setAutoDraw(bool bAutoDraw)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->setAutoDraw(bAutoDraw);
	}
}

void QtScriptCCRenderTexture::setClearColor(const cocos2d::_ccColor4F& clearColor)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->setClearColor(clearColor);
	}
}

void QtScriptCCRenderTexture::endToLua()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->endToLua();
	}
}

void QtScriptCCRenderTexture::beginWithClear(float r, float g, float b, float a)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->beginWithClear(r, g, b, a);
	}
}

void QtScriptCCRenderTexture::beginWithClear(float r, float g, float b, float a, float depthValue)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->beginWithClear(r, g, b, a, depthValue);
	}
}

void QtScriptCCRenderTexture::beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->beginWithClear(r, g, b, a, depthValue, stencilValue);
	}
}

void QtScriptCCRenderTexture::clearDepth(float depthValue)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->clearDepth(depthValue);
	}
}

cocos2d::_ccColor4F QtScriptCCRenderTexture::getClearColor()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->getClearColor();
	}
	return cocos2d::_ccColor4F();
}

void QtScriptCCRenderTexture::listenToBackground(cocos2d::CCObject* obj)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->listenToBackground(obj);
	}
}

void QtScriptCCRenderTexture::clear(float r, float g, float b, float a)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->clear(r, g, b, a);
	}
}

unsigned int QtScriptCCRenderTexture::getClearFlags()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->getClearFlags();
	}
	return static_cast<unsigned int>(0);
}

cocos2d::CCImage* QtScriptCCRenderTexture::newCCImage()
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->newCCImage();
	}
	return nullptr;
}

cocos2d::CCImage* QtScriptCCRenderTexture::newCCImage(bool flipImage)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->newCCImage(flipImage);
	}
	return nullptr;
}

void QtScriptCCRenderTexture::setClearDepth(float fClearDepth)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		__o->setClearDepth(fClearDepth);
	}
}

bool QtScriptCCRenderTexture::initWithWidthAndHeight(int w, int h, int eFormat)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->initWithWidthAndHeight(w, h, cocos2d::CCTexture2DPixelFormat(eFormat));
	}
	return false;
}

bool QtScriptCCRenderTexture::initWithWidthAndHeight(int w, int h, int eFormat, unsigned int uDepthStencilFormat)
{
	auto __o = this->thiz<CCRenderTexture *>();
	if (__o)
	{
		return __o->initWithWidthAndHeight(w, h, cocos2d::CCTexture2DPixelFormat(eFormat), uDepthStencilFormat);
	}
	return false;
}

QScriptValue QtScriptCCRenderTexture::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<int>(context->argument(0));
			auto arg1 = qscriptvalue_cast<int>(context->argument(1));
			return __e->toScriptValue(CCRenderTexture::create(arg0, arg1));
		}
		case 3:
		{
			auto arg0 = qscriptvalue_cast<int>(context->argument(0));
			auto arg1 = qscriptvalue_cast<int>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::CCTexture2DPixelFormat(tmp_2);
			return __e->toScriptValue(CCRenderTexture::create(arg0, arg1, arg2));
		}
		case 4:
		{
			auto arg0 = qscriptvalue_cast<int>(context->argument(0));
			auto arg1 = qscriptvalue_cast<int>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::CCTexture2DPixelFormat(tmp_2);
			auto arg3 = qscriptvalue_cast<unsigned int>(context->argument(3));
			return __e->toScriptValue(CCRenderTexture::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRenderTexture::create");
	return __e->uncaughtException();
}

int QtScriptCCRenderTexture::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCRenderTexture::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCRenderTexture::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCRenderTexture();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCRenderTexture constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleBatchNode::QtScriptCCParticleBatchNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCParticleBatchNode::QtScriptCCParticleBatchNode(QScriptEngine *engine)
	: QtScriptCCParticleBatchNode(engine, "ParticleBatchNode")
{
}

void QtScriptCCParticleBatchNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCParticleBatchNode, QtScriptCCParticleBatchNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleBatchNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTexture", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleBatchNode::createWithTexture)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCParticleBatchNode::setTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		__o->setTexture(texture);
	}
}

bool QtScriptCCParticleBatchNode::initWithFile(const QByteArray& fileImage, unsigned int capacity)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		return __o->initWithFile(fileImage.data(), capacity);
	}
	return false;
}

void QtScriptCCParticleBatchNode::disableParticle(unsigned int particleIndex)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		__o->disableParticle(particleIndex);
	}
}

cocos2d::CCTexture2D* QtScriptCCParticleBatchNode::getTexture()
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

void QtScriptCCParticleBatchNode::setTextureAtlas(cocos2d::CCTextureAtlas* var)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		__o->setTextureAtlas(var);
	}
}

void QtScriptCCParticleBatchNode::setBlendFunc(cocos2d::_ccBlendFunc blendFunc)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		__o->setBlendFunc(blendFunc);
	}
}

cocos2d::CCTextureAtlas* QtScriptCCParticleBatchNode::getTextureAtlas()
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		return __o->getTextureAtlas();
	}
	return nullptr;
}

cocos2d::_ccBlendFunc QtScriptCCParticleBatchNode::getBlendFunc()
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

void QtScriptCCParticleBatchNode::insertChild(cocos2d::CCParticleSystem* pSystem, unsigned int index)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		__o->insertChild(pSystem, index);
	}
}

void QtScriptCCParticleBatchNode::removeChildAtIndex(unsigned int index, bool doCleanup)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		__o->removeChildAtIndex(index, doCleanup);
	}
}

bool QtScriptCCParticleBatchNode::initWithTexture(cocos2d::CCTexture2D* tex, unsigned int capacity)
{
	auto __o = this->thiz<CCParticleBatchNode *>();
	if (__o)
	{
		return __o->initWithTexture(tex, capacity);
	}
	return false;
}

QScriptValue QtScriptCCParticleBatchNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCParticleBatchNode::create(arg0));
		}
		case 2:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCParticleBatchNode::create(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleBatchNode::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleBatchNode::createWithTexture(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			return __e->toScriptValue(CCParticleBatchNode::createWithTexture(arg0));
		}
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTexture2D*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<unsigned int>(context->argument(1));
			return __e->toScriptValue(CCParticleBatchNode::createWithTexture(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleBatchNode::createWithTexture");
	return __e->uncaughtException();
}

int QtScriptCCParticleBatchNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleBatchNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleBatchNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleBatchNode();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleBatchNode constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptsCCParticle_ModeA::QtScriptsCCParticle_ModeA(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<sCCParticle::ModeA, false>(engine, className)
{
}

QtScriptsCCParticle_ModeA::QtScriptsCCParticle_ModeA(QScriptEngine *engine)
	: QtScriptsCCParticle_ModeA(engine, "Particle_ModeA")
{
}

void QtScriptsCCParticle_ModeA::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<sCCParticle::ModeA, QtScriptsCCParticle_ModeA>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptsCCParticle_ModeA::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptsCCParticle_ModeA::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptsCCParticle_ModeA::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::sCCParticle::ModeA constructor");
	return false;
}

cocos2d::CCPoint QtScriptsCCParticle_ModeA::_public_field_get_dir() const
{
	auto object = thiz<sCCParticle::ModeA *>();
	if (object)
	{
		return object->dir;
	}
	return cocos2d::CCPoint();
}

void QtScriptsCCParticle_ModeA::_public_field_set_dir(const cocos2d::CCPoint& value)
{
	auto object = thiz<sCCParticle::ModeA *>();
	if (object)
	{
		object->dir = value;
	}
}

float QtScriptsCCParticle_ModeA::_public_field_get_radialAccel() const
{
	auto object = thiz<sCCParticle::ModeA *>();
	if (object)
	{
		return object->radialAccel;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle_ModeA::_public_field_set_radialAccel(float value)
{
	auto object = thiz<sCCParticle::ModeA *>();
	if (object)
	{
		object->radialAccel = value;
	}
}

float QtScriptsCCParticle_ModeA::_public_field_get_tangentialAccel() const
{
	auto object = thiz<sCCParticle::ModeA *>();
	if (object)
	{
		return object->tangentialAccel;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle_ModeA::_public_field_set_tangentialAccel(float value)
{
	auto object = thiz<sCCParticle::ModeA *>();
	if (object)
	{
		object->tangentialAccel = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptsCCParticle_ModeB::QtScriptsCCParticle_ModeB(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<sCCParticle::ModeB, false>(engine, className)
{
}

QtScriptsCCParticle_ModeB::QtScriptsCCParticle_ModeB(QScriptEngine *engine)
	: QtScriptsCCParticle_ModeB(engine, "Particle_ModeB")
{
}

void QtScriptsCCParticle_ModeB::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<sCCParticle::ModeB, QtScriptsCCParticle_ModeB>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptsCCParticle_ModeB::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptsCCParticle_ModeB::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptsCCParticle_ModeB::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::sCCParticle::ModeB constructor");
	return false;
}

float QtScriptsCCParticle_ModeB::_public_field_get_angle() const
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		return object->angle;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle_ModeB::_public_field_set_angle(float value)
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		object->angle = value;
	}
}

float QtScriptsCCParticle_ModeB::_public_field_get_degreesPerSecond() const
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		return object->degreesPerSecond;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle_ModeB::_public_field_set_degreesPerSecond(float value)
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		object->degreesPerSecond = value;
	}
}

float QtScriptsCCParticle_ModeB::_public_field_get_radius() const
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		return object->radius;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle_ModeB::_public_field_set_radius(float value)
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		object->radius = value;
	}
}

float QtScriptsCCParticle_ModeB::_public_field_get_deltaRadius() const
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		return object->deltaRadius;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle_ModeB::_public_field_set_deltaRadius(float value)
{
	auto object = thiz<sCCParticle::ModeB *>();
	if (object)
	{
		object->deltaRadius = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptsCCParticle::QtScriptsCCParticle(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<sCCParticle, false>(engine, className)
{
}

QtScriptsCCParticle::QtScriptsCCParticle(QScriptEngine *engine)
	: QtScriptsCCParticle(engine, "Particle")
{
}

void QtScriptsCCParticle::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<sCCParticle, QtScriptsCCParticle>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptsCCParticle::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptsCCParticle::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptsCCParticle::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::sCCParticle constructor");
	return false;
}

cocos2d::CCPoint QtScriptsCCParticle::_public_field_get_pos() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->pos;
	}
	return cocos2d::CCPoint();
}

void QtScriptsCCParticle::_public_field_set_pos(const cocos2d::CCPoint& value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->pos = value;
	}
}

cocos2d::CCPoint QtScriptsCCParticle::_public_field_get_startPos() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->startPos;
	}
	return cocos2d::CCPoint();
}

void QtScriptsCCParticle::_public_field_set_startPos(const cocos2d::CCPoint& value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->startPos = value;
	}
}

cocos2d::_ccColor4F QtScriptsCCParticle::_public_field_get_color() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->color;
	}
	return cocos2d::_ccColor4F();
}

void QtScriptsCCParticle::_public_field_set_color(const cocos2d::_ccColor4F& value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->color = value;
	}
}

cocos2d::_ccColor4F QtScriptsCCParticle::_public_field_get_deltaColor() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->deltaColor;
	}
	return cocos2d::_ccColor4F();
}

void QtScriptsCCParticle::_public_field_set_deltaColor(const cocos2d::_ccColor4F& value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->deltaColor = value;
	}
}

float QtScriptsCCParticle::_public_field_get_size() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->size;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle::_public_field_set_size(float value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->size = value;
	}
}

float QtScriptsCCParticle::_public_field_get_deltaSize() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->deltaSize;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle::_public_field_set_deltaSize(float value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->deltaSize = value;
	}
}

float QtScriptsCCParticle::_public_field_get_rotation() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->rotation;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle::_public_field_set_rotation(float value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->rotation = value;
	}
}

float QtScriptsCCParticle::_public_field_get_deltaRotation() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->deltaRotation;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle::_public_field_set_deltaRotation(float value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->deltaRotation = value;
	}
}

float QtScriptsCCParticle::_public_field_get_timeToLive() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->timeToLive;
	}
	return static_cast<float>(0);
}

void QtScriptsCCParticle::_public_field_set_timeToLive(float value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->timeToLive = value;
	}
}

unsigned int QtScriptsCCParticle::_public_field_get_atlasIndex() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->atlasIndex;
	}
	return static_cast<unsigned int>(0);
}

void QtScriptsCCParticle::_public_field_set_atlasIndex(unsigned int value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->atlasIndex = value;
	}
}

cocos2d::sCCParticle::ModeA QtScriptsCCParticle::_public_field_get_modeA() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->modeA;
	}
	return cocos2d::sCCParticle::ModeA();
}

void QtScriptsCCParticle::_public_field_set_modeA(const cocos2d::sCCParticle::ModeA& value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->modeA = value;
	}
}

cocos2d::sCCParticle::ModeB QtScriptsCCParticle::_public_field_get_modeB() const
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		return object->modeB;
	}
	return cocos2d::sCCParticle::ModeB();
}

void QtScriptsCCParticle::_public_field_set_modeB(const cocos2d::sCCParticle::ModeB& value)
{
	auto object = thiz<sCCParticle *>();
	if (object)
	{
		object->modeB = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleSystem::QtScriptCCParticleSystem(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCParticleSystem::QtScriptCCParticleSystem(QScriptEngine *engine)
	: QtScriptCCParticleSystem(engine, "ParticleSystem")
{
}

void QtScriptCCParticleSystem::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCParticleSystem, QtScriptCCParticleSystem>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSystem::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSystem::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

float QtScriptCCParticleSystem::getStartSizeVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartSizeVar();
	}
	return static_cast<float>(0);
}

cocos2d::CCTexture2D* QtScriptCCParticleSystem::getTexture()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getTexture();
	}
	return nullptr;
}

bool QtScriptCCParticleSystem::isFull()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->isFull();
	}
	return false;
}

cocos2d::CCParticleBatchNode* QtScriptCCParticleSystem::getBatchNode()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getBatchNode();
	}
	return nullptr;
}

cocos2d::_ccColor4F QtScriptCCParticleSystem::getStartColor()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartColor();
	}
	return cocos2d::_ccColor4F();
}

int QtScriptCCParticleSystem::getPositionType()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return int(__o->getPositionType());
	}
	return 0;
}

void QtScriptCCParticleSystem::setPosVar(const cocos2d::CCPoint& var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setPosVar(var);
	}
}

float QtScriptCCParticleSystem::getEndSpin()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndSpin();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setRotatePerSecondVar(float degrees)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setRotatePerSecondVar(degrees);
	}
}

float QtScriptCCParticleSystem::getStartSpinVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartSpinVar();
	}
	return static_cast<float>(0);
}

float QtScriptCCParticleSystem::getRadialAccelVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getRadialAccelVar();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::stopSystem()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->stopSystem();
	}
}

float QtScriptCCParticleSystem::getEndSizeVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndSizeVar();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setTangentialAccel(float t)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setTangentialAccel(t);
	}
}

float QtScriptCCParticleSystem::getRadialAccel()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getRadialAccel();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setStartRadius(float startRadius)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartRadius(startRadius);
	}
}

void QtScriptCCParticleSystem::setRotatePerSecond(float degrees)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setRotatePerSecond(degrees);
	}
}

void QtScriptCCParticleSystem::setEndSize(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndSize(var);
	}
}

cocos2d::CCPoint QtScriptCCParticleSystem::getGravity()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getGravity();
	}
	return cocos2d::CCPoint();
}

float QtScriptCCParticleSystem::getTangentialAccel()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getTangentialAccel();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setEndRadius(float endRadius)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndRadius(endRadius);
	}
}

float QtScriptCCParticleSystem::getAngle()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getAngle();
	}
	return static_cast<float>(0);
}

float QtScriptCCParticleSystem::getSpeed()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getSpeed();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setEndColor(const cocos2d::_ccColor4F& var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndColor(var);
	}
}

void QtScriptCCParticleSystem::setStartSpin(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartSpin(var);
	}
}

void QtScriptCCParticleSystem::setDuration(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setDuration(var);
	}
}

bool QtScriptCCParticleSystem::initWithTotalParticles(unsigned int numberOfParticles)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->initWithTotalParticles(numberOfParticles);
	}
	return false;
}

void QtScriptCCParticleSystem::setTexture(cocos2d::CCTexture2D* var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setTexture(var);
	}
}

cocos2d::CCPoint QtScriptCCParticleSystem::getPosVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getPosVar();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCParticleSystem::updateWithNoTime()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->updateWithNoTime();
	}
}

bool QtScriptCCParticleSystem::isBlendAdditive()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->isBlendAdditive();
	}
	return false;
}

float QtScriptCCParticleSystem::getAngleVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getAngleVar();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setPositionType(int var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setPositionType(cocos2d::tCCPositionType(var));
	}
}

float QtScriptCCParticleSystem::getEndRadius()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndRadius();
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCParticleSystem::getSourcePosition()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getSourcePosition();
	}
	return cocos2d::CCPoint();
}

void QtScriptCCParticleSystem::setLifeVar(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setLifeVar(var);
	}
}

void QtScriptCCParticleSystem::setTotalParticles(unsigned int var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setTotalParticles(var);
	}
}

void QtScriptCCParticleSystem::setEndColorVar(const cocos2d::_ccColor4F& var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndColorVar(var);
	}
}

void QtScriptCCParticleSystem::updateQuadWithParticle(cocos2d::sCCParticle* particle, const cocos2d::CCPoint& newPosition)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->updateQuadWithParticle(particle, newPosition);
	}
}

unsigned int QtScriptCCParticleSystem::getAtlasIndex()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getAtlasIndex();
	}
	return static_cast<unsigned int>(0);
}

float QtScriptCCParticleSystem::getStartSize()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartSize();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setStartSpinVar(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartSpinVar(var);
	}
}

void QtScriptCCParticleSystem::resetSystem()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->resetSystem();
	}
}

void QtScriptCCParticleSystem::setAtlasIndex(unsigned int var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setAtlasIndex(var);
	}
}

void QtScriptCCParticleSystem::setTangentialAccelVar(float t)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setTangentialAccelVar(t);
	}
}

void QtScriptCCParticleSystem::setEndRadiusVar(float endRadiusVar)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndRadiusVar(endRadiusVar);
	}
}

bool QtScriptCCParticleSystem::isActive()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->isActive();
	}
	return false;
}

void QtScriptCCParticleSystem::setRadialAccelVar(float t)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setRadialAccelVar(t);
	}
}

void QtScriptCCParticleSystem::setStartSize(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartSize(var);
	}
}

void QtScriptCCParticleSystem::setSpeed(float speed)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setSpeed(speed);
	}
}

float QtScriptCCParticleSystem::getStartSpin()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartSpin();
	}
	return static_cast<float>(0);
}

float QtScriptCCParticleSystem::getRotatePerSecond()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getRotatePerSecond();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::initParticle(cocos2d::sCCParticle* particle)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->initParticle(particle);
	}
}

void QtScriptCCParticleSystem::setEmitterMode(int var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEmitterMode(var);
	}
}

float QtScriptCCParticleSystem::getDuration()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getDuration();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setSourcePosition(const cocos2d::CCPoint& var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setSourcePosition(var);
	}
}

float QtScriptCCParticleSystem::getEndSpinVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndSpinVar();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setBlendAdditive(bool value)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setBlendAdditive(value);
	}
}

void QtScriptCCParticleSystem::setLife(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setLife(var);
	}
}

void QtScriptCCParticleSystem::setAngleVar(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setAngleVar(var);
	}
}

void QtScriptCCParticleSystem::setRotationIsDir(bool t)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setRotationIsDir(t);
	}
}

void QtScriptCCParticleSystem::setEndSizeVar(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndSizeVar(var);
	}
}

void QtScriptCCParticleSystem::setAngle(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setAngle(var);
	}
}

void QtScriptCCParticleSystem::setBatchNode(cocos2d::CCParticleBatchNode* var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setBatchNode(var);
	}
}

float QtScriptCCParticleSystem::getTangentialAccelVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getTangentialAccelVar();
	}
	return static_cast<float>(0);
}

int QtScriptCCParticleSystem::getEmitterMode()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEmitterMode();
	}
	return 0;
}

void QtScriptCCParticleSystem::setEndSpinVar(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndSpinVar(var);
	}
}

bool QtScriptCCParticleSystem::initWithFile(const QByteArray& plistFile)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->initWithFile(plistFile.data());
	}
	return false;
}

float QtScriptCCParticleSystem::getSpeedVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getSpeedVar();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setStartColor(const cocos2d::_ccColor4F& var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartColor(var);
	}
}

float QtScriptCCParticleSystem::getRotatePerSecondVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getRotatePerSecondVar();
	}
	return static_cast<float>(0);
}

float QtScriptCCParticleSystem::getEndSize()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndSize();
	}
	return static_cast<float>(0);
}

float QtScriptCCParticleSystem::getLife()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getLife();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setSpeedVar(float speed)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setSpeedVar(speed);
	}
}

void QtScriptCCParticleSystem::setAutoRemoveOnFinish(bool var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setAutoRemoveOnFinish(var);
	}
}

void QtScriptCCParticleSystem::setGravity(const cocos2d::CCPoint& g)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setGravity(g);
	}
}

void QtScriptCCParticleSystem::postStep()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->postStep();
	}
}

void QtScriptCCParticleSystem::setEmissionRate(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEmissionRate(var);
	}
}

cocos2d::_ccColor4F QtScriptCCParticleSystem::getEndColorVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndColorVar();
	}
	return cocos2d::_ccColor4F();
}

bool QtScriptCCParticleSystem::getRotationIsDir()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getRotationIsDir();
	}
	return false;
}

float QtScriptCCParticleSystem::getEmissionRate()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEmissionRate();
	}
	return static_cast<float>(0);
}

cocos2d::_ccColor4F QtScriptCCParticleSystem::getEndColor()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndColor();
	}
	return cocos2d::_ccColor4F();
}

float QtScriptCCParticleSystem::getLifeVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getLifeVar();
	}
	return static_cast<float>(0);
}

void QtScriptCCParticleSystem::setStartSizeVar(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartSizeVar(var);
	}
}

void QtScriptCCParticleSystem::setOpacityModifyRGB(bool var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setOpacityModifyRGB(var);
	}
}

bool QtScriptCCParticleSystem::addParticle()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->addParticle();
	}
	return false;
}

bool QtScriptCCParticleSystem::getOpacityModifyRGB()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getOpacityModifyRGB();
	}
	return false;
}

float QtScriptCCParticleSystem::getStartRadius()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartRadius();
	}
	return static_cast<float>(0);
}

unsigned int QtScriptCCParticleSystem::getParticleCount()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getParticleCount();
	}
	return static_cast<unsigned int>(0);
}

float QtScriptCCParticleSystem::getStartRadiusVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartRadiusVar();
	}
	return static_cast<float>(0);
}

cocos2d::_ccBlendFunc QtScriptCCParticleSystem::getBlendFunc()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getBlendFunc();
	}
	return cocos2d::_ccBlendFunc();
}

void QtScriptCCParticleSystem::setStartColorVar(const cocos2d::_ccColor4F& var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartColorVar(var);
	}
}

void QtScriptCCParticleSystem::setEndSpin(float var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setEndSpin(var);
	}
}

void QtScriptCCParticleSystem::setRadialAccel(float t)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setRadialAccel(t);
	}
}

bool QtScriptCCParticleSystem::initWithDictionary(cocos2d::CCDictionary* dictionary)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->initWithDictionary(dictionary);
	}
	return false;
}

bool QtScriptCCParticleSystem::initWithDictionary(cocos2d::CCDictionary* dictionary, const QByteArray& dirname)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->initWithDictionary(dictionary, dirname.data());
	}
	return false;
}

bool QtScriptCCParticleSystem::isAutoRemoveOnFinish()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->isAutoRemoveOnFinish();
	}
	return false;
}

unsigned int QtScriptCCParticleSystem::getTotalParticles()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getTotalParticles();
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCParticleSystem::setStartRadiusVar(float startRadiusVar)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setStartRadiusVar(startRadiusVar);
	}
}

void QtScriptCCParticleSystem::setBlendFunc(cocos2d::_ccBlendFunc var)
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		__o->setBlendFunc(var);
	}
}

float QtScriptCCParticleSystem::getEndRadiusVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getEndRadiusVar();
	}
	return static_cast<float>(0);
}

cocos2d::_ccColor4F QtScriptCCParticleSystem::getStartColorVar()
{
	auto __o = this->thiz<CCParticleSystem *>();
	if (__o)
	{
		return __o->getStartColorVar();
	}
	return cocos2d::_ccColor4F();
}

QScriptValue QtScriptCCParticleSystem::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCParticleSystem::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSystem::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleSystem::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleSystem::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSystem::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleSystem::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleSystem::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleSystem::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleSystem();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSystem constructor");
	}
	return ok;
}

bool QtScriptCCParticleSystem::_public_field_get_bTransformSystemDirty() const
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		return object->m_bTransformSystemDirty;
	}
	return false;
}

void QtScriptCCParticleSystem::_public_field_set_bTransformSystemDirty(const bool& value)
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		object->m_bTransformSystemDirty = value;
	}
}

unsigned int QtScriptCCParticleSystem::_public_field_get_uAllocatedParticles() const
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		return object->m_uAllocatedParticles;
	}
	return static_cast<unsigned int>(0);
}

void QtScriptCCParticleSystem::_public_field_set_uAllocatedParticles(unsigned int value)
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		object->m_uAllocatedParticles = value;
	}
}

bool QtScriptCCParticleSystem::_public_field_get_bIsActive() const
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		return object->m_bIsActive;
	}
	return false;
}

void QtScriptCCParticleSystem::_public_field_set_bIsActive(const bool& value)
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		object->m_bIsActive = value;
	}
}

bool QtScriptCCParticleSystem::_public_field_get_bIsBlendAdditive() const
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		return object->m_bIsBlendAdditive;
	}
	return false;
}

void QtScriptCCParticleSystem::_public_field_set_bIsBlendAdditive(const bool& value)
{
	auto object = thiz<CCParticleSystem *>();
	if (object)
	{
		object->m_bIsBlendAdditive = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleSystemQuad::QtScriptCCParticleSystemQuad(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystem(engine, className)
{
}

QtScriptCCParticleSystemQuad::QtScriptCCParticleSystemQuad(QScriptEngine *engine)
	: QtScriptCCParticleSystemQuad(engine, "ParticleSystemQuad")
{
}

void QtScriptCCParticleSystemQuad::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystem *>());
	auto ctor = RegisterT<CCParticleSystemQuad, QtScriptCCParticleSystemQuad>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSystemQuad::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSystemQuad::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCParticleSystemQuad::setDisplayFrame(cocos2d::CCSpriteFrame* spriteFrame)
{
	auto __o = this->thiz<CCParticleSystemQuad *>();
	if (__o)
	{
		__o->setDisplayFrame(spriteFrame);
	}
}

void QtScriptCCParticleSystemQuad::initTexCoordsWithRect(const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCParticleSystemQuad *>();
	if (__o)
	{
		__o->initTexCoordsWithRect(rect);
	}
}

void QtScriptCCParticleSystemQuad::setTextureWithRect(cocos2d::CCTexture2D* texture, const cocos2d::CCRect& rect)
{
	auto __o = this->thiz<CCParticleSystemQuad *>();
	if (__o)
	{
		__o->setTextureWithRect(texture, rect);
	}
}

void QtScriptCCParticleSystemQuad::initIndices()
{
	auto __o = this->thiz<CCParticleSystemQuad *>();
	if (__o)
	{
		__o->initIndices();
	}
}

void QtScriptCCParticleSystemQuad::listenBackToForeground(cocos2d::CCObject* obj)
{
	auto __o = this->thiz<CCParticleSystemQuad *>();
	if (__o)
	{
		__o->listenBackToForeground(obj);
	}
}

QScriptValue QtScriptCCParticleSystemQuad::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleSystemQuad::create());
		}
		case 1:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			return __e->toScriptValue(CCParticleSystemQuad::create(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSystemQuad::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleSystemQuad::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleSystemQuad::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSystemQuad::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleSystemQuad::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleSystemQuad::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleSystemQuad::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleSystemQuad();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSystemQuad constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleFire::QtScriptCCParticleFire(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleFire::QtScriptCCParticleFire(QScriptEngine *engine)
	: QtScriptCCParticleFire(engine, "ParticleFire")
{
}

void QtScriptCCParticleFire::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleFire, QtScriptCCParticleFire>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleFire::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleFire::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleFire::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleFire::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFire::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleFire::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleFire::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFire::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleFire::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleFire::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleFire::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleFire();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFire constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleFireworks::QtScriptCCParticleFireworks(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleFireworks::QtScriptCCParticleFireworks(QScriptEngine *engine)
	: QtScriptCCParticleFireworks(engine, "ParticleFireworks")
{
}

void QtScriptCCParticleFireworks::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleFireworks, QtScriptCCParticleFireworks>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleFireworks::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleFireworks::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleFireworks::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleFireworks::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFireworks::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleFireworks::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleFireworks::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFireworks::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleFireworks::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleFireworks::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleFireworks::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleFireworks();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFireworks constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleSun::QtScriptCCParticleSun(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleSun::QtScriptCCParticleSun(QScriptEngine *engine)
	: QtScriptCCParticleSun(engine, "ParticleSun")
{
}

void QtScriptCCParticleSun::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleSun, QtScriptCCParticleSun>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSun::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSun::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleSun::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleSun::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSun::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleSun::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleSun::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSun::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleSun::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleSun::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleSun::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleSun();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSun constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleGalaxy::QtScriptCCParticleGalaxy(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleGalaxy::QtScriptCCParticleGalaxy(QScriptEngine *engine)
	: QtScriptCCParticleGalaxy(engine, "ParticleGalaxy")
{
}

void QtScriptCCParticleGalaxy::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleGalaxy, QtScriptCCParticleGalaxy>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleGalaxy::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleGalaxy::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleGalaxy::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleGalaxy::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleGalaxy::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleGalaxy::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleGalaxy::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleGalaxy::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleGalaxy::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleGalaxy::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleGalaxy::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleGalaxy();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleGalaxy constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleFlower::QtScriptCCParticleFlower(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleFlower::QtScriptCCParticleFlower(QScriptEngine *engine)
	: QtScriptCCParticleFlower(engine, "ParticleFlower")
{
}

void QtScriptCCParticleFlower::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleFlower, QtScriptCCParticleFlower>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleFlower::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleFlower::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleFlower::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleFlower::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFlower::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleFlower::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleFlower::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFlower::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleFlower::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleFlower::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleFlower::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleFlower();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleFlower constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleMeteor::QtScriptCCParticleMeteor(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleMeteor::QtScriptCCParticleMeteor(QScriptEngine *engine)
	: QtScriptCCParticleMeteor(engine, "ParticleMeteor")
{
}

void QtScriptCCParticleMeteor::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleMeteor, QtScriptCCParticleMeteor>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleMeteor::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleMeteor::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleMeteor::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleMeteor::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleMeteor::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleMeteor::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleMeteor::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleMeteor::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleMeteor::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleMeteor::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleMeteor::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleMeteor();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleMeteor constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleSpiral::QtScriptCCParticleSpiral(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleSpiral::QtScriptCCParticleSpiral(QScriptEngine *engine)
	: QtScriptCCParticleSpiral(engine, "ParticleSpiral")
{
}

void QtScriptCCParticleSpiral::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleSpiral, QtScriptCCParticleSpiral>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSpiral::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSpiral::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleSpiral::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleSpiral::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSpiral::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleSpiral::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleSpiral::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSpiral::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleSpiral::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleSpiral::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleSpiral::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleSpiral();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSpiral constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleExplosion::QtScriptCCParticleExplosion(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleExplosion::QtScriptCCParticleExplosion(QScriptEngine *engine)
	: QtScriptCCParticleExplosion(engine, "ParticleExplosion")
{
}

void QtScriptCCParticleExplosion::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleExplosion, QtScriptCCParticleExplosion>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleExplosion::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleExplosion::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleExplosion::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleExplosion::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleExplosion::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleExplosion::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleExplosion::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleExplosion::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleExplosion::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleExplosion::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleExplosion::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleExplosion();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleExplosion constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleSmoke::QtScriptCCParticleSmoke(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleSmoke::QtScriptCCParticleSmoke(QScriptEngine *engine)
	: QtScriptCCParticleSmoke(engine, "ParticleSmoke")
{
}

void QtScriptCCParticleSmoke::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleSmoke, QtScriptCCParticleSmoke>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSmoke::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSmoke::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleSmoke::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleSmoke::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSmoke::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleSmoke::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleSmoke::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSmoke::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleSmoke::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleSmoke::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleSmoke::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleSmoke();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSmoke constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleSnow::QtScriptCCParticleSnow(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleSnow::QtScriptCCParticleSnow(QScriptEngine *engine)
	: QtScriptCCParticleSnow(engine, "ParticleSnow")
{
}

void QtScriptCCParticleSnow::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleSnow, QtScriptCCParticleSnow>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSnow::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleSnow::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleSnow::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleSnow::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSnow::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleSnow::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleSnow::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSnow::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleSnow::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleSnow::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleSnow::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleSnow();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleSnow constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParticleRain::QtScriptCCParticleRain(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCParticleSystemQuad(engine, className)
{
}

QtScriptCCParticleRain::QtScriptCCParticleRain(QScriptEngine *engine)
	: QtScriptCCParticleRain(engine, "ParticleRain")
{
}

void QtScriptCCParticleRain::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCParticleSystemQuad *>());
	auto ctor = RegisterT<CCParticleRain, QtScriptCCParticleRain>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleRain::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("createWithTotalParticles", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParticleRain::createWithTotalParticles)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCParticleRain::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParticleRain::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleRain::create");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCParticleRain::createWithTotalParticles(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<unsigned int>(context->argument(0));
			return __e->toScriptValue(CCParticleRain::createWithTotalParticles(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleRain::createWithTotalParticles");
	return __e->uncaughtException();
}

int QtScriptCCParticleRain::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParticleRain::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParticleRain::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParticleRain();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParticleRain constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCDevice::QtScriptCCDevice(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCDevice *, false>(engine, className)
{
}

QtScriptCCDevice::QtScriptCCDevice(QScriptEngine *engine)
	: QtScriptCCDevice(engine, "Device")
{
}

void QtScriptCCDevice::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	QScriptValue inherit;
	auto ctor = RegisterT<CCDevice, QtScriptCCDevice>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("getDPI", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCDevice::getDPI)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCDevice::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCDevice::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCDevice::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCDevice");
	return false;
}

QScriptValue QtScriptCCDevice::getDPI(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCDevice::getDPI());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCDevice::getDPI");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCFileUtils::QtScriptCCFileUtils(QScriptEngine *engine, const QByteArray &className)
	: QtScriptTypeInfo(engine, className)
{
}

QtScriptCCFileUtils::QtScriptCCFileUtils(QScriptEngine *engine)
	: QtScriptCCFileUtils(engine, "FileUtils")
{
}

void QtScriptCCFileUtils::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<TypeInfo *>());
	auto ctor = RegisterT<CCFileUtils, QtScriptCCFileUtils>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("purgeFileUtils", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFileUtils::purgeFileUtils)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("sharedFileUtils", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCFileUtils::sharedFileUtils)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCFileUtils::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCFileUtils::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCFileUtils::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCFileUtils");
	return false;
}

bool QtScriptCCFileUtils::isPopupNotify()
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return __o->isPopupNotify();
	}
	return false;
}

void QtScriptCCFileUtils::removeSearchPath(const QByteArray& path)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->removeSearchPath(path.data());
	}
}

QByteArray QtScriptCCFileUtils::fullPathForFilename(const QByteArray& pszFileName)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return QByteArray(__o->fullPathForFilename(pszFileName.data()).c_str(), int(__o->fullPathForFilename(pszFileName.data()).size()));
	}
	return QByteArray();
}

QByteArray QtScriptCCFileUtils::fullPathFromRelativeFile(const QByteArray& pszFilename, const QByteArray& pszRelativeFile)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return QByteArray(__o->fullPathFromRelativeFile(pszFilename.data(), pszRelativeFile.data()));
	}
	return QByteArray();
}

QByteArray QtScriptCCFileUtils::getFileData(const QByteArray& pszFileName, const QByteArray& pszMode, unsigned long* pSize)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return QByteArray(reinterpret_cast<const char*>(__o->getFileData(pszFileName.data(), pszMode.data(), pSize)));
	}
	return QByteArray();
}

void QtScriptCCFileUtils::setSearchPaths(const std::vector<std::string>& searchPaths)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->setSearchPaths(searchPaths);
	}
}

void QtScriptCCFileUtils::setFilenameLookupDictionary(cocos2d::CCDictionary* pFilenameLookupDict)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->setFilenameLookupDictionary(pFilenameLookupDict);
	}
}

void QtScriptCCFileUtils::addSearchResolutionsOrder(const QByteArray& order)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->addSearchResolutionsOrder(order.data());
	}
}

QByteArray QtScriptCCFileUtils::getFileDataFromZip(const QByteArray& pszZipFilePath, const QByteArray& pszFileName, unsigned long* pSize)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return QByteArray(reinterpret_cast<const char*>(__o->getFileDataFromZip(pszZipFilePath.data(), pszFileName.data(), pSize)));
	}
	return QByteArray();
}

long QtScriptCCFileUtils::getClassTypeInfo()
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return __o->getClassTypeInfo();
	}
	return static_cast<long>(0);
}

void QtScriptCCFileUtils::removeAllPaths()
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->removeAllPaths();
	}
}

void QtScriptCCFileUtils::setSearchResolutionsOrder(const std::vector<std::string>& searchResolutionsOrder)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->setSearchResolutionsOrder(searchResolutionsOrder);
	}
}

void QtScriptCCFileUtils::purgeCachedEntries()
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->purgeCachedEntries();
	}
}

bool QtScriptCCFileUtils::isAbsolutePath(const QByteArray& strPath)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return __o->isAbsolutePath(std::string(strPath.data(), size_t(strPath.size())));
	}
	return false;
}

void QtScriptCCFileUtils::addSearchPath(const QByteArray& path)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->addSearchPath(path.data());
	}
}

void QtScriptCCFileUtils::loadFilenameLookupDictionaryFromFile(const QByteArray& filename)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->loadFilenameLookupDictionaryFromFile(filename.data());
	}
}

std::vector<std::string> QtScriptCCFileUtils::getSearchPaths()
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return __o->getSearchPaths();
	}
	return std::vector<std::string>();
}

std::vector<std::string> QtScriptCCFileUtils::getSearchResolutionsOrder()
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		return __o->getSearchResolutionsOrder();
	}
	return std::vector<std::string>();
}

void QtScriptCCFileUtils::setPopupNotify(bool bNotify)
{
	auto __o = this->thiz<CCFileUtils *>();
	if (__o)
	{
		__o->setPopupNotify(bNotify);
	}
}

QScriptValue QtScriptCCFileUtils::purgeFileUtils(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCFileUtils::purgeFileUtils();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFileUtils::purgeFileUtils");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCFileUtils::sharedFileUtils(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCFileUtils::sharedFileUtils());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCFileUtils::sharedFileUtils");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCImage::QtScriptCCImage(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCImage::QtScriptCCImage(QScriptEngine *engine)
	: QtScriptCCImage(engine, "Image")
{
}

void QtScriptCCImage::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCImage, QtScriptCCImage>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCImage::getDataLen()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->getDataLen();
	}
	return 0;
}

bool QtScriptCCImage::saveToFile(const QByteArray& pszFilePath)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->saveToFile(pszFilePath.data());
	}
	return false;
}

bool QtScriptCCImage::saveToFile(const QByteArray& pszFilePath, bool bIsToRGB)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->saveToFile(pszFilePath.data(), bIsToRGB);
	}
	return false;
}

bool QtScriptCCImage::isPremultipliedAlpha()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->isPremultipliedAlpha();
	}
	return false;
}

unsigned short QtScriptCCImage::getHeight()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->getHeight();
	}
	return static_cast<unsigned short>(0);
}

bool QtScriptCCImage::initWithString(const QByteArray& pText)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithString(pText.data());
	}
	return false;
}

bool QtScriptCCImage::initWithString(const QByteArray& pText, int nWidth)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithString(pText.data(), nWidth);
	}
	return false;
}

bool QtScriptCCImage::initWithString(const QByteArray& pText, int nWidth, int nHeight)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithString(pText.data(), nWidth, nHeight);
	}
	return false;
}

bool QtScriptCCImage::initWithString(const QByteArray& pText, int nWidth, int nHeight, int eAlignMask)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithString(pText.data(), nWidth, nHeight, cocos2d::CCImage::ETextAlign(eAlignMask));
	}
	return false;
}

bool QtScriptCCImage::initWithString(const QByteArray& pText, int nWidth, int nHeight, int eAlignMask, const QByteArray& pFontName)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithString(pText.data(), nWidth, nHeight, cocos2d::CCImage::ETextAlign(eAlignMask), pFontName.data());
	}
	return false;
}

bool QtScriptCCImage::initWithString(const QByteArray& pText, int nWidth, int nHeight, int eAlignMask, const QByteArray& pFontName, int nSize)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithString(pText.data(), nWidth, nHeight, cocos2d::CCImage::ETextAlign(eAlignMask), pFontName.data(), nSize);
	}
	return false;
}

bool QtScriptCCImage::hasAlpha()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->hasAlpha();
	}
	return false;
}

bool QtScriptCCImage::initWithImageFile(const QByteArray& strPath)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithImageFile(strPath.data());
	}
	return false;
}

bool QtScriptCCImage::initWithImageFile(const QByteArray& strPath, int imageType)
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->initWithImageFile(strPath.data(), cocos2d::CCImage::EImageFormat(imageType));
	}
	return false;
}

unsigned short QtScriptCCImage::getWidth()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->getWidth();
	}
	return static_cast<unsigned short>(0);
}

int QtScriptCCImage::getBitsPerComponent()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return __o->getBitsPerComponent();
	}
	return 0;
}

QByteArray QtScriptCCImage::getData()
{
	auto __o = this->thiz<CCImage *>();
	if (__o)
	{
		return QByteArray(reinterpret_cast<const char*>(__o->getData()));
	}
	return QByteArray();
}

int QtScriptCCImage::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCImage::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCImage::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCImage();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCImage constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCThread::QtScriptCCThread(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCThread, false>(engine, className)
{
}

QtScriptCCThread::QtScriptCCThread(QScriptEngine *engine)
	: QtScriptCCThread(engine, "Thread")
{
}

void QtScriptCCThread::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCThread, QtScriptCCThread>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCThread::createAutoreleasePool()
{
	auto __o = this->thiz<CCThread *>();
	if (__o)
	{
		__o->createAutoreleasePool();
	}
}

int QtScriptCCThread::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCThread::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCThread::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			Q_UNUSED(out);
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCThread constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptcc_timeval::QtScriptcc_timeval(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<cc_timeval, false>(engine, className)
{
}

QtScriptcc_timeval::QtScriptcc_timeval(QScriptEngine *engine)
	: QtScriptcc_timeval(engine, "timeval")
{
}

void QtScriptcc_timeval::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<cc_timeval, QtScriptcc_timeval>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptcc_timeval::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptcc_timeval::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptcc_timeval::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::cc_timeval constructor");
	return false;
}

cc_time_t QtScriptcc_timeval::_public_field_get_tv_sec() const
{
	auto object = thiz<cc_timeval *>();
	if (object)
	{
		return object->tv_sec;
	}
	return static_cast<cc_time_t>(0);
}

void QtScriptcc_timeval::_public_field_set_tv_sec(cc_time_t value)
{
	auto object = thiz<cc_timeval *>();
	if (object)
	{
		object->tv_sec = value;
	}
}

int32_t QtScriptcc_timeval::_public_field_get_tv_usec() const
{
	auto object = thiz<cc_timeval *>();
	if (object)
	{
		return object->tv_usec;
	}
	return static_cast<int32_t>(0);
}

void QtScriptcc_timeval::_public_field_set_tv_usec(int32_t value)
{
	auto object = thiz<cc_timeval *>();
	if (object)
	{
		object->tv_usec = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTime::QtScriptCCTime(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCTime, false>(engine, className)
{
}

QtScriptCCTime::QtScriptCCTime(QScriptEngine *engine)
	: QtScriptCCTime(engine, "Time")
{
}

void QtScriptCCTime::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	QScriptValue inherit;
	auto ctor = RegisterT<CCTime, QtScriptCCTime>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("currentTimeSeconds", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTime::currentTimeSeconds)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("gettimeofday", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTime::gettimeofday)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("deltaTime", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTime::deltaTime)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTime::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTime::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTime::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTime constructor");
	return false;
}

QScriptValue QtScriptCCTime::currentTimeSeconds(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCTime::currentTimeSeconds());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTime::currentTimeSeconds");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTime::gettimeofday(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 1, 1))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 1:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::cc_timeval*>(context->argument(0));
			return __e->toScriptValue(CCTime::gettimeofdayCocos2d(arg0));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTime::gettimeofdayCocos2d");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTime::deltaTime(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::cc_timeval*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<cocos2d::cc_timeval*>(context->argument(1));
			return __e->toScriptValue(CCTime::deltaTime(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTime::deltaTime");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCApplicationProtocol::QtScriptCCApplicationProtocol(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCApplicationProtocol *, false>(engine, className)
{
}

QtScriptCCApplicationProtocol::QtScriptCCApplicationProtocol(QScriptEngine *engine)
	: QtScriptCCApplicationProtocol(engine, "ApplicationProtocol")
{
}

void QtScriptCCApplicationProtocol::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCApplicationProtocol, QtScriptCCApplicationProtocol>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCApplicationProtocol::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCApplicationProtocol::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCApplicationProtocol::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCApplicationProtocol");
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCApplication::QtScriptCCApplication(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCApplicationProtocol(engine, className)
{
}

QtScriptCCApplication::QtScriptCCApplication(QScriptEngine *engine)
	: QtScriptCCApplication(engine, "Application")
{
}

void QtScriptCCApplication::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCApplicationProtocol *>());
	auto ctor = RegisterT<CCApplication, QtScriptCCApplication>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedApplication", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCApplication::sharedApplication)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCApplication::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCApplication::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCApplication::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCApplication");
	return false;
}

void QtScriptCCApplication::setStartupScriptFilename(const QByteArray& startupScriptFile)
{
	auto __o = this->thiz<CCApplication *>();
	if (__o)
	{
		__o->setStartupScriptFilename(std::string(startupScriptFile.data(), size_t(startupScriptFile.size())));
	}
}

int QtScriptCCApplication::getTargetPlatform()
{
	auto __o = this->thiz<CCApplication *>();
	if (__o)
	{
		return int(__o->getTargetPlatform());
	}
	return 0;
}

QByteArray QtScriptCCApplication::getStartupScriptFilename()
{
	auto __o = this->thiz<CCApplication *>();
	if (__o)
	{
		return QByteArray(__o->getStartupScriptFilename().c_str(), int(__o->getStartupScriptFilename().size()));
	}
	return QByteArray();
}

void QtScriptCCApplication::setAnimationInterval(double interval)
{
	auto __o = this->thiz<CCApplication *>();
	if (__o)
	{
		__o->setAnimationInterval(interval);
	}
}

int QtScriptCCApplication::getCurrentLanguage()
{
	auto __o = this->thiz<CCApplication *>();
	if (__o)
	{
		return int(__o->getCurrentLanguage());
	}
	return 0;
}

QScriptValue QtScriptCCApplication::sharedApplication(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCApplication::sharedApplication());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCApplication::sharedApplication");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEGLViewProtocol::QtScriptCCEGLViewProtocol(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCEGLViewProtocol *, false>(engine, className)
{
}

QtScriptCCEGLViewProtocol::QtScriptCCEGLViewProtocol(QScriptEngine *engine)
	: QtScriptCCEGLViewProtocol(engine, "EGLViewProtocol")
{
}

void QtScriptCCEGLViewProtocol::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCEGLViewProtocol, QtScriptCCEGLViewProtocol>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCEGLViewProtocol::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEGLViewProtocol::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEGLViewProtocol::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCEGLViewProtocol");
	return false;
}

cocos2d::CCRect QtScriptCCEGLViewProtocol::getViewPortRect()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getViewPortRect();
	}
	return cocos2d::CCRect();
}

cocos2d::CCSize QtScriptCCEGLViewProtocol::getFrameSize()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getFrameSize();
	}
	return cocos2d::CCSize();
}

void QtScriptCCEGLViewProtocol::setViewName(const QByteArray& pszViewName)
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		__o->setViewName(pszViewName.data());
	}
}

float QtScriptCCEGLViewProtocol::getScaleY()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getScaleY();
	}
	return static_cast<float>(0);
}

float QtScriptCCEGLViewProtocol::getScaleX()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getScaleX();
	}
	return static_cast<float>(0);
}

cocos2d::CCPoint QtScriptCCEGLViewProtocol::getVisibleOrigin()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getVisibleOrigin();
	}
	return cocos2d::CCPoint();
}

cocos2d::CCSize QtScriptCCEGLViewProtocol::getVisibleSize()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getVisibleSize();
	}
	return cocos2d::CCSize();
}

cocos2d::CCSize QtScriptCCEGLViewProtocol::getDesignResolutionSize()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getDesignResolutionSize();
	}
	return cocos2d::CCSize();
}

QByteArray QtScriptCCEGLViewProtocol::getViewName()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return QByteArray(__o->getViewName());
	}
	return QByteArray();
}

cocos2d::CCRect QtScriptCCEGLViewProtocol::getScissorRect()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->getScissorRect();
	}
	return cocos2d::CCRect();
}

bool QtScriptCCEGLViewProtocol::isScissorEnabled()
{
	auto __o = this->thiz<CCEGLViewProtocol *>();
	if (__o)
	{
		return __o->isScissorEnabled();
	}
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCEGLView::QtScriptCCEGLView(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCEGLViewProtocol(engine, className)
{
}

QtScriptCCEGLView::QtScriptCCEGLView(QScriptEngine *engine)
	: QtScriptCCEGLView(engine, "EGLView")
{
}

void QtScriptCCEGLView::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCEGLViewProtocol *>());
	auto ctor = RegisterT<CCEGLView, QtScriptCCEGLView>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedOpenGLView", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCEGLView::sharedOpenGLView)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCEGLView::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCEGLView::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCEGLView::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCEGLView");
	return false;
}

void QtScriptCCEGLView::setIMEKeyboardState(bool bOpen)
{
	auto __o = this->thiz<CCEGLView *>();
	if (__o)
	{
		__o->setIMEKeyboardState(bOpen);
	}
}

bool QtScriptCCEGLView::isOpenGLReady()
{
	auto __o = this->thiz<CCEGLView *>();
	if (__o)
	{
		return __o->isOpenGLReady();
	}
	return false;
}

QScriptValue QtScriptCCEGLView::sharedOpenGLView(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCEGLView::sharedOpenGLView());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCEGLView::sharedOpenGLView");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCShaderCache::QtScriptCCShaderCache(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCShaderCache::QtScriptCCShaderCache(QScriptEngine *engine)
	: QtScriptCCShaderCache(engine, "ShaderCache")
{
}

void QtScriptCCShaderCache::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCShaderCache, QtScriptCCShaderCache>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("purgeSharedShaderCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShaderCache::purgeSharedShaderCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("sharedShaderCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCShaderCache::sharedShaderCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCShaderCache::reloadDefaultShaders()
{
	auto __o = this->thiz<CCShaderCache *>();
	if (__o)
	{
		__o->reloadDefaultShaders();
	}
}

cocos2d::CCGLProgram* QtScriptCCShaderCache::programForKey(const QByteArray& key)
{
	auto __o = this->thiz<CCShaderCache *>();
	if (__o)
	{
		return __o->programForKey(key.data());
	}
	return nullptr;
}

void QtScriptCCShaderCache::loadDefaultShaders()
{
	auto __o = this->thiz<CCShaderCache *>();
	if (__o)
	{
		__o->loadDefaultShaders();
	}
}

void QtScriptCCShaderCache::addProgram(cocos2d::CCGLProgram* program, const QByteArray& key)
{
	auto __o = this->thiz<CCShaderCache *>();
	if (__o)
	{
		__o->addProgram(program, key.data());
	}
}

QScriptValue QtScriptCCShaderCache::purgeSharedShaderCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCShaderCache::purgeSharedShaderCache();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShaderCache::purgeSharedShaderCache");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCShaderCache::sharedShaderCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCShaderCache::sharedShaderCache());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShaderCache::sharedShaderCache");
	return __e->uncaughtException();
}

int QtScriptCCShaderCache::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCShaderCache::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCShaderCache::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCShaderCache();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCShaderCache constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCAnimationCache::QtScriptCCAnimationCache(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCAnimationCache::QtScriptCCAnimationCache(QScriptEngine *engine)
	: QtScriptCCAnimationCache(engine, "AnimationCache")
{
}

void QtScriptCCAnimationCache::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCAnimationCache, QtScriptCCAnimationCache>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedAnimationCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAnimationCache::sharedAnimationCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("purgeSharedAnimationCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCAnimationCache::purgeSharedAnimationCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCAnimationCache::addAnimation(cocos2d::CCAnimation* animation, const QByteArray& name)
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		__o->addAnimation(animation, name.data());
	}
}

void QtScriptCCAnimationCache::addAnimationsWithFile(const QByteArray& plist)
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		__o->addAnimationsWithFile(plist.data());
	}
}

void QtScriptCCAnimationCache::removeAnimationByName(const QByteArray& name)
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		__o->removeAnimationByName(name.data());
	}
}

bool QtScriptCCAnimationCache::init()
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

cocos2d::CCAnimation* QtScriptCCAnimationCache::animationByName(const QByteArray& name)
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		return __o->animationByName(name.data());
	}
	return nullptr;
}

void QtScriptCCAnimationCache::addAnimationsWithDictionary(cocos2d::CCDictionary* dictionary)
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		__o->addAnimationsWithDictionary(dictionary);
	}
}

void QtScriptCCAnimationCache::addAnimationsWithDictionary(cocos2d::CCDictionary* dictionary, const QByteArray& plist)
{
	auto __o = this->thiz<CCAnimationCache *>();
	if (__o)
	{
		__o->addAnimationsWithDictionary(dictionary, plist.data());
	}
}

QScriptValue QtScriptCCAnimationCache::sharedAnimationCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCAnimationCache::sharedAnimationCache());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimationCache::sharedAnimationCache");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCAnimationCache::purgeSharedAnimationCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCAnimationCache::purgeSharedAnimationCache();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimationCache::purgeSharedAnimationCache");
	return __e->uncaughtException();
}

int QtScriptCCAnimationCache::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCAnimationCache::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCAnimationCache::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCAnimationCache();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCAnimationCache constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCSpriteFrameCache::QtScriptCCSpriteFrameCache(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCSpriteFrameCache::QtScriptCCSpriteFrameCache(QScriptEngine *engine)
	: QtScriptCCSpriteFrameCache(engine, "SpriteFrameCache")
{
}

void QtScriptCCSpriteFrameCache::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCSpriteFrameCache, QtScriptCCSpriteFrameCache>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("purgeSharedSpriteFrameCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpriteFrameCache::purgeSharedSpriteFrameCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("sharedSpriteFrameCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCSpriteFrameCache::sharedSpriteFrameCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCSpriteFrameCache::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCSpriteFrameCache::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCSpriteFrameCache::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCSpriteFrameCache");
	return false;
}

void QtScriptCCSpriteFrameCache::addSpriteFramesWithFile(const QByteArray& pszPlist)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->addSpriteFramesWithFile(pszPlist.data());
	}
}

void QtScriptCCSpriteFrameCache::addSpriteFramesWithFile(const QByteArray& plist, const QByteArray& textureFileName)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->addSpriteFramesWithFile(plist.data(), textureFileName.data());
	}
}

void QtScriptCCSpriteFrameCache::addSpriteFrame(cocos2d::CCSpriteFrame* pobFrame, const QByteArray& pszFrameName)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->addSpriteFrame(pobFrame, pszFrameName.data());
	}
}

cocos2d::CCSpriteFrame* QtScriptCCSpriteFrameCache::spriteFrameByName(const QByteArray& pszName)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		return __o->spriteFrameByName(pszName.data());
	}
	return nullptr;
}

void QtScriptCCSpriteFrameCache::removeUnusedSpriteFrames()
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->removeUnusedSpriteFrames();
	}
}

void QtScriptCCSpriteFrameCache::removeSpriteFramesFromFile(const QByteArray& plist)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->removeSpriteFramesFromFile(plist.data());
	}
}

bool QtScriptCCSpriteFrameCache::init()
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

void QtScriptCCSpriteFrameCache::removeSpriteFrames()
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->removeSpriteFrames();
	}
}

void QtScriptCCSpriteFrameCache::removeSpriteFramesFromTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->removeSpriteFramesFromTexture(texture);
	}
}

void QtScriptCCSpriteFrameCache::removeSpriteFrameByName(const QByteArray& pszName)
{
	auto __o = this->thiz<CCSpriteFrameCache *>();
	if (__o)
	{
		__o->removeSpriteFrameByName(pszName.data());
	}
}

QScriptValue QtScriptCCSpriteFrameCache::purgeSharedSpriteFrameCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCSpriteFrameCache::purgeSharedSpriteFrameCache();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteFrameCache::purgeSharedSpriteFrameCache");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCSpriteFrameCache::sharedSpriteFrameCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCSpriteFrameCache::sharedSpriteFrameCache());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCNotificationCenter::QtScriptCCNotificationCenter(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCNotificationCenter::QtScriptCCNotificationCenter(QScriptEngine *engine)
	: QtScriptCCNotificationCenter(engine, "NotificationCenter")
{
}

void QtScriptCCNotificationCenter::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCNotificationCenter, QtScriptCCNotificationCenter>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedNotificationCenter", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCNotificationCenter::sharedNotificationCenter)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("purgeNotificationCenter", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCNotificationCenter::purgeNotificationCenter)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCNotificationCenter::postNotification(const QByteArray& name)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		__o->postNotification(name.data());
	}
}

void QtScriptCCNotificationCenter::postNotification(const QByteArray& name, cocos2d::CCObject* object)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		__o->postNotification(name.data(), object);
	}
}

void QtScriptCCNotificationCenter::removeObserver(cocos2d::CCObject* target, const QByteArray& name)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		__o->removeObserver(target, name.data());
	}
}

void QtScriptCCNotificationCenter::registerObserver(cocos2d::CCObject* arg0, const QScriptValue& arg1, const QByteArray& arg2)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		__o->registerScriptObserver(arg0, QtCocosScriptEngine::instance()->retainJSObject(arg1), arg2.data());
	}
}

int QtScriptCCNotificationCenter::getObserverHandlerByName(const QByteArray& name)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		return __o->getObserverHandlerByName(name.data());
	}
	return 0;
}

void QtScriptCCNotificationCenter::unregisterScriptObserver(cocos2d::CCObject* target, const QByteArray& name)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		__o->unregisterScriptObserver(target, name.data());
	}
}

int QtScriptCCNotificationCenter::removeAllObservers(cocos2d::CCObject* target)
{
	auto __o = this->thiz<CCNotificationCenter *>();
	if (__o)
	{
		return __o->removeAllObservers(target);
	}
	return 0;
}

QScriptValue QtScriptCCNotificationCenter::sharedNotificationCenter(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCNotificationCenter::sharedNotificationCenter());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNotificationCenter::sharedNotificationCenter");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCNotificationCenter::purgeNotificationCenter(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCNotificationCenter::purgeNotificationCenter();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNotificationCenter::purgeNotificationCenter");
	return __e->uncaughtException();
}

int QtScriptCCNotificationCenter::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCNotificationCenter::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCNotificationCenter::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCNotificationCenter();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCNotificationCenter constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCNotificationObserver::QtScriptCCNotificationObserver(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCNotificationObserver::QtScriptCCNotificationObserver(QScriptEngine *engine)
	: QtScriptCCNotificationObserver(engine, "NotificationObserver")
{
}

void QtScriptCCNotificationObserver::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCNotificationObserver, QtScriptCCNotificationObserver>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCNotificationObserver::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCNotificationObserver::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCNotificationObserver::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCNotificationObserver");
	return false;
}

void QtScriptCCNotificationObserver::performSelector(cocos2d::CCObject* obj)
{
	auto __o = this->thiz<CCNotificationObserver *>();
	if (__o)
	{
		__o->performSelector(obj);
	}
}

QByteArray QtScriptCCNotificationObserver::getName()
{
	auto __o = this->thiz<CCNotificationObserver *>();
	if (__o)
	{
		return QByteArray(__o->getName());
	}
	return QByteArray();
}

cocos2d::CCObject* QtScriptCCNotificationObserver::getTarget()
{
	auto __o = this->thiz<CCNotificationObserver *>();
	if (__o)
	{
		return __o->getTarget();
	}
	return nullptr;
}

cocos2d::CCObject* QtScriptCCNotificationObserver::getObject()
{
	auto __o = this->thiz<CCNotificationObserver *>();
	if (__o)
	{
		return __o->getObject();
	}
	return nullptr;
}

int64_t QtScriptCCNotificationObserver::getHandler()
{
	auto __o = this->thiz<CCNotificationObserver *>();
	if (__o)
	{
		return __o->getHandler();
	}
	return static_cast<int64_t>(0);
}

void QtScriptCCNotificationObserver::setHandler(int64_t var)
{
	auto __o = this->thiz<CCNotificationObserver *>();
	if (__o)
	{
		__o->setHandler(var);
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCProfiler::QtScriptCCProfiler(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCProfiler::QtScriptCCProfiler(QScriptEngine *engine)
	: QtScriptCCProfiler(engine, "Profiler")
{
}

void QtScriptCCProfiler::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCProfiler, QtScriptCCProfiler>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedProfiler", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCProfiler::sharedProfiler)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCProfiler::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCProfiler::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCProfiler::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCProfiler;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCProfiler constructor");
	return false;
}

void QtScriptCCProfiler::displayTimers()
{
	auto __o = this->thiz<CCProfiler *>();
	if (__o)
	{
		__o->displayTimers();
	}
}

bool QtScriptCCProfiler::init()
{
	auto __o = this->thiz<CCProfiler *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

void QtScriptCCProfiler::releaseTimer(const QByteArray& timerName)
{
	auto __o = this->thiz<CCProfiler *>();
	if (__o)
	{
		__o->releaseTimer(timerName.data());
	}
}

void QtScriptCCProfiler::releaseAllTimers()
{
	auto __o = this->thiz<CCProfiler *>();
	if (__o)
	{
		__o->releaseAllTimers();
	}
}

cocos2d::CCProfilingTimer* QtScriptCCProfiler::createAndAddTimerWithName(const QByteArray& timerName)
{
	auto __o = this->thiz<CCProfiler *>();
	if (__o)
	{
		return __o->createAndAddTimerWithName(timerName.data());
	}
	return nullptr;
}

QScriptValue QtScriptCCProfiler::sharedProfiler(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCProfiler::sharedProfiler());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCProfiler::sharedProfiler");
	return __e->uncaughtException();
}

cocos2d::CCDictionary* QtScriptCCProfiler::_public_field_get_pActiveTimers() const
{
	auto object = thiz<CCProfiler *>();
	if (object)
	{
		return object->m_pActiveTimers;
	}
	return nullptr;
}

void QtScriptCCProfiler::_public_field_set_pActiveTimers(cocos2d::CCDictionary* value)
{
	auto object = thiz<CCProfiler *>();
	if (object)
	{
		object->m_pActiveTimers = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCProfilingTimer::QtScriptCCProfilingTimer(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCProfilingTimer::QtScriptCCProfilingTimer(QScriptEngine *engine)
	: QtScriptCCProfilingTimer(engine, "ProfilingTimer")
{
}

void QtScriptCCProfilingTimer::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCProfilingTimer, QtScriptCCProfilingTimer>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

void QtScriptCCProfilingTimer::reset()
{
	auto __o = this->thiz<CCProfilingTimer *>();
	if (__o)
	{
		__o->reset();
	}
}

bool QtScriptCCProfilingTimer::initWithName(const QByteArray& timerName)
{
	auto __o = this->thiz<CCProfilingTimer *>();
	if (__o)
	{
		return __o->initWithName(timerName.data());
	}
	return false;
}

QByteArray QtScriptCCProfilingTimer::description()
{
	auto __o = this->thiz<CCProfilingTimer *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

cocos2d::cc_timeval* QtScriptCCProfilingTimer::getStartTime()
{
	auto __o = this->thiz<CCProfilingTimer *>();
	if (__o)
	{
		return __o->getStartTime();
	}
	return nullptr;
}

int QtScriptCCProfilingTimer::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCProfilingTimer::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCProfilingTimer::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCProfilingTimer();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCProfilingTimer constructor");
	}
	return ok;
}

QByteArray QtScriptCCProfilingTimer::_public_field_get_nameStr() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return QByteArray(object->m_NameStr.c_str(), int(object->m_NameStr.size()));
	}
	return QByteArray();
}

void QtScriptCCProfilingTimer::_public_field_set_nameStr(const QByteArray& value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->m_NameStr = std::string(value.data(), size_t(value.size()));
	}
}

int QtScriptCCProfilingTimer::_public_field_get_numberOfCalls() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->numberOfCalls;
	}
	return static_cast<int>(0);
}

void QtScriptCCProfilingTimer::_public_field_set_numberOfCalls(int value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->numberOfCalls = value;
	}
}

int QtScriptCCProfilingTimer::_public_field_get_dAverageTime1() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->m_dAverageTime1;
	}
	return static_cast<int>(0);
}

void QtScriptCCProfilingTimer::_public_field_set_dAverageTime1(int value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->m_dAverageTime1 = value;
	}
}

int QtScriptCCProfilingTimer::_public_field_get_dAverageTime2() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->m_dAverageTime2;
	}
	return static_cast<int>(0);
}

void QtScriptCCProfilingTimer::_public_field_set_dAverageTime2(int value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->m_dAverageTime2 = value;
	}
}

long long QtScriptCCProfilingTimer::_public_field_get_totalTime() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->totalTime;
	}
	return static_cast<long long>(0);
}

void QtScriptCCProfilingTimer::_public_field_set_totalTime(long long value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->totalTime = value;
	}
}

int QtScriptCCProfilingTimer::_public_field_get_minTime() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->minTime;
	}
	return static_cast<int>(0);
}

void QtScriptCCProfilingTimer::_public_field_set_minTime(int value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->minTime = value;
	}
}

int QtScriptCCProfilingTimer::_public_field_get_maxTime() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->maxTime;
	}
	return static_cast<int>(0);
}

void QtScriptCCProfilingTimer::_public_field_set_maxTime(int value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->maxTime = value;
	}
}

cocos2d::cc_timeval QtScriptCCProfilingTimer::_public_field_get_sStartTime() const
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		return object->m_sStartTime;
	}
	return cocos2d::cc_timeval();
}

void QtScriptCCProfilingTimer::_public_field_set_sStartTime(const cocos2d::cc_timeval& value)
{
	auto object = thiz<CCProfilingTimer *>();
	if (object)
	{
		object->m_sStartTime = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCUserDefault::QtScriptCCUserDefault(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCUserDefault *, false>(engine, className)
{
}

QtScriptCCUserDefault::QtScriptCCUserDefault(QScriptEngine *engine)
	: QtScriptCCUserDefault(engine, "UserDefault")
{
}

void QtScriptCCUserDefault::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	QScriptValue inherit;
	auto ctor = RegisterT<CCUserDefault, QtScriptCCUserDefault>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("purgeSharedUserDefault", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCUserDefault::purgeSharedUserDefault)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("isXMLFileExist", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCUserDefault::isXMLFileExist)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("getXMLFilePath", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCUserDefault::getXMLFilePath)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("sharedUserDefault", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCUserDefault::sharedUserDefault)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCUserDefault::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCUserDefault::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCUserDefault::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCUserDefault");
	return false;
}

void QtScriptCCUserDefault::setIntegerForKey(const QByteArray& pKey, int value)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		__o->setIntegerForKey(pKey.data(), value);
	}
}

float QtScriptCCUserDefault::getFloatForKey(const QByteArray& pKey)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getFloatForKey(pKey.data());
	}
	return static_cast<float>(0);
}

float QtScriptCCUserDefault::getFloatForKey(const QByteArray& pKey, float defaultValue)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getFloatForKey(pKey.data(), defaultValue);
	}
	return static_cast<float>(0);
}

bool QtScriptCCUserDefault::getBoolForKey(const QByteArray& pKey)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getBoolForKey(pKey.data());
	}
	return false;
}

bool QtScriptCCUserDefault::getBoolForKey(const QByteArray& pKey, bool defaultValue)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getBoolForKey(pKey.data(), defaultValue);
	}
	return false;
}

void QtScriptCCUserDefault::setDoubleForKey(const QByteArray& pKey, double value)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		__o->setDoubleForKey(pKey.data(), value);
	}
}

void QtScriptCCUserDefault::setFloatForKey(const QByteArray& pKey, float value)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		__o->setFloatForKey(pKey.data(), value);
	}
}

QByteArray QtScriptCCUserDefault::getStringForKey(const QByteArray& pKey)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return QByteArray(__o->getStringForKey(pKey.data()).c_str(), int(__o->getStringForKey(pKey.data()).size()));
	}
	return QByteArray();
}

QByteArray QtScriptCCUserDefault::getStringForKey(const QByteArray& pKey, const QByteArray& defaultValue)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return QByteArray(__o->getStringForKey(pKey.data(), std::string(defaultValue.data(), size_t(defaultValue.size()))).c_str(), int(__o->getStringForKey(pKey.data(), std::string(defaultValue.data(), size_t(defaultValue.size()))).size()));
	}
	return QByteArray();
}

void QtScriptCCUserDefault::setStringForKey(const QByteArray& pKey, const QByteArray& value)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		__o->setStringForKey(pKey.data(), std::string(value.data(), size_t(value.size())));
	}
}

void QtScriptCCUserDefault::flush()
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		__o->flush();
	}
}

int QtScriptCCUserDefault::getIntegerForKey(const QByteArray& pKey)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getIntegerForKey(pKey.data());
	}
	return 0;
}

int QtScriptCCUserDefault::getIntegerForKey(const QByteArray& pKey, int defaultValue)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getIntegerForKey(pKey.data(), defaultValue);
	}
	return 0;
}

double QtScriptCCUserDefault::getDoubleForKey(const QByteArray& pKey)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getDoubleForKey(pKey.data());
	}
	return static_cast<double>(0);
}

double QtScriptCCUserDefault::getDoubleForKey(const QByteArray& pKey, double defaultValue)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		return __o->getDoubleForKey(pKey.data(), defaultValue);
	}
	return static_cast<double>(0);
}

void QtScriptCCUserDefault::setBoolForKey(const QByteArray& pKey, bool value)
{
	auto __o = this->thiz<CCUserDefault *>();
	if (__o)
	{
		__o->setBoolForKey(pKey.data(), value);
	}
}

QScriptValue QtScriptCCUserDefault::purgeSharedUserDefault(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCUserDefault::purgeSharedUserDefault();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCUserDefault::purgeSharedUserDefault");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCUserDefault::isXMLFileExist(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCUserDefault::isXMLFileExist());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCUserDefault::isXMLFileExist");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCUserDefault::getXMLFilePath(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(QByteArray(CCUserDefault::getXMLFilePath().c_str(), int(CCUserDefault::getXMLFilePath().size())));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCUserDefault::getXMLFilePath");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCUserDefault::sharedUserDefault(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCUserDefault::sharedUserDefault());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCUserDefault::sharedUserDefault");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCIMEDelegate::QtScriptCCIMEDelegate(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCIMEDelegate *, false>(engine, className)
{
}

QtScriptCCIMEDelegate::QtScriptCCIMEDelegate(QScriptEngine *engine)
	: QtScriptCCIMEDelegate(engine, "IMEDelegate")
{
}

void QtScriptCCIMEDelegate::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCIMEDelegate, QtScriptCCIMEDelegate>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCIMEDelegate::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCIMEDelegate::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCIMEDelegate::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCIMEDelegate");
	return false;
}

bool QtScriptCCIMEDelegate::detachWithIME()
{
	auto __o = this->thiz<CCIMEDelegate *>();
	if (__o)
	{
		return __o->detachWithIME();
	}
	return false;
}

bool QtScriptCCIMEDelegate::attachWithIME()
{
	auto __o = this->thiz<CCIMEDelegate *>();
	if (__o)
	{
		return __o->attachWithIME();
	}
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCIMEDispatcher::QtScriptCCIMEDispatcher(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCIMEDispatcher *, false>(engine, className)
{
}

QtScriptCCIMEDispatcher::QtScriptCCIMEDispatcher(QScriptEngine *engine)
	: QtScriptCCIMEDispatcher(engine, "IMEDispatcher")
{
}

void QtScriptCCIMEDispatcher::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	QScriptValue inherit;
	auto ctor = RegisterT<CCIMEDispatcher, QtScriptCCIMEDispatcher>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedDispatcher", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCIMEDispatcher::sharedDispatcher)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCIMEDispatcher::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCIMEDispatcher::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCIMEDispatcher::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCIMEDispatcher");
	return false;
}

QByteArray QtScriptCCIMEDispatcher::getContentText()
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		return QByteArray(__o->getContentText());
	}
	return QByteArray();
}

void QtScriptCCIMEDispatcher::dispatchDeleteBackward()
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		__o->dispatchDeleteBackward();
	}
}

void QtScriptCCIMEDispatcher::dispatchInsertText(const QByteArray& pText, int nLen)
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		__o->dispatchInsertText(pText.data(), nLen);
	}
}

void QtScriptCCIMEDispatcher::dispatchKeyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		__o->dispatchKeyboardWillShow(info);
	}
}

void QtScriptCCIMEDispatcher::dispatchKeyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		__o->dispatchKeyboardDidShow(info);
	}
}

void QtScriptCCIMEDispatcher::dispatchKeyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		__o->dispatchKeyboardWillHide(info);
	}
}

void QtScriptCCIMEDispatcher::dispatchKeyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
	auto __o = this->thiz<CCIMEDispatcher *>();
	if (__o)
	{
		__o->dispatchKeyboardDidHide(info);
	}
}

QScriptValue QtScriptCCIMEDispatcher::sharedDispatcher(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCIMEDispatcher::sharedDispatcher());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCIMEDispatcher::sharedDispatcher");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTextFieldDelegate::QtScriptCCTextFieldDelegate(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCTextFieldDelegate *, false>(engine, className)
{
}

QtScriptCCTextFieldDelegate::QtScriptCCTextFieldDelegate(QScriptEngine *engine)
	: QtScriptCCTextFieldDelegate(engine, "TextFieldDelegate")
{
}

void QtScriptCCTextFieldDelegate::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCTextFieldDelegate, QtScriptCCTextFieldDelegate>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCTextFieldDelegate::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTextFieldDelegate::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTextFieldDelegate::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTextFieldDelegate;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTextFieldDelegate constructor");
	return false;
}

bool QtScriptCCTextFieldDelegate::onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* sender)
{
	auto __o = this->thiz<CCTextFieldDelegate *>();
	if (__o)
	{
		return __o->onTextFieldAttachWithIME(sender);
	}
	return false;
}

bool QtScriptCCTextFieldDelegate::onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF* sender, const QByteArray& delText, int nLen)
{
	auto __o = this->thiz<CCTextFieldDelegate *>();
	if (__o)
	{
		return __o->onTextFieldDeleteBackward(sender, delText.data(), nLen);
	}
	return false;
}

bool QtScriptCCTextFieldDelegate::onDraw(cocos2d::CCTextFieldTTF* sender)
{
	auto __o = this->thiz<CCTextFieldDelegate *>();
	if (__o)
	{
		return __o->onDraw(sender);
	}
	return false;
}

bool QtScriptCCTextFieldDelegate::onTextFieldInsertText(cocos2d::CCTextFieldTTF* sender, const QByteArray& text, int nLen)
{
	auto __o = this->thiz<CCTextFieldDelegate *>();
	if (__o)
	{
		return __o->onTextFieldInsertText(sender, text.data(), nLen);
	}
	return false;
}

bool QtScriptCCTextFieldDelegate::onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* sender)
{
	auto __o = this->thiz<CCTextFieldDelegate *>();
	if (__o)
	{
		return __o->onTextFieldDetachWithIME(sender);
	}
	return false;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTextFieldTTF::QtScriptCCTextFieldTTF(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCLabelTTF(engine, className)
{
}

QtScriptCCTextFieldTTF::QtScriptCCTextFieldTTF(QScriptEngine *engine)
	: QtScriptCCTextFieldTTF(engine, "TextFieldTTF")
{
}

void QtScriptCCTextFieldTTF::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCLabelTTF *>());
	auto ctor = RegisterT<CCTextFieldTTF, QtScriptCCTextFieldTTF>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("textFieldWithPlaceHolder", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTextFieldTTF::textFieldWithPlaceHolder)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTextFieldTTF::getCharCount()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->getCharCount();
	}
	return 0;
}

cocos2d::CCTextFieldDelegate* QtScriptCCTextFieldTTF::getDelegate()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->getDelegate();
	}
	return nullptr;
}

void QtScriptCCTextFieldTTF::setSecureTextEntry(bool value)
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		__o->setSecureTextEntry(value);
	}
}

cocos2d::_ccColor3B QtScriptCCTextFieldTTF::getColorSpaceHolder()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->getColorSpaceHolder();
	}
	return cocos2d::_ccColor3B();
}

bool QtScriptCCTextFieldTTF::initWithPlaceHolder(const QByteArray& placeholder, const QByteArray& fontName, float fontSize)
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->initWithPlaceHolder(placeholder.data(), fontName.data(), fontSize);
	}
	return false;
}

bool QtScriptCCTextFieldTTF::initWithPlaceHolder(const QByteArray& placeholder, const cocos2d::CCSize& dimensions, int alignment, const QByteArray& fontName, float fontSize)
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->initWithPlaceHolder(placeholder.data(), dimensions, cocos2d::CCTextAlignment(alignment), fontName.data(), fontSize);
	}
	return false;
}

void QtScriptCCTextFieldTTF::setColorSpaceHolder(const cocos2d::_ccColor3B& color)
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		__o->setColorSpaceHolder(color);
	}
}

bool QtScriptCCTextFieldTTF::detachWithIME()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->detachWithIME();
	}
	return false;
}

void QtScriptCCTextFieldTTF::setDelegate(cocos2d::CCTextFieldDelegate* var)
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		__o->setDelegate(var);
	}
}

void QtScriptCCTextFieldTTF::setPlaceHolder(const QByteArray& text)
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		__o->setPlaceHolder(text.data());
	}
}

bool QtScriptCCTextFieldTTF::isSecureTextEntry()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->isSecureTextEntry();
	}
	return false;
}

QByteArray QtScriptCCTextFieldTTF::getPlaceHolder()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return QByteArray(__o->getPlaceHolder());
	}
	return QByteArray();
}

bool QtScriptCCTextFieldTTF::attachWithIME()
{
	auto __o = this->thiz<CCTextFieldTTF *>();
	if (__o)
	{
		return __o->attachWithIME();
	}
	return false;
}

QScriptValue QtScriptCCTextFieldTTF::textFieldWithPlaceHolder(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 5))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<float>(context->argument(2));
			return __e->toScriptValue(CCTextFieldTTF::textFieldWithPlaceHolder(arg0, arg1, arg2));
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto arg1 = qscriptvalue_cast<cocos2d::CCSize>(context->argument(1));
			auto tmp_2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg2 = cocos2d::CCTextAlignment(tmp_2);
			auto tmp_3 = qscriptvalue_cast<QByteArray>(context->argument(3));
			auto arg3 = tmp_3.data();
			auto arg4 = qscriptvalue_cast<float>(context->argument(4));
			return __e->toScriptValue(CCTextFieldTTF::textFieldWithPlaceHolder(arg0, arg1, arg2, arg3, arg4));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextFieldTTF::textFieldWithPlaceHolder");
	return __e->uncaughtException();
}

int QtScriptCCTextFieldTTF::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTextFieldTTF::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTextFieldTTF::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTextFieldTTF();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextFieldTTF constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTextureCache::QtScriptCCTextureCache(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTextureCache::QtScriptCCTextureCache(QScriptEngine *engine)
	: QtScriptCCTextureCache(engine, "TextureCache")
{
}

void QtScriptCCTextureCache::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTextureCache, QtScriptCCTextureCache>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("sharedTextureCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTextureCache::sharedTextureCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("purgeSharedTextureCache", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTextureCache::purgeSharedTextureCache)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
	ctor.setProperty("reloadAllTextures", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTextureCache::reloadAllTextures)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCTextureCache::dumpCachedTextureInfo()
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		__o->dumpCachedTextureInfo();
	}
}

bool QtScriptCCTextureCache::reloadTexture(const QByteArray& fileName)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->reloadTexture(fileName.data());
	}
	return false;
}

cocos2d::CCTexture2D* QtScriptCCTextureCache::addETCImage(const QByteArray& filename)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->addETCImage(filename.data());
	}
	return nullptr;
}

QByteArray QtScriptCCTextureCache::description()
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return QByteArray(__o->description());
	}
	return QByteArray();
}

cocos2d::CCTexture2D* QtScriptCCTextureCache::addUIImage(cocos2d::CCImage* image, const QByteArray& key)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->addUIImage(image, key.data());
	}
	return nullptr;
}

void QtScriptCCTextureCache::removeTextureForKey(const QByteArray& textureKeyName)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		__o->removeTextureForKey(textureKeyName.data());
	}
}

cocos2d::CCTexture2D* QtScriptCCTextureCache::textureForKey(const QByteArray& key)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->textureForKey(key.data());
	}
	return nullptr;
}

cocos2d::CCDictionary* QtScriptCCTextureCache::snapshotTextures()
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->snapshotTextures();
	}
	return nullptr;
}

cocos2d::CCTexture2D* QtScriptCCTextureCache::addPVRImage(const QByteArray& filename)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->addPVRImage(filename.data());
	}
	return nullptr;
}

cocos2d::CCTexture2D* QtScriptCCTextureCache::addImage(const QByteArray& fileimage)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		return __o->addImage(fileimage.data());
	}
	return nullptr;
}

void QtScriptCCTextureCache::removeAllTextures()
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		__o->removeAllTextures();
	}
}

void QtScriptCCTextureCache::removeUnusedTextures()
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		__o->removeUnusedTextures();
	}
}

void QtScriptCCTextureCache::removeTexture(cocos2d::CCTexture2D* texture)
{
	auto __o = this->thiz<CCTextureCache *>();
	if (__o)
	{
		__o->removeTexture(texture);
	}
}

QScriptValue QtScriptCCTextureCache::sharedTextureCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCTextureCache::sharedTextureCache());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureCache::sharedTextureCache");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTextureCache::purgeSharedTextureCache(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCTextureCache::purgeSharedTextureCache();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureCache::purgeSharedTextureCache");
	return __e->uncaughtException();
}

QScriptValue QtScriptCCTextureCache::reloadAllTextures(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			CCTextureCache::reloadAllTextures();
			return __e->undefinedValue();
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureCache::reloadAllTextures");
	return __e->uncaughtException();
}

int QtScriptCCTextureCache::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTextureCache::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTextureCache::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTextureCache();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTextureCache constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCParallaxNode::QtScriptCCParallaxNode(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCNode(engine, className)
{
}

QtScriptCCParallaxNode::QtScriptCCParallaxNode(QScriptEngine *engine)
	: QtScriptCCParallaxNode(engine, "ParallaxNode")
{
}

void QtScriptCCParallaxNode::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCNode *>());
	auto ctor = RegisterT<CCParallaxNode, QtScriptCCParallaxNode>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCParallaxNode::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCParallaxNode::addChild(cocos2d::CCNode* child, unsigned int zOrder, int tag)
{
	auto __o = this->thiz<CCParallaxNode *>();
	if (__o)
	{
		__o->addChild(child, zOrder, tag);
	}
}

void QtScriptCCParallaxNode::addChild(cocos2d::CCNode* child, unsigned int z, const cocos2d::CCPoint& parallaxRatio, const cocos2d::CCPoint& positionOffset)
{
	auto __o = this->thiz<CCParallaxNode *>();
	if (__o)
	{
		__o->addChild(child, z, parallaxRatio, positionOffset);
	}
}

QScriptValue QtScriptCCParallaxNode::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCParallaxNode::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParallaxNode::create");
	return __e->uncaughtException();
}

int QtScriptCCParallaxNode::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCParallaxNode::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCParallaxNode::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCParallaxNode();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCParallaxNode constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTileMapAtlas::QtScriptCCTileMapAtlas(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCAtlasNode(engine, className)
{
}

QtScriptCCTileMapAtlas::QtScriptCCTileMapAtlas(QScriptEngine *engine)
	: QtScriptCCTileMapAtlas(engine, "TileMapAtlas")
{
}

void QtScriptCCTileMapAtlas::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCAtlasNode *>());
	auto ctor = RegisterT<CCTileMapAtlas, QtScriptCCTileMapAtlas>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTileMapAtlas::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

bool QtScriptCCTileMapAtlas::initWithTileFile(const QByteArray& tile, const QByteArray& mapFile, int tileWidth, int tileHeight)
{
	auto __o = this->thiz<CCTileMapAtlas *>();
	if (__o)
	{
		return __o->initWithTileFile(tile.data(), mapFile.data(), tileWidth, tileHeight);
	}
	return false;
}

void QtScriptCCTileMapAtlas::releaseMap()
{
	auto __o = this->thiz<CCTileMapAtlas *>();
	if (__o)
	{
		__o->releaseMap();
	}
}

cocos2d::_ccColor3B QtScriptCCTileMapAtlas::tileAt(const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCTileMapAtlas *>();
	if (__o)
	{
		return __o->tileAt(position);
	}
	return cocos2d::_ccColor3B();
}

cocos2d::sImageTGA* QtScriptCCTileMapAtlas::getTGAInfo()
{
	auto __o = this->thiz<CCTileMapAtlas *>();
	if (__o)
	{
		return __o->getTGAInfo();
	}
	return nullptr;
}

void QtScriptCCTileMapAtlas::setTile(const cocos2d::_ccColor3B& tile, const cocos2d::CCPoint& position)
{
	auto __o = this->thiz<CCTileMapAtlas *>();
	if (__o)
	{
		__o->setTile(tile, position);
	}
}

void QtScriptCCTileMapAtlas::setTGAInfo(cocos2d::sImageTGA* var)
{
	auto __o = this->thiz<CCTileMapAtlas *>();
	if (__o)
	{
		__o->setTGAInfo(var);
	}
}

QScriptValue QtScriptCCTileMapAtlas::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 4, 4))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 4:
		{
			auto tmp_0 = qscriptvalue_cast<QByteArray>(context->argument(0));
			auto arg0 = tmp_0.data();
			auto tmp_1 = qscriptvalue_cast<QByteArray>(context->argument(1));
			auto arg1 = tmp_1.data();
			auto arg2 = qscriptvalue_cast<int>(context->argument(2));
			auto arg3 = qscriptvalue_cast<int>(context->argument(3));
			return __e->toScriptValue(CCTileMapAtlas::create(arg0, arg1, arg2, arg3));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTileMapAtlas::create");
	return __e->uncaughtException();
}

int QtScriptCCTileMapAtlas::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTileMapAtlas::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTileMapAtlas::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTileMapAtlas();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTileMapAtlas constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptccTouchHandlerHelperData::QtScriptccTouchHandlerHelperData(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<ccTouchHandlerHelperData, false>(engine, className)
{
}

QtScriptccTouchHandlerHelperData::QtScriptccTouchHandlerHelperData(QScriptEngine *engine)
	: QtScriptccTouchHandlerHelperData(engine, "ccTouchHandlerHelperData")
{
}

void QtScriptccTouchHandlerHelperData::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<ccTouchHandlerHelperData, QtScriptccTouchHandlerHelperData>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptccTouchHandlerHelperData::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptccTouchHandlerHelperData::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptccTouchHandlerHelperData::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		Q_UNUSED(out);
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::ccTouchHandlerHelperData constructor");
	return false;
}

int QtScriptccTouchHandlerHelperData::_public_field_get_type() const
{
	auto object = thiz<ccTouchHandlerHelperData *>();
	if (object)
	{
		return object->m_type;
	}
	return static_cast<int>(0);
}

void QtScriptccTouchHandlerHelperData::_public_field_set_type(int value)
{
	auto object = thiz<ccTouchHandlerHelperData *>();
	if (object)
	{
		object->m_type = value;
	}
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTouchHandler::QtScriptCCTouchHandler(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTouchHandler::QtScriptCCTouchHandler(QScriptEngine *engine)
	: QtScriptCCTouchHandler(engine, "TouchHandler")
{
}

void QtScriptCCTouchHandler::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTouchHandler, QtScriptCCTouchHandler>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("handlerWithDelegate", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTouchHandler::handlerWithDelegate)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTouchHandler::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTouchHandler::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTouchHandler::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTouchHandler;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTouchHandler constructor");
	return false;
}

cocos2d::CCTouchDelegate* QtScriptCCTouchHandler::getDelegate()
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		return __o->getDelegate();
	}
	return nullptr;
}

bool QtScriptCCTouchHandler::initWithDelegate(cocos2d::CCTouchDelegate* pDelegate, int nPriority)
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		return __o->initWithDelegate(pDelegate, nPriority);
	}
	return false;
}

int QtScriptCCTouchHandler::getPriority()
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		return __o->getPriority();
	}
	return 0;
}

void QtScriptCCTouchHandler::setPriority(int nPriority)
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		__o->setPriority(nPriority);
	}
}

int QtScriptCCTouchHandler::getEnabledSelectors()
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		return __o->getEnabledSelectors();
	}
	return 0;
}

void QtScriptCCTouchHandler::setDelegate(cocos2d::CCTouchDelegate* pDelegate)
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		__o->setDelegate(pDelegate);
	}
}

void QtScriptCCTouchHandler::setEnalbedSelectors(int nValue)
{
	auto __o = this->thiz<CCTouchHandler *>();
	if (__o)
	{
		__o->setEnalbedSelectors(nValue);
	}
}

QScriptValue QtScriptCCTouchHandler::handlerWithDelegate(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTouchDelegate*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<int>(context->argument(1));
			return __e->toScriptValue(CCTouchHandler::handlerWithDelegate(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTouchHandler::handlerWithDelegate");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCStandardTouchHandler::QtScriptCCStandardTouchHandler(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTouchHandler(engine, className)
{
}

QtScriptCCStandardTouchHandler::QtScriptCCStandardTouchHandler(QScriptEngine *engine)
	: QtScriptCCStandardTouchHandler(engine, "StandardTouchHandler")
{
}

void QtScriptCCStandardTouchHandler::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTouchHandler *>());
	auto ctor = RegisterT<CCStandardTouchHandler, QtScriptCCStandardTouchHandler>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("handlerWithDelegate", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCStandardTouchHandler::handlerWithDelegate)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCStandardTouchHandler::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCStandardTouchHandler::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCStandardTouchHandler::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCStandardTouchHandler;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCStandardTouchHandler constructor");
	return false;
}

QScriptValue QtScriptCCStandardTouchHandler::handlerWithDelegate(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTouchDelegate*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<int>(context->argument(1));
			return __e->toScriptValue(CCStandardTouchHandler::handlerWithDelegate(arg0, arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCStandardTouchHandler::handlerWithDelegate");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTargetedTouchHandler::QtScriptCCTargetedTouchHandler(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCTouchHandler(engine, className)
{
}

QtScriptCCTargetedTouchHandler::QtScriptCCTargetedTouchHandler(QScriptEngine *engine)
	: QtScriptCCTargetedTouchHandler(engine, "TargetedTouchHandler")
{
}

void QtScriptCCTargetedTouchHandler::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCTouchHandler *>());
	auto ctor = RegisterT<CCTargetedTouchHandler, QtScriptCCTargetedTouchHandler>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("handlerWithDelegate", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTargetedTouchHandler::handlerWithDelegate)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCTargetedTouchHandler::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTargetedTouchHandler::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTargetedTouchHandler::constructObject(QScriptContext *context, NativeObjectType &out)
{
	if (context->argumentCount() == 0)
	{
		out = new CCTargetedTouchHandler;
		return true;
	}

	QtScriptUtils::badArgumentsException(context,
		"cocos2d::CCTargetedTouchHandler constructor");
	return false;
}

bool QtScriptCCTargetedTouchHandler::isSwallowsTouches()
{
	auto __o = this->thiz<CCTargetedTouchHandler *>();
	if (__o)
	{
		return __o->isSwallowsTouches();
	}
	return false;
}

cocos2d::CCSet* QtScriptCCTargetedTouchHandler::getClaimedTouches()
{
	auto __o = this->thiz<CCTargetedTouchHandler *>();
	if (__o)
	{
		return __o->getClaimedTouches();
	}
	return nullptr;
}

void QtScriptCCTargetedTouchHandler::setSwallowsTouches(bool bSwallowsTouches)
{
	auto __o = this->thiz<CCTargetedTouchHandler *>();
	if (__o)
	{
		__o->setSwallowsTouches(bSwallowsTouches);
	}
}

bool QtScriptCCTargetedTouchHandler::initWithDelegate(cocos2d::CCTouchDelegate* pDelegate, int nPriority, bool bSwallow)
{
	auto __o = this->thiz<CCTargetedTouchHandler *>();
	if (__o)
	{
		return __o->initWithDelegate(pDelegate, nPriority, bSwallow);
	}
	return false;
}

QScriptValue QtScriptCCTargetedTouchHandler::handlerWithDelegate(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 3, 3))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 3:
		{
			auto arg0 = qscriptvalue_cast<cocos2d::CCTouchDelegate*>(context->argument(0));
			auto arg1 = qscriptvalue_cast<int>(context->argument(1));
			auto arg2 = qscriptvalue_cast<bool>(context->argument(2));
			return __e->toScriptValue(CCTargetedTouchHandler::handlerWithDelegate(arg0, arg1, arg2));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTargetedTouchHandler::handlerWithDelegate");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCTimer::QtScriptCCTimer(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCTimer::QtScriptCCTimer(QScriptEngine *engine)
	: QtScriptCCTimer(engine, "Timer")
{
}

void QtScriptCCTimer::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCTimer, QtScriptCCTimer>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("timerWithHandler", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCTimer::timerWithHandler)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCTimer::setInterval(float fInterval)
{
	auto __o = this->thiz<CCTimer *>();
	if (__o)
	{
		__o->setInterval(fInterval);
	}
}

float QtScriptCCTimer::getInterval()
{
	auto __o = this->thiz<CCTimer *>();
	if (__o)
	{
		return __o->getInterval();
	}
	return static_cast<float>(0);
}

bool QtScriptCCTimer::initWithHandler(const QScriptValue& arg0, float arg1)
{
	auto __o = this->thiz<CCTimer *>();
	if (__o)
	{
		return __o->initWithScriptHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0), arg1);
	}
	return false;
}

QScriptValue QtScriptCCTimer::timerWithHandler(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 2, 2))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 2:
		{
			auto arg0 = context->argument(0);
			auto arg1 = qscriptvalue_cast<float>(context->argument(1));
			return __e->toScriptValue(CCTimer::timerWithScriptHandler(QtCocosScriptEngine::instance()->retainJSObject(arg0), arg1));
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTimer::timerWithScriptHandler");
	return __e->uncaughtException();
}

int QtScriptCCTimer::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCTimer::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCTimer::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCTimer();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCTimer constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCScheduler::QtScriptCCScheduler(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCScheduler::QtScriptCCScheduler(QScriptEngine *engine)
	: QtScriptCCScheduler(engine, "Scheduler")
{
}

void QtScriptCCScheduler::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCScheduler, QtScriptCCScheduler>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

cocos2d::CCSet* QtScriptCCScheduler::pauseAllTargets()
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		return __o->pauseAllTargets();
	}
	return nullptr;
}

void QtScriptCCScheduler::setTimeScale(float fTimeScale)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->setTimeScale(fTimeScale);
	}
}

void QtScriptCCScheduler::unscheduleUpdateForTarget(const cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->unscheduleUpdateForTarget(pTarget);
	}
}

void QtScriptCCScheduler::scheduleUpdateForTarget(cocos2d::CCObject* pTarget, int nPriority, bool bPaused)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->scheduleUpdateForTarget(pTarget, nPriority, bPaused);
	}
}

unsigned QtScriptCCScheduler::schedule(const QScriptValue& arg0, float arg1, bool arg2)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		return static_cast<unsigned>(__o->scheduleScriptFunc(QtCocosScriptEngine::instance()->retainJSObject(arg0), arg1, arg2));
	}
	return static_cast<unsigned>(0);
}

void QtScriptCCScheduler::unscheduleAllWithMinPriority(int nMinPriority)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->unscheduleAllWithMinPriority(nMinPriority);
	}
}

bool QtScriptCCScheduler::isTargetPaused(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		return __o->isTargetPaused(pTarget);
	}
	return false;
}

void QtScriptCCScheduler::resumeTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->resumeTarget(pTarget);
	}
}

void QtScriptCCScheduler::unscheduleScriptEntry(unsigned int uScheduleScriptEntryID)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->unscheduleScriptEntry(uScheduleScriptEntryID);
	}
}

void QtScriptCCScheduler::unscheduleAll()
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->unscheduleAll();
	}
}

void QtScriptCCScheduler::resumeTargets(cocos2d::CCSet* targetsToResume)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->resumeTargets(targetsToResume);
	}
}

void QtScriptCCScheduler::unscheduleAllForTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->unscheduleAllForTarget(pTarget);
	}
}

void QtScriptCCScheduler::pauseTarget(cocos2d::CCObject* pTarget)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		__o->pauseTarget(pTarget);
	}
}

cocos2d::CCSet* QtScriptCCScheduler::pauseAllTargetsWithMinPriority(int nMinPriority)
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		return __o->pauseAllTargetsWithMinPriority(nMinPriority);
	}
	return nullptr;
}

float QtScriptCCScheduler::getTimeScale()
{
	auto __o = this->thiz<CCScheduler *>();
	if (__o)
	{
		return __o->getTimeScale();
	}
	return static_cast<float>(0);
}

int QtScriptCCScheduler::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCScheduler::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCScheduler::constructObject(QScriptContext *context, NativeObjectType &out)
{
	auto __e = context->engine();
	Q_UNUSED(__e);
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCScheduler();
			ok = true;
			break;
		}
	}
	
	if (!ok)
	{
		QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCScheduler constructor");
	}
	return ok;
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCComponent::QtScriptCCComponent(QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCObject(engine, className)
{
}

QtScriptCCComponent::QtScriptCCComponent(QScriptEngine *engine)
	: QtScriptCCComponent(engine, "Component")
{
}

void QtScriptCCComponent::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCObject *>());
	auto ctor = RegisterT<CCComponent, QtScriptCCComponent>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create", engine->newFunction(
		static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
			&QtScriptCCComponent::create)),
			QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

int QtScriptCCComponent::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCComponent::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCComponent::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCComponent");
	return false;
}

void QtScriptCCComponent::setEnabled(bool b)
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		__o->setEnabled(b);
	}
}

void QtScriptCCComponent::onEnter()
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		__o->onEnter();
	}
}

void QtScriptCCComponent::onExit()
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		__o->onExit();
	}
}

void QtScriptCCComponent::setName(const QByteArray& pName)
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		__o->setName(pName.data());
	}
}

bool QtScriptCCComponent::isEnabled()
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		return __o->isEnabled();
	}
	return false;
}

cocos2d::CCNode* QtScriptCCComponent::getOwner()
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		return __o->getOwner();
	}
	return nullptr;
}

bool QtScriptCCComponent::init()
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		return __o->init();
	}
	return false;
}

void QtScriptCCComponent::setOwner(cocos2d::CCNode* pOwner)
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		__o->setOwner(pOwner);
	}
}

QByteArray QtScriptCCComponent::getName()
{
	auto __o = this->thiz<CCComponent *>();
	if (__o)
	{
		return QByteArray(__o->getName());
	}
	return QByteArray();
}

QScriptValue QtScriptCCComponent::create(QScriptContext *context, QScriptEngine* __e)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return __e->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return __e->toScriptValue(CCComponent::create());
		}
	}

	QtScriptUtils::badArgumentsException(context,
			"cocos2d::CCComponent::create");
	return __e->uncaughtException();
}

} // end of cocos2d

namespace cocos2d {
QtScriptCCComponentContainer::QtScriptCCComponentContainer(QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<CCComponentContainer *, false>(engine, className)
{
}

QtScriptCCComponentContainer::QtScriptCCComponentContainer(QScriptEngine *engine)
	: QtScriptCCComponentContainer(engine, "ComponentContainer")
{
}

void QtScriptCCComponentContainer::Register(const QScriptValue &targetNamespace)
{
	QScriptValue inherit;
	auto ctor = RegisterT<CCComponentContainer, QtScriptCCComponentContainer>(targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
}

int QtScriptCCComponentContainer::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCComponentContainer::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCComponentContainer::constructObject(QScriptContext *context, NativeObjectType &out)
{
	Q_UNUSED(out);
	QtScriptUtils::noPublicConstructorException(context,
		"cocos2d::CCComponentContainer");
	return false;
}

cocos2d::CCComponent* QtScriptCCComponentContainer::get(const QByteArray& pName)
{
	auto __o = this->thiz<CCComponentContainer *>();
	if (__o)
	{
		return __o->get(pName.data());
	}
	return nullptr;
}

void QtScriptCCComponentContainer::visit(float fDelta)
{
	auto __o = this->thiz<CCComponentContainer *>();
	if (__o)
	{
		__o->visit(fDelta);
	}
}

bool QtScriptCCComponentContainer::remove(const QByteArray& pName)
{
	auto __o = this->thiz<CCComponentContainer *>();
	if (__o)
	{
		return __o->remove(pName.data());
	}
	return false;
}

void QtScriptCCComponentContainer::removeAll()
{
	auto __o = this->thiz<CCComponentContainer *>();
	if (__o)
	{
		__o->removeAll();
	}
}

bool QtScriptCCComponentContainer::add(cocos2d::CCComponent* pCom)
{
	auto __o = this->thiz<CCComponentContainer *>();
	if (__o)
	{
		return __o->add(pCom);
	}
	return false;
}

bool QtScriptCCComponentContainer::isEmpty()
{
	auto __o = this->thiz<CCComponentContainer *>();
	if (__o)
	{
		return __o->isEmpty();
	}
	return false;
}

} // end of cocos2d

void qtscript_register_all_cocos2dx(QScriptEngine* engine)
{
	QScriptValue targetNamespace;
	targetNamespace = QtScriptUtils::getNamespaceObject(engine, "cc");
	cocos2d::QtScriptCCShaderCache::Register(targetNamespace);
	cocos2d::QtScriptCCDataVisitor::Register(targetNamespace);
	cocos2d::QtScriptCCAction::Register(targetNamespace);
	cocos2d::QtScriptCCFiniteTimeAction::Register(targetNamespace);
	cocos2d::QtScriptCCActionInterval::Register(targetNamespace);
	cocos2d::QtScriptCCRepeat::Register(targetNamespace);
	cocos2d::QtScriptCCNode::Register(targetNamespace);
	cocos2d::QtScriptCCSpriteBatchNode::Register(targetNamespace);
	cocos2d::QtScriptCCLabelBMFont::Register(targetNamespace);
	cocos2d::QtScriptCCTintBy::Register(targetNamespace);
	cocos2d::QtScriptCCSpriteFrame::Register(targetNamespace);
	cocos2d::QtScriptCCParticleSystem::Register(targetNamespace);
	cocos2d::QtScriptCCParticleSystemQuad::Register(targetNamespace);
	cocos2d::QtScriptCCParticleExplosion::Register(targetNamespace);
	cocos2d::QtScriptCCScene::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionScene::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionEaseScene::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionMoveInL::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionMoveInT::Register(targetNamespace);
	cocos2d::QtScript_ccV3F_C4B_T2F::Register(targetNamespace);
	cocos2d::QtScriptCCGridAction::Register(targetNamespace);
	cocos2d::QtScriptCCTiledGrid3DAction::Register(targetNamespace);
	cocos2d::QtScriptCCSplitCols::Register(targetNamespace);
	cocos2d::QtScriptCCFadeOutTRTiles::Register(targetNamespace);
	cocos2d::QtScriptCCFadeOutBLTiles::Register(targetNamespace);
	cocos2d::QtScriptCCNodeRGBA::Register(targetNamespace);
	cocos2d::QtScriptCCProgressTimer::Register(targetNamespace);
	cocos2d::QtScriptCCGrid3DAction::Register(targetNamespace);
	cocos2d::QtScriptCCWaves::Register(targetNamespace);
	cocos2d::QtScriptCCActionInstant::Register(targetNamespace);
	cocos2d::QtScriptCCCallFunc::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSlideInL::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSlideInT::Register(targetNamespace);
	cocos2d::QtScriptCCRipple3D::Register(targetNamespace);
	cocos2d::QtScriptCCParticleSmoke::Register(targetNamespace);
	cocos2d::QtScriptCCParticleFire::Register(targetNamespace);
	cocos2d::QtScriptCCParticleGalaxy::Register(targetNamespace);
	cocos2d::QtScriptCCBezierBy::Register(targetNamespace);
	cocos2d::QtScriptCCProfiler::Register(targetNamespace);
	cocos2d::QtScriptCCStopGrid::Register(targetNamespace);
	cocos2d::QtScriptCCActionManager::Register(targetNamespace);
	cocos2d::QtScript_ccFontShadow::Register(targetNamespace);
	cocos2d::QtScriptCCFloat::Register(targetNamespace);
	cocos2d::QtScriptCCActionEase::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBounce::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBounceIn::Register(targetNamespace);
	cocos2d::QtScriptCCEaseRateAction::Register(targetNamespace);
	cocos2d::QtScriptCCJumpBy::Register(targetNamespace);
	cocos2d::QtScriptCCJumpTo::Register(targetNamespace);
	cocos2d::QtScriptCCTexture2D::Register(targetNamespace);
	cocos2d::QtScriptCCCardinalSplineTo::Register(targetNamespace);
	cocos2d::QtScriptCCCardinalSplineBy::Register(targetNamespace);
	cocos2d::QtScriptCCCatmullRomBy::Register(targetNamespace);
	cocos2d::QtScriptCCParticleFlower::Register(targetNamespace);
	cocos2d::QtScriptCCTargetedAction::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFade::Register(targetNamespace);
	cocos2d::QtScriptCCArray::Register(targetNamespace);
	cocos2d::QtScriptCCParallaxNode::Register(targetNamespace);
	cocos2d::QtScriptCCBool::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSplitCols::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSplitRows::Register(targetNamespace);
	cocos2d::QtScriptCCTimer::Register(targetNamespace);
	cocos2d::QtScriptCCScriptHandlerEntry::Register(targetNamespace);
	cocos2d::QtScriptCCSchedulerScriptHandlerEntry::Register(targetNamespace);
	cocos2d::QtScript_ccQuad2::Register(targetNamespace);
	cocos2d::QtScript_ccQuad3::Register(targetNamespace);
	cocos2d::QtScriptCCActionTweenDelegate::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBounceOut::Register(targetNamespace);
	cocos2d::QtScriptCCEaseExponentialIn::Register(targetNamespace);
	cocos2d::QtScriptCCParticleFireworks::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionCrossFade::Register(targetNamespace);
	cocos2d::QtScriptCCSpriteFrameCache::Register(targetNamespace);
	cocos2d::QtScriptCCSkewTo::Register(targetNamespace);
	cocos2d::QtScriptCCPoolManager::Register(targetNamespace);
	cocos2d::QtScriptCCEGLViewProtocol::Register(targetNamespace);
	cocos2d::QtScriptCCLayer::Register(targetNamespace);
	cocos2d::QtScriptCCLayerRGBA::Register(targetNamespace);
	cocos2d::QtScriptCCLayerColor::Register(targetNamespace);
	cocos2d::QtScriptCCLayerGradient::Register(targetNamespace);
	cocos2d::QtScriptCCShaky3D::Register(targetNamespace);
	cocos2d::QtScriptCCRotateBy::Register(targetNamespace);
	cocos2d::QtScriptCCPageTurn3D::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgress::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgressInOut::Register(targetNamespace);
	cocos2d::QtScriptCCComponentContainer::Register(targetNamespace);
	cocos2d::QtScriptCCTwirl::Register(targetNamespace);
	cocos2d::QtScriptsCCParticle_ModeB::Register(targetNamespace);
	cocos2d::QtScriptCCLayerMultiplex::Register(targetNamespace);
	cocos2d::QtScriptCCImage::Register(targetNamespace);
	cocos2d::QtScriptTypeInfo::Register(targetNamespace);
	cocos2d::QtScriptCCCallFuncN::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSceneOriented::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionZoomFlipAngular::Register(targetNamespace);
	cocos2d::QtScriptCCToggleVisibility::Register(targetNamespace);
	cocos2d::QtScriptCCTouchScriptHandlerEntry::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFadeTR::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFadeUp::Register(targetNamespace);
	cocos2d::QtScriptCCGridBase::Register(targetNamespace);
	cocos2d::QtScriptCCShatteredTiles3D::Register(targetNamespace);
	cocos2d::QtScriptCCZone::Register(targetNamespace);
	cocos2d::QtScriptCCShow::Register(targetNamespace);
	cocos2d::QtScript_ccV2F_C4B_T2F_Triangle::Register(targetNamespace);
	cocos2d::QtScriptCCGLProgram::Register(targetNamespace);
	cocos2d::QtScriptCCAccelDeccelAmplitude::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionRotoZoom::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBounceInOut::Register(targetNamespace);
	cocos2d::QtScriptCCAtlasNode::Register(targetNamespace);
	cocos2d::QtScriptCCTileMapAtlas::Register(targetNamespace);
	cocos2d::QtScriptCCRenderTexture::Register(targetNamespace);
	cocos2d::QtScriptCCSprite::Register(targetNamespace);
	cocos2d::QtScriptCCLabelTTF::Register(targetNamespace);
	cocos2d::QtScriptCCParticleSun::Register(targetNamespace);
	cocos2d::QtScriptcc_timeval::Register(targetNamespace);
	cocos2d::QtScriptCCReverseTime::Register(targetNamespace);
	cocos2d::QtScriptCCSkewBy::Register(targetNamespace);
	cocos2d::QtScriptCCFadeOutUpTiles::Register(targetNamespace);
	cocos2d::QtScriptCCFadeOutDownTiles::Register(targetNamespace);
	cocos2d::QtScriptCCRect::Register(targetNamespace);
	cocos2d::QtScriptCCPoint::Register(targetNamespace);
	cocos2d::QtScriptCCTime::Register(targetNamespace);
	cocos2d::QtScript_ccT2F_Quad::Register(targetNamespace);
	cocos2d::QtScriptCCProfilingTimer::Register(targetNamespace);
	cocos2d::QtScriptCCDevice::Register(targetNamespace);
	cocos2d::QtScriptCCEaseIn::Register(targetNamespace);
	cocos2d::QtScriptCCThread::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItem::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItemSprite::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItemImage::Register(targetNamespace);
	cocos2d::QtScriptCCMotionStreak::Register(targetNamespace);
	cocos2d::QtScriptCCRemoveSelf::Register(targetNamespace);
	cocos2d::QtScriptCCTintTo::Register(targetNamespace);
	cocos2d::QtScript_ccV2F_C4B_T2F::Register(targetNamespace);
	cocos2d::QtScriptCCConfiguration::Register(targetNamespace);
	cocos2d::QtScriptCCEaseSineOut::Register(targetNamespace);
	cocos2d::QtScriptCCEaseSineInOut::Register(targetNamespace);
	cocos2d::QtScriptCCTouchHandler::Register(targetNamespace);
	cocos2d::QtScriptCCTargetedTouchHandler::Register(targetNamespace);
	cocos2d::QtScriptCCHide::Register(targetNamespace);
	cocos2d::QtScriptCCIMEDispatcher::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionMoveInR::Register(targetNamespace);
	cocos2d::QtScriptCCGrid3D::Register(targetNamespace);
	cocos2d::QtScriptCCPlace::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgressOutIn::Register(targetNamespace);
	cocos2d::QtScriptccAnimationFrameData::Register(targetNamespace);
	cocos2d::QtScriptCCShakyTiles3D::Register(targetNamespace);
	cocos2d::QtScriptCCLabelAtlas::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBackInOut::Register(targetNamespace);
	cocos2d::QtScript_ccV3F_C4B_T2F_Quad::Register(targetNamespace);
	cocos2d::QtScriptCCAnimationCache::Register(targetNamespace);
	cocos2d::QtScriptsCCParticle_ModeA::Register(targetNamespace);
	cocos2d::QtScriptCCEaseElastic::Register(targetNamespace);
	cocos2d::QtScriptCCBlink::Register(targetNamespace);
	cocos2d::QtScript_ccPointSprite::Register(targetNamespace);
	cocos2d::QtScriptCCFlipX3D::Register(targetNamespace);
	cocos2d::QtScriptCCSet::Register(targetNamespace);
	cocos2d::QtScriptCCDouble::Register(targetNamespace);
	cocos2d::QtScriptCCScheduler::Register(targetNamespace);
	cocos2d::QtScriptCCCatmullRomTo::Register(targetNamespace);
	cocos2d::QtScriptCCInteger::Register(targetNamespace);
	cocos2d::QtScriptCCActionTween::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBackOut::Register(targetNamespace);
	cocos2d::QtScriptCCPointArray::Register(targetNamespace);
	cocos2d::QtScriptCCApplicationProtocol::Register(targetNamespace);
	cocos2d::QtScriptCCApplication::Register(targetNamespace);
	cocos2d::QtScriptCCAutoreleasePool::Register(targetNamespace);
	cocos2d::QtScriptCCParticleRain::Register(targetNamespace);
	cocos2d::QtScriptCCNotificationObserver::Register(targetNamespace);
	cocos2d::QtScriptCCScaleTo::Register(targetNamespace);
	cocos2d::QtScriptCCScaleBy::Register(targetNamespace);
	cocos2d::QtScriptCCTextFieldDelegate::Register(targetNamespace);
	cocos2d::QtScriptCCAnimationFrame::Register(targetNamespace);
	cocos2d::QtScriptCCEvent::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionShrinkGrow::Register(targetNamespace);
	cocos2d::QtScriptCCDeccelAmplitude::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionMoveInB::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgressHorizontal::Register(targetNamespace);
	cocos2d::QtScriptCCParticleSnow::Register(targetNamespace);
	cocos2d::QtScriptCCFollow::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItemLabel::Register(targetNamespace);
	cocos2d::QtScriptCCCallFuncND::Register(targetNamespace);
	cocos2d::QtScriptCCCallFuncO::Register(targetNamespace);
	cocos2d::QtScriptCCEaseSineIn::Register(targetNamespace);
	cocos2d::QtScriptCCIMEDelegate::Register(targetNamespace);
	cocos2d::QtScriptCCTextFieldTTF::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgressRadialCCW::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItemFont::Register(targetNamespace);
	cocos2d::QtScriptCCAffineTransform::Register(targetNamespace);
	cocos2d::QtScriptCCTexturePVR::Register(targetNamespace);
	cocos2d::QtScriptCCEaseElasticInOut::Register(targetNamespace);
	cocos2d::QtScript_ccFontStroke::Register(targetNamespace);
	cocos2d::QtScriptCCProgressFromTo::Register(targetNamespace);
	cocos2d::QtScriptCCBMFontConfiguration::Register(targetNamespace);
	cocos2d::QtScriptCCEaseElasticOut::Register(targetNamespace);
	cocos2d::QtScriptCCDictionary::Register(targetNamespace);
	cocos2d::QtScriptCCProgressTo::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgressRadialCW::Register(targetNamespace);
	cocos2d::QtScript_ccVertex3F::Register(targetNamespace);
	cocos2d::QtScriptCCEGLView::Register(targetNamespace);
	cocos2d::QtScriptCCEaseExponentialInOut::Register(targetNamespace);
	cocos2d::QtScriptCCFadeTo::Register(targetNamespace);
	cocos2d::QtScriptCCWavesTiles3D::Register(targetNamespace);
	cocos2d::QtScriptCCEaseExponentialOut::Register(targetNamespace);
	cocos2d::QtScriptCCDirector::Register(targetNamespace);
	cocos2d::QtScript_ccBezierConfig::Register(targetNamespace);
	cocos2d::QtScriptCCWaves3D::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFadeBL::Register(targetNamespace);
	cocos2d::QtScriptCCUserDefault::Register(targetNamespace);
	cocos2d::QtScriptCCAcceleration::Register(targetNamespace);
	cocos2d::QtScriptCCReuseGrid::Register(targetNamespace);
	cocos2d::QtScriptCCLiquid::Register(targetNamespace);
	cocos2d::QtScriptCCComponent::Register(targetNamespace);
	cocos2d::QtScriptCCParticleMeteor::Register(targetNamespace);
	cocos2d::QtScriptCCSequence::Register(targetNamespace);
	cocos2d::QtScriptCCEaseElasticIn::Register(targetNamespace);
	cocos2d::QtScriptCCTextureAtlas::Register(targetNamespace);
	cocos2d::QtScriptCCTurnOffTiles::Register(targetNamespace);
	cocos2d::QtScriptCCJumpTiles3D::Register(targetNamespace);
	cocos2d::QtScriptCCLens3D::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFadeDown::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSlideInR::Register(targetNamespace);
	cocos2d::QtScriptCCShuffleTiles::Register(targetNamespace);
	cocos2d::QtScript_ccVertex2F::Register(targetNamespace);
	cocos2d::QtScriptCCAnimate::Register(targetNamespace);
	cocos2d::QtScriptCCAccelAmplitude::Register(targetNamespace);
	cocos2d::QtScriptCCFlipY3D::Register(targetNamespace);
	cocos2d::QtScriptCCParticleBatchNode::Register(targetNamespace);
	cocos2d::QtScriptCCTextureCache::Register(targetNamespace);
	cocos2d::QtScriptCCActionCamera::Register(targetNamespace);
	cocos2d::QtScriptCCOrbitCamera::Register(targetNamespace);
	cocos2d::QtScript_ccBlendFunc::Register(targetNamespace);
	cocos2d::QtScriptCCDisplayLinkDirector::Register(targetNamespace);
	cocos2d::QtScriptCCMoveBy::Register(targetNamespace);
	cocos2d::QtScriptCCPrettyPrinter::Register(targetNamespace);
	cocos2d::QtScriptCCDrawNode::Register(targetNamespace);
	cocos2d::QtScript_ccTexParams::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionTurnOffTiles::Register(targetNamespace);
	cocos2d::QtScript_ccV2F_C4F_T2F_Quad::Register(targetNamespace);
	cocos2d::QtScriptCCGrabber::Register(targetNamespace);
	cocos2d::QtScriptccTouchHandlerHelperData::Register(targetNamespace);
	cocos2d::QtScriptCCTouch::Register(targetNamespace);
	cocos2d::QtScriptCCDelayTime::Register(targetNamespace);
	cocos2d::QtScriptCCEaseBackIn::Register(targetNamespace);
	cocos2d::QtScriptCCParticleSpiral::Register(targetNamespace);
	cocos2d::QtScriptCCRepeatForever::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionZoomFlipX::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionZoomFlipY::Register(targetNamespace);
	cocos2d::QtScriptCCMoveTo::Register(targetNamespace);
	cocos2d::QtScriptCCSpawn::Register(targetNamespace);
	cocos2d::QtScriptCCFadeIn::Register(targetNamespace);
	cocos2d::QtScriptCCSplitRows::Register(targetNamespace);
	cocos2d::QtScriptCCAnimation::Register(targetNamespace);
	cocos2d::QtScriptCCEaseInOut::Register(targetNamespace);
	cocos2d::QtScriptCCClippingNode::Register(targetNamespace);
	cocos2d::QtScriptCCCamera::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionProgressVertical::Register(targetNamespace);
	cocos2d::QtScriptCCFadeOut::Register(targetNamespace);
	cocos2d::QtScript_ccFontDefinition::Register(targetNamespace);
	cocos2d::QtScriptCCFlipX::Register(targetNamespace);
	cocos2d::QtScriptCCFlipY::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionPageTurn::Register(targetNamespace);
	cocos2d::QtScriptCCEaseOut::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItemToggle::Register(targetNamespace);
	cocos2d::QtScript_ccV2F_C4B_T2F_Quad::Register(targetNamespace);
	cocos2d::QtScriptCCTiledGrid3D::Register(targetNamespace);
	cocos2d::QtScriptCCRotateTo::Register(targetNamespace);
	cocos2d::QtScript_ccColor3B::Register(targetNamespace);
	cocos2d::QtScript_ccPVRTexturePixelFormatInfo::Register(targetNamespace);
	cocos2d::QtScriptCCBezierTo::Register(targetNamespace);
	cocos2d::QtScriptCCMenuItemAtlasFont::Register(targetNamespace);
	cocos2d::QtScript_ccTex2F::Register(targetNamespace);
	cocos2d::QtScriptsCCParticle::Register(targetNamespace);
	cocos2d::QtScript_ccV2F_C4F_T2F::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionSlideInB::Register(targetNamespace);
	cocos2d::QtScriptCCString::Register(targetNamespace);
	cocos2d::QtScriptCCMenu::Register(targetNamespace);
	cocos2d::QtScriptCCNotificationCenter::Register(targetNamespace);
	cocos2d::QtScriptCCSize::Register(targetNamespace);
	cocos2d::QtScriptCCFileUtils::Register(targetNamespace);
	cocos2d::QtScriptCCStandardTouchHandler::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFlipY::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFlipX::Register(targetNamespace);
	cocos2d::QtScript_ccColor4B::Register(targetNamespace);
	cocos2d::QtScript_ccColor4F::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionFlipAngular::Register(targetNamespace);
	cocos2d::QtScriptCCSpeed::Register(targetNamespace);
	cocos2d::QtScriptCCTransitionJumpZoom::Register(targetNamespace);
}
