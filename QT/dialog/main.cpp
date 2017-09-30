#include <QtGui>
#include "dialog.h"
#include <QApplication>
int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	minDialog *mylog = new minDialog;

	mylog->show();


	return app.exec();
}
