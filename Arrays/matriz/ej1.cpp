#include <iostream>
using namespace std;

void cargarMatriz(int matrizMN[][25]){
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            matrizMN[i][j]=j+1;
            }
            matrizMN[i][4]=2;
        }
    }

void imprimirMatriz(int matrizMN[][25]){
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            cout<<matrizMN[j][i]<<" ";
            }
        cout<<endl;
        }
    }

void sumaColumnas(int matrizMN[][25], int v[]){
    for(int t=0;t<5;t++){
        v[t]=0;
        }
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            v[j]+=matrizMN[j][i];
            }
    }
    for(int k=0;k<5;k++){
        cout<<v[k]<<" ";
        }   
}

void maximoFila(int matrizMN[][25], int max[]){
float m;
    for(int i=0;i<5;i++){
        bool pri=true;
        for(int j=0;j<5;j++){
            if(matrizMN[i][j]!=0){
                if(pri || matrizMN[i][j]>m){
                    pri=false;
                    m=matrizMN[i][j];
                }
            }
    }    
        cout<<m<<" ";
    }

   
}

       
int main() {
    int matriz[30][25];
    int vectorsuma[5];
    
    cargarMatriz(matriz);
    imprimirMatriz(matriz);
    sumaColumnas(matriz, vectorsuma);
    cout<<endl;
    maximoFila(matriz,vectorsuma);
    
    
    
    


    return 0;
}