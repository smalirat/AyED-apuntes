#include <iostream>

using namespace std;

int main(){

    int nros[5];
    int mayor,numero;

    cout<<"ingrese un numero: ";
    cin>>nros[0];
    mayor = nros[0];


    for(int i=1;i<5,i++;){
        cout<<"ingrese un numero: ";
        cin>>nros[i];

        if (nros[i]>mayor){
            mayor = nros[i];
        }
    }

    cout<<"El mayor es: "<<mayor;

    return 0;
        

       
    }





