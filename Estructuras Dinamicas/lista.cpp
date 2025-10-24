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

void insertar(Nodo *lista, Estudiante est);
void listarAprobados(Nodo *lista);
float promedio(Nodo *lista);
Nodo *buscarSecuencial(Nodo *lista, unsigned unleg);
Nodo *buscarSecMejorada(Nodo *lista, unsigned unleg);
void modificarNota(Nodo *lista, int unLeg, int nuevaNota);

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

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.leg << " - " << p->info.nom << " - " << p->info.nota << endl;
        p = p->sig;
    }
}

void listarAprobados(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        if (p->info.nota >= 6)
        {
            cout << p->info.leg << " - " << p->info.nom << " - " << p->info.nota << endl;
            p = p->sig;
        }
        else
            p = p->sig;
    }
}

float promedio(Nodo *lista)
{
    Nodo *p;
    float cont = 0, prom = 0;
    p = lista;
    while (p != NULL)
    {
        prom += p->info.nota;
        cont++;
        p = p->sig;
    }

    return (prom / cont);
}

Nodo *buscarSecuencial(Nodo *lista, unsigned unleg)
{
    Nodo *p;
    p = lista;
    while (p != NULL && p->info.leg != unleg)
    {
        p = p->sig;
    }
    return p;
}

Nodo *buscarSecMejorada(Nodo *lista, unsigned unleg)
{
    Nodo *p;
    p = lista;
    while (p != NULL && p->info.leg < unleg)
        p = p->sig;
    if (p == NULL || p->info.leg != unleg)
        return NULL;
    else
        return p;
}

void modificarNota(Nodo *lista, int unLeg, int nuevaNota)
{
    Nodo *p;
    p = buscarSecMejorada(p, unLeg);
    if (p != NULL)
        p->info.nota = nuevaNota;
}

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
