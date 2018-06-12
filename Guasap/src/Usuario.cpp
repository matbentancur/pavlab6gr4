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
//		listaContactos[dtContacto.getCelular()] = dtContacto;
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

//set<DtConversacion*> Usuario::obtenerConversacionesActivas(){
//
//}
//
//set<DtConversacion*> Usuario::obtenerConversacionesArchivadas(){
//
//}
//
//set<DtMensaje*> Usuario::obtenerMensajes(int){
//
//}

//set<DtReceptor*> verInfoMensaje(int){
//
//}

//DtReceptor getDtReceptor(){
//
//}

//void Usuario::ingresarIdConversacion(int){
//
//}
//
//set<DtConversacion*> Usuario::obtenerConversaciones(){
//
//}
//
//bool Usuario::buscarConversacion(int){
//
//}

//obtenerContacto(): DtContacto{
//
//}

//DtConversacion Usuario::obtenerConversacion(int){
//
//}
//
//bool Usuario::iniciarConversacion(Usuario){
//
//}
