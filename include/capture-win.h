
#ifndef CAPTURE_WIN_H
#define CAPTURE_WIN_H

#include <QWidget>

class QImage;
class QLabel;
class QTimer;

class CaptureWin : public QWidget
{
	Q_OBJECT

public:
	CaptureWin();
	virtual ~CaptureWin() {}

	void setImage(const QImage &image, bool init = false);
	void stop();

protected:
	virtual void closeEvent(QCloseEvent *event);

private slots:
	void update();

signals:
	void close();

private:
	QLabel *m_label;
	QLabel *m_msg;
	unsigned m_frame;
	unsigned m_lastFrame;
	unsigned m_fps;
	QTimer *m_timer;
};

#endif
