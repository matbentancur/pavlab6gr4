#include "DtTarjetaContacto.h"

DtTarjetaContacto::DtTarjetaContacto()
{
    //ctor
}

DtTarjetaContacto::~DtTarjetaContacto()
{
    //dtor
}

DtTarjetaContacto::DtTarjetaContacto(string nombre, string telefono) : DtMensaje(){
    this->nombre = nombre;
    this->telefono = telefono;
}

DtTarjetaContacto::DtTarjetaContacto(int codigo, FechaHora enviado, bool visto, string nombre, string telefono) : DtMensaje(codigo, enviado, visto){
    this->nombre = nombre;
    this->telefono = telefono;
}

string DtTarjetaContacto::getNombre(){
    return this->nombre;
}

string DtTarjetaContacto::getTelefono(){
    return this->telefono;
}

ostream& operator << (ostream& salida, DtTarjetaContacto& dtTarjetaContacto) {
    string vistoString = (dtTarjetaContacto.visto == 0) ? "No" : "Si";
    salida <<
        "Codigo: " << dtTarjetaContacto.codigo << "\n" <<
        "Enviado: " << dtTarjetaContacto.enviado <<
        "Visto Todos: " << vistoString << "\n" <<
        "Nombre: " << dtTarjetaContacto.nombre << "\n" <<
        "Telefono: " << dtTarjetaContacto.telefono << "\n";
    return salida;
}
