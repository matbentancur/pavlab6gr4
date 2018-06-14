#ifndef ICONVERSACIONCONTROLLER_H
#define ICONVERSACIONCONTROLLER_H

#include <set>
#include <map>
#include "Sesion.h"
#include "DtConversacion.h"
#include "ManejadorUsuario.h"

using namespace std;

class IConversacionController {
    public:
//        virtual set<DtConversacion*> listarConversaciones() = 0;
        virtual map<int,DtConversacion> listarConversacionesActivas() = 0;
        virtual map<int,DtConversacion> listarConversacionesArchivadas() = 0;
//        virtual bool archivarConversacion() = 0;
//        virtual void ingresarIdConversacion(int) = 0;
//        virtual DtConversacion obtenerConversacion(int) = 0;
//        virtual DtConversacion iniciarConversacion(int) = 0;

        virtual ~IConversacionController(){};
};

#endif // ICONVERSACIONCONTROLLER_H
