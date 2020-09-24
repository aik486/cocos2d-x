#pragma once

#include <functional>

class QScriptValue;
namespace cocos2d
{
class QtCocosScriptUtils
{
public:
	using TextureBackendGetBytesCallback =
		std::function<void(const unsigned char *, size_t, size_t)>;

	static TextureBackendGetBytesCallback getTextureBackendGetBytesCallback(
		const QScriptValue &callback);
};
}
