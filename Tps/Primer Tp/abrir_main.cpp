#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Repartidor
{
    int dni, zona;
    char vehiculo[36], nombre[36], apellido[36], patente[36];
};


int main()
{
    FILE *arch;
    char nomArchivo[20] = "RepMoto.dat";

    arch = fopen(nomArchivo, "rb");
    if (arch == NULL)
    {
        cout << "Error de archivo" << endl;
    }
    else
    {
        Repartidor repartidor;
        fread(&repartidor,sizeof(Repartidor),1,arch);
        while (!feof(arch))
        {
            cout << "Nombre: " << repartidor.nombre << endl;
            cout << "Apellido: " << repartidor.apellido << endl;
            cout << "DNI: " << repartidor.dni << endl;
            cout << "Patente: " << repartidor.patente << endl;
            cout << "Zona: " << repartidor.zona << endl;
            cout << endl;
            fread(&repartidor,sizeof(Repartidor),1,arch);
        }
        fclose(arch);
    }

    return 0;
}