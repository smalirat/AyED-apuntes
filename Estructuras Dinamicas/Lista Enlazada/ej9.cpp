#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void mostrar(Nodo *listaC);
void agregar(Nodo *&listaC, int nro);
void insertar(Nodo *&listaC, int nro);

int contador(Nodo *listaC);

int main()
{
    Nodo *lis = NULL;
    int num, cant;
    cin >> num;
    while (num != 0)
    {

        insertar(lis, num);
        cin >> num;
    }
    cout << "Lista: " << endl;
    mostrar(lis);
    cant = contador(lis);
    cout << "Cantidad: " << cant;
    return 0;
}

void mostrar(Nodo *listaC)
{
    if (listaC != NULL)
    {

        Nodo *p = listaC->sig;
        do
        {
            cout << p->dato << endl;
            p = p->sig;
        } while (p != listaC->sig);
    }
}

void insertar(Nodo *&listaC, int nro)
{
    // agrega un nodo a la lista circular ordenada
    Nodo *n = new Nodo;
    n->dato = nro;
    if (listaC == NULL)
    {
        n->sig = n;
        listaC = n;
    }
    else
    {
        Nodo *p = listaC->sig, *ant = listaC;
        if (p->dato < nro)
        {
            do
            {
                ant = p;
                p = p->sig;
            } while (p != listaC->sig && p->dato < nro);
        }
        n->sig = p;
        ant->sig = n;
        if (n->dato > listaC->dato)
            listaC = n;
    }
}

int contador(Nodo *listaC)
{
    int cont = 0;

    if (listaC != NULL)
    {
        Nodo *p = listaC->sig;
        do
        {
            p = p->sig;
            cont++;
        } while (p != listaC->sig);
    }

    return cont;
}
