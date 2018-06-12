#include "ManejadorUsuario.h"
#include <iostream>

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (ManejadorUsuario::instancia == NULL)
        ManejadorUsuario::instancia = new ManejadorUsuario();
    return ManejadorUsuario::instancia;
}

Usuario* ManejadorUsuario::findUsuario(int idUsuario){
    return this->usuarios[idUsuario];
}

bool ManejadorUsuario::existeUsuario(int idUsuario){
    if(findUsuario(idUsuario) == NULL){
        return false;
    }else{
        return true;
    }
}

ManejadorUsuario::~ManejadorUsuario(){
    map<int,Usuario*>::iterator i;
    for(i = usuarios.begin(); i !=usuarios.end();++i)
        delete i->second;
}
