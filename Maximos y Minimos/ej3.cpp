#include <iostream>

using namespace std;

int main()
{
    int i,cont=1;
    float mayor, n;

    cout << "Ingrese el primer valor: ";
    cin >> mayor;

    for (i = 1; i < 5; i++) {
        cout << "Ingrese un valor: ";
        cin >> n;
        if (n > mayor) {
            mayor = n;
            
        }
        else{
            if(n=mayor)
                cont++;
        }
    }

    cout << mayor << " es el mayor, y fue ingresado "<<cont<<" veces";
    return 0;
}
