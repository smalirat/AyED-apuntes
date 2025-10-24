#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Infracciones
{
    int codigo,dia,mes;
    char patente[7];
    float importe;
};

struct Vehiculo
{
    int año;
    char patente[7], nombre[40];
};

int main()
{
    FILE *arch, *archivo;
    char nomArch[21];
    strcat(nomArch,".dat");
    archivo=fopen("Vehiculos.dat","rb");
    arch=fopen("Infracciones","wb");
    if(arch==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {   
        Vehiculo v[1000];
        Infracciones inf[10];
        fread(&v, sizeof(Vehiculo), 1, archivo);

        for(int i=0;i<2;i++){
        cout<<v[i].patente<<endl;
        cout<<"Patente infraccion: ";
        cin>>inf[i].patente;
        cout<<"codigo: ";
        cin>>inf[i].codigo;
        cout<<"Dia ";
        cin>>inf[i].dia; 
        cout<<"Mes ";
        cin>>inf[i].mes;
        cout<<"Importe ";
        cin>>inf[i].importe;  


        fwrite(&inf,sizeof(Infracciones),1,arch);
        fread(&v, sizeof(Vehiculo), 1, archivo);
        }
        
        fclose(archivo);
        fclose(arch);
    }

    return 0;
}
