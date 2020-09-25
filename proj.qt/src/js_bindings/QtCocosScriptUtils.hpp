#pragma once

#include <functional>

class QScriptValue;
namespace cocos2d
{
class Sprite3D;
class QtCocosScriptUtils
{
public:
	using TextureBackendGetBytesCallback =
		std::function<void(const unsigned char *, size_t, size_t)>;
	using Sprite3DCallback = std::function<void(Sprite3D *, void *)>;

	static TextureBackendGetBytesCallback getTextureBackendGetBytesCallback(
		QScriptValue callback);

	static Sprite3DCallback getSprite3DCallback(QScriptValue callback);
};
}
