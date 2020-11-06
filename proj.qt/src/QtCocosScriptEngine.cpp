#include "QtCocosScriptEngine.h"

#include "cocos2d.h"

#include "QtScriptInstall.h"
#include "js_bindings/manual/QtScriptRef.hpp"
#include "js_bindings/manual/QtScriptRefHolder.h"
#include "js_bindings/manual/QtScriptCCCustomEffect.h"
#include "js_bindings/generated/qtscript_cocos2dx.hpp"

#include "js_bindings/QtCocosScriptUtils.hpp"

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
	"length",
	"prototype",
};

#define STATIC_PROPERTY (QScriptValue::ReadOnly | QScriptValue::Undeletable)

static QScriptValue stringVecToScriptValue(
	QScriptEngine *eng, const std::vector<std::string> &cont)
{
	QScriptValue a = eng->newArray(uint(cont.size()));
	auto begin = cont.begin();
	auto end = cont.end();
	auto it = begin;
	quint32 i;
	for (i = 0; it != end; ++it, ++i)
	{
		a.setProperty(i, eng->toScriptValue(QByteArray::fromStdString(*it)));
	}
	return a;
}

static void stringVecFromScriptValue(
	const QScriptValue &value, std::vector<std::string> &cont)
{
	quint32 length = QtCocosScriptEngine::instance()
						 ->propertyById(QtCocosScriptEngine::LENGTH, value)
						 .toUInt32();
	cont.reserve(length);
	for (quint32 i = 0; i < length; ++i)
	{
		QScriptValue item = value.property(i);
		auto ba = qscriptvalue_cast<QByteArray>(item);
		cont.emplace_back(ba.toStdString());
	}
}

static Color4B ccColor3Bto4B(const Color3B &from)
{
	return Color4B(from);
}

static Color3B ccColor4Bto3B(const Color4B &from)
{
	return Color3B(from);
}

static Color4F ccColor3Bto4F(const Color3B &from)
{
	return Color4F(from);
}

static Color3B ccColor4Fto3B(const Color4F &from)
{
	return Color3B(from);
}

static Color4B ccColor4Fto4B(const Color4F &from)
{
	return Color4B(from);
}

static Color4F ccColor4Bto4F(const Color4B &from)
{
	return Color4F(from);
}

static Size ccPointToCCSize(const Point &point)
{
	return Size(point);
}

