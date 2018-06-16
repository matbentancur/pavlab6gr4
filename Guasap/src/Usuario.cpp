#include "Usuario.h"

Usuario::Usuario()
{
    //ctor
}

Usuario::~Usuario()
{
    //dtor
}

Usuario::Usuario(string celular, string nombre) {
    this->celular = celular;
    this->nombre = nombre;
}

Usuario::Usuario(string celular, string nombre, string imagen, string descripcion) {
    this->celular = celular;
    this->nombre = nombre;
    this->imagen = imagen;
    this->descripcion = descripcion;
}

string Usuario::getCelular() {
    return this->celular;
}

void Usuario::setCelular(string celular){
    this->celular = celular;
}

string Usuario::getNombre() {
    return this->nombre;
}

void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}

Fecha Usuario::getRegistro() {
    return this->registro;
}

void Usuario::setRegistro(Fecha registro){
    this->registro = registro;
}

string Usuario::getImagen() {
    return this->imagen;
}

void Usuario::setImagen(string imagen){
    this->imagen = imagen;
}

string Usuario::getDescripcion() {
    return this->descripcion;
}

void Usuario::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

FechaHora Usuario::getUltimaConexion() {
    return this->ultimaConexion;
}

void Usuario::setUltimaConexion(FechaHora ultimaConexion){
    this->ultimaConexion = ultimaConexion;
}

map<string,DtContacto> Usuario::obtenerContactos(){
    map<string,DtContacto> listaContactos;
	map<string,Usuario*>::iterator i;
    for(i = contactos.begin(); i != contactos.end(); ++i){
//		DtContacto dtContacto = (*i)->getDtContacto();
        Usuario * usuario = i->second;
        DtContacto dtContacto = usuario->getDtContacto();
        listaContactos.insert(std::pair<string, DtContacto>(usuario->getCelular(), dtContacto));
	}
	return listaContactos;
}

DtContacto Usuario::getDtContacto(){
    DtContacto dtContacto = DtContacto(this->celular, this->nombre, this->imagen);
    return dtContacto;
}

bool Usuario::agregarContacto(Usuario* usuario){
    map<string,Usuario*>::iterator i;
    i = this->contactos.find(usuario->getCelular());
    if (i != this->contactos.end()){
        return false;
    }
    this->contactos.insert(std::pair<string, Usuario*>(usuario->getCelular(), usuario));
    return true;
}

map<int,DtConversacion> Usuario::obtenerConversacionesActivas(){
    map<int,DtConversacion> listaConversaciones;
	set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion * usuarioConversacion = *i;
        if (usuarioConversacion->getEstado() == 1){
            DtConversacion dtConversacion = usuarioConversacion->obtenerConversacion();
            listaConversaciones.insert(std::pair<int, DtConversacion>(dtConversacion.getIdConversacion(), dtConversacion));
        }
	}
	return listaConversaciones;
}

map<int,DtConversacion> Usuario::obtenerConversacionesArchivadas(){
    map<int,DtConversacion> listaConversaciones;
	set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion * usuarioConversacion = *i;
        if (usuarioConversacion->getEstado() == 2){
            DtConversacion dtConversacion = usuarioConversacion->obtenerConversacion();
            listaConversaciones.insert(std::pair<int, DtConversacion>(dtConversacion.getIdConversacion(), dtConversacion));
        }
	}
	return listaConversaciones;
}

map<int,DtMensaje> Usuario::obtenerMensajes(int idConversacion){
    map<int,DtMensaje> listaMensajes;
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion * usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            listaMensajes = usuarioConversacion->obtenerMensajes();
        }
	}
	return listaMensajes;
}

map<string,DtReceptor> Usuario::verInfoMensaje(int idConversacion, int codigo){
    map<string,DtReceptor> listaReceptores;
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion * usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            listaReceptores = usuarioConversacion->verInfoMensaje(codigo);
        }
	}
	return listaReceptores;
}

bool Usuario::archivarConversacion(int idConversacion){
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion * usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            usuarioConversacion->setEstado(archivada);
            return true;
        }
	}
	return false;
}

bool Usuario::agregarUsuarioConversacion(UsuarioConversacion* usuarioConversacion){
    this->usuarioConversacion.insert(usuarioConversacion);
    return true;
}

bool Usuario::enviarMensajeConversacion(int idConversacion, DtMensaje nuevoMensaje){
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion * usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
//            usuarioConversacion->setEstado(archivada);
            return true;
        }
	}
	return false;
}

//bool Usuario::buscarConversacion(int){
//
//}

//bool Usuario::iniciarConversacion(Usuario){
//
//}
