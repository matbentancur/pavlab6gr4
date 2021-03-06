#ifndef USUARIOCONVERSACION_H
#define USUARIOCONVERSACION_H

#include <iostream> //cout
#include <typeinfo> //bad_cast
#include <set>
#include <map>
#include "EstadoConversacion.h"
#include "DtConversacion.h"
#include "DtPrivada.h"
#include "DtGrupo.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "Conversacion.h"
#include "Privada.h"
#include "Grupo.h"
#include "Mensaje.h"

class Conversacion;

class UsuarioConversacion {

    private:
        FechaHora agregadoEnConversacion;
        EstadoConversacion estado;
        Conversacion* conversacion;

    public:
        UsuarioConversacion(FechaHora, EstadoConversacion, Conversacion*);

        ~UsuarioConversacion();

        FechaHora getAgregadoEnConversacion();
        void setAgregadoEnConversacion(FechaHora);

        EstadoConversacion getEstado();
        void setEstado(EstadoConversacion);

        Conversacion* getConversacion();
        void setConversacion(Conversacion*);

        DtConversacion* obtenerConversacion();
        map<int,DtMensaje*> obtenerMensajes();
        map<string,DtReceptor> verInfoMensaje(int);

        bool enviarMensajeConversacion(Mensaje*);
        bool eliminarMensaje(int);
};

#endif
