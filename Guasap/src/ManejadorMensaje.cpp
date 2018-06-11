//#include "ManejadorMensaje.h"
//#include <iostream>
//
//ManejadorMensaje* ManejadorMensaje::instancia = NULL;
//
//ManejadorMensaje::ManejadorMensaje(){}
//
//ManejadorMensaje* ManejadorMensaje::getInstancia(){
//    if (ManejadorMensaje::instancia == NULL)
//        ManejadorMensaje::instancia = new ManejadorMensaje();
//    return ManejadorMensaje::instancia;
//}
//
//Mensaje* ManejadorMensaje::findMensaje(int idMensaje){
//    return this->mensajes[idMensaje];
//}
//
//ManejadorMensaje::~ManejadorMensaje(){
//    map<int,Mensaje*>::iterator i;
//    for(i = mensajes.begin(); i !=mensajes.end();++i)
//        delete i->second;
//}
