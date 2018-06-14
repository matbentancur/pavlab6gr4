#ifndef CONVERSACIONCONTROLLER_H
#define CONVERSACIONCONTROLLER_H

#include "IConversacionController.h"

class ConversacionController : public IConversacionController {
    public:
        ConversacionController();
        virtual ~ConversacionController();

        set<DtConversacion*> listarConversaciones();
        map<int,DtConversacion> listarConversacionesActivas();
        map<int,DtConversacion> listarConversacionesArchivadas();
        bool archivarConversacion();
        void ingresarIdConversacion(int);
        DtConversacion obtenerConversacion(int);
        DtConversacion iniciarConversacion(int);
};

#endif // CONVERSACIONCONTROLLER_H
