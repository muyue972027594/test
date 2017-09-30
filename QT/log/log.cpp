/*
 *文件名：log.cpp
 *功  能：登陆界面
 *作  者：张
 *日  期：9.26
 *
 */

#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
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
	label->setPixmap(QPixmap("./imag/qi.jpg"));
	QLineEdit *edit_name = new QLineEdit("QQ/phon");
	QLineEdit *edit_pass = new QLineEdit("password");
	edit_name->setEchoMode(QLineEdit::Normal);
	edit_pass->setEchoMode(QLineEdit::Password);
	edit_name->home(true);
	edit_pass->home(true);
	QPushButton *but_log = new QPushButton("loging");
	QPushButton *but_new = new QPushButton("creat newID");
	QPushButton *but_fog = new QPushButton("forget pass");
	QCheckBox *box_remin = new QCheckBox("remind me");
	QCheckBox *box_aulog = new QCheckBox("auto log");

	QGridLayout *glay = new QGridLayout;
	
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

	window->setLayout(glay);
	window->show();

	return app.exec();
}
