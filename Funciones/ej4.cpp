/*Dada una serie de números enteros positivos que finalizan con cero, informar:
a) su factorial
b) cuantos múltiplos de 3
c) cuantos múltiplos de 5
d) cuantos múltiplos de 3 y de 5
Utilice las funciones de ejercicios anteriores.*/

#include <iostream>
using namespace std;

unsigned factorial(unsigned n) {
    unsigned result = 1;
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


bool multiplo3(int n);
bool multiplo5(int n);
bool multiplo3y5(int n);




int main() {
    unsigned factorial_n,n,tres,cinco,tresycinco,conttres=0,contcinco=0,conttresycinco=0;
    cout << "Ingrese un numero: ";
    cin >> n;

    while (n!=0){

    unsigned factorial_n = factorial(n);

    cout << "El factorial de " << n << " es " << factorial_n << endl;

    tres = multiplo3(n);
    cinco = multiplo5(n);
    tresycinco =multiplo3y5(n);

    if (tres==true){
    conttres++;
    }
    if (cinco==true){
    contcinco++;
    }
    if (tresycinco==true){
    conttresycinco++;
    }

    cout << "Ingrese otro numero: ";
    cin >> n;


    }

    cout << "Hay "<<conttres<<" multiplos de 3"<<endl;
    cout << "Hay "<<contcinco<<" multiplos de 5"<<endl;
    cout << "Hay "<<conttresycinco<<" multiplos de 3 y 5"<<endl;

    return 0;
}

bool multiplo3(int n) {
    
    if (n%3 == 0) {
       return true;
    }
    else{
        return false;
    }
}
bool multiplo5(int n) {
    
    if (n%5 == 0) {
       return true;
    }
    else{
        return false;
    }
}
bool multiplo3y5(int n) {
    
    if (n%3 == 0 && n%5 == 0) {
       return true;
    }
    else{
        return false;
    }
}