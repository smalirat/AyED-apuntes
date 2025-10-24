#include <iostream>

using namespace std;

int espejo(int numero) {
    int digito = numero%10;

    if (numero/100==digito){
        return numero;
    }
    else{
        return digito*100 + espejo(numero/10);
    }
}

int main()
{
    int n;

    cout<<"Ingrese un número: "<<endl;
    cin>>n;
    cout<<"el especular es: "<<espejo(n);
   
    return 0;

}
