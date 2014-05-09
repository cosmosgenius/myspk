#ifndef MYSPKMAIN_H
#define MYSPKMAIN_H

#include <QMainWindow>

namespace Ui {
class MySpkMain;
}

class MySpkMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit MySpkMain(QWidget *parent = 0);
    ~MySpkMain();

private:
    Ui::MySpkMain *ui;
};

#endif // MYSPKMAIN_H
