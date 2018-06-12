#include "Video.h"

Video::Video(int codigo, FechaHora enviado, bool visto, string url, int duracion) : Multimedia(codigo,enviado, visto){
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

DtMensaje Video::getDtMensaje(){
    DtVideo dtVideo = DtVideo(this->codigo, this->enviado, this->visto, this->url, this->duracion);
    return dtVideo;
}

Video::~Video(){}

