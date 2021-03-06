#ifndef DTRECEPTOR_H_INCLUDED
#define DTRECEPTOR_H_INCLUDED

#include <string>
#include <iostream>
#include "FechaHora.h"

using namespace std;

class DtReceptor{

    private:
        string celular;
        string nombre;
        bool visto;
        FechaHora vistoFechaHora;

    public:
        DtReceptor();
        DtReceptor(string,string,bool,FechaHora);
        virtual ~DtReceptor();
        string getCelular();
        string getNombre();
        bool getVisto();
        FechaHora getVistoFechaHora();

        friend ostream& operator << (ostream &salida, DtReceptor&);
};

#endif // DTRECEPTOR_H_INCLUDED
