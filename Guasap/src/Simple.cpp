#include "Simple.h"

Simple::Simple(int codigo,FechaHora enviado,bool visto,Usuario* emisor,string texto) : Mensaje(codigo, enviado, visto, emisor){
    this->texto = texto;
}

string Simple::getTexto(){
    return this->texto;
}

void Simple::setTexto(string texto){
    this->texto = texto;
}

DtMensaje Simple::getDtMensaje(){
    DtSimple dtSimple = DtSimple(this->codigo, this->enviado, this->visto, this->emisor, this->texto);
    return dtSimple;
}

Simple::~Simple(){}

