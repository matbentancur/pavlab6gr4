#ifndef DTGRUPO_H
#define DTGRUPO_H

#include <string>
#include "DtConversacion.h"

using namespace std;

class DtGrupo : public DtConversacion {

    private:
        string nombre;

    public:
        DtGrupo();
        virtual ~DtGrupo();
        DtGrupo(int,string);
        string getNombre();
};

#endif // DTGRUPO_H
