#include<iostream>

#include "karta.h"


int main(){
    karta Karta1(19022005);
    karta Karta2(29092004);

    std:: cout << "Data: " << Karta1.wypisz_date() << std::endl;
    Karta1.zwieksz_numer_karty();





    return 0;
}
