#include <iostream>

using namespace std;


void ingresoDatos(int[]);
int calculoPromedio(int[]);
int cantidadMayores(int[]);



int main()
{
    int nro, suma=0,prom,cont=0;
    int nros[5];

    for(int i=1;1<=5,i++;){
        cout<<"ingrese un numero: ";
        cin>>nros[1];
       
    }

    for(int j=0;j<5,j++;){
        suma+=nros[j];
        prom=suma/5;
       
    }

    for(int i=1;1<=5,i++;){
        if(nros[i]>prom)
            cont++;
       
    }



    prom=suma/5;
    cout<<"Hay "<<cont<<"Numeros mayores ";

}

void ingresoDatos(int v[], int tam){
    for(int i=0;i<tam,i++;){
        cout<<"ingrese un numero: ";
        cin>>v[1];
    }






}