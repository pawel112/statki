#include "ustawienia.h"
#include <iostream>


//tworzenie obiektu z ustawieniami
ustawienia obiekt_ustawienia;

extern const int maks = 10;

void wczytaj_ustawienia (void)
{
	FILE* plik = NULL;
	FILE* plik2 = NULL;
	char test[1] = "";
	fopen_s (&plik, "ustawienia.cfg", "r");
	if (plik == NULL)
	{
		//brak pliku - zapis ustawieñ domyœlnych
		fopen_s (&plik2, "ustawienia.cfg", "w+");
		obiekt_ustawienia.ustawienia_domyslne (plik2);
	}
	else if (fscanf_s(plik,"%c",test) == -1) //sprawdzenie czy plik jest pusty
	{
		//pusty plik - zapis ustawieñ domyœlnych
		fclose(plik);
		fopen_s (&plik2, "ustawienia.cfg", "w+");
		obiekt_ustawienia.ustawienia_domyslne (plik2);
	}
	else
	{
		rewind(plik); //ponownie wczytuje plik od poczatku
		obiekt_ustawienia.pobierz_ustawienia (plik);
	}
};

void ustawienia::pobierz_ustawienia (FILE* plik_temp)
{
	//pobranie ustawieñ z pliku
	fscanf_s (plik_temp, "wielkosc_planszy_x = ");
	fscanf_s (plik_temp, "%d", &wielkosc_planszy_x);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "wielkosc_planszy_y = ");
	fscanf_s (plik_temp, "%d", &wielkosc_planszy_y);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "powtarzanie_ruchu_w_przypadku_trafienia = ");
	fscanf_s (plik_temp, "%d", &powtarzanie_ruchu_w_przypadku_trafienia);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "ilosc_statkow_5 = ");
	fscanf_s (plik_temp, "%d", &ilosc_statkow_5);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "ilosc_statkow_4 = ");
	fscanf_s (plik_temp, "%d", &ilosc_statkow_4);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "ilosc_statkow_3 = ");
	fscanf_s (plik_temp, "%d", &ilosc_statkow_3);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "ilosc_statkow_2 = ");
	fscanf_s (plik_temp, "%d", &ilosc_statkow_2);
	fscanf_s (plik_temp, "\n");

	fscanf_s (plik_temp, "ilosc_statkow_1 = ");
	fscanf_s (plik_temp, "%d", &ilosc_statkow_1);
	fscanf_s (plik_temp, "\n");

	fclose(plik_temp);
	sprawdz_ustawienia (plik_temp);

};

void ustawienia::ustawienia_domyslne (FILE* plik_temp)
{
	//ustawienie domyœlnych ustawieñ
	wielkosc_planszy_x = 10;
	wielkosc_planszy_y = 10;
	powtarzanie_ruchu_w_przypadku_trafienia = 1;
	ilosc_statkow_5 = 1;
	ilosc_statkow_4 = 1;
	ilosc_statkow_3 = 2;
	ilosc_statkow_2 = 3;
	ilosc_statkow_1 = 0;
	fprintf(plik_temp,"wielkosc_planszy_x = 10\nwielkosc_planszy_y = 10\npowtarzanie_ruchu_w_przypadku_trafienia = 0\nilosc_statkow_5 = 1\nilosc_statkow_4 = 1\nilosc_statkow_3 = 2\nilosc_statkow_2 = 3\nilosc_statkow_1 = 0\n");
	fclose(plik_temp);
};

void ustawienia::sprawdz_ustawienia (FILE* plik_temp)
{
	//sprawdza ustawienia i w przypadku b³êdów zastêpuje domyœlnymi
	int brak_zmian = 0;
	if ((wielkosc_planszy_x <= 0) || (wielkosc_planszy_x > maks))
	{
		wielkosc_planszy_x = 10;
		brak_zmian = 1;
	}

	if ((wielkosc_planszy_y <= 0) || (wielkosc_planszy_y > maks))
	{
		wielkosc_planszy_y = 10;
		brak_zmian = 1;
	}

	if ((powtarzanie_ruchu_w_przypadku_trafienia != 0) && (powtarzanie_ruchu_w_przypadku_trafienia != 1))
	{
		powtarzanie_ruchu_w_przypadku_trafienia = 1;
		brak_zmian = 1;
	}

	if ((ilosc_statkow_5 < 0) || (ilosc_statkow_5 > maks))
	{
		ilosc_statkow_5 = 1;
		brak_zmian = 1;
	}

	if ((ilosc_statkow_4 < 0) || (ilosc_statkow_4 > maks))
	{
		ilosc_statkow_4 = 1;
		brak_zmian = 1;
	}

	if ((ilosc_statkow_3 < 0) || (ilosc_statkow_3 > maks))
	{
		ilosc_statkow_3 = 2;
	}

	if ((ilosc_statkow_2 < 0) || (ilosc_statkow_2 > maks))
	{
		ilosc_statkow_2 = 3;
		brak_zmian = 1;
	}

	if ((ilosc_statkow_1 < 0) || (ilosc_statkow_1 > maks))
	{
		ilosc_statkow_1 = 0;
		brak_zmian = 1;
	}

	if (brak_zmian == 1)
	{
		zapis_ustawien ();
	}
};

void ustawienia::zapis_ustawien (void)
{
	FILE* plik3 = NULL;
	fopen_s (&plik3, "ustawienia.cfg", "w"); //plik zostanie ponownie utworzony

	//zapis ustawieñ do pliku
	fprintf (plik3, "wielkosc_planszy_x = %d\n", wielkosc_planszy_x);
	fprintf (plik3, "wielkosc_planszy_y = %d\n", wielkosc_planszy_y);
	fprintf (plik3, "powtarzanie_ruchu_w_przypadku_trafienia = %d\n", powtarzanie_ruchu_w_przypadku_trafienia);
	fprintf (plik3, "ilosc_statkow_5 = %d\n", ilosc_statkow_5);
	fprintf (plik3, "ilosc_statkow_4 = %d\n", ilosc_statkow_4);
	fprintf (plik3, "ilosc_statkow_3 = %d\n", ilosc_statkow_3);
	fprintf (plik3, "ilosc_statkow_2 = %d\n", ilosc_statkow_2);
	fprintf (plik3, "ilosc_statkow_1 = %d\n", ilosc_statkow_1);
	
	fclose (plik3);
};