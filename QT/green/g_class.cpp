#include <QtGui>
#include "g_class.h"
#include <stdio.h>
#include <mysql/mysql.h>

greenhouse::greenhouse(QWidget *parent) : QDialog(parent)
{
	temlabel = new QLabel(trUtf8("温度"));
	temslider = new QSlider;
	temspinbox = new QSpinBox;
	vlayout = new QVBoxLayout;

	temlabel->setFixedSize(50,30);
	temslider->setFixedSize(50,300);
	temslider->setRange(0,100);
	temspinbox->setFixedSize(50,30);
	temspinbox->setRange(0,100);

	vlayout->addWidget(temlabel);
	vlayout->addWidget(temslider);
	vlayout->addWidget(temspinbox);

	vlayout->setMargin(30);

	connect(this,SIGNAL(change(int)),this,SLOT(mychange(int)));

	setLayout(vlayout);

	mysql_init(&mysql);
	mysql_real_connect(&mysql,"localhost","root","123456","green",0,NULL,0);
}

void greenhouse::emit_change(int x)
{
	emit change(x);
}

void greenhouse::mychange(int x)
{
	char * sql = "select * from data order by id desc";
	mysql_real_query(&mysql,sql,strlen(sql));
	MYSQL_RES *res;
	MYSQL_ROW row;
	res = mysql_store_result(&mysql);
	row = mysql_fetch_row(res);

	temslider->setValue(atoi(row[0]));
	temspinbox->setValue(atoi(row[0]));
}

greenhouse::~greenhouse()
{
	delete temlabel;
	delete temslider;
	delete temspinbox;
	delete vlayout;
	mysql_close(&mysql);
}
