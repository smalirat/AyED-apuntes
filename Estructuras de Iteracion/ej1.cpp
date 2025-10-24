#include <iostream>

using namespace std;

int main()
{
    int num, i;
    for(i=1;i<=10;i++)
    {
        cout<<"Ingrese el numero entero de orden "<<i<<endl;
        cin>>num;
        if(num>0)
         cout<<num<<" Es positivo"<<endl;
    }
   return 0;
}