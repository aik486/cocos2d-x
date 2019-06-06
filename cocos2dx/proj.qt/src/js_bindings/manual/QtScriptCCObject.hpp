#pragma once

#include "QtCocosScriptEngine.h"

#include <QtCore>

#include <QScriptable>
#include <QScriptClass>
#include <QScriptContext>
#include <QScriptEngine>

namespace cocos2d
{
class QtScriptCCObject
	: public QObject
	, public QScriptable
	, public QScriptClass
{
	Q_OBJECT

	explicit QtScriptCCObject(QScriptEngine *engine);

protected:
	explicit QtScriptCCObject(QScriptEngine *engine, const QString &className);

public:
	static void Register(const QScriptValue &targetNamespace);
	inline QScriptEngine *engine() const;

	using NativeObjectType = CCObject *;

public slots:
	QString toString() const;
	void update(float dt);
	cocos2d::CCObject *copy();

protected:
	// QScriptClass
	virtual QString name() const override;
	virtual QScriptValue prototype() const override;

	// QtScriptCCObject
	virtual int constructorArgumentCountMin() const;
	virtual int constructorArgumentCountMax() const;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) const;
	QScriptValue newInstance(CCObject *obj);
	static CCObject *toCCObject(const QScriptValue &value);

	template <typename CC_T, typename CLS_T>
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

	template <typename CLS_T>
	static QScriptValue construct(QScriptContext *ctx, QScriptEngine *)
	{
		QtScriptCCObject *cls =
			qobject_cast<CLS_T *>(ctx->callee().data().toQObject());
		Q_ASSERT(cls);

		return cls->tryConstructCCObject(ctx);
	}

	template <typename CC_T, typename CLS_T>
	static QScriptValue RegisterT(
		QScriptValue targetNamespace, const QScriptValue &inherit)
	{
		auto ccEngine = QtCocosScriptEngine::instance();
		auto engine = ccEngine->engine();
		Q_ASSERT(targetNamespace.isObject());
		Q_ASSERT(engine == targetNamespace.engine());

		qScriptRegisterMetaType<CC_T *>(engine,
			QtScriptCCObject::toScriptValue<CC_T *, CLS_T>,
			QtScriptCCObject::fromScriptValue<CC_T *>);

		QScriptValue global = engine->globalObject();

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

		engine->setDefaultPrototype(qMetaTypeId<CC_T *>(), proto);

		QScriptValue ctor =
			engine->newFunction(QtScriptCCObject::construct<CLS_T>, proto);
		ctor.setData(proto);
		targetNamespace.setProperty(obj->name(), ctor,
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

private:
	QScriptValue tryConstructCCObject(QScriptContext *ctx);

private:
	QScriptValue mProto;
	QString mClassName;
};

QScriptEngine *QtScriptCCObject::engine() const
{
	return QScriptClass::engine();
}
}

Q_DECLARE_METATYPE(cocos2d::CCObject *)
