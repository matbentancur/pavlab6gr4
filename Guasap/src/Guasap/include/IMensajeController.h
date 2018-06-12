#ifndef IMENSAJECONTROLLER_H
#define IMENSAJECONTROLLER_H

#include <set>
#include "DtMensaje.h"
#include "DtImagen.h"
#include "DtSimple.h"

using namespace std;

class IMensajeController {
    public:
        virtual set<DtMensaje*> listarMensajes(int) = 0;
//        virtual set<DtReceptor*> verInfoMensajeEnviado(int) = 0;
        virtual set<DtMensaje*> crearMensajeImagen(DtImagen) = 0;
        virtual set<DtMensaje*> crearMensajeSimple(DtSimple) = 0;
//        virtual void eliminarMensaje(string,listaMensajes) = 0; //ver entrada

        virtual ~IMensajeController() {}
};

#endif // IMENSAJECONTROLLER_H
