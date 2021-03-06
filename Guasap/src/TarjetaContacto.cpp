#include "TarjetaContacto.h"

TarjetaContacto::TarjetaContacto(int codigo,FechaHora enviado,bool visto,Usuario* emisor,string nombre, string telefono) : Mensaje(codigo, enviado, visto, emisor){
    this->nombre   = nombre;
    this->telefono = telefono;
}

string TarjetaContacto::getNombre(){
    return this->nombre;
}

string TarjetaContacto::getTelefono(){
    return this->telefono;
}

void TarjetaContacto::setNombre(){
    this->nombre = nombre;
}

void TarjetaContacto::setTelefono(){
    this->telefono = telefono;
}

DtMensaje* TarjetaContacto::getDtMensaje(){
    DtTarjetaContacto* dtTarjetaContacto = new DtTarjetaContacto(this->codigo, this->enviado, this->visto, this->nombre, this->telefono);
    return dtTarjetaContacto;
}

TarjetaContacto::~TarjetaContacto(){}
