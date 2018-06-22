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
    salida <<
        "Codigo: " << dtSimple.codigo << "\n" <<
        "Enviado: " << dtSimple.enviado <<
        "Visto: " << dtSimple.visto << "\n" <<
        "Texto: " << dtSimple.texto << "\n";
    return salida;
}
