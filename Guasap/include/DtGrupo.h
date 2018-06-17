#ifndef DTGRUPO_H
#define DTGRUPO_H

#include "DtConversacion.h"
#include "FechaHora.h"

class DtGrupo : public DtConversacion {

    private:
        string urlImagen;
        FechaHora creacion;

    public:
        DtGrupo();
        virtual ~DtGrupo();

        DtGrupo(int,string,string,FechaHora);

        string getUrlImagen();
        FechaHora getCreacion();
};

#endif // DTGRUPO_H
