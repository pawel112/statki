#include "zapis_odczyt.h"
#include "gra.h"
#include "ustawienia.h"
#include <iostream>

extern gracz gracz_1;
extern gracz2 gracz_2;

void zapis (void)
{
	//gracz 1
	FILE* plik6 = NULL;

	//gracz 1
	fopen_s (&plik6, "zapis_gry.cfg", "w+");
	fprintf (plik6, "gracz 1\nteraz_ruch = ");
	fprintf (plik6, "%d", gracz_1.teraz_ruch);
	fprintf (plik6, "\nstatki\n");
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
		{
			fprintf (plik6, "statki[%d][%d] = ",i,j);
			fprintf (plik6, "%d", gracz_1.statki[i][j]);
			fprintf (plik6, "\n");
		}
	}
	fprintf (plik6, "atak\n");
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
		{
			fprintf (plik6, "atak[%d][%d] = ",i,j);
			fprintf (plik6, "%d", gracz_1.atak[i][j]);
			fprintf (plik6, "\n");
		}
	}
	fprintf (plik6, "ilosc_statkow_w_grze = ");
	fprintf (plik6, "%d", gracz_1.ilosc_statkow_w_grze);
	fprintf (plik6, "\n");

	//gracz 2
	fprintf (plik6, "gracz 2\nteraz_ruch = ");
	fprintf (plik6, "%d", gracz_2.teraz_ruch);
	fprintf (plik6, "\nstatki\n");
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
		{
			fprintf (plik6, "statki[%d][%d] = ",i,j);
			fprintf (plik6, "%d", gracz_2.statki[i][j]);
			fprintf (plik6, "\n");
		}
	}
	fprintf (plik6, "atak\n");
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
		{
			fprintf (plik6, "atak[%d][%d] = ",i,j);
			fprintf (plik6, "%d", gracz_2.atak[i][j]);
			fprintf (plik6, "\n");
		}
	}
	fprintf (plik6, "ilosc_statkow_w_grze = ");
	fprintf (plik6, "%d", gracz_2.ilosc_statkow_w_grze);
	fprintf (plik6, "\n");

	fprintf (plik6, "czy_komputer = ");
	fprintf (plik6, "%d", gracz_2.czy_komputer);
	fprintf (plik6, "\n");

	fprintf (plik6, "poziom_trudnosci = ");
	fprintf (plik6, "%d", gracz_2.poziom_trudnosci);

	fclose(plik6);
};

void odczyt (void)
{
	if (czy_jest_plik_z_stanem_gry() == 1)
	{
		//przygotowanie do gry
		gracz_1.zeruj();
		gracz_1.teraz_ruch = 0;
		gracz_1.ilosc_statkow_w_grze = 0;

		gracz_2.zeruj();
		gracz_2.teraz_ruch = 0;
		gracz_2.ilosc_statkow_w_grze = 0;
		gracz_2.czy_komputer = 0;
		gracz_2.poziom_trudnosci = 0;
		
		FILE* plik6 = NULL;

		//gracz 1
		fopen_s (&plik6, "zapis_gry.cfg", "r");
		fscanf_s (plik6, "gracz 1\nteraz_ruch = ");
		fscanf_s (plik6, "%d", &gracz_1.teraz_ruch);
		fscanf_s (plik6, "\nstatki\n");
		for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
		{
			for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
			{
				fscanf_s (plik6, "statki[%d][%d] = ");
				fscanf_s (plik6, "%d", &gracz_1.statki[i][j]);
				fscanf_s (plik6, "\n");
			}
		}
		fscanf_s (plik6, "atak\n");
		for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
		{
			for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
			{
				fscanf_s (plik6, "atak[%d][%d] = ");
				fscanf_s (plik6, "%d", &gracz_1.atak[i][j]);
				fscanf_s (plik6, "\n");
			}
		}
		fscanf_s (plik6, "ilosc_statkow_w_grze = ");
		fscanf_s (plik6, "%d", &gracz_1.ilosc_statkow_w_grze);
		fscanf_s (plik6, "\n");

		//gracz 2
		fscanf_s (plik6, "gracz 2\nteraz_ruch = ");
		fscanf_s (plik6, "%d", &gracz_2.teraz_ruch);
		fscanf_s (plik6, "\nstatki\n");
		for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
		{
			for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
			{
				fscanf_s (plik6, "statki[%d][%d] = ");
				fscanf_s (plik6, "%d", &gracz_2.statki[i][j]);
				fscanf_s (plik6, "\n");
			}
		}
		fscanf_s (plik6, "atak\n");
		for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
		{
			for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
			{
				fscanf_s (plik6, "atak[%d][%d] = ");
				fscanf_s (plik6, "%d", &gracz_2.atak[i][j]);
				fscanf_s (plik6, "\n");
			}
		}
		fscanf_s (plik6, "ilosc_statkow_w_grze = ");
		fscanf_s (plik6, "%d", &gracz_2.ilosc_statkow_w_grze);
		fscanf_s (plik6, "\n");

		fscanf_s (plik6, "czy_komputer = ");
		fscanf_s (plik6, "%d", &gracz_2.czy_komputer);
		fscanf_s (plik6, "\n");

		fscanf_s (plik6, "poziom_trudnosci = ");
		fscanf_s (plik6, "%d", &gracz_2.poziom_trudnosci);

		fclose(plik6);
	}
};

int czy_jest_plik_z_stanem_gry (void)
{
	FILE* plik4 = NULL;
	char test[1] = "";
	fopen_s (&plik4, "zapis_gry.cfg", "r");
	if (plik4 == NULL)
	{
		//brak pliku
		return 0;
	}
	else if (fscanf_s (plik4,"%c",test) == -1) //sprawdzenie czy plik jest pusty
	{
		//pusty plik
		fclose(plik4);
		return 2;
	}
	else
	{
		//niepusty plik
		rewind(plik4); //ponownie wczytuje plik od poczatku
		fclose(plik4);
		return 1;
	}
};