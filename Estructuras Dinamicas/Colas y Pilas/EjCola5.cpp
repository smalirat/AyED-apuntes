#include <iostream>

using namespace std;

struct NodoC
{
    int dato;
    NodoC*sig;
};

void encolar(NodoC*&pri,NodoC*&ult,int nro);
void desencolar(NodoC*&pri,NodoC*&ult,int &nro);


bool Ej5(NodoC*&pri,NodoC*&ult)
{
    int nro,cont=0;
    while(pri!=NULL && cont<4)
    {
        desencolar(pri,ult,nro);
        cont++;
    }
    if(cont==4)
        return true;
    else
        return false;
    //return cont==4;
}
