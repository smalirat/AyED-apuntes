

#include <iostream>
using namespace std;

int main() {
    int i;
    unsigned n,n2;
    float promedio,contador = 0,suma=0;

    cout<<"Ingrese numeros enteros positivos. Ingrese 0 para terminar.";

    for (int i = 1; ; i++) {
        cout<<endl<<"Ingrese un numero: ";
        cin >> n;

        if (n == 0) {
            break; // si se ingresa 0, terminamos el loop
        }

        suma += n;
        contador++;    
        promedio = suma/contador;
        cout<<"El promedio es de: "<<promedio;
        }
    return 0;
}
    
