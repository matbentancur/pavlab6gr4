#ifndef PRIVADA_H_INCLUDED
#define PRIVADA_H_INCLUDED

#include "Conversacion.h"
#include "DtPrivada.h"

class Privada : public Conversacion{

    private:
        string nombre;
        string destino;
    public:
        Privada(int,string,string,string);

        string getNombre();
        string getDestino();

        void setNombre(string);
        void setDestino(string);

        DtConversacion getDtConversacion();
        ~Privada();

};

#endif // PRIVADA_H_INCLUDED
