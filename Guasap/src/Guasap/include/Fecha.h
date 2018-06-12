#ifndef FECHA_H
#define FECHA_H

#include <stdexcept>

using namespace std;

class Fecha {

    private:
        int dia;
        int mes;
        int anio;

    public:
        Fecha();
        virtual ~Fecha();
        Fecha (int,int,int);
        int getDia();
        int getMes();
        int getAnio();
};

#endif // FECHA_H
