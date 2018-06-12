#include "Estado.h"

Estado::Estado(){

}

Estado::Estado(string texto, FechaHora publicado){
    this->texto     = texto;
    this->publicado = publicado;
}

string Estado::getTexto(){
       return this->texto;
}

FechaHora Estado::getPublicado(){
    return this->publicado;
}

void Estado::setTexto(string texto){
    this->texto = texto;
}

void Estado::setPublicado(FechaHora publicado){
    this->publicado = publicado;
}

Estado::~Estado(){}
