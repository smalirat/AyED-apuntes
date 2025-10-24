/*Un negocio vende distintos artículos identificados por un código, según se muestra: .código 1; 10 ; 100: l0 pesos la unidad
.código 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos. 
.código 3; 33: 3 pesos la unidad. 
Si la compra es por más de 10 unidades se hace un descuento del 10% sobre el total.
.código 4; 44: 2 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a comprar y se informe el importe de la compra:
*/

#include <iostream>
using namespace std;

int main() {
    int codigo, cantidad;
    float precio_unitario, importe;

    cout << "Ingrese el código del artículo: ";
    cin >> codigo;

    cout << "Ingrese la cantidad a comprar: ";
    cin >> cantidad;

    switch (codigo) {
        case 1:
        case 10:
        case 100:
            cout<<"El importe es de "<<cantidad*10;
            break;
        case 2:
        case 22:
        case 222:
            if ((cantidad%10)==0) {
                cout<<"El importe es de "<<cantidad/10*65;
            } else {
                cout<<"El importe es de "<<(cantidad/10*65) + (cantidad%10*7);
            }
            break;
        case 3:
        case 33:
            if(cantidad>10)
                cout<<"El importe es de "<<cantidad*3*0.9;
            else
                cout<<"El importe es de "<<cantidad*3;
            break;
        case 4:
        case 44:
                cout<<"el importe es de "<<cantidad*2;
            break;
        default:
            cout << "Código inválido." << endl;
            return 0;
    }

    return 0;
}