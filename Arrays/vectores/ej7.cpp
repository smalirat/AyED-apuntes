#include <iostream>

using namespace std;

void sumaNumeros(int veca[], int vecb[], int Num, int suma[]){
    int carry = 0;
    for (int i = Num - 1; i >= 0; i--) {
        int sum = veca[i] + vecb[i] + carry;
        suma[i + 1] = sum % 10;
        carry = sum / 10;
    }
}

void restaNumeros(int veca[], int vecb[], int Num, int resta[]) {
    int carry = 0;
    for (int i = Num - 1; i >= 0; i--) {
        int diff = veca[i] - vecb[i] - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        resta[i + 1] = diff;
    }
    resta[0] = carry;
}

void imprimirVector(const int vec[], int size) {
    for (int i = 0; i < size; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main(){
    int N,a,b;
    cout << "Ingrese un numero: ";
    cin>>N;

    int vA[N],vB[N],vSuma[N+1],vResta[N];
    cout << "Ingrese los digitos del vector A: ";
    for (int i = 0; i < N; i++) {
        cin >> vA[i];
    }
    cout << "Ingrese los digitos del vector B: ";
    for (int i = 0; i < N; i++) {
        cin >> vB[i];
    }

    sumaNumeros(vA, vB, N, vSuma);
    restaNumeros(vA, vB, N, vResta);

    cout << "Suma de los números: ";
    imprimirVector(vSuma, N + 1);

    cout << "Resta de los números: ";
    imprimirVector(vResta, N);

    return 0;
}

