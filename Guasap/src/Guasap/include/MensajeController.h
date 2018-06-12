#ifndef MENSAJECONTROLLER_H
#define MENSAJECONTROLLER_H

#include "IMensajeController.h"

class MensajeController {
    private:
        int idConversacion;

    public:
        MensajeController();
        virtual ~MensajeController();

        set<DtMensaje*> listarMensajes(int);
//        virtual set<DtReceptor*> verInfoMensajeEnviado(int);
        set<DtMensaje*> crearMensajeImagen(DtImagen);
        set<DtMensaje*> crearMensajeSimple(DtSimple);
//        void eliminarMensaje(string,listaMensajes); //ver entrada
};

#endif // MENSAJECONTROLLER_H
