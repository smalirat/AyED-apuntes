#include <iostream>

using namespace std;


int mcd(int a, int b);


int divisor,a,b;

int main()
{
   
   cout<<"Ingrese un numero: ";
   cin>>a;
   cout<<"Ingrese un numero: ";
   cin>>b;

   divisor = mcd(a, b);

   cout<<"el maximo comun diivisor es "<<divisor;

   return 0;


}


int mcd(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}