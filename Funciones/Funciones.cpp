#include <iostream>

using namespace std;

/*
Ingresa 2 notas de un estudiante
y muestra su promedio
*/

void mensajeIngreso(string texto);
void mensajeResult(int,float);
int ingreso(int,int);
float promedio(int,int);
int sumar(int,int);

//con sobrecarga de funciones
void mensaje(string);
void mensaje(int,float);


int main()
{
    int nota1,nota2,dni;
    float prom;
    //mensajeIngreso("Ingrese dni");
    mensaje("Ingrese dni"); //uso de sobrecarga de funciones
    dni=ingreso(10000000,99999999);
    mensaje("Ingrese la primera nota");
    //mensajeIngreso("Ingrese la primera nota");
    nota1=ingreso(1,10);
    //mensajeIngreso("Ingrese la segunda nota
    mensaje("Ingrese la segunda nota");
    nota2=ingreso(1,10);
    prom=promedio(nota1,nota2);
    //mensajeResult(dni,prom);
    mensaje(dni,prom);
    //mensajeResult(dni,promedio(nota1,nota2));

    return 0;
}

void mensajeIngreso(string texto)
{
    cout<<texto<<endl;
}

void mensajeResult(int n,float p)
{
    cout<<"El promedio de "<<n<<" es "<<p<<endl;
}

int ingreso(int desde,int hasta)
{
    int n;
    do
        cin>>n;
    while(n<desde || n>hasta);
    return n;
}

float promedio(int n1,int n2)
{
    float p;
    /*
    int s;
    s=sumar(n1,n2);
    p=(float)s/2;
    */
    p=(float)sumar(n1,n2)/2;
    return p;
    //return (float)sumar(n1,n2)/2;
}

int sumar(int a,int b)
{
    //int sum;
    //sum=a+b;
    return a+b;
}

void mensaje(string texto)
{
    cout<<texto<<endl;
}

void mensaje(int n,float p)
{
    cout<<"El promedio de "<<n<<" es "<<p<<endl;
}
