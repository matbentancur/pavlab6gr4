#ifndef IMAGEN_H_INCLUDED
#define IMAGEN_H_INCLUDED

#include "DtMensaje.h"
#include "DtImagen.h"
#include "Multimedia.h"

class Imagen : public Multimedia{

    private:
        string url;
        string formato;
        string texto;
        int tamanio;
    public:
        Imagen(int,FechaHora,bool,Usuario*,string,string,string,int);
        string getUrl();
        string getFormato();
        string getTexto();
        int getTamanio();

        void setUrl(string);
        void setFormato(string);
        void setTexto(string);
        void setTamanio(int);

        DtMensaje* getDtMensaje();

        ~Imagen();

};

#endif // IMAGEN_H_INCLUDED

