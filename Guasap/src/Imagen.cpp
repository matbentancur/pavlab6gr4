#include "Imagen.h"

Imagen::Imagen(int codigo, FechaHora enviado, bool visto, Usuario* emisor, string url,string formato,string texto,int tamanio) : Multimedia(codigo,enviado,visto,emisor){
    this->url = url;
    this->formato = formato;
    this->texto = texto;
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

DtMensaje* Imagen::getDtMensaje(){
    DtImagen* dtImagen = new DtImagen(this->codigo, this->enviado, this->visto, this->url, this->formato, this->tamanio, this->texto);
    return dtImagen;
}

Imagen::~Imagen(){}

