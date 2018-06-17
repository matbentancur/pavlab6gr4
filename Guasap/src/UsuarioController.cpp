#include "UsuarioController.h"

UsuarioController::UsuarioController()
{
    //ctor
}

UsuarioController::~UsuarioController()
{
    //dtor
}

string UsuarioController::getCelularContacto(){
    return this->celularContacto;
}

void UsuarioController::setCelularContacto(string celularContacto){
    this->celularContacto = celularContacto;
}

map<string,DtContacto> UsuarioController::listarContactos(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerContactos();
}

DtContacto UsuarioController::agregarContacto(string celular){
    this->setCelularContacto(celular);
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    return contacto->getDtContacto();
}

bool UsuarioController::confirmarContacto(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    Usuario* contacto = manejadorUsuario->findUsuario(this->getCelularContacto());
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
    FechaHora registro = FechaHora(10,10,2018,10,10); //ingresar fecha del reloj
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

void UsuarioController::cerrarGuasap(){
    Sesion* sesion = Sesion::getInstancia();
    sesion->setSesion("NULL");
}

void UsuarioController::crearSesion(string celularIngresado){
    Sesion* sesion = Sesion::getInstancia();
    sesion->setSesion(celularIngresado);
}

bool UsuarioController::existeSesion(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        return false;
    }else{
        return true;
    }
}

bool UsuarioController::existeUsuario(string celularIngresado){
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    return manejadorUsuario->existeUsuario(celularIngresado);
}

//bool UsuarioController::yaEsContacto(string celularIngresado){
//    bool yaEsContacto = false;
//    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
//    Sesion* sesion = Sesion::getInstancia();
//    sesion->setSesion(celularIngresado);
//    Usuario* usuario = manejadorUsuario->findUsuario(celularIngresado);
//    map<string,Usuario*>::iterator i;
//    for(i = usuario->contactos.begin(); i != usuario->contactos.end(); ++i){
//        if(i->first == celularIngresado){
//            yaEsContacto = true;
//        }
//	}
//	return yaEsContacto;
//}
