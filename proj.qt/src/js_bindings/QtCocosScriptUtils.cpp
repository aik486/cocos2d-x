#include "QtCocosScriptUtils.hpp"

#include <QScriptValue>
#include <QScriptEngine>

namespace cocos2d
{
QtCocosScriptUtils::TextureBackendGetBytesCallback
QtCocosScriptUtils::getTextureBackendGetBytesCallback(
	const QScriptValue &callback)
{
	auto cb = callback;
	return [=](const unsigned char *data, size_t width, size_t height) mutable {
		QScriptValueList arguments;
		auto engine = cb.engine();
		arguments << engine->toScriptValue(QByteArray::fromRawData(
			reinterpret_cast<const char *>(data), width * 4 * height));
		arguments << engine->toScriptValue(width);
		arguments << engine->toScriptValue(height);
		cb.call(QScriptValue(), arguments);
	};
}
}
