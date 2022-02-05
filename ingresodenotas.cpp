#include "ingresodenotas.h"
#include "ui_ingresodenotas.h"

IngresoDeNotas::IngresoDeNotas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IngresoDeNotas)
{
    ui->setupUi(this);
    QStringList cabecera={"Nombre","Nota"};
    ui->outDetalle->setColumnCount(2);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
    ancho=700;
    alto=700;
    contador=0;
    separador=50;
    ui->outGrafo->resize(ancho,alto);
    pixmap=QPixmap(ui->outGrafo->size());
    pixmap.fill(Qt::white);
    painter.begin(&pixmap);
    painterz();
    alto-=40;
}

IngresoDeNotas::~IngresoDeNotas()
{
    delete ui;
}

void IngresoDeNotas::on_pushButton_released()
{
    int fila=ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(fila);
    ui->outDetalle->setItem(fila,0,new QTableWidgetItem(ui->inNombre->text()));
    ui->outDetalle->setItem(fila,1,new QTableWidgetItem(QString::number(ui->inNota->value(),'f',2)));
    agregarArchivo();
    m_estudiantes.append(new Estudiante(ui->inNota->value(),ui->inNombre->text()));
}

void IngresoDeNotas::pruebadebarras()
{


}

void IngresoDeNotas::painterz()
{

    pen.setColor(Qt::black);
    pen.setWidth(3);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    //EJE Y
    painter.drawLine(40,20,40,680);
    //EJE X
    painter.drawLine(40,680,680,680);
    pen.setColor(Qt::gray);
    painter.setPen(pen);
    QFont font = painter.font();
    font.setPixelSize(15);
    painter.setFont(font);
    painter.drawText((ancho/2)-15,15,"GRÁFICO DE NOTAS");
    pen.setColor(Qt::black);
    painter.setPen(pen);
    //eje y
    painter.drawText(10,364,"50--");
    painter.drawText(6,25,"100--");
    painter.drawText(13,683,"0--");
    painter.drawText(50,20,"Y");
    painter.drawText(685,670,"X");
    ui->outGrafo->setPixmap(pixmap);


}

void IngresoDeNotas::agregarArchivo()
{
    int filas=ui->outDetalle->rowCount();
    int cont=0;

    QFile archivo("../notas.csv");
    if(archivo.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream datosArchivo(&archivo);
        while(cont!=filas){

            datosArchivo<<ui->outDetalle->item(cont,0)->text()+";"+
                          ui->outDetalle->item(cont,1)->text()+"\n";
            cont++;
        }
    }
    archivo.close();

}

void IngresoDeNotas::dibujo(float nota, QString nombre)
{
    pen.setWidth(2);
    if(nota>=90){
        pen.setColor(Qt::green);
        painter.setBrush(Qt::green);
    }
    else if(nota>=70){
        pen.setColor(Qt::blue);
        painter.setBrush(Qt::blue);
    }
    else if(nota>=50){
        pen.setColor(Qt::yellow);
        painter.setBrush(Qt::yellow);
    }
    else if(nota<50){
        pen.setColor(Qt::red);
        painter.setBrush(Qt::red);
    }

    painter.setPen(pen);
    int pos=-((nota*680)/100);
    if(nota>10){
        pos+=20;
    }
    painter.drawRect(separador,680,30,pos);
    pen.setColor(Qt::black);
    ++contador;
    painter.setPen(pen);
    painter.drawText(separador-7,697,nombre);
    painter.drawText(separador-5,pos+alto,QString::number(nota,'f',2));
    ui->outGrafo->setPixmap(pixmap);
    separador+=60;



}


void IngresoDeNotas::on_btnGenerarGrafico_released()
{
    pixmap.fill(Qt::white);
painterz();
separador=50;
    foreach(Estudiante *a,m_estudiantes){

        dibujo(a->getNota(),a->getNombre());
    }


}


void IngresoDeNotas::on_actionGuardar_grafico_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (pixmap.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

