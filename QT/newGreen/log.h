#ifndef _LOG_H_
#define _LOG_H_


#include "tabl_class.h"

class login:public QDialog
{
	Q_OBJECT

	QLabel *label ;
	QLineEdit *edit_name ;
	QLineEdit *edit_pass ;
	QPushButton *but_log ;
	QPushButton *but_new ;
	QPushButton *but_fog ;
	QCheckBox *box_remin ;
	QCheckBox *box_aulog ;
	mytab *tab;
	QGridLayout *glay ;

public:
	login(QWidget *parent = 0);
	void myemit();
signals:
	void myshow();
public slots:
	void islog();

};


#endif
