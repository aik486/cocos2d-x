#include "QtCocosScriptUtils.hpp"

#include <QScriptValue>
#include <QScriptEngine>

namespace cocos2d
{
QtCocosScriptUtils::TextureBackendGetBytesCallback
QtCocosScriptUtils::getTextureBackendGetBytesCallback(QScriptValue callback)
{
	return [=](const unsigned char *data, size_t width, size_t height) mutable {
		QScriptValueList arguments;
		auto engine = callback.engine();
		arguments << engine->toScriptValue(QByteArray::fromRawData(
			reinterpret_cast<const char *>(data), width * 4 * height));
		arguments << engine->toScriptValue(width);
		arguments << engine->toScriptValue(height);
		callback.call(QScriptValue(), arguments);
	};
}

QtCocosScriptUtils::Sprite3DCallback QtCocosScriptUtils::getSprite3DCallback(
	QScriptValue callback)
{
	return [=](Sprite3D *sprite, void *) mutable {
		QScriptValueList arguments;
		auto engine = callback.engine();
		arguments << engine->toScriptValue(sprite);
		callback.call(QScriptValue(), arguments);
	};
}
}
