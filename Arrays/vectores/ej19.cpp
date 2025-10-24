#include <iostream>
using namespace std;

struct Producto {
    double numero;
    int stock;
    float precio, comision;
};

struct Ventas {
    int medico, stock_vendido, numero_vendido;
    float precio, comision;
};

Producto infoProducto() {
    Producto pd;
    cout << "Ingrese numero del producto: ";
    cin >> pd.numero;
    cout << "Ingrese stock: ";
    cin >> pd.stock;
    cout << "Ingrese precio: ";
    cin >> pd.precio;
    cout << "Ingrese comision: ";
    cin >> pd.comision;
    return pd;
}

Ventas infoVentas() {
    Ventas vn;
    cout << "Ingrese numero del medico: ";
    cin >> vn.medico;
    cout << "Ingrese numero del producto vendido: ";
    cin >> vn.numero_vendido;
    cout << "Ingrese cantidad vendida: ";
    cin >> vn.stock_vendido;
    
    return vn;
}

int secuencial(Producto v[], int t, int bus) {
    int i = 0;
    while (i < t && v[i].numero != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}

void mostrarStock(Producto v[], int tam1, int tam2, Ventas v2[]) {
    for (int j = 0; j < tam2; j++) {
        int busqueda = v2[j].numero_vendido;
        int pos = secuencial(v, tam1, busqueda);
        if (pos != -1)
            v[pos].stock -= v2[j].stock_vendido;
    }

    for (int i = 0; i < tam1-1; i++) {
        cout << v[i].numero << "-" << v[i].stock << endl;
    }
}

void mostrarComisiones(Ventas v[], int tam,float vleg[],Producto v2[]) {
    double monto=0,facturacion=0;
    for (int j = 0; j < tam; j++) {
        int pos = v[j].medico;
            vleg[pos]+=((v2[j].comision/100) * v2[j].precio * v[j].stock_vendido);
            monto+=vleg[pos];
            facturacion+=v2[j].precio * v[j].stock_vendido;
    }
    for (int i = 0; i < 10; i++) {
        cout <<"medico "<< i+1 << "-" << vleg[i] << endl;
    }

    cout<<"La empresa gana: "<<facturacion-monto;

    
}

int main() {
    Producto almacen[400];
    Ventas visitas[14];
    float legajo_med[10]={0,0,0,0,0,0,0,0,0,0};
    double comisiones;
    int tam1 = 0, tam2 = 0, k = 0, h = 0;

    do {
        almacen[k] = infoProducto();
        tam1++;
        k++;
    } while (almacen[k - 1].numero != 0);

    do {
        visitas[h] = infoVentas();
        tam2++;
        h++;
    } while (visitas[h - 1].medico != 0);

    mostrarStock(almacen, tam1, tam2, visitas);
    mostrarComisiones(visitas,tam2,legajo_med,almacen);

    return 0;
}