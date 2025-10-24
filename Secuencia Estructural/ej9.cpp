//Ejercicio 9: Se ingresa un número de tres cifras. Descomponerlo en unidades, decenas y centenas.

#include <iostream>

using namespace std;

int main()
{
    int num,d1,d2,d3,d4;
    
    cout<<"Ingrese un numero de 3 cifras"<<endl;
    cin>>num;
    d1 = num /100;
    d2 = num /10 % 10;
    d3 = num % 10;

    /* Tambien se puede aplicar el código del ejercicio 3 
    d1 = num/100;
    d2 = (num - (d1*100))/10;
    d3 = (num - ((d1*100) + (d2*10))); */
    
    cout<< "Este numero tiene "<<d1<<" centenas, ";
    cout<<d2<<" dencenas y ";
    cout<<d3<<" unidades ";
    
    
    return 0;

}