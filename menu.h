#ifndef menu_h
#define menu_h

//za³¹czanie obiektu z ustawieniami i liczby maksimum
#include "ustawienia.h"
extern ustawienia obiekt_ustawienia;

void tekst_wysrodkowany (char* podany_tekst);
void menu (int kontynulacja_gry);
void menu_nowa_gra (int kontynulacja_gry);
void menu_nowa_gra_komputer (int kontynulacja_gry);
void menu_opcje (int kontynulacja_gry);
void menu_zmiana_opcje (int kontynulacja_gry, int opcja);

#endif