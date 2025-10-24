#include <iostream>

using namespace std;

int sumatoria(int m, int n){
    if (n==0){
        return 0;
    }
    else{
        return m + sumatoria(m,n-1);
    }
}



int main()
{
    int a,b;

    cout<<"Ingrese 2 números: "<<endl;
    cin>>a;
    cin>>b;

    cout<<"su producto es: "<<sumatoria(a,b);
   
    return 0;

}


