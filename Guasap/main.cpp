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
#include "FechaHora.h"
#include "Almacenamiento.h"
#include "DtConversacion.h"
#include "DtGrupo.h"
#include "DtPrivada.h"

using namespace std;

//FUNCIONES AUXILIARES
void menuPrincipal();
void menuEnviarMensaje();
void listarContactos();
void listarConversacionesActivas();
void listarConversacionesArchivadas();
bool existeSesion();
void mensajeSesion();

int main() {
    int numOper, idConversacion = 0;
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
                    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                    EstadoIngreso estadoIngreso = iUsuarioController->ingresar(celularIngresado);
                    switch(estadoIngreso){
                    case userOK: {
                        cout << "\nIniciando sesion...\n";
                        cout << "\nSesion iniciada con exito - Celular: " + celularIngresado + "\n";
                        ingresarOtroNumero = false;
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
                        break;
                    }
                    }
            } while (ingresarOtroNumero);
            }
            break;
            case 2: {
                try{
                    cout << "\n\tCerrar Guasap\n";
                    cout << "\nCerrar sesion actual? (s/n): ";
                    cin >> opcion;
                    if (opcion == 's' || opcion == 'S') {
                        UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                        IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                        iUsuarioController->cerrarGuasap();
                        cout << "\n\nCerrando sesion...\n";
                        cout << "\nSesion cerrada con exito.";
                    }
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            }
            case 3: {
                try {
                    cout << "\n\nLista de contactos\n\n";
                    listarContactos();
                    cout << "\nQuiere agregar un nuevo contacto? (s/n): ";
                    cin >> opcion;
                    if (opcion == 's' || opcion == 'S') {
                        cout << "\nIngrese el celular que desea agregar: ";
                        cin >> celularContacto;
                        UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                        IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                        DtContacto dtContacto = iUsuarioController->agregarContacto(celularContacto);
                        cout << "\n";
                        cout << dtContacto;
                        cout << "\nPresione \"s\" para confirmar la accion: ";
                        cin >> opcion;
                        if (opcion == 's' || opcion == 'S') {
                            if(iUsuarioController->confirmarContacto()){
                                cout << "\nSe agrego con exito al usuario.";
                            }else{
                                cout << "\nYa es contacto del usuario con celular: " + celularContacto + "\n";
                            }
                        }
                    }
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            }
            case 4:
                cout << "\n\tAlta grupo\n\n";
                break;
            case 5: {
                try {
                cout << "\n\nLista de conversaciones\n\n";
                cout << "\nActivas:\n\n";
                listarConversacionesActivas();
                ConversacionFactory* conversacionFactory = ConversacionFactory::getInstancia();
                IConversacionController* iConversacionController = conversacionFactory->getIConversacionController();
                int cantConvArchivadas = iConversacionController->cantConversacionesArchivadas();
                cout << "\nArchivadas: ";
                cout << cantConvArchivadas;
                menuEnviarMensaje();
                cin >> numOper;
                switch (numOper) {
                case 1:
                    cout << "\nIngrese el identificador de la conversacion: ";
                    cin >> idConversacion;
                    break;
                case 2:
                    listarConversacionesArchivadas();
                    if(cantConvArchivadas > 0){
                        cout << "\nIngrese el identificador de la conversacion: ";
                        cin >> idConversacion;
                    }
                    break;
                case 3:
                    cout << "\n\nLista de contactos\n\n";
                    listarContactos();
                    cout << "\nIngrese el numero de celular con el que desea iniciar una nueva conversacion: ";
                    cin >> celularContacto;
                    cout << "\n\tTipo de mensaje a enviar";
                    cout << "1)  Simple\n";
                    cout << "2)  Imagen\n";
                    cout << "3)  Video\n";
                    cout << "4)  Contacto\n";
                    cout << "\nIngrese una opcion: ";
                    cin >> numOper;
                    switch(numOper){
                    case 1:
                        cout << "\n\tMensaje Simple\n";
                        cout << "\nIngrese el texto del mensaje: ";
                        cin >> textoMensaje;
                    case 2:
                        cout << "\n\tMensaje de Imagen\n";
                        cout << "\nIngrese la URL de la imagen: ";
                        cin >> urlImagen;
                        cout << "\nIngrese el formato de la imagen: ";
                        cin >> formatoMensaje;
                        cout << "\n\nQuiere ingresar un texto descriptivo? (s/n): ";
                        cin >> opcion;
                        if (opcion == 's' || opcion == 'S') {
                            cout << "\nIngrese una descripcion: ";
                            cin >> urlImagen;
                        }
                    case 3:
                        cout << "\n\tMensaje de Video\n";
                        cout << "\nIngrese la URL del video: ";
                        cin >> urlVideo;
                        cout << "\nIngrese la duracion del video: ";
                        cin >> duracionMensaje;
                    case 4:
                        cout << "\n\tMensaje de Contacto\n";
                        listarContactos();
                        cout << "\nIngrese el numero de celular del contacto que desea compartir: ";
                        cin >> celularContacto;
                    }
                    break;
                }
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            }
            case 6:
                cout << "\n\nVer mensajes\n\n";
                try {
                cout << "\n\nLista de conversaciones\n\n";
                cout << "\nActivas:\n\n";
                listarConversacionesActivas();
                ConversacionFactory* conversacionFactory = ConversacionFactory::getInstancia();
                IConversacionController* iConversacionController = conversacionFactory->getIConversacionController();
                int cantConvArchivadas = iConversacionController->cantConversacionesArchivadas();
                cout << "\nArchivadas: ";
                cout << cantConvArchivadas;
                menuEnviarMensaje();
                cin >> numOper;
                switch (numOper) {
                case 1:
                    cout << "\nIngrese el identificador de la conversacion: ";
                    cin >> idConversacion;
                    break;
                case 2:
                    listarConversacionesArchivadas();
                    if(cantConvArchivadas > 0){
                        cout << "\nIngrese el identificador de la conversacion: ";
                        cin >> idConversacion;
                    }
                    break;
                case 3:
                    cout << "\n\nListar Mensajes\n\n";
                    listarContactos();
                    break;
                }
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
                break;
            case 7:
                cout << "\n\nArchivar conversaciones\n\n";
                break;
            case 8: {
                try{
                    cout << "\n\tModificar usuario\n\n";
                    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                    cout << "\nIngrese el nuevo nombre: ";
                    cin >> nombre;
                    cout << "\nIngrese la nueva URL de la imagen: ";
                    cin >> urlImagen;
                    cout << "\nIngrese una nueva descripcion: ";
                    cin >> descripcion;
                    cout << "\nLos datos se modificaron con exito.\n\n";
                    DtContacto dtContacto = iUsuarioController->modificarUsuario(nombre, urlImagen, descripcion);
                    cout << dtContacto;
                    cin.get();
                }catch(logic_error& ia){
                    cout << ia.what() << "\n";
                    cin.get();
                }
            }
                break;
            case 9:
                cout << "\n\tEliminar mensajes\n\n";
                break;
            case 10:
                int dia;
                int mes;
                int anio;
                int hora;
                int minuto;
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
                    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                    iUsuarioController->modificarReloj(fechaHora);
                    cout<< "La fecha/hora ha sido modificada a: "<< fechaHora;
                    cin.get();
                }catch(invalid_argument& ia){
                    cout<< ia.what()<<"\n";
                    cin.get();
                }
                break;
            case 11:
                try{
                    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                    cout << "\n\nConsultar fecha del sistema\n\n";
                    FechaHora reloj = iUsuarioController->consultarReloj();
                    cout<< "La fecha/hora es "<< reloj;
                    cin.get();
                }catch(invalid_argument& ia){
                    cout<< ia.what()<<"\n";
                    cin.get();
                }
                break;
            case 12:
                try{
                    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                    iUsuarioController->cargarDatosPrueba();
                    cout << "\nDatos de prueba cargados con exito\n\n";
                    cin.get();
                }catch(invalid_argument& ia){
                    cout<< ia.what()<<"\n";
                    cin.get();
                }

                break;
            case 13:
              cout << "\nEsta seguro de que desea salir? (s/n): ";
              cin >> opcion;
              if (opcion == 's' || opcion == 'S') {
                cout << "Saliendo...\n";
                salir = true;
              }
              break;
            default:
                cout << "\nNo ingreso una opcion valida, vuelva a intentarlo...\n";
        }
        cout << "\nPresione Enter Para continuar";
        fflush(stdin);
        cin.ignore();
    } while (!salir);

    return 0;
}

