#include "usuario.h"


Usuario::Usuario(QString m_clave, QString m_usuario)
{
    this->m_clave=m_clave;
    this->m_user=m_usuario;
    descifrado();
}

const QString &Usuario::user() const
{
    return m_user;
}

void Usuario::setUser(const QString &newUser)
{
    m_user = newUser;
}

const QString &Usuario::clave() const
{
    return m_clave;
}

void Usuario::setClave(const QString &newClave)
{
    m_clave = newClave;
}

void Usuario::descifrado()
{
    string clave=m_clave.toStdString();
    for(int i=0;i<m_clave.length();i++){
        if(clave[i]==90){
            clave[i]=65;
        }
        else if(clave[i]==122){
            clave[i]=97;
        }
        else{
            clave[i]=clave[i]-1;
        }
    }
    m_clave=QString::fromStdString(clave);
qDebug()<<m_clave;
}
