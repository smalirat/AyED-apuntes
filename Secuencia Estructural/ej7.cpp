//Ejercicio 7: Calcular el área y el perímetro de un rectángulo, dado la base y la altura. 

#include <iostream>
using namespace std;

int main() {
   float base, altura, area, perimetro;

   cout << "Ingrese la base: ";
   cin >> base;
   cout << "Ingrese la altura: ";
   cin >> altura;

   area = base * altura;
   perimetro = 2 * (base + altura);

   cout << "El área del rectángulo es: " << area << endl;
   cout << "El perímetro del rectángulo es: " << perimetro << endl;

   return 0;
}
