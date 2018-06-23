#ifndef IMENSAJECONTROLLER_H
#define IMENSAJECONTROLLER_H

#include <iostream> //cout
#include <typeinfo> //bad_cast
#include <set>
#include <map>
#include "Sesion.h"
#include "Almacenamiento.h"
#include "DtMensaje.h"
#include "ManejadorUsuario.h"

using namespace std;

class IMensajeController {
    public:
        virtual map<int,DtMensaje*> listarMensajes(int) = 0;
        virtual map<string,DtReceptor> verInfoMensajeEnviado(int) = 0;
        virtual bool enviarMensajeConversacion(int, DtMensaje*) = 0;
        virtual bool enviarMensajeNuevaConversacion(string, DtMensaje*) = 0;
        virtual bool eliminarMensaje(int) = 0;

        virtual ~IMensajeController() {}
};

#endif // IMENSAJECONTROLLER_H
