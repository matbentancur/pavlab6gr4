#include "Simple.h"

Simple::Simple(int codigo,FechaHora enviado,bool visto,string texto) : Mensaje(codigo, enviado, visto){
    this->texto = texto;
}

string Simple::getTexto(){
    return this->texto;
}

void Simple::setTexto(string texto){
    this->texto = texto;
}

DtMensaje Simple::getDtMensaje(){
    DtSimple dtSimple = DtSimple(this->codigo, this->enviado, this->visto, this->texto);
    return dtSimple;
}

Simple::~Simple(){}

