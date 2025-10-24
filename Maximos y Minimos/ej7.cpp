#include <iostream>

using namespace std;

int main()
{
    int tiros=0,max_puntaje = 0,numero,i,mayor,mayor2;
    float promedio,suma,puntaje;
    char continuar = 'S';

    while (continuar != 'N') {
        cout<<"Numero dado 1: ";
        cin>>mayor;
        cout<<"Numero dado 2: ";
        cin>>mayor2;
    for (i = 2; i <= 5; i++) {
        cout<<"numero dado "<<i<<": ";
        cin >> numero;
        if (numero>mayor){
            mayor = numero;
        }
        else if (numero>mayor2){
            mayor2=numero;
        }
    }
        
        // Calcular el puntaje sumando los dos valores más altos
        puntaje = mayor + mayor2;

        // Actualizar los valores de tiros, max_puntaje y sum_puntajes
        tiros++;
        suma += puntaje;
        if (puntaje > max_puntaje) {
            max_puntaje = puntaje;
        }

        // Preguntar si el usuario desea continuar
        cout<<"Puntaje del tiro "<<tiros<<": "<<puntaje<<endl;
        cout<<"Continua? S/N: ";
        cin>>continuar;
    }

    // Calcular el puntaje promedio
    promedio = suma/tiros;

    // Imprimir los resultados
    cout<<"Cantidad de tiros: "<<tiros<<endl;
    cout<<"Maximo puntaje obtenido: "<<max_puntaje<< endl;
    cout<<"Puntaje promedio: "<<promedio<< endl;

    return 0;
}