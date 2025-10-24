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

    for (int i = 0; i < 2; i++)
    {
        desapilar(pilaLibros, libro);
    }

    cout << "Pila después de eliminar los 2 primeros libros:" << endl;
    imprimirPila(pilaLibros);

    cout << "Ingresa el nuevo título para agregar en la primera posición: ";
    cin >> libroaux.titulo;

    apilar(pilaLibros, libroaux);

    cout << "Pila después de agregar un nuevo libro en la primera posición:" << endl;
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

void desapilar(NodoPila *&pila, Libro &libro)
{
    if (pila != NULL)
    {
        NodoPila *p = pila; // Guardar una referencia al nodo actual (tope de la pila)
        libro = p->datos;   // Obtener los datos del libro del nodo actual
        pila = p->sig;      // Actualizar el tope de la pila al siguiente nodo
        delete p;           // Liberar la memoria del nodo desapilado
    }
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
