/* Ejercicio 6 - Hacer un algoritmo que ingrese por teclado un número entero  n 
y a continuación ingrese n números más de los que tendrá que informar su promedio.
*/

#include <iostream>

using namespace std;

int main(){

    int suma=0,n,i;
    float numero;

    cout<<"Informar la cantidad de numeros para el promedio: ";
    cin>>n;

    for (i = 1; i <= n; i++){
        
        cout<<endl<<"Ingrese un numero: ";
        cin>>numero;
        suma = suma+numero;
    }
    
    cout<<endl<<"El promedio es: "<<suma/n;
    
    return 0;
}