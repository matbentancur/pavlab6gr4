#include "Simple.h"

Simple::Simple(DtSimple &dtSimple){
    this->setCodigo(dtSimple.getCodigo());
    this->setEnviado(dtSimple.getEnviado());
    this->setVisto(dtSimple.getVisto());
    this->texto = texto;
}

Simple::Simple(int codigo,FechaHora enviado,bool visto,string texto){
    this->setCodigo(codigo);
    this->setEnviado(enviado);
    this->setVisto(visto);
    this->texto = texto;
}

string Simple::getTexto(){
    return this->texto;
}

void Simple::setTexto(string texto){
    this->texto = texto;
}

DtMensaje getDtMensaje(){
    //return this->DtMensaje;
}

Simple::~Simple(){}

