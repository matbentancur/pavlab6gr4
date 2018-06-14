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
