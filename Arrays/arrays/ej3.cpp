#include <iostream>

using namespace std;

int secuencial(string v[], int t, string bus) {
    for (int i = 0; i < t; i++) {
        if (v[i] == bus) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Número de vehículos: ";
    cin >> n;

    string patente[n];
    int vecSuma[n];
    

    for (int i = 0; i < n; i++) {
        cout << "Patente del vehículo " << i + 1 << ": ";
        cin >> patente[i];
        vecSuma[i]=0;
        
    }

    int pagosXmes[n][13]; //agrego el mes 0 para que el mes sea igual a su posicion, y encima voy a imprimir los meses que no tengan de valor 0

    for (int i = 0; i < n; i++) {

        for(int h=0; h<13;h++){
            pagosXmes[i][h]=h;

        }
        
        
    }

    
    


    int mes;
    cout << "Mes abonado: ";
    cin >> mes;

    while (mes > 0 && mes < 13) {
        string patente_abonada;
        int importe_xvehiculo;
        cout << "Patente: ";
        cin >> patente_abonada;
        cout << "Importe abonado: ";
        cin >> importe_xvehiculo;



        int pos = secuencial(patente, n, patente_abonada);

        pagosXmes[pos][mes]=0;


        
        if (pos != -1) {
            vecSuma[pos] += importe_xvehiculo;
        } else {
            cout << "Patente no encontrada." << endl;
        }

        cout << "Mes abonado: ";
        cin >> mes;
    }

    for (int j = 0; j < n; j++) {
        cout << "Patente: " << patente[j] << " - Importe total: " << vecSuma[j] << endl;
    }

     for (int k = 0; k < n; k++) {
        cout << "Patente: " << patente[k] << " - Meses adeudados: " ;
        for(int l=0;l<13;l++){
            if (pagosXmes[k][l]!=0){
                cout<<pagosXmes[k][l]<<" ";
            }
        }
    }



    return 0;
}
