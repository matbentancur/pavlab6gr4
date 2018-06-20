#include "DtGrupo.h"

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

ostream& operator << (ostream& salida, DtGrupo& dtGrupo) {
    salida <<
        "ID: " << dtGrupo.idConversacion << "\n" <<
        "Nombre: " << dtGrupo.nombre << "\n" <<
        "URL Imagen: " << dtGrupo.urlImagen << "\n" <<
        "Creacion: " << dtGrupo.creacion << "\n";
    return salida;
}
