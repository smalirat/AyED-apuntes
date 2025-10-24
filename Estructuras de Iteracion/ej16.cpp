#include <iostream>
using namespace std;

int main() {
    unsigned factorial=1;
    int n;



    for (int i = 1;; i++) {
        cout << "Ingrese un numero. Pulse 0 para finalizar el programa: ";
        cin >> n;

        if (n == 0) {
            break; 
        }
        else {
            for (int i = 1; i <= n; i++){
            factorial *= i;
            }
    
            cout<<"El factorial de "<<n<<" es: "<<factorial<<endl;
        }

        factorial = 1;
       

    }


    return 0;

}
   