#include <iostream>

using namespace std;

struct Venta {
    int factura[25],codigo[25],importe[25];
    
};

void inicializar(int v[],int t)
{
    for(int i=0;i<t;i++)
        v[i]=0;
}



int main(){
    Venta datos;
    int vendedor[25],cant_ventas[25];
    int i=0,tam=0,ventas;
    inicializar(vendedor,25);
    inicializar(cant_ventas,25);

        cout<<"factura: ";
        cin>>datos.factura[i];
while(datos.factura[i] !=0){
        cout<<"Codigo: ";
        cin>>datos.codigo[i];
        cout<<"Importe: ";
        cin>>datos.importe[i];

        int posi=datos.codigo[i];
        vendedor[posi-1]+=datos.importe[i];
        cant_ventas[posi-1]++;
        i++;
        tam++;
        cout<<"factura: ";
        cin>>datos.factura[i];
}

for(int j=0;j<25;j++){
        cout<<vendedor[j]<<endl;
}

cout<<"vendedor: ";
cin>>ventas;
cout<<cant_ventas[ventas-1];
 return 0;   


}