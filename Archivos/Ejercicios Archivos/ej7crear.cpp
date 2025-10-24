
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Libros
{
    int codigo, stock;
    char autor[20], titulo[30], editorial[20], genero[20];
};

int main()
{
    FILE *arch1, *arch2;
    arch1 = fopen("StockEnLocal.dat", "wb");
    if (arch1 == NULL)
        cout << "Error de creacion de archivo" << endl;
    else
    {
        Libros l1;
        cout << "Codigo (cero fin) ";
        cin >> l1.codigo;
        while (l1.codigo != 0)
        {
            /* cout << "Stock: ";
            cin >> l1.stock;
            cout << "Titulo: ";
            cin >> l1.titulo;
            cout << "Autor: ";
            cin >> l1.autor;
            cout << "Editorial: ";
            cin >> l1.editorial;
            cout << "Género: ";
            cin >> l1.genero; */

            fwrite(&l1, sizeof(Libros), 1, arch1);

            cout << "Codigo (cero fin) ";
            cin >> l1.codigo;
        }
        fclose(arch1);
    }

    arch2 = fopen("StockEnDeposito.dat", "wb");
    if (arch2 == NULL)
        cout << "Error de creacion de archivo" << endl;
    else
    {
        Libros l2;
        cout << "Codigo: nuevo archivo (cero fin) ";
        cin >> l2.codigo;
        while (l2.codigo != 0)
        {
            /*cout << "Stock: ";
            cin >> l2.stock;
            cout << "Titulo: ";
            cin >> l2.titulo;
            cout << "Autor: ";
            cin >> l2.autor;
            cout << "Editorial: ";
            cin >> l2.editorial;
            cout << "Género: ";
            cin >> l2.genero; */

            fwrite(&l2, sizeof(Libros), 1, arch2);

            cout << "Codigo (cero fin) ";
            cin >> l2.codigo;
        }
        fclose(arch2);
    }

    return 0;
}
