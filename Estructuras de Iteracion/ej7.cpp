/*Ingresar la cantidad de alumnos de un curso. Ingresar por cada alumno el nombre y una nota. 
Por cada alumno informar su nombre y si está aprobado o desaprobado. 
Informar también el porcentaje de alumnos aprobados y la cantidad de desaprobados. 
*/

#include <iostream>

using namespace std;

int main(){

    int apr=0,alumnos,i,desapr=0;
    string nombre;
    float nota;

    cout<<"Informar la cantidad de alumnos: ";
    cin>>alumnos;

    for (i = 1; i <= alumnos; i++){
        
        cout<<endl<<"Nombre: ";
        cin>>nombre;
        cout<<"Nota: ";
        cin>>nota;

        if(nota>=6){
            cout<<endl<<nombre<<": APROBADO";
            apr++;
        }
        else{
            cout<<endl<<nombre<<": DESAPROBADO";
            desapr++;
        }
        
    
    }
    
    cout<<endl<<"Hay un "<<apr*100/alumnos<<" % de aprobados";
    cout<<endl<<"Hay "<<desapr<<" alumnos desaprobados";
    
    return 0;
}