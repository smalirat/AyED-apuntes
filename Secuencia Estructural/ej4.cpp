//Ejercicio 4: Obtener la edad de una persona en meses, si se ingresa su edad en años y meses. Ejemplo: Ingresado 3 años 4 meses debe mostrar 40 meses.

#include <iostream>

using namespace std;

int main()
{
    int meses,años,mesesVividos,edad;
    
    cout<<"Ingrese su edad en años "<<endl;
    cin>> años;
    cout<<"Ingrese cuantos meses falta para su cumpleaños ";
    cin>> meses;
    mesesVividos= 12 - meses;
    edad = años*12 + mesesVividos;
    cout<<"Has vivido "<<edad;
  
    return 0;

}