#include <iostream>
#include <stdio.h>

using namespace std;

struct Estudiante
{
    unsigned leg;
    char nom[30];
    int nota;
};

struct Nodo
{
    Estudiante info;
    Nodo *sig;
};

void insertar(Nodo *lista, Estudiante est)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = est;
    p = lista;
    while (p->info.leg < est.leg)
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

int main()
{
    Nodo *lEstudiantes = NULL;
    Estudiante e;
    cout << "Legajo: ";
    cin >> e.leg;
    while (e.leg != 0)
    {
        cout << "Nota";
        cin >> e.nota;
        cout << "Nombre";
        cin >> e.nom;
        insertar(lEstudiantes, e);
    }
    return 0;
}
