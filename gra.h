#ifndef gra_h
#define gra_h

//maksymalna wielkosc planszy to 100
const int maks = 100;

//za³¹czanie obiektu z ustawieniami
#include "ustawienia.h"
extern ustawienia obiekt_ustawienia;

//gracz 1
class gracz
{
public:
	int teraz_ruch;
    int statki[maks][maks];
	int atak[maks][maks];
	int ilosc_statkow_w_grze;

//metody
public:
	void zeruj (void);
	void wypisz (bool czy_atak);
	void rozmiesc_statki (bool czy_komputer_temp);
	void dodaj_statek (int dlugosc_statku_temp, int licznik_temp, bool czy_komputer_temp);
	virtual void wypisz_nazwe_gracza (void);
	bool czy_moze_byc_tu_statek (int statek_poczatek_y_temp, int statek_poczatek_x_temp, int statek_koniec_y_temp, int statek_koniec_x_temp, int dlugosc_statku, bool czy_komputer_temp);
	int atakuj (int wysokosc_temp, int szerokosc_temp);
	int atakowany (int wysokosc_temp, int szerokosc_temp);
	int odpowiedz (int wysokosc_temp, int szerokosc_temp, int odpowiedz_temp);
	int dlugosc_statku (int wysokosc_temp, int szerokosc_temp, int czy_atak, int czy_zaznaczanie_zatopien);
};

//gracz 2
class gracz2: public gracz
{
public:
	int czy_komputer;
	int poziom_trudnosci;
	virtual void wypisz_nazwe_gracza (void);
};

#endif