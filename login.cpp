#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->inUsuario->setFocus();
}

Login::~Login()
{
    delete ui;
}

