#include "Multimedia.h"

Multimedia::Multimedia() : Mensaje(){

}

Multimedia::Multimedia(int codigo, FechaHora enviado, bool visto,Usuario* emisor) : Mensaje(codigo, enviado, visto, emisor){

}

Multimedia::~Multimedia(){}

