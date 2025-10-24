#include <iostream>

using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = n; i>1;i--) {
        result *= i;
    }
    return result;
}




int main()
{
    int n;

    cout<<"Ingrese un numero";
    cin>>n;
    cout<<"Su factorial es: "<<factorial(n);



}
