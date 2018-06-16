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

int MensajeController::getUltimoCodigoMensaje(){
    return this->ultimoCodigoMensaje;
}

void MensajeController::setUltimoCodigoMensaje(int codigoMensaje){
    this->ultimoCodigoMensaje = codigoMensaje;
}

map<int,DtMensaje> MensajeController::listarMensajes(int idConversacion){
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

bool MensajeController::enviarMensajeConversacion(DtMensaje nuevoMensaje){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());

//    try{
//        DtSimple dtMensaje = dynamic_cast<DtSimple>(nuevoMensaje);
//    }catch(std::bad_cast){
//        cout << "Error en cast para Simple\n";
//    }

//    usuario->enviarMensajeConversacion(this->idConversacion, mensaje);
    return true;
}

bool MensajeController::enviarMensajeNuevaConversacion(DtMensaje){
    return true;
}
