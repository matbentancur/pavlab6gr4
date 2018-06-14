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

map<int,DtMensaje> Conversacion::getMensajes(){
    map<int,DtMensaje> listaMensajes;
	map<int,Mensaje*>::iterator i;
    for(i = mensajes.begin(); i != mensajes.end(); ++i){
        Mensaje * mensaje = i->second;
        DtMensaje dtMensaje = mensaje->getDtMensaje();
        listaMensajes.insert(std::pair<int, DtMensaje>(mensaje->getCodigo(), dtMensaje));
	}
	return listaMensajes;
}

Conversacion::~Conversacion(){}
