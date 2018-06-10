#ifndef ESTADO_H
#define ESTADO_H

#include <string>
#include "FechaHora.h"

using namespace std;

class Estado{

    private:
        string texto;
        FechaHora publicado;
    public:
        Estado();
        string getTexto();
        FechaHora getPublicado();

        void setTexto(string);
        void setPublicado(FechaHora);

        ~Estado();
};

#endif // ESTADO_H
