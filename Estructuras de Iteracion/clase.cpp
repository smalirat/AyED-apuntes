#include <iostream>

using namespace std;

int main(){

    int nota,cont,i;
    string nombre;

    for (i = 1; i <= 5; i++){
        cout<<endl<<"Ingrese su nombre: ";
        cin>> nombre;
        cout<<"Ingrese su nota: ";
        cin>> nota;

        if(nota>=6)
            cout<<nombre<<" esta aprobado"<<endl;
        else
            cout<<nombre<<" esta desaprobado"<<endl;

        }


    return 0;


}