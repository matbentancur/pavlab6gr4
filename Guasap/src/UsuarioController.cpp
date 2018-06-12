#include "UsuarioController.h"

UsuarioController::UsuarioController()
{
    //ctor
}

UsuarioController::~UsuarioController()
{
    //dtor
}

//set<DtContacto*> UsuarioController::listarContactos(){
//
//}

//DtContacto UsuarioController::agregarContacto(string){
//
//}

bool UsuarioController::confirmarContacto(){
    return true;
}

EstadoIngreso UsuarioController::ingresar(string celularIngresado){
//    return Sesion.getEstado(celularIngresado);
    return userOK; //prueba
}

FechaHora UsuarioController::crearUsuario(string,string,string){
    return FechaHora(10,10,10,10,10);
}

void UsuarioController::cerrarGuasap(string){

}
