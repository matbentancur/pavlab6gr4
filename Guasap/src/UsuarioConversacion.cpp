#include "UsuarioConversacion.h"
#include "EstadoConversacion.h"

UsuarioConversacion::UsuarioConversacion()
{
    //ctor
}

UsuarioConversacion::~UsuarioConversacion()
{
    //dtor
}

UsuarioConversacion::UsuarioConversacion(EstadoConversacion estado) {
    this->estado = estado;
}

EstadoConversacion UsuarioConversacion::getEstado() {
    return this->estado;
}

void UsuarioConversacion::setEstado(EstadoConversacion estado) {
    this->estado = estado;
}

Conversacion* UsuarioConversacion::getConversacion() {
    return this->conversacion;
}

DtConversacion UsuarioConversacion::obtenerConversacion(){
    return this->conversacion->getDtConversacion();
}

map<int,DtMensaje> UsuarioConversacion::obtenerMensajes(){
    return this->conversacion->getMensajes();
}
//
//set<DtReceptor*> UsuarioConversacion::verInfoMensaje(int){
//
//}
