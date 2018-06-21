#ifndef DTSIMPLE_H
#define DTSIMPLE_H

#include <string>
#include <iostream>
#include "DtMensaje.h"

class DtSimple : public DtMensaje {

    private:
        string texto;

    public:
        DtSimple();
        DtSimple(string);
        DtSimple(int, FechaHora, bool, string);
        virtual ~DtSimple();
        string getTexto();

        friend ostream& operator << (ostream &salida, DtSimple&);
};

#endif // DTSIMPLE_H
