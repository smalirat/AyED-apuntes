//Ejercicio 6: Obtener la edad de una persona en meses, si se ingresa su edad en años y meses. Ejemplo: Ingresado 3 años 4 meses debe mostrar 40 meses.

#include <iostream>

using namespace std;

int main()
{
    float radio,perimetro,area,diametro;
    
    cout<<"Ingrese el radio de un ciruclo "<<endl;
    cin>> radio;
    perimetro = radio * 2 * 3.14;
    area = radio * radio * 3.14;
    diametro = radio * 2;
    cout<<"Teniendo en cuenta a pi como 3.14."<<endl;
    cout<<"Su superficie es "<<area;
    cout<<"Su perímetro es "<<perimetro;
    cout<<"Su diámetro es "<<diametro;
    
    

  
    return 0;

}