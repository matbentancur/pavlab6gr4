#include "DtPrivada.h"

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
