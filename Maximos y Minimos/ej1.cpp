#include <iostream>

using namespace std;

int main()
{
    int i;
    float mayor,n;


    cin>>mayor;
    for (i = 1; i <= 5; i++) {
        cin >> n;
        while (n > mayor) {
            mayor = n;
        }
    }
    cout<<mayor<<" es el mayor";
    return 0;

}
