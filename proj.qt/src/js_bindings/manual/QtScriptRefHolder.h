#pragma once

#include "QtScriptBaseClassPrototype.h"
#include "CCRefHolder.h"

namespace cocos2d
{
class QtScriptRefHolder final
	: public QtScriptBaseClassPrototype<AnyObjectHolder, false>
{
	Q_OBJECT

	Q_PROPERTY(cocos2d::Ref *object READ object WRITE setObject)

protected:
	explicit QtScriptRefHolder(
		QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(
		QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRefHolder(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Ref *object() const;
	void setObject(Ref *object);
};
}

Q_DECLARE_METATYPE(cocos2d::AnyObjectHolder)
Q_DECLARE_METATYPE(cocos2d::AnyObjectHolder *)
Q_DECLARE_METATYPE(const cocos2d::AnyObjectHolder *)
