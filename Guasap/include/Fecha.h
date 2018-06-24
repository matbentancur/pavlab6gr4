#ifndef FECHA_H
#define FECHA_H

#include <sstream>
#include <iostream>
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

        friend ostream& operator << (ostream &salida, Fecha&);
};

#endif // FECHA_H
