#ifndef USUARIOMENSAJE_H
#define USUARIOMENSAJE_H

#include "FechaHora.h"
#include "Usuario.h"

class UsuarioMensaje {
    private:
        bool visto;
        FechaHora vistoFechaHora;
        Usuario* usuario;

    public:
        UsuarioMensaje();
        UsuarioMensaje(bool, FechaHora, Usuario*);
        virtual ~UsuarioMensaje();
};

#endif // USUARIOMENSAJE_H
