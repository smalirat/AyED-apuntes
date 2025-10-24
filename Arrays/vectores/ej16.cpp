#include <iostream>
using namespace std;

struct Producto {
    int rubro,producto;
    string descripcion;
    
};
struct Rubro
{
	int cantidad;
	int codigoRubro;
};

int cantRubros(Producto vProd[], int &c, int rubro)
{
	int aux=rubro, i=0;
	
	do
	{
		c++;
		i++;
	}while(vProd[c].rubro==aux);
	
	return i;
}

Producto ingreso(){
	Producto ps;
	
	cout<<"Ingrese codigo rubro:"<<endl;
	cin>>ps.rubro;
	cout<<"Ingrese codigo del producto:"<<endl;
	cin>>ps.producto;
	cout<<"Ingrese descripcion:"<<endl;
	cin>>ps.descripcion;
	
	return ps;
}

void mostrar(Rubro v[], int j)
{
	for(int i=0; i<j-1; i++)
	{
		cout<<"Rubro: "<<v[i+1].codigoRubro<<"    cantidad: "<<v[i+1].cantidad<<endl;
	}
}



void ordenar(Producto v1[],int n)
{
	Producto aux;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(v1[j].rubro<v1[j+1].rubro)
			{
				aux=v1[j];
				v1[j]=v1[j+1];
				v1[j+1]=aux;
			}
		}
	}
}


int main(){
    Producto vecproduc[10];
    Rubro vec[10];
    int tam=0,i=0,j=0,cont=0;

   do{
        vecproduc[i]=ingreso();;
        i++;
        tam++;
   }while(vecproduc[i-1].rubro !=0);
   ordenar(vecproduc, tam);
   do
	{
		vec[j].codigoRubro=vecproduc[cont].rubro;
		vec[j].cantidad=cantRubros(vecproduc, cont, vec[j].codigoRubro);
		j++;
	}while(cont<tam);
    mostrar(vec, j);
	
	return 0;
}



  
