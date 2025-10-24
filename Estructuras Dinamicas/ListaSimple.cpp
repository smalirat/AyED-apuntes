#include <iostream>
#include <stdio.h>

using namespace std;

struct Estudiante
{
    unsigned leg;
    char nom[21];
    unsigned nota;
};

struct Nodo
{
    Estudiante info;
    Nodo *sig;
};

void listar(Nodo *lista);
void insertar(Nodo *&lista, Estudiante est);

int main()
{
    Nodo *lEstudiantes = NULL;
    Estudiante e;
    cout << "Legajo ";
    cin >> e.leg;
    while (e.leg != 0)
    {
        /*cout << "nombre ";
        cin >> e.nom;
        cout << "nota ";
        cin >> e.nota;*/

        insertar(lEstudiantes, e);

        cout << "Legajo ";
        cin >> e.leg;
    }
    listar(lEstudiantes);

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.leg << /*<< p->info.nom << p->info.nota <<*/ endl;
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
            cout << p->info.leg << p->info.nom << p->info.nota << endl;
        p = p->sig;
    }
}

float promedio(Nodo *lista)
{
    Nodo *p = lista;
    int s = 0, c = 0;
    while (p != NULL)
    {
        s += p->info.nota;
        c++;
        p = p->sig;
    }
    if (c == 0)
        return 0;
    else
        return (float)s / c;
}

Nodo *buscarSecuencial(Nodo *lista, unsigned unLeg)
{
    // devuelve el puntero al nodo con leg unLeg y NULL
    // si no hay un nodo con el unLeg
    Nodo *p = lista;
    while (p != NULL && p->info.leg != unLeg)
        p = p->sig;
    return p;
}

Nodo *buscarSecMejorada(Nodo *lista, unsigned unLeg)
{
    // solo para buscar por lo que est� ordenado
    Nodo *p = lista;
    while (p != NULL && p->info.leg < unLeg)
        p = p->sig;
    if (p == NULL || p->info.leg != unLeg)
        return NULL;
    else
        return p;
}

void modificarNota(Nodo *lista, int unLeg, int nuevaNota)
{
    Nodo *p;
    p = buscarSecMejorada(lista, unLeg);
    if (p != NULL)
        p->info.nota = nuevaNota;
}

void insertar(Nodo *&lista, Estudiante est)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = est;
    p = lista;
    while (p != NULL && p->info.leg < est.leg)
    {
        ant = p;
        p = p->sig;
    }
    n->sig = p;
    if (p != lista){
        ant->sig = n;
    }
    else
        lista = n;
}

Nodo *buscarInsertar(Nodo *&lista, Estudiante e)
{
    Nodo *p = lista, *ant;
    while (p != NULL && p->info.leg < e.leg)
    {
        ant = p;
        p = p->sig;
    }

    if (p == NULL || p->info.leg != e.leg)
    {
        Nodo *n = new Nodo;
        n->info = e;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
    else
        return p;
}

void eliminar(Nodo *&lista, int unLeg)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.leg < unLeg)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && p->info.leg == unLeg)
    {
        if (p != lista)
            ant->sig = p->sig;
        else
            lista = p->sig;

        delete p;
    }
}

void insertarNota(Nodo *&lista, Estudiante est)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = est;
    p = lista;
    while (p != NULL && p->info.nota < est.nota)
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
void insertarNotaSinMem(Nodo *&lista, Nodo *n)
{
    Nodo *p, *ant;
    p = lista;
    while (p != NULL && p->info.nota < n->info.nota)
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

void ordenar1(Nodo *lista, Nodo *&listaOrd)
{
    // de menor a mayor por nota
    // dos listas, la original y la ordenada
    listaOrd = NULL;
    Nodo *p = lista;
    while (p != NULL)
    {
        insertarNota(listaOrd, p->info);
        p = p->sig;
    }
}
void ordenar2(Nodo *&lista, Nodo *&listaOrd)
{
    // de menor a mayor por nota
    // dos listas, la original que queda vacia
    // y la ordenada
    listaOrd = NULL;
    Nodo *p;
    while (lista != NULL)
    {
        p = lista;
        lista = lista->sig;
        insertarNota(listaOrd, p->info);
        delete p;
    }
}
void ordenar3(Nodo *&lista)
{
    // de menor a mayor por nota
    // solo una lista
    Nodo *listaOrd = NULL;
    Nodo *p;
    while (lista != NULL)
    {
        p = lista;
        lista = lista->sig;
        insertarNota(listaOrd, p->info);
        delete p;
    }
    lista = listaOrd;
}
void ordenar4(Nodo *&lista)
{
    // de menor a mayor por nota
    // solo una lista
    Nodo *listaOrd = NULL;
    Nodo *p;
    while (lista != NULL)
    {
        p = lista;
        lista = lista->sig;
        insertarNotaSinMem(listaOrd, p);
    }
    lista = listaOrd;
}
