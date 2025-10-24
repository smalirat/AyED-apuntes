
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Medicos
{
    int nroDeMatricula;
    int codigoDeEspecialidad; // 1001 a 1010
    char nombre[30];
};

struct Especialidades
{
    char nomEspecialidad[30];
    int codigoDeEspecialidad; // 1001 a 1010
};

struct Consultas
{
    int dia, mes, nroDeHistoriaClinica, nroDeMatricula;
};
int main()
{
    FILE *arch, *arch1, *arch2;
    arch = fopen("Medicos.dat", "wb");
    if (arch == NULL)
        cout << "Error de creacion de archivo" << endl;
    else
    {
        Medicos m;
        cout << "Matricula(cero fin) ";
        cin >> m.nroDeMatricula;
        while (m.nroDeMatricula != 0)
        {
            cout << "Nombre: ";
            cin >> m.nombre;

            cout << "Especialidad (1001 a 1010): ";
            cin >> m.nombre;

            fwrite(&m, sizeof(Medicos), 1, arch);

            cout << "Codigo (cero fin) ";
            cin >> m.nroDeMatricula;
        }
        fclose(arch);
    }

    arch1 = fopen("Especialidades.dat", "wb");
    if (arch1 == NULL)
        cout << "Error de creacion de archivo" << endl;
    else
    {
        Especialidades e;
        for (int i = 0; i < 3; i++)
        {
            e.codigoDeEspecialidad = 1001 + i;
            cout << "Nombre especialidad: ";
            cin >> e.nomEspecialidad;
        }
        fclose(arch1);
    }

    arch2 = fopen("Consultas.dat", "wb");
    if (arch2 == NULL)
        cout << "Error de creacion de archivo" << endl;
    else
    {
        Consultas c;
        cout << "dia (cero fin) ";
        cin >> c.dia;
        while (c.dia != 0)
        {
            cout << "Mes: ";
            cin >> c.mes;

            cout << "Historia clinica: ";
            cin >> c.nroDeHistoriaClinica;

            cout << "Matricula: ";
            cin >> c.nroDeMatricula;

            fwrite(&c, sizeof(Consultas), 1, arch2);

            cout << "dia (cero fin) ";
            cin >> c.dia;
        }
        fclose(arch2);
    }

    return 0;
}
