#include <cstdlib>
#include<iostream>


void debugMessage(const char* message){
#ifdef DEBUG
  std::cout<<"***** "<<message<<" *****\n"; 
#endif
}


#include "kantor.h"

kantor::kantor(float marza, int arr_size){  
  this->kurs_kwota_USD = 3.65;
  this->kurs_kwota_PLN = 0.26;
  this->marza = marza;

  this->history_pointer = new float[arr_size];
  this->history_index = 0;
  this->history_size = arr_size;
  
};

kantor::kantor(const kantor &kantor_template){
  debugMessage("Used copying");
  this->kurs_kwota_USD = kantor_template.kurs_kwota_USD;
  this->kurs_kwota_PLN = kantor_template.kurs_kwota_PLN;
  this->marza = kantor_template.marza;

  this->history_size = kantor_template.history_size;
  this->history_pointer = new float[kantor_template.history_size];
  this->history_index = kantor_template.history_index;

  
  for(int i = 0; i<=this->history_index; i++){
    this->history_pointer[i] = kantor_template.history_pointer[i];
  }
}


void kantor::addHistory(float kwota){
  if(this->history_index != (this->history_size-1)){
    this->history_pointer[this->history_index] = kwota;
    this->history_index++;
  }
  if(this->history_index == (this->history_size-1)){
    this->history_index = 0;
    this->history_pointer[this->history_index] = kwota;
    this->history_index++;
  }
  
}//addHistory

void kantor::printLastTransaction(){
  std::cout<<this->history_index<<". Kwota przekazana: "<<this->history_pointer[this->history_index-1] << std::endl;
}

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
  debugMessage("destructor used");
  delete[] history_pointer;
}
