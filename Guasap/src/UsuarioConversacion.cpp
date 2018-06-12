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

UsuarioConversacion::UsuarioConversacion(EstadoConversacion estadoConversacion) {
    this->estadoConversacion = estadoConversacion;
}

EstadoConversacion UsuarioConversacion::getEstadoConversacion() {
    return this->estadoConversacion;
}

void UsuarioConversacion::setEstadoConversacion(EstadoConversacion estadoConversacion) {
    this->estadoConversacion = estadoConversacion;
}
//
//DtContacto UsuarioConversacion::obtenerConversacion(){
//
//}
//
//set<DtMensaje*> UsuarioConversacion::obtenerMensajes(int){
//
//}
//
//set<DtReceptor*> UsuarioConversacion::verInfoMensaje(int){
//
//}
