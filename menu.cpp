#include "menu.h"
#include "gra.h"
#include "gra2.h"
#include "zapis_odczyt.h"
#include <cstdlib>
#include <iostream>

void tekst_wysrodkowany (char* podany_tekst)
{
	int licznik = 0;
	int tymczasowa = 0;
	for (int j=0; j<(int) strlen(podany_tekst)+1; j++)
	{
		if ((((int) podany_tekst[licznik] < 32) || ((int) podany_tekst[licznik]) > 127) && ((int) (podany_tekst[licznik]) != -91) && ((int) (podany_tekst[licznik]) != -58) && ((int) (podany_tekst[licznik]) != -54) && ((int) (podany_tekst[licznik]) != -93) && ((int) (podany_tekst[licznik]) != -47) && ((int) (podany_tekst[licznik]) != -45) && ((int) (podany_tekst[licznik]) != -116) && ((int) (podany_tekst[licznik]) != -113) && ((int) (podany_tekst[licznik]) != -81) && ((int) (podany_tekst[licznik]) != -71) && ((int) (podany_tekst[licznik]) != -26) && ((int) (podany_tekst[licznik]) != -22) && ((int) (podany_tekst[licznik]) != -77) && ((int) (podany_tekst[licznik]) != -15) && ((int) (podany_tekst[licznik]) != -13) && ((int) (podany_tekst[licznik]) != -100) && ((int) (podany_tekst[licznik]) != -97) && ((int) (podany_tekst[licznik]) != -65 && ((int) (podany_tekst[licznik]) != -106))) //warunek znajduje bia³e znaki z pominiêciem liter u¿ywanych, tylko w jêzyku polskim, pominiêcie równie¿ myœlnika
		{
			for (int i=0; i<(80-licznik+tymczasowa)/2; i++)
			{
				std::cout << " ";
			}
			for (int i=tymczasowa; i<licznik; i++)
			{
				std::cout << podany_tekst[i];
			}
			std::cout << "\n";
			licznik++;  //pomija bia³y znak
			tymczasowa = licznik;
		}
		else
		{
			licznik++;
		}
	}
};

void menu_nowa_gra (int kontynulacja_gry)
{
	tekst_wysrodkowany ("Proszê wybraæ opcjê: ");
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\nWybierz poziom trudnoœci:\n1. £atwy\n2. Œredni\n3. Trudny\n4. Powrót do menu\n");
			menu_nowa_gra_komputer (kontynulacja_gry);
			break;
		case 2:
			nowa_gra (0,0);
			break;
		case 3:
			menu (kontynulacja_gry);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\nPodana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
			system ("pause");
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\n1. Gra z komputerem\n2. Gra Gra z drugim graczem\n3. Powrót do menu\n");
			menu_nowa_gra (kontynulacja_gry);
			break;
	}
};

