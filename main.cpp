#include <stdio.h>
#include <iostream>
#include <fstream>

int main (){

  int opcion;
  char string nombre; //no se como declarar una cadena de caracter
  do{
    cout << "1. Escribir archivo" <<std::endl;
    cout << "2. Leer Archivo" <<std::endl;
    cout << "3. Crear Archivo Nuevo" <<std::endl;
    cout << "4. Borrar" <std::<endl;
    cout << "0. Salir del Programa..." <<std::endl;
    cin >> opcion;
    
        switch (opcion)
        {
        case 1:
            cout << "Ingrese nombre del archivo para escribir: " <<std::endl;
            cin>>nombre;
            std::fstream nombre;  
            nombre.open("nuevo.txt", std::fstream::out); //escribir en el archivo
            nombre << cin; //esto se supone que escribe, pero no sé si así ya funciona 
            nombre.close(); //cierra el archivo, pero no sé hasta qué punto se cierra. 
            break;
            
        case 2:
            cout << "Ingrese nombre del archivo para leer: " <<std::endl;
            cin>>nombre;
            string line; 
            std::fstream nombre;  
            nombre.open("nuevo.txt", std::fstream::in);
            if (nombre.is_open())
            {
              while (getline(nombre,line))
               {
                  cout << line << '\n';
               }
                nombre.close();
             }
             else cout << "No se pudo abrir el archivo"; 
           
            break;
        case 3:
            std::ofstream outfile ("nuevo.txt");
            outfile << "Archivo creado" << std::endl;
            cout << "Se ha creado el nuevo archivo." <<std::endl;
            break;
        case 4:
            cout << "Ingrese el nombre del archivo que desea borrar:" <<std::endl;
            cin>>nombre; //no se si se pueda hacer esto de que es el archivo que diga el usuario
            if(remove(nombre) != 0 )
            perror( "Error al borrar el archivo." );
           else
              puts( "El archivo se ha borrado" );
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta." << std::endl;
        }
    } while (opcion != 0);
    return 0;
}

