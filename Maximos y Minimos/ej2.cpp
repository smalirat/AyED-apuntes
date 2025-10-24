#include <iostream>

using namespace std;

int main()
{
    int i, pos = 1;
    float mayor, n;

    cout << "Ingrese el primer valor: ";
    cin >> mayor;

    for (i = 2; i < 5; i++) {
        cout << "Ingrese un valor: ";
        cin >> n;
        if (n > mayor) {
            mayor = n;
            pos = i;
        }
    }

    cout << mayor << " es el mayor en la posición " << pos;
    return 0;
}