void menu (int kontynulacja_gry)
{
	system ("cls");
	tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nMENU:\n\n");
	if (kontynulacja_gry == 1)
	{
		tekst_wysrodkowany ("1. Kontynuacja gry\n2. Nowa gra\n3. Opcje\n4. Wyjœcie do Windows\n");
	}
	else
	{
		tekst_wysrodkowany ("1. Nowa gra\n2. Opcje\n3. Wyjœcie do Windows\n");
	}
	tekst_wysrodkowany ("Proszê wybraæ opcjê: ");
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	if (kontynulacja_gry == 1)
	{
		switch (wybor)
		{
			case 1:
				odczyt();
				zwyciestwo ();
				break;
			case 2:
				system ("cls");
				tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\n1. Gra z komputerem\n2. Gra Gra z drugim graczem\n3. Powrót do menu\n");
				menu_nowa_gra(1);
				break;
			case 3:
				system ("cls");
				tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nOPCJE:\n\n1. Wielkoœæ planszy (w poziomie)\n2. Wielkoœæ planszy (w pionie)\n3. Powtarzanie ruchu w przypadku trafienia\n4. Iloœæ statków piêcioelementowych\n5. Iloœæ statków czteroelementowych\n6. Iloœæ statków trójelementowych\n7. Iloœæ statków dwuelementowych\n8. Iloœæ statków jednoelementowych\n9. Powrót do menu\n");
				menu_opcje(1);
				break;
			case 4:
				exit(0);
				break;
			default:
				system ("cls");
				tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nPodana liczba / ci¹g znaków nie jest liczb¹ od 1 do 4.");
				system ("pause");
				menu (1);
				break;
		}
	}
	else
	{
		switch (wybor)
		{
			case 1:
				system ("cls");
				tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\n1. Gra z komputerem\n2. Gra Gra z drugim graczem\n3. Powrót do menu\n");
				menu_nowa_gra(0);
				break;
			case 2:
				system ("cls");
				tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nOPCJE:\n\n1. Wielkoœæ planszy (w poziomie)\n2. Wielkoœæ planszy (w pionie)\n3. Powtarzanie ruchu w przypadku trafienia\n4. Iloœæ statków piêcioelementowych\n5. Iloœæ statków czteroelementowych\n6. Iloœæ statków trójelementowych\n7. Iloœæ statków dwuelementowych\n8. Iloœæ statków jednoelementowych\n9. Powrót do menu\n");
				menu_opcje(0);
				break;
			case 3:
				exit(0);
				break;
			default:
				system ("cls");
				tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nPodana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
				system ("pause");
				menu (0);
				break;
		}
	}
};

void menu_nowa_gra_komputer (int kontynulacja_gry)
{
	tekst_wysrodkowany ("Proszê wybraæ opcjê: ");
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			nowa_gra (1,1);
			break;
		case 2:
			nowa_gra (1,2);
			break;
		case 3:
			nowa_gra (1,3);
			break;
		case 4:
			menu (kontynulacja_gry);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\nPodana liczba / ci¹g znaków nie jest liczb¹ od 1 do 4.");
			system ("pause");
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nNOWA GRA:\n\nWybierz poziom trudnoœci:\n1. £atwy\n2. Œredni\n3. Trudny\n4. Powrót do menu\n");
			menu_nowa_gra_komputer (kontynulacja_gry);
			break;
	}
};

void menu_opcje (int kontynulacja_gry)
{
	tekst_wysrodkowany ("Proszê wybraæ opcjê: ");
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			menu_zmiana_opcje (kontynulacja_gry, 1);
			break;
		case 2:
			menu_zmiana_opcje (kontynulacja_gry, 2);
			break;
		case 3:
			menu_zmiana_opcje (kontynulacja_gry, 3);
			break;
		case 4:
			menu_zmiana_opcje (kontynulacja_gry, 4);
			break;
		case 5:
			menu_zmiana_opcje (kontynulacja_gry, 5);
			break;
		case 6:
			menu_zmiana_opcje (kontynulacja_gry, 6);
			break;
		case 7:
			menu_zmiana_opcje (kontynulacja_gry, 7);
			break;
		case 8:
			menu_zmiana_opcje (kontynulacja_gry, 8);
			break;
		case 9:
			menu (kontynulacja_gry);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nOPCJE:\n\nPodana liczba / ci¹g znaków nie jest liczb¹ od 1 do 9.");
			system ("pause");
			system ("cls");
			tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nOPCJE:\n\n1. Wielkoœæ planszy (w poziomie)\n2. Wielkoœæ planszy (w pionie)\n3. Powtarzanie ruchu w przypadku trafienia\n4. Iloœæ statków piêcioelementowych\n5. Iloœæ statków czteroelementowych\n6. Iloœæ statków trójelementowych\n7. Iloœæ statków dwuelementowych\n8. Iloœæ statków jednoelementowych\n9. Powrót do menu\n");
			menu_opcje (kontynulacja_gry);
			break;
	}
};

