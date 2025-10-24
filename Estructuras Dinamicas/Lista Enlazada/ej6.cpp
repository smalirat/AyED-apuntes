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
void cambiarLista(Nodo *&lista);

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

    cambiarLista(lProducto);

    cout << "Nueva lista: " << endl;

    listar(lProducto);

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

void cambiarLista(Nodo *&lista)
{
    Nodo *ant, *p;
    ant = lista;
    p = lista->sig;

    /*cout << p->info.codigo;
    cout << ant->info.codigo;
    cout << "p sig: " << p->sig->info.codigo; */

    while (p != NULL)
    {
        if (ant->info.codigo == p->info.codigo)
        {
            ant->info.stock += p->info.stock;
            Nodo *temp = p;
            ant->sig = p->sig;
            p = p->sig;
            delete temp;
        }
        else
        {
            ant = p;
            p = p->sig;
        }
    }
}
