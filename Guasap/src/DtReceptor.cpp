#include "DtReceptor.h"

DtReceptor::DtReceptor()
{
    //ctor
}

DtReceptor::~DtReceptor()
{
    //dtor
}

DtReceptor::DtReceptor(string celular, string nombre, FechaHora vistoFechaHora) {
    this->celular = celular;
    this->nombre = nombre;
    this->vistoFechaHora = vistoFechaHora;
}

string DtReceptor::getCelular(){
    return this->celular;
}

string DtReceptor::getNombre(){
    return this->nombre;
}

FechaHora DtReceptor::getVistoFechaHora(){
    return this->vistoFechaHora;
}

ostream& operator << (ostream& salida, DtReceptor& dtReceptor) {
    salida <<
        "Celular: " << dtReceptor.celular << "\n" <<
        "Nombre: " << dtReceptor.nombre << "\n" <<
        "Visto: " << dtReceptor.vistoFechaHora << "\n";
    return salida;
}
