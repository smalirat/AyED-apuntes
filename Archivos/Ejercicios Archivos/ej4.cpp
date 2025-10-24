#include <iostream>
#include <stdio.h>


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

void procesarPedidos(FILE*aProd,FILE*aPedidos,FILE*aPedNoS);
void mostrar(Pedido p);
void mostrarStock(Producto pr);
void mostrarNos (Pedido p);
int main()
{
    Producto produc;
    FILE *aProd,*aPedidos,*aPedNoS;
    aProd=fopen("Productos.dat","rb+");
    if(aProd!=NULL)
    {
        aPedidos=fopen("Pedidos.dat","rb");
        if(aPedidos!=NULL)
        {
            aPedNoS=fopen("PedNoS.dat","wb");
            if(aPedNoS!=NULL)
            {
                procesarPedidos(aProd,aPedidos,aPedNoS);
                fclose(aPedNoS);
            }
           fclose(aPedidos);
        }
        fclose(aProd);
    }

    mostrarStock(produc);

    return 0;
}

void procesarPedidos(FILE*aProd,FILE*aPedidos,FILE*aPedNoS)
{
    Pedido pedido;
    Producto prod;
    mostrarStock(prod);

    fread(&pedido,sizeof(Pedido),1,aPedidos);
    while(!feof(aPedidos))
    {
        fseek(aProd,(pedido.codProd-1)*sizeof(Producto),SEEK_SET);
        fread(&prod,sizeof(Producto),1,aProd);
        if(prod.stock>=pedido.cant)
        {
            
            prod.stock-=pedido.cant;
            fseek(aProd,-sizeof(Producto),SEEK_CUR);
            fwrite(&prod,sizeof(Producto),1,aProd);
        }
        else
            fwrite(&pedido,sizeof(Pedido),1,aPedNoS);


        fread(&pedido,sizeof(Pedido),1,aPedidos);
    }
    mostrar(pedido);
    mostrarStock(prod);
    mostrarNos(pedido);

}

void mostrar(Pedido p){
    cout<<p.nroPed<<"--"<<p.nroCli<<"--"<<p.codProd<<"--"<<p.cant;
} 

void mostrarStock(Producto pr) {
    FILE *arch = fopen("Productos.dat", "rb");
    if (arch != NULL) {
        Producto pr;
        fread(&pr, sizeof(Producto), 1, arch);
        while (!feof(arch)) {
                cout << pr.codigo << "  " << pr.stock << endl;
                fread(&pr, sizeof(Producto), 1, arch);
            }
            fclose(arch);
        }
     else {
        cout << "No se pudo abrir el archivo de productos." << endl;
     }
}

void mostrarNos (Pedido p){
    FILE *arch = fopen("PedNos.dat", "rb");
    if (arch != NULL) {
        Producto p;
        fread(&p, sizeof(Pedido), 1, arch);
        while (!feof(arch)) {
                cout<<p.nroPed<<"--"<<p.nroCli<<"--"<<p.codProd<<"--"<<p.cant;
                fread(&p, sizeof(Pedido), 1, arch);
            }
            fclose(arch);
        }
     else {
        cout << "No se pudo abrir el archivo de productos." << endl;
     }
}


