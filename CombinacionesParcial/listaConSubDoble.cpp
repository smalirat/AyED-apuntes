#include <iostream>
#include <stdio.h>

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
    NodoSub *listaMateriales1;
    NodoSub *listaMateriales2;
};
struct Nodo
{
    Obra info;
    Nodo *sig;
};

Nodo *buscarInsertar(Nodo *&Lista, Obra ob);
void generar(Nodo *&lista);
void mostrarLista(Nodo *lista);
void mostrarAsc(NodoSub *l);
void mostrarDesc(NodoSub *l);
void insertarDoble(NodoSub *&lis1, NodoSub *&lis2, Materiales mat);

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
        ob.listaMateriales1 = NULL;
        ob.listaMateriales2 = NULL;
        p = buscarInsertar(lista, ob);
        mat.fecha = fechaMat;
        mat.importe = importeMat;
        insertarDoble(p->info.listaMateriales1, p->info.listaMateriales2, mat);

        cout << "Codigo de obra: ";
        cin >> codOb;
    }
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
        mostrarAsc(p->info.listaMateriales1);
        p = p->sig;
    }
}

void insertarDoble(NodoSub *&lis1, NodoSub *&lis2, Materiales mat)
{
    NodoSub *p, *r;
    p = new NodoSub;
    p->info = mat;
    if (lis1 == NULL && lis2 == NULL) // p no va a tener ni sucesor ni antecesor (agrega a lista vac�a)
    {
        p->sig = p->ant = NULL;
        lis1 = lis2 = p;
    }
    else
    {
        r = lis1;
        while (r != NULL && r->info.fecha < mat.fecha)
            r = r->sig;

        if (r == lis1) // p va a tener sucesor y no antecesor
        {
            p->ant = NULL;
            p->sig = r;
            r->ant = p;
            lis1 = p;
        }
        else
        {
            if (r == NULL) // p va a tener antecesor y no sucesor
            {
                p->ant = lis2;
                p->sig = r;
                lis2->sig = p;
                lis2 = p;
            }
            else
            { // p va a tener sucesor y antecesor
                p->ant = r->ant;
                p->sig = r;
                /*
                Nodo*anterior=r->ant;
                anterior->sig=p;
                */
                r->ant->sig = p;
                r->ant = p;
            }
        }
    }
}

void mostrarAsc(NodoSub *l)
{
    NodoSub *p = l;
    while (p != NULL)
    {
        cout << p->info.fecha << endl;
        cout << p->info.importe << endl;
        p = p->sig;
    }
}

void mostrarDesc(NodoSub *l)
{
    NodoSub *p = l;
    while (p != NULL)
    {
        cout << p->info.fecha << endl;
        cout << p->info.importe << endl;
        p = p->ant;
    }
}