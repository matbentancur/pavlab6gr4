#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <typeinfo>
#include <exception>
#include "UsuarioFactory.h"
#include "ConversacionFactory.h"
#include "MensajeFactory.h"
#include "FechaHora.h"
#include "Almacenamiento.h"
#include "DtConversacion.h"
#include "DtGrupo.h"
#include "DtPrivada.h"
#include "DtSimple.h"
#include "DtImagen.h"
#include "DtVideo.h"
#include "DtContacto.h"

using namespace std;

//FUNCIONES AUXILIARES
void menuPrincipal();
void menuCerrarGuasap();
void menuAgregarContactos();
void menuAltaGrupo();
void menuArchivarConversacion();
void menuModificarUsuario();
void menuEnviarMensaje();
DtMensaje* menuNuevoMensaje();
void menuVerMensaje();
int menuVerInfoMensaje();
void menuEliminarMensaje();
void menuModificarReloj();
void menuConsultarReloj();
void menuCargarDatosPrueba();
void listarContactos();
void listarConversacionesActivas();
void listarConversacionesArchivadas();
int cantidadConversacionesArchivadas();
void listarMensajes(int);
void listarReceptores(int);
void listarContactosElegidos();
void listarContactosRestantes();

UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();

ConversacionFactory* conversacionFactory = ConversacionFactory::getInstancia();
IConversacionController* iConversacionController = conversacionFactory->getIConversacionController();

MensajeFactory* mensajeFactory = MensajeFactory::getInstancia();
IMensajeController* iMensajeController = mensajeFactory->getIMensajeController();

