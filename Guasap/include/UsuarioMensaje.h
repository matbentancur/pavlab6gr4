#ifndef USUARIOMENSAJE_H
#define USUARIOMENSAJE_H

#include "Usuario.h"

class Usuario;

class UsuarioMensaje {

    private:
        bool visto;
        FechaHora vistoFechaHora;
        bool eliminado;
        Usuario* usuario;

    public:
        UsuarioMensaje(bool, bool, Usuario*);
        UsuarioMensaje(bool, FechaHora, bool, Usuario*);

        bool getVisto();
        void setVisto(bool);

        FechaHora getVistoFechaHora();
        void setVistoFechaHora(FechaHora);

        bool getEliminado();
        void setEliminado(bool);

        Usuario* getUsuario();

        DtReceptor getDtReceptor();

        virtual ~UsuarioMensaje();
};

#endif // USUARIOMENSAJE_H
