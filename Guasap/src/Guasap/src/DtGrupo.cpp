#include "DtGrupo.h"

DtGrupo::DtGrupo()
{
    //ctor
}

DtGrupo::~DtGrupo()
{
    //dtor
}

DtGrupo::DtGrupo(int idConversacion, string nombre) : DtConversacion(idConversacion){
    this->nombre = nombre;
}

string DtGrupo::getNombre(){
    return this->nombre;
}
