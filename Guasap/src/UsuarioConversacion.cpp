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

DtConversacion UsuarioConversacion::obtenerConversacion(){
    return this->conversacion->getDtConversacion();
}
//
//set<DtMensaje*> UsuarioConversacion::obtenerMensajes(int){
//
//}
//
//set<DtReceptor*> UsuarioConversacion::verInfoMensaje(int){
//
//}
