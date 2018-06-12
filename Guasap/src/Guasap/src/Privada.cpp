#include "Privada.h"

Privada::Privada(DtPrivada& dtPrivada){
    this->setIdConversacion(dtPrivada.getIdConversacion());
   // this->setOrigen(dtPrivada.getOrigen());
    this->setNombre(dtPrivada.getNombre());
    this->setDestino(dtPrivada.getDestino());

}

Privada::Privada(int idConversacion, string origen,string nombre,string destino){
    this->idConversacion = idConversacion;
    this->origen         = origen;
    this->nombre         = nombre;
    this->destino        = destino;
}

string Privada::getNombre(){
    return this->nombre;
}

string Privada::getDestino(){
    return this->destino;
}

void Privada::setNombre(string nombre){
    this->nombre = nombre;
}

void Privada::setDestino(string destino){
    this->destino = destino;
}

DtPrivada Privada::getDtConversacion(){

}

Privada::~Privada(){}


