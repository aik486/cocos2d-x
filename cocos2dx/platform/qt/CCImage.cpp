#include "platform/CCImage.h"

#include "platform/CCFileUtils.h"

#include <QImage>
#include <QFont>
#include <QPainter>

namespace cocos2d
{
CCImage::CCImage()
	: m_nWidth(0)
	, m_nHeight(0)
	, m_nBitsPerComponent(0)
	, m_pData(nullptr)
	, m_bHasAlpha(false)
	, m_bPreMulti(false)
	, m_pImage(nullptr)
{
}

CCImage::~CCImage()
{
	delete m_pImage;
}

bool CCImage::initWithImageFile(const char *strPath, EImageFormat imageType)
{
	std::string fullPath =
		CCFileUtils::sharedFileUtils()->fullPathForFilename(strPath);

	return initWithImageFileThreadSafe(fullPath.c_str(), imageType);
}

bool CCImage::initWithImageFileThreadSafe(
	const char *fullPath, EImageFormat imageType)
{
	bool bRet = false;
	unsigned long nSize = 0;
	unsigned char *pBuffer =
		CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &nSize);
	if (pBuffer != NULL && nSize > 0)
	{
		bRet = initWithImageData(pBuffer, int(nSize), imageType);
	}
	CC_SAFE_DELETE_ARRAY(pBuffer);
	return bRet;
}

bool CCImage::initWithImageData(void *pData, int nDataLen, EImageFormat eFmt,
	int nWidth, int nHeight, int nBitsPerComponent)
{
	const char *format = nullptr;
	switch (eFmt)
	{
		case kFmtJpg:
			format = "jpg";
			break;

		case kFmtPng:
			format = "png";
			break;

		case kFmtTiff:
			format = "tiff";
			break;

		case kFmtWebp:
			format = "webp";
			break;

		case kFmtRawData:
			return _initWithRawData(
				pData, nDataLen, nWidth, nHeight, nBitsPerComponent, false);

		case kFmtUnKnown:
			break;
	}

	auto qimage = QImage::fromData((const uchar *) pData, nDataLen, format);
	if (qimage.isNull())
		return false;

	m_bHasAlpha = qimage.hasAlphaChannel();
	m_bPreMulti = m_bHasAlpha &&
		qimage.pixelFormat().premultiplied() == QPixelFormat::Premultiplied;

	if (m_bPreMulti)
	{
		qimage = qimage.convertToFormat(QImage::Format_RGBA8888_Premultiplied);
	} else if (m_bHasAlpha)
	{
		qimage = qimage.convertToFormat(QImage::Format_RGBA8888);
	} else
	{
		qimage = qimage.convertToFormat(QImage::Format_RGB888);
	}

	if (nullptr == m_pImage)
	{
		m_pImage = new QImage;
	}

	*m_pImage = qimage;
	m_pData = m_pImage->bits();
	m_nWidth = quint16(qimage.width());
	m_nHeight = quint16(qimage.height());
	m_nBitsPerComponent = 8;

	return true;
}

bool CCImage::initWithString(const char *pText, int nWidth, int nHeight,
	ETextAlign eAlignMask, const char *pFontName, int nSize)
{
	if (nullptr == m_pImage)
	{
		m_pImage = new QImage;
	}
	*m_pImage = QImage(nWidth, nHeight, QImage::Format_RGBA8888);
	m_pImage->fill(Qt::transparent);

	{
		QPainter painter(m_pImage);

		QFont font(QString::fromUtf8(pFontName));
		font.setPixelSize(nSize);

		painter.setFont(font);
		painter.setPen(Qt::transparent);
		painter.setBrush(Qt::white);

		auto text = QString::fromUtf8(pText);

		int flags = Qt::TextWordWrap;
		switch (eAlignMask)
		{
			case kAlignCenter:
				flags |= Qt::AlignCenter;
				break;

			case kAlignTop:
				flags |= Qt::AlignTop;
				break;

			case kAlignTopRight:
				flags |= Qt::AlignTop | Qt::AlignRight;
				break;

			case kAlignRight:
				flags |= Qt::AlignRight;
				break;

			case kAlignBottomRight:
				flags |= Qt::AlignBottom | Qt::AlignRight;
				break;

			case kAlignBottom:
				flags |= Qt::AlignBottom;
				break;

			case kAlignBottomLeft:
				flags |= Qt::AlignBottom | Qt::AlignLeft;
				break;

			case kAlignLeft:
				flags |= Qt::AlignLeft;
				break;

			case kAlignTopLeft:
				flags |= Qt::AlignTop | Qt::AlignLeft;
				break;
		}

		painter.drawText(QRect(0, 0, nWidth, nHeight), flags, text);
	}

	m_pData = m_pImage->bits();
	m_bHasAlpha = true;
	m_bPreMulti = false;
	m_nWidth = quint16(m_pImage->width());
	m_nHeight = quint16(m_pImage->height());
	m_nBitsPerComponent = 8;

	return true;
}

