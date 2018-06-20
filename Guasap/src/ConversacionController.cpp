#include "ConversacionController.h"

ConversacionController::ConversacionController()
{
    //ctor
}

ConversacionController::~ConversacionController()
{
    //dtor
}

map<int,DtConversacion> ConversacionController::listarConversacionesActivas(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerConversacionesActivas();
}

map<int,DtConversacion> ConversacionController::listarConversacionesArchivadas(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->obtenerConversacionesArchivadas();
}

bool ConversacionController::archivarConversacion(int idConversacion){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    return usuario->archivarConversacion(idConversacion);
}

bool ConversacionController::agregarSeleccionContactoGrupo(string celular){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    if (this->listaContactosGrupoElegidos.size() == 0){
        listaContactosGrupoRestantes = usuario->obtenerContactos();
    }
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    listaContactosGrupoElegidos.insert(std::pair<string, DtContacto>(celular, contacto->getDtContacto()));
    listaContactosGrupoRestantes.erase(celular);
    return true;
}

bool ConversacionController::quitarSeleccionContactoGrupo(string celular){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    if (this->listaContactosGrupoElegidos.size() == 0){
        listaContactosGrupoRestantes = usuario->obtenerContactos();
    }
    Usuario* contacto = manejadorUsuario->findUsuario(celular);
    listaContactosGrupoRestantes.insert(std::pair<string, DtContacto>(celular, contacto->getDtContacto()));
    listaContactosGrupoElegidos.erase(celular);
    return true;
}

bool ConversacionController::altaGrupo(string nombre,string urlImagen){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->findUsuario(sesion->getSesion());
    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
    int nuevoIdConversaion = almacenamiento->getNuevoIdConversacion();
    almacenamiento->setUltimoIdConversacion(nuevoIdConversaion);
    FechaHora creacion = almacenamiento->getReloj();
    Grupo* nuevoGrupo = new Grupo(nuevoIdConversaion, usuario, nombre, urlImagen, creacion);
    nuevoGrupo->agregarAdministrador(usuario);
    nuevoGrupo->agregarReceptor(usuario);
    UsuarioConversacion* nuevoUsuarioConversacion = new UsuarioConversacion(activa,nuevoGrupo);
    usuario->agregarUsuarioConversacion(nuevoUsuarioConversacion);

    //agrega para cada contacto elegido un usuarioConversacion
    map<string,DtContacto>::iterator i;
    for(i = listaContactosGrupoElegidos.begin(); i != listaContactosGrupoElegidos.end(); ++i){
        DtContacto dtContacto = i->second;
        Usuario* contacto = manejadorUsuario->findUsuario(dtContacto.getCelular());
        nuevoGrupo->agregarReceptor(contacto);
        UsuarioConversacion* nuevoUsuarioConversacion = new UsuarioConversacion(activa,nuevoGrupo);
        contacto->agregarUsuarioConversacion(nuevoUsuarioConversacion);
    }
    return true;
}
