#include <iostream>

using namespace std;

int mcd(int m, int n) {
    if ( m%n == 0) {
        return n;
    } else {
        return mcd(n,m%n);
    }
}

int main()
{
    int a,b;

    cout<<"Ingrese 2 números: "<<endl;
    cin>>a;
    cin>>b;

  
    cout<<"el mcd es: "<<mcd(a,b);
   
    return 0;

}
