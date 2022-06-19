#include "widget.h"
#include "server.h"
#include "startpage.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartPage k;
    k.show();




    return a.exec();
}
