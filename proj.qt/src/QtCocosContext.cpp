#include "QtCocosContext.h"

QtCocosContext::MakeCurrent QtCocosContext::sMakeCurrent;
QtCocosContext::SetColor QtCocosContext::sSetBackgroundColor;

bool QtCocosContext::hasSetter()
{
	return !!sMakeCurrent;
}

void QtCocosContext::setContextSetter(const MakeCurrent &setter)
{
	sMakeCurrent = setter;
}

void QtCocosContext::setBackgroundColorSetter(const SetColor &setter)
{
	sSetBackgroundColor = setter;
}

void QtCocosContext::makeCurrent()
{
	if (sMakeCurrent)
		sMakeCurrent();
}

void QtCocosContext::setBackgroundColor(const QColor &color)
{
	if (sSetBackgroundColor)
		sSetBackgroundColor(color);
}
