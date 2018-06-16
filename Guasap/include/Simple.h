#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include "DtSimple.h"
#include "Mensaje.h"

class Simple : public Mensaje{

    private:
        string texto;
    public:
        Simple(int,FechaHora,bool,Usuario*, string);

        string getTexto();
        void setTexto(string);

        DtMensaje getDtMensaje();
        ~Simple();
};

#endif // SIMPLE_H_INCLUDED
