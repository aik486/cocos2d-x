#pragma once

#include <functional>

class QColor;

class QtCocosContext
{
public:
	using MakeCurrent = std::function<void()>;
	using SetColor = std::function<void(const QColor &)>;

	static bool hasSetter();
	static void setContextSetter(const MakeCurrent &setter);
	static void setBackgroundColorSetter(const SetColor &setter);

	static void makeCurrent();

	static void setBackgroundColor(const QColor &color);

private:
	static MakeCurrent sMakeCurrent;
	static SetColor sSetBackgroundColor;
};
