#include "ConversacionController.h"

ConversacionController::ConversacionController()
{
    //ctor
}

ConversacionController::~ConversacionController()
{
    //dtor
}

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

bool ConversacionController::archivarConversacion(int idConversacion){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->archivarConversacion(idConversacion);
}

bool ConversacionController::seleccionarContactoGrupo(string celular){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    if (this->listaContactosGrupoElegidos.size() == 0){
        listaContactosGrupoRestantes = usuario->obtenerContactos();
    }
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    listaContactosGrupoElegidos.insert(std::pair<string, DtContacto>(celular, contacto->getDtContacto()));
    listaContactosGrupoRestantes.erase(celular);
    return true;
}

//DtConversacion ConversacionController::obtenerConversacion(int){
//
//}
//
//DtConversacion ConversacionController::iniciarConversacion(int){
//
//}
