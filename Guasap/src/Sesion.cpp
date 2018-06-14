#include "Sesion.h"
#include "ManejadorUsuario.h"

Sesion* Sesion::instancia = NULL;

Sesion* Sesion::getInstancia(){
    if (instancia == NULL)
        instancia = new Sesion();
    return instancia;
}

Sesion::Sesion()
{
    this->celular = "NULL";
}

Sesion::~Sesion()
{
    //dtor
}

string Sesion::getSesion(){
    return this->celular;
}

void Sesion::setSesion(string celular){
    this->celular = celular;
}

EstadoIngreso Sesion::getEstado(string celularIngresado){
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    EstadoIngreso estadoIngreso;
    if(manejadorUsuario->existeUsuario(celularIngresado)){
        if(this->celular == "NULL"){
            this->celular = celularIngresado;
            estadoIngreso = userOK;
        }else if(this->celular != "NULL"){
            if(this->celular == celularIngresado){
                estadoIngreso = igualUserLog;
            }else if(this->celular != celularIngresado){
                estadoIngreso = distintoUserLog;
            }
        }
    }
    if(!(manejadorUsuario->existeUsuario(celularIngresado))){
        estadoIngreso = userInexistente;
    }
    return estadoIngreso;
}
