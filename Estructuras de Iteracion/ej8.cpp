#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
  int i, miles, centenas, decenas, unidades, numero, cent2, dec2;
  cout << "Ingrese un numero entre 1 y 3999" << endl;
  cin >> numero;
  miles = numero / 1000;
  centenas = (numero / 100) % 10;
  decenas = (numero / 10) % 10;
  unidades = numero % 10;

  cout << "El numero en romano es: ";

  for (i = 0; i < miles; i++)
    {
      cout << "M";
    }

  if (centenas >= 5)
    {
      cout << "D";
      cent2 = centenas - 5;
      for (i = 0; i < cent2; i++)
	{
	  cout << "C";
	}
    }
  else
    {
      for (i = 0; i < centenas; i++)
	{
	  cout << "C";
	}
    }


  if (decenas >= 5)
    {
      cout << "L";
      dec2 = decenas - 5;
      for (i = 0; i < dec2; i++)
	{
	  cout << "X";
	}
    }
  else
    {
      for (i = 0; i < decenas; i++)
	{
	  cout << "X";
	}
    }
  switch (unidades)
    {
    case 1:
      cout << "I";
      break;
    case 2:
      cout << "II";
      break;
    case 3:
      cout << "III";
      break;
    case 4:
      cout << "IV";
      break;
    case 5:
      cout << "V";
      break;
    case 6:
      cout << "VI";
      break;
    case 7:
      cout << "VII";
      break;
    case 8:
      cout << "VIII";
      break;
    case 9:
      cout << "IX";
      break;
    default:
      break;
    }
  return 0;
}