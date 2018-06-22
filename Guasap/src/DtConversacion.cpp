#include "DtConversacion.h"

DtConversacion::DtConversacion()
{
    //ctor
}

DtConversacion::~DtConversacion()
{
    //dtor
}

DtConversacion::DtConversacion(int idConversacion, string nombre) {
    this->idConversacion = idConversacion;
    this->nombre = nombre;
}

int DtConversacion::getIdConversacion(){
    return this->idConversacion;
}

string DtConversacion::getNombre(){
    return this->nombre;
}

ostream& operator << (ostream& salida, DtConversacion& dtConversacion) {
    salida <<
        dtConversacion.idConversacion << " - " <<
        dtConversacion.nombre << "\n";
    return salida;
}
