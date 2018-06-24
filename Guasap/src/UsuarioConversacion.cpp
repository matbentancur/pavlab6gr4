#include "UsuarioConversacion.h"

UsuarioConversacion::~UsuarioConversacion()
{
    //dtor
}

UsuarioConversacion::UsuarioConversacion(FechaHora agregadoEnConversacion, EstadoConversacion estado, Conversacion* conversacion) {
    this->agregadoEnConversacion = agregadoEnConversacion;
    this->estado = estado;
    this->conversacion = conversacion;
}

FechaHora UsuarioConversacion::getAgregadoEnConversacion(){
    return this->agregadoEnConversacion;
}

void UsuarioConversacion::setAgregadoEnConversacion(FechaHora agregadoEnConversacion){
    this->agregadoEnConversacion = agregadoEnConversacion;
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

void UsuarioConversacion::setConversacion(Conversacion* conversacion) {
    this->conversacion = conversacion;
}

DtConversacion* UsuarioConversacion::obtenerConversacion(){
    return this->conversacion->getDtConversacion();
}

map<int,DtMensaje*> UsuarioConversacion::obtenerMensajes(){
    return this->conversacion->getMensajes();
}

map<string,DtReceptor> UsuarioConversacion::verInfoMensaje(int codigo){
    return this->conversacion->verInfoMensaje(codigo);
}

bool UsuarioConversacion::enviarMensajeConversacion(Mensaje* nuevoMensaje){
    return this->conversacion->agregrarMensaje(nuevoMensaje);
}

bool UsuarioConversacion::eliminarMensaje(int codigoMensaje){
    return this->conversacion->eliminarMensaje(codigoMensaje);
}
