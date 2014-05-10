#include "myspkmain.h"
#include "ui_myspkmain.h"
#include "palayer.h"

MySpkMain::MySpkMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MySpkMain)
{
    PaLayer a;
    a.init();
    ui->setupUi(this);
}

MySpkMain::~MySpkMain()
{
    delete ui;
}
