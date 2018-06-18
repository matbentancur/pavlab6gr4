#include "Privada.h"
#include "Usuario.h"
#include "UsuarioMensaje.h"
#include "Mensaje.h"

Privada::Privada(int idConversacion, string nombre, Usuario* origen, Usuario* destino) : Conversacion(idConversacion, nombre, origen){
    this->destino = destino;
}

Usuario* Privada::getDestino(){
    return this->destino;
}

void Privada::setDestino(Usuario* destino){
    this->destino = destino;
}

DtConversacion Privada::getDtConversacion(){
    DtPrivada dtPrivada = DtPrivada(this->idConversacion, this->nombre, this->destino->getCelular());
    return dtPrivada;
}

bool Privada::agregrarMensaje(Mensaje* nuevoMensaje){
    if (nuevoMensaje->getEmisor()->getCelular() == this->getDestino()->getCelular()){
        UsuarioMensaje* usuarioMensaje = new UsuarioMensaje(false, this->getOrigen());
        nuevoMensaje->agregarUsuarioMensaje(usuarioMensaje);
    }
    else{
        UsuarioMensaje* usuarioMensaje = new UsuarioMensaje(false, this->getDestino());
        nuevoMensaje->agregarUsuarioMensaje(usuarioMensaje);
    }
    mensajes.insert(std::pair<int, Mensaje*>(nuevoMensaje->getCodigo(), nuevoMensaje));
	return true;
}

Privada::~Privada(){}


