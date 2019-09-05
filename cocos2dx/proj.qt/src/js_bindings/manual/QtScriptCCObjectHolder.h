#pragma once

#include "QtScriptBaseClassPrototype.h"
#include "CCObjectHolder.h"

namespace cocos2d
{
class QtScriptCCObjectHolder final
	: public QtScriptBaseClassPrototype<AnyObjectHolder, false>
{
	Q_OBJECT

	Q_PROPERTY(cocos2d::CCObject *object READ object WRITE setObject)

protected:
	explicit QtScriptCCObjectHolder(
		QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(
		QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCObjectHolder(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	CCObject *object() const;
	void setObject(CCObject *object);
};
}

Q_DECLARE_METATYPE(cocos2d::AnyObjectHolder)
Q_DECLARE_METATYPE(cocos2d::AnyObjectHolder *)
Q_DECLARE_METATYPE(const cocos2d::AnyObjectHolder *)
