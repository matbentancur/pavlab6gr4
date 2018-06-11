#ifndef DTRECEPTOR_H
#define DTRECEPTOR_H

#include <string>
#include "FechaHora.h"

using namespace std;

class DtReceptor {

    private:
        string celular;
        string nombre;
        FechaHora vistoFechaHora;

    public:
        DtReceptor();
        DtReceptor(string,string,FechaHora);
        virtual ~DtReceptor();
        string getCelular();
        string getNombre();
        FechaHora getVistoFechaHora();
};

#endif
