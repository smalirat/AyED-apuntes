#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Libros
{
    int codigo, stock;
    char autor[20], titulo[30], editorial[20], genero[20];
};

void hacerVector(FILE *a1, FILE *a2, Libros v1[], Libros v2[], int auxtam[]);
void binaria(Libros v1[], Libros v2[], int t1, int t2, int bus, int p[]);

int main()
{
    FILE *arch1, *arch2;
    Libros vector1[1000], vector2[1000];
    int pos, aux[3], tam1, tam2;
    hacerVector(arch1, arch2, vector1, vector2, aux);
    if (arch1 == NULL)
        cout << "Error de creacion de archivo" << endl;
    else
    {
        tam1 = aux[1];
        tam2 = aux[2];
        int parametro[3];
        for (int i = 1; i <= 10; i++)
        {
            binaria(vector1, vector2, tam1, tam2, i, parametro);
            if (parametro[1] == -1 && parametro[2] == -1)
            {
                cout << "El libro " << i << " Falta en local y en deposito" << endl;
            }
            else
            {
                if (parametro[1] == -1)
                {
                    cout << "El libro " << i << " Falta en local" << endl;
                }
                else
                {
                    cout << "El libro " << i << " Falta en deposito" << endl;
                }
            }
        }
    }
    return 0;
}

void hacerVector(FILE *a1, FILE *a2, Libros v1[], Libros v2[], int auxtam[])
{
    a1 = fopen("StockEnLocal.dat", "rb");
    a2 = fopen("StockEnDeposito.dat", "rb");
    if (a1 == NULL || a2 == NULL)
    {
        cout << "Error de creación de archivo" << endl;
    }
    else
    {
        Libros l1, l2;
        int i = 0, j = 0;
        fread(&l1, sizeof(Libros), 1, a1);
        fread(&l2, sizeof(Libros), 1, a2);
        while (!feof(a1))
        {
            v1[i].codigo = l1.codigo;
            /*v1[i].stock = l1.stock;
            strcpy(v1[i].autor, l1.autor);
            strcpy(v1[i].titulo, l1.titulo);
            strcpy(v1[i].editorial, l1.editorial);
            strcpy(v1[i].genero, l1.genero);*/
            fread(&l1, sizeof(Libros), 1, a1);
            i++;
        }
        while (!feof(a2))
        {
            v2[j].codigo = l2.codigo;
            /*v1[j].stock = l2.stock;
            strcpy(v1[j].autor, l2.autor);
            strcpy(v1[j].titulo, l2.titulo);
            strcpy(v1[j].editorial, l2.editorial);
            strcpy(v1[j].genero, l2.genero);*/
            fread(&l2, sizeof(Libros), 1, a2);
            j++;
        }
        fclose(a1);
        fclose(a2);
        auxtam[1] = i;
        auxtam[2] = j;
    }
}

void binaria(Libros v1[], Libros v2[], int t1, int t2, int bus, int p[])
{
    p[1] = -1;
    int desde = 0, hasta = t1 - 1, medio;
    while (desde <= hasta && p[1] == -1)
    {
        medio = (desde + hasta) / 2;
        if (v1[medio].codigo == bus)
            p[1] = medio;
        else
        {
            if (bus < v1[medio].codigo)
                hasta = medio - 1;
            else
                desde = medio + 1;
        }
    }

    p[2] = -1;
    desde = 0, hasta = t2 - 1, medio;
    while (desde <= hasta && p[2] == -1)
    {
        medio = (desde + hasta) / 2;
        if (v2[medio].codigo == bus)
            p[2] = medio;
        else
        {
            if (bus < v2[medio].codigo)
                hasta = medio - 1;
            else
                desde = medio + 1;
        }
    }
}
