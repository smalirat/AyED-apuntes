#include <iostream>

using namespace std;

struct Libro
{
    string titulo;
    string materia;
};

struct NodoPila
{
    Libro datos;
    NodoPila *sig;
};

void apilar(NodoPila *&pila, Libro libro);
void desapilar(NodoPila *&pila, Libro &libro);

int main()
{
    NodoPila *pilaLibros = NULL;
    Libro libro;
    cout << "titulo: ";
    cin >> libro.titulo;
    while (libro.titulo != "fin")
    {
        cout << "materia: ";
        cin >> libro.materia;
        apilar(pilaLibros, libro);
        cout << "titulo: ";
        cin >> libro.titulo;
    }
    while (pilaLibros != NULL)
    {
        desapilar(pilaLibros, libro);
        cout << libro.titulo << " - " << libro.materia << endl;
    }
    return 0;
}

void apilar(NodoPila *&pila, Libro libro)
{
    NodoPila *p;
    p = new NodoPila;
    p->datos = libro;
    p->sig = pila;
    pila = p;
}

void desapilar(NodoPila *&pila, Libro &libro)
{
    NodoPila *p = pila;
    libro = p->datos;
    pila = p->sig;
    delete p;
}