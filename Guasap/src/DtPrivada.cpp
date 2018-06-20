#include "DtPrivada.h"

DtPrivada::DtPrivada()
{
    //ctor
}

DtPrivada::~DtPrivada()
{
    //dtor
}

DtPrivada::DtPrivada(int idConversacion, string nombre, string destino) : DtConversacion(idConversacion, nombre){
    this->destino = destino;
}

string DtPrivada::getDestino(){
    return this->destino;
}

ostream& operator << (ostream& salida, DtPrivada& dtPrivada) {
    salida <<
        "ID: " << dtPrivada.idConversacion << "\n" <<
        "Nombre: " << dtPrivada.nombre << "\n" <<
        "Destino: " << dtPrivada.destino << "\n";
    return salida;
}
