#ifndef DTSIMPLE_H
#define DTSIMPLE_H

#include <string>
#include "DtMensaje.h"

class DtSimple : public DtMensaje {

    private:
        string texto;

    public:
        DtSimple();
        DtSimple(int, FechaHora, bool, string);
        virtual ~DtSimple();
        string getTexto();
};

#endif // DTSIMPLE_H
