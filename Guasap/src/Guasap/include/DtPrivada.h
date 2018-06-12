#ifndef DTPRIVADA_H
#define DTPRIVADA_H

#include <string>
#include "DtConversacion.h"

using namespace std;

class DtPrivada : public DtConversacion {

    private:
        string destino;
        string nombre;

    public:
        DtPrivada();
        virtual ~DtPrivada();
        DtPrivada(int,string,string);
        string getDestino();
        string getNombre();
};

#endif // DTPRIVADA_H
