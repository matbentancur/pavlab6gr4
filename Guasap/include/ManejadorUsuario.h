#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "Usuario.h"
#include <map>

using namespace std;

class ManejadorUsuario{
    private:
        static ManejadorUsuario* instancia;
        map<int,Usuario*> usuarios;
        ManejadorUsuario();
    public:
        static ManejadorUsuario* getInstancia();
        Usuario* findUsuario(int);
        void agregarUsuario(Usuario*);
        virtual ~ManejadorUsuario();
};
#endif
