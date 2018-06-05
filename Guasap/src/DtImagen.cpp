#include "DtImagen.h"

DtImagen::DtImagen()
{
    //ctor
}

DtImagen::~DtImagen()
{
    //dtor
}

DtImagen::DtImagen(int codigo, FechaHora enviado, bool visto, string url, string formato, int tamanio, string texto) : DtMensaje(codigo, enviado, visto){
    this->url = url;
    this->formato = formato;
    this->tamanio = tamanio;
    this->texto = texto;
}

string DtImagen::getUrl(){
    return this->url;
}

string DtImagen::getFormato(){
    return this->formato;
}

int DtImagen::getTamanio(){
    return this->tamanio;
}

string DtImagen::getTexto(){
    return this->texto;
}
