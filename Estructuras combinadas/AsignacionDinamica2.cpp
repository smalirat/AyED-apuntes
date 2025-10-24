#include <iostream>

using namespace std;

struct Estudiante
{
    unsigned legajo;
    char nombre[21];
    unsigned nota;
};

int main()
{
    /*
    Estudiante e;
    cin>>e.legajo;
    cin>>e.nombre;
    cin>>e.nota;
    */
    Estudiante*p;
    p=new Estudiante;
    /*
    cin>>(*p).legajo;
    cin>>(*p).nombre;
    cin>>(*p).nota;
    */
    cin>>p->legajo;
    cin>>p->nombre;
    cin>>p->nota;
    p=new Estudiante;
    return 0;
}
