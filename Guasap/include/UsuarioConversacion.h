#ifndef USUARIOCONVERSACION_H
#define USUARIOCONVERSACION_H

#include <set>
#include "EstadoConversacion.h"
#include "DtConversacion.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "Conversacion.h"

class Conversacion;

class UsuarioConversacion {

    private:
        EstadoConversacion estado;
        Conversacion* conversacion;

    public:
        UsuarioConversacion();
        UsuarioConversacion(EstadoConversacion);

        ~UsuarioConversacion();

        EstadoConversacion getEstado();
        void setEstado(EstadoConversacion);

        DtConversacion obtenerConversacion();
        set<DtMensaje*> obtenerMensajes(int);
        set<DtReceptor*> verInfoMensaje(int);

};

#endif
