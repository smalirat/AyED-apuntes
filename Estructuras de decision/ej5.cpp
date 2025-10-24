//Ejercicio 5 - Dados tres valores que se ingresan por teclado, mostrar por pantalla el valor mayor

#include <iostream>

using namespace std;

int main(){
    int n1,n2,n3;

    cout<<"Ingrese un numero ";
    cin>>n1;
    cout<<"Ingrese otro ";
    cin>>n2;
    cout<<"Ingrese otro ";
    cin>>n3;



    if (n1>n2 && n1>n3){
      
        cout<<"El numero mas grande es "<<n1;
        }
    else{
        if (n2>n3 && n2>n1)
            cout<<"El numero mas grande es "<<n2;
        else
            cout<<"El numero mas grande es "<<n3;
        }

        return 0;
}