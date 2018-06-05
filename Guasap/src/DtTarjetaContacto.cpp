#include "DtTarjetaContacto.h"

DtTarjetaContacto::DtTarjetaContacto()
{
    //ctor
}

DtTarjetaContacto::~DtTarjetaContacto()
{
    //dtor
}

DtTarjetaContacto::DtTarjetaContacto(int codigo, FechaHora enviado, bool visto, string nombre, string telefono) : DtMensaje(codigo, enviado, visto){
    this->nombre = nombre;
    this->telefono = telefono;
}

string DtTarjetaContacto::getNombre(){
    return this->nombre;
}

string DtTarjetaContacto::getTelefono(){
    return this->telefono;
}
