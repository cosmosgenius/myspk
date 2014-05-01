#ifndef MYSPK_H
#define MYSPK_H

#include <QMainWindow>

namespace Ui {
class MySpk;
}

class MySpk : public QMainWindow
{
    Q_OBJECT

public:
    explicit MySpk(QWidget *parent = 0);
    ~MySpk();

private:
    Ui::MySpk *ui;
};

#endif // MYSPK_H
