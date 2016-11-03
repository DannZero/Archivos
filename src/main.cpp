#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int opcion;
    string nombre;
    string linea, entrada;
    fstream archivo;
    do {
        cout << "1. Escribir archivo" << endl;
        cout << "2. Leer Archivo" << endl;
        cout << "3. Crear Archivo Nuevo" << endl;
        cout << "4. Borrar" << endl;
        cout << "0. Salir del Programa..." << endl;
        cin >> opcion;

        switch (opcion) {
        // Escribir
        case 1:
            cout << "Ingrese nombre del archivo para escribir (\"-q\" para salir): ";
            cin >> nombre;
            archivo.open(nombre, ios::in);
            if (archivo.is_open()) {
                while (getline(archivo, linea)) {
                    cout << linea << endl;
                }
				archivo.close();
            } else {
                cout << "No se pudo abrir el archivo" << endl;
            }
            archivo.open(nombre, ios::out | ios::app);
            if (archivo.is_open()) {
                do {
                    cin >> entrada;
                    if (entrada == "-q")
                        break;
                    archivo << entrada << endl;
                } while (true);
                archivo.close();
            } else {
                cout << "No se pudo abrir el archivo" << endl;
            }
            break;
        // Leer
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
                cout << "No se pudo abrir el archivo" << endl;

            break;
        // Crear
        case 3:
            cout << "Ingrese nombre del archivo a crear: ";
            cin >> nombre;
            archivo.open(nombre, ios::out | ios::trunc);
            if (archivo.is_open()) {
                cout << "Escribe en el nuevo archivo \"" << nombre << "\" (\"-q\" para salir):" << endl;
                do {
                    cin >> entrada;
                    if (entrada == "-q")
                        break;
                    archivo << entrada << endl;
                } while (true);
                archivo.close();
            } else {
                cout << "Error al crear archivo" << endl;
            }
            break;
        // Borrar
        case 4:
            cout << "Ingrese el nombre del archivo que desea borrar: ";
            cin >> nombre;
            if (remove(nombre.c_str()) == -1)
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
