#include "Privada.h"
#include "Usuario.h"
#include "UsuarioMensaje.h"
#include "Mensaje.h"
#include "Sesion.h"
#include "ManejadorUsuario.h"

Privada::Privada(int idConversacion, Usuario* origen, Usuario* destino) : Conversacion(idConversacion, origen){
    this->destino = destino;
}

Usuario* Privada::getDestino(){
    return this->destino;
}

void Privada::setDestino(Usuario* destino){
    this->destino = destino;
}

DtConversacion* Privada::getDtConversacion(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    string nombre;
    if(usuario->getCelular() != this->destino->getCelular()){
        nombre = this->destino->getNombre() + " - " + this->destino->getCelular();
    }
    else{
        nombre = this->origen->getNombre() + " - " + this->origen->getCelular();
    }
    DtPrivada* dtPrivada = new DtPrivada(this->idConversacion, nombre, this->destino->getCelular());
    return dtPrivada;
}

bool Privada::agregrarMensaje(Mensaje* nuevoMensaje){
    if (nuevoMensaje->getEmisor()->getCelular() == this->getDestino()->getCelular()){
        UsuarioMensaje* usuarioMensaje = new UsuarioMensaje(false, false, this->getOrigen());
        nuevoMensaje->agregarUsuarioMensaje(usuarioMensaje);
    }
    else{
        UsuarioMensaje* usuarioMensaje = new UsuarioMensaje(false, false, this->getDestino());
        nuevoMensaje->agregarUsuarioMensaje(usuarioMensaje);
    }
    mensajes.insert(std::pair<int, Mensaje*>(nuevoMensaje->getCodigo(), nuevoMensaje));
	return true;
}

Privada::~Privada(){}


