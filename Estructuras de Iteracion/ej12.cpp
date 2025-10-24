//Dado un número entero positivo informar su factorial.

// Dados n y m enteros positivos, informar su producto obtenido por sumas sucesivas.

#include <iostream>

using namespace std;

int main(){

    int n, factorial = 1;

    cout<<"Ingrese un numero entero positivo: ";
    cin>>n;
   
    for (int i = 1; i <= n; i++){
        factorial *= i;
    }
    
    cout<<"El factorial de "<<n<<" es: "<<factorial;

    return 0;   
}