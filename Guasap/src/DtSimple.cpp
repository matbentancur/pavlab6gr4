#include "DtSimple.h"

DtSimple::DtSimple()
{
    //ctor
}

DtSimple::~DtSimple()
{
    //dtor
}

DtSimple::DtSimple(string texto) : DtMensaje(){
    this->texto = texto;
}

DtSimple::DtSimple(int codigo, FechaHora enviado, bool visto, Usuario* emisor, string texto) : DtMensaje(codigo, enviado, visto, emisor){
    this->texto = texto;
}

string DtSimple::getTexto(){
    return this->texto;
}
