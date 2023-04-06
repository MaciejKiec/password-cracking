#include "watki.hh"

void SIGHUP_HANDLER(int BezTegoIntaNieDziala){
    system("clear");
    std::cout << "Złamane do tej pory hasła:\n";
    for(int i = 0; i < zlamane_hasla.size(); i++){
    std::cout << "Login: " << zlamane_hasla[i].login << " Emial: " << zlamane_hasla[i].mail << " hasło: " << zlamane_hasla[i].zlamane_haslo  << "\n";
    }
    std::cout << "##################################################################################################################################\n";
}

void* producent_0(void*){

    for(int i = 0; i < slownik.size(); i++){

        //czyste słowo ze słownika
        std::string md5_slowa = zwroc_hash_w_stringu(slownik[i]);
        //std::this_thread::sleep_for(std::chrono::nanoseconds(100000)); //Bez tego program nie chce się wykonać dla małej ilości haseł
        sprawdz_dla_kazdego_hasla(slownik[i], md5_slowa);

        //Wielka pierwsza litera
        md5_slowa = zwroc_hash_w_stringu(wielka_litera_na_poczatku(slownik[i]));
        sprawdz_dla_kazdego_hasla(wielka_litera_na_poczatku(slownik[i]), md5_slowa);

        //Całe słowo z wielkich liter
        md5_slowa = zwroc_hash_w_stringu(cale_slowo_wielka_litera(slownik[i]));
        sprawdz_dla_kazdego_hasla(cale_slowo_wielka_litera(slownik[i]), md5_slowa);

    }
    //std::cout << "Wątek prodcuenta 0 zakończył pracę";
    pthread_exit(NULL);
}


void* producent_1(void*){

    for(int i = 0; i < slownik.size(); i++){

        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            //czyste słowo ze słownika 
            slowo_ze_slownika_prefix(slownik[i], dopisane_cyfry);
        
        }

        //Wielka pierwsza litera
         for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            slowo_ze_slownika_prefix(wielka_litera_na_poczatku(slownik[i]), dopisane_cyfry);
        
        }

        //Całe słowo z wielkich liter
         for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            slowo_ze_slownika_prefix(cale_slowo_wielka_litera(slownik[i]), dopisane_cyfry);
        
        }
    }
    std::cout << "Producent 1 skończył pracę\n";
    pthread_exit(NULL);
}

void* producent_2(void*){

    for(int i = 0; i < slownik.size(); i++){


        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            //czyste słowo ze słownika 
            slowo_ze_slownika_postfix(slownik[i], dopisane_cyfry);
        
        }

        //Wielka pierwsza litera
        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            slowo_ze_slownika_postfix(wielka_litera_na_poczatku(slownik[i]), dopisane_cyfry);
        
        }

        //Całe słowo z wielkich liter
        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            slowo_ze_slownika_postfix(cale_slowo_wielka_litera(slownik[i]), dopisane_cyfry);
        
        }
    }

    pthread_exit(NULL);
}

void* producent_3(void*){

    for(int i = 0; i < slownik.size(); i++){

        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            //czyste słowo ze słownika 
            slowo_ze_slownika_prefix_postfix(slownik[i], dopisane_cyfry);
        
        }

        //Wielka pierwsza litera
        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            slowo_ze_slownika_prefix_postfix(wielka_litera_na_poczatku(slownik[i]), dopisane_cyfry);
        
        }

        //Całe słowo z wielkich liter
        for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
            slowo_ze_slownika_prefix_postfix(cale_slowo_wielka_litera(slownik[i]), dopisane_cyfry);
        
        }
    }

    pthread_exit(NULL);
}

