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

        map<int,DtConversacion*> listarConversacionesActivas();
        map<int,DtConversacion*> listarConversacionesArchivadas();
        bool archivarConversacion(int);
        bool activarConversacion(int);
        bool agregarSeleccionContactoGrupo(string);
        bool quitarSeleccionContactoGrupo(string);
        bool altaGrupo(string,string);
        map<string,DtContacto> listarContactosElegidos();
        map<string,DtContacto> listarContactosRestantes();
};

#endif // CONVERSACIONCONTROLLER_H
