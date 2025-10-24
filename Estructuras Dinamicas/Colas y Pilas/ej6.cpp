#include <iostream>
#include <stdio.h>

using namespace std;

struct Personas
{
    int dni;
    string nombre;
};

struct NodoCola
{
    Personas info;
    NodoCola *sig;
};

void encolar(NodoCola *&pri, NodoCola *&ult, Personas persona);
void desencolar(NodoCola *&pri, NodoCola *&ult, Personas &persona);
void ejercicio(NodoCola *&pri, NodoCola *&ult, Personas &persona);

int main()
{
    Personas p;
    NodoCola *priColaNum, *ultColaNum;
    priColaNum = ultColaNum = NULL;
    cout << "Dni: ";
    cin >> p.dni;
    while (p.dni != 0)
    {
        cout << "Nombre: ";
        cin >> p.nombre;

        encolar(priColaNum, ultColaNum, p);

        cout << "Dni: ";
        cin >> p.dni;
    }

    ejercicio(priColaNum, ultColaNum, p);

    return 0;
}

void encolar(NodoCola *&pri, NodoCola *&ult, Personas persona)
{
    NodoCola *p = new NodoCola;
    p->info = persona;
    p->sig = NULL;
    if (ult != NULL)
        ult->sig = p;
    else
        pri = p;
    ult = p;
}

void desencolar(NodoCola *&pri, NodoCola *&ult, Personas &persona)
{
    NodoCola *p = pri;
    persona = p->info;
    pri = p->sig;
    delete p;
    if (pri == NULL)
        ult = NULL;
}

void ejercicio(NodoCola *&pri, NodoCola *&ult, Personas &persona)
{
    NodoCola *priAux = NULL, *ultAux = NULL;
    int documento;
    Personas personaAux;
    cout << "Documento: ";
    cin >> documento;

    while (pri != NULL)
    {
        desencolar(pri, ult, persona);
        if (persona.dni == documento)
        {
            personaAux = persona;
        }
        else
        {
            encolar(priAux, ultAux, persona); 
        }
    }
    encolar(priAux, ultAux, personaAux);

    while (priAux != NULL)
    {
        desencolar(priAux, ultAux, persona);
        cout << "DNI: " << persona.dni << ", Nombre: " << persona.nombre << endl;
    }
}
