#include "UsuarioController.h"
#include "Sesion.h"

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
    //Sesion* sesion = Sesion::getInstancia();
//    return sesion->getEstado(celularIngresado);
    return userOK;
}

FechaHora UsuarioController::crearUsuario(string celular, string nombre, string imagen, string descripcion){
    Usuario* usuario = new Usuario(celular, nombre, imagen, descripcion);
    FechaHora registro = FechaHora(10,10,10,10,10);
    usuario->registro = registro;
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    manejadorUsuario->agregarUsuario(usuario);

    return registro;
}

void UsuarioController::modificarUsuario(string nombre, string imagen, string descripcion){

    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    usuario->setNombre(nombre);
    usuario->setImagen(imagen);
    usuario->setDescripcion(descripcion);

}

void UsuarioController::cerrarGuasap(string){

}
