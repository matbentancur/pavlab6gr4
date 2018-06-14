#include "Mensaje.h"

Mensaje::Mensaje(int codigo,FechaHora enviado,bool visto){
    this->codigo  = codigo;
    this->enviado = enviado;
    this->visto   = visto;
}

int Mensaje::getCodigo(){
        return this->codigo;
}

FechaHora Mensaje::getEnviado(){
        return this->enviado;
}

bool Mensaje::getVisto(){
        return this->visto;
}

void Mensaje::setCodigo(int codigo){
    this->codigo = codigo;
}

void Mensaje::setEnviado(FechaHora enviado){
    this->enviado = enviado;
}

void Mensaje::setVisto(bool visto){
    this->visto = visto;
}

Mensaje::~Mensaje(){}