static Point ccSizeToCCPoint(const Size &size)
{
	return Point(size.width, size.height);
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

	auto global = engine->globalObject();

	mRootObject = engine->newObject();
	mRootObject.setPrototype(
		engine->newQMetaObject(&cocos2d::staticMetaObject));

	global.setProperty(mStringIds[CC], mRootObject, STATIC_PROPERTY);

	qScriptRegisterMetaType<std::vector<std::string>>(
		engine, stringVecToScriptValue, stringVecFromScriptValue);

	QtCocosScriptUtils::registerVector<Node *>(engine);
	QtCocosScriptUtils::registerVector<Layer *>(engine);
	QtCocosScriptUtils::registerVector<AnimationFrame *>(engine);
	QtCocosScriptUtils::registerVector<SpriteFrame *>(engine);
	QtCocosScriptUtils::registerVector<FiniteTimeAction *>(engine);
	QtCocosScriptUtils::registerVector<MenuItem *>(engine);
	QtCocosScriptUtils::registerVector<Pass *>(engine);
	QtCocosScriptUtils::registerVector<ParticleSystem *>(engine);
	QtCocosScriptUtils::registerCcValueConvesions(engine);

	QtScriptInstallQtCore(engine);
	QtScriptRef::Register(mRootObject);
	QtScriptRefHolder::Register(mRootObject);
	qtscript_register_all_cocos2dx(engine);
	QtScriptCCCustomEffect::Register(mRootObject);

	mRootObject.setProperty(QSTRKEY(spriteFrameByName),
		mEngine->newFunction(spriteFrameByName), STATIC_PROPERTY);
	mRootObject.setProperty(QSTRKEY(addImageSpriteFrame),
		mEngine->newFunction(addImageSpriteFrame), STATIC_PROPERTY);
	mRootObject.setProperty(QSTRKEY(shaderProgramByName),
		mEngine->newFunction(shaderProgramByName), STATIC_PROPERTY);
	mRootObject.setProperty(QSTRKEY(addShaderProgram),
		mEngine->newFunction(addShaderProgram), STATIC_PROPERTY);

	mRootObject.setProperty(QSTRKEY(VERSION_CODE),
		mEngine->newFunction(cocos2dVersionCode),
		STATIC_PROPERTY | QScriptValue::PropertyGetter);

	mRootObject.setProperty(QSTRKEY(VERSION_STRING),
		mEngine->newFunction(cocos2dVersionString),
		STATIC_PROPERTY | QScriptValue::PropertyGetter);

	static const bool cvtColor3Bto4B =
		QMetaType::registerConverter<Color3B, Color4B>(ccColor3Bto4B);
	Q_UNUSED(cvtColor3Bto4B);
	static const bool cvtColor4Bto3B =
		QMetaType::registerConverter<Color4B, Color3B>(ccColor4Bto3B);
	Q_UNUSED(cvtColor4Bto3B);
	static const bool cvtColor3Bto4F =
		QMetaType::registerConverter<Color3B, Color4F>(ccColor3Bto4F);
	Q_UNUSED(cvtColor3Bto4F);
	static const bool cvtColor4Fto3B =
		QMetaType::registerConverter<Color4F, Color3B>(ccColor4Fto3B);
	Q_UNUSED(cvtColor4Fto3B);
	static const bool cvtColor4Fto4B =
		QMetaType::registerConverter<Color4F, Color4B>(ccColor4Fto4B);
	Q_UNUSED(cvtColor4Fto4B);
	static const bool cvtColor4Bto4F =
		QMetaType::registerConverter<Color4B, Color4F>(ccColor4Bto4F);
	Q_UNUSED(cvtColor4Bto4F);

	static const bool cvtColor3BtoQColor =
		QMetaType::registerConverter<Color3B, QColor>(ccColor3BToQColor);
	Q_UNUSED(cvtColor3BtoQColor);
	static const bool cvtColor4BtoQColor =
		QMetaType::registerConverter<Color4B, QColor>(ccColor4BToQColor);
	Q_UNUSED(cvtColor4BtoQColor);
	static const bool cvtColor4FtoQColor =
		QMetaType::registerConverter<Color4F, QColor>(ccColor4FToQColor);
	Q_UNUSED(cvtColor4FtoQColor);
	static const bool cvtQColorToColor3B =
		QMetaType::registerConverter<QColor, Color3B>(qColorToCcColor3B);
	Q_UNUSED(cvtQColorToColor3B);
	static const bool cvtQColorToColor4B =
		QMetaType::registerConverter<QColor, Color4B>(qColorToCcColor4B);
	Q_UNUSED(cvtQColorToColor4B);
	static const bool cvtQColorToColor4F =
		QMetaType::registerConverter<QColor, Color4F>(qColorToCcColor4F);
	Q_UNUSED(cvtQColorToColor4F);

	static const bool cvtPointToSize =
		QMetaType::registerConverter<Point, Size>(ccPointToCCSize);
	Q_UNUSED(cvtPointToSize);
	static const bool cvtSizeToPoint =
		QMetaType::registerConverter<Size, Point>(ccSizeToCCPoint);
	Q_UNUSED(cvtSizeToPoint);

	static const bool cvtSizeToQSize =
		QMetaType::registerConverter<Size, QSize>(ccSizeToQSize);
	Q_UNUSED(cvtSizeToQSize);
	static const bool cvtSizeToQSizeF =
		QMetaType::registerConverter<Size, QSizeF>(ccSizeToQSizeF);
	Q_UNUSED(cvtSizeToQSizeF);

	static const bool cvtPointToQPoint =
		QMetaType::registerConverter<Point, QPoint>(ccPointToQPoint);
	Q_UNUSED(cvtPointToQPoint);
	static const bool cvtPointToQPointF =
		QMetaType::registerConverter<Point, QPointF>(ccPointToQPointF);
	Q_UNUSED(cvtPointToQPointF);

	static const bool cvtPointToQRect =
		QMetaType::registerConverter<Rect, QRect>(ccRectToQRect);
	Q_UNUSED(cvtPointToQRect);
	static const bool cvtPointToQRectF =
		QMetaType::registerConverter<Rect, QRectF>(ccRectToQRectF);
	Q_UNUSED(cvtPointToQRectF);

	static const bool cvtQSizeToSize =
		QMetaType::registerConverter<QSize, Size>(qSizeToCCSize);
	Q_UNUSED(cvtQSizeToSize);
	static const bool cvtQSizeFToSize =
		QMetaType::registerConverter<QSizeF, Size>(qSizeFToCCSize);
	Q_UNUSED(cvtQSizeFToSize);

	static const bool cvtQPointToPoint =
		QMetaType::registerConverter<QPoint, Point>(qPointToCCPoint);
	Q_UNUSED(cvtQPointToPoint);
	static const bool cvtQPointFToPoint =
		QMetaType::registerConverter<QPointF, Point>(qPointFToCCPoint);
	Q_UNUSED(cvtQPointFToPoint);

	static const bool cvtQRectToRect =
		QMetaType::registerConverter<QRect, Rect>(qRectToCCRect);
	Q_UNUSED(cvtQRectToRect);
	static const bool cvtQRectFToRect =
		QMetaType::registerConverter<QRectF, Rect>(qRectFToCCRect);
	Q_UNUSED(cvtQRectFToRect);
}

