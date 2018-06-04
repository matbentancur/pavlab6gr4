#include "DtContacto.h"

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
