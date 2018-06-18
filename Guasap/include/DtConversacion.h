#ifndef DTCONVERSACION_H
#define DTCONVERSACION_H

#include <string>

using namespace std;

class DtConversacion {

    private:
        int idConversacion;
        string nombre;

    public:
        DtConversacion();
        DtConversacion(int,string);

        virtual ~DtConversacion();

        int getIdConversacion();
        string getNombre();
};

#endif // DTCONVERSACION_H
