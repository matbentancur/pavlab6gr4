#include "ManejadorUsuario.h"
#include <iostream>

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (ManejadorUsuario::instancia == NULL)
        ManejadorUsuario::instancia = new ManejadorUsuario();
    return ManejadorUsuario::instancia;
}

Usuario* ManejadorUsuario::findUsuario(string celular){
    return this->usuarios[celular];
}

ManejadorUsuario::~ManejadorUsuario(){
    map<string,Usuario*>::iterator i;
    for(i = usuarios.begin(); i !=usuarios.end();++i)
        delete i->second;
}
