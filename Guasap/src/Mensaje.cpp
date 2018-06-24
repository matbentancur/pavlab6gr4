#include "Mensaje.h"
#include "UsuarioMensaje.h"
#include "Sesion.h"
#include "Almacenamiento.h"
#include "ManejadorUsuario.h"

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
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());

    map<string,DtReceptor> listaReceptores;
	set<UsuarioMensaje*>::iterator i;
    for(i = this->usuarioMensaje.begin(); i != this->usuarioMensaje.end(); ++i){
        UsuarioMensaje* um = *i;
        if (um->getUsuario()->getCelular() != usuario->getCelular()){
            DtReceptor dtReceptor = um->getDtReceptor();
            listaReceptores.insert(std::pair<string, DtReceptor>(dtReceptor.getCelular(), dtReceptor));
        }
	}
	return listaReceptores;
}

bool Mensaje::eliminarMensajeLogico(Usuario* usuario){
    set<UsuarioMensaje*>::iterator i;
    for(i = this->usuarioMensaje.begin(); i != this->usuarioMensaje.end(); ++i){
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
    for(i = this->usuarioMensaje.begin(); i != this->usuarioMensaje.end(); ++i){
        UsuarioMensaje* um = *i;
        if(usuario->getCelular() == um->getUsuario()->getCelular()){
            return um->getEliminado();
        }
	}
	return false;
}

void Mensaje::marcarComoVisto(Usuario* usuario){
    if (!this->getVisto()){
        set<UsuarioMensaje*>::iterator i;
        for(i = this->usuarioMensaje.begin(); i != this->usuarioMensaje.end(); ++i){
            UsuarioMensaje* um = *i;
            if(usuario->getCelular() == um->getUsuario()->getCelular()){
                if(!um->getVisto()){
                    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
                    FechaHora vistoFechaHora = almacenamiento->getReloj();
                    um->setVisto(true);
                    um->setVistoFechaHora(vistoFechaHora);
                }
            }
        }
    }
}

void Mensaje::verificarVisto(){
    if (!this->getVisto()){
        unsigned int cantidadDeVistos;
        set<UsuarioMensaje*>::iterator i;
        for(i = this->usuarioMensaje.begin(); i != this->usuarioMensaje.end(); ++i){
            UsuarioMensaje* um = *i;
            if(um->getVisto()){
                cantidadDeVistos++;
            }
        }
        if(cantidadDeVistos == this->usuarioMensaje.size()){
            this->setVisto(true);
        }
    }
}

Mensaje::~Mensaje(){}
