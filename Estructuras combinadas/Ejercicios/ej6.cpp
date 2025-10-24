/*
La ciudad de Buenos Aires requiere un estudio estadístico de infracciones realizadas por los vehículos en sus calles.
Para ello cuenta con un archivo de infracciones “Infracciones.dat”, ordenado por fecha de la infracción creciente,
con el siguiente diseño:  Patente (7 caracteres)  Fecha de Infracción (int, aammdd)  Código de infracción (int, 1 a 100)
Se desea obtener un listado ordenado por código de infracción decreciente con las  patentes que cometieron más de una vez la misma infracción.

Vector de infracciones con lista de fecha y patente
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Infracciones
{
    int fecha, codigo;
    char patente[8];
};

struct Nodo
{
    Infracciones info;
    Nodo *sig;
};

void listar(Nodo *vectorDeListas[]);
void insertar(Nodo *&lista, Infracciones i);
void inicializar(Nodo *vectorDeListas[]);
int main()
{
    Nodo *vLista[100];
    Infracciones i, aux;
    int pos;
    FILE *arch;
    inicializar(vLista);

    /* arch = fopen("Infracciones.dat", "rb");

    if (arch == NULL)
        cout << "Error al abrir el archivo";
    else
    {

        fread(&i, sizeof(Infracciones), 1, arch);
         while (!feof(arch))
         {
             pos = i.codigo;
             aux.fecha = i.fecha;
             strcpy(aux.patente, i.patente);
             insertar(vLista[pos], aux);
             fread(&i, sizeof(Infracciones), 1, arch);
         }
         fclose(arch); */
    i.fecha = 10;
    strcpy(i.patente, "pop");
    insertar(vLista[10], i);

    i.fecha = 11;
    strcpy(i.patente, "pap");
    insertar(vLista[10], i);

    i.fecha = 40;
    strcpy(i.patente, "pep");
    insertar(vLista[10], i);

    listar(vLista);

    return 0;
}

void inicializar(Nodo *vectorDeListas[])
{
    for (int i = 1; i < 11; i++)
        vectorDeListas[i] = NULL;
}

void listar(Nodo *vectorDeListas[])
{
    Nodo *p;

    for (int i = 1; i < 11; i++)
    {
        p = vectorDeListas[i];
        if (p != NULL)
            cout << "Lista " << i << endl;
        while (p != NULL)
        {
            cout << "Patente: " << p->info.patente << endl;
            cout << "Fecha" << p->info.fecha << endl; // Add a line break for clarity
            p = p->sig;
        }
    }
}

void insertar(Nodo *&lista, Infracciones i)
{
    Nodo *n, *p, *ant;
    n = new Nodo;
    n->info = i;
    p = lista;
    while (p != NULL && strcmp(p->info.patente, i.patente) < 0)
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

void verificar(Nodo *lista, int pos)
{
    Nodo *p, *ant;
    p = lista;
    Infracciones i;

    while (p != NULL)
    {
        strcpy(i.patente, p->info.patente);
        i.fecha = p->info.fecha;
        i.codigo = p->info.codigo;
        p = p->sig;
        if (strcmp(p->info.patente, i.patente) == 0)
            insertar(lista, i);
        p = p->sig;
    }
}
