/*
En una clinica se quiere hacer una un programa para tener estadisticas
de las consultas en consultorios externos del año pasado. Se atiende 10 especialidades en consulotorios
externos. Se cuenta con los siguientes archivos:

"Medicos.dat", sin orden, con un maximo de 100 registos. Cada registo tiene:
    - número de matricula (int)
    - nombre (30 caracteres)
    - codigo de especialidad (1001 a 1010)

"Especialidades.dat", ordenado con cada una de las 10 especialidades 
que en la clinica se atiende en consultorios externos Cada registro tiene:
    - codigo de especialidad (1001 a 1010)
    - nombre (30 caracteres)

"Consultas.dat", con un registo por cada consulta realizada en consultorios externos el año pasado,
ordenado por numero de historia clinica. Cada registro tiene:
    - dia (int)
    - mes (int)
    - numero de matricula del medico (int)
    - numero de historia clinica (int)


Realizar un porgrama para:

1) Informar cantidad de consultas realizadas por cada paciente.

2) Informar por cada especialidad: codigo de especialidad, nombre de especialidad y cantidad de consultas
de esa especialidad en cada mes.

3) Generar el archivo "ConsultasMedicos.dat" con registos por cada medico, con el siguiente formato:
    - numero de matricula del medico (int)
    - cantidad de consultas realizadas por ese medico (int) 
*/

