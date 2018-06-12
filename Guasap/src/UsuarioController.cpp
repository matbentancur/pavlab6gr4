#include "UsuarioController.h"

UsuarioController::UsuarioController()
{
    //ctor
}

UsuarioController::~UsuarioController()
{
    //dtor
}

set<DtContacto*> UsuarioController::listarContactos(){

}

DtContacto UsuarioController::agregarContacto(string){

}

bool UsuarioController::confirmarContacto(){

}

EstadoIngreso UsuarioController::ingresar(string celularIngresado){
    return Sesion.getEstado(celularIngresado);
}

FechaHora UsuarioController::crearUsuario(string,string,string){

}

void UsuarioController::cerrarGuasap(string){

}
