#include "Video.h"

Video::Video(DtVideo &dtVideo){
    this->setUrl(dtVideo.getUrl());
    this->setDuracion(dtVideo.getDuracion());

}

Video::Video(string url, int duracion){
    this->url      = url;
    this->duracion = duracion;
}

string Video::getUrl(){
    return this->url;
}

int Video::getDuracion(){
    return this->duracion;
}

void Video::setUrl(string url){
    this->url = url;
}

void Video::setDuracion(int duracion){
    this->duracion = duracion;
}

DtVideo Video::getDtMensaje(){

}

Video::~Video(){}

