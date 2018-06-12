#include "Fecha.h"

Fecha::Fecha()
{
    //ctor
}

Fecha::~Fecha()
{
    //dtor
}

Fecha::Fecha (int dia,int mes,int anio){
    if (dia < 1 || dia > 31){
        throw invalid_argument("\nError en la creacion de la Fecha, se ingreso un dia < 1 dia > 31");
    }
    else{
        this->dia = dia;
    }

    if (mes < 1 || mes > 12){
        throw invalid_argument("\nError en la creacion de la Fecha, se ingreso un mes < 1 o mes > 12");
    }
    else{
        this->mes = mes;
    }

    if (anio < 1900){
        throw invalid_argument("\nError en la creacion de la Fecha, se ingreso un anio < 1900");
    }
    else{
        this->anio = anio;
    }
}

int Fecha::getDia(){
    return this->dia;
}

int Fecha::getMes(){
    return this->mes;
}

int Fecha::getAnio(){
    return this->anio;
}
