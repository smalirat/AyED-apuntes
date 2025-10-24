#include <iostream>

using namespace std;

struct Producto {
    int codigo;
    int precio;
};

void ordenar(Producto vec[], int n){
    int i=1, j, aux, aux2;     
    bool cambio;     
    do{         
        cambio=false;         
        for(j=0; j  <  n-i; j++){             
            if(vec[j].precio < vec[j+1].precio){                 
                aux=vec[j].codigo;  
                aux2=vec[j].precio;

                vec[j].codigo=vec[j+1].codigo; 
                vec[j].precio=vec[j+1].precio;

                vec[j+1].codigo=aux;
                vec[j+1].precio=aux2;                 
                cambio=true;}         

        }         
        i++; 

    } while(i < n && cambio); 
    } 




int main(){
    int v=0,n;
    cout<<"Ingrese cant de productos: ";
    cin>>n;


    Producto productos[n];

 
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el código del producto: ";
        cin >> productos[i].codigo;
        
        cout << "Ingrese el precio del producto: ";
        cin >> productos[i].precio;
        v++;
    }
   

    ordenar(productos, v);

    for (int i = 0; i < v; i++) {
        cout << "Código: " << productos[i].codigo << ", Precio: " << productos[i].precio << endl;
    }




return 0;

}