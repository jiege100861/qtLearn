#include "widget.h"          //原先
#include "ui_widget.h"          //原先

Widget::Widget(QWidget *parent) :           //原先
    QWidget(parent), 
    ui(new Ui::Widget)
{
    ui->setupUi(this);                //原先

    //连接信号与槽  谁发出信号 发出什么信号 谁处理信号 怎么处理
    connect(ui->cmdLineEdit, SIGNAL(returnPressed()), this, SLOT(on_commitButton_clicked()));

    connect(ui->cancelButton, &QPushButton::clicked, this, &Widget::on_cancelButton_clicked);

    connect(ui->browseButton, &QPushButton::clicked, [this]()
    {
        QMessageBox::information(this, "信息", "点击浏览");
    });
}

Widget::~Widget()           //原先
{
    delete ui;
}

void Widget::on_commitButton_clicked()
{
    //获取lineedit数据
    QString program = ui->cmdLineEdit->text();
    //创建process对象
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program);
}

void Widget::on_cancelButton_clicked()       //源文件转到槽后会自动加这个                           
{                                            //头文件也会增加slots
    this->close();               //这个不是自动加的
}
