#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy2.txt");

    while (true){
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0) {
            switch (ksiazkaAdresowa.wybierzOpcjeZMenuGlownego()) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            };
        } else {

            char wybor;

            cout << "Wpisz '1' aby zmienic haslo: " << endl;
            cout << "Wpisz '2' aby sie wylogowac: " << endl;
            wybor = MetodyPomocnicze::wczytajZnak();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.ustawIdZalogowanegoUzytkownika(0);
                break;
            }
        }
    }

    //ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();

    return 0;
}
