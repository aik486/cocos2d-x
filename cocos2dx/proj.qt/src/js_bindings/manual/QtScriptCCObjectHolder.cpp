#include "QtScriptCCObjectHolder.h"
#include "QtScriptCCObject.hpp"

namespace cocos2d
{
QtScriptCCObjectHolder::QtScriptCCObjectHolder(
	QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<AnyObjectHolder, false>(engine, className)
{
}

int QtScriptCCObjectHolder::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCObjectHolder::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptCCObjectHolder::constructObject(
	QScriptContext *context, NativeObjectType &out)
{
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			ok = true;
			break;
		}

		case 1:
		{
			out.setObject(
				qscriptvalue_cast<cocos2d::CCObject *>(context->argument(0)));
			ok = true;
			break;
		}
	}

	if (!ok)
	{
		QtScriptUtils::badArgumentsException(
			context, "cocos2d::AnyObjectHolder constructor");
	}
	return ok;
}

QtScriptCCObjectHolder::QtScriptCCObjectHolder(QScriptEngine *engine)
	: QtScriptCCObjectHolder(engine, "ObjectHolder")
{
}

void QtScriptCCObjectHolder::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto ctor = RegisterT<AnyObjectHolder, QtScriptCCObjectHolder>(
		targetNamespace, QScriptValue());
	Q_ASSERT(ctor.isFunction());
}

CCObject *QtScriptCCObjectHolder::object() const
{
	auto o = thiz<AnyObjectHolder *>();
	if (o)
		return o->object();

	return nullptr;
}

void QtScriptCCObjectHolder::setObject(CCObject *object)
{
	auto o = thiz<AnyObjectHolder *>();
	if (o)
		o->setObject(object);
}
}
