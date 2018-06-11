#ifndef MANEJADORUSUARIOCONVERSACTION
#define MANEJADORUSUARIOCONVERSACTION

#include "UsuarioConversacion.h"
#include <map>

using namespace std;

class ManejadorUsuarioConversacion{
    private:
        static ManejadorUsuarioConversacion* instancia;
        //map<int,Conversacion*> conversaciones;
        ManejadorUsuarioConversacion();
    public:
        static ManejadorUsuarioConversacion* getInstancia();
        //Conversacion* findConversacion(int);
        //void agregarConversacion(Conversacion*);
        virtual ~ManejadorUsuarioConversacion();
};
#endif
