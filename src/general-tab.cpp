
#include "general-tab.h"
#include <libv4l2util.h>

#include <QSpinBox>
#include <QComboBox>

#include <errno.h>

GeneralTab::GeneralTab(const QString &device, v4l2 &fd, int n, QWidget *parent) :
	QGridLayout(parent),
	v4l2(fd),
	m_row(0),
	m_col(0),
	m_cols(n),
	m_frameSize(NULL)
{
        frameSizeChanged(1);


}
CapMethod GeneralTab::capMethod()
{
	//qDebug("in General::capMethod");
       // return (CapMethod)m_capMethods->itemData(m_capMethods->currentIndex()).toInt();
       return (CapMethod)1;
}
void GeneralTab::frameSizeChanged(int idx)
{
	v4l2_frmsizeenum frmsize;
        frmsize.discrete.width=320;
        frmsize.discrete.height=240;
	//if (enum_framesizes(frmsize, m_pixelformat, idx)) {
		//m_width = frmsize.discrete.width;
		//m_height = frmsize.discrete.height;
		m_width = 320;
		m_height = 240;

		v4l2_format fmt;
                
		g_fmt_cap(fmt);
                 m_pixelformat = fmt.fmt.pix.pixelformat;
		//fmt.fmt.pix.width = m_width;
		//fmt.fmt.pix.height = m_height;
		fmt.fmt.pix.width = 320;
		fmt.fmt.pix.height = 240;
		try_fmt(fmt);
		s_fmt(fmt);
	//}
        //qDebug("frame width=%d",m_width);
        //qDebug("frame height=%d", m_height);
}

void GeneralTab::updateFrameSize(unsigned w, unsigned h)
{
	v4l2_frmsizeenum frmsize;
	bool ok = false;

//	m_frameSize->clear();

//qDebug("in update fram size");


//         qDebug("hi");
	ok = enum_framesizes(frmsize, m_pixelformat);
	if (ok && frmsize.type == V4L2_FRMSIZE_TYPE_DISCRETE) {
		do {
			//m_frameSize->addItem(QString("%1x%2").arg(frmsize.discrete.width).arg(frmsize.discrete.height));
			m_frameSize->addItem(QString("%1x%2").arg(320).arg(240));
			if (frmsize.discrete.width == w && frmsize.discrete.height == h)
				m_frameSize->setCurrentIndex(frmsize.index);
		} while (enum_framesizes(frmsize));

		m_frameSize->setEnabled(true);
		return;
	}
	if (!ok) {
                  qDebug("hi");
		frmsize.stepwise.min_width = 8;
		frmsize.stepwise.max_width = 1920;
		frmsize.stepwise.step_width = 1;
		frmsize.stepwise.min_height = 4;
		frmsize.stepwise.max_height = 1200;
                frmsize.stepwise.step_height = 8;
                }
}

                
