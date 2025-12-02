#include<iostream>




//WAGA INICJALIZUJE SIE 3 RAZY W CHUJ PROBLEM NP PRZY MALLOC
class Waga{
  public:
    int n;
    char jednostka;
    Waga(){
      n = 0;
      jednostka = 'k';
      std::cout << "WAGA KONSTRUKTOR" << std::endl;
      
    }
    Waga(int n, char jednostka){
      this->n = n;
      this->jednostka = jednostka;
      std::cout << "WAGA KONSTRUKTOR2" << std::endl;
      
    }
};


class Pojazd{
  public:
    int ileKol;
    float predkosc;
    Waga w;
    Pojazd(){
      w = Waga(1,'t');
      std::cout << "POJAZD KONSTRUKTOR" << std::endl;
      ileKol = 0;
    }
};



class nowySamochod : public Pojazd{
  public:
    int ileDrzwi;
    //ponizej jest pulapka, bedzie dzialalo, ale:
    nowySamochod(){
      std::cout << "SAMOCHOD KONSTRUKTOR" << std::endl;
      w = Waga(500, 'k');
      ileKol = 4;
    }
};




class Ciezarowka:public Pojazd{
  public:
    int pojemnoscPrzyczepy;
};
class Rower:public Pojazd{
  public:  
    bool czyMaDzwonek;
};

//widac ze pola sie powtarzaja
/*
class Ciezarowka{
  public:
    int ileKol;
    float predkosc;
    int pojemnoscPrzyczepy;
};

class Samochod{
  public:
    int ileKol;
    int ileDrzwi;
    float predkosc;
};

class Rower{
  public:  
    int ileKol;
    float predkosc;
    bool czyMaDzwonek;
};
*/


int main(){
    nowySamochod autko;
    std::cout << "ilosc kol autka: " << autko.ileKol << "\n";


  return 0;
}
