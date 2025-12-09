#include<iostream>
#include<string>
using namespace std;


class Zwierze{
  public:
    string imie;
    virtual string dajGlos(){
      return "--Jakis Dzwiek--";
    }

    virtual void spij(short int t){
      cout << "Zwierz spi "<<t << " sekund" << endl;
    }

    virtual ~Zwierze(){
      cout << "destruktor zwierze" << endl;
    }
    //jezeli mamy metode abstrakcyjna to sama klasa staje sie abstrakcyjna 
    //klasa abstrakcyjna wymusza na nas zaimplementowanie wszystkich metod abstrakcyjnych
    virtual string dajGlosPure() = 0;
};


class Pies : public Zwierze{
  public:
    string dajGlos(){
      return "Woof";
    }


};

class Kot : public Zwierze{
  public:
    string dajGlos() override{
      return "Meow :3";
    }
    //jako ze spij posiada int a nie short int to nie powstalo nadpisanie funkcji, uruchamia sie ze zwierza
    //przy uzyciu override kompilator zostaje wymuszony ALE takiej metody nie ma i trzeba dodac wtedy short int (ERROR)
    void spij(short int t) override {
      cout << "Kot spi "<<t << " sekund" << endl;
    }
    ~Kot(){
      cout << "destruktor kot" << endl;
    }
    string dajGlosPure() override {
      return "essa";
    }



};



int main(){
  //Kot k;
  //Zwierze z = k;//uwaga tutaj zmienna 'z' bedzie kotem ale nie bedzie posiadala czesci kocieja
                //
                //
                //

  //trzeba dodac virtual destructor aby wywolywal sie poptrawnie. jezeli zakladamy ze destruktor cos niszczy albo bedzie on dziedziczony to tak jak najbardziej
  Zwierze *ptr = new Kot(); //blad ?
  delete ptr;
  /*
  Zwierze &kRef = k;
  Zwierze *kPtr = &k;
  //tablica wskaznikow - zwierzat
  Zwierze *tab[6];
  //w virtual wielkosc funkcji sie zwieksza bo pojawia sie "v pointer" i jest on wskaznikiem na tablice na wskaznikow na funkcje
  cout << sizeof(Zwierze) << endl;

  tab[0] = new Kot();
  tab[1] = new Kot();
  tab[2] = new Kot();
  tab[3] = new Pies();
  tab[4] = new Pies();
  tab[5] = new Pies();

  for(int i = 0;i<6;i++){
    cout << tab[i]->dajGlos() << endl;
  }


  kRef.spij(10);
  
  */
  /*
  Kot &kRef = k;
  Kot *kPtr = &k; //nie trzeba robic new (chyba wiadome)
  */
  //cout << k.dajGlos() << endl;
  //cout << kRef.dajGlos() << endl;
  //cout << kPtr->dajGlos() << endl;


  return 0;
}
