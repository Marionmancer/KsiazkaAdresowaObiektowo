#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){

    uzytkownikMenedzer.logowanieUzytkownika();
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())   {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}
void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    if (uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika()!=0){
        uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
    }
}

void KsiazkaAdresowa::wylogujUzytkownika(){
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(0);
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodajAdresata(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer -> dodajAdresata();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer -> wyswietlWszystkichAdresatow();
    } else {
        cout << "Aby wyswietlic adresatow, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}
