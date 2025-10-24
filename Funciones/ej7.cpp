//Desarrollar la función unsigned edadAGrupoEtario (unsigned edad) que retorne un valor de 1 a 8, de acuerdo al siguiente cuadro:

#include <iostream>

using namespace std;


int grupo_etario(unsigned edad);




int main()
{
   
    int grupo,a,b,edad;

   cout<<"Ingrese su edad: ";
   cin>>edad;


   grupo = grupo_etario(edad);

   cout<<"el grupo etario es: "<<grupo;

   return 0;


}


int grupo_etario(unsigned edad) {
   if (edad > 63) {
        return 8;
    } else if (edad > 49) {
        return 7;
    } else if (edad > 42) {
        return 6;
    } else if (edad > 35) {
        return 5;
    } else if (edad > 28) {
        return 4;
    } else if (edad > 21) {
        return 3;
    } else if (edad > 15) {
        return 2;
    } else {
        return 1;
    }
}
