#ifndef FECHAHORA_H
#define FECHAHORA_H

#include <iostream>
#include "Fecha.h"

using namespace std;

class FechaHora : public Fecha {

    private:
        int hora;
        int minuto;

    public:
        FechaHora();
        virtual ~FechaHora();
        FechaHora(int,int,int,int,int);
        int getHora();
        int getMinuto();

        friend ostream& operator << (ostream &salida, FechaHora&);
        friend bool operator < (const FechaHora& l, FechaHora& r);
};

#endif // FECHAHORA_H
