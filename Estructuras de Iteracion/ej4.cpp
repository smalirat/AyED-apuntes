#include <iostream>

using namespace std;

int main(){

    int cant=0,i;
    float numero;

    for (i = 1; i <= 20; i++){
        
        cout<<endl<<"Ingrese un numero: ";
        cin>>numero;
            if(numero<0)
                cant++;
    }
    
    cout<<"Hay "<<cant<<" numeros negativos";
    
    return 0;
}