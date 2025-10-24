#include <iostream>

using namespace std;

int potencia(int m, int n) {
   if(n==0){
    return 1;
   }
   else{
    return m * potencia(m,n-1);
   }
}


int main()
{
    int a,n;

    cout<<"Ingrese 1 número: ";
    cin>>a;
    cout<<"Ingrese su potencia: ";
    cin>>n;

    cout<<"el resultado es: "<<potencia(a,n);
   
    return 0;

}
