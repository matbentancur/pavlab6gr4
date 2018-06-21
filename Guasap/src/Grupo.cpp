#include "Grupo.h"
#include "Usuario.h"
#include "Mensaje.h"
#include "UsuarioMensaje.h"

Grupo::Grupo(int idConversacion, Usuario* origen, string nombre, string urlImagen, FechaHora creacion) : Conversacion(idConversacion, origen){
    this->nombre = nombre;
    this->urlImagen = urlImagen;
    this->creacion = creacion;
}

string Grupo::getNombre(){
    return this->nombre;
}

void Grupo::setNombre(string nombre){
    this->nombre = nombre;
}

string Grupo::getUrlImagen(){
    return this->urlImagen;
}

void Grupo::setUrlImagen(string urlImagen){
    this->urlImagen = urlImagen;
}

FechaHora Grupo::getCreacion(){
    return this->creacion;
}

void Grupo::setCreacion(FechaHora creacion){
    this->creacion = creacion;
}

bool Grupo::agregarAdministrador(Usuario* administrador){
    this->administradores.insert(pair<string, Usuario*>(administrador->getCelular(), administrador));
    return true;
}

bool Grupo::agregarReceptor(Usuario* receptor){
    this->receptores.insert(pair<string, Usuario*>(receptor->getCelular(), receptor));
    return true;
}

DtConversacion* Grupo::getDtConversacion(){
    DtConversacion* dtGrupo = new DtGrupo(this->idConversacion, this->nombre, this->urlImagen, this->creacion);
    return dtGrupo;
}

bool Grupo::agregrarMensaje(Mensaje* nuevoMensaje){
    map<string,Usuario*>::iterator i;
    for(i = this->receptores.begin(); i != this->receptores.end(); ++i){
        Usuario* receptor = i->second;
        if (nuevoMensaje->getEmisor()->getCelular() != receptor->getCelular()){
            UsuarioMensaje* usuarioMensaje = new UsuarioMensaje(false, false, receptor);
            nuevoMensaje->agregarUsuarioMensaje(usuarioMensaje);
        }
	}
    mensajes.insert(std::pair<int, Mensaje*>(nuevoMensaje->getCodigo(), nuevoMensaje));
	return true;
}

Grupo::~Grupo(){}
