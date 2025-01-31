#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    :uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami){
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenedzer.logowanieUzytkownika();
    adresatMenedzer.ustawIdZalogowanegoUzytkownika(uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
    }
}

void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    adresatMenedzer.wylogujUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatMenedzer.dodajAdresata();
}
