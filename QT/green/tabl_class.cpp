#include <QTabWidget>
#include <QDialog>
#include "g_class.h"
#include "tabl_class.h"



mytab::mytab(QWidget *parent):QDialog(parent)
{
	tab = new QTabWidget;
	grh1 = new greenhouse;
	grh2 = new greenhouse;
	QHBoxLayout * box = new QHBoxLayout;

	tab->addTab(grh1,trUtf8("实时数据"));
	tab->addTab(grh2,trUtf8("远程控制"));

	box->addWidget(tab);

	setLayout(box);
}
