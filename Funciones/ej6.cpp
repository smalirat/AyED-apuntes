/*
Desarrollar la función porcentaje que dados los parámetros a y b devuelva el porcentaje que
representa a sobre b. 
*/

#include <iostream>

using namespace std;


float porcentaje(float a, float b);


float porciento,a,b;

int main()
{
   
   cout<<"Ingrese un numero: ";
   cin>>a;
   cout<<"Ingrese un numero: ";
   cin>>b;

   porciento = porcentaje(a, b);

   cout<<"a es un "<<porciento<<"% de b";

   return 0;


}


float porcentaje(float a, float b) {
    return a*100/b;
}