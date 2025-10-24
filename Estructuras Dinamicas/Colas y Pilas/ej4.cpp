#include <iostream>

using namespace std;

struct Numeros
{
    int x;
    int y;
};

struct NodoPila
{
    Numeros datos;
    NodoPila *sig;
};

void apilar(NodoPila *&pila, int contenido);
void desapilar(NodoPila *&pila, NodoPila *&pilaaux, int &contenido, Numeros num);

int main()
{
    NodoPila *pila = NULL, *pilaaux = NULL;
    Numeros num;
    int contenido;

    cout << "Ingrese un numero de la pila: ";
    cin >> contenido;
    while (contenido != 0)
    {
        apilar(pila, contenido);
        cout << "Ingrese un numero de la pila: ";
        cin >> contenido;
    }

    cout << "X: ";
    cin >> num.x;
    cout << "Y: ";
    cin >> num.y;

    while (pila != NULL)
    {
        desapilar(pila, pilaaux, contenido, num);
    }

    cout << "Contenido de la pila auxiliar (pilaaux):" << endl;
    while (pilaaux != NULL)
    {
        cout << pilaaux->datos.x << " "; // Imprime el valor de X
        pilaaux = pilaaux->sig;
    }

    return 0;
}

void apilar(NodoPila *&pila, int contenido)
{
    NodoPila *p;
    p = new NodoPila;
    p->datos.x = contenido;
    p->sig = pila;
    pila = p;
}

void desapilar(NodoPila *&pila, NodoPila *&pilaaux, int &contenido, Numeros num)
{
    NodoPila *p = pila;
    contenido = p->datos.x;
    pila = p->sig;

    if (contenido == num.y)
        apilar(pilaaux, num.x);
    else
        apilar(pilaaux, contenido);

    delete p;
}