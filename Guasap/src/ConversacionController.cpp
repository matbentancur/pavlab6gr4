#include "ConversacionController.h"

ConversacionController::ConversacionController()
{
    //ctor
}

ConversacionController::~ConversacionController()
{
    //dtor
}

//set<DtConversacion*> ConversacionController::listarConversaciones(){
//
//}
//
map<int,DtConversacion> ConversacionController::listarConversacionesActivas(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerConversacionesActivas();
}

map<int,DtConversacion> ConversacionController::listarConversacionesArchivadas(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerConversacionesArchivadas();
}
//
//bool ConversacionController::archivarConversacion(){
//
//}
//
//void ConversacionController::ingresarIdConversacion(int){
//
//}
//
//DtConversacion ConversacionController::obtenerConversacion(int){
//
//}
//
//DtConversacion ConversacionController::iniciarConversacion(int){
//
//}
