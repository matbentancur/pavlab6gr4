#ifndef CONVERSACION_H_INCLUDED
#define CONVERSACION_H_INCLUDED

#include "DtConversacion.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include <set>

class Conversacion{

    protected:
        int idConversacion;
        string origen;
    public:
        Conversacion(int,string);

        int getIdConversacion();
        string getOrigen();
        void setIdConversacion(int);
        void setOrigen(string);

        virtual DtConversacion getDtConversacion() = 0;
        set<DtMensaje*> getMensajes();
        set<DtReceptor*> verInfoMensaje(int);

        ~Conversacion();
};

#endif // CONVERSACION_H_INCLUDED

/* Origen esta en la clase Conversacion pero no en su datatype */