void* producent_4(void*){

    for(int i = 0; i < slownik.size(); i++){
        for(int j = 0; j < slownik.size(); j++){

            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                //czyste słowo ze słownika 
                dwa_slowa_z_cyframi(slownik[i], slownik[j], dopisane_cyfry);
            
            }

            //Pierwsze slowo z wielkiej, drugie z małej
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(wielka_litera_na_poczatku(slownik[i]), slownik[j], dopisane_cyfry);
            
            }

            //Pierwsze slowo z małej, drugie z wielkiej
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(slownik[i], wielka_litera_na_poczatku(slownik[j]), dopisane_cyfry);
            
            }

             //Pierwsze słowo całe wielkimi liereami, drugie całe małymi
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(cale_slowo_wielka_litera(slownik[i]), slownik[j], dopisane_cyfry);
            
            }

             //Pierwsze słowo całe wielkimi liereami, drugie z wielkiej
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(cale_slowo_wielka_litera(slownik[i]), wielka_litera_na_poczatku(slownik[j]), dopisane_cyfry);
            
            }

            //Pierwsze słowo całe małymi liereami, drugie całe wielkimi
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(slownik[i], cale_slowo_wielka_litera(slownik[j]), dopisane_cyfry);
            
            }
            
               //Pierwsze słowo z wielkiej, drugie całe wielkimi
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(wielka_litera_na_poczatku(slownik[i]), cale_slowo_wielka_litera(slownik[j]), dopisane_cyfry);
            
            }

             //Pierwsze słowo z wielkiej, drugie z wielkiej
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(wielka_litera_na_poczatku(slownik[i]), wielka_litera_na_poczatku(slownik[j]), dopisane_cyfry);
            
            }

            //Oba słowa z wielkich liter
            for(int dopisane_cyfry = 1; dopisane_cyfry < ILOSC_DOPISANYCH_CYFR; dopisane_cyfry++){
                dwa_slowa_z_cyframi(cale_slowo_wielka_litera(slownik[i]), cale_slowo_wielka_litera(slownik[j]), dopisane_cyfry);
            
            }
        }
    }

    pthread_exit(NULL);
}

void* producent_5(void*){
    for(int i = 0; i < slownik.size(); i++){
        for(int j = 0; j < slownik.size(); j++){
            //oba słowa z małych liter
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(slownik[i],slownik[j],liczba_dopisanych_znakow);

            //pierwsze słowo z wielkiej, drugie bez zmian
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(wielka_litera_na_poczatku(slownik[i]),slownik[j],liczba_dopisanych_znakow);

            //pierwsze słowo całe wielkimi, drugie bez zmian
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(cale_slowo_wielka_litera(slownik[i]),slownik[j],liczba_dopisanych_znakow);

            //pierwsze słowo bez zmian, drugie z wielkiej
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(slownik[i],wielka_litera_na_poczatku(slownik[j]),liczba_dopisanych_znakow);

            //pierwsze słowo bez zmian, drugie całe wielkimi
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(slownik[i],cale_slowo_wielka_litera(slownik[j]),liczba_dopisanych_znakow);

            //pierwsze słowo z wielkiej, drugie z wielkiej
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(wielka_litera_na_poczatku(slownik[i]),wielka_litera_na_poczatku(slownik[j]),liczba_dopisanych_znakow);

            //pierwsze słowo z wielkiej, drugie całe wielkimi
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(wielka_litera_na_poczatku(slownik[i]),cale_slowo_wielka_litera(slownik[j]),liczba_dopisanych_znakow);

            //pierwsze słowo całe wielkimi, drugie z wielkiej
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(cale_slowo_wielka_litera(slownik[i]),wielka_litera_na_poczatku(slownik[j]),liczba_dopisanych_znakow);

            //oba słowa z wielkiej
            for(int liczba_dopisanych_znakow = 1; liczba_dopisanych_znakow < ILOSC_DOPISANYCH_ZNAKOW; liczba_dopisanych_znakow++) dwa_slowa_ze_znakami(cale_slowo_wielka_litera(slownik[i]),cale_slowo_wielka_litera(slownik[j]),liczba_dopisanych_znakow);

            
        }
    }
    pthread_exit(NULL);
}

void* watek_konsumenta(void*){
    signal(SIGHUP, SIGHUP_HANDLER);

    int ilosc_zlamanych_hasel = 0;
    while(ilosc_zlamanych_hasel < hasla_do_zlamania.size()){
        pthread_mutex_lock(&mutex_konsument);
        pthread_cond_wait(&zlamano_haslo, &mutex_konsument);
        ilosc_zlamanych_hasel++;
        std::cout << "Login: " << zlamane_hasla[ilosc_zlamanych_hasel-1].login << " Emial: " << zlamane_hasla[ilosc_zlamanych_hasel-1].mail << " znalezione hasło: " << zlamane_hasla[ilosc_zlamanych_hasel-1].zlamane_haslo  << "\n";
        pthread_mutex_unlock(&mutex_konsument);
    }
    //std::cout << "Wątek konsumenta zakończył pracę\n";
    pthread_exit(NULL);
}