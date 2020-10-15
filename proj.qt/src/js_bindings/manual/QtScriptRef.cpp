#include "QtScriptRef.hpp"
#include "QtScriptUtils.h"

namespace cocos2d
{
QtScriptRef::QtScriptRef(QScriptEngine *engine, const QByteArray &className)
	: QtScriptAbstractClass(engine, className)
{
}

QtScriptRef::QtScriptRef(QScriptEngine *engine)
	: QtScriptRef(engine, "Ref")
{
}

void QtScriptRef::Register(const QScriptValue &targetNamespace)
{
	auto ctor = RegisterT<Ref, QtScriptRef>(targetNamespace, QScriptValue());
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty(QSTRKEY(cast),
		ctor.engine()->newFunction(
			static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
				&QtScriptRef::cast)),
		QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

QScriptValue QtScriptRef::newInstance(Ref *obj, QScriptValue thisObject)
{
	Q_ASSERT(obj);
	auto data = engine()->newVariant(QVariant::fromValue(obj));
	if (thisObject.isObject())
	{
		thisObject.setScriptClass(this);
		thisObject.setData(data);
		return thisObject;
	}
	return engine()->newObject(this, data);
}

Ref *QtScriptRef::toRef(const QScriptValue &value)
{
	auto v = QtScriptUtils::scriptValueVariantData(value);

	if (v.userType() != qMetaTypeId<Ref *>())
		return nullptr;

	return v.value<Ref *>();
}

QScriptValue QtScriptRef::newScriptObject(QScriptContext *context)
{
	Ref *newObject;
	if (!constructObject(context, newObject))
	{
		return engine()->uncaughtException();
	}
	newObject->autorelease();
	return newInstance(newObject, context->thisObject());
}

QString QtScriptRef::toString() const
{
	return QStringLiteral("[cc.%1]").arg(mClassName);
}

QScriptValue QtScriptRef::cast(QScriptContext *context, QScriptEngine *)
{
	int argc = context->argumentCount();
	Ref *obj;
	if (argc == 1)
	{
		obj = qscriptvalue_cast<cocos2d::Ref *>(context->argument(0));
	} else
	{
		obj = nullptr;
	}
	if (!obj)
	{
		return QtScriptUtils::badArgumentsException(context, "cc.Object.cast");
	}

	auto cls =
		qobject_cast<QtScriptRef *>(context->callee().data().toQObject());
	Q_ASSERT(cls);
	return cls->newInstance(obj);
}

int QtScriptRef::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptRef::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptRef::constructObject(QScriptContext *context, Ref *&)
{
	QtScriptUtils::noPublicConstructorException(context, "cocos2d::Ref");
	return false;
}
}
