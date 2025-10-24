#include <iostream>

using namespace std;

struct Alumno {
    int nota[10];
    string nombre[10];
};

float promedio(int v[], int tam) {
    float suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += v[i];
    }
    float promedio = suma / tam;
    return promedio;
}

int main(){
    Alumno alumno;
    int tam, i, j, cant_alumnos = 3;
    float alumnos[cant_alumnos];

    for (i = 0; i < cant_alumnos; i++) {
        tam = 0;
        j = 0;
        cout << "Nombre: ";
        cin >> alumno.nombre[j];
        
        do {
            cout << "Nota: ";
            cin >> alumno.nota[j];
            tam++;
            j++;
        } while (alumno.nota[j - 1] > 0 && alumno.nota[j - 1] < 11);
        
        alumnos[i] = promedio(alumno.nota, tam - 1);
    }

    for (int k = 0; k < cant_alumnos; k++) {
        cout << alumno.nombre[k] << "-" << alumnos[k] << endl;
    }

    return 0;
}