void menuPrincipal() {
  cout << "\nProgramacion Avanzada - Laboratorio 6\n\n";
  cout << "\t\tGUASAP\n\n";
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

void menuEnviarMensaje() {
    cout << "\n\nLista de operaciones disponibles:\n\n";
    cout << "1)  Seleccionar una conversacion activa\n";
    cout << "2)  Ver las conversaciones archivadas\n";
    cout << "3)  Enviar un mensaje nuevo\n";
    cout << "Ingrese una opcion: ";
}

void listarContactos(){
    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
    map<string,DtContacto> contactos = iUsuarioController->listarContactos();
    map<string,DtContacto>::iterator i;
    if(contactos.begin() == contactos.end()){
        cout << "\nLa lista de contactos esta vacia.\n";
    }else{
        for(i = contactos.begin(); i != contactos.end(); ++i){
            cout << i->second << "\n";
        }
    }
}

void listarConversacionesActivas(){
    ConversacionFactory* conversacionFactory = ConversacionFactory::getInstancia();
    IConversacionController* iConversacionController = conversacionFactory->getIConversacionController();
    map<int,DtConversacion> conversacionesActivas = iConversacionController->listarConversacionesActivas();
    map<int,DtConversacion>::iterator i;
    if(i == conversacionesActivas.end()){
        cout << "\nLa lista de conversaciones activas esta vacia.\n";
    }else{
        for(i = conversacionesActivas.begin(); i != conversacionesActivas.end(); ++i){
            DtConversacion conversacion = i->second;
            cout << conversacion.getIdConversacion() << " - " << conversacion.getNombre() << "\n";
//            try{
//                DtPrivada dtcp = dynamic_cast<DtPrivada&>(conversacion);
//                cout << dtcp << "\n";
//            }catch(exception& e){
//                cout << "Error en cast para Privada\n";
//            }
//            try{
//                DtGrupo dtcg = dynamic_cast<DtGrupo&>(conversacion);
//                cout << dtcg << "\n";
//            }catch(exception& e){
//                cout << "Error en cast para Grupo\n";
//            }
        }
    }
}

void listarConversacionesArchivadas(){
    ConversacionFactory* conversacionFactory = ConversacionFactory::getInstancia();
    IConversacionController* iConversacionController = conversacionFactory->getIConversacionController();
    map<int,DtConversacion> conversacionesArchivadas= iConversacionController->listarConversacionesArchivadas();
    map<int,DtConversacion>::iterator i;
    if(conversacionesArchivadas.begin() == conversacionesArchivadas.end()){
        cout << "\nLa lista de conversaciones archivadas esta vacia.\n";
    }else{
        for(i = conversacionesArchivadas.begin(); i != conversacionesArchivadas.end(); ++i){
            DtConversacion conversacion = i->second;
            cout << conversacion.getIdConversacion() << " - " << conversacion.getNombre() << "\n";
        }
    }
}
