/*
En un club se quiere hacer un programa para obtener datos estadísticos de los atletas que compitieron
en las 15 actividades deportivas que se practican en el mismo.  Se tiene el archivo “Competidores.dat”,
con cada una de las participaciones de los atletas competencias, sin orden, donde cada registro tiene el siguiente formato:
Código de actividad (1..15)  Número de socio del atleta   Fecha de la competencia (struct dia, mes, anio)  Resultado (int)
Se pide: a) Informar por cada actividad, por cada mes, cada uno de los atletas que compitieron y el resultado obtenido,
ordenado por código de actividad, por mes y por número de socio.
b) Informar por cada mes del año el total de atletas que compitieron en cada actividad.
c) Informar en qué actividad deportiva hubo más de un primer puesto.

 a) Matriz de lista, la lista ordenada por codigo
Fila act, columna mes
b) Hacer funciones q recorran
c) SI ya se tienen 2, se deja de correr la lista
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Fecha
{
    unsigned dia, mes, año;
};

struct Archivo
{
    unsigned numSocio;
    int codigo, resultado;
    Fecha f;
};

struct Competidores
{
    unsigned numSocio;
    int resultado;
};
struct Nodo
{
    Competidores info;
    Nodo *sig;
};

void inicializar(Nodo *m[][12]);
void insertar(Nodo *&lista, Competidores c);
void mostrarVectorDeListas(Nodo *m[][12]);

int main()
{
    Nodo *matriz[15][12];
    Competidores c;
    Archivo a;
    FILE *arch;
    int fila, columna;

    inicializar(matriz);

    c.numSocio = 100;
    c.resultado = 1;
    insertar(matriz[1][2], c);

    c.numSocio = 120;
    c.resultado = 2;
    insertar(matriz[1][2], c);

    c.numSocio = 300;
    c.resultado = 3;
    insertar(matriz[3][5], c);

    mostrarVectorDeListas(matriz);

    return 0;
}

void inicializar(Nodo *m[][12])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 12; j++)
            m[i][j] = NULL;
    }
}

void insertar(Nodo *&lista, Competidores c)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = c;
    p = lista;

    while (p != NULL && p->info.numSocio < c.numSocio)
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

void mostrarVectorDeListas(Nodo *m[][12])
{
    Nodo *p;
    int cont[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            p = m[i][j];
            if (p != NULL)
            {
                cout << "Actividad " << i + 1 << endl;
                cout << "Mes: " << j + 1 << endl;
            }

            while (p != NULL)
            {

                cout << "Socio: " << p->info.numSocio << "  Resultado: " << p->info.resultado << endl;
                cont[j]++;
                p = p->sig;
            }
        }
    }

    for (int k = 0; k < 12; k++)
    {
        if (cont[k] != 0)
            cout << "El mes " << k + 1 << " tuvo " << cont[k] << " participantes" << endl;
    }
}
