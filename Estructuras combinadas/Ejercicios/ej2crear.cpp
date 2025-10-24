#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Archivo
{
    int factura, codigo;
    float importe;
};

int main()
{
    FILE *arch;
    char nomArch[21];
    cout << "Nombre del archivo: ";
    cin >> nomArch;
    strcat(nomArch, ".dat");
    arch = fopen(nomArch, "wb");
    if (arch == NULL)
        cout << "Error de creación de archivo" << endl;
    else
    {
        Archivo a;
        cout << "Código de vendedor (cero fin): ";
        cin >> a.codigo;
        while (a.codigo != 0)
        {
            cout << "Número de factura: ";
            cin >> a.factura;
            cout << "Importe: ";
            cin >> a.importe;

            fwrite(&a, sizeof(Archivo), 1, arch);

            cout << "Código de vendedor (cero fin): ";
            cin >> a.codigo;
        }
        fclose(arch);
    }
    return 0;
}
