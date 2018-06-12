#include "DtPrivada.h"

DtPrivada::DtPrivada()
{
    //ctor
}

DtPrivada::~DtPrivada()
{
    //dtor
}

DtPrivada::DtPrivada(int idConversacion, string destino, string nombre) : DtConversacion(idConversacion){
    this->destino = destino;
    this->nombre = nombre;
}

string DtPrivada::getDestino(){
    return this->destino;
}

string DtPrivada::getNombre(){
    return this->nombre;
}
