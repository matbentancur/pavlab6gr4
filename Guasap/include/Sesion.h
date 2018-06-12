#ifndef SESION_H
#define SESION_H

#include <string>
#include "EstadoIngreso.h"

using namespace std;

class Sesion {

    private:
        string celular;
        static Sesion* instancia;
        Sesion();

    public:
        virtual ~Sesion();
        string getSesion();
        static Sesion* getInstancia();
        EstadoIngreso getEstado(string);
};

#endif // SESION_H
