#ifndef watki_HH
#define watki_HH

#include "operacje_na_stringach.hh"
#include "operacje_na_slowach.hh"

extern pthread_mutex_t mutex_konsument;
extern pthread_mutex_t mutex_zapisu_hasla;
extern pthread_cond_t zlamano_haslo;
extern std::vector<std::string> slownik;
extern std::vector<Haslo> hasla_do_zlamania;
extern std::vector<Haslo> zlamane_hasla;


void SIGHUP_HANDLER(int BezTegoIntaNieDziala);
void* producent_0(void*); //czyste słowa
void* producent_1(void*); //prefix liczbowy
void* producent_2(void*); //postfix liczbowy
void* producent_3(void*); //prefix + postfix liczbowy
void* producent_4(void*); //producent dwuwyrazowy
void* producent_5(void*); //producent dwuwyrazowy ze znakami pomiędzy wyrazami
void* watek_konsumenta(void*);


#endif