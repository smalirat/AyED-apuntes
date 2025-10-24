// Dados n y m enteros positivos, informar su producto obtenido por sumas sucesivas.

#include <iostream>

using namespace std;

int main(){

    int n,m,i,producto;

    cout<<"Ingresar un numero: ";
    cin>>n;
    cout<<"Ingresar otro: ";
    cin>>m;

    producto = 0;
    for (i = 1; i <= m; i++){
        producto += n;
    }
    
    cout<<"El producto de "<<n<<" y "<<m<<" es: "<<producto;
    return 0;   
}
