#include "MensajeController.h"

MensajeController::MensajeController()
{
    //ctor
}

MensajeController::~MensajeController()
{
    //dtor
}

int MensajeController::getIdConversaion(){
    return this->idConversacion;
}

void MensajeController::setIdConversaion(int idConversacion){
    this->idConversacion = idConversacion;
}

map<int,DtMensaje> MensajeController::listarMensajes(int idConversacion){
    this->setIdConversaion(idConversacion);
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerMensajes(this->getIdConversaion());
}
