#ifndef INGRESODENOTAS_H
#define INGRESODENOTAS_H

#include <QMainWindow>
#include <QFile>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QTextStream>
#include "estudiante.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
namespace Ui {
class IngresoDeNotas;
}

class IngresoDeNotas : public QMainWindow
{
    Q_OBJECT

public:
    explicit IngresoDeNotas(QWidget *parent = nullptr);
    ~IngresoDeNotas();
    int ancho;
    int alto;
private slots:
    void on_pushButton_released();
    void on_btnGenerarGrafico_released();

    void on_actionGuardar_grafico_triggered();

private:
    void pruebadebarras();
    Ui::IngresoDeNotas *ui;
    void painterz();
    QPixmap pixmap;
    QPen pen;
    QPainter painter;
    void agregarArchivo();
    int contador;
    QList<Estudiante*>m_estudiantes;
    void dibujo(float nota,QString nombre);
    int separador;
};

#endif // INGRESODENOTAS_H
