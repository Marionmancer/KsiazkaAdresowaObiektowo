#include "AdresatMenedzer.h"

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){
    ustawWektorAdresaci(plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku
                        (pobierzIdZalogowanegoUzytkownika()));
}

void AdresatMenedzer::ustawIdZalogowanegoUzytkownika (int idZalogowanegoUzytkownika) {
    this-> idZalogowanegoUzytkownika = idZalogowanegoUzytkownika;
}

int AdresatMenedzer::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
void AdresatMenedzer::ustawWektorAdresaci(vector <Adresat> adresaci){
    this-> adresaci = adresaci;
}

vector <Adresat> AdresatMenedzer::pobierzWektorAdresaci(){
    return adresaci;
}
