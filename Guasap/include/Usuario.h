#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <map>
#include "Fecha.h"
#include "FechaHora.h"
#include "DtContacto.h"
#include "DtConversacion.h"
#include "DtMensaje.h"
#include "DtReceptor.h"
#include "UsuarioConversacion.h"

class UsuarioConversacion;

using namespace std;

class Usuario {

    private:
        string celular;
        string nombre;
        Fecha registro;
        string imagen;
        string descripcion;
        FechaHora ultimaConexion;
        map<string,Usuario*> contactos;
        set<UsuarioConversacion*> usuarioConversacion;

    public:
        Usuario();
        Usuario(string, string);
        Usuario(string, string,string,string);
        virtual ~Usuario();

        string getCelular();
        void setCelular(string);

        string getNombre();
        void setNombre(string);

        Fecha getRegistro();
        void setRegistro(Fecha);

        string getImagen();
        void setImagen(string);

        string getDescripcion();
        void setDescripcion(string);

        FechaHora getUltimaConexion();
        void setUltimaConexion(FechaHora);

        map<string,DtContacto> obtenerContactos();
        DtContacto getDtContacto();
        bool agregarContacto(Usuario*);
        map<int,DtConversacion> obtenerConversacionesActivas();
        map<int,DtConversacion> obtenerConversacionesArchivadas();
        map<int,DtMensaje> obtenerMensajes(int);
        map<string,DtReceptor> verInfoMensaje(int,int);
        bool archivarConversacion(int);

        bool agregarUsuarioConversacion(UsuarioConversacion*);

        bool buscarConversacion(int);
//        obtenerContacto(): DtContacto //repetida con getDtContacto.
        DtConversacion obtenerConversacion(int);
        bool iniciarConversacion(Usuario);

};

#endif // USUARIO_H
