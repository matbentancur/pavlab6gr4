#include "Usuario.h"
#include "UsuarioConversacion.h"
#include "Almacenamiento.h"
#include "Simple.h"
#include "TarjetaContacto.h"
#include "Imagen.h"
#include "Video.h"
#include "Privada.h"

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

Usuario::Usuario(string celular, Fecha registro, string nombre, string imagen, string descripcion) {
    this->celular = celular;
    this->registro = registro;
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
        Usuario* usuario = i->second;
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

map<int,DtConversacion*> Usuario::obtenerConversacionesActivas(){
    map<int,DtConversacion*> listaConversaciones;
	set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion* usuarioConversacion = *i;
        if (usuarioConversacion->getEstado() == 1){
            DtConversacion* dtConversacion = usuarioConversacion->obtenerConversacion();
            listaConversaciones.insert(std::pair<int, DtConversacion*>(dtConversacion->getIdConversacion(), dtConversacion));
        }
	}
	return listaConversaciones;
}

map<int,DtConversacion*> Usuario::obtenerConversacionesArchivadas(){
    map<int,DtConversacion*> listaConversaciones;
	set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion* usuarioConversacion = *i;
        if (usuarioConversacion->getEstado() == 2){
            DtConversacion* dtConversacion = usuarioConversacion->obtenerConversacion();
            listaConversaciones.insert(std::pair<int, DtConversacion*>(dtConversacion->getIdConversacion(), dtConversacion));
        }
	}
	return listaConversaciones;
}

map<int,DtMensaje*> Usuario::obtenerMensajes(int idConversacion){
    map<int,DtMensaje*> listaMensajes;
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion* usuarioConversacion = *i;
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
        UsuarioConversacion* usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            listaReceptores = usuarioConversacion->verInfoMensaje(codigo);
        }
	}
	return listaReceptores;
}

bool Usuario::archivarConversacion(int idConversacion){
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion* usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            usuarioConversacion->setEstado(archivada);
            return true;
        }
	}
	return false;
}

bool Usuario::activarConversacion(int idConversacion){
    set<UsuarioConversacion*>::iterator i;
    for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
        UsuarioConversacion* usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            usuarioConversacion->setEstado(activa);
            return true;
        }
	}
	return false;
}

bool Usuario::agregarUsuarioConversacion(UsuarioConversacion* usuarioConversacion){
    this->usuarioConversacion.insert(usuarioConversacion);
    return true;
}

bool Usuario::enviarMensajeConversacion(int idConversacion, Usuario* emisor, DtMensaje* nuevoMensaje){
    Mensaje* mensaje;
    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
    int nuevoCodigoMensaje = almacenamiento->getNuevoCodigoMensaje();
    almacenamiento->setUltimoCodigoMensaje(nuevoCodigoMensaje);
    FechaHora enviado = almacenamiento->getReloj();
    bool mensajeCreado = false;

    try{
        DtSimple* dtm = dynamic_cast<DtSimple*>(nuevoMensaje);
        if (dtm != NULL){
            mensaje = new Simple(nuevoCodigoMensaje, enviado, false, emisor, dtm->getTexto());
            mensajeCreado = true;
        }
    }catch(std::bad_cast){
        cout << "Error en cast para Simple\n";
    }
    try{
        DtImagen* dtm = dynamic_cast<DtImagen*>(nuevoMensaje);
        if (dtm != NULL){
            mensaje = new Imagen(nuevoCodigoMensaje, enviado, false, emisor, dtm->getUrl(), dtm->getFormato(), dtm->getTexto(), dtm->getTamanio());
            mensajeCreado = true;
        }
    }catch(exception& e){
        cout << "Error en cast para Imagen\n";
    }
    try{
        DtVideo* dtm = dynamic_cast<DtVideo*>(nuevoMensaje);
        if (dtm != NULL){
            mensaje = new Video(nuevoCodigoMensaje, enviado, false, emisor, dtm->getUrl(), dtm->getDuracion());
            mensajeCreado = true;
        }
    }catch(exception& e){
        cout << "Error en cast para Video\n";
    }

    try{
        DtTarjetaContacto* dtm = dynamic_cast<DtTarjetaContacto*>(nuevoMensaje);
        if (dtm != NULL){
            mensaje = new TarjetaContacto(nuevoCodigoMensaje, enviado, false, emisor, dtm->getNombre(), dtm->getTelefono());
            mensajeCreado = true;
        }
    }catch(exception& e){
        cout << "Error en cast para Tarjeta de Contacto\n";
    }

    if (mensajeCreado){
        set<UsuarioConversacion*>::iterator i;
        for(i = usuarioConversacion.begin(); i != usuarioConversacion.end(); ++i){
            UsuarioConversacion* usuarioConversacion = *i;
            if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
                return usuarioConversacion->enviarMensajeConversacion(mensaje);
            }
        }
    }
    return false;
}

bool Usuario::enviarMensajeNuevaConversacion(Usuario* origen, Usuario* destino, DtMensaje* nuevoMensaje){
    Almacenamiento* almacenamiento = Almacenamiento::getInstancia();
    int nuevoIdConversacion = almacenamiento->getNuevoIdConversacion();
    almacenamiento->setUltimoIdConversacion(nuevoIdConversacion);
    Privada* conversacion = new Privada(nuevoIdConversacion, origen, destino);

    FechaHora agregado = almacenamiento->getReloj();
    UsuarioConversacion* origenUsuarioConversacion = new UsuarioConversacion(agregado,activa,conversacion);
    origen->agregarUsuarioConversacion(origenUsuarioConversacion);

    UsuarioConversacion* destinoUsuarioConversacion = new UsuarioConversacion(agregado,activa,conversacion);
    destino->agregarUsuarioConversacion(destinoUsuarioConversacion);
    return this->enviarMensajeConversacion(nuevoIdConversacion, origen, nuevoMensaje);
}

bool Usuario::eliminarMensaje(int idConversacion,int codigoMensaje){
	set<UsuarioConversacion*>::iterator i;
    for(i = this->usuarioConversacion.begin(); i != this->usuarioConversacion.end(); ++i){
        UsuarioConversacion* usuarioConversacion = *i;
        if (usuarioConversacion->getConversacion()->getIdConversacion() == idConversacion){
            return usuarioConversacion->eliminarMensaje(codigoMensaje);
        }
	}
    return false;
}
