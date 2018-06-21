#ifndef DTPRIVADA_H
#define DTPRIVADA_H

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

        friend ostream& operator<<(ostream &os, DtPrivada&);
};

#endif // DTPRIVADA_H
