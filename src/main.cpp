#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int opcion;
    char* nombre, entrada;
    string linea;
    fstream archivo;
    do {
        cout << "1. Escribir archivo" << endl;
        cout << "2. Leer Archivo" << endl;
        cout << "3. Crear Archivo Nuevo" << endl;
        cout << "4. Borrar" << endl;
        cout << "0. Salir del Programa..." << endl;
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese nombre del archivo para escribir: ";
            cin >> nombre;
            // Abrir el archivo en modo escritura, lectura y concatenar
            archivo.open(nombre, ios::out | ios::in | ios::app);
            if (archivo.is_open()) {
                while (getline(archivo, linea)) {
                    cout << linea << endl;
                }
                do {
                    cin >> entrada;
                    archivo << entrada << endl;
                } while (entrada != '\n');
            } else {
                cout << "No se pudo abrir el archivo" << endl;
            }
            archivo.close();
            break;

        case 2:
            cout << "Ingrese nombre del archivo para leer: ";
            cin >> nombre;
            archivo.open(nombre, ios::in);
            if (archivo.is_open()) {
                while (getline(archivo, linea)) {
                    cout << linea << endl;
                }
                archivo.close();
            } else
                cout << "No se pudo abrir el archivo";

            break;
        case 3:
            cout << "Ingrese nombre del archivo a crear: ";
            cin >> nombre;
            archivo.open(nombre, ios::in);
            if (archivo.is_open()) {
                do {
                    cin >> entrada;
                    archivo << entrada << endl;
                } while (entrada != '\n');
                archivo.close();
            } else {
                cout << "Error." << endl;
            }
            break;
        case 4:
            cout << "Ingrese la direccion del archivo que desea borrar:" << endl;
            cin >> entrada;
            if (remove(const entrada) != 0)
                cout << "Error al borrar el archivo." << endl;
            else
                cout << "Archivo eliminado correctamente." << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);
    return 0;
}
