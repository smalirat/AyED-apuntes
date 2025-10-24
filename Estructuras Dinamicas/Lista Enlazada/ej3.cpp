#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Alumnos
{
    unsigned documento;
    string nombre;
};

struct Nodo
{
    Alumnos info;
    Nodo *sig;
};

void listar(Nodo *lista);
void insertar(Nodo *&lista, Alumnos alumn);
void listaNombre(Nodo *&lista);
void imprimir(Nodo *&lista);

int main()
{
    Nodo *lProducto = NULL;
    Alumnos a;
    cout << "Dni: ";
    cin >> a.documento;
    while (a.documento != 0)
    {
        cout << "Nombre ";
        cin >> a.nombre;

        insertar(lProducto, a);

        cout << "Dni: ";
        cin >> a.documento;
    }
    listar(lProducto);
    listaNombre(lProducto);
    imprimir(lProducto);

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

void insertar(Nodo *&lista, Alumnos alumn)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = alumn;
    p = lista;
    while (p != NULL && p->info.documento < alumn.documento)
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

void listaNombre(Nodo *&lista)
{
    Nodo *listaOrd = NULL;
    Nodo *p;

    while (lista != NULL)
    {
        p = lista;
        lista = lista->sig;

        if (listaOrd == NULL || p->info.nombre < listaOrd->info.nombre)
        {
            p->sig = listaOrd;
            listaOrd = p;
        }
        else
        {
            Nodo *n = listaOrd;
            while (n->sig != NULL && n->sig->info.nombre < p->info.nombre)
            {
                n = n->sig;
            }
            p->sig = n->sig;
            n->sig = p;
        }
    }

    lista = listaOrd;
}

void imprimir(Nodo *&lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.documento << " - " << p->info.nombre << endl;
        p = p->sig;
    }
}
