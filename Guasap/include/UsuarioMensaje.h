#ifndef USUARIOMENSAJE_H
#define USUARIOMENSAJE_H

#include "Usuario.h"

class Usuario;

class UsuarioMensaje {
    private:
        bool visto;
        FechaHora vistoFechaHora;
        Usuario* usuario;

    public:
        UsuarioMensaje(bool, FechaHora, Usuario*);
        virtual ~UsuarioMensaje();
};

#endif // USUARIOMENSAJE_H
