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

map<string,DtReceptor> UsuarioConversacion::verInfoMensaje(int codigo){
    return this->conversacion->verInfoMensaje(codigo);
}
