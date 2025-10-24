#include <iostream>
using namespace std;

unsigned factorial(unsigned n) {
    unsigned result = 1;
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

float combinatoria(unsigned m, unsigned n){
    return factorial(m)/(factorial(n) * factorial(m-n));
}

int main() {
    unsigned n,m,cuenta;
    cout << "Ingrese un numero: ";
    cin >> m;
    cout << "Ingrese un numero: ";
    cin >> n;

    cuenta = combinatoria(m,n);

    cout<<"El combinatorio de "<<m<<" tomados de a "<<n<<" es: "<<cuenta;
   



    return 0;
}
