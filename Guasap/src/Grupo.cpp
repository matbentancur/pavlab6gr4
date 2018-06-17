#include "Grupo.h"
#include "Usuario.h"

Grupo::Grupo(int idConversacion,string nombre,Usuario* origen,string urlImagen,FechaHora creacion) : Conversacion(idConversacion, nombre, origen){
    this->urlImagen = urlImagen;
    this->creacion = creacion;
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

DtConversacion Grupo::getDtConversacion(){
    DtGrupo dtGrupo = DtGrupo(this->idConversacion, this->nombre, this->urlImagen, this->creacion);
    return dtGrupo;
}

Grupo::~Grupo(){}
