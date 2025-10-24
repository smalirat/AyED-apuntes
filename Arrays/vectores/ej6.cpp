#include <iostream>

using namespace std;

int main() {
    int d1, d2;
    int cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0;
    int cont8 = 0, cont9 = 0, cont10 = 0, cont11 = 0, cont12 = 0;

    for (int i = 0; i < 2; i++) {
        cout << "Ingrese el resultado del primer dado: ";
        cin >> d1;
        cout << "Ingrese el resultado del segundo dado: ";
        cin >> d2;

        int suma = d1 + d2;

        switch (suma) {
            case 2:
                cont2++;
                break;
            case 3:
                cont3++;
                break;
            case 4:
                cont4++;
                break;
            case 5:
                cont5++;
                break;
            case 6:
                cont6++;
                break;
            case 7:
                cont7++;
                break;
            case 8:
                cont8++;
                break;
            case 9:
                cont9++;
                break;
            case 10:
                cont10++;
                break;
            case 11:
                cont11++;
                break;
            case 12:
                cont12++;
                break;
            default:
                break;
        }
    }

    cout << "Frecuencia de resultados:\n";
    cout << "2: " << cont2 << " veces\n";
    cout << "3: " << cont3 << " veces\n";
    cout << "4: " << cont4 << " veces\n";
    cout << "5: " << cont5 << " veces\n";
    cout << "6: " << cont6 << " veces\n";
    cout << "7: " << cont7 << " veces\n";
    cout << "8: " << cont8 << " veces\n";
    cout << "9: " << cont9 << " veces\n";
    cout << "10: " << cont10 << " veces\n";
    cout << "11: " << cont11 << " veces\n";
    cout << "12: " << cont12 << " veces\n";

    return 0;
}
