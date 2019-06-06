#include "QtScriptCCObject.hpp"

namespace cocos2d
{
QtScriptCCObject::QtScriptCCObject(
	QScriptEngine *engine, const QString &className)
	: QObject(engine)
	, QScriptClass(engine)
	, mClassName(className)
{
}

QtScriptCCObject::QtScriptCCObject(QScriptEngine *engine)
	: QtScriptCCObject(engine, "Object")
{
}

void QtScriptCCObject::Register(const QScriptValue &targetNamespace)
{
	auto ccEngine = QtCocosScriptEngine::instance();
	Q_ASSERT(ccEngine);
	auto inherit = ccEngine->propertyById(QtCocosScriptEngine::PROTOTYPE,
		ccEngine->propertyById(
			QtCocosScriptEngine::OBJECT, ccEngine->engine()->globalObject()));
	RegisterT<CCObject, QtScriptCCObject>(targetNamespace, inherit);
}

QScriptValue QtScriptCCObject::newInstance(CCObject *obj)
{
	Q_ASSERT(obj);
	auto engine = this->engine();
	auto result = engine->newVariant(QVariant::fromValue(obj));
	result.setScriptClass(this);
	return result;
}

CCObject *QtScriptCCObject::toCCObject(const QScriptValue &value)
{
	if (!value.isVariant())
	{
		return nullptr;
	}
	auto v = value.toVariant();
	if (v.userType() != qMetaTypeId<CCObject *>())
		return nullptr;

	return v.value<CCObject *>();
}

QScriptValue QtScriptCCObject::tryConstructCCObject(QScriptContext *ctx)
{
	if (!QtCocosScriptEngine::checkArgumentCount(
			ctx, constructorArgumentCountMin(), constructorArgumentCountMax()))
	{
		return engine()->uncaughtException();
	}

	CCObject *newObject;
	if (!constructObject(ctx, newObject))
	{
		return engine()->uncaughtException();
	}
	newObject->autorelease();
	return newInstance(newObject);
}

QString QtScriptCCObject::toString() const
{
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
	{
		CCPrettyPrinter printer;
		ccObject->acceptVisitor(printer);

		return QString::fromUtf8(printer.getResult().c_str());
	}

	return QStringLiteral("[cc.%1]").arg(mClassName);
}

void QtScriptCCObject::update(float dt)
{
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
		ccObject->update(dt);
}

CCObject *QtScriptCCObject::copy()
{
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
	{
		return ccObject->copy();
	}
	return nullptr;
}

QString QtScriptCCObject::name() const
{
	return mClassName;
}

QScriptValue QtScriptCCObject::prototype() const
{
	return mProto;
}

int QtScriptCCObject::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCObject::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCObject::constructObject(
	QScriptContext *, NativeObjectType &out) const
{
	out = new CCObject;
	return true;
}
}
