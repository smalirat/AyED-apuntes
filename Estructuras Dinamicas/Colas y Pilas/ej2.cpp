#include <iostream>

using namespace std;

struct Libro
{
    string titulo;
};

struct NodoPila
{
    Libro datos;
    NodoPila *sig;
};

void apilar(NodoPila *&pila, Libro libro);
void desapilar(NodoPila *&pila, Libro &libro);
void imprimirPila(NodoPila *pila);
void apilarnuevo(NodoPila *&pila, Libro libro, Libro libro2);

int main()
{
    NodoPila *pilaLibros = NULL;
    Libro libro, libroaux;
    cout << "Ingresa el título del libro (escribe 'fin' para terminar): ";
    cin >> libro.titulo;
    while (libro.titulo != "fin")
    {
        apilar(pilaLibros, libro);
        cout << "Ingresa el título del libro (escribe 'fin' para terminar): ";
        cin >> libro.titulo;
    }

    cout << "Pila después de cargar libros:" << endl;
    imprimirPila(pilaLibros);

    cout << "Ingresa el nuevo título para agregar en la primera posición: ";
    cin >> libroaux.titulo;

    apilarnuevo(pilaLibros, libro, libroaux);

    cout << "Pila después de agregar un nuevo libro en la tercera posición:" << endl;
    imprimirPila(pilaLibros);

    return 0;
}

void apilar(NodoPila *&pila, Libro libro)
{
    NodoPila *p = new NodoPila; // Crear un nuevo nodo de la pila
    p->datos = libro;           // Asignar los datos del libro al nuevo nodo
    p->sig = pila;              // Establecer el siguiente nodo como el actual tope de la pila
    pila = p;                   // Actualizar el tope de la pila al nuevo nodo
}

void imprimirPila(NodoPila *pila)
{
    NodoPila *temp = pila;
    while (temp != NULL)
    {
        cout << temp->datos.titulo << endl;
        temp = temp->sig;
    }
}

void desapilar(NodoPila *&pila, Libro &libro)
{
    if (pila != NULL)
    {
        NodoPila *p = pila;
        libro = p->datos;
        pila = p->sig;
        delete p;
    }
}

void apilarnuevo(NodoPila *&pila, Libro libro, Libro libro2)
{
    if (pila == NULL)
    {
        apilar(pila, libro);
    }
    else
    {
        NodoPila *tempPila = NULL;
        for (int i = 0; i < 2; i++)
        {
            desapilar(pila, libro);
            apilar(tempPila, libro);
        }

        apilar(pila, libro2);

        while (tempPila != NULL)
        {
            desapilar(tempPila, libro);
            apilar(pila, libro);
        }
        delete tempPila;
    }
}