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
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
        Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
        return usuario->obtenerContactos();
    }
}

DtContacto UsuarioController::agregarContacto(string celular){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        this->setCelularContacto(celular);
        ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
        Usuario* contacto = manejadorUsuario->findUsuario(celular);
        if(contacto == NULL){
            throw logic_error("\nNo existe un usuario con numero de celular: " + celular + "\n");
        }else{
            return contacto->getDtContacto();
        }
    }
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
    EstadoIngreso estadoIngreso = sesion->getEstado(celularIngresado);
    if(estadoIngreso == userOK){
        sesion->setSesion(celularIngresado);
    }
    return estadoIngreso;
}

FechaHora UsuarioController::crearUsuario(string celular, string nombre, string imagen, string descripcion){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* usuario = new Usuario(celular, nombre, imagen, descripcion);
    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
    FechaHora registro = almacenamiento->getReloj();
    usuario->setRegistro(registro);
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    if(manejadorUsuario->agregarUsuario(usuario)){
        sesion->setSesion(celular);
    }
    return registro;
}

void UsuarioController::modificarUsuario(string nombre, string imagen, string descripcion){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
        Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
        usuario->setNombre(nombre);
        usuario->setImagen(imagen);
        usuario->setDescripcion(descripcion);
    }
}

void UsuarioController::cerrarGuasap(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        sesion->setSesion("NULL");
    }
}

bool UsuarioController::modificarReloj(FechaHora fechaHora){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
        almacenamiento->setReloj(fechaHora);
        return true;
    }
    return false;
}

FechaHora UsuarioController::consultarReloj(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
        return almacenamiento->getReloj();
    }
}

void UsuarioController::cargarDatosPrueba(){
    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    FechaHora registro = almacenamiento->getReloj();

    Usuario* u1 = new Usuario("090123654", registro, "Juan Pérez", "home/img/perfil/juan.png", "Amo usar Guasap");
    manejadorUsuario->agregarUsuario(u1);

    Usuario* u2 = new Usuario("090765432", registro, "María Fernández", "home/img/perfil/maria.png", "Me encanta Avanzada");
    manejadorUsuario->agregarUsuario(u2);

    Usuario* u3 = new Usuario("090246810", registro, "Pablo Iglesias", "home/img/perfil/pablo.png", "Me gustan los animales");
    manejadorUsuario->agregarUsuario(u3);

    Usuario* u4 = new Usuario("090666777", registro, "Sara Ruiz", "home/img/perfil/sara.png", "¡Estoy feliz!");
    manejadorUsuario->agregarUsuario(u4);

    Usuario* u5 = new Usuario("098197161", registro, "Matias Bentancur", "home/img/perfil/matias.png", "Este lab es una matanza");
    manejadorUsuario->agregarUsuario(u5);
}
