#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED

#include "Conversacion.h"
#include "FechaHora.h"

using namespace std;

class Usuario;
class Mensaje;

class Grupo : public Conversacion{

    private:
        string nombre;
        string urlImagen;
        FechaHora creacion;
        map<string,Usuario*> administradores;
        map<string,Usuario*> receptores;

    public:
        Grupo(int,Usuario*,string,string,FechaHora);

        string getNombre();
        void setNombre(string);

        string getUrlImagen();
        void setUrlImagen(string);

        FechaHora getCreacion();
        void setCreacion(FechaHora);

        bool agregarAdministrador(Usuario*);
        bool agregarReceptor(Usuario*);

        DtConversacion* getDtConversacion();

        bool agregrarMensaje(Mensaje*);

        ~Grupo();

};

#endif // GRUPO_H_INCLUDED
