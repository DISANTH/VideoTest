
#ifndef GENERAL_TAB_H
#define GENERAL_TAB_H

#include <QSpinBox>
#include <sys/time.h>
#include <linux/videodev2.h>
#include "qv4l2.h"
#include "v4l2-api.h"

class QComboBox;
class QSpinBox;

class GeneralTab: public QGridLayout, public v4l2
{
	Q_OBJECT

public:
	GeneralTab(const QString &device, v4l2 &fd, int n, QWidget *parent = 0);
	virtual ~GeneralTab() {}

	CapMethod capMethod();
	int width() const { return m_width; }
	int height() const { return m_height; }

private slots:
	//void frameSizeChanged(int);

private:
	void updateFrameSize(unsigned w, unsigned h);
	void frameSizeChanged(int);

//	void addWidget(QWidget *w, Qt::Alignment align = Qt::AlignLeft);
	void addLabel(const QString &text, Qt::Alignment align = Qt::AlignRight)
	{
//		addWidget(new QLabel(text, parentWidget()), align);
	}
	void info(const QString &info)
	{
		g_mw->info(info);
	}
	virtual void error(const QString &error)
	{
		g_mw->error(error);
	}

	int m_row;
	int m_col;
	int m_cols;
	struct v4l2_tuner m_tuner;
	struct v4l2_capability m_querycap;
	__u32 m_pixelformat;
	__u32 m_width, m_height;

	// General tab
	QComboBox *m_frameSize;
	QGridLayout *m_layout;
        QComboBox *m_frameInterval;
};

#endif
