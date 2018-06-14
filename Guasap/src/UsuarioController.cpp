#include "UsuarioController.h"

UsuarioController::UsuarioController()
{
    //ctor
}

UsuarioController::~UsuarioController()
{
    //dtor
}

map<string,DtContacto> UsuarioController::listarContactos(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerContactos();
}

DtContacto UsuarioController::agregarContacto(string celular){
    this->celularContacto = celular;
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    return contacto->getDtContacto();
}


bool UsuarioController::confirmarContacto(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    Usuario* contacto = manejadorUsuario->findUsuario(this->celularContacto);
    if(usuario->agregarContacto(contacto)){
        return true;
    }
    return false;
}

EstadoIngreso UsuarioController::ingresar(string celularIngresado){
    Sesion* sesion = Sesion::getInstancia();
    return sesion->getEstado(celularIngresado);
}

FechaHora UsuarioController::crearUsuario(string celular, string nombre, string imagen, string descripcion){
    Usuario* usuario = new Usuario(celular, nombre, imagen, descripcion);
    FechaHora registro = FechaHora(10,10,10,10,10); //ingresar fecha del reloj
    usuario->setRegistro(registro);
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
