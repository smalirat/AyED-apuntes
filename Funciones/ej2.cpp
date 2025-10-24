#include <iostream>
using namespace std;

unsigned factorial(unsigned n) {
    unsigned result = 1;
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    unsigned n;
    cout << "Ingrese un numero: ";
    cin >> n;

    unsigned factorial_n = factorial(n);

    cout << "El factorial de " << n << " es " << factorial_n << endl;


    return 0;
}