void menu_zmiana_opcje (int kontynulacja_gry, int opcja)
{
	system ("cls");
	tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nOPCJE:\n");
	
	char p1[120] = "\nAktualna ";
	char p2[100] = "";
	char p3[100] = " - ";
	char p4[100] = "";
	char p5[100] = ".\n";
	char p6[100] = "Podaj now¹ wartoœæ od 0 do ";
	char p7[100] = "";
	char p8[100] = " (w³¹cznie): ";
	
	if (opcja == 1)
	{
		strcpy_s (p2, "wielkoœæ planszy (w pionie)");
		_itoa_s (obiekt_ustawienia.wielkosc_planszy_x, p4, 10);
		_itoa_s (maks, p7, 10);
	}
	else if (opcja == 2)
	{
		strcpy_s (p2, "wielkoœæ planszy (w poziomie)");
		_itoa_s (obiekt_ustawienia.wielkosc_planszy_y, p4, 10);
		_itoa_s (maks, p7, 10);
	}
	else if (opcja == 3)
	{
		strcpy_s (p2, "opcja powtarzanie ruchu w przypadku trafienia");
		_itoa_s (obiekt_ustawienia.powtarzanie_ruchu_w_przypadku_trafienia, p4, 10);
		_itoa_s (1, p7, 10);
	}
	else if (opcja == 4)
	{
		strcpy_s (p2, "iloœæ statków piêcioelementowych");
		_itoa_s (obiekt_ustawienia.ilosc_statkow_5, p4, 10);
		_itoa_s (maks, p7, 10);
	}
	else if (opcja == 5)
	{
		strcpy_s (p2, "iloœæ statków czteroelementowych");
		_itoa_s (obiekt_ustawienia.ilosc_statkow_4, p4, 10);
		_itoa_s (maks, p7, 10);
	}
	else if (opcja == 6)
	{
		strcpy_s (p2, "iloœæ statków trójelementowych");
		_itoa_s (obiekt_ustawienia.ilosc_statkow_3, p4, 10);
		_itoa_s (maks, p7, 10);
	}
	else if (opcja == 7)
	{
		strcpy_s (p2, "iloœæ statków dwuelementowych");
		_itoa_s (obiekt_ustawienia.ilosc_statkow_2, p4, 10);
		_itoa_s (maks, p7, 10);
		
	}
	else if (opcja == 8)
	{
		strcpy_s (p2, "iloœæ statków jednoelementowych");
		_itoa_s (obiekt_ustawienia.ilosc_statkow_1, p4, 10);
		_itoa_s (maks, p7, 10);
	}

	strcat_s (p1, p2);
	strcat_s (p1, p3);
	strcat_s (p1, p4);
	strcat_s (p1, p5);
	strcat_s (p1, p6);
	strcat_s (p1, p7);
	strcat_s (p1, p8);
	tekst_wysrodkowany (p1);
	
	int nowa_wartosc;
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	
	std::cin >> nowa_wartosc;

	//sprawdza ustawienia i w przypadku b³êdów zastêpuje domyœlnymi
	if ((opcja !=3) && ((nowa_wartosc < 0) || (nowa_wartosc > maks)))
	{
		if ((opcja == 1) || (opcja == 2))
		{
			nowa_wartosc = 1;
			char p1[100] = "\nPodana liczba nie jest w zakresie od 0 do ";
			char p2[100] = "";
			_itoa_s (maks, p2, 10);
			char p3[100] = " w³¹cznie. Zmieniam wartoœæ na 1.\n";
			strcat_s (p1, 50, p2);
			strcat_s (p1, 100, p3);
			tekst_wysrodkowany (p1);
			system ("pause");
		}
		else if ((opcja == 4) || (opcja == 5))
		{
			nowa_wartosc = 1;
			char p1[100] = "\nPodana liczba nie jest w zakresie od 0 do ";
			char p2[100] = "";
			_itoa_s (maks, p2, 10);
			char p3[100] = " w³¹cznie. Zmieniam wartoœæ na 1.\n";
			strcat_s (p1, 50, p2);
			strcat_s (p1, 100, p3);
			tekst_wysrodkowany (p1);
			system ("pause");

		}
		else if (opcja == 6)
		{
			nowa_wartosc = 2;
			char p1[100] = "\nPodana liczba nie jest w zakresie od 0 do ";
			char p2[100] = "";
			_itoa_s (maks, p2, 10);
			char p3[100] = " w³¹cznie. Zmieniam wartoœæ na 2.\n";
			strcat_s (p1, 50, p2);
			strcat_s (p1, 100, p3);
			tekst_wysrodkowany (p1);
			system ("pause");
		}
		else if (opcja == 7)
		{
			nowa_wartosc = 3;
			char p1[100] = "\nPodana liczba nie jest w zakresie od 0 do ";
			char p2[100] = "";
			_itoa_s (maks, p2, 10);
			char p3[100] = " w³¹cznie. Zmieniam wartoœæ na 3.\n";
			strcat_s (p1, 50, p2);
			strcat_s (p1, 100, p3);
			tekst_wysrodkowany (p1);
			system ("pause");
		}
		else if (opcja == 8)
		{
			nowa_wartosc = 0;
			char p1[100] = "\nPodana liczba nie jest w zakresie od 0 do ";
			char p2[100] = "";
			_itoa_s (maks, p2, 10);
			char p3[100] = " w³¹cznie. Zmieniam wartoœæ na 0.\n";
			strcat_s (p1, 50, p2);
			strcat_s (p1, 100, p3);
			tekst_wysrodkowany (p1);
			system ("pause");
		}
	}
	else if ((opcja == 3) && (nowa_wartosc !=0) && (nowa_wartosc != 1))
	{
		nowa_wartosc = 0;
		char p1[100] = "\nPodana liczba nie jest w zakresie od 0 do ";
		char p2[100] = "";
		_itoa_s (1, p2, 10);
		char p3[100] = " w³¹cznie. Zmieniam wartoœæ na 0.\n";
		strcat_s (p1, 50, p2);
		strcat_s (p1, 100, p3);
		tekst_wysrodkowany (p1);
		system ("pause");
	}

	//zapis nowej wartoœci do obiektu ustawienia
	switch (opcja)
	{
		case 1:
			obiekt_ustawienia.wielkosc_planszy_x = nowa_wartosc;
			break;
		case 2:
			obiekt_ustawienia.wielkosc_planszy_y = nowa_wartosc;
			break;
		case 3:
			obiekt_ustawienia.powtarzanie_ruchu_w_przypadku_trafienia = nowa_wartosc;
			break;
		case 4:
			obiekt_ustawienia.ilosc_statkow_5 = nowa_wartosc;
			break;
		case 5:
			obiekt_ustawienia.ilosc_statkow_4 = nowa_wartosc;
			break;
		case 6:
			obiekt_ustawienia.ilosc_statkow_3 = nowa_wartosc;
			break;
		case 7:
			obiekt_ustawienia.ilosc_statkow_2 = nowa_wartosc;
			break;
		case 8:
			obiekt_ustawienia.ilosc_statkow_1 = nowa_wartosc;
			break;
	}
	obiekt_ustawienia.zapis_ustawien();
	tekst_wysrodkowany ("Zapisano now¹ wartoœæ.");
	system ("pause");
	system ("cls");
	tekst_wysrodkowany ("Gra statki\nAutor: Pawe³ Roszatycki\n\nOPCJE:\n\n1. Wielkoœæ planszy (w poziomie)\n2. Wielkoœæ planszy (w pionie)\n3. Powtarzanie ruchu w przypadku trafienia\n4. Iloœæ statków piêcioelementowych\n5. Iloœæ statków czteroelementowych\n6. Iloœæ statków trójelementowych\n7. Iloœæ statków dwuelementowych\n8. Iloœæ statków jednoelementowych\n9. Powrót do menu\n");
	menu_opcje (kontynulacja_gry);
};