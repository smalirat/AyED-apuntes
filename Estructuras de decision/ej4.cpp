/*Ejercicio 4 - Confeccionar un programa que solicite dos valores reales positivos, expresados en cm. 
El primero corresponde a la base y el segundo a la altura de un triángulo, se desea calcular el valor de la superficie. 
Si la superficie calculada es menor a 100 cm2, expresarla en milímetros cuadrados, caso contrario en metros cuadrados. Informar resultado con unidades. 
( 1 m2 = 10.000 cm2)*/

#include <iostream>

using namespace std;

int main(){
    float n1,n2,area,mm,mts;

    cout<<"Ingrese la base del triángulo en centímetros"<<endl;
    cin>>n1;
    cout<<"Ingrese la altura del triángulo "<<endl;
    cin>>n2;

    area = n1*n2/2;

    if (area<100){
        mm = area*10;
        cout<<"El area es de "<<mm<<" milímetros";
        }
    else{
        mts = area/10000; 
        cout<<"El area es de "<<mts<<" metros";
        }

        return 0;
}