#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Alumno
{
    int legajo,codigo,dia,mes,año;
    char nombre[36], apellido[36];
};

int main()
{
    FILE *archivo;
    char nomArchivo[20];
    strcpy(nomArchivo, "DIAFINALES");
    strcat(nomArchivo,".dat");
    archivo=fopen(nomArchivo,"ab");

   
    if(archivo==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Alumno finales;
        cout<<"Legajo (cero fin) ";
        cin>>finales.legajo;
        while(finales.legajo!=0)
        {
            cout << "Nombre: ";
            cin >> finales.nombre;
            cout << "Apellido: ";
            cin >> finales.apellido;
            cout << "Codigo: ";
            cin >> finales.codigo;
            cout << "Dia: ";
            cin >> finales.dia;
            cout << "Mes: ";
            cin >> finales.mes;
            cout << "Año: ";
            cin >> finales.año;

            //guardo en archivo
            fwrite(&finales,sizeof(Alumno),1,archivo);

            cout<<"Legajo (cero fin) ";
            cin>>finales.legajo;
        }
        fclose(archivo);
    }

    return 0;
}