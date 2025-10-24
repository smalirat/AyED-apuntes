/*Desarrollar una función que dados el día, el mes y el año de una fecha correcta, devuelva la
misma en formato de entero de 8 dígitos con el formato AAAAMMDD.*/

#include <iostream>

using namespace std;


unsigned numero(unsigned año, unsigned mes, unsigned dia) {

    unsigned fecha = (año*10000)+(mes*100)+dia;

    return fecha;
}




int main()
{
   
    unsigned fecha,año,mes,dia;

    cout<<"Ingrese año: ";
    cin>>año;
    cout<<"Ingrese mes: ";
    cin>>mes;
    cout<<"Ingrese dia: ";
    cin>>dia;

    fecha = numero(año, mes, dia);

    cout << "La fecha en formato AAAAMMDD es: " << fecha << endl;

  
    return 0;

}
