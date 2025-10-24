#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Inscriptos
{
    unsigned dni, cod;
    float ingreso;
    char nombre[20], apellido[20];
};
struct NodoSub
{
    Inscriptos info;
    NodoSub *sig;
};

struct Archivo
{
    unsigned codigo;
    int cantidad;
    char descripcion[30];
};

struct Creditos
{
    unsigned codigo;
    int cantidad;
    char descripcion[30];
    NodoSub *listaIns;
};
struct Nodo
{
    Creditos info;
    Nodo *sig;
};

void insertar(Nodo *&lista, Creditos c);
void buscarSub(Nodo *lista, NodoSub *&sublista, Inscriptos i);
void insertarSub(NodoSub *&sublista, Inscriptos i);
void listar(Nodo *lista);
int main()
{
    /*FILE *ac, *ai;
    ac = fopen("Creditos.dat", "rb");
    ai = fopen("Inscriptos.dat", "rb");
    if (ac == NULL || ai == NULL)
        cout << "Error al abrir el archivo";
    else
    {
        Inscriptos i;
        Creditos c;
        Archivo a;
        Nodo *listac = NULL;
        NodoSub *sublistai = NULL;
        fread(&c, sizeof(Creditos), 1, ac);
        cout << c.codigo;
        cout << c.cantidad;
        while (!feof(ac))
        {
            c.listaIns = NULL;
            insertar(listac, c);
            fread(&c, sizeof(Creditos), 1, ac);
        }
        fclose(ac);

        listar(listac);

        fread(&i, sizeof(Inscriptos), 1, ai);
        while (!feof(ai))
        {
            insertarSub(listac, sublistai, i);
            fread(&i, sizeof(Inscriptos), 1, ai);
        }
        fclose(ai);
    }*/
    Inscriptos i;
    Creditos c;
    Nodo *listac = NULL;
    NodoSub *sublistai = NULL;

    c.codigo = 200;
    c.cantidad = 1;
    c.listaIns = NULL;
    insertar(listac, c);

    c.codigo = 100;
    c.cantidad = 2;
    c.listaIns = NULL;
    insertar(listac, c);

    listar(listac);

    i.cod = 100;
    i.ingreso = 2000;
    buscarSub(listac, sublistai, i);
    i.cod = 100;
    i.ingreso = 4000;
    buscarSub(listac, sublistai, i);
    i.cod = 200;
    i.ingreso = 2000;
    buscarSub(listac, sublistai, i);

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << p->info.codigo << endl;
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Creditos c)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = c;
    p = lista;
    while (p != NULL && p->info.codigo < c.codigo)
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

void buscarSub(Nodo *lista, NodoSub *&sublista, Inscriptos i)
{
    Nodo *p = lista;
    while (p != NULL && p->info.codigo < i.cod)
    {
        p = p->sig;
    }
    if (p == NULL || p->info.codigo != i.cod)
        cout << "No se encontro el codigo" << endl;
    else
    {
        if (p->info.cantidad > 0)
        {
            insertarSub(p->info.listaIns, i);
            p->info.cantidad--;
        }
    }
}

void mostrarLista(Nodo *lista)
{
    Nodo *p = lista;
    while (p != NULL)
    {
        cout << "Código: " << p->info.codigo << endl;
        // cout << "Descripcion: " << p->info.descripcion << endl;

        NodoSub *subp = p->info.listaIns;
        while (subp != NULL)
        {
            cout << subp->info.cod << endl;
            // cout << subp->info.dni << endl;
            cout << subp->info.ingreso << endl;
            // cout << subp->info.nombre << endl;
            // cout << subp->info.apellido << endl;
            subp = subp->sig;
        }

        p = p->sig;
    }
}

void insertarSub(NodoSub *&lista, Inscriptos i)
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = i;
    p = lista;
    if (p != NULL)
        cout << "p info: " << p->info.ingreso << endl;
    cout << "ingreso de i: " << i.ingreso << endl;
    while (p != NULL && p->info.ingreso < i.ingreso)
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
