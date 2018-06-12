#include "DtConversacion.h"

DtConversacion::DtConversacion()
{
    //ctor
}

DtConversacion::~DtConversacion()
{
    //dtor
}

DtConversacion::DtConversacion(int idConversacion) {
    this->idConversacion = idConversacion;
}

int DtConversacion::getIdConversacion(){
    return this->idConversacion;
}
