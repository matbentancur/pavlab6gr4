#include "Privada.h"

Privada::Privada(int idConversacion, string origen,string nombre,string destino) : Conversacion(idConversacion, origen){
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

DtConversacion Privada::getDtConversacion(){
    DtPrivada dtPrivada = DtPrivada(this->idConversacion, this->destino, this->nombre);
    return dtPrivada;
}

Privada::~Privada(){}


