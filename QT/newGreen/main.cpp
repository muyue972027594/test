#include <QApplication>
#include "log.h"
#include <unistd.h>
#include <pthread.h>

void * fun1(void *arg)
{
	login *ml = (login *)arg;
	while(1)
	{
	ml->myemit();
	usleep(100);
	}


}


int main(int argc ,char *argv[])
{
	pthread_t pid;

	QApplication app(argc,argv);

	login * mylog = new login;
	mylog->show();

	pthread_create(&pid,NULL,fun1,mylog);

	app.exec();
}
