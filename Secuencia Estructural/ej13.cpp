/*Ejercicio 13: En una empresa automotriz existen 3 áreas: Ensambladora, Pintura y Eléctrica. El presupuesto anual de la empresa se reparte de la siguiente manera:
Área Presupuesto
Ensambladora 37%
Pintura 42%
Eléctrica 21%
Obtener la cantidad
*/

#include <iostream>
using namespace std;

int main() {
   float presupuesto, ensambladora, pintura, electrica;

   cout << "Ingrese el presupuesto: ";
   cin >> presupuesto;

   ensambladora = presupuesto * 0.37;
   pintura = presupuesto * 0.42;
   electrica = presupuesto * 0.21;

   cout << "La Ensambladora recibirá: " << ensambladora << " pesos." << endl;
   cout << "La Pintura recibirá: " << pintura << " pesos." << endl;
   cout << "La Eléctrica recibirá: " << electrica << " pesos." << endl;

   return 0;
}
