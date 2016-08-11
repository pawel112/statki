#include "ustawienia.h"
#include "gra.h"
#include "gra2.h"
#include "menu.h"
#include "ruchy_komputera.h"
#include "zapis_odczyt.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

extern gracz gracz_1;
extern gracz2 gracz_2;

void gracz::rozmiesc_statki (bool czy_komputer_temp)
{
	for (int i=0; i<obiekt_ustawienia.ilosc_statkow_5; i++)
	{
		dodaj_statek (5, i, czy_komputer_temp);
	}
	for (int i=0; i<obiekt_ustawienia.ilosc_statkow_4; i++)
	{
		dodaj_statek (4, i, czy_komputer_temp);
	}
	for (int i=0; i<obiekt_ustawienia.ilosc_statkow_3; i++)
	{
		dodaj_statek (3, i, czy_komputer_temp);
	}
	for (int i=0; i<obiekt_ustawienia.ilosc_statkow_2; i++)
	{
		dodaj_statek (2, i, czy_komputer_temp);
	}
	for (int i=0; i<obiekt_ustawienia.ilosc_statkow_1; i++)
	{
		dodaj_statek (1, i, czy_komputer_temp);
	}
};

void gracz::dodaj_statek (int dlugosc_statku_temp, int licznik_temp, bool czy_komputer_temp)
{
	for (int j=0; j<1; )
	{
		int statek_poczatek_y = 0;
		int statek_poczatek_x = 0;
		int statek_koniec_y = 0;
		int statek_koniec_x = 0;
		if (czy_komputer_temp == 0)
		{
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\n");
			wypisz(0);

			char p1[100] = "\nPodaj wspó³rzêdne pocz¹tkowego punktu dla ";
			char p2[100] = "";
			_itoa_s (licznik_temp+1, p2, 10);
			char p3[100] = "-go ";
			char p4[100] = "";
			_itoa_s (dlugosc_statku_temp, p4, 10);
			char p5[100] = "-cio czêœciowego statku:\n\n";
			strcat_s (p1, 50, p2);
			strcat_s (p1, 100, p3);
			strcat_s (p1, 100, p4);
			strcat_s (p1, 100, p5);
			tekst_wysrodkowany (p1);
			
			char statek_poczatek[4];
			//czyszczenie bufora klawiatury
			std::cin.clear();
			std::cin.sync();
			std::cin >> statek_poczatek;
			statek_poczatek_y = (toupper (statek_poczatek[0])-65); //uwzglêdnienie, mo¿liwoœci wpisania ma³ej litery przez u¿ytkownika
			statek_poczatek[0] = '0';
			statek_poczatek_x = atoi (statek_poczatek)-1;

			char k1[100] = "\nPodaj wspó³rzêdne koñcowego punktu dla ";
			strcat_s (k1, 50, p2);
			strcat_s (k1, 100, p3);
			strcat_s (k1, 50, p4);
			strcat_s (k1, 100, p5);
			tekst_wysrodkowany (k1);

			char statek_koniec[4];
			//czyszczenie bufora klawiatury
			std::cin.clear();
			std::cin.sync();
			std::cin >> statek_koniec;
			statek_koniec_y = (toupper (statek_koniec[0])-65); //uwzglêdnienie, mo¿liwoœci wpisania ma³ej litery przez u¿ytkownika
			statek_koniec[0] = '0';
			statek_koniec_x = atoi (statek_koniec)-1;
		}
		else
		{
			statek_poczatek_y = rand()%obiekt_ustawienia.wielkosc_planszy_y;
			statek_poczatek_x = rand()%obiekt_ustawienia.wielkosc_planszy_x;
			statek_koniec_y = rand()%obiekt_ustawienia.wielkosc_planszy_y;
			statek_koniec_x = rand()%obiekt_ustawienia.wielkosc_planszy_x;
		}

		if (czy_moze_byc_tu_statek (statek_poczatek_y, statek_poczatek_x, statek_koniec_y, statek_koniec_x, dlugosc_statku_temp, czy_komputer_temp) == 1)
		{
			j++;
			ilosc_statkow_w_grze = ilosc_statkow_w_grze + dlugosc_statku_temp;
		}
	}
};