bool CCImage::saveToFile(const char *pszFilePath, bool bIsToRGB)
{
	if (nullptr == m_pImage)
		return false;

	QImage image = *m_pImage;

	if (bIsToRGB)
		image = image.convertToFormat(QImage::Format_RGB888);

	return image.save(QString::fromUtf8(pszFilePath));
}

bool CCImage::_initWithJpgData(void *pData, int nDataLen)
{
	return initWithImageData(pData, nDataLen, kFmtJpg);
}

bool CCImage::_initWithPngData(void *pData, int nDataLen)
{
	return initWithImageData(pData, nDataLen, kFmtPng);
}

bool CCImage::_initWithTiffData(void *pData, int nDataLen)
{
	return initWithImageData(pData, nDataLen, kFmtTiff);
}

bool CCImage::_initWithWebpData(void *pData, int nDataLen)
{
	return initWithImageData(pData, nDataLen, kFmtWebp);
}

bool CCImage::_initWithRawData(void *pData, int nDatalen, int nWidth,
	int nHeight, int nBitsPerComponent, bool bPreMulti)
{
	QImage::Format sourceImageFormat;
	QImage::Format storeImageFormat = bPreMulti
		? QImage::Format_RGBA8888_Premultiplied
		: QImage::Format_RGB888;

	Q_ASSERT(nWidth <= 65535);
	Q_ASSERT(nHeight <= 65535);

	int length = nWidth * nHeight;
	Q_ASSERT(length > 0);

	int bytesPerPixel = nDatalen / length;

	switch (bytesPerPixel)
	{
		case 2:
			Q_ASSERT(nBitsPerComponent == (bPreMulti ? 4 : 5));
			sourceImageFormat = bPreMulti
				? QImage::Format_ARGB4444_Premultiplied
				: QImage::Format_RGB555;
			break;

		case 3:
			Q_ASSERT(nBitsPerComponent == (bPreMulti ? 5 : 8));
			sourceImageFormat = bPreMulti
				? QImage::Format_ARGB8555_Premultiplied
				: QImage::Format_RGB888;
			break;

		case 4:
			Q_ASSERT(nBitsPerComponent == 8);
			sourceImageFormat = bPreMulti
				? QImage::Format_RGBA8888_Premultiplied
				: QImage::Format_RGBA8888;
			storeImageFormat = sourceImageFormat;
			break;

		default:
			Q_UNREACHABLE();
			return false;
	}

	if (nullptr == m_pImage)
	{
		m_pImage = new QImage;
	}

	*m_pImage = QImage(nWidth, nHeight, sourceImageFormat);

	int bytesPerLine = nWidth * (m_pImage->depth() / 8);

	auto source = reinterpret_cast<const quint8 *>(pData);

	for (int y = 0; y < nHeight; y++)
	{
		memcpy(m_pImage->scanLine(y), source, bytesPerLine);
		source += bytesPerLine;
	}

	if (sourceImageFormat != storeImageFormat)
		*m_pImage = m_pImage->convertToFormat(storeImageFormat);

	auto pixelFormat = m_pImage->pixelFormat();
	m_bHasAlpha = pixelFormat.alphaUsage() == QPixelFormat::UsesAlpha;
	m_bPreMulti = pixelFormat.premultiplied() == QPixelFormat::Premultiplied;

	m_pData = m_pImage->bits();
	m_nBitsPerComponent = 8;
	m_nWidth = quint16(nWidth);
	m_nHeight = quint16(nHeight);

	return true;
}

bool CCImage::_saveImageToPNG(const char *pszFilePath, bool bIsToRGB)
{
	if (nullptr == m_pImage)
		return false;

	QImage image = *m_pImage;

	if (bIsToRGB)
		image = image.convertToFormat(QImage::Format_RGB888);

	return image.save(QString::fromUtf8(pszFilePath), "png");
}

bool CCImage::_saveImageToJPG(const char *pszFilePath)
{
	if (nullptr == m_pImage)
		return false;

	return m_pImage->save(QString::fromUtf8(pszFilePath), "jpg");
}
}
