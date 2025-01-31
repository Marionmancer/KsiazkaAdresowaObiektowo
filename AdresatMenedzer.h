#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer {

    int idZalogowanegoUzytkownika;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami)
    :plikZAdresatami(nazwaPlikuZAdresatami){};

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();
    void wylogujUzytkownika();
    void dodajAdresata();

    void ustawIdZalogowanegoUzytkownika (int idZalogowanegoUzytkownika);
    void ustawWektorAdresaci(vector <Adresat> adresaci);

    int pobierzIdZalogowanegoUzytkownika();
    vector <Adresat> pobierzWektorAdresaci();
};
#endif
