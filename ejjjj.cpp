#include <iostream>
using namespace std;
struct ventas
{
    int fact;
    int codigo;
    float imp;
};
struct nodo
{
    ventas v;
    nodo *sig;
};
void desarchivar(nodo *&lista);
void enlistar(nodo *&lista, ventas vent);
void generar(FILE *&arch);
void listar(nodo *&lista);
int main()
{
    nodo *lista = NULL;
    ventas vent;
    FILE *arch;
    int d;
    cout << "Desea generar un archivo(1 si 0 no)" << endl;
    cin >> d;
    if (d == 1)
    {
        generar(arch);
    }
    desarchivar(lista);
    listar(lista);
    return 0;
}
void desarchivar(nodo *&lista)
{
    FILE *arch = fopen("ventas.dat", "rb");
    if (arch == NULL)
    {
        cout << "El archivo esta vacio" << endl;
        return;
    }
    ventas v;
    while (fread(&v, sizeof(ventas), 1, arch) == 1)
    {
        enlistar(lista, v);
    }
    fclose(arch);
}
void enlistar(nodo *&lista, ventas vent)
{
    nodo *p, *n, *ant;
    n = new nodo;
    n->v = vent;
    p = lista;
    while (p != NULL && p->v.codigo < vent.codigo)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista)
    {
        ant->sig = p;
    }
    else
    {
        lista = n;
    }
}
void generar(FILE *&arch)
{
    ventas v;
    arch = fopen("ventas.dat", "wb");
    if (arch == NULL)
    {
        return;
    }
    cout << "Ingrese el numero de factura (0 para terminar)" << endl;
    cin >> v.fact;
    while (v.fact != 0)
    {
        cout << "Ingrese el codigo de venta" << endl;
        cin >> v.codigo;
        cout << "Ingrese el importe" << endl;
        cin >> v.imp;
        fwrite(&v, sizeof(ventas), 1, arch);
        cout << "Ingrese el numero de factura (0 para terminar)" << endl;
        cin >> v.fact;
    }
    fclose(arch);
}
void listar(nodo *&lista)
{
    nodo *p;
    p = lista;
    if (p == NULL)
    {
        cout << "No se ha ingresado ninguna venta" << endl;
        return;
    }
    while (p != NULL)
    {
        cout << "Numero de factura: " << p->v.fact << endl;
        cout << "Codigo de venta: " << p->v.codigo << endl;
        cout << "Importe: " << p->v.imp << endl;
        p = p->sig;
    }
}