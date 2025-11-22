#include<iostream>
using namespace std;

#include "kantor.h"

int main(){
  kantor Kantor1(0.95,8);
  kantor Kantor2(0.99,7);
  

  Kantor1.przeliczKwote(30,PLN,USD);
  Kantor2.przeliczKwote(30,PLN,USD);
  Kantor1.przeliczKwote(40,PLN,USD);
  Kantor1.przeliczKwote(40,PLN,USD);
  Kantor1.przeliczKwote(18,USD,PLN);


  Kantor1.printHistory();
  Kantor2.printHistory();
  



  return 0;
}
