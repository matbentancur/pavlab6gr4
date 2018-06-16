#ifndef USUARIOCONVERSACION_H
#define USUARIOCONVERSACION_H

#include <set>
#include <map>
#include "EstadoConversacion.h"
#include "DtConversacion.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "Conversacion.h"

class Conversacion;
class DtMensaje;

class UsuarioConversacion {

    private:
        EstadoConversacion estado;
        Conversacion* conversacion;

    public:
        UsuarioConversacion(EstadoConversacion, Conversacion*);

        ~UsuarioConversacion();

        EstadoConversacion getEstado();
        void setEstado(EstadoConversacion);

        Conversacion* getConversacion();
        void setConversacion(Conversacion*);

        DtConversacion obtenerConversacion();
        map<int,DtMensaje> obtenerMensajes();
        map<string,DtReceptor> verInfoMensaje(int);

        bool enviarMensajeConversacion(DtMensaje);

};

#endif
