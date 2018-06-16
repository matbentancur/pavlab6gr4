#include "DtMensaje.h"

DtMensaje::DtMensaje()
{
    //ctor
}

DtMensaje::~DtMensaje()
{
    //dtor
}

DtMensaje::DtMensaje(int codigo, FechaHora enviado, bool visto, Usuario* emisor) {
    this->codigo = codigo;
    this->enviado = enviado;
    this->visto = visto;
    this->emisor = emisor;
}

int DtMensaje::getCodigo(){
    return this->codigo;
}

FechaHora DtMensaje::getEnviado(){
    return this->enviado;
}

bool DtMensaje::getVisto(){
    return this->visto;
}

Usuario* DtMensaje::getEmisor(){
    return this->emisor;
}
