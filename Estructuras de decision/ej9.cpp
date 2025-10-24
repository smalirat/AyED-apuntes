//Ejercicio - 9 Dado un número de cinco cifras informar si es capicúa.

#include <iostream>

using namespace std;

int main(){
    int n1,d1,d2,d4,d5;

    cout<<"Ingrese un número de 5 cifras"<<endl;
    cin>>n1;
    d1 = n1/10000;
    d2 = (n1/1000)%10;
    d4 = (n1/10)%10;
    d5 = n1%10;

    if (n1 < 10000 || n1 > 99999) {
        cout << "El número no tiene cinco cifras." << endl;
        return 0;
    }


    if (d1==d5 && d2==d4)
        cout<<"El numero es capicua";
    else
        cout<<"El numero no es capicua";
}
