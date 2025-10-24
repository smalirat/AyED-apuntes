#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, integrantes, edad, primario = 0, secundario = 0, integrantes_familia;
    float edad_familia = 0, suma = 0, suma2 = 0, promedio_familia, mayor = 0, personas = 0, analfabeto = 0, promedio, mujer = 0, porcentaje, terciario = 0;
    string domicilio, nombre, familia_grande;
    char vivienda, sexo, estudios, completo;

    cout << "Ingrese cantidad de integrantes: ";
    cin >> integrantes;
    mayor = integrantes;

    while (integrantes != 0) {
        cout << "Domicilio: ";
        cin >> domicilio;
        cout << "Tipo de vivienda ('C' para casa, 'D' para departamento): ";
        cin >> vivienda;

        for (i = 1; i <= integrantes; i++) {
            cout << "Nombre y apellido: ";
            cin >> nombre;
            cout << "Edad: ";
            cin >> edad;

            personas++;
            suma += edad;
            suma2 += edad;

            cout << "Sexo ('F' para femenino, 'M' para masculino): ";
            cin >> sexo;
            cout << "Nivel de estudios alcanzado ('N' para ninguno, 'P' para primario, 'S' para secundario, 'T' para terciario): ";
            cin >> estudios;
            cout << "Estado de estudios ('C' para completo, 'I' para incompleto): ";
            cin >> completo;

            switch (estudios) {
                case 'N':
                case 'n':
                    if (edad > 10) {
                        analfabeto++;
                    }
                    break;
                case 'P':
                case 'p':
                    if (completo == 'C') {
                        primario++;
                    }
                    break;
                case 'S':
                case 's':
                    primario++;
                    if (completo == 'I') {
                        secundario++;
                    }
                    break;
                case 'T':
                case 't':
                    primario++;
                    if (sexo == 'F') {
                        terciario++;
                    }
                    break;
                default:
                    break;
            }

            promedio_familia = suma2 / integrantes;

            if (vivienda == 'D' && integrantes > mayor) {
                mayor = integrantes;
                familia_grande = domicilio;
            }

            if (promedio_familia > edad_familia) {
                edad_familia = promedio_familia;
            }

            if (sexo == 'F') {
                mujer++;
            }

            suma2 = 0;

            cout << "Ingrese cantidad de integrantes de una nueva familia: ";
            cin >> integrantes;
            mayor = integrantes;
        }
    }

    promedio = suma / personas;
    porcentaje = mujer / terciario * 100.0;

    cout << "Cantidad de personas que completaron el primario: " << primario << endl;
    cout << "Cantidad de analfabetos mayores de 10 años: " << analfabeto << endl;
    cout << "Lugar de la familia más grande: " << familia_grande << endl;
    cout<<"la mayor edad promedio: "<<edad_familia<<endl;
    cout<<"Secundarios incompletos: "<<secundario<<endl;
    cout<<"% de mujeres que completaron el terciario: "<<porcentaje<<endl;

}
