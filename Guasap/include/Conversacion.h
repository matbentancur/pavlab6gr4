#ifndef CONVERSACION_H_INCLUDED
#define CONVERSACION_H_INCLUDED

#include <set>
#include <map>
#include "DtConversacion.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "Mensaje.h"

class Mensaje;

class Conversacion{

    protected:
        int idConversacion;
        string origen;
        map<int,Mensaje*> mensajes;

    public:
        Conversacion(int,string);

        int getIdConversacion();
        string getOrigen();
        void setIdConversacion(int);
        void setOrigen(string);

        virtual DtConversacion getDtConversacion() = 0;
        map<int,DtMensaje> getMensajes();
        set<DtReceptor*> verInfoMensaje(int);

        ~Conversacion();
};

#endif // CONVERSACION_H_INCLUDED

/* Origen esta en la clase Conversacion pero no en su datatype */
