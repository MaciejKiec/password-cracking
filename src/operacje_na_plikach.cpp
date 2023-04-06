#include "operacje_na_plikach.hh"

bool wczytaj_plik_z_haslami(std::string nazwa_pliku_do_wczytania, std::vector<Haslo>* hasla){

     hasla->clear();
     std::fstream plik_z_haslami;
     plik_z_haslami.open(nazwa_pliku_do_wczytania);

    if(plik_z_haslami){
        std::string hash, trash, mail, login;

     while(!plik_z_haslami.eof()){
          plik_z_haslami >> trash >> hash >> mail >> login;
          getline(plik_z_haslami,trash);
          hasla->push_back(Haslo {hash,login,mail});
     }
     plik_z_haslami.close();
     return true;
    }else{
        return false;
    }

}

bool wczytaj_slownik(std::string nazwa_pliku_do_wczytania, std::vector<std::string>* slownik){
     slownik->clear();
     std::fstream plik_slownika;
     plik_slownika.open(nazwa_pliku_do_wczytania);

     if(plik_slownika){
        std::string bufor;

        while(!plik_slownika.eof()){
            plik_slownika >> bufor;
            slownik->push_back(bufor);
        }
        plik_slownika.close();
        return true;
     }else{
        return false;
     }
}