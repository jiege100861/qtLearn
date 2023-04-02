#ifndef WIDGET_H  //原先
#define WIDGET_H  //原先

#include <QWidget>  //原先
#include <QProcess>
#include <QMessageBox>

namespace Ui {    //原先
class Widget;     //原先
} 

class Widget : public QWidget    //原先
{
    Q_OBJECT
   
public:
    explicit Widget(QWidget *parent = 0);    //原先
    ~Widget();

private slots:
    void on_commitButton_clicked();         
    void on_cancelButton_clicked();

private:                          //原先
    Ui::Widget *ui;
};

#endif // WIDGET_H             //原先
