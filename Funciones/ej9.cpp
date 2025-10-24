/*Desarrollar una función tal que dada una fecha en formato número de 8 dígitos
(AAAAMMDD), devuelva el día, el mes y el año correspondientes
*/

#include <iostream>

using namespace std;


void funcion_fecha(unsigned fecha, unsigned &mes, unsigned &dia, unsigned &año) {
    

    año = fecha/10000;
    mes = (fecha%10000)/100;
    dia = fecha%100;


}


int main()
{
   
    unsigned fecha,año,mes,dia;

    cout<<"Ingrese una fecha en formato AAAAMMDD: ";
    cin>>fecha;

    funcion_fecha(fecha,  mes,  dia,  año);

    cout<<"El año es: "<<año;
    cout<<" El mes es: "<<mes;
    cout<<" El dia es: "<<dia;


  
    return 0;

}

