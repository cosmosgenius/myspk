#include "myspkmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MySpkMain w;
    w.show();

    return a.exec();
}
