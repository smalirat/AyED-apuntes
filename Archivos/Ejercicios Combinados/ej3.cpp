#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Vehiculo
{
    int año;
    char patente[7], nombre[40];
};

struct Infracciones{
    int codigo,dia,mes;
    char patente[7];
    float importe;

};

struct Municipio{
    int codigo,dia,mes,año;
    char patente[7], nombre[40];;
    float importe;
};

void apareo(){

};

float importe(Vehiculo vec,Infracciones infra){
    int antiguedad;
    cout<<"Año: "<<vec.año<<endl;
    cout<<"Mes: "<<infra.mes<<endl;
    cout<<"Dia: "<<infra.dia<<endl;
    cout<<"Importe inicial: "<<infra.importe<<endl;
    antiguedad=((2023-vec.año)*365) - (infra.mes*30) - infra.dia;
    cout<<"Antiguedad: "<<antiguedad<<endl;
    if(antiguedad>7300){
        return (infra.importe-(infra.importe*0.2));
    }
    else{
        return infra.importe;
    }
    
};

int main()
{
    FILE *archM, *archV, *archI;
    char nomArch[21];
    archM=fopen("InfracMunicipio.dat","wb");
    if(archM==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Vehiculo v[1000];
        Infracciones inf[10];
        Municipio m[10];
        archV=fopen("Vehiculos.dat","rb");
        archI=fopen("Infracciones","rb");

        fread(&v, sizeof(Vehiculo), 1, archV);
        fread(&inf, sizeof(Infracciones), 1, archI);
        while(!feof(archV) && !feof(archI)){
            
            apareo();
            m[i].importe=importe(v,inf);
            cout<<"Importe: "<<m.importe<<endl;



            fwrite(&m,sizeof(Municipio),1,archM);
            fread(&v, sizeof(Vehiculo), 1, archV);
            fread(&inf, sizeof(Infracciones), 1, archI);
        }
        
        fclose(archI);
        fclose(archV);
        fclose(archM);
    }
    return 0;

    }

    
