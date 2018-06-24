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

ostream& operator << (ostream& salida, FechaHora& fechaHora){
    string diaString;
    ostringstream diaConvert;
    if (fechaHora.getDia() < 10){
        diaConvert << "0" << fechaHora.getDia();
    }
    else{
        diaConvert << fechaHora.getDia();
    }
    diaString = diaConvert.str();

    string mesString;
    ostringstream mesConvert;
    if (fechaHora.getMes() < 10){
        mesConvert << "0" << fechaHora.getMes();
    }
    else{
        mesConvert << fechaHora.getMes();
    }
    mesString = mesConvert.str();

    string horaString;
    ostringstream horaConvert;
    if (fechaHora.getHora() < 10){
        horaConvert << "0" << fechaHora.getHora();
    }
    else{
        horaConvert << fechaHora.getHora();
    }
    horaString = horaConvert.str();

    string minutoString;
    ostringstream minutoConvert;
    if (fechaHora.getMinuto() < 10){
        minutoConvert << "0" << fechaHora.getMinuto();
    }
    else{
        minutoConvert << fechaHora.getMinuto();
    }
    minutoString = minutoConvert.str();

    salida <<
        diaString << "/" << mesString << "/" << fechaHora.getAnio()
            << " " << horaString << ":" << minutoString << "\n";
    return salida;
}

bool operator < (const FechaHora& l, FechaHora& r){
    if (l.anio < r.anio){
        return true;
    }
    else if (l.anio > r.anio){
        return false;
    }

    if (l.mes < r.mes){
        return true;
    }
    else if (l.mes > r.mes){
        return false;
    }

    if (l.dia < r.dia){
        return true;
    }
    else if (l.dia > r.dia){
        return false;
    }

    if (l.hora < r.hora){
        return true;
    }
    else if (l.hora > r.hora){
        return false;
    }

    if (l.minuto < r.minuto){
        return true;
    }
    else if (l.minuto > r.minuto){
        return false;
    }
    return false;
}
