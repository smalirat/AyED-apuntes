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
void inicializarMedicos(int consultasPorMes[3][12]);
void procesarMedicos(FILE *archivoMedicos, Medicos vecDeMedicos[]);

int main()
{
    FILE *archivoMedicos = fopen("Medicos.dat", "rb");
    FILE *archivoEspecialidades = fopen("Especialidades.dat", "rb");
    FILE *archivoConsultas = fopen("Consultas.dat", "rb");
    FILE *archivoConsultasMedicos = fopen("ConsultasMedicos.dat", "wb");

    if (archivoMedicos == NULL || archivoEspecialidades == NULL || archivoConsultas == NULL || archivoConsultasMedicos == NULL)
    {
        cout << "Error al abrir los archivos" << endl;
        return 1;
    }
    else
    {
        int consultas_mes[10][12];
        Medicos vecMed[100];
        void inicializarMedicos();

        return 0;
    }
}

void inicializarMedicos(int consultasPorMes[3][12])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
            consultasPorMes[i][j] = 0;
    }
}

void procesarMedicos(FILE *archivoMedicos, Medicos vecDeMedicos[])
{
    Medicos m;
    int i = 0;

    fread(&m, sizeof(Medicos), 1, archivoMedicos);

    while (!feof(archivoMedicos))
    {
        vecDeMedicos[i].nroDeMatricula = m.nroDeMatricula;
        vecDeMedicos[i].codigoDeEspecialidad = m.codigoDeEspecialidad;
        i++;
    }
}
