//Ejercicio 14: Un empresario constructor sabe que necesita 0,5 metros cúbicos de arena por metro cuadrado de revoque a realizar. Hacer un programa donde ingrese las medidas de una pared (largo y alto) expresada en metros y obtenga la cantidad de arena necesaria para revocarla.

#include <iostream>
using namespace std;

int main() {
   float largo, alto, area, arena;

   cout << "Ingrese el largo de la pared en metros: ";
   cin >> largo;

   cout << "Ingrese el alto de la pared en metros: ";
   cin >> alto;

   area = largo * alto;
   arena = area * 0.5;

   cout << "La cantidad de arena necesaria para revocar la pared es: " << arena << " metros cúbicos." << endl;

   return 0;
}
