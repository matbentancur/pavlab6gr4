#ifndef MULTIMEDIA_H_INCLUDED
#define MULTIMEDIA_H_INCLUDED

#include "Mensaje.h"

class Multimedia : public Mensaje{
    public:
        Multimedia(int,FechaHora,bool);
        ~Multimedia();

};

#endif // MULTIMEDIA_H_INCLUDED