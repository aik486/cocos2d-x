#include "QtCocosScriptEngine.h"

#include "cocos2dx_qt.h"
#include "js_bindings/QtScriptCCObject.hpp"

#include <QScriptEngine>

using namespace cocos2d;

static QtCocosScriptEngine *_instance = nullptr;

const char *QtCocosScriptEngine::STRING_IDS[] = {
	"cc", // CC
	"Object", // OBJECT
	"prototype", // PROTOTYPE
	"backClicked", // BACK_CLICKED,
	"menuClicked", // MENU_CLICKED,
	"onTouchesBegan", // ON_TOUCHES_BEGIN,
	"onTouchesEnded", // ON_TOUCHES_ENDED,
	"onTouchesMoved", // ON_TOUCHES_MOVED,
	"onTouchesCancelled", // ON_TOUCHES_CANCELLED,
	"onTouchBegan", // ON_TOUCH_BEGIN,
	"onTouchEnded", // ON_TOUCH_ENDED,
	"onTouchMoved", // ON_TOUCH_MOVED,
	"onTouchCancelled", // ON_TOUCH_CANCELLED,
	"update", // UPDATE
	"activate", // ACTIVATE
	"onEnter", // ON_ENTER,
	"onExit", // ON_EXIT,
	"onEnterTransitionDidFinish", // ON_ENTER_TRANSITION_DID_FINISH,
	"onExitTransitionDidStart", // ON_EXIT_TRANSITION_DID_START,
};

QtCocosScriptEngine::QtCocosScriptEngine(QScriptEngine *engine)
	: mEngine(engine)
{
	Q_ASSERT(_instance == nullptr);
	_instance = this;

	CC_ASSERT(engine);
	for (int i = 0; i < STRING_ID_COUNT; i++)
	{
		mStringIds[i] = engine->toStringHandle(STRING_IDS[i]);
	}

	mRootObject = engine->newObject();
	engine->globalObject().setProperty(mStringIds[CC], mRootObject,
		QScriptValue::ReadOnly | QScriptValue::Undeletable);

	QtScriptCCObject::Register(mRootObject);
}

QtCocosScriptEngine::~QtCocosScriptEngine()
{
	Q_ASSERT(_instance == this);
	_instance = nullptr;
}

qint64 QtCocosScriptEngine::retainJSObject(const QScriptValue &v)
{
	if (!v.isObject())
		return 0;

	auto result = v.objectId();
	mJSObjectMap[result] = v;
	return result;
}

void QtCocosScriptEngine::releaseJSObject(qint64 objectId)
{
	Q_ASSERT(objectId);
	mJSObjectMap.erase(objectId);
}

bool QtCocosScriptEngine::isArgumentCountLessThan(
	QScriptContext *context, int minArgs)
{
	Q_ASSERT(context);
	if (context->argumentCount() < minArgs)
	{
		context->throwError(
			tr("Expected at least %1 arguments, but %2 provided")
				.arg(minArgs)
				.arg(context->argumentCount()));
		return true;
	}

	return false;
}

bool QtCocosScriptEngine::isArgumentCountGreaterThan(
	QScriptContext *context, int maxArgs)
{
	Q_ASSERT(context);
	if (context->argumentCount() > maxArgs)
	{
		context->throwError(tr("Expected at most %1 arguments, but %2 provided")
								.arg(maxArgs)
								.arg(context->argumentCount()));
		return true;
	}

	return false;
}

bool QtCocosScriptEngine::checkArgumentCount(
	QScriptContext *context, int min, int max)
{
	if (isArgumentCountLessThan(context, min) ||
		isArgumentCountGreaterThan(context, max))
	{
		return false;
	}
	return true;
}

void QtCocosScriptEngine::noPublicConstructorException(
	QScriptContext *context, const QString &className)
{
	Q_ASSERT(context);
	context->throwError(
		tr("No public constructor for class %1").arg(className));
}

void QtCocosScriptEngine::badArgumentsException(
	QScriptContext *context, const QString &funcName)
{
	Q_ASSERT(context);
	context->throwError(tr("Bad arguments for %1 call").arg(funcName));
}

const QScriptValue &QtCocosScriptEngine::ccRootObject() const
{
	return mRootObject;
}

