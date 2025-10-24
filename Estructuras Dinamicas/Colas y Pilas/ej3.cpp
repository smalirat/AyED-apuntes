#include <iostream>

using namespace std;

struct NodoPila
{
    char letra;
    NodoPila *sig;
};

void apilar(NodoPila *&pila, char l);
void desapilar(NodoPila *&pila, char &l);

int main()
{
    NodoPila *pila = NULL;
    char palabra[10];
    char comp;
    int i = 0, cont = 0;

    cout << "Ingresa la palabra: ";
    cin >> palabra;
    while (palabra[i] != '\0')
    {
        apilar(pila, palabra[i]);
        i++;
    }

    while (pila != NULL)
    {
        desapilar(pila, comp);
        if (comp == palabra[cont])
            cont++;
        else
            break;
    }

    if (cont == i)
        cout << "Es capicua";
    else
        cout << "No es capicua";

    return 0;
}

void apilar(NodoPila *&pila, char l)
{
    NodoPila *p = new NodoPila;
    p->letra = l;
    p->sig = pila;
    pila = p;
}

void desapilar(NodoPila *&pila, char &l)
{
    NodoPila *p = pila;
    l = p->letra;
    pila = p->sig;
    delete p;
}