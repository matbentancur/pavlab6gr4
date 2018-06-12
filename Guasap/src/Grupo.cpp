#include "Grupo.h"

Grupo::Grupo(int idConversacion,string origen,string nombre,string urlImagen,FechaHora creacion) : Conversacion(idConversacion, origen){
    this->nombre         = nombre;
    this->urlImagen      = urlImagen;
    this->creacion       = creacion;
}

string Grupo::getNombre(){
    return this->nombre;
}

string Grupo::getUrlImagen(){
    return this->urlImagen;
}

FechaHora Grupo::getCreacion(){
    return this->creacion;
}

void Grupo::setNombre(string nombre){
    this->nombre = nombre;
}

void Grupo::setUrlImagen(string urlImagen){
    this->urlImagen = urlImagen;
}

void Grupo::setCreacion(FechaHora creacion){
    this->creacion = creacion;
}
/*
DtGrupo Grupo::getDtConversacion(){

}
*/
Grupo::~Grupo(){}
