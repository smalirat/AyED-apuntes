#include <iostream>

using namespace std;


int secuencial(int v[], int t, int bus) {
    int i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}

struct Factura {
    int codigo;
    unsigned precio;
    int talle;
};

int main (){
    
    Factura ticket;

    int tam = 3;
    float venta, compra;
    int codigo[tam], talles[tam], precio[tam];
    int cod_ropa,unidades,talle;
    unsigned dni;
    string nombre;
    float precio_final;

    for(int i=0; i<3; i++){
        cout<<"Codigo de prenda: ";
        cin>>codigo[i];
        cout<<"Talle disponible: ";
        cin>>talles[i];
        cout<<"Precio: ";
        cin>>precio[i];
    }
    

    cout<<"Hola cliente, Codigo de prenda: ";
    cin>>cod_ropa;

    while(cod_ropa >= 0){
        cout<<"Cantidad de unidades a comprar: ";
        cin>>unidades;
        cout<<"Talle de prenda: ";
        cin>>talle;

        venta = 0;
        
        int pos = secuencial(codigo, tam, cod_ropa);

        venta = precio[pos]*unidades;

        if (unidades>3){
            precio_final = (venta + (venta*0.21))*0.90;
        }
        else{
            precio_final =(venta + (venta*0.21));
        }
        cout <<"El precio de la compra es: "<<precio_final;

        cout<<"Hola cliente, Codigo de prenda: ";
        cin>>cod_ropa;

    }

    
    return 0;

}