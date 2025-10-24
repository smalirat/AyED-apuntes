#include <iostream>

using namespace std;

int main(){

    int suma=0,i;
    float numero;

    for (i = 1; i <= 10; i++){
        
        cout<<endl<<"Ingrese un numero: ";
        cin>>numero;
        suma = suma+numero;
    }
    
    
    cout<<endl<<"la suma de los numeros es: "<<suma;
    
    return 0;
}