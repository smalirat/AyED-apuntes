#include <iostream>

using namespace std;

int main() {
    int cuenta, deudor = 0, acreedor = 0, nulo = 0;
    string nombre;
    float saldo;

    cout<<"Ingrese el numero de cuenta: ";
    cin>>cuenta;

    while (cuenta >= 0) {
        cout<<"Ingrese el nombre del cliente: ";
        cin>>nombre;
        cout<<"Ingrese el saldo actual: ";
        cin>>saldo;

        if (saldo < 0) {
            cout <<"Cuenta "<<cuenta<<" del cliente "<<nombre<<"es deudor"<<endl;
            deudor++;
        } else if (saldo > 0) {
            cout<<"Cuenta "<<cuenta<<" del cliente "<<nombre<<" es acreedor"<<endl;
            acreedor++;
        } else {
            cout << "Cuenta " << cuenta << " del cliente " << nombre << " tiene saldo nulo" << endl;
            nulo++;
        }

        cout << "Ingrese el numero de cuenta: ";
        cin >> cuenta;
    }

    cout << "Cantidad de cuentas con saldo deudor: " << deudor << endl;
    cout << "Cantidad de cuentas con saldo acreedor: " << acreedor << endl;
    cout << "Cantidad de cuentas con saldo nulo: " << nulo << endl;

    return 0;
}