#include "Privada.h"
#include "Usuario.h"

Privada::Privada(int idConversacion, string nombre, Usuario* origen, Usuario* destino) : Conversacion(idConversacion, nombre, origen){
    this->destino = destino;
}

Usuario* Privada::getDestino(){
    return this->destino;
}

void Privada::setDestino(Usuario* destino){
    this->destino = destino;
}

DtConversacion Privada::getDtConversacion(){
    DtPrivada dtPrivada = DtPrivada(this->idConversacion, this->nombre, this->destino->getCelular());
    return dtPrivada;
}

Privada::~Privada(){}


