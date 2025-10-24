#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Alumno
{
    int legajo, codigo, dia, mes, año;
    char nombre[36], apellido[36];
};

int main()
{
    Alumno finales;
    FILE *archivo, *archivo2;
    int materia;
    char probando[20] = "DIAFINALES.dat";

    char nomArchivo[24]; 
    cin >> nomArchivo;
    strcat(nomArchivo, "FINALES.dat");  

    cout << "Código de Materia: ";
    cin >> materia;

    archivo = fopen(probando, "rb");
    if (archivo == NULL)
    {
        cout << "Error de archivo" << endl;
        return 1; // Agregar una salida del programa en caso de error
    }
    else
    {
        archivo2 = fopen(nomArchivo, "wb"); // Usar "wb" para escritura binaria
        if (archivo2 == NULL)
        {
            cout << "Error al crear archivo MATFINALES" << endl;
            fclose(archivo); // Cerrar el archivo abierto anteriormente
            return 1; // Agregar una salida del programa en caso de error
        }

        fread(&finales, sizeof(Alumno), 1, archivo);
        while (!feof(archivo))
        {
            if (finales.codigo == materia)
            {
                fwrite(&finales, sizeof(Alumno), 1, archivo2);
            }
            fread(&finales, sizeof(Alumno), 1, archivo); // Leer el siguiente registro
        }

        fclose(archivo);
        fclose(archivo2);

        return 0; 
    }
}
