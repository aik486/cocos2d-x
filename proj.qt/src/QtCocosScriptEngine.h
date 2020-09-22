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

		STRING_ID_COUNT
	};

	QtCocosScriptEngine(QScriptEngine *engine);
	virtual ~QtCocosScriptEngine() override;

	qint64 retainJSObject(const QScriptValue &v);
	void releaseJSObject(qint64 objectId);

	inline QScriptEngine *engine() const;

	static bool isArgumentCountLessThan(QScriptContext *context, int minArgs);
	static bool isArgumentCountGreaterThan(
		QScriptContext *context, int maxArgs);
	static bool checkArgumentCount(QScriptContext *context, int min, int max);
	static void noPublicConstructorException(
		QScriptContext *context, const QString &className);
	static void badArgumentsException(
		QScriptContext *context, const QString &funcName);

	const QScriptValue &ccRootObject() const;

	static QtCocosScriptEngine *instance();

	virtual cocos2d::ccScriptType getScriptType() override;
	virtual void removeScriptObjectByObject(cocos2d::Ref *pObj) override;
	virtual void removeScriptHandler(int64_t nHandler) override;
	virtual int executeString(const char *codes) override;
	virtual int executeScriptFile(const char *filename) override;
	virtual int executeGlobalFunction(const char *functionName) override;
	virtual int sendEvent(cocos2d::ScriptEvent *evt) override;
	virtual bool handleAssert(const char *msg) override;
	virtual bool parseConfig(ConfigType type, const std::string &str) override;

	virtual void setCalledFromScript(bool callFromScript) override;
	virtual bool isCalledFromScript() override;

	virtual void garbageCollect() override;

	virtual void removeObjectProxy(cocos2d::Ref *obj) override;

	QScriptValue getRegisteredJSObject(qint64 id) const;

	const QScriptString &jsString(int id) const;
	QScriptValue propertyById(int id, const QScriptValue &object) const;

signals:
	void log(const QScriptValue &value);

private:
	int executeNodeEvent(cocos2d::Node *pNode, int nAction);
	int executeMenuItemEvent(cocos2d::MenuItem *pMenuItem);
	int executeCallFuncActionEvent(
		cocos2d::CallFunc *pAction, cocos2d::Ref *pTarget);
	int executeSchedule(int64_t nHandler, float dt, cocos2d::Node *);
	int executeLayerTouchesEvent(cocos2d::Layer *pLayer, int eventType,
		std::vector<cocos2d::Touch *> *pTouches);
	int executeLayerTouchEvent(
		cocos2d::Layer *pLayer, int eventType, cocos2d::Touch *pTouch);
	int executeLayerKeypadEvent(cocos2d::Layer *pLayer, int eventType);
	int executeEvent(
		int64_t nHandler, const char *, cocos2d::Ref *, const char *);

	QScriptValue executeEventHandler(QScriptValue func,
		const QScriptValue &object,
		const QScriptValueList &args = QScriptValueList());
	QScriptValue checkResult(QScriptValue value);

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
	std::unordered_map<qint64, QScriptValue> mJSObjectMap;
	QScriptValue mRootObject;
	static const char *STRING_IDS[STRING_ID_COUNT];
};

QScriptEngine *QtCocosScriptEngine::engine() const
{
	return mEngine;
}
