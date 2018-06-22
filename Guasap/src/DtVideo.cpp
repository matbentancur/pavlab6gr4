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

ostream& operator << (ostream& salida, DtVideo& dtVideo) {
    salida <<
        "Codigo: " << dtVideo.codigo << "\n" <<
        "Enviado: " << dtVideo.enviado <<
        "Visto: " << dtVideo.visto << "\n" <<
        "URL: " << dtVideo.url << "\n" <<
        "Duracion: " << dtVideo.duracion << "\n";
    return salida;
}
