#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include <set>
#include "DtContacto.h"
#include "EstadoIngreso.h"
#include "FechaHora.h"

using namespace std;

class IUsuarioController {
    public:

        virtual set<DtContacto*> listarContactos() = 0;
        virtual DtContacto agregarContacto(string) = 0;
        virtual bool confirmarContacto() = 0;
        virtual EstadoIngreso ingresar(string) = 0;
        virtual FechaHora crearUsuario(string,string,string) = 0;
        virtual void cerrarGuasap(string) = 0;

        virtual ~IUsuarioController() {}
};

#endif // IUSUARIOCONTROLLER_H
