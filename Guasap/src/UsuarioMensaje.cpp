#include "UsuarioMensaje.h"

UsuarioMensaje::UsuarioMensaje(bool visto, FechaHora vistoFechaHora, Usuario* usuario) {
    this->visto = visto;
    this->vistoFechaHora = vistoFechaHora;
//    this->usuario = usuario;
}

UsuarioMensaje::~UsuarioMensaje()
{
    //dtor
}

bool UsuarioMensaje::getVisto(){
    return this->visto;
}

void UsuarioMensaje::setVisto(bool visto){
    this->visto = visto;
}

FechaHora UsuarioMensaje::getVistoFechaHora(){
    return this->vistoFechaHora;
}

void UsuarioMensaje::setVistoFechaHora(FechaHora vistoFechaHora){
    this->vistoFechaHora = vistoFechaHora;
}

Usuario* UsuarioMensaje::getUsuario(){
    return this->usuario;
}
