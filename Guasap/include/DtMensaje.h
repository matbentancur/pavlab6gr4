#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <string>
#include "FechaHora.h"

using namespace std;

class DtMensaje {

    protected:
        int codigo;
        FechaHora enviado;
        bool visto;

    public:
        DtMensaje();
        DtMensaje(int, FechaHora, bool);
        virtual ~DtMensaje();
        int getCodigo();
        FechaHora getEnviado();
        bool getVisto();

};

#endif // DTMENSAJE_H
