#include "Kantor.h"

float Kantor::kurs =3.5;

Kantor::Kantor(float marza){
    this->marza = marza;
}

float Kantor::transfer(float kwota){
    //tutaj dopsiz do historii wpis
    return kwota*kurs*marza;
}
Kantor::~Kantor(){
    delete[] tab;
}
