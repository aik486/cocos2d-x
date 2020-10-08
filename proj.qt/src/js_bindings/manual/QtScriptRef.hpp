#pragma once

#include "QtCocosScriptEngine.h"

#include "QtScriptAbstractClass.h"

#include <QScriptEngine>

namespace cocos2d
{
class QtScriptRef : public QtScriptAbstractClass
{
	Q_OBJECT

	explicit QtScriptRef(QScriptEngine *engine);

protected:
	explicit QtScriptRef(QScriptEngine *engine, const QByteArray &className);

public:
	static void Register(const QScriptValue &targetNamespace);

	using NativeObjectType = Ref *;
	using StorageType = Ref *;

	Q_INVOKABLE QString toString() const;

protected:
	static QScriptValue cast(QScriptContext *context, QScriptEngine *);

	// QtScriptRef
	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *context, Ref *&);
	QScriptValue newInstance(Ref *obj);
	static Ref *toRef(const QScriptValue &value);

	template <typename CLS_T, typename CC_T>
	static QScriptValue toScriptValue(QScriptEngine *engine, CC_T const &object)
	{
		Ref *obj = object;
		if (!obj)
			return engine->nullValue();

		QScriptValue proto = engine->defaultPrototype(qMetaTypeId<CC_T>());
		QtScriptRef *cls = qobject_cast<CLS_T *>(proto.toQObject());
		Q_ASSERT(nullptr != cls);

		return cls->newInstance(obj);
	}
	template <typename CC_T>
	static void fromScriptValue(const QScriptValue &value, CC_T &out)
	{
		auto obj = toRef(value);
		out = dynamic_cast<CC_T>(obj);
	}

	template <typename TT, typename CLS_T>
	static void registerPointerMetaType(
		QScriptEngine *engine, const QScriptValue &proto)
	{
		qScriptRegisterMetaType<TT *>(engine,
			QtScriptRef::toScriptValue<CLS_T, TT *>,
			QtScriptRef::fromScriptValue<TT *>, proto);

		typedef QScriptValue (*ToScriptValue)(QScriptEngine *, TT *const &);
		typedef void (*FromScriptValue)(const QScriptValue &, TT *&);

		typedef QScriptValue (*ConstToScriptValue)(
			QScriptEngine *, const TT *const &);
		typedef void (*ConstFromScriptValue)(const QScriptValue &, const TT *&);

		qScriptRegisterMetaType<const TT *>(engine,
			reinterpret_cast<ConstToScriptValue>(static_cast<ToScriptValue>(
				&QtScriptRef::toScriptValue<CLS_T, TT *>)),
			reinterpret_cast<ConstFromScriptValue>(static_cast<FromScriptValue>(
				&QtScriptRef::fromScriptValue<TT *>)),
			proto);
	}

	template <typename CC_T, typename CLS_T>
	static QScriptValue RegisterT(
		QScriptValue targetNamespace, const QScriptValue &inherit)
	{
		auto ccEngine = QtCocosScriptEngine::instance();
		auto engine = ccEngine->engine();
		Q_ASSERT(targetNamespace.isObject());
		Q_ASSERT(engine == targetNamespace.engine());

		QtScriptRef *obj = new CLS_T(engine);
		auto proto = engine->newQObject(obj, QScriptEngine::QtOwnership,
			QScriptEngine::ExcludeChildObjects |
				QScriptEngine::ExcludeDeleteLater |
				QScriptEngine::SkipMethodsInEnumeration |
				QScriptEngine::ExcludeSuperClassContents |
				QScriptEngine::ExcludeSlots);
		obj->mProto = proto;

		if (inherit.isObject())
			proto.setPrototype(inherit);

		registerPointerMetaType<CC_T, CLS_T>(engine, proto);

		QScriptValue ctor =
			engine->newFunction(QtScriptRef::construct<CLS_T>, proto);
		ctor.setData(proto);
		targetNamespace.setProperty(obj->mClassName, ctor,
			QScriptValue::ReadOnly | QScriptValue::Undeletable);

		return ctor;
	}

	template <typename T>
	T thiz() const
	{
		T result;
		fromScriptValue<T>(thisObject(), result);
		return result;
	}

	virtual QScriptValue newScriptObject(QScriptContext *context) override;
};
} // namespace cocos2d

Q_DECLARE_METATYPE(cocos2d::Ref *)
Q_DECLARE_METATYPE(const cocos2d::Ref *)
