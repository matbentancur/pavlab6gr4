#include "DtParticipante.h"

DtParticipante::DtParticipante(){

}

DtParticipante::~DtParticipante(){

}

DtParticipante::DtParticipante(string celular, string nombre,bool administrador, FechaHora vistoFechaHora){
    this->celular = celular;
    this->nombre = nombre;
    this->administrador = administrador;
    this->vistoFechaHora = vistoFechaHora;
}

string DtParticipante::getCelular(){
    return this->celular;
}

string DtParticipante::getNombre(){
    return this->nombre;
}

bool DtParticipante::getAdministrador(){
    return this->administrador;
}

FechaHora DtParticipante::getFechaHora(){
    return this->vistoFechaHora;
}

ostream& operator << (ostream& salida, DtParticipante& dtParticipante) {
    salida <<
        "Celular: " << dtParticipante.celular << "\n" <<
        "Nombre: " << dtParticipante.nombre << "\n" <<
        "Administrador: " << dtParticipante.administrador << "\n" <<
        "Visto: " << dtParticipante.vistoFechaHora << "\n";
    return salida;
}
