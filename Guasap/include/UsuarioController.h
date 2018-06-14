#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

#include "IUsuarioController.h"

class UsuarioController : public IUsuarioController {
    private:
        string celularContacto;

    public:
        UsuarioController();
        virtual ~UsuarioController();

        map<string,DtContacto> listarContactos();
        DtContacto agregarContacto(string);
        bool confirmarContacto();
        EstadoIngreso ingresar(string);
        FechaHora crearUsuario(string,string,string,string);
        void modificarUsuario(string,string,string);
        void cerrarGuasap(string);
};

#endif // USUARIOCONTROLLER_H
