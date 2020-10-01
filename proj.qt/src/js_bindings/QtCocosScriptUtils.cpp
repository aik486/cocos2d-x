#include "QtCocosScriptUtils.hpp"

#include "js_bindings/generated/qtscript_cocos2dx.hpp"

#include "QtScriptQByteArray.h"

#include <QScriptValueIterator>

namespace cocos2d
{
QtCocosScriptUtils::PixelsCallback QtCocosScriptUtils::getPixelsCallback(
	QScriptValue callback)
{
	if (!callback.isFunction())
	{
		return nullptr;
	}

	return [=](const unsigned char *data, size_t pixelSize, size_t width,
			   size_t height) mutable {
		QScriptValueList arguments;
		auto engine = callback.engine();
		arguments << engine->toScriptValue(QByteArray::fromRawData(
			reinterpret_cast<const char *>(data), width * pixelSize * height));
		arguments << engine->toScriptValue(width);
		arguments << engine->toScriptValue(height);
		callback.call(QScriptValue(), arguments);
	};
}

QtCocosScriptUtils::Sprite3DCallback QtCocosScriptUtils::getSprite3DCallback(
	QScriptValue callback)
{
	if (!callback.isFunction())
	{
		return nullptr;
	}

	return [=](Sprite3D *sprite, void *) mutable {
		QScriptValueList arguments;
		auto engine = callback.engine();
		arguments << engine->toScriptValue(sprite);
		callback.call(QScriptValue(), arguments);
	};
}

void QtCocosScriptUtils::registerCcValueConvesions(QScriptEngine *engine)
{
	qScriptRegisterMetaType<Value>(
		engine, ccValueToQScriptValue, qScriptValueToCcValue);

	qScriptRegisterMetaType<ValueVector>(
		engine, ccValueVectorToQScriptValue, qScriptValueToCcValueVector);

	qScriptRegisterMetaType<ValueMap>(
		engine, ccValueMapToQScriptValue, qScriptValueToCcValueMap);

	qScriptRegisterMetaType<ValueMapIntKey>(
		engine, ccValueMapIntKeyToQScriptValue, qScriptValueToCcValueMapIntKey);
}

QScriptValue QtCocosScriptUtils::ccValueToQScriptValue(
	QScriptEngine *engine, const Value &value)
{
	switch (value.getType())
	{
		case Value::Type::NONE:
			break;

		case Value::Type::BYTE:
			return QScriptValue(engine, value.asByte());

		case Value::Type::INTEGER:
			return QScriptValue(engine, value.asInt());

		case Value::Type::UNSIGNED:
			return QScriptValue(engine, value.asUnsignedInt());

		case Value::Type::FLOAT:
			return QScriptValue(engine, value.asFloat());

		case Value::Type::DOUBLE:
			return QScriptValue(engine, value.asDouble());

		case Value::Type::BOOLEAN:
			return QScriptValue(engine, value.asBool());

		case Value::Type::STRING:
			return QScriptValue(
				engine, QString::fromStdString(value.asString()));

		case Value::Type::VECTOR:
			return ccValueVectorToQScriptValue(engine, value.asValueVector());

		case Value::Type::MAP:
			return ccValueMapToQScriptValue(engine, value.asValueMap());

		case Value::Type::INT_KEY_MAP:
			return ccValueMapIntKeyToQScriptValue(engine, value.asIntKeyMap());
	}

	return engine->nullValue();
}

QScriptValue QtCocosScriptUtils::ccValueVectorToQScriptValue(
	QScriptEngine *engine, const ValueVector &vec)
{
	auto result = engine->newArray(vec.size());

	quint32 i = 0;
	for (auto it = vec.begin(); it != vec.end(); ++it, ++i)
	{
		result.setProperty(i, ccValueToQScriptValue(engine, *it));
	}

	return result;
}

QScriptValue QtCocosScriptUtils::ccValueMapToQScriptValue(
	QScriptEngine *engine, const ValueMap &map)
{
	auto result = engine->newObject();

	for (auto &it : map)
	{
		result.setProperty(QString::fromStdString(it.first),
			ccValueToQScriptValue(engine, it.second));
	}

	return result;
}

QScriptValue QtCocosScriptUtils::ccValueMapIntKeyToQScriptValue(
	QScriptEngine *engine, const ValueMapIntKey &map)
{
	auto result = engine->newArray();

	for (auto &it : map)
	{
		result.setProperty(it.first, ccValueToQScriptValue(engine, it.second));
	}

	return result;
}

void QtCocosScriptUtils::qScriptValueToCcValue(
	const QScriptValue &scriptValue, Value &out)
{
	if (!scriptValue.isValid() || scriptValue.isUndefined() ||
		scriptValue.isNull())
	{
		out = Value();
	} else if (scriptValue.isBool())
	{
		out = scriptValue.toBool();
	} else if (scriptValue.isNumber())
	{
		out = scriptValue.toNumber();
	} else if (scriptValue.isArray())
	{
		out = ValueVector();
		qScriptValueToCcValueVector(scriptValue, out.asValueVector());
	} else if (scriptValue.isVariant())
	{
		auto v = scriptValue.toVariant();
		switch (v.type())
		{
			case QVariant::Invalid:
			case QVariant::Bool:
			case QVariant::Int:
			case QVariant::UInt:
			case QVariant::LongLong:
			case QVariant::ULongLong:
			case QVariant::Double:
			case QVariant::Map:
			case QVariant::Hash:
			case QVariant::List:
			case QVariant::StringList:
			case QVariant::ByteArray:
			case QVariant::String:
				out = qVariantToCcValue(v);
				return;

			default:
				break;
		}
	} else if (scriptValue.isObject() && !scriptValue.isQObject() &&
		!scriptValue.isFunction() && !scriptValue.isQMetaObject())
	{
		out = ValueMap();
		qScriptValueToCcValueMap(scriptValue, out.asValueMap());
		return;
	}

	auto ba = qscriptvalue_cast<QByteArray *>(scriptValue);
	if (ba)
	{
		out = ba->toStdString();
	} else
	{
		out = scriptValue.toString().toStdString();
	}
}

void QtCocosScriptUtils::qScriptValueToCcValueVector(
	const QScriptValue &scriptValue, ValueVector &out)
{
	out.clear();
	if (scriptValue.isArray())
	{
		quint32 length =
			QtCocosScriptEngine::instance()
				->propertyById(QtCocosScriptEngine::LENGTH, scriptValue)
				.toUInt32();
		out.reserve(length);
		for (quint32 i = 0; i < length; i++)
		{
			Value value;
			qScriptValueToCcValue(scriptValue.property(i), value);
			out.emplace_back(std::move(value));
		}
	} else if (scriptValue.isVariant())
	{
		auto v = scriptValue.toVariant();
		switch (v.type())
		{
			case QVariant::StringList:
				out = qStringListToCcValueVector(v.toStringList());
				break;

			case QVariant::List:
				out = qVariantListToCcValueVector(v.toList());
				break;

			default:
				break;
		}
	}
}

void QtCocosScriptUtils::qScriptValueToCcValueMap(
	const QScriptValue &scriptValue, ValueMap &out)
{
	out.clear();
	if (scriptValue.isVariant())
	{
		auto v = scriptValue.toVariant();
		switch (v.type())
		{
			case QVariant::Map:
				out = qVariantMapToCcValueMap(v.toMap());
				break;

			case QVariant::Hash:
				out = qVariantHashToCcValueMap(v.toHash());
				break;

			default:
				break;
		}
	} else if (scriptValue.isObject() && !scriptValue.isQObject() &&
		!scriptValue.isFunction() && !scriptValue.isQMetaObject())
	{
		QScriptValueIterator it(scriptValue);
		while (it.hasNext())
		{
			it.next();
			if (it.flags() & QScriptValue::SkipInEnumeration)
			{
				continue;
			}

			qScriptValueToCcValue(it.value(), out[it.name().toStdString()]);
		}
	}
}

Value QtCocosScriptUtils::qVariantToCcValue(const QVariant &v)
{
	Value result;
	switch (v.type())
	{
		case QVariant::Invalid:
			break;

		case QVariant::Bool:
			result = v.toBool();
			break;

		case QVariant::Int:
			result = v.toInt();
			break;

		case QVariant::UInt:
			result = v.toUInt();
			break;

		case QVariant::LongLong:
		{
			qint64 x = v.toLongLong();
			if (x >= std::numeric_limits<int>::min() &&
				x <= std::numeric_limits<int>::max())
			{
				result = int(x);
			} else
			{
				result = double(x);
			}
			break;
		}

		case QVariant::ULongLong:
		{
			quint64 x = v.toULongLong();
			if (x <= std::numeric_limits<unsigned int>::max())
			{
				result = static_cast<unsigned int>(x);
			} else
			{
				result = double(x);
			}
			break;
		}

		case QVariant::Double:
			result = v.toDouble();
			break;

		case QVariant::Map:
			result = qVariantMapToCcValueMap(v.toMap());
			break;

		case QVariant::Hash:
			result = qVariantHashToCcValueMap(v.toHash());
			break;

		case QVariant::List:
			result = qVariantListToCcValueVector(v.toList());
			break;

		case QVariant::StringList:
			result = qStringListToCcValueVector(v.toStringList());
			break;

		case QVariant::ByteArray:
			result = v.toByteArray().toStdString();
			break;

		default:
			result = v.toString().toStdString();
			break;
	}
	return result;
}

ValueMap QtCocosScriptUtils::qVariantMapToCcValueMap(const QVariantMap &vmap)
{
	ValueMap result;
	for (auto it = vmap.cbegin(); it != vmap.cend(); ++it)
	{
		result[it.key().toStdString()] = qVariantToCcValue(it.value());
	}

	return result;
}

ValueMap QtCocosScriptUtils::qVariantHashToCcValueMap(const QVariantHash &vhash)
{
	ValueMap result;
	for (auto it = vhash.cbegin(); it != vhash.cend(); ++it)
	{
		result[it.key().toStdString()] = qVariantToCcValue(it.value());
	}

	return result;
}

ValueVector QtCocosScriptUtils::qVariantListToCcValueVector(
	const QVariantList &vlist)
{
	ValueVector result;
	result.reserve(size_t(vlist.size()));

	for (auto &v : vlist)
	{
		result.emplace_back(qVariantToCcValue(v));
	}

	return result;
}

ValueVector QtCocosScriptUtils::qStringListToCcValueVector(
	const QStringList &list)
{
	ValueVector result;
	result.reserve(size_t(list.size()));

	for (auto &s : list)
	{
		result.emplace_back(s.toStdString());
	}

	return result;
}
}
