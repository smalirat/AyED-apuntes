//Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los menores que –10

#include <iostream>

using namespace std;

int main(){

    int may=0,men=0,cont=0,n,i;
    float numero;

    for (i = 1; i <= 5; i++){
        
        cout<<endl<<"Ingrese un numero: ";
        cin>>numero;
        if (numero>100){
                cont++;
                may+=numero;
        }
        else{
            if(numero<-10)
                men+= numero;
        }
            
    }
    

    cout<<endl<<"La suma de los menores a -10 es: "<<men;
    cout<<endl<<"El promedio de los mayores a 100 es: "<<(float)may/cont;
    
    return 0;
}