#ifndef MENSAJE_H_INCLUDED
#define MENSAJE_H_INCLUDED

#include "FechaHora.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "UsuarioMensaje.h"
#include <set>

using namespace std;

class Mensaje{

    protected:
        int codigo;
        FechaHora enviado;
        bool visto;
        set<UsuarioMensaje*> usuarioMensaje;

    public:
        Mensaje(DtMensaje&);
        Mensaje(int,FechaHora,bool);

        int getCodigo();
        void setCodigo(int);
        FechaHora getEnviado();
        void setEnviado(FechaHora);
        bool getVisto();
        void setVisto(bool);

        ~Mensaje();
//        virtual DtMensaje getDtMensaje() = 0;
        set <DtReceptor*> getReceptores(); // no se implementa, no se pide en lab.
};

#endif // MENSAJE_H_INCLUDED
