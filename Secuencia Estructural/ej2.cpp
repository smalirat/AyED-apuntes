/*Leer dos números y encontrar:
a. La suma del doble del primero mas el cuadrado del segundo.
b. El promedio de sus cubos. */

#include <iostream>

using namespace std;

int main()
{
    float n1,n2,suma,promedio,doble,cuadrado,cub1,cub2;
    cout<<"Ingrese 2 numeros"<<endl;
    cin>> n1;
    cin>> n2;
    doble = n1*2;
    cuadrado = n2*n2;
    suma = doble + cuadrado;
    cub1 = n1*n1*n1;
    cub2 = n2*n2*n2;
    promedio = (cub1 + cub2)/2;

    cout<<"La suma del doble del primero mas el cuadrado del segundo es "<<suma<<endl;
    cout<<"El promedio de sus cubos es "<<promedio;


    return 0;

}