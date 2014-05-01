#include "myspk.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySpk w;
    w.show();

    return a.exec();
}
