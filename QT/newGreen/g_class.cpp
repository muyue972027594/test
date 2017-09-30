#include "g_class.h"

nowdata::nowdata(QWidget *parent) : QDialog(parent)
{
	nowdatatitle = new QLabel(trUtf8("实 时 数 据"));
	Airwendulabel = new QLabel(trUtf8("空气温度"));
	Airwenduslider = new QSlider;
	Airwenduspinbox = new QSpinBox;
	Airshidulabel = new QLabel(trUtf8("空气湿度"));
	Airshiduslider = new QSlider;
	Airshiduspinbox = new QSpinBox;
	co2potlabel = new QLabel(trUtf8("CO2浓度"));
	co2potslider = new QSlider;
	co2potspinbox = new QSpinBox;
	Soilwendulabel = new QLabel(trUtf8("土壤温度"));
	Soilwenduslider = new QSlider;
	Soilwenduspinbox = new QSpinBox;
	Soilshidulabel = new QLabel(trUtf8("土壤湿度"));
	Soilshiduslider = new QSlider;
	Soilshiduspinbox = new QSpinBox;
	guanglabel = new QLabel(trUtf8("光照强度"));
	guangslider = new QSlider;
	guangspinbox = new QSpinBox;
	glayout = new QGridLayout;


	glayout->addWidget(nowdatatitle,0,0,1,12);
	glayout->addWidget(Airwendulabel,2,0,2,2);
	glayout->addWidget(Airwenduslider,3,0,10,2);
	glayout->addWidget(Airwenduspinbox,8,0,2,2);
	glayout->addWidget(Airshidulabel,2,2,2,2);
	glayout->addWidget(Airshiduslider,3,2,10,2);
	glayout->addWidget(Airshiduspinbox,8,2,2,2);
	glayout->addWidget(co2potlabel,2,4,2,2);
	glayout->addWidget(co2potslider,3,4,10,2);
	glayout->addWidget(co2potspinbox,8,4,2,2);
	glayout->addWidget(Soilwendulabel,2,6,2,2);
	glayout->addWidget(Soilwenduslider,3,6,10,2);
	glayout->addWidget(Soilwenduspinbox,8,6,2,2);
	glayout->addWidget(Soilshidulabel,2,8,2,2);
	glayout->addWidget(Soilshiduslider,3,8,10,2);
	glayout->addWidget(Soilshiduspinbox,8,8,2,2);
	glayout->addWidget(guanglabel,2,10,2,2);
	glayout->addWidget(guangslider,3,10,10,2);
	glayout->addWidget(guangspinbox,8,10,2,2);

	glayout->setMargin(30);

	connect(this,SIGNAL(change()),this,SLOT(mychange()));

	setLayout(glayout);

	mysql_init(&mysql);
	mysql_real_connect(&mysql,"localhost","root","123456","green",0,NULL,0);
}

void nowdata::emit_change()
{
	emit change();
}

void nowdata::mychange()
{
	char * sql = "select * from data order by id desc";
	mysql_real_query(&mysql,sql,strlen(sql));
	MYSQL_RES *res;
	MYSQL_ROW row;
	res = mysql_store_result(&mysql);
	row = mysql_fetch_row(res);

	Airwenduslider->setValue(atoi(row[1]));
	Airwenduspinbox->setValue(atoi(row[1]));
	Airshiduslider->setValue(atoi(row[1]));
	Airshiduspinbox->setValue(atoi(row[1]));
	co2potslider->setValue(atoi(row[1]));
	co2potspinbox->setValue(atoi(row[1]));
	Soilwenduslider->setValue(atoi(row[1]));
	Soilwenduspinbox->setValue(atoi(row[1]));
	Soilshiduslider->setValue(atoi(row[1]));
	Soilshiduspinbox->setValue(atoi(row[1]));
	guangslider->setValue(atoi(row[1]));
	guangspinbox->setValue(atoi(row[1]));
}

nowdata::~nowdata()
{
	delete nowdatatitle;
	delete Airwendulabel;
	delete Airwenduslider;
	delete Airwenduspinbox;
	delete Airshidulabel;
	delete Airshiduslider;
	delete Airshiduspinbox;
	delete co2potlabel;
	delete co2potslider;
	delete co2potspinbox;
	delete Soilwendulabel;
	delete Soilwenduslider;
	delete Soilwenduspinbox;
	delete Soilshidulabel;
	delete Soilshiduslider;
	delete Soilshiduspinbox;
	delete guanglabel;
	delete guangslider;
	delete guangspinbox;
	delete glayout;
	mysql_close(&mysql);
}
