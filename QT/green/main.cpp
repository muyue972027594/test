#include <QApplication>
#include <QtGui>
#include "g_class.h"
#include "tabl_class.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * fun1(void *arg)
{
	mytab *gtab = (mytab *)arg;
	for(int i = 0;i < 100;i++)
	{
//	srand(time(0));
//	t = int(101.0 * rand()/(RAND_MAX + 1.0));
	gtab->grh1->emit_change(1);
	usleep(100);
	}


}


int main(int argc ,char *argv[])
{
	pthread_t pid;

	QApplication app(argc,argv);

	mytab * gtab = new mytab;
	gtab->show();

	pthread_create(&pid,NULL,fun1,gtab);

	app.exec();
}
