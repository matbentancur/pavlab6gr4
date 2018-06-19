#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include "FechaHora.h"

class Almacenamiento {
    private:
        FechaHora reloj;
        int ultimoIdConversacion;
        int ultimoCodigoMensaje;

        static Almacenamiento* instancia;
        Almacenamiento(FechaHora,int,int);

    public:
        FechaHora getReloj();
        void setReloj(FechaHora);

        int getUltimoIdConversacion();
        void setUltimoIdConversacion(int);

        int getUltimoCodigoMensaje();
        void setUltimoCodigoMensaje(int);

        static Almacenamiento* getInstancia();
        virtual ~Almacenamiento();
};

#endif // ALMACENAMIENTO_H
