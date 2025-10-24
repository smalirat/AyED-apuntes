#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Producto
{
    int codigo,stock,precio;
    char nombre[20];
};

int main(){
    FILE *arch;
    arch=fopen("Medicamentos.dat","rb");
    if(arch==NULL)
        cout<<"Error de archivo"<<endl;
    else
    {
        
        Producto p;
        fread(&p,sizeof(Producto),1,arch);
        while(!feof(arch))
        {
            if(p.stock<5){
                cout<<"Medicamento: "<<p.nombre<<endl;
                cout<<"Valor de stock: "<<p.stock*p.precio<<endl;
            }   
            fread(&p,sizeof(Producto),1,arch);
        }
        fclose(arch);
    }


    return 0;
}


