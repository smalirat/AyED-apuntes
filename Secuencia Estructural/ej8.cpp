//Ejercicio 8: Determinar el porcentaje de alumnos aprobados, desaprobados y ausentes que hubo en un examen, conociendo las cantidades de cada uno.

#include <iostream>

using namespace std;

int main()
{
    float aprobados,desaprobados,ausentes,pApr,pDesapr,pAus;
    
    cout<<"Ingrese numero de aprobados "<<endl;
    cin>> aprobados;
    cout<<"Ingrese numero de desaprobados "<<endl;
    cin>> desaprobados;
    cout<<"ingrese numero de ausentes"<<endl;
    cin>> ausentes;
    pApr = aprobados*100/(aprobados+desaprobados+ausentes);
    pDesapr = desaprobados*100/(aprobados+desaprobados+ausentes);
    pAus = ausentes*100/(aprobados+desaprobados+ausentes);

    cout<<"Ha aprobado un "<<pApr<<" % ";
    cout<<"Ha desaprobado un "<<pDesapr<<" % ";
    cout<<"Ha habido un "<<pAus<<" % de ausentes";
  
    return 0;

}

