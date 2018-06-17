#ifndef GRUPO_H_INCLUDED
#define GRUPO_H_INCLUDED

#include "Conversacion.h"
#include "DtGrupo.h"
#include "FechaHora.h"

class Grupo : public Conversacion{

    private:
        string nombre;
        string urlImagen;
        FechaHora creacion;
        map<string,Usuario*> administradores;
        map<string,Usuario*> receptores;

    public:
        Grupo(int,string,string,string,FechaHora);

        string getNombre();
        string getUrlImagen();
        FechaHora getCreacion();

        void setNombre(string);
        void setUrlImagen(string);
        void setCreacion(FechaHora);

        bool agregarAdministrador(Usuario*);
        bool agregarReceptor(Usuario*);

        DtConversacion getDtConversacion();
        ~Grupo();

};

#endif // GRUPO_H_INCLUDED
