#include "estudiante.h"

Estudiante::Estudiante(QObject *parent) : QObject(parent)
{

}

float Estudiante::getNota() const
{
    return nota;
}

void Estudiante::setNota(float newNota)
{
    nota = newNota;
}

const QString &Estudiante::getNombre() const
{
    return nombre;
}

void Estudiante::setNombre(const QString &newNombre)
{
    nombre = newNombre;
}

Estudiante::Estudiante(float nota, const QString &nombre) : nota(nota),
    nombre(nombre)
{}
