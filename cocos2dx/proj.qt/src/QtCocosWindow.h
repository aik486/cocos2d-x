#pragma once

#ifndef CC_USE_QT_OPENGL
#include "CCGL.h"
#endif

#include <QOpenGLWindow>

#include <functional>

#include "cocos_warnings_off.h"
#include "CCApplication.h"
#include "ccTypes.h"
#include "cocos_warnings_pop.h"

#include "QtCocosEGLView.h"

namespace cocos2d
{
class CCScene;
}

class QtCocosWindow
	: public QOpenGLWindow
	, public cocos2d::CCApplication
{
	Q_OBJECT

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)

public:
	QtCocosWindow();
	virtual ~QtCocosWindow() override;

	static QWidget *createWidget(QWidget *parent);
	inline QWidget *masterWidget() const;

	QWidget *makeContainerWidget(QWidget *parent);

	bool isAnimating() const;
	void animate(bool yes);

	inline int scale() const;
	void setScale(int value);

	inline cocos2d::CCNode *mainNode() const;
	cocos2d::CCScene *scene() const;
	inline bool hasFocus() const;

	static QtCocosWindow *instance();

	inline bool isInitialized() const;

	QColor backgroundColor() const;
	void setBackgroundColor(const QColor &color);

	inline bool isEnabled() const;
	inline void setEnabled(bool enabled);

public:
	virtual bool applicationDidFinishLaunching() override;
	virtual void applicationDidEnterBackground() override;
	virtual void applicationWillEnterForeground() override;
	virtual void setAnimationInterval(double) override;

protected:
	virtual bool event(QEvent *e) override;
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
	virtual void focusInEvent(QFocusEvent *event) override;
	virtual void focusOutEvent(QFocusEvent *event) override;
	virtual void mousePressEvent(QMouseEvent *event) override;
	virtual void mouseReleaseEvent(QMouseEvent *event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
	virtual void mouseMoveEvent(QMouseEvent *event) override;
	virtual void wheelEvent(QWheelEvent *event) override;
	virtual void showEvent(QShowEvent *) override;
	virtual void exposeEvent(QExposeEvent *event) override;
	virtual void keyPressEvent(QKeyEvent *event) override;
	virtual void keyReleaseEvent(QKeyEvent *event) override;

signals:
	void Initialized();
	void VisibleFrameAdjusted();
	void ScaleChanged();
	void KeyDown(QKeyEvent *event);
	void KeyUp(QKeyEvent *event);
	void MousePressed(QMouseEvent *event);
	void MouseMoved(QMouseEvent *event);
	void MouseReleased(QMouseEvent *event);
	void FocusIn();
	void FocusOut();
	void MouseEnter();
	void MouseLeave();

private:
	class Scene;
	class InternalMainNode;
	friend class Scene;
	friend class InternalMainNode;

	bool ignoredMouseEvent(QMouseEvent *event);
	void updateAnimationState(bool force);
	static bool isContextMenuEvent(QMouseEvent *event);

	enum
	{
		ANIMATING = 1 << 0,
		EXPOSED = 1 << 1,
		BEGIN_NO_TOUCH = 1 << 2
	};

	QtCocosEGLView *mEGLView;
	cocos2d::CCNode *mMainNode;
	cocos2d::CCScene *mScene;
	int mScale;
	quint32 mMouseButtons;
	quint32 mState;
	cocos2d::ccColor4F mBgColor;
	QWidget *mMasterWidget;
	bool mHasFocus;
	bool mEnabled;
	bool mRunning;
	bool mInitialized;
};

QWidget *QtCocosWindow::masterWidget() const
{
	return mMasterWidget;
}

int QtCocosWindow::scale() const
{
	return mScale;
}

cocos2d::CCNode *QtCocosWindow::mainNode() const
{
	return mMainNode;
}

bool QtCocosWindow::hasFocus() const
{
	return mHasFocus;
}

bool QtCocosWindow::isInitialized() const
{
	return mInitialized;
}

bool QtCocosWindow::isEnabled() const
{
	return mEnabled;
}

void QtCocosWindow::setEnabled(bool enabled)
{
	mEnabled = enabled;
}
