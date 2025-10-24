#include <iostream>

using namespace std;

int main()
{
    int i;
    float mayor,n,mayor2;

    cout<<"Ingrese un numero: ";
    cin>>mayor;
    cout<<"Ingrese otro numero: ";
    cin>>mayor2;
    for (i = 2; i <= 5; i++) {
        cout<<"Ingrese otro numero: ";
        cin >> n;
        if (n>mayor){
            mayor = n;
        }
        else if (n>mayor2){
            mayor2=n;
        }
    }
    cout<<mayor<<" es el mayor, ";
    cout<<mayor2<<" es el  segundo mayor";

    return 0;

}