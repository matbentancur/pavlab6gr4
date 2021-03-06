#ifndef ICONVERSACIONCONTROLLER_H
#define ICONVERSACIONCONTROLLER_H

#include <set>
#include <map>
#include "Sesion.h"
#include "Almacenamiento.h"
#include "DtConversacion.h"
#include "ManejadorUsuario.h"
#include "Grupo.h"
#include "UsuarioConversacion.h"

using namespace std;

class IConversacionController {
    public:
        virtual map<int,DtConversacion*> listarConversacionesActivas() = 0;
        virtual map<int,DtConversacion*> listarConversacionesArchivadas() = 0;
        virtual bool archivarConversacion(int) = 0;
        virtual bool activarConversacion(int) = 0;
        virtual bool agregarSeleccionContactoGrupo(string) = 0;
        virtual bool quitarSeleccionContactoGrupo(string) = 0;
        virtual bool altaGrupo(string,string) = 0;
        virtual map<string,DtContacto> listarContactosElegidos() = 0;
        virtual map<string,DtContacto> listarContactosRestantes() = 0;
        virtual ~IConversacionController(){};
};

#endif // ICONVERSACIONCONTROLLER_H
