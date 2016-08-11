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

void atak (bool czy_gracz_1)
{
	if ((czy_gracz_1 == 1) && (gracz_1.teraz_ruch == 1))
	{
		//ruch gracza 1
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nGracz 1:\n");
		system ("pause");
		system ("cls");
		gracz_1.wypisz_nazwe_gracza();
		gracz_1.wypisz(1);
		gracz_1.wypisz(0);

		//!!!DLA CELOW TESTOWYCH
		tekst_wysrodkowany ("Gracz 2:\n");
		gracz_2.wypisz(1);
		gracz_2.wypisz(0);
	}
	else if ((czy_gracz_1 == 0) && (gracz_2.teraz_ruch == 1) && (gracz_2.czy_komputer == 0))
	{
		//ruch gracza 2 - cz�owiek
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nGracz 2:\n");
		system ("pause");
		system ("cls");
		gracz_2.wypisz_nazwe_gracza();
		gracz_2.wypisz(1);
		gracz_2.wypisz(0);
	}
	else if ((czy_gracz_1 == 0) && (gracz_2.teraz_ruch == 1) && (gracz_2.czy_komputer == 1))
	{
		//ruch gracza 2 - komputer
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nGracz 2:\n");
		tekst_wysrodkowany ("Komputer\n");
		system ("pause");
	}
	else
	{
		tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 016.\n");
		system ("pause");
		exit(-1);
	}
	
	//pobiera pole do ataku
	int atak_y = 0;
	int atak_x = 0;
	if ((czy_gracz_1 == 1) || ((czy_gracz_1 == 0) && (gracz_2.czy_komputer == 0)))
	{
		tekst_wysrodkowany ("\nWybierz pole do ataku:\n");
		char pole_do_ataku[3];
		//czyszczenie bufora klawiatury
		std::cin.clear();
		std::cin.sync();
		std::cin >> pole_do_ataku;
		atak_y = (toupper (pole_do_ataku[0])-65); //uwzgl�dnienie, mo�liwo�ci wpisania ma�ej litery przez u�ytkownika
		pole_do_ataku[0] = '0';
		atak_x = atoi (pole_do_ataku)-1;
	}
	else
	{
		if (gracz_2.poziom_trudnosci == 1)
		{
			losuj_latwy (atak_y, atak_x);
		}
		else if (gracz_2.poziom_trudnosci == 2)
		{
			losuj_sredni (atak_y, atak_x);
		}
		else if (gracz_2.poziom_trudnosci == 3)
		{
			losuj_trudny (atak_y, atak_x);
		}
		else
		{
			tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 015.\n");
			system ("pause");
			exit(-1);
		}
	}

	//gracz 1
	if (czy_gracz_1 == 1)
	{	
		int atak = gracz_1.atakuj (atak_y,atak_x);
		if (atak == -1) //atak ju� nast�pi� na to pole
		{
			tekst_wysrodkowany ("\nPole zosta�o ju� wcze�niej zaatakowane. Wybierz inne.\n");
			system ("pause");
			return;
		}
		else if (atak == -2) //wyst�pi� nieznany b��d
		{
			tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 014.\n");
			system ("pause");
			exit(-1);
		}
		else if (atak == 0) //poprawny atak
		{
			int atakowany = gracz_2.atakowany (atak_y,atak_x);
			if (atakowany == 0) //pud�o
			{
				int odpowiedz = gracz_1.odpowiedz (atak_y, atak_x, 0);
				if (odpowiedz == 0)
				{
					tekst_wysrodkowany ("Pud�o.\n");
					system ("pause");
					gracz_1.teraz_ruch = 0;
					gracz_2.teraz_ruch = 1;
					return;
				}
				else
				{
					tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 020.\n");
					system ("pause");
					exit(-1);
				}
			}
			else if (atakowany == 1) //trafiony statek
			{
				int odpowiedz = gracz_1.odpowiedz (atak_y, atak_x, 1);
				if (odpowiedz == 0)
				{
					int liczba_elementow_statku_g1 = gracz_1.dlugosc_statku (atak_y, atak_x, 1, 0);
					int liczba_elementow_statku_g2 = gracz_2.dlugosc_statku (atak_y, atak_x, 0, 0);
					if (liczba_elementow_statku_g1 == liczba_elementow_statku_g2)
					{
						tekst_wysrodkowany ("Trafiony zatopiony.\n");
						gracz_1.dlugosc_statku (atak_y, atak_x, 1, 1);
						gracz_2.dlugosc_statku (atak_y, atak_x, 0, 1);
						system ("pause");
					}
					else
					{
						tekst_wysrodkowany ("Trafiony.\n");
						system ("pause");
						if (obiekt_ustawienia.powtarzanie_ruchu_w_przypadku_trafienia == 0)
						{
							gracz_1.teraz_ruch = 0;
							gracz_2.teraz_ruch = 1;
						}
						else
						{
							gracz_1.teraz_ruch = 1;
							gracz_2.teraz_ruch = 0;
						}
					}
					return;
				}
				else
				{
					tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 021.\n");
					system ("pause");
					exit(-1);
				}
			}
			else 
			{
				tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 013.\n");
				system ("pause");
				exit(-1);
			}
		}
	}

	//gracz 2 - cz�owiek
	else if ((czy_gracz_1 == 0) && (gracz_2.czy_komputer == 0))
	{
		int atak = gracz_2.atakuj (atak_y,atak_x);
		if (atak == -1) //atak ju� nast�pi� na to pole
		{
			tekst_wysrodkowany ("\nPole zosta�o ju� wcze�niej zaatakowane. Wybierz inne.\n");
			system ("pause");
			return;
		}
		else if (atak == -2) //wyst�pi� nieznany b��d
		{
			tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 014.\n");
			system ("pause");
			exit(-1);
		}
		else if (atak == 0) //poprawny atak
		{
			int atakowany = gracz_1.atakowany (atak_y,atak_x);
			if (atakowany == 0) //pud�o
			{
				int odpowiedz = gracz_2.odpowiedz (atak_y, atak_x, 0);
				if (odpowiedz == 0)
				{
					tekst_wysrodkowany ("Pud�o.\n");
					system ("pause");
					gracz_1.teraz_ruch = 0;
					gracz_2.teraz_ruch = 1;
					return;
				}
				else
				{
					tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 020.\n");
					system ("pause");
					exit(-1);
				}
			}
			else if (atakowany == 1) //trafiony statek
			{
				int odpowiedz = gracz_2.odpowiedz (atak_y, atak_x, 1);
				if (odpowiedz == 0)
				{
					tekst_wysrodkowany ("Trafiony.\n");
					system ("pause");
					if (obiekt_ustawienia.powtarzanie_ruchu_w_przypadku_trafienia == 0)
					{
						gracz_1.teraz_ruch = 1;
						gracz_2.teraz_ruch = 0;
					}
					else
					{
						gracz_1.teraz_ruch = 0;
						gracz_2.teraz_ruch = 1;
					}
					return;
				}
				else
				{
					tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 021.\n");
					system ("pause");
					exit(-1);
				}
			}
			else 
			{
				tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 013.\n");
				system ("pause");
				exit(-1);
			}
		}
	}

	//gracz 2 - komputer
	else if ((czy_gracz_1 == 0) && (gracz_2.czy_komputer == 1))
	{
		int atak = gracz_2.atakuj (atak_y,atak_x);
		if (atak == 1) //atak ju� nast�pi� na to pole
		{
			return;
		}
		else if (atak == 2) //wyst�pi� nieznany b��d
		{
			tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 014.\n");
			system ("pause");
			exit(-1);
		}
		else if (atak == 0) //poprawny atak
		{
			int atakowany = gracz_1.atakowany (atak_y,atak_x);
			if (atakowany == 0) //pud�o
			{
				int odpowiedz = gracz_2.odpowiedz (atak_y, atak_x, 0);
				if (odpowiedz == 0)
				{
					char p1[100] = "\nKomputer spud�owa� strzelaj�c w pole: ";
					char p2[2] = "";
					p2[0] = atak_y+65;
					char p3[100] = "";
					_itoa_s (atak_x+1, p3, 10);
					char p4[100] = ".\n";
					strcat_s (p1, 50, p2);
					strcat_s (p1, 100, p3);
					strcat_s (p1, 100, p4);
					tekst_wysrodkowany (p1);
					system ("pause");

					gracz_1.teraz_ruch = 1;
					gracz_2.teraz_ruch = 0;
					return;
				}
				else
				{
					tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 020.\n");
					system ("pause");
					exit(-1);
				}
			}
			else if (atakowany == 1) //trafiony statek
			{
				int odpowiedz = gracz_2.odpowiedz (atak_y, atak_x, 1);
				if (odpowiedz == 0)
				{
					char p1[100] = "\nKomputer trafi� Tw�j statek atakuj�c pole: ";
					char p2[2] = "";
					p2[0] = atak_y+65;
					char p3[100] = "";
					_itoa_s (atak_x+1, p3, 10);
					char p4[100] = ".\n";
					strcat_s (p1, 50, p2);
					strcat_s (p1, 100, p3);
					strcat_s (p1, 100, p4);
					tekst_wysrodkowany (p1);
					system ("pause");
					
					if (obiekt_ustawienia.powtarzanie_ruchu_w_przypadku_trafienia == 0)
					{
						gracz_1.teraz_ruch = 1;
						gracz_2.teraz_ruch = 0;
					}
					else
					{
						gracz_1.teraz_ruch = 0;
						gracz_2.teraz_ruch = 1;
					}
					return;
				}
				else
				{
					tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 021.\n");
					system ("pause");
					exit(-1);
				}
			}
			else 
			{
				tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 013.\n");
				system ("pause");
				exit(-1);
			}
		}
	}
};

