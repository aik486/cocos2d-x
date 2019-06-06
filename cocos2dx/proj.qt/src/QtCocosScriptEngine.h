#pragma once

#include "cocos_warnings_off.h"
#include "script_support/CCScriptSupport.h"
#include "cocos_warnings_pop.h"

#include <QObject>
#include <QScriptValue>
#include <QScriptString>
#include <QScriptEngine>

#include <unordered_map>

class QScriptContext;

class QtCocosScriptEngine
	: public QObject
	, public cocos2d::CCScriptEngineProtocol
{
	Q_OBJECT

public:
	enum
	{
		CC,
		OBJECT,
		PROTOTYPE,
		BACK_CLICKED,
		MENU_CLICKED,
		ON_TOUCHES_BEGIN,
		ON_TOUCHES_ENDED,
		ON_TOUCHES_MOVED,
		ON_TOUCHES_CANCELLED,
		ON_TOUCH_BEGIN,
		ON_TOUCH_ENDED,
		ON_TOUCH_MOVED,
		ON_TOUCH_CANCELLED,
		ON_ENTER,
		ON_EXIT,
		ON_ENTER_TRANSITION_DID_FINISH,
		ON_EXIT_TRANSITION_DID_START,
		UPDATE,
		ACTIVATE,

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
	virtual void removeScriptObjectByCCObject(cocos2d::CCObject *pObj) override;
	virtual void removeScriptHandler(int64_t nHandler) override;
	virtual int executeString(const char *codes) override;
	virtual int executeScriptFile(const char *filename) override;
	virtual int executeGlobalFunction(const char *functionName) override;
	virtual int executeNodeEvent(cocos2d::CCNode *pNode, int nAction) override;
	virtual int executeMenuItemEvent(cocos2d::CCMenuItem *pMenuItem) override;
	virtual int executeNotificationEvent(
		cocos2d::CCNotificationCenter *pCenter, const char *pszName) override;
	virtual int executeCallFuncActionEvent(
		cocos2d::CCCallFunc *pAction, cocos2d::CCObject *pTarget) override;
	virtual int executeSchedule(
		int64_t nHandler, float dt, cocos2d::CCNode *) override;
	virtual int executeLayerTouchesEvent(cocos2d::CCLayer *pLayer,
		int eventType, cocos2d::CCSet *pTouches) override;
	virtual int executeLayerTouchEvent(cocos2d::CCLayer *pLayer, int eventType,
		cocos2d::CCTouch *pTouch) override;
	virtual int executeLayerKeypadEvent(
		cocos2d::CCLayer *pLayer, int eventType) override;
	virtual int executeAccelerometerEvent(
		cocos2d::CCLayer *, cocos2d::CCAcceleration *) override;
	virtual int executeEvent(int64_t nHandler, const char *,
		cocos2d::CCObject *, const char *) override;
	virtual bool handleAssert(const char *msg) override;
	virtual bool parseConfig(ConfigType type, const std::string &str) override;

	QScriptValue getRegisteredJSObject(qint64 id) const;

	const QScriptString &jsString(int id) const;
	QScriptValue propertyById(int id, const QScriptValue &object) const;

signals:
	void log(const QScriptValue &value);

private:
	static int getNodeEventFuncId(int eventType);
	static int getTouchesFuncId(int eventType);
	static int getTouchFuncId(int eventType);
	QScriptValue executeScriptFunction(int funcId, const QScriptValue &object,
		const QScriptValueList &args = QScriptValueList());
	QScriptValue checkResult(const QScriptValue &value);

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
