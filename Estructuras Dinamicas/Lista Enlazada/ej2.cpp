#include <iostream>
#include <stdio.h>

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
void insertarNuevo(Nodo *&lista);
void baja(Nodo *&lista);
void imprimir(Nodo *&lista);
void imprimirInverso(Nodo *&lista);

int main()
{
    Nodo *lProducto = NULL;
    Alumnos a;
    cout << "Dni: ";
    cin >> a.documento;
    while (a.documento != 0)
    {
        /* cout << "Nombre ";
        cin >> a.nombre; */

        insertar(lProducto, a);

        cout << "Dni: ";
        cin >> a.documento;
    }
    listar(lProducto);
    insertarNuevo(lProducto);
    baja(lProducto);
    imprimir(lProducto);
    imprimirInverso(lProducto);

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

void insertarNuevo(Nodo *&lista)
{
    Alumnos al;

    cout << "Dni del nuevo alumno: ";
    cin >> al.documento;
    /* cout << "Nombre del nuevo alumno: ";
        cin >> a.nombre; */

    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = al;
    p = lista;
    while (p != NULL && p->info.documento < al.documento)
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
void baja(Nodo *&lista)
{
    Alumnos al;

    cout << "Dni del alumno a dar de baja: ";
    cin >> al.documento;
    /* cout << "Nombre del alumno a dar de baja: ";
        cin >> a.nombre; */

    {
        Nodo *ant, *p = lista;
        while (p != NULL && p->info.documento < al.documento)
        {
            ant = p;
            p = p->sig;
        }
        if (p != NULL && p->info.documento == al.documento)
        {
            if (p != lista)
                ant->sig = p->sig;
            else
                lista = p->sig;

            delete p;
        }
    }
}

void imprimir(Nodo *&lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.documento << /*p->info.nombre<<*/ endl;
        p = p->sig;
    }
}

void imprimirInverso(Nodo *&lista)
{
    Nodo *p;
    p = lista;
    Alumnos v1[100];
    int i = 0;

    while (p != NULL)
    {
        v1[i].documento = p->info.documento;
        // v1[i].nombre = p->info.nombre;
        p = p->sig;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << v1[j].documento << " -- " /*<<v1[j].nombre*/ << endl;
    }
}