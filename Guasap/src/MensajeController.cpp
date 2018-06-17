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

    Mensaje* mensaje;
    bool mensajeCreado = false;

    try{
        DtSimple& dtMensaje = dynamic_cast<DtSimple&>(nuevoMensaje);
        int nuevoCodigoMensaje = this->getUltimoCodigoMensaje() + 1;
        FechaHora enviado = FechaHora(10,10,10,10,10);
        mensaje = new Simple(nuevoCodigoMensaje, enviado, false, usuario, dtMensaje.getTexto());
        mensajeCreado = true;
    }catch(std::bad_cast){
        cout << "Error en cast para Simple\n";
    }

    try{
        DtTarjetaContacto& dtMensaje = dynamic_cast<DtTarjetaContacto&>(nuevoMensaje);
        int nuevoCodigoMensaje = this->getUltimoCodigoMensaje() + 1;
        FechaHora enviado = FechaHora(10,10,10,10,10);
        mensaje = new TarjetaContacto(nuevoCodigoMensaje, enviado, false, usuario, dtMensaje.getNombre(), dtMensaje.getTelefono());
        mensajeCreado = true;
    }catch(std::bad_cast){
        cout << "Error en cast para Tarjeta de Contacto\n";
    }

    try{
        DtImagen& dtMensaje = dynamic_cast<DtImagen&>(nuevoMensaje);
        int nuevoCodigoMensaje = this->getUltimoCodigoMensaje() + 1;
        FechaHora enviado = FechaHora(10,10,10,10,10);
        mensaje = new Imagen(nuevoCodigoMensaje, enviado, false, usuario, dtMensaje.getUrl(), dtMensaje.getFormato(), dtMensaje.getTexto(), dtMensaje.getTamanio());
        mensajeCreado = true;
    }catch(std::bad_cast){
        cout << "Error en cast para Imagen\n";
    }

    try{
        DtVideo& dtMensaje = dynamic_cast<DtVideo&>(nuevoMensaje);
        int nuevoCodigoMensaje = this->getUltimoCodigoMensaje() + 1;
        FechaHora enviado = FechaHora(10,10,10,10,10);
        mensaje = new Video(nuevoCodigoMensaje, enviado, false, usuario, dtMensaje.getUrl(), dtMensaje.getDuracion());
    }catch(std::bad_cast){
        cout << "Error en cast para Video\n";
    }

    if (mensajeCreado){
        usuario->enviarMensajeConversacion(this->idConversacion, mensaje);
        return true;
    }
    return false;
}

bool MensajeController::enviarMensajeNuevaConversacion(DtMensaje){
    return true;
}
