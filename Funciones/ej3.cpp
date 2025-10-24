#include <iostream>

using namespace std;


bool multiplo(int a, int b);




int main()
{
   int multi,a,b;


   cout<<"Ingrese un numero: ";
   cin>>a;
   cout<<"Ingrese un numero: ";
   cin>>b;

   multi = multiplo(a, b);

   if (multi=true){
   cout<<"a es multiplo de b ";
   }
   else 
   cout<<"a no es multiplo de b";

   return 0;


}


bool multiplo(int a, int b) {
    
    if (a%b != 0) {
       return true;
    }
    else{
        return false;
    }
}