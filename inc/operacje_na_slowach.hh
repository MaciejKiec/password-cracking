#ifndef operacje_na_slowach_HH
#define operacje_na_slowach_HH

#include "operacje_na_stringach.hh"

void slowo_ze_slownika_prefix(std::string slowo, int liczba_dopisanych_cyfr);
void slowo_ze_slownika_postfix(std::string slowo, int liczba_dopisanych_cyfr);
void slowo_ze_slownika_prefix_postfix(std::string slowo, int liczba_dopisanych_cyfr);
void dwa_slowa_z_cyframi(std::string slowo1, std::string slowo2, int liczba_dopisanych_cyfr);
void dwa_slowa_ze_znakami(std::string slowo1, std::string slowo2, int liczba_dopisanych_znakow);

#endif