#include<iostream>
using namespace std;

#include "kantor.h"

void compareMarzaxd(kantor Kantor1, kantor Kantor2){
  if(Kantor1.marza > Kantor2.marza){
    cout << "Kantor po lewej ma mniejsza marze\n";
    return;
  }
  if(Kantor1.marza < Kantor2.marza){
    cout << "Kantor po prawej ma mniejsza marze\n";
    return;
  }
  cout << "Kantory maja taka sama marze\n";
  return;
}



int main(){
  kantor Kantor1(0.95,8);
  kantor Kantor2(0.99,7);
  
  Kantor1.przeliczKwote(30,PLN,USD);
  Kantor2.przeliczKwote(30,PLN,USD);
  Kantor1.przeliczKwote(40,PLN,USD);
  Kantor1.przeliczKwote(40,PLN,USD);
  Kantor1.przeliczKwote(18,USD,PLN);

  cout << "History Kantor1:\n";
  Kantor1.printHistory();
  cout << "History Kantor2:\n";
  Kantor2.printHistory();
  cout << "History Kantor3:\n";
 
  cout << "Last transaction for Kantor1:\n";
  Kantor1.printLastTransaction();
  cout << "Last transaction for Kantor2:\n";
  Kantor2.printLastTransaction();
  
  compareMarzaxd(Kantor1, Kantor2);


  return 0;
}
