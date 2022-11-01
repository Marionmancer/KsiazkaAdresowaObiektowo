#include "PlikZAdresatami.h"

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata() {
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good()) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty()) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector <Adresat> adresaci;

    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdOstaniegoAdresata() {

    return idOstatniegoAdresata;
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa) {
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

void PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata) {
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int numerWczytanejLinii = 1;
    int numerUsuwanejLinii = 0;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0) {
        while (getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
                numerUsuwanejLinii = numerWczytanejLinii;
            else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;

            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
    ustawIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata);
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat) {
    int idEdytowanegoAdresata = adresat.pobierzId();
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujAdresataWPliku(idEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void PlikZAdresatami::edytujAdresataWPliku(int idEdytowanegoAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami) {
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            if (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) == idEdytowanegoAdresata){
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            } else {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, pobierzNazwePliku());
    }
}

void PlikZAdresatami::ustawIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata) {
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        idOstatniegoAdresata = pobierzZPlikuIdOstatniegoAdresata();
}
