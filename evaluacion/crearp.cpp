#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Inscriptos
{
    unsigned dni, cod;
    float ingreso;
    char nombre[20], apellido[20];
};

struct Creditos
{
    unsigned codigo;
    int cantidad;
    char descripcion[30];
};

int main()
{
    FILE *arch, *arch2; // Cambié el nombre del puntero a arch2
    char nomArch[21], nomArch2[21];

    // Archivo de Inscriptos
    cout << "Nombre del archivo (Inscriptos): ";
    cin >> nomArch;
    strcat(nomArch, ".dat");
    arch = fopen(nomArch, "wb");

    if (arch == NULL)
        cout << "Error de creación de archivo" << endl;
    else
    {
        Inscriptos i;
        cout << "Código de inscrito (cero fin): ";
        cin >> i.cod;

        while (i.cod != 0)
        {
            cout << "Número de DNI: ";
            cin >> i.dni;
            cout << "Nombre: ";
            cin >> i.nombre;
            cout << "Apellido: ";
            cin >> i.apellido;
            cout << "Ingreso: ";
            cin >> i.ingreso;

            fwrite(&i, sizeof(Inscriptos), 1, arch);

            cout << "Código de inscrito (cero fin): ";
            cin >> i.cod;
        }
        fclose(arch);

        // Archivo de Creditos
        cout << "Nombre del archivo (Creditos): ";
        cin >> nomArch2;
        strcat(nomArch2, ".dat");
        arch2 = fopen(nomArch2, "wb"); // Corregí el nombre del puntero a arch2
        if (arch2 == NULL)
            cout << "Error de creación de archivo" << endl;
        else
        {
            Creditos c;
            cout << "Código de crédito (cero fin): ";
            cin >> c.codigo;

            while (c.codigo != 0)
            {
                cout << "Cantidad: ";
                cin >> c.cantidad;
                cout << "Descripción: ";
                cin >> c.descripcion;
                fwrite(&c, sizeof(Creditos), 1, arch2);

                cout << "Código de crédito (cero fin): ";
                cin >> c.codigo;
            }
            fclose(arch2);
        }
        return 0;
    }
}
