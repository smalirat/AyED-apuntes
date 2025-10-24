#include <iostream>

using namespace std;

void ordenar(int vecCod[], int vecPrec[], int n){
    int i=1, j, aux, aux2;     
    bool cambio;     
    do{         
        cambio=false;         
        for(j=0; j  <  n-i; j++){             
            if(vecPrec[j] < vecPrec[j+1]){                 
                aux=vecCod[j];  
                aux2=vecPrec[j];

                vecCod[j]=vecCod[j+1]; 
                vecPrec[j]=vecPrec[j+1];

                vecCod[j+1]=aux;
                vecPrec[j+1]=aux2;                 
                cambio=true;}         

        }         
        i++; 

    } while(i < n && cambio); 
    } 




int main(){
    int v=0,n;
    cout<<"Ingrese cant de productos: ";
    cin>>n;


    int codigo[10], precio[10];

 
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el código del producto (0 para finalizar): ";
        cin >> codigo[i];
        
        cout << "Ingrese el precio del producto: ";
        cin >> precio[i];
        v++;
    }
   

    ordenar(codigo, precio, v);

    for (int i = 0; i < v; i++) {
        cout << "Código: " << codigo[i] << ", Precio: " << precio[i] << endl;
    }




return 0;

}