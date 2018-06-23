#include "Mensaje.h"
#include "UsuarioMensaje.h"

Mensaje::Mensaje(){

}

Mensaje::Mensaje(int codigo,FechaHora enviado,bool visto, Usuario* emisor){
    this->codigo  = codigo;
    this->enviado = enviado;
    this->visto = visto;
    this->emisor = emisor;
}

int Mensaje::getCodigo(){
        return this->codigo;
}

void Mensaje::setCodigo(int codigo){
    this->codigo = codigo;
}

FechaHora Mensaje::getEnviado(){
        return this->enviado;
}

void Mensaje::setEnviado(FechaHora enviado){
    this->enviado = enviado;
}

bool Mensaje::getVisto(){
        return this->visto;
}

void Mensaje::setVisto(bool visto){
    this->visto = visto;
}

Usuario* Mensaje::getEmisor(){
        return this->emisor;
}

void Mensaje::setEmisor(Usuario* emisor){
    this->emisor = emisor;
}

bool Mensaje::agregarUsuarioMensaje(UsuarioMensaje* um){
    this->usuarioMensaje.insert(um);
	return true;
}

map <string,DtReceptor> Mensaje::getReceptores(){
    map<string,DtReceptor> listaReceptores;
	set<UsuarioMensaje*>::iterator i;
    for(i = usuarioMensaje.begin(); i != usuarioMensaje.end(); ++i){
        UsuarioMensaje* um = *i;
        DtReceptor dtReceptor = um->getDtReceptor();
        listaReceptores.insert(std::pair<string, DtReceptor>(dtReceptor.getCelular(), dtReceptor));
	}
	return listaReceptores;
}

bool Mensaje::eliminarMensajeLogico(Usuario* usuario){
    set<UsuarioMensaje*>::iterator i;
    for(i = usuarioMensaje.begin(); i != usuarioMensaje.end(); ++i){
        UsuarioMensaje* um = *i;
        if(usuario->getCelular() == um->getUsuario()->getCelular()){
            um->setEliminado(true);
            return true;
        }
	}
	return false;
}

bool Mensaje::estaEliminado(Usuario* usuario){
    set<UsuarioMensaje*>::iterator i;
    for(i = usuarioMensaje.begin(); i != usuarioMensaje.end(); ++i){
        UsuarioMensaje* um = *i;
        if(usuario->getCelular() == um->getUsuario()->getCelular()){
            return um->getEliminado();
        }
	}
	return false;
}

Mensaje::~Mensaje(){}
