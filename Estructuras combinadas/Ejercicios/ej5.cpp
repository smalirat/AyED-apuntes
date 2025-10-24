/*
Una compañía que ofrece préstamos a sus clientes a pagar en 12 meses, desea obtener un listado con los códigos de clientes
y los números de las cuotas adeudadas de aquellos clientes que adeuden cuotas, ordenado por código de  - 2 - cliente.
Para ello cuenta con un archivo de cobranzas, sin ningún orden, con el siguiente diseño:
Código de cliente (int)  Número de cuota (1 a 12)
Lista con un vector (SOY UNA BESTIAAAAA)
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Clientes
{
    unsigned codigo;
    int cuota[12];
};

struct Nodo
{
    Clientes info;
    Nodo *sig;
};

void listar(Nodo *lista);
void insertar(Nodo *&lista, Clientes c);

int main()
{
    Nodo *lista = NULL;
    Clientes c;
    int pos;

    cout << "Codigo ";
    cin >> c.codigo;
    while (c.codigo != 0)
    {
        for (int i = 0; i < 12; i++)
        {
            c.cuota[i] = 0;
        }

        cout << "Mes ";
        cin >> pos;
        while (pos > 0 && pos <= 12)
        {
            c.cuota[pos - 1] = 1;
            cout << "Mes ";
            cin >> pos;
        }

        insertar(lista, c);

        cout << "Codigo ";
        cin >> c.codigo;
    }
    listar(lista);

    return 0;
}

void listar(Nodo *lista)
{
    Nodo *p;
    p = lista;
    while (p != NULL)
    {
        cout << "Código: " << p->info.codigo << endl;
        cout << "Adeuda los meses: ";
        for (int k = 0; k < 12; k++)
        {
            if (p->info.cuota[k] == 1)
                cout << k + 1 << " ";
        }
        cout << endl; // Add a line break for clarity
        p = p->sig;
    }
}

void insertar(Nodo *&lista, Clientes c)
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
