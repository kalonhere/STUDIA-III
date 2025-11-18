#include<iostream>

#include "karta.h"

int karta::nastepny_numer_karty = 200;

karta::karta(int termin_karty){
    this->termin_karty = termin_karty;
    this->numer_karty = nastepny_numer_karty;
    nastepny_numer_karty += 10;
}

int karta::wypisz_date(){
    return this->termin_karty;
}

void karta::zwieksz_numer_karty(){
    nastepny_numer_karty += 1;
}


