#include <iostream>
using namespace std;

void cargarMatriz(int m[][25],int tam){
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            m[i][j]=3*j+i;
            }
        }

    }

void imprimirMatriz(int m[][25], int tam){
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            cout<<m[i][j]<<" ";
            }
        cout<< endl;
        }
    }



int diagonales(int m[][25], int tam){
    int suma1=0;
    for(int i=0;i<tam;i++){
        for(int j=i+1;j<tam;j++){
            suma1+=m[i][j];
        }
    }
    return suma1;
}

    



int main() {
    int n;
    int matriz[n][25];

    cout<<"Tamaño de N: ";
    cin>>n;

    cargarMatriz(matriz,n);
    imprimirMatriz(matriz,n);
    int sumatoria = diagonales(matriz,n);
    cout<<endl<<sumatoria;


    
    return 0;
}