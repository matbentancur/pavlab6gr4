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
    //ctor
}

Sesion::~Sesion()
{
    //dtor
}

string Sesion::getSesion(){
    return this->celular;
}

//EstadoIngreso Sesion::getEstado(string celularIngresado){
//    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
//    if(!(manejadorUsuario->existeUsuario(celularIngresado))){
//        return userOK;
//    }else if(manejadorUsuario->existeUsuario(celularIngresado)){
//        if(this->celular == NULL){
//            this.celular = celularIngresado;
//            return userInexistente;
//        }
//    }else if(manejadorUsuario->existeUsuario(celularIngresado)){
//        if(celularIngresado == this->celular){
//            if(this->celular != NULL && this.celular == celularIngresado){
//                return igualUserLog;
//            }
//        }
//    }else if(manejadorUsuario->existeUsuario(celularIngresado)){
//        if(celularIngresado == this->celular){
//            if(this->celular != NULL && this.celular != celularIngresado){
//                return distintoUserLog;
//            }
//        }
//    }
//}
