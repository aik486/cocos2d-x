#include "QtCocosScriptEngine.h"

Q_DECLARE_METATYPE(std::vector<std::string>)

#include "cocos2dx.h"
#include "QtScriptInstall.h"
#include "js_bindings/manual/QtScriptRef.hpp"
#include "js_bindings/manual/QtScriptRefHolder.h"
#include "js_bindings/manual/QtScriptCCCustomEffect.h"
#include "js_bindings/generated/qtscript_cocos2dx.hpp"

#include "QtCocosHelper.h"
#include "QtCocosEnums.h"
#include "QtCocosContext.h"

#include <QScriptEngine>
#include <QScriptValueIterator>
#include <QIODevice>
#include <QImage>

using namespace cocos2d;

static QtCocosScriptEngine *_instance = nullptr;

const char *QtCocosScriptEngine::STRING_IDS[] = {
	"cc",
	"Object",
	"prototype",
};

#define STATIC_PROPERTY (QScriptValue::ReadOnly | QScriptValue::Undeletable)

static QScriptValue stringVecToScriptValue(
	QScriptEngine *eng, const std::vector<std::string> &cont)
{
	QScriptValue a = eng->newArray();
	auto begin = cont.begin();
	auto end = cont.end();
	auto it = begin;
	quint32 i;
	for (i = 0; it != end; ++it, ++i)
	{
		a.setProperty(
			i, eng->toScriptValue(QByteArray(it->c_str(), int(it->size()))));
	}
	return a;
}

static void stringVecFromScriptValue(
	const QScriptValue &value, std::vector<std::string> &cont)
{
	quint32 len = value.property(QLatin1String("length")).toUInt32();
	cont.reserve(len);
	for (quint32 i = 0; i < len; ++i)
	{
		QScriptValue item = value.property(i);
		auto ba = qscriptvalue_cast<QByteArray>(item);
		cont.push_back(std::string(ba.data(), size_t(ba.size())));
	}
}

static QScriptValue qColorToScriptValue(QScriptEngine *eng, const QColor &color)
{
	return eng->toScriptValue(cocos2d::qColorToCcColor4B(color));
}

static void qColorFromScriptValue(const QScriptValue &value, QColor &color)
{
	color = ccColor4BToQColor(qscriptvalue_cast<cocos2d::_ccColor4B>(value));
}

static _ccColor4B ccColor3Bto4B(const _ccColor3B &from)
{
	_ccColor4B result;
	result.r = from.r;
	result.g = from.g;
	result.b = from.b;
	result.a = 255;
	return result;
}

static _ccColor3B ccColor4Bto3B(const _ccColor4B &from)
{
	_ccColor3B result;
	result.r = from.r;
	result.g = from.g;
	result.b = from.b;
	return result;
}

static _ccColor4F ccColor3Bto4F(const _ccColor3B &from)
{
	_ccColor4F result;
	result.r = from.r / 255.f;
	result.g = from.g / 255.f;
	result.b = from.b / 255.f;
	result.a = 1.f;
	return result;
}

static _ccColor3B ccColor4Fto3B(const _ccColor4F &from)
{
	_ccColor3B result;
	result.r = GLubyte(std::max(0, std::min(255, int(from.r * 255.f))));
	result.g = GLubyte(std::max(0, std::min(255, int(from.g * 255.f))));
	result.b = GLubyte(std::max(0, std::min(255, int(from.b * 255.f))));
	return result;
}

static _ccColor4B ccColor4Fto4B(const _ccColor4F &from)
{
	_ccColor4B result;
	result.r = GLubyte(std::max(0, std::min(255, int(from.r * 255.f))));
	result.g = GLubyte(std::max(0, std::min(255, int(from.g * 255.f))));
	result.b = GLubyte(std::max(0, std::min(255, int(from.b * 255.f))));
	result.a = GLubyte(std::max(0, std::min(255, int(from.a * 255.f))));
	return result;
}

static _ccColor4F ccColor4Bto4F(const _ccColor4B &from)
{
	_ccColor4F result;
	result.r = from.r / 255.f;
	result.g = from.g / 255.f;
	result.b = from.b / 255.f;
	result.a = from.a / 255.f;
	return result;
}

