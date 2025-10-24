/*Confeccionar un programa que pueda determinar el importe a pagar por una prestación médica según su código. 
Los importes se cobran según la siguiente tabla : 
Código Importe $ 
A 200 D 400
F 600 M 1500
T 15000
Por cada prestación se debe ingresar el número de historia del paciente y el código de la prestación. Se debe emitir un ticket para cada uno, con el número de la historia, el código y el importe a pagar.
*/

#include <iostream>
using namespace std;

int main(){
    char codigo,mayusc;
    int cantidad,importe;
    float nro_hist_paciente;

    cout<<"Ingrese el código de la prestacion medica (A,D,F,M,T): ";
    cin>>codigo;

    cout<<"Ingrese su número de historia clínica ";
    cin>>nro_hist_paciente;

   

    switch (codigo) {
        case 'T':
        case 't':
            importe = 15000;
            mayusc = 'T';
            break;
        case 'M':
        case 'm':
            importe = 1500;
            mayusc = 'M';
            break;
        case 'F':
        case 'f':
            importe = 600;
            mayusc = 'F';
            break;
        case 'D':
        case 'd':
            importe = 400;
            mayusc = 'D';
            break; 
        case 'A':
        case 'a':
            importe = 200;
            mayusc = 'S';
            break;
        default:
            cout<<"Codigo de la prestación INVALIDO";
            return 0;
    }

    cout<<"TICKET CLINICA MEDICA:"<<endl;
    cout<<"Historia clinica: "<<nro_hist_paciente<<endl;
    cout<<"Código de la prestación: "<<mayusc<<endl;
    cout<<"El importe es de "<<importe<<" $";


    return 0;
}