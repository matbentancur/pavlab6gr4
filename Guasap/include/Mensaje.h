#ifndef MENSAJE_H_INCLUDED
#define MENSAJE_H_INCLUDED

#include <set>
#include "FechaHora.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "UsuarioMensaje.h"

using namespace std;

class UsuarioMensaje;

class Mensaje{

    protected:
        int codigo;
        FechaHora enviado;
        bool visto;
        set<UsuarioMensaje*> usuarioMensaje;

    public:
        Mensaje(int,FechaHora,bool);

        int getCodigo();
        void setCodigo(int);
        FechaHora getEnviado();
        void setEnviado(FechaHora);
        bool getVisto();
        void setVisto(bool);

        virtual DtMensaje getDtMensaje() = 0;
        map <string,DtReceptor> getReceptores();

        ~Mensaje();
};

#endif // MENSAJE_H_INCLUDED
