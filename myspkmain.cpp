#include "myspkmain.h"
#include "ui_myspkmain.h"

MySpkMain::MySpkMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MySpkMain)
{
    ui->setupUi(this);
}

MySpkMain::~MySpkMain()
{
    delete ui;
}
