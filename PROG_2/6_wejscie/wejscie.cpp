#include<iostream>
using namespace std;

class Kot {

  public:
    int wiek;
    string imie;

    void dajGlos(){
      cout << "Miau! :3";
    }

    Kot(int wiek, string imie){
      this->wiek = wiek;
      this->imie = imie;
    }
};

class Tygrys : public Kot{
  public:


  void dajGlos(){
    cout << "Roar!";
  }


  Tygrys(int wiek, string imie) : Kot( wiek, imie){
    
  };


};

int main(){

  Tygrys kicia(10,"essa");

  kicia.dajGlos();
  



  return 0;
}
