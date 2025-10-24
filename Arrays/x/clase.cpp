#include <iostream>

using namespace std;


int ingresarDatos (int vl[],float vs[],int ce){


    int leg, i=0;

    cout<<"Legajo: ";
    cin>>leg;
    while(leg!= 0 && i<ce){
        vl[i]=leg;
        cout<<"Sueldo: ";
        cin>>vs[i];
        i++;
        cout<<"Legajo: ";
        cin>>leg;
        }
        return i;
}
void mostrarTodos(int vl[],float vs[],int c){



    cout<<endl<<"Listado de empleados"<<endl;





}
float maximo(float v[],int t){

    float m =v[0];
    for(int i=1;i<t;i++){
        if(v[i]>m){
            m=v[i];
        }
    }
    return m;   
}


int main()
{

    int legajos[10],cantEmpl;
    float sueldos[10], maxSueldo;
    cantEmpl=ingresarDatos(legajos,sueldos,10);

    if (cantEmpl!=0){

    }




    return 0;

}