void nowa_gra (int czy_komputer_temp, int poziom_trudnosci_temp)
{
	//przygotowananie do nowej gry
	gracz_1.zeruj();
	gracz_2.zeruj();
	gracz_2.czy_komputer = czy_komputer_temp;
	gracz_2.poziom_trudnosci = poziom_trudnosci_temp;

	//ustawienie statk�w
	if (gracz_2.czy_komputer == 0)
	{
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nGracz 1:\n");
		system ("pause");
		gracz_1.rozmiesc_statki(0);
		gracz_1.wypisz(0);
		system ("pause");
		
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nGracz 2:\n");
		system ("pause");
		gracz_2.rozmiesc_statki(0);
		gracz_2.wypisz(0);
		system ("pause");
	}
	else
	{
		gracz_1.rozmiesc_statki(0);
		gracz_1.wypisz(0);
		system ("pause");

		gracz_2.rozmiesc_statki(1);
	}

	gracz_1.teraz_ruch = 1; //gracz 1 zawsze zaczyna ruch
	zwyciestwo ();
	
};


void zwyciestwo (void)
{
	int j=0;
	while (j<1)
	{
		if (gracz_1.teraz_ruch == 1)
		{
			atak (1);
			zapis();
		}
		else if (gracz_2.teraz_ruch == 1)
		{
			atak (0);
			zapis();
		}
		else
		{
			tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 004.\n");
			system ("pause");
			exit(-1);
		}

		if ((gracz_1.ilosc_statkow_w_grze == 0) || (gracz_2.ilosc_statkow_w_grze == 0))
		{
			++j;
		}
	}

	if ((gracz_1.ilosc_statkow_w_grze == 0) && (gracz_2.czy_komputer == 0))
	{
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nWygra� Gracz 2.\n\nGratulacje.\n");
		zapis();
		system ("pause");
		menu(0);
	}
	else if ((gracz_2.ilosc_statkow_w_grze == 0) && (gracz_2.czy_komputer == 0))
	{
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nWygra� Gracz 1.\n\nGratulacje.\n");
		zapis();
		system ("pause");
		menu(0);
	}
	else if ((gracz_1.ilosc_statkow_w_grze == 0) && (gracz_2.czy_komputer == 1))
	{
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nKoniec gry.\n\nZosta�e� pokonany przez komputer.\n");
		zapis();
		system ("pause");
		menu(0);
	}
	else if ((gracz_2.ilosc_statkow_w_grze == 0) && (gracz_2.czy_komputer == 1))
	{
		system ("cls");
		tekst_wysrodkowany ("Gra statki\nAutor: Pawe� Roszatycki\n\nPokona�e� komputer.\n\nGratulacje.\n");
		zapis();
		system ("pause");
		menu(0);
	}
	else
	{
		tekst_wysrodkowany ("Wyst�pi� nieznany b��d.\nGra zostanie zako�czona. Kod b��du: 003.\n");
		system ("pause");
		exit(-1);
	}
};