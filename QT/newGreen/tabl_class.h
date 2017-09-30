#ifndef TABL_CLASS_H
#define TABL_CLASS_H

#include <QTabWidget>
#include "g_class.h"

class mytab:public QDialog
{
	Q_OBJECT
	
	QTabWidget * tab;
	nowdata * grh1;
public:

	mytab(QWidget *parent = 0);
	void emitshow();
signals:
	void showdata();	

};






#endif
