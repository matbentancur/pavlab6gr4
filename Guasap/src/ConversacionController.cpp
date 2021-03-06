#include "ConversacionController.h"

ConversacionController::ConversacionController()
{
    //ctor
}

ConversacionController::~ConversacionController()
{
    //dtor
}

map<int,DtConversacion*> ConversacionController::listarConversacionesActivas(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerConversacionesActivas();
}

map<int,DtConversacion*> ConversacionController::listarConversacionesArchivadas(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerConversacionesArchivadas();
}

bool ConversacionController::archivarConversacion(int idConversacion){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->archivarConversacion(idConversacion);
}

bool ConversacionController::activarConversacion(int idConversacion){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->activarConversacion(idConversacion);
}

bool ConversacionController::agregarSeleccionContactoGrupo(string celular){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    if (this->listaContactosGrupoElegidos.size() == 0){
        listaContactosGrupoRestantes = usuario->obtenerContactos();
    }
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    if(contacto == NULL){
        throw logic_error("\nNo existe un usuario con numero de celular: " + celular + "\n");
    }
    listaContactosGrupoElegidos.insert(std::pair<string, DtContacto>(celular, contacto->getDtContacto()));
    listaContactosGrupoRestantes.erase(celular);
    return true;
}

bool ConversacionController::quitarSeleccionContactoGrupo(string celular){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    if (this->listaContactosGrupoElegidos.size() == 0){
        listaContactosGrupoRestantes = usuario->obtenerContactos();
    }
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    if(contacto == NULL){
        throw logic_error("\nNo existe un usuario con numero de celular: " + celular + "\n");
    }
    listaContactosGrupoRestantes.insert(std::pair<string, DtContacto>(celular, contacto->getDtContacto()));
    listaContactosGrupoElegidos.erase(celular);
    return true;
}

bool ConversacionController::altaGrupo(string nombre,string urlImagen){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    if (this->listaContactosGrupoElegidos.size() == 0){
        throw logic_error("\nDebe seleccionar al menos un contacto para crear el grupo.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
    int nuevoIdConversaion = almacenamiento->getNuevoIdConversacion();
    almacenamiento->setUltimoIdConversacion(nuevoIdConversaion);
    FechaHora creacion = almacenamiento->getReloj();
    Grupo* nuevoGrupo = new Grupo(nuevoIdConversaion, usuario, nombre, urlImagen, creacion);
    nuevoGrupo->agregarAdministrador(usuario);
    nuevoGrupo->agregarReceptor(usuario);
    UsuarioConversacion* nuevoUsuarioConversacion = new UsuarioConversacion(creacion,activa,nuevoGrupo);
    usuario->agregarUsuarioConversacion(nuevoUsuarioConversacion);

    //agrega para cada contacto elegido un usuarioConversacion
    map<string,DtContacto>::iterator i;
    for(i = listaContactosGrupoElegidos.begin(); i != listaContactosGrupoElegidos.end(); ++i){
        DtContacto dtContacto = i->second;
        Usuario* contacto = manejadorUsuario->findUsuario(dtContacto.getCelular());
        nuevoGrupo->agregarReceptor(contacto);
        UsuarioConversacion* nuevoUsuarioConversacion = new UsuarioConversacion(creacion,activa,nuevoGrupo);
        contacto->agregarUsuarioConversacion(nuevoUsuarioConversacion);
    }
    return true;
}

map<string,DtContacto> ConversacionController::listarContactosElegidos(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    return this->listaContactosGrupoElegidos;
}

map<string,DtContacto> ConversacionController::listarContactosRestantes(){
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getSesion() == "NULL"){
        throw logic_error("\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n");
    }
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    if (this->listaContactosGrupoElegidos.size() == 0){
        listaContactosGrupoRestantes = usuario->obtenerContactos();
    }
    return listaContactosGrupoRestantes;
}
