#ifndef PRIVADA_H_INCLUDED
#define PRIVADA_H_INCLUDED

#include "Conversacion.h"

using namespace std;

class Usuario;
class Mensaje;

class Privada : public Conversacion{

    private:
        Usuario* destino;

    public:
        Privada(int,Usuario*,Usuario*);

        Usuario* getDestino();
        void setDestino(Usuario*);

        DtConversacion getDtConversacion();

        bool agregrarMensaje(Mensaje*);

        ~Privada();

};

#endif // PRIVADA_H_INCLUDED
