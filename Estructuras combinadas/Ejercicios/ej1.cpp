#include <iostream>
#include <stdio.h>

/*En una empresa de construcción se quiere almacenar en un archivo los importes y fechas de los materiales comprados
para cada una de las obras que está construcción. Para ello se ingresa por teclado,
por cada compra de materiales realizada: el código de la obra, la fecha y el importe de la compra.
Los datos son ingresados sin orden. Para cada obra se puede haber comprado materiales varias veces.
Se pide generar un archivo secuencial con código de obra, fecha e importe, ordenado por código de obra y por fecha,
con los datos ingresados por teclado. */

using namespace std;
struct Materiales
{
    unsigned importe;
    unsigned fecha;
};
struct NodoSub
{
    Materiales info;
    NodoSub *sig;
    NodoSub *ant;
};
struct Obra
{
    unsigned codigo;
    NodoSub *listaMateriales;
};
struct Nodo
{
    Obra info;
    Nodo *sig;
};

void insertar(NodoSub *&lista, Materiales mat);
Nodo *buscarInsertar(Nodo *&Lista, Obra ob);
void generar(Nodo *&lista);
void mostrarLista(Nodo *lista);

int main()
{
    Nodo *listaObra = NULL;
    generar(listaObra);
    cout << "Lista de Obras y Materiales:" << endl;
    mostrarLista(listaObra);

    return 0;
}

void generar(Nodo *&lista)
{
    Obra ob;
    Materiales mat;
    Nodo *p;
    unsigned codOb, importeMat, fechaMat;
    cout << "Codigo de obra: ";
    cin >> codOb;
    while (codOb != 0) // ingresa datos del examen
    {
        cout << "Fecha compra: ";
        cin >> fechaMat;
        cout << "Importe: ";
        cin >> importeMat;

        ob.codigo = codOb;
        ob.listaMateriales->sig = NULL;
        ob.listaMateriales->ant = NULL;
        p = buscarInsertar(lista, ob);
        mat.fecha = fechaMat;
        mat.importe = importeMat;
        insertarDoble(p->info.listaMateriales, mat);

        cout << "Codigo de obra: ";
        cin >> codOb;
    }
}

void insertar(NodoSub *&lista, Materiales mat) // ordenado por fecha
{
    NodoSub *n, *p, *ant;
    n = new NodoSub;
    n->info = mat;
    p = lista;
    while (p != NULL && p->info.fecha < mat.fecha)
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

Nodo *buscarInsertar(Nodo *&lista, Obra ob)
{
    Nodo *ant, *p = lista;
    while (p != NULL && p->info.codigo < ob.codigo)
    {
        ant = p;
        p = p->sig;
    }
    if (p != NULL && ob.codigo == p->info.codigo)
        return p;
    else
    {
        Nodo *n = new Nodo;
        n->info = ob;
        n->sig = p;
        if (p != lista)
            ant->sig = n;
        else
            lista = n;
        return n;
    }
}

void mostrarLista(Nodo *lista)
{
    Nodo *p = lista;
    while (p != NULL)
    {
        cout << "Código de obra: " << p->info.codigo << endl;

        NodoSub *subp = p->info.listaMateriales;
        while (subp != NULL)
        {
            cout << "  Fecha: " << subp->info.fecha << " - Importe: " << subp->info.importe << endl;
            subp = subp->sig;
        }

        p = p->sig;
    }
}