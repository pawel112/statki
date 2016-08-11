//Autor: Pawe� Roszatycki

//za��czanie bibliotek
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

//za��czanie w�asnych plik�w
#include "zapis_odczyt.h"
#include "ustawienia.h"
#include "menu.h"
#include "gra.h"

int main ()
{
	//umo�liwienie losowania liczb
	srand( (unsigned) time(NULL));

	//wczytanie ustawie�
	wczytaj_ustawienia();

	//wczytywanie stanu gry
	int kontynulacja_gry = 0;
	if (czy_jest_plik_z_stanem_gry() == 1)
	{
		kontynulacja_gry = 1;
	}

	//zmiana kodowania znak�w, w celu poprawnego wy�wietlania wszystkich liter u�ywanych w polskim alfabecie
	setlocale(LC_ALL, "polish");

	//wywo�ywanie menu
	menu (kontynulacja_gry);

	system ("pause");
	return 0;
};