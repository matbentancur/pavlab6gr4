#include "DtReceptor.h"

DtReceptor::DtReceptor()
{
    //ctor
}

DtReceptor::~DtReceptor()
{
    //dtor
}

DtReceptor::DtReceptor(string celular, string nombre, bool visto, FechaHora vistoFechaHora) {
    this->celular = celular;
    this->nombre = nombre;
    this->visto = visto;
    this->vistoFechaHora = vistoFechaHora;
}

string DtReceptor::getCelular(){
    return this->celular;
}

string DtReceptor::getNombre(){
    return this->nombre;
}

bool DtReceptor::getVisto(){
    return this->visto;
}

FechaHora DtReceptor::getVistoFechaHora(){
    return this->vistoFechaHora;
}

ostream& operator << (ostream& salida, DtReceptor& dtReceptor) {
    string vistoString = (dtReceptor.visto == 0) ? "No" : "Si";
    salida <<
        "Celular: " << dtReceptor.celular << "\n" <<
        "Nombre: " << dtReceptor.nombre << "\n" <<
        "Visto: " << vistoString << "\n" <<
        "Visto Fecha Hora: " << dtReceptor.vistoFechaHora << "\n";
    return salida;
}
