#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include "UsuarioFactory.h"
#include "FechaHora.h"

using namespace std;

//FUNCIONES AUXILIARES
void menuPrincipal();
void listarContactos();
bool existeSesion();
void mensajeSesion();
FechaHora consultarReloj();
void modificarReloj(FechaHora&);

int main() {
    int numOper = 0;
    string celularSistema, celularIngresado, celularContacto, nombre, urlImagen, descripcion = "";
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
                        iUsuarioController->crearSesion(celularIngresado);
                        celularSistema = celularIngresado;
                        cout << "\nSesion iniciada con exito - Celular: " + celularIngresado + "\n";
                        break;
                    }
                    case userInexistente:
                        celularSistema = celularIngresado;
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
                                    iUsuarioController->crearSesion(celularIngresado);
                                    celularSistema = celularIngresado;
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
                            cout << "\nCerrando sesion...\n";
                            iUsuarioController->cerrarGuasap();
                            cout << "\nSesion cerrada con exito.";
                            cout << "\nIniciando sesion...\n";
                            iUsuarioController->crearSesion(celularIngresado);
                            celularSistema = celularIngresado;
                            cout << "\nSesion iniciada con exito - Celular: " + celularIngresado + "\n";
                            ingresarOtroNumero = false;
                        }
                        break;
                    }
                    }
            } while (ingresarOtroNumero);
            }
            break;
            case 2: {
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\tCerrar Guasap\n";
                    cout << "\nCerrar sesion actual (s/n)?: ";
                    cin >> opcion;
                    if (opcion == 's' || opcion == 'S') {
                        cout << "\nCerrando sesion...\n";
                        UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                        IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                        iUsuarioController->cerrarGuasap();
                        cout << "\nSesion cerrada con exito.";
                    }
                }
                break;
            }
            case 3: {
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\nLista de contactos\n\n";
                    listarContactos();
                    cout << "\nQuiere agregar un nuevo contacto (s/n)?: ";
                    cin >> opcion;
                    if (opcion == 's' || opcion == 'S') {
                        cout << "\nIngrese el celular que desea agregar: ";
                        cin >> celularContacto;
                        UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                        IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                        if(iUsuarioController->existeUsuario(celularContacto) == false){
                            cout << "\nNo existe un usuario con ese numero.\n";
                        }else{
                            if(iUsuarioController->yaEsContacto(celularContacto) == true){
                                cout << "\nYa es contacto del usuario con celular: " + celularContacto + "\n";
                            }else{
                                DtContacto dtContacto = iUsuarioController->agregarContacto(celularContacto);
                                cout << "\n";
                                cout << dtContacto;
                                cout << "\nPresione \"s\" para confirmar la accion: ";
                                cin >> opcion;
                                if (opcion == 's' || opcion == 'S') {
                                    if(iUsuarioController->confirmarContacto()){
                                        cout << "\nSe agrego con exito al usuario.";
                                    }else{
                                        cout << "\nNo se pudo agregar al usuario.";
                                    }
                                }
                            }
                        }
                    }
                }
                break;
            }
            case 4:
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\tAlta grupo\n\n";
                }
                break;
            case 5:
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\tEnviar mensajes\n\n";
                }
                break;
            case 6:
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\nVer mensajes\n\n";
                }
                break;
            case 7:
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\nArchivar conversaciones\n\n";
                }
                break;
            case 8:
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\tModificar usuario\n\n";
                }
                break;
            case 9:
                if(existeSesion() == false){
                    mensajeSesion();
                }else{
                    cout << "\n\tEliminar mensajes\n\n";
                }
                break;
            case 10:
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
                    modificarReloj(fechaHora);
                }catch(invalid_argument& ia){
                    cout<< ia.what()<<"\n";
                    cin.get();
                }
                break;
            case 11:
                cout << "\n\nConsultar fecha del sistema\n\n";
                datosReloj = consultarReloj();
                cout<< "La fecha/hora es "<< datosReloj;
                break;
            case 12:
                cout << "\n\tInicializar/cargar un conjunto de datos de prueba\n\n";
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
  cout << "10)  Modificar fecha del sistema\n";
  cout << "11)  Consultar fecha del sistema\n";
  cout << "12)  Inicializar/cargar un conjunto de datos de prueba\n";
  cout << "13)  Salir\n\n";
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

bool existeSesion(){
    UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
    IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
    return iUsuarioController->existeSesion();
}

void mensajeSesion(){
    cout << "\nNo hay ninguna sesion activa, primero debe iniciar sesion.\n";
}

void modificarReloj(FechaHora& fechaHora){
    FechaHora* nuevaFechaHora = new FechaHora(fechaHora);
    cout<< "Fecha actualizada\n";
}

FechaHora consultarReloj(){
    FechaHora dReloj = FechaHora();
    return dReloj;
}
