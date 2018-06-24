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

ostream& operator << (ostream& salida, Fecha& fecha){
    string diaString;
    ostringstream diaConvert;
    if (fecha.getDia() < 10){
        diaConvert << "0" << fecha.getDia();
    }
    else{
        diaConvert << fecha.getDia();
    }
    diaString = diaConvert.str();

    string mesString;
    ostringstream mesConvert;
    if (fecha.getMes() < 10){
        mesConvert << "0" << fecha.getMes();
    }
    else{
        mesConvert << fecha.getMes();
    }
    mesString = mesConvert.str();

    salida <<
        diaString << "/" << mesString << "/" << fecha.getAnio() << "\n";
    return salida;
}