QtCocosScriptEngine::~QtCocosScriptEngine()
{
	Q_ASSERT(_instance == this);
	_instance = nullptr;
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

int QtCocosScriptEngine::executeString(const char *codes)
{
	auto result = checkResult(mEngine->evaluate(QString::fromUtf8(codes)));

	return result.isError() ? 1 : 0;
}

int QtCocosScriptEngine::executeScriptFile(const char *filePath)
{
	int result = checkResult(
		mEngine->evaluate(
			QString::fromStdString(
				FileUtils::getInstance()->getStringFromFile(filePath)),
			QString::fromUtf8(filePath)))
					 .toInt32();

	checkResult(QScriptValue());
	return result;
}

int QtCocosScriptEngine::executeGlobalFunction(const char *functionName)
{
	auto func = mEngine->globalObject().property(QLatin1String(functionName));
	int result = checkResult(func.call()).toInt32();
	checkResult(QScriptValue());
	return result;
}

int QtCocosScriptEngine::sendEvent(ScriptEvent *)
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

void QtCocosScriptEngine::garbageCollect()
{
	mEngine->collectGarbage();
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

QScriptValue QtCocosScriptEngine::cocos2dVersionCode(
	QScriptContext *context, QScriptEngine *engine)
{
	if (context->argumentCount() != 0)
	{
		QtScriptUtils::badArgumentsException(context, "cc.VERSION_CODE");
		return engine->uncaughtException();
	}

	return QScriptValue(engine, COCOS2D_VERSION);
}

QScriptValue QtCocosScriptEngine::cocos2dVersionString(
	QScriptContext *context, QScriptEngine *engine)
{
	if (context->argumentCount() != 0)
	{
		QtScriptUtils::badArgumentsException(context, "cc.VERSION_STRING");
		return engine->uncaughtException();
	}

	return QScriptValue(engine, QString::fromUtf8(cocos2d::cocos2dVersion()));
}

QScriptValue QtCocosScriptEngine::spriteFrameByName(
	QScriptContext *context, QScriptEngine *engine)
{
	if (context->argumentCount() != 1)
	{
		QtScriptUtils::badArgumentsException(context, "cc.spriteFrameByName");
		return engine->uncaughtException();
	}

	return engine->toScriptValue(
		SpriteFrameCache::getInstance()->getSpriteFrameByName(
			qscriptvalue_cast<QByteArray>(context->argument(0)).toStdString()));
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
			QtScriptUtils::badArgumentsException(
				context, "cc.addImageSpriteFrame");
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

	backend::PixelFormat textureFormat;
	if (image.hasAlphaChannel())
	{
		if (image.format() != QImage::Format_RGBA8888_Premultiplied)
		{
			image =
				image.convertToFormat(QImage::Format_RGBA8888_Premultiplied);
		}

		textureFormat = backend::PixelFormat::RGBA8888;
	} else
	{
		if (image.format() != QImage::Format_RGB888)
			image = image.convertToFormat(QImage::Format_RGB888);
		textureFormat = backend::PixelFormat::RGB888;
	}

	if (image.isNull())
	{
		image = QImage(1, 1, QImage::Format_RGB888);
		image.fill(Qt::transparent);
	}

	QtCocosContext::makeCurrent();

	Rect rect(0, 0, float(image.width()), float(image.height()));
	auto texture = new Texture2D;
	bool textureOk = texture->initWithData(image.constBits(), qImageSize(image),
		textureFormat, image.width(), image.height(), rect.size, true);

	Q_ASSERT(textureOk);
	Q_UNUSED(textureOk);

	if (argc == 3)
	{
		auto params =
			qscriptvalue_cast<backend::SamplerDescriptor>(context->argument(2));
		texture->setTexParameters(params);
	}

	auto spriteFrame = SpriteFrame::createWithTexture(texture, rect);
	SpriteFrameCache::getInstance()->addSpriteFrame(spriteFrame, key.data());

	texture->release();
	return engine->toScriptValue(spriteFrame);
}

QScriptValue QtCocosScriptEngine::shaderProgramByName(
	QScriptContext *context, QScriptEngine *engine)
{
	if (context->argumentCount() != 1)
	{
		QtScriptUtils::badArgumentsException(context, "cc.shaderProgramByName");
		return engine->uncaughtException();
	}

	return engine->toScriptValue(
		backend::ProgramCache::getInstance()->getCustomProgram(
			qscriptvalue_cast<QByteArray>(context->argument(0)).toStdString()));
}

QScriptValue QtCocosScriptEngine::addShaderProgram(
	QScriptContext *context, QScriptEngine *engine)
{
	int argc = context->argumentCount();
	switch (argc)
	{
		case 3:
			break;

		default:
			QtScriptUtils::badArgumentsException(
				context, "cc.addShaderProgram");
			return engine->uncaughtException();
	}

	QtCocosContext::makeCurrent();

	auto key = qscriptvalue_cast<QByteArray>(context->argument(0));

	auto arg1 = context->argument(1);
	auto arg2 = context->argument(2);

	auto vDevice = qscriptvalue_cast<QIODevice *>(arg1);
	auto fDevice = qscriptvalue_cast<QIODevice *>(arg2);

	auto vert =
		vDevice ? vDevice->readAll() : qscriptvalue_cast<QByteArray>(arg1);
	auto frag =
		fDevice ? fDevice->readAll() : qscriptvalue_cast<QByteArray>(arg2);

	auto program = backend::Device::getInstance()->newProgram(
		vert.toStdString(), frag.toStdString());

	backend::ProgramCache::getInstance()->addCustomProgram(
		key.toStdString(), program);

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
