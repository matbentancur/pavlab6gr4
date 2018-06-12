#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <typeinfo>

using namespace std;

//FUNCIONES AUXILIARES
void menu();

int main()
{
    int numOper = 0;
    bool salir = false;
    char opcion = 'n';
    do {
    menu();
    cin >> numOper;
    switch (numOper) {
    case 1:
        cout << "\n\Abrir Guasap\n\n";
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

void menu() {
  cout << "\nProgramacion Avanzada - Laboratorio 6\n\n";
  cout << "\t\tGUASAP\n\n";
  cout << "Lista de operaciones disponibles:\n";
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
