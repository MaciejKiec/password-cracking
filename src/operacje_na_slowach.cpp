#include "operacje_na_slowach.hh"


void slowo_ze_slownika_prefix(std::string slowo, int liczba_dopisanych_cyfr){

    if (liczba_dopisanych_cyfr < 1){
        std::cerr << "Wystąpił błąd! Wprowadzono złą liczbę dopisanych cyfr!\n";
        exit(0);
    }

    std::string temp = slowo;
    int liczba_zer = liczba_dopisanych_cyfr;
    temp.insert(0,liczba_zer,'0');
    
    for(int i = 1; i < pow(10,liczba_dopisanych_cyfr); i++){
        temp = std::to_string(i) + slowo;
        liczba_zer = liczba_dopisanych_cyfr - 1 - floor(log10(i));
        if(liczba_zer > 0) temp.insert(0,liczba_zer,'0');
        sprawdz_dla_kazdego_hasla(temp,zwroc_hash_w_stringu(temp));
    }
    
}


void slowo_ze_slownika_postfix(std::string slowo, int liczba_dopisanych_cyfr){
     if (liczba_dopisanych_cyfr < 1){
        std::cerr << "Wystąpił błąd! Wprowadzono złą liczbę dopisanych cyfr!\n";
        exit(0);
    }

    std::string temp = slowo;
    int liczba_zer = liczba_dopisanych_cyfr;
    temp.insert(temp.length(),liczba_zer,'0');

    for(int i = 1; i < pow(10,liczba_dopisanych_cyfr); i++){
        liczba_zer = liczba_dopisanych_cyfr - 1 - floor(log10(i));
        temp = slowo;
        if(liczba_zer > 0) temp.insert(temp.length(),liczba_zer,'0');
        temp = temp + std::to_string(i);
        sprawdz_dla_kazdego_hasla(temp,zwroc_hash_w_stringu(temp));
    }

}

void slowo_ze_slownika_prefix_postfix(std::string slowo, int liczba_dopisanych_cyfr){
    if (liczba_dopisanych_cyfr < 1){
        std::cerr << "Wystąpił błąd! Wprowadzono złą liczbę dopisanych cyfr!\n";
        exit(0);
    }

    std::string temp = slowo;
    std::string temp1;
    int liczba_zer = liczba_dopisanych_cyfr;
    temp.insert(0,liczba_zer,'0');
    
    for(int i = 1; i < pow(10,liczba_dopisanych_cyfr); i++){
        temp = std::to_string(i) + slowo;
        liczba_zer = liczba_dopisanych_cyfr - 1 - floor(log10(i));
        if(liczba_zer > 0) temp.insert(0,liczba_zer,'0');
        temp.insert(temp.length(),liczba_zer,'0');
            for(int j = 1; j < pow(10,liczba_dopisanych_cyfr); j++){
            temp1 = temp;
            liczba_zer = liczba_dopisanych_cyfr - 1 - floor(log10(j));
            if(liczba_zer > 0) temp1.insert(temp1.length(),liczba_zer,'0');
            temp1 = temp1 + std::to_string(j);
            sprawdz_dla_kazdego_hasla(temp1,zwroc_hash_w_stringu(temp1));
        }  
    }

}

void dwa_slowa_z_cyframi(std::string slowo1, std::string slowo2, int liczba_dopisanych_cyfr){
    if (liczba_dopisanych_cyfr < 1){
        std::cerr << "Wystąpił błąd! Wprowadzono złą liczbę dopisanych cyfr!\n";
        exit(0);
    }

    std::string temp = slowo1;
    int liczba_zer = liczba_dopisanych_cyfr;
    temp.insert(temp.length(),liczba_zer,'0');

    for(int i = 1; i < pow(10,liczba_dopisanych_cyfr); i++){
        liczba_zer = liczba_dopisanych_cyfr - 1 - floor(log10(i));
        temp = slowo1;
        if(liczba_zer > 0) temp.insert(temp.length(),liczba_zer,'0');
        temp = temp + std::to_string(i) + slowo2;
        sprawdz_dla_kazdego_hasla(temp,zwroc_hash_w_stringu(temp));
    }


}

void dwa_slowa_ze_znakami(std::string slowo1, std::string slowo2, int liczba_dopisanych_znakow){
    if (liczba_dopisanych_znakow < 1){
        std::cerr << "Wystąpił błąd! Wprowadzono złą liczbę dopisanych cyfr!\n";
        exit(0);
    }

    std::string wyjsciowe_slowo1, wyjsciowe_slowo2, wyjsciowe_slowo3, wyjsciowe_slowo4, wyjsciowe_slowo5;
    std::string tablica_znakow[5] = {"#","@","!","$","*"};

        for(int i = 0; i < 5; i++){
            wyjsciowe_slowo1 = slowo1;
            wyjsciowe_slowo1 += tablica_znakow[i];
            if(liczba_dopisanych_znakow == 1){
                wyjsciowe_slowo1 += slowo2;
                sprawdz_dla_kazdego_hasla(wyjsciowe_slowo1,zwroc_hash_w_stringu(wyjsciowe_slowo1));
                continue;
            }
            for(int j = 0; j < 5; j++){
                    wyjsciowe_slowo2 = wyjsciowe_slowo1;
                    wyjsciowe_slowo2 += tablica_znakow[j];
                    if(liczba_dopisanych_znakow == 2){
                        wyjsciowe_slowo2 += slowo2;
                        sprawdz_dla_kazdego_hasla(wyjsciowe_slowo1,zwroc_hash_w_stringu(wyjsciowe_slowo1));
                        continue;
                    }
                    for(int k = 0; k < 5; k++){
                        wyjsciowe_slowo3 = wyjsciowe_slowo2;
                        wyjsciowe_slowo3 += tablica_znakow[k];
                        if(liczba_dopisanych_znakow == 3){
                            wyjsciowe_slowo3 += slowo2;
                            sprawdz_dla_kazdego_hasla(wyjsciowe_slowo1,zwroc_hash_w_stringu(wyjsciowe_slowo1));
                            continue;
                        }
                        for(int l = 0; l < 5; l++){
                            wyjsciowe_slowo4 = wyjsciowe_slowo3;
                            wyjsciowe_slowo4 += tablica_znakow[l];
                            if(liczba_dopisanych_znakow == 4){
                                wyjsciowe_slowo4 += slowo2;
                                sprawdz_dla_kazdego_hasla(wyjsciowe_slowo1,zwroc_hash_w_stringu(wyjsciowe_slowo1));
                                continue;
                            }
                            for(int o = 0; o < 5; o++){
                                wyjsciowe_slowo5 = wyjsciowe_slowo4;
                                wyjsciowe_slowo5 += tablica_znakow[o];
                                if(liczba_dopisanych_znakow == 5){
                                    wyjsciowe_slowo5 += slowo2;
                                    sprawdz_dla_kazdego_hasla(wyjsciowe_slowo1,zwroc_hash_w_stringu(wyjsciowe_slowo1));
                                }

                            }

                        }

                    }

            }
    }
}