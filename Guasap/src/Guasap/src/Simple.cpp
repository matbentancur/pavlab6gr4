#include "Simple.h"

Simple::Simple(DtSimple &dtSimple){
    this->setCodigo(dtSimple.getCodigo());
    this->setEnviado(dtSimple.getEnviado());
    this->setVisto(dtSimple.getVisto());
    this->setTexto(dtSimple.getTexto());
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

DtMensaje Simple::getDtMensaje(){
    //return this->DtMensaje;
}

Simple::~Simple(){}

