#include "DtPrivada.h"
#include <iostream>

DtPrivada::DtPrivada()
{
    //ctor
}

DtPrivada::~DtPrivada()
{
    //dtor
}

DtPrivada::DtPrivada(int idConversacion, string nombre, string destino) : DtConversacion(idConversacion, nombre){
    this->destino = destino;
}

string DtPrivada::getDestino(){
    return this->destino;
}

ostream& operator << (ostream& os, DtPrivada& dtPrivada) {
    os <<
        "Celular: " << dtPrivada.destino<< "\n" <<
        "Nombre: " << dtPrivada.getNombre()<< "\n";
    return os;
}
