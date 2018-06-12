#ifndef SESION_H
#define SESION_H

#include <string>
#include "EstadoIngreso.h"

using namespace std;

class Sesion {

    private:
        string celular;

    public:
        Sesion();
        virtual ~Sesion();
        string getSesion();
        EstadoIngreso getEstado(string);
};

#endif // SESION_H
