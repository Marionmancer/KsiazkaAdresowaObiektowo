#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenedzer {

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

    void ustawIdZalogowanegoUzytkownika (int idZalogowanegoUzytkownika);
    int pobierzIdZalogowanegoUzytkownika();

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami)
    :plikZUzytkownikami(nazwaPlikuZUzytkownikami){};
    void logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();

};
#endif
