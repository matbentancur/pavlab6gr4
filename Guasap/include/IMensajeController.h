#ifndef IMENSAJECONTROLLER_H
#define IMENSAJECONTROLLER_H

#include <set>
#include <map>
#include "Sesion.h"
#include "DtMensaje.h"
#include "DtImagen.h"
#include "DtSimple.h"
#include "ManejadorUsuario.h"

using namespace std;

class IMensajeController {
    public:
        virtual map<int,DtMensaje> listarMensajes(int) = 0;
        virtual map<string,DtReceptor> verInfoMensajeEnviado(int) = 0;
        virtual bool enviarMensajeConversacion(DtMensaje) = 0;
        virtual bool enviarMensajeNuevaConversacion(DtMensaje) = 0;
//        virtual set<DtMensaje*> crearMensajeImagen(DtImagen) = 0;
//        virtual set<DtMensaje*> crearMensajeSimple(DtSimple) = 0;
////        virtual void eliminarMensaje(string,listaMensajes) = 0; //ver entrada

        virtual ~IMensajeController() {}
};

#endif // IMENSAJECONTROLLER_H
