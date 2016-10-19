int main (){

  int opcion;
  char string nombre; //no se como declarar una cadena de caracter
  do{
    cout << "1. Escribir archivo" <<endl;
    cout << "2. Leer Archivo" <<endl;
    cout << "3. Crear Archivo Nuevo" <<endl;
    cout << "4. Borrar" <<endl;
    cout << "0. Salir del Programa..." <<endl;
    cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ingrese nombre del archivo para escribir: " <<endl;
            cin>>nombre;
            //abrir archivo con el nombre
            //escribir en el archivo
            break;
        case 2:
            cout << "Ingrese nombre del archivo para leer: " <<endl;
            //abrir archivo con el nombre
            //leer archivo con el nombre
            break;
        case 3:
            cout << "Ingrese el nombre del nuevo archivo: " <<endl;
            //crear nuevo archivo
            break;
        case 4:
            cout << "Ingrese el nombre del archivo que desea borrar:" <<endl;
            //abrir archivo con el nombre
            //borrar contenido del archivo
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);
    return 0;
}

