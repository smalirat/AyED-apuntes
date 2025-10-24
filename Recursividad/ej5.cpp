#include <iostream>

using namespace std;

int combinatorio(int m, int n) {
    if (n == 0) {
        return 1;
    } else {
        return combinatorio(m,n-1) * ((float)(m-n+1)/n);
    }
}

int main()
{
    int a,b;

    cout<<"Ingrese 2 números: "<<endl;
    cin>>a;
    cin>>b;

  
    cout<<"el combinatorio es: "<<combinatorio(a,b);
   
    return 0;

}
