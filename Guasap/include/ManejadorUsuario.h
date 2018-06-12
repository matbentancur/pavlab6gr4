#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "Usuario.h"
#include <map>

using namespace std;

class ManejadorUsuario{
    private:
        static ManejadorUsuario* instancia;
        map<string,Usuario*> usuarios;
        ManejadorUsuario();
    public:
        static ManejadorUsuario* getInstancia();
        Usuario* findUsuario(string);
        bool existeUsuario(string);
        bool agregarUsuario(Usuario*);
        virtual ~ManejadorUsuario();
};
#endif
