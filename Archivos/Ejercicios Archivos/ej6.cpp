#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Series
{
    int id;
    char titulo[30], genero[30];
};

void apareo(FILE *as1, FILE *as2, FILE *archivo);
void abrirAct(FILE *archivo);

int main()
{
    FILE *arch, *archs1, *archs2;
    arch = fopen("ActSeries.dat", "wb");
    archs1 = fopen("Series.dat", "rb");
    archs2 = fopen("NovSeries.dat", "rb");
    if (arch == NULL)
        cout << "Error al crear el archivo" << endl;
    else
    {
        apareo(archs1, archs2, arch);
        abrirAct(arch);
    }
    fclose(arch);
}

void apareo(FILE *as1, FILE *as2, FILE *archivo)
{
    Series s1, s2, s;
    if (as1 == NULL || as2 == NULL)
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    fread(&s1, sizeof(Series), 1, as1);
    fread(&s2, sizeof(Series), 1, as2);

    while (!feof(as1) && !feof(as2))
    {
        if (s1.id < s2.id)
        {
            cout << s1.id << " " << s1.titulo << endl;
            fwrite(&s1, sizeof(Series), 1, archivo);
            fread(&s1, sizeof(Series), 1, as1);
        }
        else
        {
            cout << s2.id << " " << s2.titulo << endl;
            fwrite(&s2, sizeof(Series), 1, archivo);
            fread(&s2, sizeof(Series), 1, as2);
        }
    }

     while(!feof(as1))
    {
        cout << s1.id << " " << s1.titulo << endl;
        fwrite(&s1, sizeof(Series), 1, archivo);
        fread(&s1,sizeof(Series),1,as1);
    }
    while(!feof(as2))
    {
        cout << s2.id << " " << s2.titulo << endl;
        fwrite(&s2, sizeof(Series), 1, archivo);
        fread(&s2, sizeof(Series), 1, as2);
    }

    fclose(archivo);
    fclose(as1);
    fclose(as2);
}

void abrirAct(FILE *archivo)
{
    Series s;
    archivo = fopen("ActSeries.dat", "rb");
    fread(&s, sizeof(Series), 1, archivo);
    while (!feof(archivo))
    {
        cout << "Id: " << s.id << endl;
        cout << "Serie: " << s.titulo << endl;
        cout << "Género: " << s.genero << endl;

        fread(&s, sizeof(Series), 1, archivo);
    }
    fclose(archivo);
} 
