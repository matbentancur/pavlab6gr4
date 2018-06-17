#include "DtVideo.h"

DtVideo::DtVideo()
{
    //ctor
}

DtVideo::~DtVideo()
{
    //dtor
}

DtVideo::DtVideo(string url, int duracion) : DtMensaje(){
    this->url = url;
    this->duracion = duracion;
}

DtVideo::DtVideo(int codigo, FechaHora enviado, bool visto, string url, int duracion) : DtMensaje(codigo, enviado, visto){
    this->url = url;
    this->duracion = duracion;
}

string DtVideo::getUrl(){
    return this->url;
}

int DtVideo::getDuracion(){
    return this->duracion;
}
