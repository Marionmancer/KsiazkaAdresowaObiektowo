#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt","Adresaci.txt");
//    ksiazkaAdresowa.logowanieUzytkownika();
//    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
//    ksiazkaAdresowa.dodajAdresata();
//    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
//    system("pause");
//    ksiazkaAdresowa.wylogujUzytkownika();
//    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.dodajAdresata();


    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
