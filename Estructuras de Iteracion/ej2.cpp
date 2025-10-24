#include <iostream>

using namespace std;

int main(){

    int cant,i;
    float n1,n2,nota;
    string nombre;

    cout<<"Ingrese la cantidad de alumnos: ";
    cin>>cant;


    for (i = 1; i <= cant; i++){
        
        cout<<endl<<"Ingrese su nombre: ";
        cin>> nombre;
        cout<<"Ingrese su nota: ";
        cin>> n1;
        cout<<"Ingrese su otra nota: ";
        cin>> n2;
        
        nota = (n1+n2)/2;

        cout<<nombre<<" Su promedio es "<<nota;

    
            

        }
    
    
    
    return 0;


}