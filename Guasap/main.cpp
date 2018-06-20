#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "UsuarioFactory.h"
#include "FechaHora.h"
#include "Almacenamiento.h"

using namespace std;

//FUNCIONES AUXILIARES
void menuPrincipal();
void listarContactos();
bool existeSesion();
void mensajeSesion();

int main() {
    int numOper = 0;
    string celularIngresado, celularContacto, nombre, urlImagen, descripcion = "";
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
                        cout << "\n\nCerrar sesion actual (s/n)?: ";
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
                    cout << "\nCerrar sesion actual (s/n)?: ";
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
                    cout << "\nQuiere agregar un nuevo contacto (s/n)?: ";
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
            case 5:
                cout << "\n\tEnviar mensajes\n\n";
                break;
            case 6:
                cout << "\n\nVer mensajes\n\n";
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
                    iUsuarioController->modificarUsuario(nombre, urlImagen, descripcion);
                    cout << "\nLos datos se modificaron con exito.";
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
              cout << "\nEsta seguro de que desea salir (s/n)?: ";
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

void listarContactos(){
    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
    map<string,DtContacto> contactos = iUsuarioController->listarContactos();
    map<string,DtContacto>::iterator i;
    if(contactos.begin() == contactos.end()){
        cout << "\nLa lista de contactos esta vacia.\n";
    }else{
        for(i = contactos.begin(); i != contactos.end(); ++i){
            cout << i->second;
        }
    }
}
