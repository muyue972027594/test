/*
 *文件名：loging.cpp
 *功  能：登陆界面
 *作  者：张
 *日  期：9.26
 *
 */

#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPixmap>

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	QWidget *window = new QWidget;
	window->setWindowTitle("QQ");
	
	QLabel *label = new QLabel;
	label->setPixmap(QPixmap("./qi.jpg"));
	QLineEdit *edit_name = new QLineEdit("QQ number/phon number");
	QLineEdit *edit_pass = new QLineEdit("QQ passwor");
	edit_name->setEchoMode(QLineEdit::Normal);
	edit_pass->setEchoMode(QLineEdit::Password);
	QPushButton *but_log = new QPushButton("loging");
	QPushButton *but_new = new QPushButton("creat newID");
	QPushButton *but_fog = new QPushButton("forget pass");
	QCheckBox *box_remin = new QCheckBox("remind me");
	QCheckBox *box_aulog = new QCheckBox("auto log");

	QHBoxLayout *hlay1 = new QHBoxLayout;
	QHBoxLayout *hlay2 = new QHBoxLayout;
	QVBoxLayout *vlay1 = new QVBoxLayout;
	QVBoxLayout *vlay2 = new QVBoxLayout;

	hlay1->addWidget(box_remin);
	hlay1->addWidget(box_aulog);

	vlay1->addWidget(edit_name);
	vlay1->addWidget(edit_pass);
	vlay1->addLayout(hlay1);
	vlay1->addWidget(but_log);

	vlay2->addWidget(but_new);
	vlay2->addWidget(but_fog);
	vlay2->addStretch();

	hlay2->addWidget(label);
	hlay2->addLayout(vlay1);
	hlay2->addLayout(vlay2);

	hlay2->setMargin(50);
	hlay2->setSpacing(20);

	window->setLayout(hlay2);
	window->show();

	return app.exec();
}
