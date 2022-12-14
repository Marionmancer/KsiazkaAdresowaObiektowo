#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Uzytkownik.h"
#include "PlikTekstowy.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami : public PlikTekstowy {

    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string nazwaPlikuZUzytkownikami) : PlikTekstowy(nazwaPlikuZUzytkownikami){};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector<Uzytkownik> uzytkownicy);

};

#endif // PLIKZUZYTKOWNIKAMI_H
