#ifndef CONVERSACIONCONTROLLER_H
#define CONVERSACIONCONTROLLER_H

#include "IConversacionController.h"

class ConversacionController : public IConversacionController {

    private:
        int ultimoIdConversacion;
        map<string,DtContacto> listaContactosGrupoElegidos;
        map<string,DtContacto> listaContactosGrupoRestantes;

    public:
        ConversacionController();
        virtual ~ConversacionController();

        int getUltimoIdConversacion();
        void setUltimoIdConversacion(int);

        map<int,DtConversacion> listarConversacionesActivas();
        map<int,DtConversacion> listarConversacionesArchivadas();
        bool archivarConversacion(int);
        bool agregarSeleccionContactoGrupo(string);
        bool quitarSeleccionContactoGrupo(string);
        bool altaGrupo(string,string);

        DtConversacion iniciarConversacion(int);
};

#endif // CONVERSACIONCONTROLLER_H
