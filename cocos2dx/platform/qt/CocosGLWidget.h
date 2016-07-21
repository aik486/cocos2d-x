#pragma once

#include <QOpenGLWidget>
#include <QMutex>
#include <QTimer>

#include <functional>

#include "cocos_warnings_off.h"
#include "CCApplication.h"
#include "CCEGLView.h"
#include "cocos_warnings_pop.h"

namespace cocos2d
{
	class CCScene;
	class CCNode;
	class CCRenderTexture;
}

class CocosGLWidget : public QOpenGLWidget, public cocos2d::CCApplication
{
	Q_OBJECT

public:
	explicit CocosGLWidget(QWidget *parent = 0);
	virtual ~CocosGLWidget();

	void useRenderBuffer(bool use);

	cocos2d::CCNode *MainNode() const { return mMainNode; }

	enum
	{
		DOUBLE_CLICK_LEFT = cocos2d::CCEGLViewQt::DOUBLE_CLICK_FLAG | (int) Qt::LeftButton,
		DOUBLE_CLICK_RIGHT = cocos2d::CCEGLViewQt::DOUBLE_CLICK_FLAG | (int) Qt::RightButton,
		DOUBLE_CLICK_MIDDLE = cocos2d::CCEGLViewQt::DOUBLE_CLICK_FLAG | (int) Qt::MiddleButton
	};

protected:
	virtual void initializeGL() override;
	virtual void paintGL() override;
	virtual void resizeGL(int width, int height) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void wheelEvent(QWheelEvent *event) override;
	virtual void enterEvent(QEvent *) override;
	virtual void leaveEvent(QEvent *) override;
	virtual void keyPressEvent(QKeyEvent *event) override;
	virtual void keyReleaseEvent(QKeyEvent *event) override;

signals:
	void Initialized();
	void VisibleFrameAdjusted();
	void MouseEntered();
	void MouseLeft();
	void KeyDown(QKeyEvent *event);
	void KeyUp(QKeyEvent *event);

public slots:
	void Synchronize(const std::function<void ()> &safeCode);

public:
	virtual bool applicationDidFinishLaunching() override;
	virtual void applicationDidEnterBackground() override;
	virtual void applicationWillEnterForeground() override;
	virtual void setAnimationInterval(double) override;

private slots:
	void BeforeResize();

private:
	void updateRenderBuffer(int width, int height);

	cocos2d::CCEGLViewQt *mEGLView;
	QMutex mMutex;
	QTimer *mTimer;

	cocos2d::CCRenderTexture *mRootNode;
	cocos2d::CCNode *mMainNode;
	cocos2d::CCScene *mScene;

	uint32_t mMouseButtons;
	bool mBeginNoTouch:1;
	bool mUseRenderBuffer:1;
};
