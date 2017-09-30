/*
 *文件名：log.cpp
 *功  能：登陆界面
 *作  者：张
 *日  期：9.26
 *
 */

#include "log.h"

login::login(QWidget *parent):QDialog(parent)
{
	label = new QLabel;
	label->setPixmap(QPixmap("./imag/qi.jpg"));
	//label->setFixedSize(100,100);
	edit_name = new QLineEdit(trUtf8("用户名"));
	edit_pass = new QLineEdit(trUtf8("密码"));
	edit_name->setEchoMode(QLineEdit::Normal);
	edit_pass->setEchoMode(QLineEdit::Password);
	edit_name->home(true);
	edit_pass->home(true);
	but_log = new QPushButton(trUtf8("登  录"));
	but_new = new QPushButton(trUtf8("注  册"));
	but_fog = new QPushButton(trUtf8("忘记密码"));
	box_remin = new QCheckBox(trUtf8("记住密码"));
	box_aulog = new QCheckBox(trUtf8("自动登录"));

	glay = new QGridLayout;
	tab = new mytab;
	connect(this,SIGNAL(myshow()),tab,SIGNAL(showdata()));
	connect(but_log,SIGNAL(clicked()),this,SLOT(islog()));

	glay->addWidget(label,0,0,3,1);
	glay->addWidget(edit_name,0,1,1,2);
	glay->addWidget(edit_pass,1,1,1,2);
	glay->addWidget(box_remin,2,1,1,1);
	glay->addWidget(box_aulog,2,2,1,1);
	glay->addWidget(but_log,3,1,1,2);
	glay->addWidget(but_new,0,3,1,1);
	glay->addWidget(but_fog,1,3,1,2);

	glay->setMargin(50);
	glay->setSpacing(20);

	setLayout(glay);

}

void login::myemit()
{
	emit myshow();

}

void login::islog()
{
	if(!strcmp(edit_name->text().toStdString().c_str(),"zhang") &&
		!strcmp((edit_pass->text()).toStdString().c_str(),"123456"))
	{
		this->close();
		tab->show();
	}
	else
	{
		QMessageBox::information(NULL,trUtf8("登录错误"),
				trUtf8("用户名或密码错误！"),
				QMessageBox::Yes|QMessageBox::No,
				QMessageBox::Yes);
	}
}

