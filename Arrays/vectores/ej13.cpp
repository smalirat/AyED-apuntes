#include <iostream>
using namespace std;
struct Alumno {
    int nota;
    string nombre;
};
int condicion(Alumno alum[], int aprobado){
    int aprueba=1,promociona=2,recursa=3;
    int i=0;
    if(alum[i].nota < 6){
        aprobado = recursa;
    }
    else if (alum[i].nota < 8){
        aprobado = aprueba;
    }
        else {
            aprobado = promociona;
        }
    return aprobado;
}
int main(){
    int v=0,n;
    int resultado,condi;
    cout<<"Ingrese cant de alumnos: ";
    cin>>n;
   Alumno alumnos [n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la nota: ";
        cin >> alumnos[i].nota;
        
        cout << "Ingrese el nombre del alumno: ";
        cin >> alumnos[i].nombre;
        v++;
    }
    for (int i = 0; i < n; i++) {
        cout << "Nombre: " << alumnos[i].nombre << ", Nota: " << alumnos[i].nota;
        condi = condicion(alumnos, resultado);
        if(condi == 1){
            cout<<", FINAL"<<endl;
        }
        else if (condi == 2){
            cout<<", PROMOCIONA"<<endl;
        }
            else {
                cout<<", RECURSA"<<endl;
            }
        
    }
return 0;
}

