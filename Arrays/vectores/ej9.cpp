#include <iostream>

using namespace std;

void ordenar(unsigned vecCod[], int vecPrec[], int n){
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
    cout<<"Ingrese cant de alumnos: ";
    cin>>n;


    int notas[n]; 
    unsigned dni[n];

 
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la nota: ";
        cin >> notas[i];
        
        cout << "Ingrese el dni del alumno: ";
        cin >> dni[i];
        v++;
    }
   

    ordenar(dni, notas, v);

    for (int i = 0; i < v; i++) {
        cout << "Nota: " << notas[i] << ", Dni: " << dni[i] << endl;
    }




return 0;

}