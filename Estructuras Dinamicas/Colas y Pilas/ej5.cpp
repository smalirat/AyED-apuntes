#include <iostream>
#include <stdio.h>

using namespace std;

struct NodoCola
{
    int info;
    NodoCola *sig;
};

void encolar(NodoCola *&pri, NodoCola *&ult, int nro);
void desencolar(NodoCola *&pri, NodoCola *&ult, int &nro);

int main()
{
    int n, cont = 0;
    NodoCola *priColaNum, *ultColaNum;
    priColaNum = ultColaNum = NULL;
    cin >> n;
    while (n != 0)
    {
        encolar(priColaNum, ultColaNum, n);
        cin >> n;
    }

    while (priColaNum != NULL && cont < 4)
    {
        desencolar(priColaNum, ultColaNum, n);
        cont++;
    }

    if (cont < 4)
    {
        cout << "No fue posible desencolar 4 elementos";
    }
    else
    {
        cout << "Numeros no desencolados: ";
        while (priColaNum != 0)
        {
            desencolar(priColaNum, ultColaNum, n);
            cout << n << endl;
        }
    }

    return 0;
}

void encolar(NodoCola *&pri, NodoCola *&ult, int nro)
{
    NodoCola *p = new NodoCola;
    p->info = nro;
    p->sig = NULL;
    if (ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult = p;
}

void desencolar(NodoCola *&pri, NodoCola *&ult, int &nro)
{
    NodoCola *p = pri;
    nro = p->info; // nro=pri->info;
    pri = p->sig;
    delete p;
    if (pri == NULL)
        ult = NULL;
}