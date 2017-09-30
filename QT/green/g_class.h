#ifndef _G_CLASS_H_
#define _G_CLASS_H_


#include <QDialog>
#include <QtGui>
#include <mysql/mysql.h>

class greenhouse : public QDialog
{
	Q_OBJECT

	QLabel * temlabel;
	QSlider * temslider;
	QSpinBox * temspinbox;
	QVBoxLayout *vlayout;
	MYSQL mysql;
public:
	greenhouse(QWidget *parent = 0);
	void emit_change(int x);
	~greenhouse();
signals:
	void change(int x);

public slots:
	void mychange(int x);


};





#endif




