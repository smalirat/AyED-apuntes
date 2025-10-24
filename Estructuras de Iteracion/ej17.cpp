#include <iostream>
using namespace std;

int main() {
    int escaleno=0, isoceles=0, equilatero=0;
    float lado1, lado2, lado3;

    do {
        cout << endl << "Ingrese el primer lado: ";
        cin >> lado1;
        cout << endl << "Ingrese el segundo lado: ";
        cin >> lado2;
        cout << endl << "Ingrese el tercer lado: ";
        cin >> lado3;

        if (lado1 != 0 && lado2 != 0 && lado3 != 0) {
            if (lado1 == lado2 && lado1 == lado3) {
                equilatero++;
            } else 
                if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
                    isoceles++;
                }
                else {
                    escaleno++;
                }
        }
    } while (lado1 != 0 && lado2 != 0 && lado3 != 0);

    cout<<endl<<"Hay "<<equilatero<<" triangulos equilateros, "<<escaleno<<" escalenos y "<<isoceles<<" isoceles";
    
    return 0;
}
