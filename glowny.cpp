//Autor: Pawe³ Roszatycki

//za³¹czanie bibliotek
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

//za³¹czanie w³asnych plików
#include "zapis_odczyt.h"
#include "ustawienia.h"
#include "menu.h"
#include "gra.h"

int main ()
{
	//umo¿liwienie losowania liczb
	srand( (unsigned) time(NULL));

	//wczytanie ustawieñ
	wczytaj_ustawienia();

	//wczytywanie stanu gry
	int kontynulacja_gry = 0;
	if (czy_jest_plik_z_stanem_gry() == 1)
	{
		kontynulacja_gry = 1;
	}

	//zmiana kodowania znaków, w celu poprawnego wyœwietlania wszystkich liter u¿ywanych w polskim alfabecie
	setlocale(LC_ALL, "polish");

	//wywo³ywanie menu
	menu (kontynulacja_gry);

	system ("pause");
	return 0;
};