#ifndef DTGRUPO_H
#define DTGRUPO_H

#include <iostream>
#include "DtConversacion.h"
#include "FechaHora.h"

class DtGrupo : public DtConversacion {

    private:
        string urlImagen;
        FechaHora creacion;

    public:
        DtGrupo();
        ~DtGrupo();

        DtGrupo(int,string,string,FechaHora);

        string getUrlImagen();
        FechaHora getCreacion();

        friend ostream& operator << (ostream &salida, DtGrupo&);
};

#endif // DTGRUPO_H
