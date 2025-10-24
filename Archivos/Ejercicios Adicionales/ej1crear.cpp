#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Producto
{
    int codigo,stock,precio;
    char nombre[20];
};

int main()
{
    FILE *arch;
    char nomArch[21];
    cout<<"Nombre del archivo ";
    cin>>nomArch;
    strcat(nomArch,".dat");
    arch=fopen(nomArch,"wb");
    if(arch==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Producto prod;
        cout<<"Codigo (cero fin) ";
        cin>>prod.codigo;
        while(prod.codigo!=0)
        {
            cout<<"Stock: ";
            cin>>prod.stock;
            cout<<"Precio: ";
            cin>>prod.precio;
            cout<<"Nombre de remedio: ";
            cin>>prod.nombre;

            fwrite(&prod,sizeof(Producto),1,arch);

            cout<<"Codigo (cero fin) ";
            cin>>prod.codigo;
        }
        fclose(arch);
    }

    return 0;
}
