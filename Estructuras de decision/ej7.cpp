/*Ejercicio 7 - Dado tres valores que representan las longitudes de segmentos
determinar e imprimir una leyenda según sea: “Forman triangulo” o “No forman triangulo”.*/

#include <iostream>
using namespace std;

int main()
{
    float l1, l2, l3;
    cout << "Ingrese la longitud del primer segmento: ";
    cin >> l1;
    cout << "Ingrese la longitud del segundo segmento: ";
    cin >> l2;
    cout << "Ingrese la longitud del tercer segmento: ";
    cin >> l3;

    if ((l1+l2>l3) && (l1+l3>l2) && (l2+l3>l1))
    {
        cout << "Forman triangulo";
    }
    else
    {
        cout << "No forman triangulo";
    }

    return 0;
}