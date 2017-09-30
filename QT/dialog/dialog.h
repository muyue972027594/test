/*
 *文件名：dialog.h
 *功  能：定义一个dialog的类
 *作  者：张
 *日  期：9.27
 *
 *
 *
 *
 */
#ifndef _DIALOG_H_
#define _DIALOG_H_

#include <QDialog>
#include <QtGui>

class minDialog : public QDialog
{
	Q_OBJECT

public:
	QLabel    *label;
	QLineEdit *line;
	QCheckBox *cbox1;
	QCheckBox *cbox2;
	QPushButton *button1;
	QPushButton *button2;
	QGridLayout *glayout;
public:
	minDialog(QWidget *parent = 0);

signals:
	void find(const QString &str,Qt::CaseSensitivity csens);
	void find_backward(const QString &str,Qt::CaseSensitivity csens);

public slots:
//	void findclicked();
//	void enablefind(const QString &text);

};


#endif
