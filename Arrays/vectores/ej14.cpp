#include <iostream>

using namespace std;

struct Producto {
    int codigo[3],stock[3];
    
};

struct Proveedor{
    int codigo[3],cantidad[3];
};

void apareo(int v1[],int v2[],int tam1, int tam2,int v1cant[], int v2cant[]){
    int i=0,j=0;
    while(i<tam1 && j<tam2)
     {
         if(v1[i]<v2[j])
         {
             cout<<v1[i]<<"-"<<v1cant[i]<<endl;
             i++;
         }
         else
         {
             if(v1[i]==v2[j])
             {
                cout<<v1[i]<<"-"<<v1cant[i]<<endl;
                i++;
                j++;
             }
             else
             {
                cout<<v2[j]<<"-"<<v2cant[j]<<endl;
                j++;
             }
         }
     }

     for(int k=i;k<tam1;k++)
        cout<<v1[k]<<"-"<<v1cant[k]<<endl;
     for(int k=j;k<tam2;k++)
        cout<<v2[k]<<"-"<<v2cant[k]<<endl;


}


int main(){
    Producto produc;
    Proveedor prov;
    int tam,i,j;

    for(i=0;i<3;i++){
        produc.codigo[i]=(i+1)*2;
        produc.stock[i]=i*3;
    }

    for(j=0;j<3;j++){
        prov.codigo[j]=(j+1)*2-1;
        prov.cantidad[j]=3*j;
        
    }

    apareo(produc.codigo,prov.codigo,3,3,produc.stock,prov.cantidad);






    


}