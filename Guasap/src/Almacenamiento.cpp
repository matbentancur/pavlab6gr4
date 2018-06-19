#include "Almacenamiento.h"

Almacenamiento* Almacenamiento::instancia = NULL;

Almacenamiento* Almacenamiento::getInstancia(){
    if (instancia == NULL){
        FechaHora fechaHora = FechaHora(1,1,2018,0,0);
        instancia = new Almacenamiento(fechaHora,0,0);
    }
    return instancia;
}

Almacenamiento::~Almacenamiento()
{
    //dtor
}

Almacenamiento::Almacenamiento(FechaHora reloj, int ultimoIdConversacion, int ultimoCodigoMensaje) {
    this->reloj = reloj;
    this->ultimoIdConversacion = ultimoIdConversacion;
    this->ultimoCodigoMensaje = ultimoCodigoMensaje;
}

FechaHora Almacenamiento::getReloj(){
    return this->reloj;
}

void Almacenamiento::setReloj(FechaHora reloj){
    this->reloj = reloj;
}

int Almacenamiento::getUltimoIdConversacion(){
    return this->ultimoIdConversacion;
}

void Almacenamiento::setUltimoIdConversacion(int idConversacion){
    this->ultimoIdConversacion = idConversacion;
}

int Almacenamiento::getUltimoCodigoMensaje(){
    return this->ultimoCodigoMensaje;
}

void Almacenamiento::setUltimoCodigoMensaje(int codigoMensaje){
    this->ultimoCodigoMensaje = codigoMensaje;
}
