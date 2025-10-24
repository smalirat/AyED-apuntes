/*Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo valores):
a) El valor máximo negativo
b) El valor mínimo positivo
d) El promedio de todos los valores.
*/


#include <iostream>

using namespace std;

int main()
{
    int i;
    float mayor=0,n,menor=0,cont=1,promedio,suma;

    cout<<"Ingrese un numero, pulse 0 para finalizar: ";
    cin>>n;
    mayor = n;
    menor = n;
    suma = n;
    
    while(n!=0){
        if(n>0 && n<menor){
            menor = n;
            }
        else 
            if (n<0 && n<mayor){
                mayor = n;
                }
        cout<<"Ingrese otro numero: ";
        cin>>n;
    cont++;
    suma += n;

    }
    promedio= suma/cont;

    cout<<mayor<<" es el mayor de los negativos, ";
    cout<<menor<<" es el menor de los positivos ";
    cout<<"el promedio es "<<promedio;


    return 0;

}