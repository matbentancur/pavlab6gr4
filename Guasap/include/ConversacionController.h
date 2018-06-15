#ifndef CONVERSACIONCONTROLLER_H
#define CONVERSACIONCONTROLLER_H

#include "IConversacionController.h"

class ConversacionController : public IConversacionController {

    private:
        map<string,DtContacto> listaContactosGrupoElegidos;
        map<string,DtContacto> listaContactosGrupoRestantes;

    public:
        ConversacionController();
        virtual ~ConversacionController();

        map<int,DtConversacion> listarConversacionesActivas();
        map<int,DtConversacion> listarConversacionesArchivadas();
        bool archivarConversacion(int);
        bool seleccionarContactoGrupo(string);

        DtConversacion obtenerConversacion(int);
        DtConversacion iniciarConversacion(int);
};

#endif // CONVERSACIONCONTROLLER_H
