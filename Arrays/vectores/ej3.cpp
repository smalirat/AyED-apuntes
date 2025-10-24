#include <iostream>

using namespace std;

int main()
{
    int nro, suma=0,prom,cont=0;
    int nros[5];

    for(int i=0;i<5;i++){
        cout<<"ingrese un numero: ";
        cin>>nros[i];
       
    }

    for(int j=0;j<5;j++){
        suma+=nros[j];
        prom=suma/5;
    }

    for(int i=0;i<5;i++){
      if(nros[i]>prom){
            cout<<nros[i]<<endl;
        }
    }

 




    return 0;
   

}


