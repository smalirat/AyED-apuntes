//Ejercicio 10: Dado la longitud de los dos catetos de un triángulo rectángulo y mostrar la longitud de la hipotenusa

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float c1,c2,hipotenusa,pitagoras;
    
    cout<<"Ingrese el lao de un cateto"<<endl;
    cin>>c1;
    cout<<"Ingrese el lado del otro  cateto"<<endl;
    cin>>c2;
    
    pitagoras = c1*c1 + c2*c2;
    hipotenusa = sqrt(pitagoras);
    cout<<hipotenusa;


    
    
    return 0;

}