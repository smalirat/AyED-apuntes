//Dados tres valores que representan los lados de un triángulo, informar si el mismo es equilátero, isósceles o escaleno

#include <iostream>
using namespace std;

int main()
{
    float l1, l2, l3;
    cout << "Ingrese la longitud del primer lado: ";
    cin >> l1;
    cout << "Ingrese la longitud del segundo lado: ";
    cin >> l2;
    cout << "Ingrese la longitud del tercer lado: ";
    cin >> l3;

    if ((l1==l2) && (l1==l3))
    {
        cout << "Forman un triangulo equilátero";
    }
    else
    {
        if((l1==l2 && l1!=l3)||(l1==l3 && l1!=l2))
            cout <<"Forman triangulo isoceles";
        else
            cout<<"Forman un triangulo escaleno";
    }   

    return 0;
}