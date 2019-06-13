#include "QtScriptCCObject.hpp"

namespace cocos2d
{
QtScriptCCObject::QtScriptCCObject(
	QScriptEngine *engine, const QByteArray &className)
	: QtScriptAbstractClass(engine, className)
{
}

QtScriptCCObject::QtScriptCCObject(QScriptEngine *engine)
	: QtScriptCCObject(engine, "Object")
{
}

void QtScriptCCObject::Register(const QScriptValue &targetNamespace)
{
	RegisterT<CCObject, QtScriptCCObject>(targetNamespace, QScriptValue());
}

QScriptValue QtScriptCCObject::newInstance(CCObject *obj)
{
	Q_ASSERT(obj);
	auto result = engine()->newVariant(QVariant::fromValue(obj));
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

QScriptValue QtScriptCCObject::newScriptObject(QScriptContext *context)
{
	CCObject *newObject;
	if (!constructObject(context, newObject))
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

QScriptValue QtScriptCCObject::copy()
{
	CCObject *object = nullptr;
	auto ccObject = thiz<CCObject *>();
	if (ccObject)
	{
		object = ccObject->copy();
	}

	if (!object)
		return context()->throwError(tr("The object is not copyable"));
	object->autorelease();
	return newInstance(object);
}

int QtScriptCCObject::constructorArgumentCountMin() const
{
	return 0;
}

int QtScriptCCObject::constructorArgumentCountMax() const
{
	return 0;
}

bool QtScriptCCObject::constructObject(QScriptContext *, CCObject *&out)
{
	out = new CCObject;
	return true;
}
}