static CCSize ccPointToCCSize(const CCPoint &point)
{
	CCSize result;
	result.width = point.x;
	result.height = point.y;
	return result;
}

static CCPoint ccSizeToCCPoint(const CCSize &size)
{
	CCPoint result;
	result.x = size.width;
	result.y = size.height;
	return result;
}

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

	auto glObject = engine->newObject();
	glObject.setPrototype(engine->newQMetaObject(&gl_enum::staticMetaObject));

	auto global = engine->globalObject();
	global.setProperty("gl", glObject, STATIC_PROPERTY);

	mRootObject = engine->newObject();
	mRootObject.setPrototype(
		engine->newQMetaObject(&cocos2d::staticMetaObject));

	global.setProperty(mStringIds[CC], mRootObject, STATIC_PROPERTY);

	qScriptRegisterMetaType<std::vector<std::string>>(
		engine, stringVecToScriptValue, stringVecFromScriptValue);

	QtScriptInstallQtCore(engine);
	QtScriptCCObject::Register(mRootObject);
	QtScriptRefHolder::Register(mRootObject);
	qtscript_register_all_cocos2dx(engine);
	QtScriptCCCustomEffect::Register(mRootObject);

	qScriptRegisterMetaType<QColor>(mEngine, qColorToScriptValue,
		qColorFromScriptValue,
		engine->defaultPrototype(qMetaTypeId<_ccColor4B>()));

	mRootObject.setProperty(QSTRKEY(spriteFrameByName),
		mEngine->newFunction(spriteFrameByName), STATIC_PROPERTY);
	mRootObject.setProperty(QSTRKEY(addImageSpriteFrame),
		mEngine->newFunction(addImageSpriteFrame), STATIC_PROPERTY);
	mRootObject.setProperty(QSTRKEY(shaderProgramByName),
		mEngine->newFunction(shaderProgramByName), STATIC_PROPERTY);
	mRootObject.setProperty(QSTRKEY(addShaderProgram),
		mEngine->newFunction(addShaderProgram), STATIC_PROPERTY);

	static const bool cvtColor3Bto4B =
		QMetaType::registerConverter<_ccColor3B, _ccColor4B>(ccColor3Bto4B);
	Q_UNUSED(cvtColor3Bto4B);
	static const bool cvtColor4Bto3B =
		QMetaType::registerConverter<_ccColor4B, _ccColor3B>(ccColor4Bto3B);
	Q_UNUSED(cvtColor4Bto3B);
	static const bool cvtColor3Bto4F =
		QMetaType::registerConverter<_ccColor3B, _ccColor4F>(ccColor3Bto4F);
	Q_UNUSED(cvtColor3Bto4F);
	static const bool cvtColor4Fto3B =
		QMetaType::registerConverter<_ccColor4F, _ccColor3B>(ccColor4Fto3B);
	Q_UNUSED(cvtColor4Fto3B);
	static const bool cvtColor4Fto4B =
		QMetaType::registerConverter<_ccColor4F, _ccColor4B>(ccColor4Fto4B);
	Q_UNUSED(cvtColor4Fto4B);
	static const bool cvtColor4Bto4F =
		QMetaType::registerConverter<_ccColor4B, _ccColor4F>(ccColor4Bto4F);
	Q_UNUSED(cvtColor4Bto4F);

	static const bool cvtColor3BtoQColor =
		QMetaType::registerConverter<_ccColor3B, QColor>(ccColor3BToQColor);
	Q_UNUSED(cvtColor3BtoQColor);
	static const bool cvtColor4BtoQColor =
		QMetaType::registerConverter<_ccColor4B, QColor>(ccColor4BToQColor);
	Q_UNUSED(cvtColor4BtoQColor);
	static const bool cvtColor4FtoQColor =
		QMetaType::registerConverter<_ccColor4F, QColor>(ccColor4FToQColor);
	Q_UNUSED(cvtColor4FtoQColor);
	static const bool cvtQColorToColor3B =
		QMetaType::registerConverter<QColor, _ccColor3B>(qColorToCcColor3B);
	Q_UNUSED(cvtQColorToColor3B);
	static const bool cvtQColorToColor4B =
		QMetaType::registerConverter<QColor, _ccColor4B>(qColorToCcColor4B);
	Q_UNUSED(cvtQColorToColor4B);
	static const bool cvtQColorToColor4F =
		QMetaType::registerConverter<QColor, _ccColor4F>(qColorToCcColor4F);
	Q_UNUSED(cvtQColorToColor4F);

	static const bool cvtPointToSize =
		QMetaType::registerConverter<CCPoint, CCSize>(ccPointToCCSize);
	Q_UNUSED(cvtPointToSize);
	static const bool cvtSizeToPoint =
		QMetaType::registerConverter<CCSize, CCPoint>(ccSizeToCCPoint);
	Q_UNUSED(cvtSizeToPoint);

	static const bool cvtSizeToQSize =
		QMetaType::registerConverter<CCSize, QSize>(ccSizeToQSize);
	Q_UNUSED(cvtSizeToQSize);
	static const bool cvtSizeToQSizeF =
		QMetaType::registerConverter<CCSize, QSizeF>(ccSizeToQSizeF);
	Q_UNUSED(cvtSizeToQSizeF);

	static const bool cvtPointToQPoint =
		QMetaType::registerConverter<CCPoint, QPoint>(ccPointToQPoint);
	Q_UNUSED(cvtPointToQPoint);
	static const bool cvtPointToQPointF =
		QMetaType::registerConverter<CCPoint, QPointF>(ccPointToQPointF);
	Q_UNUSED(cvtPointToQPointF);

	static const bool cvtPointToQRect =
		QMetaType::registerConverter<CCRect, QRect>(ccRectToQRect);
	Q_UNUSED(cvtPointToQRect);
	static const bool cvtPointToQRectF =
		QMetaType::registerConverter<CCRect, QRectF>(ccRectToQRectF);
	Q_UNUSED(cvtPointToQRectF);

	static const bool cvtQSizeToSize =
		QMetaType::registerConverter<QSize, CCSize>(qSizeToCCSize);
	Q_UNUSED(cvtQSizeToSize);
	static const bool cvtQSizeFToSize =
		QMetaType::registerConverter<QSizeF, CCSize>(qSizeFToCCSize);
	Q_UNUSED(cvtQSizeFToSize);

	static const bool cvtQPointToPoint =
		QMetaType::registerConverter<QPoint, CCPoint>(qPointToCCPoint);
	Q_UNUSED(cvtQPointToPoint);
	static const bool cvtQPointFToPoint =
		QMetaType::registerConverter<QPointF, CCPoint>(qPointFToCCPoint);
	Q_UNUSED(cvtQPointFToPoint);

	static const bool cvtQRectToRect =
		QMetaType::registerConverter<QRect, CCRect>(qRectToCCRect);
	Q_UNUSED(cvtQRectToRect);
	static const bool cvtQRectFToRect =
		QMetaType::registerConverter<QRectF, CCRect>(qRectFToCCRect);
	Q_UNUSED(cvtQRectFToRect);
}