QtCocosScriptEngine *QtCocosScriptEngine::instance()
{
	return _instance;
}

ccScriptType QtCocosScriptEngine::getScriptType()
{
	return kScriptTypeJavascript;
}

void QtCocosScriptEngine::removeScriptObjectByCCObject(CCObject *)
{
	//do nothing
}

void QtCocosScriptEngine::removeScriptHandler(int64_t nHandler)
{
	if (nHandler == 0)
		return;

	releaseJSObject(nHandler);
}

int QtCocosScriptEngine::executeString(const char *)
{
	return 0;
}

int QtCocosScriptEngine::executeScriptFile(const char *)
{
	return 0;
}

int QtCocosScriptEngine::executeGlobalFunction(const char *functionName)
{
	auto func = mEngine->globalObject().property(QLatin1String(functionName));
	checkResult(func.call());
	return 1;
}

int QtCocosScriptEngine::executeNodeEvent(CCNode *pNode, int nAction)
{
	int funcId = getNodeEventFuncId(nAction);
	if (funcId < 0)
		return 0;

	auto object = getRegisteredJSObject(pNode->getScriptHandler());
	if (!object.isObject())
		return 0;

	executeScriptFunction(funcId, object);
	return 1;
}

int QtCocosScriptEngine::executeMenuItemEvent(CCMenuItem *pMenuItem)
{
	auto object = getRegisteredJSObject(pMenuItem->getScriptTapHandler());
	if (object.isFunction())
	{
		checkResult(object.call());
		return 1;
	}

	if (!object.isObject())
		return 0;

	executeScriptFunction(ACTIVATE, object);
	return 1;
}

int QtCocosScriptEngine::executeNotificationEvent(
	CCNotificationCenter *pCenter, const char *pszName)
{
	if (!pCenter || !pszName)
		return 0;

	auto func = getRegisteredJSObject(pCenter->getScriptHandler());
	if (!func.isFunction())
		return 0;

	checkResult(func.call(QScriptValue(),
		QScriptValueList() << QScriptValue(
			mEngine, QString::fromUtf8(pszName))));

	return 1;
}

int QtCocosScriptEngine::executeCallFuncActionEvent(
	CCCallFunc *pAction, CCObject *pTarget)
{
	if (!pAction || !pTarget)
		return 0;

	auto func = getRegisteredJSObject(pAction->getScriptHandler());
	if (!func.isFunction())
		return 0;

	auto object = mEngine->toScriptValue(pTarget);
	if (!object.isObject())
		return 0;

	checkResult(func.call(object));
	return 1;
}

int QtCocosScriptEngine::executeSchedule(
	int64_t nHandler, float dt, CCNode *node)
{
	QScriptValue object;
	object = getRegisteredJSObject(nHandler);
	QScriptValueList args;
	args << QScriptValue(mEngine, dt);
	if (object.isFunction())
	{
		checkResult(object.call(mEngine->toScriptValue(node), args));
		return 1;
	}
	if (!object.isObject())
		return 0;

	executeScriptFunction(
		UPDATE, object, QScriptValueList() << QScriptValue(mEngine, dt));
	return 1;
}

int QtCocosScriptEngine::executeLayerTouchesEvent(
	CCLayer *pLayer, int eventType, CCSet *pTouches)
{
	Q_ASSERT(pLayer);
	auto handler = pLayer->getScriptTouchHandlerEntry();
	if (!handler)
		return 0;

	QScriptValue object = getRegisteredJSObject(handler->getHandler());
	if (!object.isObject())
		return 0;

	int funcId = getTouchesFuncId(eventType);
	QScriptValueList args;
	auto array = mEngine->newArray(pTouches->count());
	quint32 i = 0;
	for (auto it = pTouches->begin(); it != pTouches->end(); ++it, ++i)
	{
		array.setProperty(
			i, mEngine->toScriptValue(reinterpret_cast<CCTouch *>(*it)));
	}
	args << array;
	executeScriptFunction(funcId, object, args);
	return 1;
}

