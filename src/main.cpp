#include "operacje_na_stringach.hh"
#include "operacje_na_plikach.hh"
#include "watki.hh"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

pthread_mutex_t mutex_konsument;
pthread_mutex_t mutex_zapisu_hasla;
pthread_cond_t zlamano_haslo;
std::vector<std::string> slownik;
std::vector<Haslo> hasla_do_zlamania;
std::vector<Haslo> zlamane_hasla;

int main(){
    pthread_cond_init(&zlamano_haslo, NULL);
    pthread_mutex_init(&mutex_zapisu_hasla, NULL);
    pthread_mutex_init(&mutex_konsument, NULL);
    pthread_t producent0, producent1, producent2, producent3, producent4, producent5, konsument;

    std::string nazwa_pliku_slownika;
    std::string nazwa_pliku_z_haslami;

    std::cout << "Wpisz nazwę pliku slownika: ";
    std::cin >> nazwa_pliku_slownika;

    while(!wczytaj_slownik(nazwa_pliku_slownika, &slownik)){
        std::cout << "\nNie udało się wczytać słownika! Spróbuj ponownie: ";
        std::cin >> nazwa_pliku_slownika;
    }

    std::cout << "\nWpisz nazwę pliku z hasłami do złamania: ";
    std::cin >> nazwa_pliku_z_haslami;

    while(!wczytaj_plik_z_haslami(nazwa_pliku_z_haslami, &hasla_do_zlamania)){
        std::cout << "\nNie udało się wczytać pliku z hasłami! Spróbuj ponownie: ";
        std::cin >> nazwa_pliku_z_haslami;
    }  

    std::cout << "\nUdalo się poprawnie wczytać oba pliki \n";
    system("clear");

    pthread_create(&konsument, NULL, watek_konsumenta, NULL);
    pthread_create(&producent0, NULL, producent_0, NULL);
    pthread_create(&producent1, NULL, producent_1, NULL);
    pthread_create(&producent2, NULL, producent_2, NULL);
    pthread_create(&producent3, NULL, producent_3, NULL);
    pthread_create(&producent4, NULL, producent_4, NULL);
    pthread_create(&producent5, NULL, producent_5, NULL);
    pthread_exit(NULL);

    return 0;
}