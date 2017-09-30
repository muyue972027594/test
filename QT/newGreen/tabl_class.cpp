#include "tabl_class.h"



mytab::mytab(QWidget *parent):QDialog(parent)
{
	tab = new QTabWidget;
	grh1 = new nowdata;
	QHBoxLayout * box = new QHBoxLayout;

	connect(this,SIGNAL(showdata()),grh1,SLOT(mychange()));

	tab->addTab(grh1,trUtf8("实时数据"));

	box->addWidget(tab);

	setLayout(box);
}
void mytab::emitshow()
{
	emit showdata();
}

