#include "UsuarioController.h"
#include "Grupo.h"
#include "EstadoConversacion.h"
#include "UsuarioConversacion.h"
#include "Simple.h"

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

DtContacto UsuarioController::modificarUsuario(string nombre, string imagen, string descripcion){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }else{
        ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
        Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
        usuario->setNombre(nombre);
        usuario->setImagen(imagen);
        usuario->setDescripcion(descripcion);
        return usuario->getDtContacto();
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

    //USUARIOS
    Usuario* u1 = new Usuario("090123654", registro, "Juan Pérez", "home/img/perfil/juan.png", "Amo usar Guasap");
    manejadorUsuario->agregarUsuario(u1);

    Usuario* u2 = new Usuario("090765432", registro, "María Fernández", "home/img/perfil/maria.png", "Me encanta Avanzada");
    manejadorUsuario->agregarUsuario(u2);

    Usuario* u3 = new Usuario("090246810", registro, "Pablo Iglesias", "home/img/perfil/pablo.png", "Me gustan los animales");
    manejadorUsuario->agregarUsuario(u3);

    Usuario* u4 = new Usuario("090666777", registro, "Sara Ruiz", "home/img/perfil/sara.png", "¡Estoy feliz!");
    manejadorUsuario->agregarUsuario(u4);

    Usuario* u5 = new Usuario("1", registro, "Matías Bentancur", "home/img/perfil/matias.png", "Este lab es una matanza");
    manejadorUsuario->agregarUsuario(u5);

    //CONTACTOS
    u1->agregarContacto(u2);
    u1->agregarContacto(u3);
    u1->agregarContacto(u4);

    u2->agregarContacto(u1);
    u2->agregarContacto(u3);

    u3->agregarContacto(u1);
    u3->agregarContacto(u2);
    u3->agregarContacto(u3);

    u4->agregarContacto(u1);
    u4->agregarContacto(u3);

    u5->agregarContacto(u1);
    u5->agregarContacto(u2);
    u5->agregarContacto(u3);
    u5->agregarContacto(u4);

    //CONVERSACIONES
    FechaHora creacion = FechaHora(22,5,2017,15,35);
    Grupo* g1 = new Grupo(almacenamiento->getNuevoIdConversacion(), u1, "Amigos", "home/img/amigos.png", creacion);
    g1->agregarAdministrador(u1);
    g1->agregarReceptor(u1);
    g1->agregarReceptor(u2);
    g1->agregarReceptor(u3);
    g1->agregarReceptor(u4);

    UsuarioConversacion* u1g1 = new UsuarioConversacion(activa,g1);
    u1->agregarUsuarioConversacion(u1g1);

    UsuarioConversacion* u2g1 = new UsuarioConversacion(activa,g1);
    u2->agregarUsuarioConversacion(u2g1);

    UsuarioConversacion* u3g1 = new UsuarioConversacion(activa,g1);
    u3->agregarUsuarioConversacion(u3g1);

    UsuarioConversacion* u4g1 = new UsuarioConversacion(activa,g1);
    u4->agregarUsuarioConversacion(u4g1);

    Privada* cs2 = new Privada(almacenamiento->getNuevoIdConversacion(), u1, u2);
    UsuarioConversacion* u1cs2 = new UsuarioConversacion(activa,cs2);
    u1->agregarUsuarioConversacion(u1cs2);
    UsuarioConversacion* u2cs2 = new UsuarioConversacion(activa,cs2);
    u2->agregarUsuarioConversacion(u2cs2);

    Privada* cs3 = new Privada(almacenamiento->getNuevoIdConversacion(), u3, u4);
    UsuarioConversacion* u3cs3 = new UsuarioConversacion(activa,cs3);
    u3->agregarUsuarioConversacion(u3cs3);
    UsuarioConversacion* u4cs3 = new UsuarioConversacion(activa,cs3);
    u4->agregarUsuarioConversacion(u4cs3);

    //MENSAJES
    FechaHora fhm1 = FechaHora(22,5,2017,18,04);
    Simple* m1 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm1, false, u4, "¡Miren que bueno este video!");
    g1->agregrarMensaje(m1);
}
