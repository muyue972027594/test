#include <QtGui>
#include "dialog.h"


minDialog::minDialog(QWidget *parent):QDialog(parent)
{
	label = new QLabel("Find &what");
	line  = new QLineEdit("water");
	line->home(true);
	label->setBuddy(line);
	cbox1 = new QCheckBox("&Match case");
	cbox2 = new QCheckBox("Search &backward");
	button1 = new QPushButton("&Find");
//	button1->setDefault(true);
//	button1->setEnabled(false);
	button2 = new QPushButton("&close");

	glayout->addWidget(label,0,0,1,1);
	glayout->addWidget(line,0,1,1,2);
	glayout->addWidget(cbox1,1,0,1,2);
	glayout->addWidget(cbox2,2,0,1,2);
	glayout->addWidget(button1,0,3,1,1);
	glayout->addWidget(button1,1,3,1,1);

	glayout->setSpacing(20);
	glayout->setMargin(30);

//	connect(line,SIGNAL(textChanged(const QString &)),
//			this,SLOT(enablefind(const QString &)));
//	connect(button1,SIGNAL(clicked()),
//			this,SLOT(findclicked()));
//	connect(button2,SIGNAL(clicked()),
//			this,SLOT(close()));

	setLayout(glayout);
}


//void minDialog::findclicked()
//{}
//void minDialog::enablefind(const QString &text)
//{}



