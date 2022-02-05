#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include "usuario.h"
#include <QMessageBox>
#include "ingresodenotas.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    bool acertado();


private slots:
    void on_btnLogin_released();

private:
    Ui::Login *ui;
    QList<Usuario*>m_usuario;
    void limpiar();


};
#endif // LOGIN_H
