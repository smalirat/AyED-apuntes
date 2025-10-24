#include <iostream>
using namespace std;

int main() {
    int a=0,b=0,c=0,d=0,e=0;
    int n;



    for (int i = 1;; i++) {
        cout << "Ingrese una edad entre 18 y 22. Pulse 0 para finalizar el programa: ";
        cin >> n;

        if (n == 0) {
            break; 
        }
        else {
            switch (n) {
                case 18:
                    a++;
                    break;
                case 19:
                    b++;
                    break;
                case 20:
                    c++;
                    break;
                case 21:
                    d++;
                    break;
                case 22:
                    e++;
                    break;
                default:
                    cout << "Edad invalida. Ingrese una edad entre 18 y 22." << endl;
                    continue;
            }
           
        }

        cout<<"Se ingreso "<<a<<" veces 18"<<endl;
        cout<<"Se ingreso "<<b<<" veces 19"<<endl;
        cout<<"Se ingreso "<<c<<" veces 20"<<endl;
        cout<<"Se ingreso "<<d<<" veces 21"<<endl;
        cout<<"Se ingreso "<<e<<" veces 22"<<endl;


    }

   
    
    return 0;
}
