#include "QtScriptCCObject.hpp"
#include "QtScriptUtils.h"

namespace cocos2d
{
QtScriptCCObject::QtScriptCCObject(
	QScriptEngine *engine, const QByteArray &className)
	: QtScriptAbstractClass(engine, className)
{
}

QtScriptCCObject::QtScriptCCObject(QScriptEngine *engine)
	: QtScriptCCObject(engine, "Object")
{
}

void QtScriptCCObject::Register(const QScriptValue &targetNamespace)
{
	auto ctor =
		RegisterT<CCObject, QtScriptCCObject>(targetNamespace, QScriptValue());
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty(QSTRKEY(cast),
		ctor.engine()->newFunction(
			static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
				&QtScriptCCObject::cast)),
		QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptCCObject::newInstance(CCObject *obj)
{
	Q_ASSERT(obj);
	auto data = engine()->newVariant(QVariant::fromValue(obj));
	return engine()->newObject(this, data);
}

CCObject *QtScriptCCObject::toCCObject(const QScriptValue &value)
{
	auto v = QtScriptUtils::scriptValueVariantData(value);

	if (v.userType() != qMetaTypeId<CCObject *>())
		return nullptr;

	return v.value<CCObject *>();
}

QScriptValue QtScriptCCObject::newScriptObject(QScriptContext *context)
{
	CCObject *newObject;
	if (!constructObject(context, newObject))
	{
		return engine()->uncaughtException();
	}
	newObject->autorelease();
	return newInstance(newObject);
}

QString QtScriptCCObject::toString() const
{
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
	{
		CCPrettyPrinter printer;
		ccObject->acceptVisitor(printer);

		return QString::fromUtf8(printer.getResult().c_str());
	}

	return QStringLiteral("[cc.%1]").arg(mClassName);
}

void QtScriptCCObject::update(float dt)
{
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
		ccObject->update(dt);
}

QScriptValue QtScriptCCObject::copy()
{
	CCObject *object = nullptr;
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
	{
		object = ccObject->copy();
	}

	if (!object)
		return context()->throwError(tr("The object is not copyable"));
	object->autorelease();
	return newInstance(object);
}

bool QtScriptCCObject::isEqual(const CCObject *other) const
{
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
		return ccObject->isEqual(other);

	return false;
}

QScriptValue QtScriptCCObject::cast(QScriptContext *context, QScriptEngine *)
{
	int argc = context->argumentCount();
	CCObject *obj;
	if (argc == 1)
	{
		obj = qscriptvalue_cast<cocos2d::CCObject *>(context->argument(0));
	} else
	{
		obj = nullptr;
	}
	if (!obj)
	{
		return QtScriptUtils::badArgumentsException(context, "cc.Object.cast");
	}

	auto cls =
		qobject_cast<QtScriptCCObject *>(context->callee().data().toQObject());
	Q_ASSERT(cls);
	return cls->newInstance(obj);
}

int QtScriptCCObject::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCObject::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCObject::constructObject(QScriptContext *, CCObject *&out)
{
	out = new CCObject;
	return true;
}
}
