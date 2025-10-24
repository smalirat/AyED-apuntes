//Ejercicio 5: Dadas las notas de cuatro exámenes, mostrar la nota promedio.

#include <iostream>
using namespace std;

int main() {
   float n1, n2, n3, n4, promedio;

   cout << "Ingrese la nota del primer examen: ";
   cin >> n1;
   cout << "Ingrese la nota del segundo examen: ";
   cin >> n2;
   cout << "Ingrese la nota del tercer examen: ";
   cin >> n3;
   cout << "Ingrese la nota del cuarto examen: ";
   cin >> n4;

   promedio = (n1 + n2 + n3 + n4) / 4;

   cout << "El promedio de las notas es: " << promedio << endl;

   return 0;
}
