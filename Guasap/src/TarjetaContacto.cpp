#include "TarjetaContacto.h"

TarjetaContacto::TarjetaContacto(DtTarjetaContacto &dtTarjetaContacto){
    this->setCodigo(dtTarjetaContacto.getCodigo());
    this->setEnviado(dtTarjetaContacto.getEnviado());
    this->setVisto(dtTarjetaContacto.getVisto());
    this->nombre   = nombre;
    this->telefono = telefono;
}

TarjetaContacto::TarjetaContacto(int codigo,FechaHora enviado,bool visto,string nombre, string telefono){
    this->setCodigo(codigo);
    this->setEnviado(enviado);
    this->setVisto(visto);
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

TarjetaContacto::~TarjetaContacto(){}
