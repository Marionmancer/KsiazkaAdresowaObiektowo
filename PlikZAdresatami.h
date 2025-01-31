#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami{

    const string NAZWA_PLIKU_Z_ADRESATAMI;

    bool czyPlikJestPusty();
//    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
//    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami)
                        :NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){};
//    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
//    vector <Uzytkownik> wczytajUzytkownikowZPliku();
//    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);

};
#endif
