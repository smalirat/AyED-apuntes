#include <iostream>
#include <string.h>

using namespace std;

struct Estudiante
{
    unsigned legajo;
    char nombre[21];
    unsigned nota;

};

int cargarEstudiantes(Estudiante*v[],int t);
float promedio(Estudiante*v[],int t);

int main()
{
    Estudiante*vecPuntEst[5];
    int cantEst=cargarEstudiantes(vecPuntEst,5);
    cout<<"Promedio de los presentes: "<<promedio(vecPuntEst,cantEst)<<endl;
    return 0;
}

int cargarEstudiantes(Estudiante*v[],int t)
{
    int leg,i=0;
    Estudiante*p;
    cout<<"Legajo: ";
    cin>>leg;
    while(leg!=0 && i<t)
    {
        /*
        p=new Estudiante;
        p->legajo=leg;
        cout<<"Nombre: ";
        cin>>p->nombre;
        cout<<"Nota: ";
        cin>>p->nota;

        v[i]=p;
        */
        v[i]=new Estudiante;
        v[i]->legajo=leg;
        cout<<"Nombre: ";
        cin>>v[i]->nombre;
        cout<<"Nota: ";
        cin>>v[i]->nota;
        i++;
        cout<<"Legajo: ";
        cin>>leg;
    }
    return i;
}




float promedio(Estudiante*v[],int t)
{
    int s=0;
    for(int i=0;i<t;i++)
        s+=v[i]->nota;
    return (float)s/t;
}









