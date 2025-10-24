#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

// Declaración de funciones
void cargarVector(int v1[]);
int cargarZona(int v1[], int pos);
void repartidoresZona(int v1[]);

struct Repartidor
{
    int dni,zona;
    char vehiculo[36], nombre[36], apellido[36], patente[36];
};

int main()
{
    int vector_zonas[15];
    int zona_local;

    // Inicializar el arreglo de zonas con ceros
    cargarVector(vector_zonas);

    FILE *arch;
    char nomArchivo[21] = "Rep";

    for (int i = 0; i < 2; i++)
    {
        cout << "Vehículo para el archivo ";
        char vehiculo[100];
        cin >> vehiculo;
        char nombreTemporal[121]; // Cadena temporal para el nombre del archivo
        strcpy(nombreTemporal, nomArchivo);
        strcat(nombreTemporal, vehiculo);
        strcat(nombreTemporal, ".dat");
        arch = fopen(nombreTemporal, "wb");

        if (arch == NULL)
            cout << "Error de creación de archivo" << endl;
        else
        {
            Repartidor repartidor;
            cout << "DNI (número negativo para terminar): ";
            cin >> repartidor.dni;
            while (repartidor.dni > 0)
            {
                cin.ignore();

                cout << "Zona: ";
                cin >> repartidor.zona;
                zona_local=repartidor.zona;
                int validez=cargarZona(vector_zonas, zona_local);
                if(validez != -1){
                cout << "Nombre: ";
                cin >> repartidor.nombre;
                cout << "Apellido: ";
                cin >> repartidor.apellido;
                cout << "Patente: ";
                cin >> repartidor.patente;

                
                fwrite(&repartidor, sizeof(Repartidor), 1, arch);
                }

                cout << "DNI (número negativo para terminar): ";
                cin >> repartidor.dni;
                }
            }


            fclose(arch);
        }
    

    return 0;
}

void cargarVector(int v1[])
{
    for (int i = 0; i < 15; i++)
    {
        v1[i] = 0;
    }
}

int cargarZona(int v1[], int pos)
{
    if (v1[pos] < 2)
    {
        v1[pos] = v1[pos] + 1;
        return 1;
    }
    else
    {
        cout << "Esta Zona no permite más repartidores" << endl;
        return -1;
    }
    
}

void repartidoresZona(int v1[]){
    for (int i = 0; i < 15; i++){
        cout<<"La zona"<<i<<" tiene"<<v1[i]<<"repartidores"<<endl;
    }

}