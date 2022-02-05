#ifndef USUARIO_H
#define USUARIO_H

#include <QObject>
#include <QDebug>
#include <string>

class Usuario
{

public:
    Usuario(QString m_clave, QString m_usuario);



    const QString &user() const;
    void setUser(const QString &newUser);
    const QString &clave() const;
    void setClave(const QString &newClave);

signals:

private:
    void descifrado();
    QString m_user;
    QString m_clave;


};

#endif // USUARIO_H
