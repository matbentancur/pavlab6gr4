#ifndef MULTIMEDIA_H_INCLUDED
#define MULTIMEDIA_H_INCLUDED

#include "Mensaje.h"

class Multimedia : public Mensaje{
    public:
        Multimedia();
        Multimedia(int,FechaHora,bool,Usuario*);
        ~Multimedia();

};

#endif // MULTIMEDIA_H_INCLUDED
