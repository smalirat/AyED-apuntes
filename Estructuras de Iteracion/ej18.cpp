#include <iostream>

using namespace std;

int main(){

    int n,i;
    float notas=0,nota,promedio;
    string nombre;

    for (i = 1; i <= 3; i++){
        
        cout<<endl<<"Ingrese su nombre: ";
        cin>> nombre;
        for (i = 1; i++;){
        cout<<"Ingrese su nota, pulse 0 para finalizar: ";
        cin>>nota;
            if(nota !=0){
                notas+=nota;
                n++;}
            else{
                break;
            }
        }
        promedio = notas/n;
        

        cout<<nombre<<" su promedio es "<<promedio;

    
            

        }
    
    
    
    return 0;


}