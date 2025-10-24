/* En un torneo de fútbol participan K equipos. El torneo se juega con el sistema de todos contra todos. 
Por cada partido disputado por un equipo se dispone de la siguiente información : 
a) Nombre del equipo, b) Código del resultado ('P'= Perdido, 'E'= Empatado, 'G'= Ganado). 
Se arma un lote de datos con todos los resultados del torneo, agrupados por nombre del equipo. 
Desarrollar el programa que imprima: Por cada equipo, su nombre y el puntaje total que obtuvo (suma 3 si gana, y 1 si empata).
*/

#include <iostream>

using namespace std;

int main(){

    int equipos,partidos,alumnos,i,j,puntaje=0;
    string nombre;
    char resultado;

    cout<<"Cantidad de equipos ";
    cin>>equipos;

    partidos = equipos - 1;

    for (i = 1; i <= equipos; i++){
        
        cout<<endl<<"Nombre: ";
        cin>>nombre;

        puntaje=0;

        for (j=1; j<=partidos;j++){
            cout<<"Resultado del partido "<<j<<"(G/E/P): "<<endl;
            cin>>resultado;

            switch(resultado) {
                case('G'):
                    puntaje += 3;
                    break;
                case('E'):
                    puntaje += 1;
                    break;
                case('P'):
                    break;
                default:
                    cout<<"Codigo de resultado invalido";
                    break;
            }
        }

        cout<<"El puntaje de "<<nombre<<" es de: "<<puntaje;


    }
    return 0;
}
