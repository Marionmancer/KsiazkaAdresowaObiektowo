#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami){
        uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzIdZalogowanegoUzytkownika());
    };
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    void ustawIdZalogowanegoUzytkownika (int idUzytkownika);

    int pobierzIdZalogowanegoUzytkownika();
};

#endif //KSIAZKAADRESOWA_H
