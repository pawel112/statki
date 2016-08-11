#ifndef ustawienia_h
#define ustawienia_h

#include <iostream>  //mo¿liwoœæ u¿ycia plików w deklaracji funkcji

class ustawienia
{
public:
	int wielkosc_planszy_x;
	int wielkosc_planszy_y;
	int powtarzanie_ruchu_w_przypadku_trafienia;
	int ilosc_statkow_5;
	int ilosc_statkow_4;
	int ilosc_statkow_3;
	int ilosc_statkow_2;
	int ilosc_statkow_1;

	//metody
	void zapis_ustawien (void); //zapis ustawien do pliku
	void pobierz_ustawienia (FILE* plik_temp); //ustawia domyœlne ustawienia
	void ustawienia_domyslne (FILE* plik_temp); //pobiera ustawienia z pliku ustawienia.cfg
	void sprawdz_ustawienia (FILE* plik_temp); //sprawdza poprawnosc ustawien
};

void wczytaj_ustawienia (void);

#endif