QtCocosScriptEngine::~QtCocosScriptEngine()
{
	Q_ASSERT(_instance == this);
	_instance = nullptr;
}

qint64 QtCocosScriptEngine::retainJSObject(const QScriptValue &v)
{
	if (!v.isObject() && !v.isFunction())
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
	auto func = getRegisteredJSObject(pNode->getScriptHandler());
	if (!func.isFunction())
		return 0;

	executeEventHandler(func, mEngine->toScriptValue(pNode),
		QScriptValueList() << QScriptValue(mEngine, nAction));
	return 1;
}

int QtCocosScriptEngine::executeMenuItemEvent(CCMenuItem *pMenuItem)
{
	auto func = getRegisteredJSObject(pMenuItem->getScriptTapHandler());
	if (func.isFunction())
	{
		executeEventHandler(func, mEngine->toScriptValue(pMenuItem));
		return 1;
	}
	return 0;
}

int QtCocosScriptEngine::executeNotificationEvent(
	CCNotificationCenter *pCenter, const char *pszName)
{
	if (!pCenter || !pszName)
		return 0;

	auto func = getRegisteredJSObject(pCenter->getScriptHandler());
	if (!func.isFunction())
		return 0;

	executeEventHandler(func, QScriptValue(),
		QScriptValueList() << QScriptValue(
			mEngine, QString::fromUtf8(pszName)));

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

	auto node = dynamic_cast<CCNode *>(pTarget);
	auto object =
		node ? mEngine->toScriptValue(node) : mEngine->toScriptValue(pTarget);

	executeEventHandler(func, object);
	return 1;
}

