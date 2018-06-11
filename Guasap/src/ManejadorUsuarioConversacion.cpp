#include "ManejadorUsuarioConversacion.h"
#include <iostream>

ManejadorUsuarioConversacion* ManejadorUsuarioConversacion::instancia = NULL;

ManejadorUsuarioConversacion::ManejadorUsuarioConversacion(){}

ManejadorUsuarioConversacion* ManejadorUsuarioConversacion::getInstancia(){
    if (ManejadorUsuarioConversacion::instancia == NULL)
        ManejadorUsuarioConversacion::instancia = new ManejadorUsuarioConversacion();
    return ManejadorUsuarioConversacion::instancia;
}

//Conversacion* ManejadorUsuarioConversacion::findConversacion(int idConversacion){
//    return this->conversaciones[idConversacion];
//}

ManejadorUsuarioConversacion::~ManejadorUsuarioConversacion(){
//    map<int,Conversacion*>::iterator i;
//    for(i = conversaciones.begin(); i !=conversaciones.end();++i)
//        delete i->second;
}
