#include "DtMensaje.h"

DtMensaje::DtMensaje()
{
    //ctor
}

DtMensaje::~DtMensaje()
{
    //dtor
}

DtMensaje::DtMensaje(int codigo, FechaHora enviado, bool visto) {
    this->codigo = codigo;
    this->enviado = enviado;
    this->visto = visto;
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
