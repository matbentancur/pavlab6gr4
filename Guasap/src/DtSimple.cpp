#include "DtSimple.h"

DtSimple::DtSimple()
{
    //ctor
}

DtSimple::~DtSimple()
{
    //dtor
}

DtSimple::DtSimple(int codigo, FechaHora enviado, bool visto, string texto) : DtMensaje(codigo, enviado, visto){
    this->texto = texto;
}

string DtSimple::getTexto(){
    return this->texto;
}
