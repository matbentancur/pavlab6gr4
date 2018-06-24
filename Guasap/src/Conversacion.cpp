#include "Conversacion.h"
#include "Mensaje.h"
#include "Sesion.h"
#include "ManejadorUsuario.h"

Conversacion::Conversacion(int idConversacion, Usuario* origen){
     this->idConversacion = idConversacion;
     this->origen = origen;
}

int Conversacion::getIdConversacion(){
    return this->idConversacion;
}

void Conversacion::setIdConversacion(int idConversacion){
        this->idConversacion = idConversacion;
}

Usuario* Conversacion::getOrigen(){
    return this->origen;
}

void Conversacion::setOrigen(Usuario* origen){
        this->origen = origen;
}

map<int,DtMensaje*> Conversacion::getMensajes(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());

    map<int,DtMensaje*> listaMensajes;
	map<int,Mensaje*>::iterator i;
    for(i = mensajes.begin(); i != mensajes.end(); ++i){
        Mensaje * mensaje = i->second;
        if (!mensaje->estaEliminado(usuario)){
            mensaje->marcarComoVisto(usuario);
            DtMensaje* dtMensaje = mensaje->getDtMensaje();
            listaMensajes.insert(std::pair<int, DtMensaje*>(mensaje->getCodigo(), dtMensaje));
        }
	}
	return listaMensajes;
}

map<string,DtReceptor> Conversacion::verInfoMensaje(int codigo){
    map<string,DtReceptor> listaReceptores;
	map<int,Mensaje*>::iterator i;
    for(i = mensajes.begin(); i != mensajes.end(); ++i){
        Mensaje * mensaje = i->second;
        if (mensaje->getCodigo() == codigo){
            listaReceptores = mensaje->getReceptores();
        }
	}
	return listaReceptores;
}

bool Conversacion::eliminarMensaje(int codigoMensaje){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());

    map<int,Mensaje*>::iterator i;
    i = this->mensajes.find(codigoMensaje);
    if (i != mensajes.end()){
        Mensaje* mensaje = i->second;
        if(usuario->getCelular() == mensaje->getEmisor()->getCelular()){
            mensajes.erase(i);
            return true;
        }
        else{
            return mensaje->eliminarMensajeLogico(usuario);
        }
    }
    return false;
}

Conversacion::~Conversacion(){}
