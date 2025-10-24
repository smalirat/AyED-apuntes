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
Nodo *combinarListas(Nodo *lista1, Nodo *lista2);

int main()
{
    Nodo *lProducto = NULL;
    Producto p;
    cout << "Codigo ";
    cin >> p.codigo;
    while (p.codigo != 0)
    {
        /* cout << "Descripcion ";
        cin >> p.descripcion;
        cout << "Importe ";
        cin >> p.importe; */
        cout << "Stock ";
        cin >> p.stock;

        insertar(lProducto, p);

        cout << "Codigo ";
        cin >> p.codigo;
    }
    listar(lProducto);

    Nodo *lProducto2 = NULL;
    cout << "Codigo ";
    cin >> p.codigo;
    while (p.codigo != 0)
    {
        /* cout << "Descripcion ";
        cin >> p.descripcion;
        cout << "Importe ";
        cin >> p.importe; */
        cout << "Stock ";
        cin >> p.stock;

        insertar(lProducto2, p);

        cout << "Codigo ";
        cin >> p.codigo;
    }
    listar(lProducto2);

    Nodo *listaCombinada = combinarListas(lProducto, lProducto2);
    listar(listaCombinada);

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.codigo << " - " << p->info.stock << endl;
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

Nodo *combinarListas(Nodo *lista1, Nodo *lista2)
{
    Nodo *listaCombinada = NULL;
    Nodo *cola = NULL;

    while (lista1 != NULL && lista2 != NULL)
    {
        if (lista1->info.codigo < lista2->info.codigo)
        {
            if (listaCombinada == NULL)
            {
                listaCombinada = lista1;
                cola = lista1;
            }
            else
            {
                cola->sig = lista1;
                cola = lista1;
            }
            lista1 = lista1->sig;
        }
        else
        {
            if (listaCombinada == NULL)
            {
                listaCombinada = lista2;
                cola = lista2;
            }
            else
            {
                cola->sig = lista2;
                cola = lista2;
            }
            lista2 = lista2->sig;
        }
    }

    if (lista1 != NULL)
    {
        if (listaCombinada == NULL)
        {
            listaCombinada = lista1;
        }
        else
        {
            cola->sig = lista1;
        }
    }
    else if (lista2 != NULL)
    {
        if (listaCombinada == NULL)
        {
            listaCombinada = lista2;
        }
        else
        {
            cola->sig = lista2;
        }
    }

    return listaCombinada;
}
