#include <iostream>

using namespace std;


float suma(float a, float b){

    return a+b;
}
float resta(float a, float b){

    float diferencia;
    if (a>b){
        diferencia = a-b;
    }
    else{
        diferencia = b-a;
    }
    return diferencia;
}
float porcentaje(float a, float b){

    float porciento;
    if (a>b){
        porciento = b*100/a;
    }
    else{
        porciento = a*100/b;
    }
    return porciento;

}

int mcd(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

unsigned factorial(unsigned n) {
    unsigned result = 1;
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

float combinatoria(unsigned m, unsigned n){

    if (m<n){
    return factorial(m)/(factorial(n) * factorial(m-n));
    }
    else {
        return factorial(n)/(factorial(m) * factorial(n-m));
    }

}

int main()
{
   int opcion,maximo;
   float a,b,sum,res,por;
   unsigned fact;
   float comb;

   cout<<endl<<"Ingrese un numero: ";
   cin>>a;
   cout<<"Ingrese un numero: ";
   cin>>b;
   cout<<"Seleccione una opcion (0 para finalizar): "<<endl;
   cout << "1. Muestre la suma de los números." << endl;
   cout << "2. Muestre la resta del menor de los números al mayor." << endl;
   cout << "3. Muestre que porcentaje representa el menor de los números sobre el mayor." << endl;
   cout << "4. Muestre el máximo común divisor de ambos números." << endl;
   cout << "5. Muestre el número combinatorio del mayor de los números sobre el menor." << endl;
   cout << "6. Cambiar los números." << endl;
   cin>>opcion;


   while(opcion!=0){


   switch(opcion){
   case 1:
        sum=suma(a,b);
        cout<<"La suma es: "<<sum;
        break;
   case 2:
        res=resta(a,b);
        cout<<"La resta es: "<<res;
        break;
   case 3:
        por=porcentaje(a,b);
        cout<<"El porcentaje del menor sobre el mayor es: "<<por<<"%";
        break;
   case 4:
        maximo=mcd(a,b);
        cout<<"El mcd de sus enteros es: "<<maximo;
        break;
   case 5:
        comb=combinatoria(a,b);
        cout<<"La combinatoria del mayor sobre el menor es: "<<comb;
        break;
    case 6:
        break;
   default:
        cout<<"Numero inválido: ";
        break;
   }
   
   cout<<endl<<"Ingrese un numero: ";
   cin>>a;
   cout<<"Ingrese un numero: ";
   cin>>b;
   cout<<"Seleccione una opcion (0 para finalizar): "<<endl;
   cout << "1. Muestre la suma de los números." << endl;
   cout << "2. Muestre la resta del menor de los números al mayor." << endl;
   cout << "3. Muestre que porcentaje representa el menor de los números sobre el mayor." << endl;
   cout << "4. Muestre el máximo común divisor de ambos números." << endl;
   cout << "5. Muestre el número combinatorio del mayor de los números sobre el menor." << endl;
   cout << "6. Cambiar los números." << endl;
   cin>>opcion;




   }

   








   return 0;


}
