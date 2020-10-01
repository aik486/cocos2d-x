#pragma once

#include "base/CCScriptSupport.h"

#include <QObject>
#include <QScriptValue>
#include <QScriptString>
#include <QScriptEngine>

#include <unordered_map>

class QScriptContext;

class QtCocosScriptEngine
	: public QObject
	, public cocos2d::ScriptEngineProtocol
{
	Q_OBJECT

public:
	enum
	{
		CC,
		OBJECT,
		PROTOTYPE,
		LENGTH,

		STRING_ID_COUNT
	};

	QtCocosScriptEngine(QScriptEngine *engine);
	virtual ~QtCocosScriptEngine() override;

	inline QScriptEngine *engine() const;

	const QScriptValue &ccRootObject() const;

	static QtCocosScriptEngine *instance();

	virtual cocos2d::ccScriptType getScriptType() override;
	virtual int executeString(const char *codes) override;
	virtual int executeScriptFile(const char *filename) override;
	virtual int executeGlobalFunction(const char *functionName) override;
	virtual int sendEvent(cocos2d::ScriptEvent *evt) override;
	virtual bool handleAssert(const char *msg) override;
	virtual bool parseConfig(ConfigType type, const std::string &str) override;

	virtual void garbageCollect() override;

	const QScriptString &jsString(int id) const;
	QScriptValue propertyById(int id, const QScriptValue &object) const;

signals:
	void log(const QScriptValue &value);

private:
	QScriptValue checkResult(QScriptValue value);

	static QScriptValue cocos2dVersionCode(
		QScriptContext *context, QScriptEngine *engine);
	static QScriptValue cocos2dVersionString(
		QScriptContext *context, QScriptEngine *engine);
	static QScriptValue spriteFrameByName(
		QScriptContext *context, QScriptEngine *engine);
	static QScriptValue addImageSpriteFrame(
		QScriptContext *context, QScriptEngine *engine);
	static QScriptValue shaderProgramByName(
		QScriptContext *context, QScriptEngine *engine);
	static QScriptValue addShaderProgram(
		QScriptContext *context, QScriptEngine *engine);

private:
	QScriptEngine *mEngine;
	QScriptString mStringIds[STRING_ID_COUNT];
	QScriptValue mRootObject;
	static const char *STRING_IDS[STRING_ID_COUNT];
};

QScriptEngine *QtCocosScriptEngine::engine() const
{
	return mEngine;
}