int QtCocosScriptEngine::executeSchedule(int64_t nHandler, float dt, Node *node)
{
	QScriptValue func = getRegisteredJSObject(nHandler);
	if (func.isFunction())
	{
		QScriptValueList args;
		args << QScriptValue(mEngine, dt);
		executeEventHandler(func, mEngine->toScriptValue(node), args);
		return 1;
	}
	return 0;
}

int QtCocosScriptEngine::executeLayerTouchesEvent(
	Layer *pLayer, int eventType, std::vector<Touch *> *pTouches)
{
	Q_ASSERT(pLayer);
	auto handler = pLayer->getScriptTouchHandlerEntry();
	if (!handler)
		return 0;

	QScriptValue func = getRegisteredJSObject(handler->getHandler());
	if (!func.isFunction())
		return 0;

	QScriptValueList args;
	args << QScriptValue(mEngine, eventType);
	auto array = mEngine->newArray(pTouches->count());
	quint32 i = 0;
	for (auto it = pTouches->begin(); it != pTouches->end(); ++it, ++i)
	{
		array.setProperty(
			i, mEngine->toScriptValue(reinterpret_cast<CCTouch *>(*it)));
	}
	args << array;
	auto result =
		executeEventHandler(func, mEngine->toScriptValue(pLayer), args);
	return result.isError() ? 0 : result.toBool();
}

int QtCocosScriptEngine::executeLayerTouchEvent(
	Layer *pLayer, int eventType, Touch *pTouch)
{
	Q_ASSERT(pLayer);
	auto handler = pLayer->getScriptTouchHandlerEntry();
	if (!handler)
		return 0;

	QScriptValue func = getRegisteredJSObject(handler->getHandler());
	if (!func.isFunction())
		return 0;

	QScriptValueList args;
	args << QScriptValue(mEngine, eventType);
	args << mEngine->toScriptValue(pTouch);
	auto result =
		executeEventHandler(func, mEngine->toScriptValue(pLayer), args);
	return result.isError() ? 0 : result.toBool();
}

