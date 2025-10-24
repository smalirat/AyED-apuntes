//Ejercicio - 10 Hacer un algoritmo que ingresando por teclado el mes (1 a 12) y el año (4 dígitos), informe la cantidad de días que tiene el mes.

#include <iostream>

using namespace std;

int main() {
    int mes, yr, dias;

    cout << "Ingrese el mes (1-12): ";
    cin >> mes;

    cout << "Ingrese el año (4 cifras): ";
    cin >> yr;

    switch (mes) {
        case 1: // Enero
        case 3: // Marzo
        case 5: // Mayo
        case 7: // Julio
        case 8: // Agosto
        case 10: // Octubre
        case 12: // Diciembre
            dias = 31;
            break;
        case 4: // Abril
        case 6: // Junio
        case 9: // Septiembre
        case 11: // Noviembre
            dias = 30;
            break;
        case 2: // Febrero
            if ((yr % 4 == 0 && yr % 100 != 0) || yr % 400 == 0) {
                dias = 29; 
            } else {
                dias = 28; 
            }
            break;
        default:
            cout << "El mes ingresado es inválido." << endl;
            return 0;
    }

    cout << "El mes " << mes << " del año " << yr << " tiene " << dias << " días." << endl;

    return 0;
}
