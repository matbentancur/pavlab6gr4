#include "DtSimple.h"

DtSimple::DtSimple()
{
    //ctor
}

DtSimple::~DtSimple()
{
    //dtor
}

DtSimple::DtSimple(string texto) : DtMensaje(){
    this->texto = texto;
}

DtSimple::DtSimple(int codigo, FechaHora enviado, bool visto, string texto) : DtMensaje(codigo, enviado, visto){
    this->texto = texto;
}

string DtSimple::getTexto(){
    return this->texto;
}

ostream& operator << (ostream& salida, DtSimple& dtSimple) {
    string vistoString = (dtSimple.visto == 0) ? "No" : "Si";
    salida <<
        "Codigo: " << dtSimple.codigo << "\n" <<
        "Enviado: " << dtSimple.enviado <<
        "Visto Todos: " << vistoString << "\n" <<
        "Texto: " << dtSimple.texto << "\n";
    return salida;
}
