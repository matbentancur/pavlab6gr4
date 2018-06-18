#ifndef IMENSAJECONTROLLER_H
#define IMENSAJECONTROLLER_H

#include <iostream> //cout
#include <typeinfo> //bad_cast
#include <set>
#include <map>
#include "Sesion.h"
#include "DtMensaje.h"
#include "DtSimple.h"
#include "DtTarjetaContacto.h"
#include "DtImagen.h"
#include "DtVideo.h"
#include "ManejadorUsuario.h"
#include "Simple.h"
#include "TarjetaContacto.h"
#include "Imagen.h"
#include "Video.h"

using namespace std;

class IMensajeController {
    public:
        virtual map<int,DtMensaje> listarMensajes(int) = 0;
        virtual map<string,DtReceptor> verInfoMensajeEnviado(int) = 0;
        virtual bool enviarMensajeConversacion(DtMensaje) = 0;
        virtual bool enviarMensajeNuevaConversacion(DtMensaje) = 0;
        virtual bool eliminarMensaje(int) = 0;

        virtual ~IMensajeController() {}
};

#endif // IMENSAJECONTROLLER_H
