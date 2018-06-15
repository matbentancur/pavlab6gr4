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

        Conversacion* getConversacion();

        DtConversacion obtenerConversacion();
        map<int,DtMensaje> obtenerMensajes();
        set<DtReceptor*> verInfoMensaje(int);

};

#endif
