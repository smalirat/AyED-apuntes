#include <iostream>

using namespace std;

string texto(string linea, int veces) {
    if (veces == 1) {
        return linea;
    } else {
            return linea + texto(linea, veces-1);
        }
    }




int main()
{
    int n;
    string linea;

    cout<<"Ingrese una linea de texto: ";
    cin>>linea;
    cout<<"Ingrese cuantas veces imprimirla: ";
    cin>>n;

    cout<<texto(linea,n);

    return 0;
    



}
