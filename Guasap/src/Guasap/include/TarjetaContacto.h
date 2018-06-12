#ifndef TARJETACONTACTO_H_INCLUDED
#define TARJETACONTACTO_H_INCLUDED

#include "DtTarjetaContacto.h"
#include "Mensaje.h"

class TarjetaContacto : public Mensaje{

    private:
        string nombre;
        string telefono;
    public:
        TarjetaContacto(DtTarjetaContacto&);
        TarjetaContacto(int,FechaHora,bool,string,string);

        string getNombre();
        void setNombre();
        string getTelefono();
        void setTelefono();

        ~TarjetaContacto();
        DtTarjetaContacto getDtMensaje();
};

#endif // TARJETACONTACTO_H_INCLUDED
