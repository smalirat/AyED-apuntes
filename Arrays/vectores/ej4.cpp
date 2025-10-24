#include <iostream>

using namespace std;

int main(){

    int nros[5];
    int mayor,menor,numero,pos_may,pos_men;

    cout<<"ingrese un numero: ";
    cin>>nros[0];
    mayor = nros[0];


    for(int i=1;i<5;i++){
        cout<<"ingrese un numero: ";
        cin>>nros[i];

        if (nros[i]>mayor){
            mayor = nros[i];
            pos_may=i+1;
        }

        if (nros[i]<menor){
            menor = nros[i];
            pos_men=i+1;
        }
        
    }

    for(int i=1;i<5;i++){
        cout<<nros[0]<<" "<<nros[i]<<" ";
    }


    cout<<endl<<"El mayor es: "<<mayor<<" en la posicion: "<<pos_may;
    cout<<endl<<"El menor es: "<<menor<<" en la posicion: "<<pos_men;

    return 0;
        

       
    }