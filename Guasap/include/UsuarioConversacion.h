#ifndef USUARIOCONVERSACION_H
#define USUARIOCONVERSACION_H

#include <set>
#include "EstadoConversacion.h"
#include "DtContacto.h"
#include "DtMensaje.h"
#include "DtReceptor.h"

class UsuarioConversacion {

    private:
        EstadoConversacion estadoConversacion;

    public:
        UsuarioConversacion();
        UsuarioConversacion(EstadoConversacion);

        ~UsuarioConversacion();

        EstadoConversacion getEstadoConversacion();
        void setEstadoConversacion(EstadoConversacion);

        DtContacto obtenerConversacion();
        set<DtMensaje*> obtenerMensajes(int);
        set<DtReceptor*> verInfoMensaje(int);

};

#endif
