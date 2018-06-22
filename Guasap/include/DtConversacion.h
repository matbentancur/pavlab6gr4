#ifndef DTCONVERSACION_H
#define DTCONVERSACION_H

#include <iostream>
#include <string>

using namespace std;

class DtConversacion {

    protected:
        int idConversacion;
        string nombre;

    public:
        DtConversacion();
        DtConversacion(int,string);

        virtual ~DtConversacion();

        int getIdConversacion();
        string getNombre();

        friend ostream& operator << (ostream &salida, DtConversacion&);

};

#endif // DTCONVERSACION_H
