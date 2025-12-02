#include<iostream>




//WAGA INICJALIZUJE SIE 3 RAZY W CHUJ PROBLEM NP PRZY MALLOC
class Waga{
  public:
    int n;
    char jednostka;
    Waga(){
      n = 0;
      jednostka = 'k';
      std::cout << "\033[1;44mWAGA KONSTRUKTOR\033m[" << std::endl;
      
    }
    Waga(int n, char jednostka){
      this->n = n;
      this->jednostka = jednostka;
      std::cout << "\e[1;36mWAGA KONSTRUKTOR2\e[m" << std::endl;
      
    }
};


class Pojazd{
  public:
    int ileKol;
    float predkosc;
    Waga w;
    
    void przedstaw(){std::cout << "POJAZD\n";}
    //lista inicjalizacyjna pomaga ominac trzykrotne wykorzystanie konstruktora
    Pojazd() : ileKol(0),predkosc(0),w(Waga(1,'t')){
      std::cout << "POJAZD KONSTRUKTOR" << std::endl;
      ileKol = 0;
    }
    Pojazd(int waga) : ileKol(0),predkosc(0),w(Waga(waga,'t')){
      std::cout << "POJAZD KONSTRUKTOR2" << std::endl;

    }
    ~Pojazd(){
      std::cout << "POJAZD DESTRUKTOR" << std::endl;

    }
};



class nowySamochod : public Pojazd{
  public:
    int ileDrzwi;
    //ponizej jest pulapka, bedzie dzialalo, ale:
    //w nie jest czescia samochodu tylko pojazdu, lista pozwala inicjalizowac tylko te leementy ktore naleza do klasy
    //nowySamochod() : w(waga(500,'k')){
    nowySamochod(int ileDrzwi) : Pojazd(500),ileDrzwi(ileDrzwi){
      std::cout << "SAMOCHOD KONSTRUKTOR" << std::endl;
      ileKol = 4;
    }
    ~nowySamochod(){
      std::cout << "SAMOCHOD DESTRUKTOR" << std::endl;

    }
};

class SamochodSportowy : public nowySamochod{
  public:
    void przedstaw(){Pojazd::przedstaw(); std::cout << "SAMOCHOD SPORTOWY\n";}
    SamochodSportowy() : nowySamochod(3){
      std::cout << "SAMOCHOD SPORTOWY KONSTRUKTOR" << std::endl;

    }
    ~SamochodSportowy(){
      std::cout << "SAMOCHOD SPORTOWY DESTRUKTOR" << std::endl;

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
    nowySamochod autko(5);
    std::cout << "ilosc drzwi autka: " << autko.ileDrzwi << "\n";
    std::cout << "ilosc kol autka: " << autko.ileKol << "\n";
    std::cout << "waga autka: " << autko.w.n << "\n";
    SamochodSportowy ss;
    std::cout << "ilosc drzwi ss: " << ss.ileDrzwi << "\n";
    ss.przedstaw();


  return 0;
}
