#include "QtScriptRefHolder.h"
#include "QtScriptRef.hpp"

namespace cocos2d
{
QtScriptRefHolder::QtScriptRefHolder(
	QScriptEngine *engine, const QByteArray &className)
	: QtScriptBaseClassPrototype<AnyObjectHolder, false>(engine, className)
{
}

int QtScriptRefHolder::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptRefHolder::constructorArgumentCountMax() const
{
	return 1;
}

bool QtScriptRefHolder::constructObject(
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
				qscriptvalue_cast<cocos2d::Ref *>(context->argument(0)));
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

QtScriptRefHolder::QtScriptRefHolder(QScriptEngine *engine)
	: QtScriptRefHolder(engine, "RefHolder")
{
}

void QtScriptRefHolder::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto ctor = RegisterT<AnyObjectHolder, QtScriptRefHolder>(
		targetNamespace, QScriptValue());
	Q_ASSERT(ctor.isFunction());
}

Ref *QtScriptRefHolder::object() const
{
	auto o = thiz<AnyObjectHolder *>();
	if (o)
		return o->object();

	return nullptr;
}

void QtScriptRefHolder::setObject(Ref *object)
{
	auto o = thiz<AnyObjectHolder *>();
	if (o)
		o->setObject(object);
}
}
