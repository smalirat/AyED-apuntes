/*
Dado el archivo VENTAS.DAT, ordenado por número de factura,  con la siguiente estructura de registro:
Número de factura (int)  Código de vendedor (int)  Importe (float)
a) Imprima un listado ordenado por código de vendedor, con código de vendedor y el detalle de cada venta, ordenadas de mayor a menor por importe.
b) Genere el archivo “VentasVendedor.dat” ordenado por código de vendedor, con código de vendedor y el importe total de ventas.

Recorrer el archivo una vez, y a medida que lo recorro voy armando una lista de vendedores con sublista de ventas
*/

#include <iostream>
#include <stdio.h>

using namespace std;
struct Ventas
{
    int numFactura;
    float importeVentas;
};
struct NodoSub
{
    Ventas info;
    NodoSub *sig;
};
struct Vendedores
{
    int codigo_vendedor;
    NodoSub *listaVentas;
};

struct Archivo
{
    int factura, codigo;
    float importe;
};
struct Nodo
{
    Vendedores info;
    Nodo *sig;
};

void insertar(NodoSub *&lista, Ventas v);
Nodo *buscarInsertar(Nodo *&Lista, Vendedores vend);
void generar(Nodo *&lista);
void mostrarLista(Nodo *lista);

int main()
{
    Nodo *listaObra = NULL;
    generar(listaObra);
    cout << "Lista de vendedores y ventas:" << endl;
    mostrarLista(listaObra);

    return 0;
}

void generar(Nodo *&lista)
{
    Ventas v;
    Vendedores vend;
    Archivo a;
    Nodo *p;
    FILE *arch;
    arch = fopen("VENTAS.dat", "rb");
    if (arch == NULL)
        cout << "Error al abrir el archivo";
    else
    {
        fread(&a, sizeof(Archivo), 1, arch);
        while (!feof(arch))
        {
            vend.codigo_vendedor = a.codigo;
            v.numFactura = a.factura;
            v.importeVentas = a.importe;
            vend.listaVentas = NULL;
            p = buscarInsertar(lista, vend);
            insertar(p->info.listaVentas, v);
            fread(&a, sizeof(Archivo), 1, arch);
        }
        fclose(arch);
    }
}

void insertar(NodoSub *&lista, Ventas v) // ordenado por importe
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = v;
    p = lista;
    while (p != NULL && p->info.importeVentas >= v.importeVentas)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
        ant->sig = n;
    else
        lista = n;
}

Nodo *buscarInsertar(Nodo *&lista, Vendedores vend)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.codigo_vendedor < vend.codigo_vendedor)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && vend.codigo_vendedor == p->info.codigo_vendedor)
        return p;
    else
    {
        Nodo *n = new Nodo;
        n->info = vend;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}

void mostrarLista(Nodo *lista)
{
    Nodo *p = lista;
    while (p != NULL)
    {
        cout << "Código de vendedor: " << p->info.codigo_vendedor << endl;

        NodoSub *subp = p->info.listaVentas;
        while (subp != NULL)
        {
            cout << "  Importe: " << subp->info.importeVentas << " - Num Factura: " << subp->info.numFactura << endl;
            subp = subp->sig;
        }

        p = p->sig;
    }
}