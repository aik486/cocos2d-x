#pragma once

#include "base/CCVector.h"

#include <QScriptValue>
#include <QScriptEngine>
#include <functional>

namespace cocos2d
{
class Sprite3D;
class QtCocosScriptUtils
{
public:
	using PixelsCallback = // data, width, height
		std::function<void(const unsigned char *, size_t, size_t)>;

	using Sprite3DCallback = std::function<void(Sprite3D *, void *)>;

	static PixelsCallback getPixelsCallback(QScriptValue callback);

	static Sprite3DCallback getSprite3DCallback(QScriptValue callback);

	template <typename ELEMENT_T>
	static void registerVector(QScriptEngine *engine)
	{
		qScriptRegisterMetaType<Vector<ELEMENT_T>>(
			engine, vecToScriptValue<ELEMENT_T>, vecFromScriptValue<ELEMENT_T>);
	}

private:
	template <typename ELEMENT_T>
	static QScriptValue vecToScriptValue(
		QScriptEngine *eng, const Vector<ELEMENT_T> &cont)
	{
		QScriptValue a = eng->newArray();
		auto begin = cont.begin();
		auto end = cont.end();
		auto it = begin;
		quint32 i;
		for (i = 0; it != end; ++it, ++i)
		{
			a.setProperty(i, eng->toScriptValue(*it));
		}
		return a;
	}

	template <typename ELEMENT_T>
	static void vecFromScriptValue(
		const QScriptValue &value, Vector<ELEMENT_T> &cont)
	{
		quint32 len = value.property(QLatin1String("length")).toUInt32();
		cont.reserve(len);
		for (quint32 i = 0; i < len; ++i)
		{
			QScriptValue item = value.property(i);
			auto element = qscriptvalue_cast<ELEMENT_T>(item);
			cont.pushBack(element);
		}
	}
};
}
