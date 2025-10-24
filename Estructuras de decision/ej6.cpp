//Ejercicio 6 - Escribir un algoritmo que lea dos fechas (día, mes y año) e informe cual es la más reciente

#include <iostream>

using namespace std;

int main(){
    int yr1,mes1,dia1,yr2,mes2,dia2,fecha1,fecha2;

    cout<<"Ingrese una fecha "<<endl<<"Año:";
    cin>>yr1;
    cout<<"Mes:";
    cin>>mes1;
    cout<<"Día: ";
    cin>>dia1;
    cout<<"Ingrese otra fecha "<<endl<<"Año:";
    cin>>yr2;
    cout<<"Mes:";
    cin>>mes2;
    cout<<"Día: ";
    cin>>dia2;
    
    fecha1 = yr1 * 365 + mes1 * 30 + dia1;
    fecha2 = yr2 * 365 + mes2 * 30 + dia2;



    if (fecha1<fecha2){
        cout<<"La segunda fecha es más reciente ";
        }
    else{
        if(fecha1>fecha2)
            cout<<"La primera fecha es más reciente";
        else
            cout<<"Las fechas son iguales";
        }

        return 0;
}