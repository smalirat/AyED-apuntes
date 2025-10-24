#include <iostream>

using namespace std;

int main()
{
    int i,integrantes,edad,primario=0,secundario=0,integrantes_familia;
    float edad_familia=0,suma=0,suma2=0,promedio_familia,mayor=0,personas=0,analfabeto=0,promedio,mujer=0,porcentaje,terciario=0;
    string domicilio,nombre,familia_grande;
    char vivienda,sexo,estudios,completo;

    cout<<"Ingrese cantidad de integrantes: ";
    cin>>integrantes;
    mayor = integrantes;

    while(integrantes!=0){


        

        cout<<"domicilio: ";
        cin>>domicilio;
        cout<<"vivienda (‘C’: casa, ‘D’: departamento): ";
        cin>>vivienda;
        
        
        for(i=1;i<=integrantes;i++){

        cout<<"nombre y apellido: ";
        cin>>nombre;
        cout<<"edad: ";
        cin>>edad;

        personas++;
        suma+=edad;
        suma2+=edad;

        cout<<"sexo (‘F’, ‘M’): ";
        cin>>sexo;


        cout<<"estudio alcanzado (N/P/S/T): ";
        cin>>estudios;
        cout<<"Completo o Incompleto (C/I); ";
        cin>>completo;

        switch (estudios)
        {
        case 'N':
        case 'n':
            if(edad>10){
            analfabeto++;}
            break;
        case 'P':
        case 'p':
            if(completo == 'C'){
            primario++;}
            break;
        case 'S':
        case 's':
            primario++;
            if(completo == 'I'){
            secundario++;}
            break;
        case 'T':
        case 't':
            primario++;
            if(sexo == 'F'){
            terciario++;}
            break;
        default:
            break;
        }

        
        promedio_familia = suma2/integrantes;


        if (vivienda == 'D' && integrantes > mayor) {
            mayor = integrantes;
            familia_grande = domicilio;
        }



        }


        


        if (promedio_familia>edad_familia){
            edad_familia=promedio_familia;
        }


        
        if(sexo=='F'){
            mujer++;
        }

    suma2 = 0;

    cout<<"Ingrese cantidad de integrantes de una nueva familia: ";
    cin>>integrantes;
    mayor = integrantes;


    }
    

    promedio = suma/personas;
    porcentaje = mujer/terciario*100.000;

    cout<<"Completaron el primario: "<<primario<<endl;
    cout<<"Analfabetos: "<<analfabeto<<endl;
    cout<<"Lugar familia con mas integrantes: "<<familia_grande<<endl;
    cout<<"Edad promedio: "<<promedio<<endl;
    cout<<"la mayor edad promedio: "<<edad_familia<<endl;
    cout<<"Secundarios incompletos: "<<secundario<<endl;
    cout<<"% de mujeres que completaron el terciario: "<<porcentaje<<endl;
    



    return 0;

}