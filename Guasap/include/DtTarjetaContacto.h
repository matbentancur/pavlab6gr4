#ifndef DTTARJETACONTACTO_H
#define DTTARJETACONTACTO_H

#include <string>
#include "DtMensaje.h"

class DtTarjetaContacto : public DtMensaje {

    private:
        string nombre;
        string telefono;

    public:
        DtTarjetaContacto();
        DtTarjetaContacto(int, FechaHora, bool, Usuario*, string, string);
        virtual ~DtTarjetaContacto();
        string getNombre();
        string getTelefono();
};

#endif // DTTARJETACONTACTO_H
