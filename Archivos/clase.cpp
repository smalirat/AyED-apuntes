#include <iostream>
#include <string.h>

using namespace std;

int main()
{
   char nombre[21],palabra[5]="Casa";
   char nom[5]="Jose";

   //cin nombre;
   cin.getline(nombre,20);
   cout<<nombre<<endl;


   if(strcmp(palabra, nom)==0)//comparar cadenas
        cout<<"="<<endl;
    else
        cout<<"No="<<endl;
    
    if(strcmpi("ala","ALa")==0)//comparar sin mayusc
        cout<<"="<<endl;

    //strcat(nom," Perez"); //unir cadenas
    cout<<nom<<endl;
    
    cout<<strlen(palabra);






    return 0;
}