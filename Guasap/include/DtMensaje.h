#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <string>
#include "FechaHora.h"
#include "Usuario.h"

class Usuario;

class DtMensaje {

    private:
        int codigo;
        FechaHora enviado;
        bool visto;
        Usuario* emisor;

    public:
        DtMensaje();
        DtMensaje(int, FechaHora, bool, Usuario*);
        virtual ~DtMensaje();
        int getCodigo();
        FechaHora getEnviado();
        bool getVisto();
        Usuario* getEmisor();

};

#endif // DTMENSAJE_H
