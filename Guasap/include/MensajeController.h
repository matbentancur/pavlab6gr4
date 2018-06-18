#ifndef MENSAJECONTROLLER_H
#define MENSAJECONTROLLER_H

#include "IMensajeController.h"

class MensajeController : public IMensajeController{

    private:
        int idConversacion;
        int ultimoCodigoMensaje;

    public:
        MensajeController();
        virtual ~MensajeController();

        int getIdConversacion();
        void setIdConversacion(int);

        int getUltimoCodigoMensaje();
        void setUltimoCodigoMensaje(int);

        map<int,DtMensaje> listarMensajes(int);
        map<string,DtReceptor> verInfoMensajeEnviado(int);
        bool enviarMensajeConversacion(DtMensaje);
        bool enviarMensajeNuevaConversacion(DtMensaje);

        bool eliminarMensaje(int);
};

#endif // MENSAJECONTROLLER_H