int QtCocosScriptEngine::executeLayerKeypadEvent(Layer *pLayer, int eventType)
{
	Q_ASSERT(pLayer);
	auto handler = pLayer->getScriptKeypadHandlerEntry();
	if (!handler)
		return 0;

	QScriptValue func = getRegisteredJSObject(handler->getHandler());
	if (!func.isFunction())
		return 0;

	QScriptValueList args;
	args << QScriptValue(mEngine, eventType);
	auto result =
		executeEventHandler(func, mEngine->toScriptValue(pLayer), args);
	return result.isError() ? 0 : result.toBool();
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

QScriptValue QtCocosScriptEngine::checkResult(QScriptValue value)
{
	if (mEngine->hasUncaughtException())
	{
		value = mEngine->uncaughtException();
		emit log(value);
		mEngine->clearExceptions();
	}
	return value;
}

QScriptValue QtCocosScriptEngine::spriteFrameByName(
	QScriptContext *context, QScriptEngine *engine)
{
	if (context->argumentCount() != 1)
	{
		badArgumentsException(context, "cc.spriteFrameByName");
		return engine->uncaughtException();
	}

	return engine->toScriptValue(
		CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(
			qscriptvalue_cast<QByteArray>(context->argument(0)).constData()));
}

QScriptValue QtCocosScriptEngine::addImageSpriteFrame(
	QScriptContext *context, QScriptEngine *engine)
{
	int argc = context->argumentCount();
	switch (argc)
	{
		case 2:
		case 3:
			break;

		default:
			badArgumentsException(context, "cc.addImageSpriteFrame");
			return engine->uncaughtException();
	}

	auto key = qscriptvalue_cast<QByteArray>(context->argument(0));
	auto arg1 = context->argument(1);
	auto device = qscriptvalue_cast<QIODevice *>(arg1);

	QImage image;

	if (device)
	{
		image.load(device, nullptr);
	} else
	{
		image.loadFromData(qscriptvalue_cast<QByteArray>(arg1));
	}

	CCTexture2DPixelFormat textureFormat;
	if (image.hasAlphaChannel())
	{
		if (image.format() != QImage::Format_RGBA8888_Premultiplied)
		{
			image =
				image.convertToFormat(QImage::Format_RGBA8888_Premultiplied);
		}

		textureFormat = kCCTexture2DPixelFormat_RGBA8888;
	} else
	{
		if (image.format() != QImage::Format_RGB888)
			image = image.convertToFormat(QImage::Format_RGB888);
		textureFormat = kCCTexture2DPixelFormat_RGB888;
	}

	if (image.isNull())
	{
		image = QImage(1, 1, QImage::Format_RGB888);
		image.fill(Qt::transparent);
	}

	QtCocosContext::makeCurrent();

	CCRect rect(0, 0, float(image.width()), float(image.height()));
	auto texture = new CCTexture2D;
	bool textureOk = texture->initWithData(image.constBits(), textureFormat,
		image.width(), image.height(), rect.size, true);

	Q_ASSERT(textureOk);
	Q_UNUSED(textureOk);

	if (argc == 3)
	{
		auto params = qscriptvalue_cast<ccTexParams>(context->argument(2));
		texture->setTexParameters(&params);
	}

	auto spriteFrame = CCSpriteFrame::createWithTexture(texture, rect);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(
		spriteFrame, key.data());

	texture->release();
	return engine->toScriptValue(spriteFrame);
}

QScriptValue QtCocosScriptEngine::shaderProgramByName(
	QScriptContext *context, QScriptEngine *engine)
{
	if (context->argumentCount() != 1)
	{
		badArgumentsException(context, "cc.shaderProgramByName");
		return engine->uncaughtException();
	}

	return engine->toScriptValue(
		CCShaderCache::sharedShaderCache()->programForKey(
			qscriptvalue_cast<QByteArray>(context->argument(0)).constData()));
}

QScriptValue QtCocosScriptEngine::addShaderProgram(
	QScriptContext *context, QScriptEngine *engine)
{
	int argc = context->argumentCount();
	switch (argc)
	{
		case 3:
		case 4:
			break;

		default:
			badArgumentsException(context, "cc.addShaderProgram");
			return engine->uncaughtException();
	}

	QtCocosContext::makeCurrent();

	auto program = new CCGLProgram;

	auto key = qscriptvalue_cast<QByteArray>(context->argument(0));

	auto arg1 = context->argument(1);
	auto arg2 = context->argument(2);

	auto vDevice = qscriptvalue_cast<QIODevice *>(arg1);
	auto fDevice = qscriptvalue_cast<QIODevice *>(arg2);

	auto vert =
		vDevice ? vDevice->readAll() : qscriptvalue_cast<QByteArray>(arg1);
	auto frag =
		fDevice ? fDevice->readAll() : qscriptvalue_cast<QByteArray>(arg2);

	program->initWithVertexShaderByteArray(vert.constData(), frag.constData());

	if (argc == 4)
	{
		QScriptValueIterator it(context->argument(3));
		while (it.hasNext())
		{
			it.next();
			if (it.flags() & QScriptValue::SkipInEnumeration)
				continue;

			program->addAttribute(
				it.name().toUtf8().constData(), it.value().toUInt32());
		}
	}

	program->link();
	program->updateUniforms();

	CCShaderCache::sharedShaderCache()->addProgram(program, key.constData());

	program->release();

	return engine->toScriptValue(program);
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

QScriptValue QtCocosScriptEngine::executeEventHandler(
	QScriptValue func, const QScriptValue &object, const QScriptValueList &args)
{
	Q_ASSERT(func.isFunction());
	return checkResult(func.call(object, args));
}
