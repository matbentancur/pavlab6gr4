#ifndef MENSAJE_H_INCLUDED
#define MENSAJE_H_INCLUDED

#include <map>
#include <set>
#include "FechaHora.h"
#include "DtMensaje.h"
#include "DtReceptor.h"

using namespace std;

class UsuarioMensaje;
class Usuario;

class Mensaje{

    protected:
        int codigo;
        FechaHora enviado;
        bool visto;
        Usuario* emisor;
        set<UsuarioMensaje*> usuarioMensaje;

    public:
        Mensaje();
        Mensaje(int,FechaHora,bool,Usuario*);

        int getCodigo();
        void setCodigo(int);
        FechaHora getEnviado();
        void setEnviado(FechaHora);
        bool getVisto();
        void setVisto(bool);
        Usuario* getEmisor();
        void setEmisor(Usuario*);

        bool agregarUsuarioMensaje(UsuarioMensaje*);

        bool eliminarMensajeLogico(Usuario*);
        bool estaEliminado(Usuario*);
        void marcarComoVisto(Usuario*);
        void verificarVisto();

        virtual DtMensaje* getDtMensaje() = 0;
        map<string,DtReceptor> getReceptores();

        ~Mensaje();
};

#endif // MENSAJE_H_INCLUDED
