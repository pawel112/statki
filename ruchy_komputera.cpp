#include "gra.h"
#include "menu.h"
#include "ruchy_komputera.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

gracz gracz_1;
gracz2 gracz_2;

void losuj_latwy (int &wspolrzedna_y_temp, int &wspolrzedna_x_temp)
{
	wspolrzedna_y_temp = rand()%obiekt_ustawienia.wielkosc_planszy_y+1; //wspó³rzêdna y
	wspolrzedna_x_temp = rand()%obiekt_ustawienia.wielkosc_planszy_x+1; //wspó³rzêdna x
}

void losuj_sredni (int &wspolrzedna_y_temp, int &wspolrzedna_x_temp)
{
	//strategia komputera: strzelaæ w miejsce, w którym jest statek gracza, aby gracz mia³ jakiekolwiek szanse, komputer czasami pud³uje, lecz czêœciej pud³uje ni¿ na trudnym poziomie
	int liczba = rand()%6; //losowanie liczb: od 0 do 5
	if (liczba == 0)
	{
		//komputer strzela w pole, na którym znajduje siê statek gracza
		for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
		{
			for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
			{
				if (gracz_1.statki[i][j] == 1)
				{
					wspolrzedna_y_temp = i; //wspó³rzêdna y
					wspolrzedna_x_temp = j; //wspó³rzêdna x
					break;
				}
			}
		}
	}
	else
	{
		//komputer strzela w losowe pole
		wspolrzedna_y_temp = rand()%obiekt_ustawienia.wielkosc_planszy_y+1; //wspó³rzêdna y
		wspolrzedna_x_temp = rand()%obiekt_ustawienia.wielkosc_planszy_x+1; //wspó³rzêdna x
	}
};

void losuj_trudny (int &wspolrzedna_y_temp, int &wspolrzedna_x_temp)
{
	//strategia komputera: strzelaæ w miejsce, w którym jest statek gracza, aby gracz mia³ jakiekolwiek szanse, komputer mo¿e czasami spud³owaæ
	int liczba = rand()%3; //losowanie liczb: 0, 1 i 2
	if (liczba == 2)
	{
		//komputer strzela w pole, na którym znajduje siê statek gracza
		for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
		{
			for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
			{
				if (gracz_1.statki[i][j] == 1)
				{
					wspolrzedna_y_temp = i; //wspó³rzêdna y
					wspolrzedna_x_temp = j; //wspó³rzêdna x
					break;
				}
			}
		}
	}
	else
	{
		//komputer strzela w losowe pole
		wspolrzedna_y_temp = rand()%obiekt_ustawienia.wielkosc_planszy_y+1; //wspó³rzêdna y
		wspolrzedna_x_temp = rand()%obiekt_ustawienia.wielkosc_planszy_x+1; //wspó³rzêdna x
	}
};