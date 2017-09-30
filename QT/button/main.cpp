#include <QApplication>  //当窗口初始化的时候，引用的头文件
#include <QPushButton>   //定义QPushButton对象，引用的头文件
#include <QLabel>
int main(int argc,char **argv)
{
	   QApplication app(argc,argv);  //窗体初始化
	      QPushButton *button = new QPushButton("Quit");
	      QLabel *label = new QLabel("<font color=red>Quit!</font></h2>");
	         QObject::connect(button,SIGNAL(clicked()),button,SLOT(close()));
		    button->show();//显示该窗体
		    label->show();
		       return app.exec();
}

