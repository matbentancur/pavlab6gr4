#ifndef CONVERSACIONCONTROLLER_H
#define CONVERSACIONCONTROLLER_H

#include "IConversacionController.h"

class ConversacionController : public IConversacionController {
    public:
        ConversacionController();
        virtual ~ConversacionController();

        set<DtConversacion*> listarConversaciones();
        set<DtConversacion*> listarConversacionesActivas();
        set<DtConversacion*> listarConversacionesArchivadas();
        bool archivarConversacion();
        void ingresarIdConversacion(int);
        DtConversacion obtenerConversacion(int);
        DtConversacion iniciarConversacion(int);
};

#endif // CONVERSACIONCONTROLLER_H
