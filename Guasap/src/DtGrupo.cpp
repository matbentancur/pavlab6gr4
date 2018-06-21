#include "DtGrupo.h"
#include <iostream>

DtGrupo::DtGrupo()
{
    //ctor
}

DtGrupo::~DtGrupo()
{
    //dtor
}

DtGrupo::DtGrupo(int idConversacion, string nombre, string urlImagen, FechaHora creacion) : DtConversacion(idConversacion, nombre){
    this->urlImagen = urlImagen;
    this->creacion = creacion;
}

string DtGrupo::getUrlImagen(){
    return this->urlImagen;
}

FechaHora DtGrupo::getCreacion(){
    return this->creacion;
}

ostream& operator << (ostream& os, DtGrupo& dtGrupo) {
    os <<
        "Nombre: " << dtGrupo.getNombre()<< "\n";
    return os;
}
