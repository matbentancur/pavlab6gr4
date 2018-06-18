#include "Conversacion.h"
#include "Mensaje.h"

Conversacion::Conversacion(int idConversacion, string nombre, Usuario* origen){
     this->idConversacion = idConversacion;
     this->nombre = nombre;
     this->origen = origen;
}

int Conversacion::getIdConversacion(){
    return this->idConversacion;
}

void Conversacion::setIdConversacion(int idConversacion){
        this->idConversacion = idConversacion;
}

string Conversacion::getNombre(){
    return this->nombre;
}

void Conversacion::setNombre(string nombre){
    this->nombre = nombre;
}

Usuario* Conversacion::getOrigen(){
    return this->origen;
}

void Conversacion::setOrigen(Usuario* origen){
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

map<string,DtReceptor> Conversacion::verInfoMensaje(int codigo){
    map<string,DtReceptor> listaReceptores;
	map<int,Mensaje*>::iterator i;
    for(i = mensajes.begin(); i != mensajes.end(); ++i){
        Mensaje * mensaje = i->second;
        if (mensaje->getCodigo() == codigo){
            listaReceptores = mensaje->getReceptores();
        }
	}
	return listaReceptores;
}

bool Conversacion::agregrarMensaje(Mensaje* nuevoMensaje){
    mensajes.insert(std::pair<int, Mensaje*>(nuevoMensaje->getCodigo(), nuevoMensaje));
	return true;
}

Conversacion::~Conversacion(){}
