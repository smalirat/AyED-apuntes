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
void nuevasListas(Nodo *&lista, Nodo *&lmayor, Nodo *&lmenor);

int main()
{
    Nodo *lProducto = NULL, *l1 = NULL, *l2 = NULL;
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

    nuevasListas(lProducto, l1, l2);

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.codigo << " " << p->info.stock << endl;
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

void nuevasListas(Nodo *&lista, Nodo *&lmayor, Nodo *&lmenor)
{
    Nodo *p;
    Producto produc;
    p = lista;
    p->info = lista->info;

    while (p != NULL)
    {
        if (p->info.stock >= 50)
        {
            insertar(lmayor, p->info);
            p = p->sig;
        }
        else
        {
            insertar(lmenor, p->info);
            p = p->sig;
        }
    }

    cout << "+50: " << endl;
    listar(lmayor);
    cout << "-50: " << endl;
    listar(lmenor);
}
