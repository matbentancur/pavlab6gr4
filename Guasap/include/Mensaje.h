#ifndef MENSAJE_H_INCLUDED
#define MENSAJE_H_INCLUDED

#include "FechaHora.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include <set>

using namespace std;

class Mensaje{

    protected:
        int codigo;
        FechaHora enviado;
        bool visto;
    public:
        Mensaje(DtMensaje&);
        Mensaje(int,FechaHora,bool);

        int getCodigo();
        void setCodigo(int);
        FechaHora getEnviado();
        void setEnviado(FechaHora);
        bool getVisto();
        void setVisto(bool);

        ~Mensaje();
//        virtual DtMensaje getDtMensaje() = 0;
        set <DtReceptor*> getReceptores();
};

#endif // MENSAJE_H_INCLUDED
