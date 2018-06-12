#include "FechaHora.h"

FechaHora::FechaHora()
{
    //ctor
}

FechaHora::~FechaHora()
{
    //dtor
}

FechaHora::FechaHora(int dia, int mes, int anio, int hora, int minuto) : Fecha(dia,mes,anio){

    if (hora < 0 || hora > 23){
        throw invalid_argument("\nError en la creacion de la FechaHora, se ingreso una hora menor a 0 o mayor a 23");
    }
    else{
        this->hora = hora;
    }

    if (minuto < 0 || minuto > 59){
        throw invalid_argument("\nError en la creacion de la FechaHora, se ingreso un minuto menor a 0 o mayor a 59");
    }
    else{
        this->minuto = minuto;
    }
}

int FechaHora::getHora(){
    return this->hora;
}

int FechaHora::getMinuto(){
    return this->minuto;
}

