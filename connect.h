#ifndef CONNECT_H
#define CONNECT_H

#include <QWidget>

namespace Ui {
class Connect;
}

class Connect : public QWidget
{
    Q_OBJECT

public:
    explicit Connect(QWidget *parent = nullptr);
    ~Connect();

signals:
    void info(QString ip,QString port);//发送连接信号

private slots:
    void on_pushButton_clicked();//点击连接

private:
    Ui::Connect *ui;
};

#endif // CONNECT_H
