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

class Usuario {

    private:
        string celular;
        string nombre;
        Fecha registro;
        string imagen;
        string descripcion;
        FechaHora ultimaConexion;
        map<string,Usuario*> contactos;

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
        set<DtConversacion*> obtenerConversacionesActivas();
        set<DtConversacion*> obtenerConversacionesArchivadas();
        set<DtMensaje*> obtenerMensajes(int);
//        set<DtReceptor*> verInfoMensaje(int);
//        DtReceptor getDtReceptor();
        void ingresarIdConversacion(int);
        set<DtConversacion*> obtenerConversaciones();
        bool buscarConversacion(int);
//        obtenerContacto(): DtContacto //repetida con getDtContacto.
        DtConversacion obtenerConversacion(int);
        bool iniciarConversacion(Usuario);

};

#endif // USUARIO_H
