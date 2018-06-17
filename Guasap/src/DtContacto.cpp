#include "DtContacto.h"
#include <iostream>

DtContacto::DtContacto()
{
    //ctor
}

DtContacto::~DtContacto()
{
    //dtor
}

DtContacto::DtContacto(string celular, string nombre, string imagen) {
    this->celular = celular;
    this->nombre = nombre;
    this->imagen = imagen;
}

string DtContacto::getCelular(){
    return this->celular;
}

string DtContacto::getNombre(){
    return this->nombre;
}

string DtContacto::getImagen(){
    return this->imagen;
}

ostream& operator << (ostream& os, DtContacto& dtContacto) {
    os <<
        "Celular: " << dtContacto.celular << "\n" <<
        "Nombre: " << dtContacto.nombre << "\n" <<
        "Imagen: " << dtContacto.imagen<< "\n";
    return os;
}
