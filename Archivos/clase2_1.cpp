#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Producto
{
    int codigo,stock;
};

void mostrar(FILE*a);
int busquedaBinaria(FILE*a, int unCod, Producto &prod);
void esta(char nomA[],int unCod);
void sumarStock(char nomA[],int unCod, int cant);
int cantReg(FILE*arch);

int main()
{
    FILE *archivo;
    char nomArch[21];
    int busqueda;

    cout<<"Nombre del archivo ";
    cin>>nomArch;
    strcat(nomArch,".dat");
    archivo=fopen(nomArch,"rb");
    if(archivo==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        mostrar(archivo);
        fclose(archivo);
    }

    cout<<"Num de bsuqeuda: ";
    cin>>busqueda;

    sumarStock(nomArch,busqueda, 10);

    return 0;
}

void mostrar(FILE*a){
    Producto prod;
    fread(&prod,sizeof(Producto),1,a);
    while(!feof(a)){
        cout<<prod.codigo<<"   "<<prod.stock<<endl;
        fread(&prod,sizeof(Producto),1,a);
    }
}

int busquedaBinaria(FILE*a, int unCod, Producto &prod){
    int desde,hasta,medio,pos=-1;
    desde=0;
    hasta=cantReg(a)-1;
    while(pos==-1 && desde<=hasta){
        medio=(desde+hasta)/2;
        fseek(a,medio*sizeof(Producto),SEEK_SET);
        fread(&prod,sizeof(Producto),1,a);
        if(prod.codigo==unCod){
            pos=medio;
        }
        else{
            if(unCod<prod.codigo){
                hasta=medio-1;
            }
            else{
                desde=medio+1; 
            }
        }
    }
    return pos;
}

void esta(char nomA[],int unCod){
    Producto p;
    FILE *archivo=fopen(nomA,"rb");
    if(busquedaBinaria(archivo,unCod,p )!=-1)
        cout<<unCod<<" esta";
    else
        cout<<unCod<<" no esta";
}

void sumarStock(char nomA[],int unCod, int cantASumar){
    Producto p;
    FILE *archivo=fopen(nomA,"rb+");
    int pos=busquedaBinaria(archivo,unCod,p);
    if(pos!=-1){
        /*
        fseek(archivo,pos*sizeof(Producto),SEEK_SET);
        Producto p;
        fread(&p,sizeof(Producto),1,archivo);
        */
        p.stock+=cantASumar;
        fseek(archivo,pos*sizeof(Producto),SEEK_SET); 
        fwrite(&p, sizeof(Producto), 1, archivo);

    }       
    else
        cout<<unCod<<" no esta";
}

int cantReg(FILE*arch){
    fseek(arch,0,SEEK_END);
    return ftell(arch)/sizeof(Producto);
}
