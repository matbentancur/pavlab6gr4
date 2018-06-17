#include "UsuarioConversacion.h"

UsuarioConversacion::~UsuarioConversacion()
{
    //dtor
}

UsuarioConversacion::UsuarioConversacion(EstadoConversacion estado, Conversacion* conversacion) {
    this->estado = estado;
    this->conversacion = conversacion;
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

DtConversacion UsuarioConversacion::obtenerConversacion(){
    return this->conversacion->getDtConversacion();
}

map<int,DtMensaje> UsuarioConversacion::obtenerMensajes(){
    return this->conversacion->getMensajes();
}

map<string,DtReceptor> UsuarioConversacion::verInfoMensaje(int codigo){
    return this->conversacion->verInfoMensaje(codigo);
}

bool UsuarioConversacion::enviarMensajeConversacion(Mensaje* nuevoMensaje){

    try{
        Privada* c = dynamic_cast<Privada*>(this->conversacion);
    }catch(std::bad_cast){
        cout << "Error en cast para Privada\n";
    }

    try{
        Grupo* c = dynamic_cast<Grupo*>(this->conversacion);

    }catch(std::bad_cast){
        cout << "Error en cast para Privada\n";
    }

    return this->conversacion->agregrarMensaje(nuevoMensaje);
}
