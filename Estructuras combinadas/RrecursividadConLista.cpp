#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

void listar(Nodo *lista)
{
    if (lista != NULL)
    {
        cout << lista->dato << endl;
        listar(lista->sig);
    }
}

void listarDesc(Nodo *lista)
{
    if (lista != NULL)
    {
        listarDesc(lista->sig);
        cout << lista->dato << endl;
    }
}