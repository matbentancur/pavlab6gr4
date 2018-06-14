#ifndef DTIMAGEN_H
#define DTIMAGEN_H

#include "DtMensaje.h"

class DtImagen : public DtMensaje {

    private:
        string url;
        string formato;
        int tamanio;
        string texto;

    public:
        DtImagen();
        DtImagen(int, FechaHora, bool, string, string, int, string);
        virtual ~DtImagen();
        string getUrl();
        string getFormato();
        int getTamanio();
        string getTexto();
};

#endif // DTIMAGEN_H
