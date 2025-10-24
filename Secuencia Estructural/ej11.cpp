//Ejercicio 11 En una empresa vendedora de alambres se quiere calcular el precio de un pedido. Para ello se ingresa los metros pedidos. El precio del alambre es de 75 pesos por metro.

#include <iostream>
using namespace std;

int main() {
   float mts, precio;

   cout << "Ingrese la cantidad de metros de alambre ";
   cin >> mts;

   precio = mts * 75;

   cout << "El precio del pedido es: " << precio << " pesos." << endl;

   return 0;
}