#ifndef DTVIDEO_H
#define DTVIDEO_H

#include <string>
#include <iostream>
#include "DtMensaje.h"

class DtVideo : public DtMensaje {
    private:
        string url;
        int duracion;

    public:
        DtVideo();
        DtVideo(string, int);
        DtVideo(int, FechaHora, bool, string, int);
        virtual ~DtVideo();
        string getUrl();
        int getDuracion();

        friend ostream& operator << (ostream &salida, DtVideo&);
};

#endif // DTVIDEO_H
