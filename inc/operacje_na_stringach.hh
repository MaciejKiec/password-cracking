#ifndef operacje_na_stringach_HH
#define operacje_na_stringach_HH
#define ILOSC_DOPISANYCH_CYFR 3
#define ILOSC_DOPISANYCH_ZNAKOW 5 //MAX 5

#include <vector>
#include "iostream"
#include  <string.h>
#include <openssl/evp.h>
#include <fstream>
#include <iterator>
#include <bits/stdc++.h>
#include <sstream>
#include <iomanip>
#include <math.h>

struct Haslo{
     std::string hash_hasla;
     std::string login;
     std::string mail;
     std::string zlamane_haslo = std::string();
};

extern pthread_mutex_t mutex_konsument;
extern pthread_mutex_t mutex_zapisu_hasla;
extern pthread_cond_t zlamano_haslo;
extern std::vector<std::string> slownik;
extern std::vector<Haslo> hasla_do_zlamania;
extern std::vector<Haslo> zlamane_hasla;


void czy_zlamano(int index, std::string slowo ,std::string md5_slowa); 
void sprawdz_dla_kazdego_hasla(std::string slowo, std::string md5_slowa);

void funkcja_hashujaca(const char *data, int len, char *md5buf);
std::string zwroc_hash_w_stringu(std::string string_do_zhashowania);
std::string wielka_litera_na_poczatku(std::string slowo);
std::string cale_slowo_wielka_litera(std::string slowo);





#endif