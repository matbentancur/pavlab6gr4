#include "DtTarjetaContacto.h"

DtTarjetaContacto::DtTarjetaContacto()
{
    //ctor
}

DtTarjetaContacto::~DtTarjetaContacto()
{
    //dtor
}

DtTarjetaContacto::DtTarjetaContacto(string nombre, string telefono) : DtMensaje(){
    this->nombre = nombre;
    this->telefono = telefono;
}

DtTarjetaContacto::DtTarjetaContacto(int codigo, FechaHora enviado, bool visto, Usuario* emisor, string nombre, string telefono) : DtMensaje(codigo, enviado, visto,emisor){
    this->nombre = nombre;
    this->telefono = telefono;
}

string DtTarjetaContacto::getNombre(){
    return this->nombre;
}

string DtTarjetaContacto::getTelefono(){
    return this->telefono;
}
