#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Vehiculo
{
    int año;
    char patente[7], nombre[40];
};

int main()
{
    FILE *arch;
    char nomArch[21];
    arch=fopen("Vehiculos.dat","wb");
    if(arch==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Vehiculo v[1000];
        
        for (int i=0; i<1;i++){
        cout<<"Patente (cero fin) ";
        cin>>v[i].patente;
        cout<<"Nombre: ";
        cin>>v[i].nombre;
        cout<<"Año ";
        cin>>v[i].año; 
        
        fwrite(&v,sizeof(Vehiculo),1,arch);
        }

        fclose(arch);
    }
    

    return 0;
}
