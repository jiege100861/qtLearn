#include <QApplication>//原先，程序对象
#include <QLabel>//用到QLabel就要包含的头文件
#include <QLineEdit>//用到文本行编辑框就要包含的头文件
#include <QPushButton>//用到按钮就要包含的头文件
#include <QHBoxLayout>    //用到水平布局就要包含的头文件
#include <QVBoxLayout>    //用到垂直布局就要包含的头文件
#include <QWidget>  //用到窗口就要包含的头文件

int main(int argc, char *argv[])//原先
{
	QApplication app(argc, argv);//原先
	//QLabel对象（类名）    *infoLabel对象指针    new QLabel new加类名产生新的对象
	//infoLabel关于这个命名方式，前面是来表示这个控件的信息的。
	//这个控件主要来存放什么信息呢？
	//其实就是一个，就相当于是一个提示信息嘛，这个文本框的提示信息啊，这个这个这个窗口的提示信息对不对。
	//所以我们起了个名字叫info小写，后面呢是它的标签，是它的控件名是不是label对吧，大写的L，好，所以就这样子来命名！
	//创建提示信息标签
	QLabel *infoLabel = new QLabel;
	//又来创建一个打开标签
	QLabel *openLabel = new QLabel;
	//创建cmd文本编辑框
	QLineEdit *cmdLineEdit = new QLineEdit;
	//创建确定按钮
	QPushButton *commitButton = new QPushButton;
	//创建取消按钮
	QPushButton *cancelButton = new QPushButton;
	//创建浏览按钮
	QPushButton *browseButton = new QPushButton;
	//设置文本
	infoLabel->setText("input cmd:");
	openLabel->setText("open");
	commitButton->setText("commit");
	cancelButton->setText("cancel");
	browseButton->setText("browse");
	//创建cmd水平布局对象
	QHBoxLayout *cmdLayout = new QHBoxLayout;  
	//添加控件
	cmdLayout->addWidget(openLabel);
	cmdLayout->addWidget(cmdLineEdit);
	//创建button水平布局对象
	QHBoxLayout *buttonLayout = new QHBoxLayout;
	//添加控件
	buttonLayout->addWidget(commitButton);
	buttonLayout->addWidget(cancelButton);
	buttonLayout->addWidget(browseButton);
	//创建main垂直布局对象
	QVBoxLayout *mainLayout = new QVBoxLayout;
	//添加控件
	mainLayout->addWidget(infoLabel);
	//把水平布局添加到垂直布局里面
	mainLayout->addLayout(cmdLayout);
	mainLayout->addLayout(buttonLayout);
	//创建窗口对象，一开始是空白窗口，要和主布局联系在一起
	QWidget w;
	//用“.”，因为不是指针
	//添加主布局
	w.setLayout(mainLayout);
	//显示窗口
	w.show();
	//改变窗口名称
	w.setWindowTitle("running");
	return app.exec();//原先
}
