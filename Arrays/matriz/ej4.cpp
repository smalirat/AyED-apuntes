#include <iostream>
using namespace std;

void cargarMatriz(int m[7][5]){
    for(int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            m[i][j]=j+1;
            }
        }
    }

void cargarCeros(int m[7][5],int v1[], int v2[]){
    for(int i=0;i<7;i++){
        v1[i]=0;
        for(int j=0;j<5;j++){
            m[i][j]=0;
            }
        }
    for(int j=0;j<5;j++){
        v2[j]=0;
    }
}


void imprimirMatriz(int m[7][5]){
    for(int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            cout<<m[i][j]<<" ";
            }
        cout<< endl;
        }
    }

void cargarVentas(int m[7][5]){
    int modelo,color,cantidad;

    cout<<"Modelo: ";
    cin>>modelo;

    while(modelo>0){
        cout<<"Color: ";
        cin>>color;
        cout<<"Cantidad: ";
        cin>>cantidad;

        m[modelo-1][color-1]+=cantidad;

        cout<<"Modelo: ";
        cin>>modelo;

    }

    }

void listado(int m[7][5], int v1[], int v2[]){
    int total=0;
    for(int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            v1[i]+=m[i][j];
            v2[i]+=m[j][i];
            total+=m[i][j];
            }
        }
    for(int k=0;k<7;k++){
        cout<<"El modelo "<<k+1<<" "<<v1[k]<<" ventas"<<endl;
    }
    for(int t=0;t<5;t++){
        cout<<"El color "<<t+1<<" "<<v2[t]<<" ventas"<<endl;
    }

    cout<<"El total es: "<<total;

}


void totales(int m[7][5], int v1[], int v2[]){}    



int main() {
    int n;
    int matriz[7][5],ventas[7][5],modelo[7],color[5];

   
    cargarMatriz(matriz);
    cargarCeros(ventas,modelo,color);
    cargarVentas(ventas);
    imprimirMatriz(ventas);
    listado(ventas,modelo,color);


    //int sumatoria = diagonales(matriz,n);
    //cout<<endl<<sumatoria;


    
    return 0;
}