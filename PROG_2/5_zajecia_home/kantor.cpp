#include <cstdlib>
#include<iostream>

#include "kantor.h"

kantor::kantor(float marza, int arr_size){
  this->kurs_kwota_USD = 3.65;
  this->kurs_kwota_PLN = 0.26;
  this->marza = marza;

  this->history_pointer = new float[arr_size];
  this->history_index = 0;
  this->history_size = arr_size;
  
};

void kantor::addHistory(float kwota){
  if(this->history_index != 4){
    this->history_pointer[this->history_index] = kwota;
    this->history_index++;
  }
  if(this->history_index == 4){
    this->history_index = 0;
    this->history_pointer[this->history_index] = kwota;
    this->history_index++;
  }
  
}//addHistory

void kantor::printHistory(){
  for(int i = 0; i<this->history_size; i++){
    if(this->history_pointer[i] != 0)std::cout << (i+1) << ". Kwota przekazana: " <<  this->history_pointer[i] << std::endl;
  }

}

void kantor::przeliczKwote(float kwota, CURRENCY input, CURRENCY output){
  if(input == output){std::cout<<"taka sama waluta\n";}
  if(output == PLN){
    std::cout << "przeliczanie " << kwota << " PLN na USD: " << (kwota*kurs_kwota_USD*marza) << std::endl;
    kantor::addHistory(kwota);
  }
  if(output == USD){
    std::cout << "przeliczanie " << kwota << " USD na PLN: " << (kwota*kurs_kwota_PLN*marza) << std::endl;
    kantor::addHistory(kwota);
  }
  
}//przelicz kwote
kantor::~kantor(){
  delete[] history_pointer;
}
