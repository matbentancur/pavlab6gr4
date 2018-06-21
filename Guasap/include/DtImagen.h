#ifndef DTIMAGEN_H
#define DTIMAGEN_H

#include <iostream>
#include "DtMensaje.h"

class DtImagen : public DtMensaje {

    private:
        string url;
        string formato;
        int tamanio;
        string texto;

    public:
        DtImagen();
        DtImagen(string, string, int, string);
        DtImagen(int, FechaHora, bool, string, string, int, string);
        virtual ~DtImagen();
        string getUrl();
        string getFormato();
        int getTamanio();
        string getTexto();

        friend ostream& operator << (ostream &salida, DtImagen&);
};

#endif // DTIMAGEN_H