/*
En una clinica se quiere hacer una un programa para tener estadisticas
de las consultas en consultorios externos del año pasado. Se atiende 10 especialidades en consulotorios
externos. Se cuenta con los siguientes archivos:

"Medicos.dat", sin orden, con un maximo de 100 registos. Cada registo tiene:
    - número de matricula (int)
    - nombre (30 caracteres)
    - codigo de especialidad (1001 a 1010)

"Especialidades.dat", ordenado con cada una de las 10 especialidades 
que en la clinica se atiende en consultorios externos Cada registro tiene:
    - codigo de especialidad (1001 a 1010)
    - nombre (30 caracteres)

"Consultas.dat", con un registo por cada consulta realizada en consultorios externos el año pasado,
ordenado por numero de historia clinica. Cada registro tiene:
    - dia (int)
    - mes (int)
    - numero de matricula del medico (int)
    - numero de historia clinica (int)


Realizar un porgrama para:

1) Informar cantidad de consultas realizadas por cada paciente.

2) Informar por cada especialidad: codigo de especialidad, nombre de especialidad y cantidad de consultas
de esa especialidad en cada mes.

3) Generar el archivo "ConsultasMedicos.dat" con registos por cada medico, con el siguiente formato:
    - numero de matricula del medico (int)
    - cantidad de consultas realizadas por ese medico (int) 
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

#define CANT_MEDICOS 100
#define CANT_ESPECIALIDADES 10
#define MES 12

using namespace std;

struct MedicosArchivo {
    int nroDeMatricula;
    int codigoDeEspecialidad; // 1001 a 1010
    char nombre[30];
};

struct EspecialidadesArchivo {
    int codigoDeEspecialidad; // 1001 a 1010
    char nombre[30];
};

struct ConsultasArchivo {
    int dia;
    int mes;
    int nroDeMatricula;
    int nroDeHistoriaClinica;
};

struct ConsultasMedicos {
    int nroDeMatricula;
    int codigoDeEspecialidad;
    int cantidadDeConsultas;
};

struct ConsultasMedicosArchivo {
    int nroDeMatricula;
    int cantidadDeConsultas;
};

void inicializarMedicos(int consultasPorMes[][MES]);
void procesarMedicos(FILE *archivoMedicos, ConsultasMedicos vecDeMedicos[], int &tam);
void procesarConsultas(FILE *archivoConsultas, ConsultasMedicos vecDeMedicos[], int consultasPorMes[][MES], int tam);
void mostrarConsultas(FILE *archivoEspecialidades, int consultasPorMes[][MES]);
void generarArchivo(FILE *archivoConsultasMedicos, ConsultasMedicos vecDeMedicos[], int tam);
int busquedaSecuencial(ConsultasMedicos vecDeMedicos[], unsigned dimension, int datoBuscado);

int main() {
    FILE *archivoMedicos = fopen("Medicos.dat", "rb");
    FILE *archivoEspecialidades = fopen("Especialidades.dat", "rb");
    FILE *archivoConsultas = fopen("Consultas.dat", "rb");
    FILE *archivoConsultasMedicos = fopen("ConsultasMedicos.dat", "wb");

    if(archivoMedicos == NULL ||archivoEspecialidades == NULL || archivoConsultas == NULL || archivoConsultasMedicos == NULL) {
        cout << "Error al abrir los archivos" << endl;
        return 1;
    }
    else {
        int tamLogico = 0;
        int consultasPorMes[CANT_ESPECIALIDADES][MES];
        ConsultasMedicos vecDeMedicos[CANT_MEDICOS];

        inicializarMedicos(consultasPorMes);
        procesarMedicos(archivoMedicos, vecDeMedicos, tamLogico);
        procesarConsultas(archivoConsultas, vecDeMedicos, consultasPorMes, tamLogico);
        mostrarConsultas(archivoConsultas, consultasPorMes);
        generarArchivo(archivoConsultasMedicos, vecDeMedicos, tamLogico);
    }

    return 0;
}

void inicializarMedicos(int consultasPorMes[][MES]) {
    for(int i = 0; i < CANT_ESPECIALIDADES; i++) {
        for(int j = 0; j < MES; j++)
            consultasPorMes[i][j] = 0;
    }
}

void procesarMedicos(FILE *archivoMedicos, ConsultasMedicos vecDeMedicos[], int &tam) {
    MedicosArchivo medicoActual;

    fread(&medicoActual, sizeof(MedicosArchivo), 1, archivoMedicos);

    while (!feof(archivoMedicos) && tam < CANT_MEDICOS) {
        vecDeMedicos[tam].nroDeMatricula = medicoActual.nroDeMatricula;
        vecDeMedicos[tam].codigoDeEspecialidad = medicoActual.codigoDeEspecialidad;
        vecDeMedicos[tam].cantidadDeConsultas = 0;
        tam++;

        fread(&medicoActual, sizeof(MedicosArchivo), 1, archivoMedicos);
    }

    fclose(archivoMedicos);
}

void procesarConsultas(FILE *archivoConsultas, ConsultasMedicos vecDeMedicos[], int consultasPorMes[][MES], int tam) {
    ConsultasArchivo consultaActual;
    int nroDeHistoriaClinicaActual;
    int cantidadDeConsultasTotales;
    int pos;

    fread(&consultaActual, sizeof(ConsultasArchivo), 1, archivoConsultas);

    while (!feof(archivoConsultas)) {
        nroDeHistoriaClinicaActual = consultaActual.nroDeHistoriaClinica;
        cantidadDeConsultasTotales = 0; 

        do {
            pos = busquedaSecuencial(vecDeMedicos, tam, consultaActual.nroDeMatricula);

            if (pos != -1) {
                vecDeMedicos[pos].cantidadDeConsultas++;
                consultasPorMes[vecDeMedicos[pos].codigoDeEspecialidad - 1001][consultaActual.mes - 1]++;
                cantidadDeConsultasTotales++;
            }

        } while (!feof(archivoConsultas) && consultaActual.nroDeHistoriaClinica == nroDeHistoriaClinicaActual);

        cout << "Cantidad de consultas del paciente " << nroDeHistoriaClinicaActual << ": " << cantidadDeConsultasTotales << endl;
    } 

    fclose(archivoConsultas);
}

void mostrarConsultas(FILE *archivoEspecialidades, int consultasPorMes[][MES]) {
    EspecialidadesArchivo especialidadActual;

    for(int i = 0; i < CANT_ESPECIALIDADES; i++) {
        fread(&especialidadActual, sizeof(EspecialidadesArchivo), 1, archivoEspecialidades);

        cout << "Codigo de especialidad: " << especialidadActual.codigoDeEspecialidad << endl;
        cout << "Nombre de especialidad: " << especialidadActual.nombre << endl;

        for(int j = 0; j < MES; j++) 
            cout << "Cantidad de consultas en el mes " << j + 1 << ": " << consultasPorMes[i][j] << endl;
    }

    fclose(archivoEspecialidades);
}

void generarArchivo(FILE *archivoConsultasMedicos, ConsultasMedicos vecDeMedicos[], int tam) {
    ConsultasMedicosArchivo medicoActual;

    for(int i = 0; i < tam; i++) {
        medicoActual.nroDeMatricula = vecDeMedicos[i].nroDeMatricula;
        medicoActual.cantidadDeConsultas = vecDeMedicos[i].cantidadDeConsultas;

        fwrite(&medicoActual, sizeof(ConsultasMedicosArchivo), 1, archivoConsultasMedicos);
    }

    fclose(archivoConsultasMedicos);
}

int busquedaSecuencial(ConsultasMedicos vecDeMedicos[], unsigned dimension, int datoBuscado) {
    unsigned i = 0;

    while (i < dimension && vecDeMedicos[i].nroDeMatricula != datoBuscado)
        i++;

    if (i == dimension)
        return -1;
    else
        return i;
}