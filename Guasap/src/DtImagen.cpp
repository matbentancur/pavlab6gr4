#include "DtImagen.h"

DtImagen::DtImagen()
{
    //ctor
}

DtImagen::~DtImagen()
{
    //dtor
}

DtImagen::DtImagen(string url, string formato, int tamanio, string texto) : DtMensaje(){
    this->url = url;
    this->formato = formato;
    this->tamanio = tamanio;
    this->texto = texto;
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

ostream& operator << (ostream& salida, DtImagen& dtImagen) {
    salida <<
        "Codigo: " << dtImagen.codigo << "\n" <<
        "Enviado: " << dtImagen.enviado <<
        "Visto: " << dtImagen.visto << "\n" <<
        "URL: " << dtImagen.url << "\n" <<
        "Formato: " << dtImagen.formato << "\n" <<
        "Tamanio: " << dtImagen.tamanio << "\n" <<
        "Texto: " << dtImagen.texto << "\n";
    return salida;
}
