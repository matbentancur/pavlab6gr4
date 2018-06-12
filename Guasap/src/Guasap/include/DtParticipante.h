#ifndef DTPARTICIPANTE_H_INCLUDED
#define DTPARTICIPANTE_H_INCLUDED

#include <string>
#include "FechaHora.h"

using namespace std;

class DtParticipante{

    private:
        string celular;
        string nombre;
        bool administrador;
        FechaHora vistoFechaHora;

    public:
        DtParticipante();
        DtParticipante(string,string,bool,FechaHora);
        virtual ~DtParticipante();
        string getCelular();
        string getNombre();
        bool getAdministrador();
        FechaHora getFechaHora();
};

#endif // DTPARTICIPANTE_H_INCLUDED
