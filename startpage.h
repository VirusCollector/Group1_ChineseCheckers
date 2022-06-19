#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <widget.h>
#include <server.h>

namespace Ui {
class StartPage;
}

class StartPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartPage(QWidget *parent = nullptr);
    ~StartPage();
       server *t;
       Widget *s;

signals:
    void s_server();
    void s_client();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::StartPage *ui;
};

#endif // STARTPAGE_H
