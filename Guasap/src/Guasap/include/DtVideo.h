#ifndef DTVIDEO_H
#define DTVIDEO_H

#include <string>
#include "DtMensaje.h"

class DtVideo : public DtMensaje {
    private:
        string url;
        int duracion;

    public:
        DtVideo();
        DtVideo(int, FechaHora, bool, string, int);
        virtual ~DtVideo();
        string getUrl();
        int getDuracion();
};

#endif // DTVIDEO_H
