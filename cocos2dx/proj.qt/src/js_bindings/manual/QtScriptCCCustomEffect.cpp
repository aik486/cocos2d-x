#include "QtScriptCCCustomEffect.h"

namespace cocos2d
{
QtScriptCCCustomEffect::QtScriptCCCustomEffect(
	QScriptEngine *engine, const QByteArray &className)
	: QtScriptCCSprite(engine, className)
{
}

int QtScriptCCCustomEffect::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCCustomEffect::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCCustomEffect::constructObject(
	QScriptContext *context, QtScriptCCObject::NativeObjectType &out)
{
	bool ok = false;
	switch (context->argumentCount())
	{
		case 0:
		{
			out = new CCCustomEffect();
			ok = true;
			break;
		}
	}

	if (!ok)
	{
		QtScriptUtils::badArgumentsException(
			context, "cocos2d::CCCustomEffect constructor");
	}
	return ok;
}

QtScriptCCCustomEffect::QtScriptCCCustomEffect(QScriptEngine *engine)
	: QtScriptCCSprite(engine, "CustomEffect")
{
}

void QtScriptCCCustomEffect::Register(const QScriptValue &targetNamespace)
{
	auto engine = targetNamespace.engine();
	Q_ASSERT(engine);
	auto inherit = engine->defaultPrototype(qMetaTypeId<CCSprite *>());
	auto ctor = RegisterT<CCCustomEffect, QtScriptCCCustomEffect>(
		targetNamespace, inherit);
	Q_ASSERT(ctor.isFunction());
	ctor.setProperty("create",
		engine->newFunction(
			static_cast<QScriptValue (*)(QScriptContext *, QScriptEngine *)>(
				&QtScriptCCCustomEffect::create)),
		QScriptValue::ReadOnly | QScriptValue::Undeletable);
}

void QtScriptCCCustomEffect::addTextureForShader(
	CCTexture2D *texture, const QByteArray &uniformName)
{
	auto o = this->thiz<CCCustomEffect *>();
	if (o)
	{
		o->addTextureForShader(texture, uniformName);
	}
}

void QtScriptCCCustomEffect::setPreDrawCallback(QScriptValue callback)
{
	if (!callback.isFunction())
	{
		QtScriptUtils::badArgumentsException(
			context(), "cocos2d::CCCustomEffect::setPreDrawCallback");
	}
	auto o = this->thiz<CCCustomEffect *>();
	if (o)
	{
		auto thiz = thisObject();
		o->setPreDrawCallback([callback, thiz](CCCustomEffect *) mutable {
			callback.call(thiz);
		});
	}
}

void QtScriptCCCustomEffect::setCopyCallback(QScriptValue callback)
{
	if (!callback.isFunction())
	{
		QtScriptUtils::badArgumentsException(
			context(), "cocos2d::CCCustomEffect::setCopyCallback");
	}
	auto o = this->thiz<CCCustomEffect *>();
	if (o)
	{
		auto thiz = thisObject();
		o->setCopyCallback(
			[callback, thiz](CCCustomEffect *, CCCustomEffect *dst) mutable {
				auto engine = callback.engine();
				callback.call(
					thiz, QScriptValueList() << engine->toScriptValue(dst));
			});
	}
}

QScriptValue QtScriptCCCustomEffect::create(
	QScriptContext *context, QScriptEngine *engine)
{
	if (!QtScriptUtils::checkArgumentCount(context, 0, 0))
	{
		return engine->uncaughtException();
	}

	switch (context->argumentCount())
	{
		case 0:
		{
			return engine->toScriptValue(CCCustomEffect::create());
		}
	}

	QtScriptUtils::badArgumentsException(
		context, "cocos2d::CCCustomEffect::create");
	return engine->uncaughtException();
}
}
