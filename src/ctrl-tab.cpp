
#include "qv4l2.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QLineEdit>
#include <QValidator>
#include <QLayout>
#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QToolTip>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

void ApplicationWindow::addWidget(QGridLayout *grid, QWidget *w, Qt::Alignment align)
{
qDebug("in AddWidget");

	grid->addWidget(w, m_row, m_col, align | Qt::AlignVCenter);
	m_col++;
	if (m_col == m_cols) {
		m_col = 0;
		m_row++;
	}
}

void ApplicationWindow::addTabs()
{
	v4l2_queryctrl qctrl;
	unsigned ctrl_class;
	unsigned i;
	int id;


//qDebug("in AddTabs fun");

	memset(&qctrl, 0, sizeof(qctrl));
	qctrl.id = V4L2_CTRL_FLAG_NEXT_CTRL;
	while (queryctrl(qctrl)) {
		if ((qctrl.flags & V4L2_CTRL_FLAG_DISABLED) == 0) {
			m_ctrlMap[qctrl.id] = qctrl;
			if (qctrl.type != V4L2_CTRL_TYPE_CTRL_CLASS)
				m_classMap[V4L2_CTRL_ID2CLASS(qctrl.id)].push_back(qctrl.id);
		}
		qctrl.id |= V4L2_CTRL_FLAG_NEXT_CTRL;
	}
	if (qctrl.id == V4L2_CTRL_FLAG_NEXT_CTRL) {
		strcpy((char *)qctrl.name, "User Controls");
		qctrl.id = V4L2_CTRL_CLASS_USER | 1;
		qctrl.type = V4L2_CTRL_TYPE_CTRL_CLASS;
		m_ctrlMap[qctrl.id] = qctrl;
		for (id = V4L2_CID_USER_BASE; id < V4L2_CID_LASTP1; id++) {
			qctrl.id = id;
			if (!queryctrl(qctrl))
				continue;
			if (qctrl.flags & V4L2_CTRL_FLAG_DISABLED)
				continue;
			m_ctrlMap[qctrl.id] = qctrl;
			m_classMap[V4L2_CTRL_CLASS_USER].push_back(qctrl.id);
		}
		for (qctrl.id = V4L2_CID_PRIVATE_BASE;
				queryctrl(qctrl); qctrl.id++) {
			if (qctrl.flags & V4L2_CTRL_FLAG_DISABLED)
				continue;
			m_ctrlMap[qctrl.id] = qctrl;
			m_classMap[V4L2_CTRL_CLASS_USER].push_back(qctrl.id);
		}
	}

	for (ClassMap::iterator iter = m_classMap.begin(); iter != m_classMap.end(); ++iter) {
		ctrl_class = V4L2_CTRL_ID2CLASS(iter->second[0]);
		id = ctrl_class | 1;
		m_col = m_row = 0;
		m_cols = 4;

		const v4l2_queryctrl &qctrl = m_ctrlMap[id];
		QWidget *t = new QWidget(m_tabs);
		QVBoxLayout *vbox = new QVBoxLayout(t);
		QWidget *w = new QWidget(t);

		vbox->addWidget(w);

		QGridLayout *grid = new QGridLayout(w);

		grid->setSpacing(3);
		m_tabs->addTab(t, (char *)qctrl.name);
		for (i = 0; i < iter->second.size(); i++) {
			if (i & 1)
				id = iter->second[(1+iter->second.size()) / 2 + i / 2];
			else
				id = iter->second[i / 2];
			addCtrl(grid, m_ctrlMap[id]);
		}
		grid->addWidget(new QWidget(w), grid->rowCount(), 0, 1, m_cols);
		grid->setRowStretch(grid->rowCount() - 1, 1);
		w = new QWidget(t);
		vbox->addWidget(w);
		grid = new QGridLayout(w);
		finishGrid(grid, ctrl_class);
	}

}

void ApplicationWindow::finishGrid(QGridLayout *grid, unsigned ctrl_class)
{
}

void ApplicationWindow::addCtrl(QGridLayout *grid, const v4l2_queryctrl &qctrl)
{
}

void ApplicationWindow::ctrlAction(int id)
{
}

long long ApplicationWindow::getVal64(unsigned id)
{
}

int ApplicationWindow::getVal(unsigned id)
{
}

void ApplicationWindow::updateCtrl(unsigned id)
{
}

void ApplicationWindow::refresh(unsigned ctrl_class)
{
}

void ApplicationWindow::setWhat(QWidget *w, unsigned id, long long v)
{
}

void ApplicationWindow::setVal(unsigned id, int v)
{
}

void ApplicationWindow::setVal64(unsigned id, long long v)
{
}

void ApplicationWindow::setDefaults(unsigned ctrl_class)
{
}

QString ApplicationWindow::getCtrlFlags(unsigned flags)
{
}

