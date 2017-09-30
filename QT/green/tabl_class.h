#ifndef TABL_CLASS_H
#define TABL_CLASS_H

#include <QTabWidget>
#include <QDialog>
#include "g_class.h"

class mytab:public QDialog
{
	Q_OBJECT
	
public:
	QTabWidget * tab;
	greenhouse * grh1;
	greenhouse * grh2;
	mytab(QWidget *parent = 0);
	

};






#endif
