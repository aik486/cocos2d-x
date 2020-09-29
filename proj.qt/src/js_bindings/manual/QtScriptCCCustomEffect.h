#pragma once

#include "QtCocosExtension.h"
#include "js_bindings/generated/qtscript_cocos2dx.hpp"

namespace cocos2d
{
class QtScriptCCCustomEffect : public QtScriptSprite
{
	Q_OBJECT

protected:
	explicit QtScriptCCCustomEffect(
		QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(
		QScriptContext *context, NativeObjectType &out) override;

public:
	explicit QtScriptCCCustomEffect(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addTextureForShader(
		cocos2d::Texture2D *texture, const QByteArray &uniformName);

	Q_INVOKABLE void setPreDrawCallback(QScriptValue callback);
	Q_INVOKABLE void setCopyCallback(QScriptValue callback);

	static QScriptValue create(QScriptContext *context, QScriptEngine *engine);
};
}

Q_DECLARE_METATYPE(cocos2d::CCCustomEffect *)
Q_DECLARE_METATYPE(const cocos2d::CCCustomEffect *)
