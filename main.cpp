#include "login.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Catalán"<<"Inglés"<< "Español";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "Idioma",
                                                       "Seleccione un idioma",
                                                       idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "Catalán"){
        traducion.load(":/ingresodenotas_ca.qm");
    }
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    else if (idiomaSeleccionado == "Inglés"){
        traducion.load(":/ingresodenotas_en.qm");
    }


    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }

    Login w;
    w.show();
    return a.exec();
}
