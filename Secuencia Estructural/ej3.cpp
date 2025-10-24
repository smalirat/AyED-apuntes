//Ejercicio 3: Determinar la suma de las cifras de un número entero positivo de 4 cifras. Ejemplo: Dado 8125, la suma es 16.

#include <iostream>

using namespace std;

int main()
{
    int num,suma,d1,d2,d3,d4;
    
    cout<<"Ingrese un numero de 4 cifras"<<endl;
    cin>>num;
    d1 = num/1000;
    d2 = (num - (d1*1000))/100;
    d3 = (num - ((d1*1000) + (d2*100)))/10;
    d4 = (num - ((d1*1000) + (d2*100) + (d3*10)))/1;
    
    suma = d1+d2+d3+d4;
    cout<<"La suma es "<<suma;
    return 0;

}