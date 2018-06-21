#include "UsuarioMensaje.h"

UsuarioMensaje::UsuarioMensaje(bool visto, bool eliminado, Usuario* usuario) {
    this->visto = visto;
    this->eliminado = eliminado;
    this->usuario = usuario;
}

UsuarioMensaje::UsuarioMensaje(bool visto, FechaHora vistoFechaHora, bool eliminado, Usuario* usuario) {
    this->visto = visto;
    this->vistoFechaHora = vistoFechaHora;
    this->eliminado = eliminado;
    this->usuario = usuario;
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

bool UsuarioMensaje::getEliminado(){
    return this->eliminado;
}

void UsuarioMensaje::setEliminado(bool eliminado){
    this->eliminado = eliminado;
}

Usuario* UsuarioMensaje::getUsuario(){
    return this->usuario;
}

DtReceptor UsuarioMensaje::getDtReceptor(){
    DtReceptor dtReceptor = DtReceptor(this->usuario->getCelular(), this->usuario->getNombre(), this->vistoFechaHora);
    return dtReceptor;
}
