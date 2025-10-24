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
    FILE *archivo;
    char nomArchivo[20] = "ANALISISFINALES.dat"; //esto lo cambio para ir probando

    archivo = fopen(nomArchivo, "rb");
    if (archivo == NULL)
    {
        cout << "Error de archivo" << endl;
    }
    else
    {
        Alumno finales;
        fread(&finales,sizeof(Alumno),1,archivo);
        while (!feof(archivo))
        {
            cout << "Legajo: " << finales.legajo << endl;
            cout << "Nombre: " << finales.nombre << endl;
            cout << "Apellido: " << finales.apellido << endl;
            cout << "Codigo: " << finales.codigo << endl;
            cout << "Dia: " << finales.dia << endl;
            cout << "Mes: " << finales.mes << endl;
            cout << "Año: " << finales.año << endl;
            cout << endl;
            fread(&finales,sizeof(Alumno),1,archivo);
        }
        fclose(archivo);
    }

    return 0;
}