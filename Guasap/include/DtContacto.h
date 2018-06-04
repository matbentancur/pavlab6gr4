#ifndef DTCONTACTO_H
#define DTCONTACTO_H

#include <string>

using namespace std;

class DtContacto {

    private:
        string celular;
        string nombre;
        string imagen;

    public:
        DtContacto();
        DtContacto(string,string,string);
        virtual ~DtContacto();
        string getCelular();
        string getNombre();
        string getImagen();
};

#endif // DTCONTACTO_H
