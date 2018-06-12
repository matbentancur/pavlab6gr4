#include "Conversacion.h"

Conversacion::Conversacion(int idConversacion,string origen){
     this->idConversacion = idConversacion;
     this->origen         = origen;
}

int Conversacion::getIdConversacion(){
    return this->idConversacion;
}

string Conversacion::getOrigen(){
    return this->origen;
}

void Conversacion::setIdConversacion(int idConversacion){
        this->idConversacion = idConversacion;
}

void Conversacion::setOrigen(string origen){
        this->origen = origen;
}

Conversacion::~Conversacion(){}
