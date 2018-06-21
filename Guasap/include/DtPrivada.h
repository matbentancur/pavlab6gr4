#ifndef DTPRIVADA_H
#define DTPRIVADA_H

#include <iostream>
#include "DtConversacion.h"

using namespace std;

class DtPrivada : public DtConversacion {

    private:
        string destino;

    public:
        DtPrivada();
        virtual ~DtPrivada();
        DtPrivada(int,string,string);

        string getDestino();

        friend ostream& operator << (ostream &salida, DtPrivada&);
};

#endif // DTPRIVADA_H