int main() {
    int numOper = 0;
    string celularIngresado, celularContacto, nombre, urlImagen, descripcion, textoMensaje, urlVideo, formatoMensaje, tamanioMensaje, descripcionMensaje, duracionMensaje = "";
    bool salir = false;
    bool existeUsuario = false;
    bool ingresarOtroNumero = true;
    char opcion = 'n';
    do {
        menuPrincipal();
        cin >> numOper;
        switch (numOper) {
            case 1: {
                cout << "\n\tAbrir Guasap\n";
                cout << "\nIngrese el numero de celular: ";
                cin >> celularIngresado;
                do {
                    EstadoIngreso estadoIngreso = iUsuarioController->ingresar(celularIngresado);
                    switch(estadoIngreso){
                    case userOK: {
                        cout << "\nIniciando sesion...\n";
                        cout << "\nSesion iniciada con exito - Celular: " + celularIngresado + "\n";
                        ingresarOtroNumero = false;
                        cin.get();
                        break;
                    }
                    case userInexistente:
                        cout << "\nNo existe un usuario con ese numero de celular.\n";
                        do {
                            cout << "\nLista de operaciones disponibles:\n\n";
                            cout << "1)  Ingresar otro numero\n";
                            cout << "2)  Darse de alta con el numero " + celularIngresado + " \n";
                            cout << "3)  Cancelar (volver al menu principal)\n";
                            cout << "\nIngrese el numero de la operacion a realizar: ";
                            cin >> numOper;
                            switch (numOper) {
                            case 1:
                                ingresarOtroNumero = true;
                                existeUsuario = true;
                                cout << "\nIngrese el numero de celular: ";
                                cin >> celularIngresado;
                                break;
                            case 2: {
                                cout << "\nCrear un usuario\n";
                                cout << "\nIngrese el nombre: ";
                                cin >> nombre;
                                cout << "\nIngrese la URL de la imagen: ";
                                cin >> urlImagen;
                                cout << "\nIngrese una descripcion: ";
                                cin >> descripcion;
                                try{
                                    FechaHora fechaHora = iUsuarioController->crearUsuario(celularIngresado, nombre, urlImagen, descripcion);
                                    cout << "\nSe agrego con exito al usuario: " + nombre + ", con celular: " + celularIngresado;
                                    cout << "\n\nIniciando sesion...\n";
                                    cout << "\nSesion iniciada con exito - Celular: " + celularIngresado + "\n";
                                }catch(invalid_argument& ia){
                                    cout << ia.what() << "\n";
                                    cin.get();
                                }
                                ingresarOtroNumero = false;
                                existeUsuario = true;
                                break;
                            }
                            case 3: {
                                ingresarOtroNumero = false;
                                existeUsuario = true;
                                break;
                            }
                            default:
                                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                            }
                        } while (!existeUsuario);
                        break;
                    case igualUserLog:
                        cout << "\nYa hay una sesion iniciada con el numero de celular: " + celularIngresado;
                        ingresarOtroNumero = false;
                        cin.get();
                        break;
                    case distintoUserLog: {
                        cout << "\nYa hay una sesion iniciada. \nDebe cerrar la sesion actual para inciar sesion con el celular: " + celularIngresado;
                        cout << "\n\nCerrar sesion actual? (s/n): ";
                        cin >> opcion;
                        if (opcion == 's' || opcion == 'S') {
                            cout << "\n\nCerrando sesion...\n";
                            iUsuarioController->cerrarGuasap();
                            cout << "\nSesion cerrada con exito.";
                            ingresarOtroNumero = true;
                        }
                        cin.get();
                        break;
                    }
                    }
            } while (ingresarOtroNumero);
            }
            break;
            case 2: {
                try{
                    menuCerrarGuasap();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            }
            case 3: {
                try{
                    menuAgregarContactos();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            }
            case 4:
                try{
                    menuAltaGrupo();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 5:
                try {
                    menuEnviarMensaje();
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 6:
                try{
                    menuVerMensaje();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 7:
                try{
                    menuArchivarConversacion();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 8:
                try{
                    menuModificarUsuario();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 9:
                try{
                    menuEliminarMensaje();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 10:
                try{
                    menuModificarReloj();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 11:
                try{
                    menuConsultarReloj();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 12:
                try{
                    menuCargarDatosPrueba();
                }
                catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 13:
              cout << "\nEsta seguro de que desea salir? (s/n): ";
              cin >> opcion;
              if (opcion == 's' || opcion == 'S') {
                cout << "\nSaliendo...\n";
                salir = true;
              }
              break;
            default:
                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                cin.get();
        }
        cout << "\nPresione Enter Para continuar";
        fflush(stdin);
        cin.ignore();
    } while (!salir);

    return 0;
}

void menuPrincipal() {
    cout << string( 50, '\n' );
    cout << "  #####                                     \n";
    cout << " #     # #    #   ##    ####    ##   #####  \n";
    cout << " #       #    #  #  #  #       #  #  #    # \n";
    cout << " #  #### #    # #    #  ####  #    # #    # \n";
    cout << " #     # #    # ######      # ###### #####  \n";
    cout << " #     # #    # #    # #    # #    # #      \n";
    cout << "  #####   ####  #    #  ####  #    # #      \n";
    cout << "\nProgramacion Avanzada - Laboratorio 6\n\n";
    cout << "Lista de operaciones disponibles:\n\n";
    cout << "1)  Abrir Guasap\n";
    cout << "2)  Cerrar Guasap\n";
    cout << "3)  Agregar contactos\n";
    cout << "4)  Alta grupo\n";
    cout << "5)  Enviar mensajes\n";
    cout << "6)  Ver mensajes\n";
    cout << "7)  Archivar conversaciones\n";
    cout << "8)  Modificar usuario\n";
    cout << "9)  Eliminar mensajes\n";
    cout << "10) Modificar fecha del sistema\n";
    cout << "11) Consultar fecha del sistema\n";
    cout << "12) Inicializar/cargar un conjunto de datos de prueba\n";
    cout << "13) Salir\n\n";
    cout << "Ingrese el numero de la operacion a realizar: ";
}

void menuCerrarGuasap(){
    char opcion;
    try{
        cout << "\n\tCerrar Guasap\n";
        cout << "\nCerrar sesion actual? (s/n): ";
        cin >> opcion;
        if (opcion == 's' || opcion == 'S') {
            iUsuarioController->cerrarGuasap();
            cout << "\n\nCerrando sesion...\n";
            cout << "\nSesion cerrada con exito.";
            cin.get();
        }
    }catch(logic_error& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void menuAgregarContactos(){
    int opcion;
    char confirmar;
    string celularContacto;
    try {
        cout << "\n\nLista de contactos\n\n";
        listarContactos();
        cout << "\n\nLista de operaciones disponibles:\n\n";
        cout << "1)  Agregar nuevo contacto\n";
        cout << "2)  Volver\n";
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                try{
                    cout << "\nIngrese el celular que desea agregar: ";
                    cin >> celularContacto;
                    DtContacto dtContacto = iUsuarioController->agregarContacto(celularContacto);
                    cout << "\n";
                    cout << dtContacto;
                    cout << "\nPresione \"s\" para confirmar la accion: ";
                    cin >> confirmar;
                    if (confirmar == 's' || confirmar == 'S') {
                        if(iUsuarioController->confirmarContacto()){
                            cout << "\nSe agrego con exito al usuario.";
                        }else{
                            cout << "\nYa es contacto del usuario con celular: " + celularContacto + "\n";
                        }
                    }
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                cin.get();
                break;
            case 2:
                menuPrincipal();
                break;
            default:
                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                cin.get();
        }
    }catch(logic_error& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void menuAltaGrupo(){
    string nomGrupo;
    string urlGrupo;
    string celularContacto;
    int opGrupo;
    bool salirGrupo = false;
    try {
        do{
            cout << "\n\nContactos elegidos:\n\n";
            listarContactosElegidos();
            cout << "\nContactos restantes:\n\n";
            listarContactosRestantes();
            cout << "\nLista de operaciones disponibles:\n\n";
            cout<< "1)  Agregar contactos al grupo\n";
            cout<< "2)  Quitar contactos al grupo\n";
            cout<< "3)  Continuar con la creacion del grupo\n";
            cout<< "4)  Volver\n";
            cout << "\nIngrese una opcion: ";
            cin>> opGrupo;
            switch(opGrupo){
                case 1:
                    cout << "\nIngrese el celular del contacto que quiere agregar al grupo: ";
                    cin >> celularContacto;
                    if(iConversacionController->agregarSeleccionContactoGrupo(celularContacto)){
                        cout<< "\nContacto agregado con exito.\n";
                    }
                    break;
                case 2: {
                    map<string,DtContacto> elegidos = iConversacionController->listarContactosElegidos();
                    if(elegidos.size() == 0){
                        cout << "\nDebe elegir al menos un contacto para crear el grupo.\n";
                        cout << "\nLista de operaciones disponibles:\n\n";
                        cout<< "1)  Volver al menu alta grupo\n";
                        cout<< "2)  Volver al menu principal\n";
                        cout << "\nIngrese una opcion: ";
                        cin>> opGrupo;
                        switch(opGrupo){
                            case 1:
                                menuAltaGrupo();
                                break;
                            case 2:
                                salirGrupo = true;
                                menuPrincipal();
                                break;
                        }
                    }else{
                        cout << "\nIngrese el celular del contacto que quiere eliminar del grupo: ";
                        cin >> celularContacto;
                        if(iConversacionController->quitarSeleccionContactoGrupo(celularContacto)){
                            cout<< "\nContacto eliminado con exito.\n";
                        }
                    }
                    break;
                }
                case 3: {
                    map<string,DtContacto> elegidos = iConversacionController->listarContactosElegidos();
                    if(elegidos.size() == 0){
                        cout << "\nDebe elegir al menos un contacto para crear el grupo.\n";
                        cout << "\nLista de operaciones disponibles:\n\n";
                        cout<< "1)  Volver al menu alta grupo\n";
                        cout<< "2)  Volver al menu principal\n";
                        cout << "\nIngrese una opcion: ";
                        cin>> opGrupo;
                        switch(opGrupo){
                        case 1:
                            menuAltaGrupo();
                            break;
                        case 2:
                            salirGrupo = true;
                            menuPrincipal();
                            break;
                        }
                    }else{
                        cout<< "\nIngrese el nombre del grupo: ";
                        cin>> nomGrupo;
                        cout<< "\nIngrese URL del grupo: ";
                        cin>> urlGrupo;
                        if(iConversacionController->altaGrupo(nomGrupo,urlGrupo)){
                            cout<< "\n\nSe creo el grupo con nombre " + nomGrupo + " y URL " + urlGrupo + "\n";
                        }
                        salirGrupo = true;
                    }
                    cin.get();
                    break;
                }
                case 4:
                    salirGrupo = true;
                    menuPrincipal();
                    break;
                default:
                    cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                    cin.get();
            }
        } while(!salirGrupo);
    }catch(logic_error& ia){
        cout<< ia.what()<<"\n";
        cin.get();
    }
}

void menuArchivarConversacion(){
    int opcion;
    int idConversacion;
    cout << "\n\nArchivar conversaciones\n";
    try {
        cout << "\n\nLista de conversaciones\n";
        cout << "\nActivas:\n\n";
        listarConversacionesActivas();
        cout << "\n\nLista de operaciones disponibles:\n\n";
        cout << "1)  Archivar una conversacion\n";
        cout << "2)  Volver\n";
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\nIngrese el identificador de la conversacion: ";
                cin >> idConversacion;
                try{
                    if (iConversacionController->archivarConversacion(idConversacion)){
                        cout << "\nSe ha archivado la conversacion " << idConversacion << "\n";
                    }
                    else{
                        cout << "\nNo se pudo archivar la conversacion " << idConversacion << "\n";
                    }
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                cin.get();
                break;
            case 2:
                menuPrincipal();
                break;
            default:
                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                cin.get();
        }
    }catch(logic_error& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void menuModificarUsuario() {
    string nombre;
    string urlImagen;
    string descripcion;
    try{
        FechaHora reloj = iUsuarioController->consultarReloj();
    }catch(invalid_argument& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
    try{
        cout << "\n\tModificar usuario\n\n";
        cout << "\nIngrese el nuevo nombre: ";
        cin >> nombre;
        cout << "\nIngrese la nueva URL de la imagen: ";
        cin >> urlImagen;
        cout << "\nIngrese una nueva descripcion: ";
        cin >> descripcion;
        DtContacto dtContacto = iUsuarioController->modificarUsuario(nombre, urlImagen, descripcion);
        cout << "\nLos datos se modificaron con exito.\n\n";
        cout << dtContacto;
        cin.get();
    }catch(logic_error& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void menuEnviarMensaje() {
    int numOper;
    int idConversacion;
    string celularIngresado, celularContacto, nombre, urlImagen, descripcion, textoMensaje, urlVideo, formatoMensaje, tamanioMensaje, descripcionMensaje, duracionMensaje = "";
    cout << "\n\nLista de conversaciones\n\n";
    cout << "\nActivas:\n\n";
    listarConversacionesActivas();
    cout << "\nArchivadas: ";
    cout << cantidadConversacionesArchivadas();
    cout << "\n\nLista de operaciones disponibles:\n\n";
    cout << "1)  Seleccionar una conversacion activa\n";
    cout << "2)  Ver las conversaciones archivadas\n";
    cout << "3)  Enviar un mensaje nuevo\n";
    cout << "4)  Volver\n";
    cout << "\nIngrese una opcion: ";
    cin >> numOper;
    switch (numOper) {
    case 1: {
        cout << "\nIngrese el identificador de la conversacion: ";
        cin >> idConversacion;
        DtMensaje* dtMensaje = menuNuevoMensaje();
        iMensajeController->listarMensajes(idConversacion);
        if(iMensajeController->enviarMensajeConversacion(dtMensaje)){
            cout << "\nEl mensaje se envio con exito.";
        }else{
            cout << "\nOcurrio un error y el mensaje no se pudo enviar.";
        }
        cin.get();
        break;
    }
    case 2:
        cout << "\n\nConversaciones archivadas:\n";
        listarConversacionesArchivadas();
        if(cantidadConversacionesArchivadas() > 0){
            cout << "\nIngrese el identificador de la conversacion: ";
            cin >> idConversacion;
            DtMensaje* dtMensaje = menuNuevoMensaje();
            iMensajeController->listarMensajes(idConversacion);
            if(iMensajeController->enviarMensajeConversacion(dtMensaje)){
                cout << "\nEl mensaje se envio con exito.\n";
                iConversacionController->activarConversacion(idConversacion);
            }else{
                cout << "\nOcurrio un error y el mensaje no se pudo enviar.\n";
            }
        }
        cin.get();
        break;
    case 3: {
        cout << "\n\nLista de contactos\n\n";
        listarContactos();
        cout << "Ingrese el numero de celular con el que desea iniciar una nueva conversacion: ";
        cin >> celularContacto;
        DtMensaje* dtMensaje = menuNuevoMensaje();
        if(iMensajeController->enviarMensajeNuevaConversacion(celularContacto, dtMensaje)){
            cout << "\nEl mensaje se envio con exito.\n";
        }else{
            cout << "\nOcurrio un error y el mensaje no se pudo enviar.\n";
        }
        cin.get();
        break;
    }
    case 4:
        menuPrincipal();
        break;
    default:
        cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
        cin.get();
    }
}

DtMensaje* menuNuevoMensaje(){
    char opcion;
    int numOper;
    int tamanio;
    int duracion;
    DtMensaje* dtMensaje = new DtMensaje();
    string celularIngresado, celularContacto, nombre, url, descripcion, texto, formato = "";
    cout << "\n\tTipo de mensaje a enviar\n\n";
    cout << "1)  Simple\n";
    cout << "2)  Imagen\n";
    cout << "3)  Video\n";
    cout << "4)  Contacto\n";
    cout << "\nIngrese una opcion: ";
    cin >> numOper;
    switch(numOper){
        case 1: {
            cout << "\n\tMensaje Simple\n";
            cout << "\nIngrese el texto del mensaje: ";
            cin >> texto;
            DtSimple* dtMensaje = new DtSimple(texto);
            return dtMensaje;
        }
        case 2: {
            cout << "\n\tMensaje de Imagen\n";
            cout << "\nIngrese la URL de la imagen: ";
            cin >> url;
            cout << "\nIngrese el formato de la imagen: ";
            cin >> formato;
            cout << "\nIngrese el tamanio de la imagen: ";
            cin >> tamanio;
            cout << "\n\nQuiere ingresar un texto descriptivo? (s/n): ";
            cin >> opcion;
            descripcion = "";
            if (opcion == 's' || opcion == 'S') {
                cout << "\nIngrese una descripcion: ";
                cin >> descripcion;
            }
            DtImagen* dtMensaje = new DtImagen(url, formato, tamanio, descripcion);
            return dtMensaje;
        }
        case 3: {
            cout << "\n\tMensaje de Video\n";
            cout << "\nIngrese la URL del video: ";
            cin >> url;
            cout << "\nIngrese la duracion del video: ";
            cin >> duracion;
            DtVideo* dtMensaje = new DtVideo(url, duracion);
            return dtMensaje;
        }
        case 4: {
            cout << "\n\tMensaje de Contacto\n";
            map<string,DtContacto> contactos = iUsuarioController->listarContactos();
            map<string,DtContacto>::iterator i;
            if(contactos.size() == 0){
                cout << "\nLa lista de contactos esta vacia.\n";
            }else{
                for(i = contactos.begin(); i != contactos.end(); ++i){
                    cout << i->second << "\n";
                }
            }
            cout << "\nIngrese el numero de celular del contacto que desea compartir: ";
            cin >> celularContacto;
            for(i = contactos.begin(); i != contactos.end(); ++i){
                if(i->second.getCelular() == celularContacto){
                    DtTarjetaContacto* dtMensaje = new DtTarjetaContacto(i->second.getNombre(), celularContacto);
                    return dtMensaje;
                }
            }
        }
        default:
            cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
            cin.get();
    }
    return dtMensaje;
}

void menuVerMensaje() {
    int opcion;
    int idConversacion;
    cout << "\n\nVer mensajes";
    try {
        cout << "\n\nLista de conversaciones\n\n";
        cout << "\nActivas:\n\n";
        listarConversacionesActivas();
        cout << "\nArchivadas: ";
        cout << cantidadConversacionesArchivadas();
        cout << "\n\nLista de operaciones disponibles:\n\n";
        cout << "1)  Ver mensajes de una conversacion activa\n";
        cout << "2)  Ver las conversaciones archivadas\n";
        cout << "3)  Volver\n";
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\nIngrese el identificador de la conversacion: ";
                cin >> idConversacion;
                do{
                    cout << "\n";
                    listarMensajes(idConversacion);
                } while(menuVerInfoMensaje() != 2);
                menuVerMensaje();
                break;
            case 2:
                cout << "\n\nLista de conversaciones\n\n";
                cout << "\nArchivadas:\n\n";
                listarConversacionesArchivadas();
                if(cantidadConversacionesArchivadas() > 0){
                    cout << "\n\nLista de operaciones disponibles:\n\n";
                    cout << "1)  Ver mensajes de una conversacion archivada\n";
                    cout << "2)  Volver\n";
                    cout << "Ingrese una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                        case 1:
                            cout << "\nIngrese el identificador de la conversacion: ";
                            cin >> idConversacion;
                            do{
                                listarMensajes(idConversacion);
                            } while(menuVerInfoMensaje() != 2);
                            menuVerMensaje();
                            break;
                        case 2:
                            menuVerMensaje();
                            break;
                    }
                }
                break;
            case 3:
                menuPrincipal();
                break;
            default:
                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                cin.get();
        }
    }catch(logic_error& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

int menuVerInfoMensaje(){
    int opcion;
    int codigoMensaje;
    cout << "\n\nLista de operaciones disponibles:\n\n";
    cout << "1)  Ver información del mensaje\n";
    cout << "2)  Volver\n";
    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            cout << "\nIngrese el codigo del mensaje: ";
            cin >> codigoMensaje;
            cout << "\n";
            listarReceptores(codigoMensaje);
            cin.get();
            cin.get();
            break;
    }
    return opcion;
}

void menuEliminarMensaje() {
    int opcion;
    int idConversacion;
    int codigoMensaje;
    cout << "\n\tEliminar mensajes";
    try {
        cout << "\n\nLista de conversaciones\n\n";
        cout << "\nActivas:\n\n";
        listarConversacionesActivas();
        cout << "\nArchivadas: ";
        cout << cantidadConversacionesArchivadas();
        cout << "\n\nLista de operaciones disponibles:\n\n";
        cout << "1)  Ver mensajes de una conversacion activa\n";
        cout << "2)  Ver las conversaciones archivadas\n";
        cout << "3)  Volver\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "\nIngrese el identificador de la conversacion: ";
                cin >> idConversacion;
                listarMensajes(idConversacion);
                cout << "\n\nLista de operaciones disponibles:\n\n";
                cout << "1)  Eliminiar mensaje\n";
                cout << "2)  Volver\n";
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch (opcion) {
                    case 1:
                        cout << "\nIngrese el codigo del mensaje: ";
                        cin >> codigoMensaje;
                        try{
                            if (iMensajeController->eliminarMensaje(codigoMensaje)){
                                cout << "Se ha eliminado el mensaje " << codigoMensaje;
                            }
                            else{
                                cout << "No se pudo eliminar el mensaje " << codigoMensaje;
                            }
                        }catch(logic_error& ia){
                            cout << ia.what() << "\n";
                            cin.get();
                        }
                        cin.get();
                        break;
                    case 2:
                        menuEliminarMensaje();
                        break;
                    default:
                        cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                        cin.get();
                }
                cin.get();
                break;
            case 2:
                cout << "\n\nLista de conversaciones\n\n";
                cout << "\nArchivadas:\n\n";
                listarConversacionesArchivadas();
                if(cantidadConversacionesArchivadas() > 0){
                    cout << "\n\nLista de operaciones disponibles:\n\n";
                    cout << "1)  Ver mensajes de una conversacion archivada\n";
                    cout << "2)  Volver\n";
                    cout << "Ingrese una opcion: ";
                    cin >> opcion;
                    switch (opcion) {
                        case 1:
                            cout << "\nIngrese el identificador de la conversacion: ";
                            cin >> idConversacion;
                            listarMensajes(idConversacion);
                            cout << "\n\nLista de operaciones disponibles:\n\n";
                            cout << "1)  Eliminiar mensaje\n";
                            cout << "2)  Volver\n";
                            cout << "Ingrese una opcion: ";
                            cin >> opcion;
                            switch (opcion) {
                                case 1:
                                    cout << "\nIngrese el codigo del mensaje: ";
                                    cin >> codigoMensaje;
                                    try{
                                        if (iMensajeController->eliminarMensaje(codigoMensaje)){
                                            cout << "Se ha eliminado el mensaje " << codigoMensaje;
                                        }
                                        else{
                                            cout << "No se pudo eliminar el mensaje " << codigoMensaje;
                                        }
                                    }catch(logic_error& ia){
                                        cout << ia.what() << "\n";
                                        cin.get();
                                    }
                                    cin.get();
                                    break;
                                case 2:
                                    menuEliminarMensaje();
                                    break;
                                default:
                                    cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                                    cin.get();
                            }
                            cin.get();
                            break;
                        }
                    }
                break;
            case 3:
                menuPrincipal();
                break;
            default:
                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
                cin.get();
        }
    }catch(logic_error& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void menuModificarReloj() {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    try{
        FechaHora reloj = iUsuarioController->consultarReloj();
        cout << "La fecha/hora es " << reloj;
    }catch(invalid_argument& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
    cout << "\n\tModificar fecha del sistema\n\n";
    cout << "Ingrese dia\n";
    cin >> dia;
    cout << "Ingrese mes\n";
    cin >> mes;
    cout << "Ingrese anio\n";
    cin >> anio;
    cout << "Ingrese hora\n";
    cin >> hora;
    cout << "Ingrese minuto\n";
    cin >> minuto;
    try{
        FechaHora fechaHora = FechaHora(dia, mes, anio, hora, minuto);
        iUsuarioController->modificarReloj(fechaHora);
        cout << "La fecha/hora ha sido modificada a: " << fechaHora;
        cin.get();
    }catch(invalid_argument& ia){
        cout << ia.what() <<"\n";
        cin.get();
    }
}

void menuConsultarReloj() {
    try{
        cout << "\n\nConsultar fecha del sistema\n\n";
        FechaHora reloj = iUsuarioController->consultarReloj();
        cout << "La fecha/hora es " << reloj;
        cin.get();
    }catch(invalid_argument& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void menuCargarDatosPrueba() {
    try{
        iUsuarioController->cargarDatosPrueba();
        cout << "\nDatos de prueba cargados con exito\n";
        cin.get();
    }catch(invalid_argument& ia){
        cout << ia.what() << "\n";
        cin.get();
    }
}

void listarContactos(){
    map<string,DtContacto> contactos = iUsuarioController->listarContactos();
    map<string,DtContacto>::iterator i;
    if(contactos.size() == 0){
        cout << "\nLa lista de contactos esta vacia.\n";
    }else{
        for(i = contactos.begin(); i != contactos.end(); ++i){
            cout << i->second << "\n";
        }
    }
}

void listarConversacionesActivas(){
    map<int,DtConversacion*> conversacionesActivas = iConversacionController->listarConversacionesActivas();
    map<int,DtConversacion*>::iterator i;
    if(conversacionesActivas.size() == 0){
        cout << "\nLa lista de conversaciones activas esta vacia.\n";
    }else{
        for(i = conversacionesActivas.begin(); i != conversacionesActivas.end(); ++i){
            DtConversacion* conversacion = i->second;
            cout << *conversacion;
        }
    }
}

void listarConversacionesArchivadas(){
    map<int,DtConversacion*> conversacionesArchivadas = iConversacionController->listarConversacionesArchivadas();
    map<int,DtConversacion*>::iterator i;
    if(conversacionesArchivadas.size() == 0){
        cout << "\nLa lista de conversaciones archivadas esta vacia.\n";
    }else{
        for(i = conversacionesArchivadas.begin(); i != conversacionesArchivadas.end(); ++i){
            DtConversacion* conversacion = i->second;
            cout << *conversacion;
        }
    }
}

int cantidadConversacionesArchivadas(){
    map<int,DtConversacion*> conversacionesArchivadas = iConversacionController->listarConversacionesArchivadas();
    return conversacionesArchivadas.size();
}

void listarMensajes(int idConversacion){
    map<int,DtMensaje*> mensajes = iMensajeController->listarMensajes(idConversacion);
    map<int,DtMensaje*>::iterator i;
    if(mensajes.size() == 0){
        cout << "\nLa conversacion esta vacia.\n";
    }else{
        for(i = mensajes.begin(); i != mensajes.end(); ++i){
            DtMensaje* mensaje = i->second;
            try{
                DtSimple* dtm = dynamic_cast<DtSimple*>(mensaje);
                if (dtm != NULL){
                cout << *dtm << "\n";
                }
            }catch(exception& e){
                cout << "Error en cast para Simple\n";
            }
            try{
                DtImagen* dtm = dynamic_cast<DtImagen*>(mensaje);
                if (dtm != NULL){
                cout << *dtm << "\n";
                }
            }catch(exception& e){
                cout << "Error en cast para Imagen\n";
            }
            try{
                DtVideo* dtm = dynamic_cast<DtVideo*>(mensaje);
                if (dtm != NULL){
                cout << *dtm << "\n";
                }
            }catch(exception& e){
                cout << "Error en cast para Video\n";
            }
            try{
                DtTarjetaContacto* dtm = dynamic_cast<DtTarjetaContacto*>(mensaje);
                if (dtm != NULL){
                cout << *dtm << "\n";
                }
            }catch(exception& e){
                cout << "Error en cast para TarjetaContacto\n";
            }
        }
    }
}

void listarReceptores(int codigoMensaje){
    map<string,DtReceptor> receptores = iMensajeController->verInfoMensajeEnviado(codigoMensaje);
    map<string,DtReceptor>::iterator i;
    if(receptores.size() == 0){
        cout << "\nEl mensaje no tiene receptores.\n";
    }else{
        for(i = receptores.begin(); i != receptores.end(); ++i){
            cout << i->second << "\n";
        }
    }
}

void listarContactosElegidos(){
    map<string,DtContacto> elegidos = iConversacionController->listarContactosElegidos();
    map<string,DtContacto>::iterator i;
    if(elegidos.size() == 0){
        cout << "\nNo se han elegido contactos por el momento.\n";
    }else{
        for(i = elegidos.begin(); i != elegidos.end(); ++i){
            cout << i->second << "\n";
        }
    }
}

void listarContactosRestantes(){
    map<string,DtContacto> restantes = iConversacionController->listarContactosRestantes();
    map<string,DtContacto>::iterator i;
    if(restantes.size() == 0){
        cout << "\nNo quedan mas contactos para elegir.\n";
    }else{
        for(i = restantes.begin(); i != restantes.end(); ++i){
            cout << i->second << "\n";
        }
    }
}
