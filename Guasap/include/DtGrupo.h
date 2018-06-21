#ifndef DTGRUPO_H
#define DTGRUPO_H

#include <iostream>
#include "DtConversacion.h"
#include "FechaHora.h"

class DtGrupo : public DtConversacion {

    private:
        string nombre;
        string urlImagen;
        FechaHora creacion;

    public:
        DtGrupo();
        virtual ~DtGrupo();

        DtGrupo(int,string,string,FechaHora);

        string getNombre();
        string getUrlImagen();
        FechaHora getCreacion();

        void print();
        friend ostream& operator << (ostream &salida, DtGrupo&);
};

#endif // DTGRUPO_H
