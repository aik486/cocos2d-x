#pragma once

#include "QtCocosScriptEngine.h"

#include "QtScriptAbstractClass.h"

#include <QScriptEngine>

namespace cocos2d
{
class QtScriptCCObject : public QtScriptAbstractClass
{
	Q_OBJECT

	explicit QtScriptCCObject(QScriptEngine *engine);

protected:
	explicit QtScriptCCObject(
		QScriptEngine *engine, const QByteArray &className);

public:
	static void Register(const QScriptValue &targetNamespace);

	using NativeObjectType = CCObject *;
	using StorageType = CCObject *;

public slots:
	QString toString() const;
	void update(float dt);
	QScriptValue copy();

protected:
	// QtScriptCCObject
	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, CCObject *&out);
	QScriptValue newInstance(CCObject *obj);
	static CCObject *toCCObject(const QScriptValue &value);

	template <typename CLS_T, typename CC_T>
	static QScriptValue toScriptValue(QScriptEngine *engine, CC_T const &object)
	{
		CCObject *obj = object;
		QScriptValue proto = engine->defaultPrototype(qMetaTypeId<CC_T>());
		QtScriptCCObject *cls = qobject_cast<CLS_T *>(proto.toQObject());
		Q_ASSERT(nullptr != cls);

		return cls->newInstance(obj);
	}
	template <typename CC_T>
	static void fromScriptValue(const QScriptValue &value, CC_T &out)
	{
		auto obj = toCCObject(value);
		if (obj)
			Q_ASSERT(dynamic_cast<CC_T>(obj) != nullptr);
		out = static_cast<CC_T>(obj);
	}

	template <typename TT, typename CLS_T>
	static void registerPointerMetaType(QScriptEngine *engine)
	{
		qScriptRegisterMetaType<TT *>(engine,
			QtScriptCCObject::toScriptValue<CLS_T, TT *>,
			QtScriptCCObject::fromScriptValue<TT *>);

		typedef QScriptValue (*ToScriptValue)(QScriptEngine *, TT *const &);
		typedef void (*FromScriptValue)(const QScriptValue &, TT *&);

		typedef QScriptValue (*ConstToScriptValue)(
			QScriptEngine *, const TT *const &);
		typedef void (*ConstFromScriptValue)(const QScriptValue &, const TT *&);

		qScriptRegisterMetaType<const TT *>(engine,
			reinterpret_cast<ConstToScriptValue>(static_cast<ToScriptValue>(
				&QtScriptCCObject::toScriptValue<CLS_T, TT *>)),
			reinterpret_cast<ConstFromScriptValue>(static_cast<FromScriptValue>(
				&QtScriptCCObject::fromScriptValue<TT *>)));
	}

	template <typename CC_T, typename CLS_T>
	static QScriptValue RegisterT(
		QScriptValue targetNamespace, const QScriptValue &inherit)
	{
		auto ccEngine = QtCocosScriptEngine::instance();
		auto engine = ccEngine->engine();
		Q_ASSERT(targetNamespace.isObject());
		Q_ASSERT(engine == targetNamespace.engine());

		QtScriptCCObject *obj = new CLS_T(engine);
		auto proto = engine->newQObject(obj, QScriptEngine::QtOwnership,
			QScriptEngine::ExcludeChildObjects |
				QScriptEngine::ExcludeDeleteLater |
				QScriptEngine::SkipMethodsInEnumeration |
				QScriptEngine::ExcludeSuperClassContents |
				QScriptEngine::ExcludeSlots);
		obj->mProto = proto;

		proto.setPrototype(inherit.isObject()
				? inherit
				: ccEngine->propertyById(QtCocosScriptEngine::PROTOTYPE,
					  ccEngine->propertyById(QtCocosScriptEngine::OBJECT,
						  engine->globalObject())));

		registerPointerMetaType<CC_T, CLS_T>(engine);

		engine->setDefaultPrototype(qMetaTypeId<CC_T *>(), proto);

		QScriptValue ctor =
			engine->newFunction(QtScriptCCObject::construct<CLS_T>, proto);
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

Q_DECLARE_METATYPE(cocos2d::CCObject *)
Q_DECLARE_METATYPE(const cocos2d::CCObject *)
