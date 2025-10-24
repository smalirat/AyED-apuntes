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
    int n;
    NodoCola *priColaNum, *ultColaNum;
    priColaNum = ultColaNum = NULL;
    cin >> n;
    while (n != 0)
    {
        encolar(priColaNum, ultColaNum, n);
        cin >> n;
    }
    while (priColaNum != NULL)
    {
        desencolar(priColaNum, ultColaNum, n);
        cout << n << endl;
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