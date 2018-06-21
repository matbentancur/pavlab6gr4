#ifndef DTTARJETACONTACTO_H
#define DTTARJETACONTACTO_H

#include <string>
#include <iostream>
#include "DtMensaje.h"

class DtTarjetaContacto : public DtMensaje {

    private:
        string nombre;
        string telefono;

    public:
        DtTarjetaContacto();
        DtTarjetaContacto(string, string);
        DtTarjetaContacto(int, FechaHora, bool, string, string);
        virtual ~DtTarjetaContacto();
        string getNombre();
        string getTelefono();

        friend ostream& operator << (ostream &salida, DtTarjetaContacto&);
};

#endif // DTTARJETACONTACTO_H
