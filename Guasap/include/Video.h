#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include "DtVideo.h"
#include "Multimedia.h"

class Video : public Multimedia{

    private:
        string url;
        int duracion;
    public:
        Video(int,FechaHora,bool,Usuario*,string,int);
        string getUrl();
        int getDuracion();
        void setUrl(string);
        void setDuracion(int);

        DtMensaje getDtMensaje();
        ~Video();
};

#endif // VIDEO_H_INCLUDED
