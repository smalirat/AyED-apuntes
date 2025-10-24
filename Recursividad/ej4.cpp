#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else{
        return (n-1) + fibonacci(n-2);
    }
   
}


int main()
{
    int a;

    cout<<"Ingrese un número: ";
    cin>>a;
  
    cout<<"el termino en la serie de fibonacci es: "<<fibonacci(a);
   
    return 0;

}
