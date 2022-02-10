#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    generar();
    ui->inPassword->setEchoMode(QLineEdit::Password);
    ui->inUsuario->setFocus();
    QDir sitio(QDir::homePath()+"/Desktop"+"/Almacen");
    if(!sitio.exists()){
        sitio.mkpath(".");
        generar();
    }
    QString nombre=QDir::homePath()+"/Desktop"+"/Almacen/users.csv";
    QFile archivo;
    QTextStream io;
    archivo.setFileName(nombre);
    archivo.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!archivo.isOpen()){
        qDebug()<<"ERROR";
        QMessageBox::warning(this,"ERROR FATAL","No se encontro el archivo users.csv");
        return;
    };
    QString User, Password;
    io.setDevice(&archivo);
    while(!io.atEnd()){
        auto linea = io.readLine();
        auto valores=linea.split(";");
        User=valores[0];
        Password=valores[1];
        m_usuario.append(new Usuario(Password,User));
    }
    archivo.close();

}

Login::~Login()
{

    delete ui;
}


void Login::on_btnLogin_released()
{
    bool correcto=false;//CAMBIAR PARA QUE FUNCIONE BIEN DEBE ESTAR EN FALSE
    for(int i=0;i<m_usuario.size();i++){
        if(ui->inUsuario->text()==m_usuario.at(i)->user()&&ui->inPassword->text()==m_usuario.at(i)->clave()){
            correcto=true;
        }
    }
    if(!correcto){
        QMessageBox::warning(this,"DATOS INCORRECTOS","INGRESE LOS DATOS NUEVAMENTE");
        limpiar();
        return;
    }
    else{
        QMainWindow::hide();
        IngresoDeNotas *w=new IngresoDeNotas(this);
        w->show();

    }

}

void Login::limpiar()
{
    ui->inPassword->clear();
    ui->inUsuario->clear();
}

void Login::generar()
{

    QFile archivo(QDir::homePath()+"/Desktop/"+"/Almacen/users.csv");
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        datosArchivo<<"Andrew;Boesfx\nJuan;Kvbo\n";
}
    archivo.close();
}



