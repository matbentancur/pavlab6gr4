#include "UsuarioController.h"
#include "Grupo.h"
#include "EstadoConversacion.h"
#include "UsuarioConversacion.h"
#include "Simple.h"
#include "Imagen.h"
#include "Video.h"
#include "TarjetaContacto.h"

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

    Usuario* u5 = new Usuario("1", registro, "Matías Bentancur", "home/img/perfil/matias.png", "Este lab es una matanza"); //PRUEBAS
    manejadorUsuario->agregarUsuario(u5); //PRUEBAS

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

    u5->agregarContacto(u1); //PRUEBAS
    u5->agregarContacto(u2); //PRUEBAS
    u5->agregarContacto(u3); //PRUEBAS
    u5->agregarContacto(u4); //PRUEBAS

    //CONVERSACIONES
    FechaHora creacion = FechaHora(22,5,2017,15,35);
    Grupo* g1 = new Grupo(almacenamiento->getNuevoIdConversacion(), u1, "Amigos", "home/img/amigos.png", creacion);
    g1->agregarAdministrador(u1);
    g1->agregarReceptor(u1);
    g1->agregarReceptor(u2);
    g1->agregarReceptor(u3);
    g1->agregarReceptor(u4);
    g1->agregarReceptor(u5); //PRUEBAS

    UsuarioConversacion* u1g1 = new UsuarioConversacion(creacion,activa,g1);
    u1->agregarUsuarioConversacion(u1g1);

    UsuarioConversacion* u2g1 = new UsuarioConversacion(creacion,activa,g1);
    u2->agregarUsuarioConversacion(u2g1);

    UsuarioConversacion* u3g1 = new UsuarioConversacion(creacion,activa,g1);
    u3->agregarUsuarioConversacion(u3g1);

    UsuarioConversacion* u4g1 = new UsuarioConversacion(creacion,activa,g1);
    u4->agregarUsuarioConversacion(u4g1);

    UsuarioConversacion* u5g1 = new UsuarioConversacion(creacion,activa,g1); //PRUEBAS
    u5->agregarUsuarioConversacion(u5g1); //PRUEBAS

    Privada* cs2 = new Privada(almacenamiento->getNuevoIdConversacion(), u1, u2);
    UsuarioConversacion* u1cs2 = new UsuarioConversacion(creacion,activa,cs2);
    u1->agregarUsuarioConversacion(u1cs2);
    UsuarioConversacion* u2cs2 = new UsuarioConversacion(creacion,activa,cs2);
    u2->agregarUsuarioConversacion(u2cs2);

    Privada* cs3 = new Privada(almacenamiento->getNuevoIdConversacion(), u3, u4);
    UsuarioConversacion* u3cs3 = new UsuarioConversacion(creacion,activa,cs3);
    u3->agregarUsuarioConversacion(u3cs3);
    UsuarioConversacion* u4cs3 = new UsuarioConversacion(creacion,activa,cs3);
    u4->agregarUsuarioConversacion(u4cs3);

    Privada* cs4 = new Privada(almacenamiento->getNuevoIdConversacion(), u5, u4); //PRUEBAS
    UsuarioConversacion* u5cs4 = new UsuarioConversacion(creacion,archivada,cs4); //PRUEBAS
    u5->agregarUsuarioConversacion(u5cs4); //PRUEBAS
    UsuarioConversacion* u4cs4 = new UsuarioConversacion(creacion,activa,cs4); //PRUEBAS
    u4->agregarUsuarioConversacion(u4cs4); //PRUEBAS

    //MENSAJES
    FechaHora fhm1 = FechaHora(22,5,2017,18,04);
    Simple* m1 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm1, false, u4, "¡Miren que bueno este video!");
    g1->agregrarMensaje(m1);
    m1->marcarComoVisto(u1);
    m1->marcarComoVisto(u3);

    FechaHora fhm2 = FechaHora(22,05,2018,18,05);
    Video* m2 = new Video(almacenamiento->getNuevoCodigoMensaje(), fhm2, false, u4, "home/img/video.mkv",5);
    g1->agregrarMensaje(m2);
    m2->marcarComoVisto(u1);
    m2->marcarComoVisto(u3);

    FechaHora fhm3 = FechaHora(22,05,2018,18,12);
    Simple* m3 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm3, false, u1, "¡Muy gracioso!");
    g1->agregrarMensaje(m3);
    m3->marcarComoVisto(u3);
    m3->marcarComoVisto(u4);

    FechaHora fhm4 = FechaHora(22,05,2018,18,13);
    Simple* m4 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm4, false, u3, "¡Excelente!");
    g1->agregrarMensaje(m4);
    m4->marcarComoVisto(u1);
    m4->marcarComoVisto(u4);

    FechaHora fhm5 = FechaHora(23,05,2018,12,23);
    Simple* m5 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm5, false, u2, "Hola, me pasas el contacto de Sara que no lo tengo");
    cs2->agregrarMensaje(m5);
    m5->marcarComoVisto(u1);

    FechaHora fhm6 = FechaHora(23,05,2018,12,25);
    TarjetaContacto* m6 = new TarjetaContacto(almacenamiento->getNuevoCodigoMensaje(), fhm6, false, u1, "Sara Ruiz", "090666777");
    cs2->agregrarMensaje(m6);
    m6->marcarComoVisto(u2);

    FechaHora fhm7 = FechaHora(23,05,2018,12,26);
    Simple* m7 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm7, false, u2, "Gracias");
    cs2->agregrarMensaje(m7);
    m7->marcarComoVisto(u1);

    FechaHora fhm8 = FechaHora(23,05,2018,18,30);
    Simple* m8 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm8, false, u4, "Hola Pablo, ¿cómo estas?");
    cs3->agregrarMensaje(m8);
    m8->marcarComoVisto(u3);

    FechaHora fhm9 = FechaHora(22,6,2018,14,24); //PRUEBAS

    Simple* m9 = new Simple(almacenamiento->getNuevoCodigoMensaje(), fhm9, false, u5, "¡Miren que bueno este video!");
    cs4->agregrarMensaje(m9);

    Video* m10 = new Video(almacenamiento->getNuevoCodigoMensaje(), fhm9, false, u5, "home/img/video.mkv",5);
    cs4->agregrarMensaje(m10);

    TarjetaContacto* m11 = new TarjetaContacto(almacenamiento->getNuevoCodigoMensaje(), fhm9, false, u5, "Sara Ruiz", "090666777");
    cs4->agregrarMensaje(m11);

    Imagen* m12 = new Imagen(almacenamiento->getNuevoCodigoMensaje(), fhm9, false, u5, "home/img/miFoto.jpeg", "JPEG", "Esta es mi foto", 12000);
    cs4->agregrarMensaje(m12);
}
