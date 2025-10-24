
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Series
{
    int id;
    char titulo[30],genero[30];
};

int main()
{
    FILE *arch,*arch2;
    arch=fopen("Series.dat","wb");
    if(arch==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Series s;
        cout<<"Id (cero fin) ";
        cin>>s.id;
        while(s.id!=0)
        {
            cout<<"Titulo: ";
            cin>>s.titulo;
            cout<<"Genero: ";
            cin>>s.genero;

            
            fwrite(&s,sizeof(Series),1,arch);

            cout<<"id (cero fin) ";
            cin>>s.id;
        }
        fclose(arch);
    }

    arch2=fopen("NovSeries.dat","wb");
    if(arch2==NULL)
        cout<<"Error de creacion de archivo"<<endl;
    else
    {
        Series s;
        cout<<"Id nuevo (cero fin) ";
        cin>>s.id;
        while(s.id!=0)
        {
            cout<<"Titulo: ";
            cin>>s.titulo;
            cout<<"Genero: ";
            cin>>s.genero;

            
            fwrite(&s,sizeof(Series),1,arch);

            cout<<"id nuevo (cero fin) ";
            cin>>s.id;
        }
        fclose(arch);
    }


    return 0;
}
