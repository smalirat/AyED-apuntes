#include <iostream>

using namespace std;

void funcion_fecha(unsigned fecha, unsigned &mes, unsigned &dia, unsigned &año) {
    

    año = fecha/10000;
    mes = (fecha%10000)/100;
    dia = fecha%100;
}
int grupo_etario(unsigned edad) {
   if (edad > 63) {
        return 8;
    } else if (edad > 49) {
        return 7;
    } else if (edad > 42) {
        return 6;
    } else if (edad > 35) {
        return 5;
    } else if (edad > 28) {
        return 4;
    } else if (edad > 21) {
        return 3;
    } else if (edad > 15) {
        return 2;
    } else {
        return 1;
    }
}


int main(){
    unsigned fecha,dia,mes,año;
    char sexo;
    int grupo,g1=0,g2=0,g3=0,g4=0,g5=0,g6=0,g7=0,g8=0,octubre=0,julio=0,primavera=0;

    cout<<"Introdcuir fecha de nacimiento en el formato AAAAMMDD (Fecha 0 para finalizar): ";
    cin>>fecha;
    cout<<"Sexo ('M'/'F')";
    cin>>sexo;

    funcion_fecha(fecha,  mes,  dia,  año);

    while(fecha!=0)

    if(mes==10){
        octubre++;
    }

    if(fecha<19900709){
        julio++;
    }

    if(fecha<19821222 && fecha>19820923){
        primavera++;
    }



    grupo = grupo_etario(año);
    switch(grupo){
        case 1:
            g1++;
            break;
         case 2:
            g2++;
            break;
         case 3:
            g3++;
            break;
        case 4:
            g4++;
            break;
        case 5:
            g5++;
            break;
        case 6:
            g6++;
            break;
        case 7:
            g7++;
            break;
        case 8:
            g8++;
            break;
     }





    return 0;
}