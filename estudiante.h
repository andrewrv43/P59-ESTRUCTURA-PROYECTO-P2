#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>

class Estudiante : public QObject
{
    Q_OBJECT
public:
    explicit Estudiante(QObject *parent = nullptr);
    Estudiante(float nota, const QString &nombre);

    float getNota() const;
    void setNota(float newNota);
    const QString &getNombre() const;
    void setNombre(const QString &newNombre);

signals:
private:
float nota;
QString nombre;

};

#endif // ESTUDIANTE_H
