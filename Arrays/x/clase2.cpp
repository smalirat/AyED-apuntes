#include <iostream>

using namespace std;

int maximo(int v[],int t,int pos[], int &j[]){

    int m,j;
    
    for (int i=0;i<t;i++){
        if(i==0 || v[i]>m){
            m=v[i];
            j=0;
            pos[j]=i;
            j++;
        }
        else{
            if(v[i==m])
            {
                pos[j]=i;
                j++;
            }


        }
    }
}

int main()
{

    int vecNros[10]={13,40,6,78,3,432,34,1,87,10};
    int vecPos[10], tamPos;
    int mayor=maximo (vecNros, 10,vecPos,tamPos);
    





    return 0;

}