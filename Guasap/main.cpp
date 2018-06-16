#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
//#include <typeinfo>
#include "UsuarioFactory.h"
#include "Sesion.h"

using namespace std;

//FUNCIONES AUXILIARES
void menuPrincipal();
void prueba();

int main() {
    int numOper = 0;
    string celularSistema, celularIngresado, nombre, urlImagen, descripcion = "";
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
                        Sesion* sesion = Sesion::getInstancia();
                        sesion->setSesion(celularIngresado);
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
                                UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                                IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
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
                                    Sesion* sesion = Sesion::getInstancia();
                                    sesion->setSesion(celularIngresado);
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
                        cout << "\nYa hay una sesion iniciada. Debe cerrar la sesion actual para inciar sesion con el celular: " + celularIngresado;
                        cout << "\n¿Cerrar sesion actual (s/n)?: ";
                        cin >> opcion;
                        if (opcion == 's' || opcion == 'S') {
                            cout << "\nCerrando sesion...\n";
                            Sesion* sesion = Sesion::getInstancia();
                            UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                            IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                            iUsuarioController->cerrarGuasap(sesion->getSesion());
                            cout << "\nSesion cerrada con exito.";
                            ingresarOtroNumero = false;
                        }
                        break;
                    }
                    }
            } while (ingresarOtroNumero);
            }
            break;
            case 2: {
                cout << "\n\tCerrar Guasap\n";
                Sesion* sesion = Sesion::getInstancia();
                if(sesion->getSesion() == "NULL"){
                    cout << "\nNo hay ninguna sesion activa.\n";
                    fflush(stdin);
                    cin.ignore();
                }else{
                    cout << "\n¿Cerrar sesion actual (s/n)?: ";
                    cin >> opcion;
                    if (opcion == 's' || opcion == 'S') {
                        cout << "\nCerrando sesion...\n";
                        UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
                        IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
                        iUsuarioController->cerrarGuasap(sesion->getSesion());
                        cout << "\nSesion cerrada con exito.";
                    }
                }
                break;
            }
            case 3:
                cout << "\n\tAgregar contactos\n\n";
                break;
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
            case 8:
                cout << "\n\tModificar usuario\n\n";
                break;
            case 9:
                cout << "\n\tEliminar mensajes\n\n";
                break;
            case 10:
                cout << "\n\tModificar fecha del sistema\n\n";
                break;
            case 11:
                cout << "\n\nConsultar fecha del sistema\n\n";
                break;
            case 12:
                cout << "\n\tInicializar/cargar un conjunto de datos de prueba\n\n";
                break;
            case 13:
              cout << "\n¿Esta seguro de que desea salir (s/n)?: ";
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

//void pruebaMatias(){
//    Usuario* a = new Usuario("123", "nomPrueba1", "a", "b");
//    Usuario* b = new Usuario("456", "nomPrueba2", "a", "b");
//    a->agregarContacto(b);
//    map<string,Usuario*>::iterator i = a->contactos.begin();
//    cout << "celular: " + i->first;
//}
