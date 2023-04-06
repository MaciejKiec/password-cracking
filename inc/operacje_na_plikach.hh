#ifndef operacje_na_plikach_HH
#define operacje_na_plikach_HH

#include "operacje_na_stringach.hh"
#include <vector>


bool wczytaj_plik_z_haslami(std::string nazwa_pliku_do_wczytania, std::vector<Haslo>* hasla);
bool wczytaj_slownik(std::string nazwa_pliku_do_wczytania, std::vector<std::string>* slownik);

#endif