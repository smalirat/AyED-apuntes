/*Desarrollar un procedimiento tal que dada una hora (HHMMSS) y un tiempo también en
formato HHMMSS devuelva la nueva hora que surge de sumar el tiempo a la hora inicial,
considere también si cambió el día.
*/



#include <iostream>

using namespace std;

void horario(unsigned numero, unsigned &hora, unsigned &minuto, unsigned &segundo) {
    hora = numero / 10000;
    minuto = (numero % 10000) / 100;
    segundo = numero % 100;
}

void calculo(unsigned int hora1, unsigned int minuto1, unsigned int segundo1, 
             unsigned int hora2, unsigned int minuto2, unsigned int segundo2, 
             unsigned int &nueva_hora, unsigned int &nuevo_minuto, unsigned int &nuevo_segundo) {
    nuevo_segundo = segundo1 + segundo2;
    nuevo_minuto = minuto1 + minuto2 + nuevo_segundo / 60;
    nueva_hora = hora1 + hora2 + nuevo_minuto / 60;

    nuevo_segundo %= 60;
    nuevo_minuto %= 60;
    nueva_hora %= 24;


    if (nueva_hora >= 24) {
        nueva_hora -= 24;
    }

}

int main() {
    unsigned numero1, hora1, minuto1, segundo1;
    unsigned numero2, hora2, minuto2, segundo2;

    cout << "Ingrese una hora (HHMMSS): ";
    cin >> numero1;
    horario(numero1, hora1, minuto1, segundo1);

    cout << "Ingrese otra hora (HHMMSS): ";
    cin >> numero2;
    horario(numero2, hora2, minuto2, segundo2);

    unsigned nueva_hora, nuevo_minuto, nuevo_segundo;
    calculo(hora1, minuto1, segundo1, hora2, minuto2, segundo2, nueva_hora, nuevo_minuto, nuevo_segundo);

    cout << "La nueva hora es: " << nueva_hora << ":" << nuevo_minuto << ":" << nuevo_segundo << endl;

    return 0;
}
