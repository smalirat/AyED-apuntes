#include <iostream>

using namespace std;


/*int secuencial(int v[], int t, int bus) {
    int i = 0;
    while (i < t && v[i] != bus)
        i++;
    if (i == t)
        return -1;
    else
        return i;
}*/

int binaria (int v[], int t, int bus){
  int pos = -1, desde = 0, hasta = t - 1, medio;
  while (desde <= hasta && pos == -1)
    {
      medio = (desde + hasta) / 2;
      if (v[medio] == bus)
	pos = medio;
      else
	{
	  if (bus < v[medio])
	    hasta = medio - 1;
	  else
	    desde = medio + 1;
	}
    }
  return pos;
}

void burbujeo (int v[], int v2[], int n){
  int i = 1, j, aux,aux2;
  bool cambio;
  do
    {
      cambio = false;
      for (j = 0; j < n - i; j++)
	{
	  if (v[j] > v[j + 1])
	    {
	      aux = v[j];
	      v[j] = v[j + 1];
	      v[j + 1] = aux;

          aux2 = v2[j];
	      v2[j] = v2[j + 1];
	      v2[j + 1] = aux2;

	      cambio = true;
	    }
	}
      i++;
    }
  while (i < n && cambio);
}



int main (){
    
    int tam = 3;
    int codigo[tam], asientos[tam], asientos_vendidos[tam];
    int cod_avion,pasajes;
    unsigned dni;
    string nombre;

    for(int i=0; i<3; i++){
        cout<<"Codigo de vuelo: ";
        cin>>codigo[i];
        cout<<"Asientos disponibles: ";
        cin>>asientos[i];
        asientos_vendidos[i]= 0;

    }

    burbujeo(codigo,asientos,tam);


    cout<<"Hola pasajero, Codigo de vuelo: ";
    cin>>cod_avion;

    while(cod_avion!=0){
        cout<<"Cantidad de pasajes a comprar: ";
        cin>>pasajes;
        cout<<"DNI: ";
        cin>>dni;
        cout<<"Nombre: ";
        cin>>nombre;

        int pos = binaria(codigo, tam, cod_avion);

        asientos[pos]-=pasajes;
        asientos_vendidos[pos] += pasajes;


        /* cout << "TICKET" << endl;
        cout << "DNI: " << dni << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Cantidad de pasajes: " << pasajes << endl;
        cout << "Código de vuelo: " << cod_avion << endl; */

        cout<<"Hola pasajero, Codigo de vuelo: ";
        cin>>cod_avion; 


    }

    for(int i=0; i<3; i++){
        cout<<"El vuelo "<<codigo[i]<<" tiene "<<asientos[i]<<" asientos disponibles"<<" asientos vendidos: "<<asientos_vendidos[i]<<endl;
    }




    return 0;




}