#include <iostream>
#include <stdio.h>

using namespace std;

struct Producto
{
    unsigned codigo;
    char descripcion[21];
    float importe;
    int stock;
};

struct Nodo
{
    Producto info;
    Nodo *sig;
};

void listar(Nodo *lista);
void insertar(Nodo *&lista, Producto produc);
void elemento(Nodo *lista);
void importe(Nodo *lista);
int stock(Nodo *lista);

int main()
{
    Nodo *lProducto = NULL;
    Producto p;
    cout << "Codigo ";
    cin >> p.codigo;
    while (p.codigo != 0)
    {
        /* cout << "Descripcion ";
        cin >> p.descripcion; */
        cout << "Importe ";
        cin >> p.importe;
        cout << "Stock ";
        cin >> p.stock;

        insertar(lProducto, p);

        cout << "Codigo ";
        cin >> p.codigo;
    }
    listar(lProducto);

    elemento(lProducto);
    importe(lProducto);
    int st = stock(lProducto);
    cout << st;

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Producto produc)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = produc;
    p = lista;
    while (p != NULL && p->info.codigo < produc.codigo)
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

void elemento(Nodo *lista)
{
    int n, cont = 1;

    cout << "Dar un numero: ";
    cin >> n;

    Nodo *p, *ant;

    p = lista;

    while (p != NULL && cont < n)
    {
        ant = p;
        p = p->sig;
        cont++;
    }

    if (p != NULL)
        cout << p->info.codigo << endl;
    else if (cont == 1)
    {
        cout << "Lista Vacia" << endl;
    }
    else
        cout << "No hay suficientes elementos en la lista" << endl;
}

void importe(Nodo *lista)
{
    int n;

    cout << "Dar un codigo de la lista: ";
    cin >> n;

    Nodo *p = lista;
    while (p != NULL && p->info.codigo < n)
        p = p->sig;
    if (p == NULL || p->info.codigo != n)
        cout << "No se encontro el codigo" << endl;
    else
    {
        p->info.importe += (p->info.importe / 10);
        cout << "Nuevo importe: " << p->info.importe << endl;
    }
}

int stock(Nodo *lista)
{
    int n;

    cout << "Dar un codigo de la lista: ";
    cin >> n;

    Nodo *p = lista;
    while (p != NULL && p->info.codigo < n)
        p = p->sig;
    if (p == NULL || p->info.codigo != n)
        return 0;
    else
        return p->info.stock;
}
