#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <typeinfo>
#include "UsuarioFactory.h"

using namespace std;

//FUNCIONES AUXILIARES
void menuPrincipal();

int main()
{
    int numOper = 0;
    string celularSistema= "";
    string celularIngresado = "";
    bool salir = false;
    bool existeUsuario = true;
    bool ingresarOtroNumero = true;
    char opcion = 'n';
    do {
    menuPrincipal();
    cin >> numOper;
    switch (numOper) {
    case 1: {
        cout << "\n\nAbrir Guasap\n\n";
        cout << "\nIngrese el numero de celular: ";
        cin >> celularIngresado;
        UsuarioFactory* usuarioFactory = UsuarioFactory::getInstancia();
        IUsuarioController* iUsuarioController = usuarioFactory->getIUsuarioController();
        do{
        EstadoIngreso estadoIngreso = iUsuarioController->ingresar(celularIngresado);
        switch(estadoIngreso){
        case 1: {
            cout << "\nIngreso valido -  FALTA IMPLEMENTAR\n";
            break;
        }
        case 2:
            celularSistema = celularIngresado;
            do {
                cout << "\nNo existe un usuario con ese numero de celular.\n";
                cout << "\nLista de operaciones disponibles:\n\n";
                cout << "1)  Ingresar otro numero\n";
                cout << "2)  Darse de alta con el numero " + celularIngresado + " \n";
                cout << "3)  Cancelar (volver al menu principal)\n";
                cout << "\nIngrese el numero de la operacion a realizar: ";
                cin >> numOper;
                switch (numOper) {
                case 1: {
                    cout << "\nIngrese el numero de celular: ";
                    cin >> celularIngresado;
                    ingresarOtroNumero = false;
                    break;
                }
                case 2: {
                    cout << "\nDar de alta un usuario -  FALTA IMPLEMENTAR\n";
                    ingresarOtroNumero = false;
                    existeUsuario = false;
                    break;
                }
                case 3: {
                    ingresarOtroNumero = false;
                    existeUsuario = false;
                    break;
                }
                }
            } while (existeUsuario);
//            iUsuarioController->crearUsuario();
            break;
//            } while (!ingresarOtroNumero);
            break;
        case 3:
            cout << "\nMismo numero que el usuario logueado -  NO HACE NADA\n";
            break;
        case 4: {
            cout << "\nYa hay una sesion iniciada -  FALTA IMPLEMENTAR\n";
//            iUsuarioController->cerrarGuasap();
//            EstadoIngreso estadoIngreso = iUsuarioController->ingresar(celular);
            break;
        }
        }
        break;
    } while (!ingresarOtroNumero);
    }
    break;
    case 2:
        cout << "\n\Cerrar Guasap\n";
        break;
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
        cout << "\n\Ver mensajes\n\n";
        break;
    case 7:
        cout << "\n\Archivar conversaciones\n\n";
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
        cout << "\n\Consultar fecha del sistema\n\n";
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
