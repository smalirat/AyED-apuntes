//Ejercicio 3 - Se ingresan dos valores por teclado si el primero es mayor al segundo, informar la resta de los valores, en caso contrario la suma.

#include <iostream>

using namespace std;

int main(){
    int n1,n2,resta,suma;

    cout<<"Ingrese un número"<<endl;
    cin>>n1;
    cout<<"Ingrese otro número"<<endl;
    cin>>n2;



    if (n1>n2){
        resta = n1-n2;
        cout<<"La resta es "<<resta;
        }
    else{
        suma = n1+n2;
        cout<<"La suma es "<<suma;
        }

        return 0;
}