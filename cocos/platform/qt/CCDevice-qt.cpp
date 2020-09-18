/****************************************************************************
Copyright (c) 2020 Alexandra Cherdantseva

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "platform/CCDevice.h"
#include "base/ccTypes.h"

#include <QImage>
#include <QFont>
#include <QPainter>
#include <QStaticText>
#include <QtMath>

NS_CC_BEGIN


void Device::setAccelerometerEnabled(bool)
{

}

void Device::setAccelerometerInterval(float)
{

}

Data Device::getTextureDataForText(const char * text, const FontDefinition& textDefinition, TextAlign align, int &width, int &height, bool& hasPremultipliedAlpha)
{
	Qt::Alignment alignment;
	switch (align)
	{
		case TextAlign::CENTER:
			alignment |= Qt::AlignCenter;
			break;

		case TextAlign::TOP:
			alignment |= Qt::AlignTop;
			break;

		case TextAlign::TOP_RIGHT:
			alignment |= Qt::AlignTop | Qt::AlignRight;
			break;

		case TextAlign::RIGHT:
			alignment |= Qt::AlignRight;
			break;

		case TextAlign::BOTTOM_RIGHT:
			alignment |= Qt::AlignBottom | Qt::AlignRight;
			break;

		case TextAlign::BOTTOM:
			alignment |= Qt::AlignBottom;
			break;

		case TextAlign::BOTTOM_LEFT:
			alignment |= Qt::AlignBottom | Qt::AlignLeft;
			break;

		case TextAlign::LEFT:
			alignment |= Qt::AlignLeft;
			break;

		case TextAlign::TOP_LEFT:
			alignment |= Qt::AlignTop | Qt::AlignLeft;
			break;
	}
	QStaticText staticText;
	staticText.setTextFormat(Qt::PlainText);
	QTextOption textOption;
	textOption.setAlignment(alignment);
	textOption.setWrapMode(width <= 0
			? QTextOption::NoWrap
			: QTextOption::WrapAtWordBoundaryOrAnywhere);
	staticText.setTextOption(textOption);
	staticText.setTextWidth(width <= 0 ? qreal(-1.0) : qreal(width));
	staticText.setText(QString::fromUtf8(text));
	QFont font(QString::fromStdString(textDefinition._fontName));
	font.setPixelSize(textDefinition._fontSize);
	staticText.prepare(QTransform(), font);
	auto size = staticText.size();
	width = width > 0 ? width : qCeil(size.width());
	height = height > 0 ? height : qCeil(size.height());

	QImage image(width, height, QImage::Format_RGBA8888);
	image.fill(Qt::transparent);

	QPainter painter(&image);

	painter.setFont(font);
	painter.setPen(QColor(
	   textDefinition._fontFillColor.r,
	   textDefinition._fontFillColor.g,
	   textDefinition._fontFillColor.b,
	   textDefinition._fontAlpha));
	painter.setBrush(Qt::transparent);

	painter.drawStaticText(0, 0, staticText);

	Data data;
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)	
	data.copy(image.bits(), image.sizeInBytes());
#else
	data.copy(image.bits(), image.byteCount());
#endif
	hasPremultipliedAlpha = false;
	return data;
}

void Device::setKeepScreenOn(bool)
{
}

void Device::vibrate(float)
{
}

NS_CC_END
