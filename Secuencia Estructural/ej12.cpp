//Ejercicio 12: Se desea calcular el valor del cambio de moneda a Dólares y Euros ingresando la cantidad en Pesos y las cotizaciones.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float cDolar,cEuro,pesos,dolar,euro;
    
    cout<<"¿Cuántos pesos quiere cambiar?"<<endl;
    cin>>pesos;
    cout<<"¿A cuanto cotiza el Dolar?"<<endl;
    cin>>cDolar;
    cout<<"¿A cuanto cotiza el Euro?"<<endl;
    cin>>cEuro;
    
    dolar = pesos /cDolar;
    euro = pesos /cEuro;
    
    cout<< "Puedes comprar: "<<dolar<<" dolares o "<<euro<<" euros";


    
    
    return 0;

}