#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Producto
{
    unsigned codigo;
    unsigned stock;
};

struct Pedido
{
    unsigned nroPed;
    unsigned nroCli;
    unsigned codProd;
    unsigned cant;
};

int main()
{
    FILE *arch,*arch2;
    char nomArch[21],nomArch2[21];
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
            
            fwrite(&prod,sizeof(Producto),1,arch);

            cout<<"Codigo (cero fin) ";
            cin>>prod.codigo;
        }
        fclose(arch);
    }

    cout<<"Nombre del segundo archivo ";
    cin>>nomArch2;
    strcat(nomArch2,".dat");
    arch2=fopen(nomArch2,"wb");
    if(arch2==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Pedido ped;
        cout<<"Nro pedido (cero fin) ";
        cin>>ped.nroPed;
        while(ped.nroPed!=0)
        {
            cout<<"Nro cliente: ";
            cin>>ped.nroCli;
            cout<<"Codigo del producto: ";
            cin>>ped.codProd;
            cout<<"Cantidad: ";
            cin>>ped.cant;
            
            fwrite(&ped,sizeof(Pedido),1,arch2);

            cout<<"Nro pedido (cero fin) ";
            cin>>ped.nroPed;
        }
        fclose(arch);
    }

    return 0;
}
