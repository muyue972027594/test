/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNTITLED_H
#define UI_UNTITLED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QQ
{
public:
    QWidget *dockWidgetContents;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_3;

    void setupUi(QDockWidget *QQ)
    {
        if (QQ->objectName().isEmpty())
            QQ->setObjectName(QString::fromUtf8("QQ"));
        QQ->resize(666, 250);
        QFont font;
        font.setPointSize(13);
        QQ->setFont(font);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        pushButton = new QPushButton(dockWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 160, 99, 27));
        checkBox = new QCheckBox(dockWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(180, 120, 99, 22));
        checkBox_2 = new QCheckBox(dockWidgetContents);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(320, 120, 99, 22));
        lineEdit = new QLineEdit(dockWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(270, 30, 151, 27));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 30, 61, 31));
        label->setFont(font);
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 70, 68, 17));
        lineEdit_2 = new QLineEdit(dockWidgetContents);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(270, 70, 151, 27));
        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 30, 99, 27));
        pushButton_3 = new QPushButton(dockWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 70, 99, 27));
        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 40, 121, 81));
        label_3->setPixmap(QPixmap(QString::fromUtf8("newGreen/imag/qi.jpg")));
        QQ->setWidget(dockWidgetContents);

        retranslateUi(QQ);

        QMetaObject::connectSlotsByName(QQ);
    } // setupUi

    void retranslateUi(QDockWidget *QQ)
    {
        QQ->setWindowTitle(QApplication::translate("QQ", "DockWidget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("QQ", "PushButton", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("QQ", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("QQ", "CheckBox", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QQ", "\347\224\250\346\210\267\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("QQ", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("QQ", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("QQ", "PushButton", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QQ: public Ui_QQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNTITLED_H
