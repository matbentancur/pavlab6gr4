#include "Imagen.h"

Imagen::Imagen(DtImagen &dtImagen){
    this->setUrl(dtImagen.getUrl());
    this->setFormato(dtImagen.getFormato());
    this->setTexto(dtImagen.getTexto());
    this->setTamanio(dtImagen.getTamanio());
}

Imagen::Imagen(string url,string formato,string texto,int tamanio){
    this->url     = url;
    this->formato = formato;
    this->texto   = texto;
    this->tamanio = tamanio;
}

string Imagen::getUrl(){
    return this->url;
}

string Imagen::getFormato(){
    return this->formato;
}

string Imagen::getTexto(){
    return this->texto;
}

int Imagen::getTamanio(){
    return this->tamanio;
}

void Imagen::setUrl(string url){
    this->url = url;
}

void Imagen::setFormato(string formato){
    this->formato = formato;
}

void Imagen::setTexto(string texto){
    this->texto = texto;
}

void Imagen::setTamanio(int tamanio){
    this->tamanio = tamanio;
}

DtImagen Imagen::getDtMensaje(){
 //
}

Imagen::~Imagen(){}

