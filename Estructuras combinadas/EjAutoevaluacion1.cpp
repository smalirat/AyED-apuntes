#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct NodoCola
{
    char info[6];
    NodoCola*sig;
};
struct Cola
{
    NodoCola*primero;
    NodoCola*ultimo;
};

void encolar(NodoCola*&pri,NodoCola*&ult,char dato[]);
void desencolar(NodoCola*&pri,NodoCola*&ult, char dato[]);
void recibir(Cola v[],char nombre[],int prioridad);
void atender(Cola v[],int t);
void inicializar(Cola v[],int t);
int ingresoValido(int desde, int hasta);

int main()
{
    Cola salaEspera[5];
    int opcion,prioridad;
    char nombre[6];
    inicializar(salaEspera,5);
    do
    {
        cout<<"1 - Ingresar un paciente"<<endl;
        cout<<"2 - Atender un paciente"<<endl;
        cout<<"3 - Salir"<<endl;
        cin>>opcion;
        switch(opcion)
        {
            case 1:
                cout<<"Nombre del paciente: ";
                cin>>nombre;
                cout<<"Prioridad: ";
                prioridad=ingresoValido(0,4);
                recibir(salaEspera,nombre,prioridad);
                break;
            case 2:
                atender(salaEspera,5);
                break;
        }
    }while(opcion!=3);
    return 0;
}

void recibir(Cola v[],char nombre[],int prioridad)
{
    encolar(v[prioridad].primero,v[prioridad].ultimo,nombre);
}

void atender(Cola v[],int t)
{
    int i=0;
    while(i<t && v[i].primero==NULL)
        i++;
    if(i==5)
        cout<<"Sala de espera vacia"<<endl;
    else
    {
        char nom[6];
        desencolar(v[i].primero,v[i].ultimo,nom);
        cout<<nom<<endl;
    }
}

void encolar(NodoCola*&pri,NodoCola*&ult,char dato[])
{
    NodoCola*p;
    p=new NodoCola;
    strcpy(p->info,dato);
    p->sig=NULL;
    if(ult!=NULL)
        ult->sig=p;
    else
        pri=p;
    ult=p;
}

void desencolar(NodoCola*&pri,NodoCola*&ult,char dato[])
{
    NodoCola*p;
    p=pri;
    strcpy(dato,p->info);
    pri=p->sig;
    delete p;
    if(pri==NULL)
        ult=NULL;

}

void inicializar(Cola v[],int t)
{
    for(int i=0;i<t;i++)
    {
        v[i].primero=NULL;
        v[i].ultimo=NULL;
    }
}

int ingresoValido(int desde, int hasta)
{
    int p;
    do
        cin>>p;
    while(p<desde || p>hasta);
    return p;
}
