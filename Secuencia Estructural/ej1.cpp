//Ejercicio 1 - Dados 3 numeros enteros positivos, muestre la suma, la resta y la multiplicacion de todos.

#include <iostream>

using namespace std;

int main()
{
    int n1,n2,n3,suma,resta,producto;

    cout<<"Ingrese 3 numeros enteros positivos"<<endl;
    cin>> n1;
    cin>> n2;
    cin>> n3;
    suma = n1+n2+n3;
    resta = n1-n2-n3;
    producto = n1*n2*n3;
    cout<<"El resultado de la suma es "<<suma<<endl;
    cout<<"El resultado de la resta en ese orden es "<<resta<<endl;
    cout<<"Su producto es "<<producto<<endl;
    return 0;

}
