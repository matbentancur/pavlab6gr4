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
