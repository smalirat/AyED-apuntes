/*
Una biblioteca necesita un programa que efectúe las altas en el archivo maestro de libros. Para ello cuenta con:
a) LIBROS.dat, archivo maestro de libros ordenado por código de libro, con  un registro por cada libro, con el siguiente diseño:
Código de libro (int)  Título del libro (30 caracteres)  Apellido del autor (15 caracteres)  Nacionalidad (int)  Cantidad de ejemplares
b)  NOVEDADES.dat, archivo con los libros a dar de alta  sin ningún orden, con el mismo diseño del archivo maestro.
Se pide realizar la metodología necesaria para que el programa:
1) Genere un nuevo archivo LIBROSACT.dat, con el mismo diseño y orden que el  maestro y con las altas incorporadas.
2) Emitir el siguiente listado, agrupado por nacionalidad y ordenado ascendente por cantidad total de autores:
 Nacionalidad................................... Cantidad Total de autores: 999
 Apellido del Autor……........................... Cantidad total de títulos: 99

1)
2) Lista de naciuonalidades con sublista de autores
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Autores
{
    char apellido[20];
    int cant;
};

struct NodoSub
{
    Autores info;
    NodoSub *sig;
};

struct Libros
{
    int nacionalidad, codigo, cantidad;
    char titulo[20], apell[20];
    NodoSub *listaSub;
};

struct Nodo
{
    Libros info;
    Nodo *sig;
};

void listar(Nodo *lista);
void insertar(Nodo *&lista, Libros l);
Nodo *buscarInsertar(Nodo *&Lista, Libros l);
void inserSub(NodoSub *&lista, Autores a);
void listarNacionalidades(Nodo *lista);
int main()
{
    FILE *archL, *archN;
    Libros l;
    Autores a;
    Nodo *listaLib = NULL, *listaNac = NULL, *p;

    l.codigo = 100;
    l.cantidad = 100;
    l.nacionalidad = 120;
    strcpy(l.apell, "jose");
    strcpy(a.apellido, "jose");
    a.cant = 1;
    insertar(listaLib, l);
    l.listaSub = NULL;
    p = buscarInsertar(listaNac, l);
    inserSub(p->info.listaSub, a);

    l.codigo = 200;
    l.cantidad = 200;
    l.nacionalidad = 120;
    strcpy(l.apell, "jose");
    strcpy(a.apellido, "jose");
    insertar(listaLib, l);
    l.listaSub = NULL;
    p = buscarInsertar(listaNac, l);
    inserSub(p->info.listaSub, a);

    l.codigo = 50;
    l.cantidad = 50;
    l.nacionalidad = 120;
    strcpy(l.apell, "pedro");
    strcpy(a.apellido, "pedro");
    a.cant = 1;
    insertar(listaLib, l);
    l.listaSub = NULL;
    p = buscarInsertar(listaNac, l);
    inserSub(p->info.listaSub, a);

    l.codigo = 200;
    l.cantidad = 200;
    l.nacionalidad = 120;
    strcpy(l.apell, "jose");
    strcpy(a.apellido, "jose");
    insertar(listaLib, l);
    l.listaSub = NULL;
    p = buscarInsertar(listaNac, l);
    inserSub(p->info.listaSub, a);

    l.codigo = 500;
    l.cantidad = 500;
    l.nacionalidad = 140;
    strcpy(l.apell, "pop");
    strcpy(a.apellido, "pop");
    a.cant = 1;
    insertar(listaLib, l);
    l.listaSub = NULL;
    p = buscarInsertar(listaNac, l);
    p->info.listaSub = NULL;
    inserSub(p->info.listaSub, a);

    listar(listaLib);
    listarNacionalidades(listaNac);

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << "Codigo: " << p->info.codigo << endl;
        cout << "Cantidad: " << p->info.cantidad << endl;
        cout << "Nacionalidad: " << p->info.nacionalidad << endl;
        /*El resto de variables*/
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Libros l)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = l;
    p = lista;
    while (p != NULL && p->info.codigo < l.codigo)
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

Nodo *buscarInsertar(Nodo *&lista, Libros l)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.nacionalidad < l.nacionalidad)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && l.nacionalidad == p->info.nacionalidad)
        return p;
    else
    {
        Nodo *n = new Nodo;
        n->info = l;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}
void inserSub(NodoSub *&lista, Autores a)
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = a;
    p = lista;

    while (p != NULL && strcmp(p->info.apellido, a.apellido) < 0)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && strcmp(p->info.apellido, a.apellido) == 0)
        p->info.cant++;
    else
    {
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
    }
}
void listarNacionalidades(Nodo *lista)
{
    cout << "Lista de nacionalidades: " << endl;
    Nodo *p = lista;
    while (p != NULL)
    {
        cout << "Nacionalidad: " << p->info.nacionalidad << endl;
        NodoSub *subp = p->info.listaSub;
        while (subp != NULL)
        {
            cout << "  Apellido: " << subp->info.apellido << endl;
            cout << "  Cantidad de Títulos: " << subp->info.cant << endl;
            subp = subp->sig;
        }
        p = p->sig;
        cout << "----------------------" << endl;
    }
}
