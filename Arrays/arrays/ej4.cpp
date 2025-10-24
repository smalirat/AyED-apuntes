#include <iostream>

using namespace std;

void inicializar(int v[],int t)
{
    for(int i=0;i<t;i++)
        v[i]=0;
}

void mostrarVector(int v[],int t)
{
    for(int i=0;i<t;i++)
        cout<<v[i]<<endl;
}

void cargarPorFila(int m[][9],int cf,int cc,int Vf[],int Vc[])
{
    for(int j=0;j<cf;j++)
    {
        Vf[j]=j+1;
        for(int i=0;i<cc/2;i++)
        {
            m[j][i]=8-(2*i);
            Vc[i]=m[j][i]=8-(2*i);
        }
        for(int h=cc/2;h<cc;h++)
        {
            m[j][h]=1+(2*(h-4));
            Vc[h]=1+(2*(h-4));
            
        }

    }

}

void cargarBooleanos(int m[][9],int cf,int cc)
{
   
    for(int j=0;j<cf;j++)
    {
        for(int i=0;i<cc;i++)
        {
            m[j][i]=0;
        }
        

}
}

int sumaButacas(int m[][9],int cf,int cc,int v1[]){
    int suma=0;
    for(int j=0;j<cf;j++)
    {
        for(int i=0;i<cc;i++)
        {
            v1[j]+=m[j][i];
            suma+=m[j][i];
        }

    }
    return suma;
}

void mostrarBooleanos(int m[][9],int cf, int cc){
    for(int i=0;i<cf;i++){
        for(int j=0;j<cc;j++){
                if(m[i][j]==0){
                cout<<"D"<<"  ";
                }
                else{
                    cout<<"R"<<"  ";
                }

        }
    cout<<endl;
    }
}

int secuencial(int v[], int t, int bus){
    int i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}

void puntosFilas(int m[][9],int cf,int cc, int v1[]){
    int max=0;
    for(int i=0;i<cf;i++){
        if(v1[i]==0){
            cout<<"La fila "<<i+1<<" esta vacia"<<endl;
            
        }
    }
    for(int i=0;i<cf;i++){
        if(v1[i]>v1[max]){
            max=i;
        }
    }
    cout<<"La fila con mas espectadores es: "<<max+1;

}

int main(){
    int butacas[12][9],Fila[12],Col[9];
    int disponibles[12][9];
    int fila,columna,posFila,posCol,total=0;
    inicializar(Fila,12);
    //inicializar(Col,9);
    cargarPorFila(butacas,12,9,Fila,Col);
    cargarBooleanos(disponibles,12,9);
    mostrarBooleanos(disponibles,12,9);

    cout<<"Ingrese la fila: ";
    cin>>fila;

    while(fila>0 && fila<=12){
        cout<<"Ingrese el numero de butaca: ";
        cin>>columna;

    posFila=secuencial(Fila, 12, fila);
    posCol=secuencial(Col, 9, columna);

    if (posFila != -1 && posCol != -1) // Verifica que la fila y la columna sean válidas
        {
            if (disponibles[posFila][posCol] == 0){
                disponibles[posFila][posCol] = 1;
                mostrarBooleanos(disponibles, 12, 9);
            }
            else{
                cout << "La butaca ya está ocupada." << endl;
            }
        }
        else
        {
            cout << "La fila o la columna ingresada no es válida." << endl;
        }
    

    mostrarBooleanos(disponibles,12,9);

        cout<<endl<<"Ingrese la fila: ";
        cin>>fila;
    }

    inicializar(Fila,12);
    total = sumaButacas(disponibles,12,9,Fila);
    cout<<"Butacas vendidas: "<<total<<endl;
    puntosFilas(disponibles,12,9,Fila);

    return 0;
}