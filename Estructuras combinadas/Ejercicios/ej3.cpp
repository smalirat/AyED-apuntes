
#include <iostream>
#include <stdio.h>

using namespace std;
struct Ventas
{
    int numFactura;
    float importeVentas;
};

struct Archivo
{
    int factura, codigo;
    float importe;
};
struct Nodo
{
    Ventas info;
    Nodo *sig;
};
void inicializar(Nodo *vectorDeListas[]);
void insertar(Nodo *&listaDeEnteros, Ventas vent);
void mostrarVectorDeListas(Nodo *vectorDeListas[]);

int main()
{
    Nodo *vectorDeListas[11];
    Ventas v;
    Archivo a;
    FILE *arch;
    int pos;

    inicializar(vectorDeListas);

    arch = fopen("VENTAS.dat", "rb");

    if (arch == NULL)
        cout << "Error al abrir el archivo";
    else
    {

        fread(&a, sizeof(Archivo), 1, arch);
        while (!feof(arch))
        {
            pos = a.codigo;
            v.numFactura = a.factura;
            v.importeVentas = a.importe;
            insertar(vectorDeListas[pos], v);
            fread(&a, sizeof(Archivo), 1, arch);
        }
        fclose(arch);
    }

    // insertarPrimero(vectorDeListas[0], 3);
    mostrarVectorDeListas(vectorDeListas);

    return 0;
}

void inicializar(Nodo *vectorDeListas[])
{
    for (int i = 1; i < 11; i++)
        vectorDeListas[i] = NULL;
}

void insertar(Nodo *&listaDeEnteros, Ventas vent)
{
    Nodo *n = new Nodo;
    n->info = vent;
    n->sig = listaDeEnteros;
    listaDeEnteros = n;
}

void mostrarVectorDeListas(Nodo *vectorDeListas[])
{
    FILE *arch2;
    Ventas v;
    arch2 = fopen("VentasVendedor.dat", "wb");
    if (arch2 == NULL)
        cout << "Error al abrir el archivo";
    else
    {
        Nodo *p;

        for (int i = 1; i < 11; i++)
        {
            p = vectorDeListas[i];
            if (p != NULL)
                cout << "Lista " << i << endl;
            while (p != NULL)
            {

                cout << "Elemento de la lista: " << p->info.numFactura << "  " << p->info.importeVentas << endl;

                v.numFactura = p->info.numFactura;
                v.importeVentas = p->info.importeVentas;
                fwrite(&v, sizeof(Ventas), 1, arch2);

                p = p->sig;
                cout << "-------------------------------------" << endl;
            }
        }
        fclose(arch2);
    }
}
