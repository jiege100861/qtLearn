#include "widget.h"          //原先
#include "ui_widget.h"          //原先

Widget::Widget(QWidget *parent) :           //原先
    QWidget(parent), 
    ui(new Ui::Widget)
{
    ui->setupUi(this);                //原先
    
    //信号是信号，槽是槽函数
    //连接信号与槽  谁发出信号 发出什么信号 谁处理信号 怎么处理
    //this这个widget类，调用on_commitButton_clicked()这个成员函数来处理
    //第一种：回车是确认
    connect(ui->cmdLineEdit, SIGNAL(returnPressed()),
    this, SLOT(on_commitButton_clicked()));

    //第二种：用地址点击取消
    connect(ui->cancelButton, &QPushButton::clicked, 
    this, &Widget::on_cancelButton_clicked);

    //第三种：槽函数里面处理的事情不多，没必要单独写一个槽函数
    //弹出对话框
    //记得包含头文件QMessageBox
    connect(ui->browseButton, &QPushButton::clicked, [this]()
    {
        QMessageBox::information(this, "信息", "点击浏览");
        //this是Widget父类，子类窗口名字是信息，提示信息是点击浏览
    });
}

Widget::~Widget()           //原先
{
    delete ui;
}

void Widget::on_commitButton_clicked()
{
    //获取lineedit数据，得使用到界面，访问界面用ui指针，指向界面文件
    //通过ui访问界面文件里面得的cmdLineEdit
    //QLineEdit里面有个成员函数，用它可以获取文本
    //返回值是QString格式，类似，c++里面string这样一个类，program就是个字符串对象
    QString program = ui->cmdLineEdit->text();
    
    //创建process对象，使用this作为参数  
    QProcess *myProcess = new QProcess(this);
    
    //program是从文本框里面获取的，start启动
    myProcess->start(program);
}

//也可以自己写槽函数，记得在头文件里面包含slots声明
void Widget::on_cancelButton_clicked()       //源文件转到槽后会自动加这个                           
{                                            //头文件也会增加slots
    this->close();               //这个不是自动加的
    //执行这句，相当于启动新的进程，头文件要包含
}
