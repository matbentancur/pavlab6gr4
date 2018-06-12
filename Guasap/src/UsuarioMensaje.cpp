#include "UsuarioMensaje.h"

UsuarioMensaje::UsuarioMensaje()
{
    //ctor
}

UsuarioMensaje::~UsuarioMensaje()
{
    //dtor
}

UsuarioMensaje::UsuarioMensaje(bool visto, FechaHora vistoFechaHora, Usuario* usuario) {
    this->visto = visto;
    this->vistoFechaHora = vistoFechaHora;
    this->usuario = usuario;
}
