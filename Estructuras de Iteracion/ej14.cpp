/*Desarrollar un algoritmo que permita ingresar un conjunto de valores, cada uno de los cuales representa el sueldo de un empleado 
(se sabe que un sueldo igual a 0 indica el fin del conjunto), e informe: 
a) Cuántos empleados ganan menos de $900 b) Cuántos ganan $900 o más, pero menos de $1200 
c) Cuántos ganan $1200 o más, pero menos de $2000 d) Cuántos ganan $2000 o más. 
*/

#include <iostream>

using namespace std;

int main(){

    unsigned sueldo;
    int empleados,a=0,b=0,c=0,d=0,i,j;
    string nombre;

    cout<<"Cantidad de empleados ";
    cin>>empleados;

    for (i = 1; i <= empleados; i++){
        
        cout<<endl<<"Nombre: ";
        cin>>nombre;
        cout<<"Sueldo: ";
        cin>>sueldo;

        if (sueldo>=2000)
            d++;
        else
            if (1200<=sueldo && sueldo<2000)
                c++;
                else
                    if (900<sueldo && sueldo<1200)
                        b++;
                    else
                        a++;
}

    cout<<a<<" empleados ganan menos de $900"<<endl;
    cout<<b<<" empleados ganan ganan $900 o mas, pero menos de $1200"<<endl;
    cout<<c<<" empleados ganan $1200 o mas, pero menos de $2000"<<endl;
    cout<<d<<" empleados ganan $2000 o mas"<<endl;




}