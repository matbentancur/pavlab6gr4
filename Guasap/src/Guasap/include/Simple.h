#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include "DtSimple.h"
#include "Mensaje.h"

class Simple : public Mensaje{

    private:
        string texto;
    public:
        Simple(DtSimple&);
        Simple(int,FechaHora,bool,string);

        string getTexto();
        void setTexto(string);

         virtual DtMensaje getDtMensaje()=0;
        ~Simple();
};

#endif // SIMPLE_H_INCLUDED
