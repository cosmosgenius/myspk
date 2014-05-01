#include "myspk.h"
#include "ui_myspk.h"

MySpk::MySpk(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MySpk)
{
    ui->setupUi(this);
}

MySpk::~MySpk()
{
    delete ui;
}
