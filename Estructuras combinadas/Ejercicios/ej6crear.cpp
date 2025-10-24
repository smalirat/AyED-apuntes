#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Archivo
{
    int fecha, codigo;
    char patente[8];
};

int main()
{
    FILE *arch;
    char nomArch[21], patent[8];
    cout << "Nombre del archivo: ";
    cin >> nomArch;
    strcat(nomArch, ".dat");
    arch = fopen(nomArch, "wb");
    if (arch == NULL)
        cout << "Error de creación de archivo" << endl;
    else
    {
        Archivo a;
        cout << "Código (cero fin): ";
        cin >> a.codigo;
        while (a.codigo != 0)
        {
            cout << "Fecha : ";
            cin >> a.fecha;
            cout << "Patente: ";
            cin >> a.patente;

            fwrite(&a, sizeof(Archivo), 1, arch);

            cout << "Código de vendedor (cero fin): ";
            cin >> a.codigo;
        }
        fclose(arch);
    }
    return 0;
}