int QtCocosScriptEngine::executeLayerTouchEvent(
	CCLayer *pLayer, int eventType, CCTouch *pTouch)
{
	Q_ASSERT(pLayer);
	auto handler = pLayer->getScriptTouchHandlerEntry();
	if (!handler)
		return 0;

	QScriptValue object = getRegisteredJSObject(handler->getHandler());
	if (!object.isObject())
		return 0;

	int funcId = getTouchFuncId(eventType);
	QScriptValueList args;
	args << mEngine->toScriptValue(pTouch);
	auto result = executeScriptFunction(funcId, object, args);
	return result.isError() ? 0 : result.toBool();
}

int QtCocosScriptEngine::executeLayerKeypadEvent(CCLayer *pLayer, int eventType)
{
	Q_ASSERT(pLayer);
	auto handler = pLayer->getScriptKeypadHandlerEntry();
	if (!handler)
		return 0;

	QScriptValue object = getRegisteredJSObject(handler->getHandler());
	if (!object.isObject())
		return 0;

	QScriptValue callback;
	switch (ccKeypadMSGType(eventType))
	{
		case kTypeBackClicked:
			executeScriptFunction(BACK_CLICKED, object);
			break;
		case kTypeMenuClicked:
			executeScriptFunction(MENU_CLICKED, object);
			break;
	}
	return 1;
}

int QtCocosScriptEngine::executeAccelerometerEvent(CCLayer *, CCAcceleration *)
{
	return 0;
}

int QtCocosScriptEngine::executeEvent(
	int64_t, const char *, CCObject *, const char *)
{
	return 0;
}

bool QtCocosScriptEngine::handleAssert(const char *)
{
	return false;
}

bool QtCocosScriptEngine::parseConfig(ConfigType, const std::string &)
{
	return false;
}

QScriptValue QtCocosScriptEngine::getRegisteredJSObject(qint64 id) const
{
	if (!id)
		return QScriptValue();

	auto it = mJSObjectMap.find(id);
	Q_ASSERT(it != mJSObjectMap.end());
	return it->second;
}

QScriptValue QtCocosScriptEngine::checkResult(const QScriptValue &value)
{
	if (value.isError())
	{
		emit log(value);
		mEngine->clearExceptions();
	}
	return value;
}

const QScriptString &QtCocosScriptEngine::jsString(int id) const
{
	Q_ASSERT(id >= 0);
	Q_ASSERT(id < STRING_ID_COUNT);

	return mStringIds[id];
}

QScriptValue QtCocosScriptEngine::propertyById(
	int id, const QScriptValue &object) const
{
	return object.property(jsString(id));
}

int QtCocosScriptEngine::getNodeEventFuncId(int nAction)
{
	switch (nAction)
	{
		case kCCNodeOnEnter:
			return ON_ENTER;

		case kCCNodeOnExit:
			return ON_EXIT;

		case kCCNodeOnEnterTransitionDidFinish:
			return ON_ENTER_TRANSITION_DID_FINISH;

		case kCCNodeOnExitTransitionDidStart:
			return ON_EXIT_TRANSITION_DID_START;
	}

	return -1;
}

int QtCocosScriptEngine::getTouchesFuncId(int eventType)
{
	switch (eventType)
	{
		case CCTOUCHBEGAN:
			return ON_TOUCHES_BEGIN;

		case CCTOUCHENDED:
			return ON_TOUCHES_ENDED;

		case CCTOUCHMOVED:
			return ON_TOUCHES_MOVED;

		case CCTOUCHCANCELLED:
			return ON_TOUCHES_CANCELLED;
	}
	return -1;
}

int QtCocosScriptEngine::getTouchFuncId(int eventType)
{
	switch (eventType)
	{
		case CCTOUCHBEGAN:
			return ON_TOUCH_BEGIN;
		case CCTOUCHENDED:
			return ON_TOUCH_ENDED;
		case CCTOUCHMOVED:
			return ON_TOUCH_MOVED;
		case CCTOUCHCANCELLED:
			return ON_TOUCH_CANCELLED;
	}

	return -1;
}

QScriptValue QtCocosScriptEngine::executeScriptFunction(
	int funcId, const QScriptValue &object, const QScriptValueList &args)
{
	Q_ASSERT(funcId >= 0);
	Q_ASSERT(funcId < STRING_ID_COUNT);
	Q_ASSERT(object.isObject());

	auto func = object.property(mStringIds[funcId]);
	return checkResult(func.call(object, args));
}
