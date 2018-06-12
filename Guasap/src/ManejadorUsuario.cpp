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

bool ManejadorUsuario::agregarUsuario(Usuario* usuario){
    map<string,Usuario*>::iterator i;
    i = this->usuarios.find(usuario->getCelular());
    if (i != this->usuarios.end()){
        return false;
    }
    this->usuarios.insert(pair<string, Usuario*>(usuario->getCelular(), usuario));
    return true;
}

bool ManejadorUsuario::existeUsuario(string idUsuario){
    if(findUsuario(idUsuario) == NULL){
        return false;
    }else{
        return true;
    }
}

ManejadorUsuario::~ManejadorUsuario(){
    map<string,Usuario*>::iterator i;
    for(i = usuarios.begin(); i !=usuarios.end();++i)
        delete i->second;
}
