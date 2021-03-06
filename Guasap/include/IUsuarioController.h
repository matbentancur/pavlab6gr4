#ifndef IUSUARIOCONTROLLER_H
#define IUSUARIOCONTROLLER_H

#include <set>
#include <map>
#include <string>
#include "Sesion.h"
#include "Almacenamiento.h"
#include "DtContacto.h"
#include "EstadoIngreso.h"
#include "FechaHora.h"
#include "Usuario.h"
#include "ManejadorUsuario.h"

using namespace std;

class IUsuarioController {
    public:

        virtual map<string,DtContacto> listarContactos() = 0;
        virtual DtContacto agregarContacto(string) = 0;
        virtual bool confirmarContacto() = 0;
        virtual EstadoIngreso ingresar(string) = 0;
        virtual FechaHora crearUsuario(string,string,string,string) = 0;
        virtual DtContacto modificarUsuario(string,string,string) = 0;
        virtual void cerrarGuasap() = 0;
        virtual bool modificarReloj(FechaHora) = 0;
        virtual FechaHora consultarReloj() = 0;
        virtual void cargarDatosPrueba() = 0;

        virtual ~IUsuarioController() {}
};

#endif // IUSUARIOCONTROLLER_H
