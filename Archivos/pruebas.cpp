#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char nombre[21], palabra[5] = "Casa";
    char nom[5] = "Casa";

    cout << strcmp(palabra, nom);

    return 0;
}