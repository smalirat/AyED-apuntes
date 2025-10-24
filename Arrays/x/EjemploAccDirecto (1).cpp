#include <iostream>


using namespace std;
//Se ingresan los legajos y sueldos de los empleados de una empresa que,
//como maximo tiene 100 empleados. El ingreso de datos finaliza con legajo cero.
//Se pide:
//    Mostrar legajo y sueldo de todos lo empleados
//    Mostrar los legajos de los empleados que tienen el mayor sueldo.

//2) Los legajos son n�meros entre 1 y 100

void inicializar(float v[],int c);
int ingresoVerificado(int desde, int hasta);
bool ingresarDatos(float vs[]);
void mostrarTodos(float vs[],int t);
float maximo(float v[],int t);
void mostrarLegMayorSueldo(float vs[],int t,float s);
float maximo(float v[],int t,int pos[],int &j);
void mostrarLegMayorSueldo(int vp[],int t,float s);


int main()
{
    float sueldos[100],maxSueldo;
    inicializar(sueldos,100);
    if(ingresarDatos(sueldos))
    {
        mostrarTodos(sueldos,100); //a

        //b con doble recorrida del vector sueldos
        maxSueldo=maximo(sueldos,100);
        mostrarLegMayorSueldo(sueldos,100,maxSueldo);

        //b con vector de posiciones
        int vecPos[100],tamPos;
        maxSueldo=maximo(sueldos,100,vecPos,tamPos);
        mostrarLegMayorSueldo(vecPos,tamPos,maxSueldo);

    }

    return 0;
}

void inicializar(float v[],int c)
{
    for(int i=0;i<c;i++)
        v[i]=0;
}

bool ingresarDatos(float vs[])
{
    int leg;
    float suel;
    bool carga=false;
    cout<<"Legajo ";
    leg=ingresoVerificado(0,100);
    while(leg!=0)
    {
        carga=true;
        cout<<"Sueldo ";
        cin>>suel;
        vs[leg-1]=suel;

        cout<<"Legajo ";
        leg=ingresoVerificado(0,100);
    }
    return carga;
}

int ingresoVerificado(int desde, int hasta)
{
    int n;
    do
        cin>>n;
    while(n<desde || n>hasta);
    return n;
}

void mostrarTodos(float vs[],int t)
{
    cout<<endl<<"Listado de empleados"<<endl;
    for(int i=0;i<t;i++)
    {
        if(vs[i]!=0)
            cout<<i+1<<" - "<<vs[i]<<endl;
    }
}

float maximo(float v[],int t)
{
    float m;
    bool pri=true;
    for(int i=0;i<t;i++)
    {
        if(v[i]!=0)
        {
            if(pri || v[i]>m)
            {
                pri=false;
                m=v[i];
            }

        }
    }
    return m;
}

void mostrarLegMayorSueldo(float vs[],int t,float s)
{
    cout<<endl<<"Legajos con el mayor sueldo "<<s<<endl;
    for(int i=0;i<t;i++)
    {
        if(vs[i]==s)
            cout<<i+1<<endl;
    }
}

float maximo(float v[],int t,int pos[],int &j)
{
    float m;
    bool pri=true;
    for(int i=0;i<t;i++)
    {
        if(v[i]!=0)
        {
            if(pri || v[i]>m)
            {
                pri=false;
                m=v[i];
                j=0;
                pos[j]=i;
                j++;
            }
            else
            {
                if(v[i]==m)
                {
                    pos[j]=i;
                    j++;
                }
            }
        }
    }
    return m;
}

void mostrarLegMayorSueldo(int vp[],int t,float s)
{
    cout<<endl<<"Legajos con el mayor sueldo "<<s<<endl;
    for(int i=0;i<t;i++)
    {
        cout<<vp[i]+1<<endl;
    }

}

