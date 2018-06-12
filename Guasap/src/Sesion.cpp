#include "Sesion.h"
#include "ManejadorUsuario.h"

Sesion::Sesion()
{
    //ctor
}

Sesion::~Sesion()
{
    //dtor
}

string Sesion::getSesion(){
    return this->celular;
}

EstadoIngreso Sesion::getEstado(string celularIngresado){
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    if(!(manejadorUsuario->existeUsuario(celularIngresado)){
        return 1;
    }else if(manejadorUsuario->existeUsuario(celularIngresado)){
        if(this->celular == NULL){
            this.celular = celularIngresado;
            return 2;
        }
    }else if(manejadorUsuario->existeUsuario(celularIngresado)){
        if(celularIngresado == this->celular){
            if(this->celular != NULL && this.celular == celularIngresado){
                return 3;
            }
        }
    }else if(manejadorUsuario->existeUsuario(celularIngresado)){
        if(celularIngresado == this->celular){
            if(this->celular != NULL && this.celular != celularIngresado){
                return 4;
            }
        }
    }
}
