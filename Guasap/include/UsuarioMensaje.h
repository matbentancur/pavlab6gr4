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

        bool getVisto();
        void setVisto(bool);

        FechaHora getVistoFechaHora();
        void setVistoFechaHora(FechaHora);

        Usuario* getUsuario();

        DtReceptor getDtReceptor();

        virtual ~UsuarioMensaje();
};

#endif // USUARIOMENSAJE_H
