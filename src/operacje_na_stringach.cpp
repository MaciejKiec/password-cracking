#include "operacje_na_stringach.hh"


void czy_zlamano(int index, std::string slowo, std::string md5_slowa){
    if(hasla_do_zlamania[index].hash_hasla == md5_slowa && hasla_do_zlamania[index].zlamane_haslo.empty()){
        pthread_mutex_lock(&mutex_zapisu_hasla);
        hasla_do_zlamania[index].zlamane_haslo = slowo;
        zlamane_hasla.push_back(hasla_do_zlamania[index]);
        pthread_cond_signal(&zlamano_haslo);
        pthread_mutex_unlock(&mutex_zapisu_hasla);
    }
}

void sprawdz_dla_kazdego_hasla(std::string slowo, std::string md5_slowa){
    for(int i = 0; i < hasla_do_zlamania.size(); i++){
        if(hasla_do_zlamania[i].zlamane_haslo.empty()); czy_zlamano(i, slowo ,md5_slowa);
    }
}

void funkcja_hashujaca(const char *data, int len, char *md5buf) {
	EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
	const EVP_MD *md = EVP_md5();
	unsigned char md_value[EVP_MAX_MD_SIZE];
	unsigned int md_len, i;
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, data, len);
	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
	EVP_MD_CTX_free(mdctx);
	for (i = 0; i < md_len; i++) {
		snprintf(&(md5buf[i * 2]), 16 * 2, "%02x", md_value[i]);
	}
}

std::string zwroc_hash_w_stringu(std::string string_do_zhashowania){
     char hash_wynikowy[33];
     funkcja_hashujaca(string_do_zhashowania.c_str(), string_do_zhashowania.length(), hash_wynikowy);
     return (std::string)hash_wynikowy;
}

std::string wielka_litera_na_poczatku(std::string slowo){
    slowo[0] = toupper(slowo[0]);
    return slowo;
}

std::string cale_slowo_wielka_litera(std::string slowo){
    for(int i = 0; i < slowo.length(); i++) slowo[i] = toupper(slowo[i]);
    return slowo;

}