bool gracz::czy_moze_byc_tu_statek (int statek_poczatek_y_temp, int statek_poczatek_x_temp, int statek_koniec_y_temp, int statek_koniec_x_temp, int dlugosc_statku_temp, bool czy_komputer_temp)
{
	//sprawdza czy wszystkie pola znajduj¹ siê na planszy
	if ((statek_poczatek_y_temp > -1) && (statek_poczatek_y_temp < obiekt_ustawienia.wielkosc_planszy_y) && (statek_poczatek_x_temp > -1) && (statek_poczatek_x_temp < obiekt_ustawienia.wielkosc_planszy_x) && (statek_koniec_y_temp > -1) && (statek_koniec_y_temp < obiekt_ustawienia.wielkosc_planszy_y) && (statek_koniec_x_temp > -1) && (statek_koniec_x_temp < obiekt_ustawienia.wielkosc_planszy_x))
	{
		//sprawdzanie czy u¿ytkownik nie poda³ pól na ukos
		int dlugosc_y = abs(statek_koniec_y_temp-statek_poczatek_y_temp);
		int dlugosc_x = abs(statek_koniec_x_temp-statek_poczatek_x_temp);
		if ((dlugosc_y == 0 && dlugosc_x != 0 && (dlugosc_statku_temp-1) == dlugosc_x) || (dlugosc_x == 0 && dlugosc_y != 0 && (dlugosc_statku_temp-1) == dlugosc_y) || (dlugosc_y == 0 && dlugosc_x == 0 && (dlugosc_statku_temp-1) == dlugosc_x))
		{
			//odwracanie wspó³rzêdnych, w przypadku, gdyby u¿ytkownik poda³ punkty w odwrotnej kolejnoœci
			if ((dlugosc_y != 0) && (statek_poczatek_y_temp - statek_koniec_y_temp> 0))
			{
				int tymczasowa = statek_koniec_y_temp;
				statek_koniec_y_temp = statek_poczatek_y_temp;
				statek_poczatek_y_temp = tymczasowa;
			}

			if ((dlugosc_x != 0) && (statek_poczatek_x_temp - statek_koniec_x_temp> 0))
			{
				int tymczasowa = statek_koniec_x_temp;
				statek_koniec_x_temp = statek_poczatek_x_temp;
				statek_poczatek_x_temp = tymczasowa;
			}

			//sprawdzenie czy mo¿na zaj¹æ wszystkie pola
			if (dlugosc_y != 0)
			{
				for (int i=statek_poczatek_y_temp; i<statek_koniec_y_temp+1; i++)
				{
					if (statki[i][statek_poczatek_x_temp] != 0)
					{
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Co najmniej jedno pole pomiêdzy dwoma punktami zawiera statek.");
							system ("pause");
						}
						return 0;
						break;
					}
				}
				
				if (statek_poczatek_x_temp > 0) //sprawdzam, czy nie jest to lewa strona tablicy
				{
					for (int i=statek_poczatek_y_temp; i<statek_poczatek_y_temp+dlugosc_y+1; i++)
					{
						if (statki[i][statek_poczatek_x_temp-1] != 0)
						{
							if (czy_komputer_temp == 0)
							{
								tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
								system ("pause");
							}
							return 0;
							break;
						}
					}
				}
				
				if (statek_poczatek_x_temp+1 < obiekt_ustawienia.wielkosc_planszy_x) //sprawdzam, czy nie jest to prawa strona tablicy
				{
					for (int i=statek_poczatek_y_temp; i<statek_poczatek_y_temp+dlugosc_y+1; i++)
					{
						if (statki[statek_poczatek_y_temp+1][i] != 0)
						{
							if (czy_komputer_temp == 0)
							{
								tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
								system ("pause");
							}
							return 0;
							break;
						}
					}
				}

				if (statek_poczatek_y_temp > 0)
				{
					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}

				if (statek_koniec_y_temp+1 < obiekt_ustawienia.wielkosc_planszy_y)
				{
					if (statki[statek_koniec_y_temp+1][statek_koniec_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_koniec_y_temp+1][statek_koniec_x_temp] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_koniec_y_temp+1][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}
				
				//mo¿na umieœciæ statek
				for (int i=statek_poczatek_y_temp; i<statek_koniec_y_temp+1; i++)
				{
					statki[i][statek_poczatek_x_temp] = 1;
				}
				return 1;
			}
			else if (dlugosc_x != 0)
			{
				for (int i=statek_poczatek_x_temp; i<statek_koniec_x_temp+1; i++)
				{
					if (statki[statek_poczatek_y_temp][i] != 0)
					{
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Co najmniej jedno pole pomiêdzy dwoma punktami zawiera statek.");
							system ("pause");
						}
						return 0;
						break;
					}
				}

				//sprawdzenie czy inne statki nie bêd¹ wokó³
				if (statek_poczatek_y_temp > 0) //sprawdzam, czy nie jest to pocz¹tek tablicy
				{
					for (int i=statek_poczatek_x_temp; i<statek_poczatek_x_temp+dlugosc_x+1; i++)
					{
						if (statki[statek_poczatek_y_temp-1][i] != 0)
						{
							if (czy_komputer_temp == 0)
							{
								tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
								system ("pause");
							}
							return 0;
							break;
						}
					}
				}
				
				if (statek_poczatek_y_temp+1 < obiekt_ustawienia.wielkosc_planszy_y) //sprawdzam, czy nie jest to koniec tablicy
				{
					for (int i=statek_poczatek_x_temp; i<statek_poczatek_x_temp+dlugosc_x+1; i++)
					{
						if (statki[statek_poczatek_y_temp+1][i] != 0)
						{
							if (czy_komputer_temp == 0)
							{
								tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
								system ("pause");
							}
							return 0;
							break;
						}
					}
				}

				if (statek_poczatek_x_temp > 0)
				{
					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp+1][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}

				if (statek_koniec_x_temp+1 < obiekt_ustawienia.wielkosc_planszy_x)
				{
					if (statki[statek_poczatek_y_temp-1][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp+1][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}

				//mo¿na umieœciæ statek
				for (int i=statek_poczatek_x_temp; i<statek_koniec_x_temp+1; i++)
				{
					statki[statek_poczatek_y_temp][i] = 1;
				}
				return 1;
			}
			else if ((dlugosc_x == 0) && (dlugosc_y == 0))
			{
				//sprawdzenie czy inne statki nie bêd¹ wokó³
				if (statek_poczatek_y_temp > 0)
				{
					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}

				if (statek_koniec_y_temp+1 < obiekt_ustawienia.wielkosc_planszy_y)
				{
					if (statki[statek_koniec_y_temp+1][statek_koniec_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_koniec_y_temp+1][statek_koniec_x_temp] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_koniec_y_temp+1][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				} 
				
				if (statek_poczatek_x_temp > 0)
				{
					if (statki[statek_poczatek_y_temp-1][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp+1][statek_poczatek_x_temp-1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}

				if (statek_koniec_x_temp+1 < obiekt_ustawienia.wielkosc_planszy_x)
				{
					if (statki[statek_poczatek_y_temp-1][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}

					if (statki[statek_poczatek_y_temp+1][statek_koniec_x_temp+1] != 0)
					{	
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Pola znajduj¹ce siê wokó³ statku nie s¹ puste.\n");
							system ("pause");
						}
						return 0;
					}
				}
				
				
				if (statki[statek_poczatek_y_temp][statek_poczatek_x_temp] != 0)
				{
					if (czy_komputer_temp == 0)
					{
						if (czy_komputer_temp == 0)
						{
							tekst_wysrodkowany ("Podane pole jest zajête przez inny statek.");
							system ("pause");
						}
					}
					return 0;
				}
				
				//mo¿na umieœciæ statek
				statki[statek_poczatek_y_temp][statek_poczatek_x_temp] = 1;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if (czy_komputer_temp == 0)
			{
				tekst_wysrodkowany ("Podane pola musz¹ byæ w linii pionowej lub poziomej lub podane wspó³rzêdne nie zgadzaj¹ siê z d³ugoœci¹ statku.");
				system ("pause");
			}
			return 0;
		}
	}
	else
	{
		if (czy_komputer_temp == 0)
		{
			tekst_wysrodkowany ("Co najmniej jedno z pól znajduje siê poza plansz¹ lub co najmniej jedna z danych nie jest wspó³rzêdnymi.");
			system ("pause");
		}
		return 0;
	}
};

void gracz::wypisz (bool czy_atak)
{
	if (czy_atak == 1)
	{
		tekst_wysrodkowany ("Tabela Twoich ataków:\n");
	}
	else
	{
		tekst_wysrodkowany ("Rozmieszczenie Twoich statków:\n");
	}
	
	//rysowanie tabeli
	std::cout << "     " << "                       ";
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		std::cout.width(2);
		std::cout.right;
		std::cout << i+1 << " ";
	}
	std::cout << "\n    " << "                       ";
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_x; i++)
	{
		std::cout.width(2);
		std::cout.right;
		std::cout << "---";
	}
	std::cout << "\n";

	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		std::cout.width(2);
		std::cout.right;
		std::cout << "                        " << ((char) (65+i)) << " | ";
		for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
		{
			if (czy_atak == 1)
			{
				std::cout.width(2);
				std::cout.right;
				std::cout << atak[i][j] << " ";
			}
			else
			{
				std::cout.width(2);
				std::cout.right;
				std::cout << statki[i][j] << " ";
			}
		}
		std::cout << "\n";
	}

	if (czy_atak == 1)
	{
		tekst_wysrodkowany ("\nOznaczenia:\n\n0 – pole jeszcze nie atakowane\n1 – pud³o\n2 - trafiony statek\n3 - trafiony zatopiony\n");
	}
	else
	{
		tekst_wysrodkowany ("\nOznaczenia:\n\n0 – brak statku\n1 – statek\n2 - statek trafiony\n3 - statek zatopiony\n");
	}
};

//przygotowanie tablic do rozpoczecia nowej gry
void gracz::zeruj (void)
{
	for (int i=0; i<obiekt_ustawienia.wielkosc_planszy_y; i++)
	{
		for (int j=0; j<obiekt_ustawienia.wielkosc_planszy_x; j++)
		{
			statki[i][j] = 0;
			atak[i][j] = 0;
		}
	}
	ilosc_statkow_w_grze = 0;
	teraz_ruch = 0;
};

//funkcja sprawdzajaca, czy mozna zaatakowaæ wybrane pole
int gracz::atakuj (int wysokosc_temp, int szerokosc_temp)
{
	if (teraz_ruch == 1)
	{
		if (atak[wysokosc_temp][szerokosc_temp] == 0)
		{
			atak[wysokosc_temp][szerokosc_temp] = 1;
			return 0; //poprawny atak
		}
		else
		{
			return -1; //b³¹d: atak ju¿ nast¹pi³
		}
	}
	else
	{
		return -2; //b³¹d: gracz nie mo¿e atakowaæ
	}
};

//funkcja sprawdza czy na danym polu znajduje siê statek
int gracz::atakowany (int wysokosc_temp, int szerokosc_temp) //! - DO POPRAWY
{
	if (statki[wysokosc_temp][szerokosc_temp] == 0)
	{
		return 0;
	}
	else if (statki[wysokosc_temp][szerokosc_temp] == 1)
	{
		statki[wysokosc_temp][szerokosc_temp] = 2;
		return 1;
	}
	else if (statki[wysokosc_temp][szerokosc_temp] == 2) //po wywo³aniu sprawdzania czy element w tablicy równa siê 1
	{
		ilosc_statkow_w_grze--;
		
		//trafienie
		return 1; //trafiony
	}
	else
	{
		tekst_wysrodkowany ("Wyst¹pi³ nieznany b³¹d.\nGra zostanie zakoñczona. Kod b³êdu: 002.\n");
		system ("pause");
		exit(-1);
		return -1;
	}
};

//funkcja zapisuje w tablicy ataki wartoœæ uzyskan¹ od funkcji atakowany
int gracz::odpowiedz (int wysokosc_temp, int szerokosc_temp, int odpowiedz_temp)
{
	if (odpowiedz_temp == 0)
	{
		atak[wysokosc_temp][szerokosc_temp] = 1; //brak trafienia
		return 0; //brak b³êdu
	}
	else if (odpowiedz_temp == 1)
	{
		atak[wysokosc_temp][szerokosc_temp] = 2; //trafiony
		return 0; //brak b³êdu
	}
	else
	{
		tekst_wysrodkowany ("Wyst¹pi³ nieznany b³¹d.\nGra zostanie zakoñczona. Kod b³êdu: 001.\n");
		system ("pause");
		exit(-1);
	}
};

int gracz::dlugosc_statku (int wysokosc_temp, int szerokosc_temp, int czy_atak, int czy_zaznaczanie_zatopien)
{
	if (czy_atak == 0)
	{
		if ((statki[wysokosc_temp][szerokosc_temp] != 1) && (statki[wysokosc_temp][szerokosc_temp] != 2))
		{
			//b³¹d - brak statku
			return 0;
		}
		if (czy_zaznaczanie_zatopien == 1)
		{
			statki[wysokosc_temp][szerokosc_temp] = 3;
		}
	}
	else
	{
		if ((atak[wysokosc_temp][szerokosc_temp] != 1) && (atak[wysokosc_temp][szerokosc_temp] != 2))
		{
			//b³¹d - brak statku
			return 0;
		}
		if (czy_zaznaczanie_zatopien == 1)
		{
			atak[wysokosc_temp][szerokosc_temp] = 3;
		}
	}
	
	//sprawdzam czy statek jest w pionie
	int licznik = 1;

	//sprawdzam w górê
	for (int i=1; obiekt_ustawienia.wielkosc_planszy_y+1; i++)
	{
		std::cout << "STATKI " << statki[wysokosc_temp-i][szerokosc_temp] << " ATAK " << atak[wysokosc_temp-i][szerokosc_temp] << "\n"; //TEST!!!
		std::cout << wysokosc_temp-i << "\n"; //TEST!!!
		if ((wysokosc_temp-i<0) || (wysokosc_temp-i>obiekt_ustawienia.wielkosc_planszy_y))
		{
			break;
		}
		else if (czy_atak == 0)
		{
			if (((statki[wysokosc_temp-i][szerokosc_temp]) == 1) || ((statki[wysokosc_temp-i][szerokosc_temp]) == 2))
			{
				if (czy_zaznaczanie_zatopien == 1)
				{
					statki[wysokosc_temp-i][szerokosc_temp] = 3;
				}
				licznik++;
			}
			else
			{
				break;
			}
		}
		else if (czy_atak == 1)
		{
			if (((atak[wysokosc_temp-i][szerokosc_temp]) == 1) || ((atak[wysokosc_temp-i][szerokosc_temp]) == 2))
			{
				if (czy_zaznaczanie_zatopien == 1)
				{
					atak[wysokosc_temp-i][szerokosc_temp] = 3;
				}
				licznik++;
			}
			else
			{
				break;
			}
		}
		else
		{
			tekst_wysrodkowany ("Wyst¹pi³ nieznany b³¹d.\nGra zostanie zakoñczona. Kod b³êdu: 200.\n");
			system ("pause");
			exit(-1);
		}
	}

	//sprawdzam w dó³
	for (int i=1; obiekt_ustawienia.wielkosc_planszy_y+1; i++)
	{
		std::cout << "STATKI " << statki[wysokosc_temp+i][szerokosc_temp] << " ATAK " << atak[wysokosc_temp+i][szerokosc_temp] << "\n"; //TEST!!!
		if ((i+wysokosc_temp<0) || (i+wysokosc_temp>obiekt_ustawienia.wielkosc_planszy_y))
		{
			break;
		}
		else if (czy_atak == 0)
		{
			if (((statki[wysokosc_temp+i][szerokosc_temp]) == 1) || ((statki[wysokosc_temp+i][szerokosc_temp]) == 2))
			{
				if (czy_zaznaczanie_zatopien == 1)
				{
					statki[wysokosc_temp+i][szerokosc_temp] = 3;
				}
				licznik++;
			}
			else
			{
				break;
			}
		}
		else if (czy_atak == 1)
		{
			if (((atak[wysokosc_temp+i][szerokosc_temp]) == 1) || ((atak[wysokosc_temp+i][szerokosc_temp]) == 2))
			{
				if (czy_zaznaczanie_zatopien == 1)
				{
					atak[wysokosc_temp+i][szerokosc_temp] = 3;
				}
				licznik++;
			}
			else
			{
				break;
			}
		}
		else
		{
			tekst_wysrodkowany ("Wyst¹pi³ nieznany b³¹d.\nGra zostanie zakoñczona. Kod b³êdu: 201.\n");
			system ("pause");
			exit(-1);
		}
	}
	if (licznik > 1)
	{
		//statek w pionie - liczba dodatnia
		return licznik;
	}
	else
	{
		//sprawdzam czy statek jest w poziomie
		//sprawdzam w lewo
		for (int i=1; obiekt_ustawienia.wielkosc_planszy_x+1; i++)
		{
			std::cout << "STATKI " << statki[wysokosc_temp][szerokosc_temp-i] << " ATAK " << atak[wysokosc_temp][szerokosc_temp-i] << "\n"; //TEST!!!
			if ((szerokosc_temp-i<0) || (szerokosc_temp-i>obiekt_ustawienia.wielkosc_planszy_x))
			{
				break;
			}
			else if (czy_atak == 0)
			{
				if (((statki[wysokosc_temp][szerokosc_temp-i]) == 1) || ((statki[wysokosc_temp][szerokosc_temp-i]) == 2))
				{
					if (czy_zaznaczanie_zatopien == 1)
					{
						statki[wysokosc_temp][szerokosc_temp-i] = 3;
					}
					licznik++;
				}
				else
				{
					break;
				}
			}
			else if (czy_atak == 1)
			{
				if (((atak[wysokosc_temp][szerokosc_temp-i]) == 1) || ((atak[wysokosc_temp][szerokosc_temp-i]) == 2))
				{
					if (czy_zaznaczanie_zatopien == 1)
					{
						atak[wysokosc_temp][szerokosc_temp-i] = 3;
					}
					licznik++;
				}
				else
				{
					break;
				}
			}
			else
			{
				tekst_wysrodkowany ("Wyst¹pi³ nieznany b³¹d.\nGra zostanie zakoñczona. Kod b³êdu: 202.\n");
				system ("pause");
				exit(-1);
			}
		}

		//sprawdzam w prawo
		for (int i=1; obiekt_ustawienia.wielkosc_planszy_x+1;i++)
		{
			std::cout << "STATKI " << statki[wysokosc_temp][szerokosc_temp+i] << " ATAK " << atak[wysokosc_temp][szerokosc_temp+i] << "\n"; //TEST!!!
			if ((i+szerokosc_temp<0) || (i+szerokosc_temp>obiekt_ustawienia.wielkosc_planszy_x))
			{
				break;
			}
			else if (czy_atak == 0)
			{
				if (((statki[wysokosc_temp][szerokosc_temp+i]) == 1) || ((statki[wysokosc_temp][szerokosc_temp+i]) == 2))
				{
					if (czy_zaznaczanie_zatopien == 1)
					{
						statki[wysokosc_temp][szerokosc_temp+i] = 3;
					}
					licznik++;
				}
				else
				{
					break;
				}
			}
			else if (czy_atak == 1)
			{
				if (((atak[wysokosc_temp][szerokosc_temp+i]) == 1) || ((atak[wysokosc_temp][szerokosc_temp+i]) == 2))
				{
					if (czy_zaznaczanie_zatopien == 1)
					{
						atak[wysokosc_temp][szerokosc_temp+i] = 3;
					}
					licznik++;
				}
				else
				{
					break;
				}
			}
			else
			{
				tekst_wysrodkowany ("Wyst¹pi³ nieznany b³¹d.\nGra zostanie zakoñczona. Kod b³êdu: 203.\n");
				system ("pause");
				exit(-1);
			}
		}

		//statek w poziomie lub statek jednoelementowy - liczba ujemna
		std::cout << licznik << "\n"; //TEST!!!
		return (-1)*licznik;
	}
}

void gracz::wypisz_nazwe_gracza (void)
{
	tekst_wysrodkowany ("Gracz 1:\n");
};

void gracz2::wypisz_nazwe_gracza (void)
{
	tekst_wysrodkowany ("Gracz 2:\n");
}