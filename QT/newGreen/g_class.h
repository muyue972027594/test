#ifndef _G_CLASS_H_
#define _G_CLASS_H_


#include <QDialog>
#include <QtGui>
#include <mysql/mysql.h>

class nowdata : public QDialog
{
	Q_OBJECT

	QLabel * nowdatatitle;
	QLabel * Airwendulabel;
	QSlider * Airwenduslider;
	QSpinBox * Airwenduspinbox;
	QLabel * Airshidulabel;
	QSlider * Airshiduslider;
	QSpinBox * Airshiduspinbox;
	QLabel * co2potlabel;
	QSlider * co2potslider;
	QSpinBox * co2potspinbox;
	QLabel * Soilwendulabel;
	QSlider * Soilwenduslider;
	QSpinBox * Soilwenduspinbox;
	QLabel * Soilshidulabel;
	QSlider * Soilshiduslider;
	QSpinBox * Soilshiduspinbox;
	QLabel * guanglabel;
	QSlider * guangslider;
	QSpinBox * guangspinbox;
	QGridLayout *glayout;
	MYSQL mysql;
public:
	nowdata(QWidget *parent = 0);
	void emit_change();
	~nowdata();
signals:
	void change();

public slots:
	void mychange();


};





#endif




