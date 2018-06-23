#include "MensajeController.h"

MensajeController::MensajeController()
{
    //ctor
}

MensajeController::~MensajeController()
{
    //dtor
}

int MensajeController::getIdConversacion(){
    return this->idConversacion;
}

void MensajeController::setIdConversacion(int idConversacion){
    this->idConversacion = idConversacion;
}

map<int,DtMensaje*> MensajeController::listarMensajes(int idConversacion){
    this->setIdConversacion(idConversacion);
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerMensajes(this->getIdConversacion());
}

map<string,DtReceptor> MensajeController::verInfoMensajeEnviado(int codigo){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->verInfoMensaje(this->getIdConversacion(), codigo);
}

bool MensajeController::enviarMensajeConversacion(int idConversacion, DtMensaje* nuevoMensaje){
    this->setIdConversacion(idConversacion);
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->enviarMensajeConversacion(this->idConversacion, usuario, nuevoMensaje);
}

bool MensajeController::enviarMensajeNuevaConversacion(string destino, DtMensaje* nuevoMensaje){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuarioOrigen = manejadorUsuario->findUsuario(sesion->getSesion());
    Usuario* usuarioDestino = manejadorUsuario->findUsuario(destino);
    return usuarioOrigen->enviarMensajeNuevaConversacion(usuarioOrigen, usuarioDestino, nuevoMensaje);
}

bool MensajeController::eliminarMensaje(int codigoMensaje){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->eliminarMensaje(this->idConversacion, codigoMensaje);
}
