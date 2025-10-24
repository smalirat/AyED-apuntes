/*Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre = ‘FIN’, 
informar el nombre de la persona con mayor edad y el de la más joven. */

#include <iostream>

using namespace std;

int main()
{
    int i;
    float mayor=0,menor=0;
    unsigned edad;
    string nombre,viejo,joven;
    

    cout<<"Ingrese la fecha de nacimiento (AAAAMMDD, sin usar barras o espacios): ";
    cin>>edad;
    cout<<"Ingrese su nombre: ";
    cin>>nombre;
    
    mayor = edad;
    menor = edad;
    
    while(nombre != "FIN" ){
        if(edad<menor){
            menor = edad;
            viejo = nombre;
            }
        else 
            if (edad>mayor){
                mayor = edad;
                joven = nombre;
                }

        cout<<"Ingrese su fecha de nacimiento: ";
        cin>>edad;
        cout<<"Ingrese su nombre: ";
        cin>>nombre;
    }

    cout<<viejo<<" es el mas grande, ";
    cout<<joven<<" es el mas joven ";

    return 0;

}