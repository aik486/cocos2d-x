#include "QtCocosScriptUtils.hpp"

namespace cocos2d
{
QtCocosScriptUtils::PixelsCallback QtCocosScriptUtils::getPixelsCallback(
	QScriptValue callback)
{
	if (!callback.isFunction())
	{
		return nullptr;
	}

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
}
