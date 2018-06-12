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

string Usuario::getNombre() {
    return this->nombre;
}

Fecha Usuario::getRegistro() {
    return this->registro;
}

string Usuario::getImagen() {
    return this->imagen;
}

string Usuario::getDescripcion() {
    return this->descripcion;
}

FechaHora Usuario::getUltimaConexion() {
    return this->ultimaConexion;
}

set<DtContacto*> Usuario::obtenerContactos(){

}

DtContacto Usuario::getDtContacto(){

}

bool Usuario::agregarContacto(Usuario){

}

set<DtConversacion*> Usuario::obtenerConversacionesActivas(){

}

set<DtConversacion*> Usuario::obtenerConversacionesArchivadas(){

}

set<DtMensaje*> Usuario::obtenerMensajes(int){

}

//set<DtReceptor*> verInfoMensaje(int){
//
//}

//DtReceptor getDtReceptor(){
//
//}

void Usuario::ingresarIdConversacion(int){

}

set<DtConversacion*> Usuario::obtenerConversaciones(){

}

bool Usuario::buscarConversacion(int){

}

//obtenerContacto(): DtContacto{
//
//}

DtConversacion Usuario::obtenerConversacion(int){

}

bool Usuario::iniciarConversacion(Usuario){

}
