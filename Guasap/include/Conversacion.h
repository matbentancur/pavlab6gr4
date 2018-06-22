#ifndef CONVERSACION_H_INCLUDED
#define CONVERSACION_H_INCLUDED

#include <map>
#include "DtPrivada.h"
#include "DtGrupo.h"
#include "DtMensaje.h"
#include "DtReceptor.h"


using namespace std;

class Usuario;
class Mensaje;

class Conversacion{

    protected:
        int idConversacion;
        Usuario* origen;
        map<int,Mensaje*> mensajes;

    public:
        Conversacion(int,Usuario*);

        int getIdConversacion();
        void setIdConversacion(int);

        Usuario* getOrigen();
        void setOrigen(Usuario*);

        virtual DtConversacion* getDtConversacion() = 0;
        map<int,DtMensaje*> getMensajes();
        map<string,DtReceptor> verInfoMensaje(int);

        virtual bool agregrarMensaje(Mensaje*) = 0;

        bool eliminarMensaje(int);

        ~Conversacion();
};

#endif // CONVERSACION_H_INCLUDED

/* Origen esta en la clase Conversacion pero no en su datatype */
