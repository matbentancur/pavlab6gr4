#ifndef FECHAHORA_H
#define FECHAHORA_H

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
};

#endif // FECHAHORA_H
