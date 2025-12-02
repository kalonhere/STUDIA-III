#include<iostream>
using namespace std;

typedef enum{
  START = 0,
  KONIEC = 1
} CZAS;


class Pracownik{
  public:
    string imie;
    int wynagrodzenie;
    int pesel;
    int godziny_pracy[2];
    
    Pracownik(string imie, int wynagrodzenie, int pesel, int start, int koniec): imie(imie){
      this->wynagrodzenie = wynagrodzenie;
      this->pesel = pesel;
      godziny_pracy[START] = start;
      godziny_pracy[KONIEC] = koniec;
    }
};


class Dyrektor : public Pracownik{
  public:
    char dzial;
    Dyrektor(char dzial,string imie, int wynagrodzenie, int pesel, int start, int koniec): Pracownik(imie,wynagrodzenie,pesel,start,koniec){
      this->dzial = dzial;
    }

};

class Kierowca : public Pracownik{
  public:
    char prawo_jazdy;
    Kierowca(char prawo_jazdy,string imie, int wynagrodzenie, int pesel, int start, int koniec): Pracownik(imie,wynagrodzenie,pesel,start,koniec){
      this->prawo_jazdy = prawo_jazdy;
    }
};

class Dostawca : public Kierowca{
  public:
    string typ;
    Dostawca(char typ,char prawo_jazdy,string imie, int wynagrodzenie, int pesel, int start, int koniec): Kierowca(prawo_jazdy,imie,wynagrodzenie,pesel,start,koniec){
      this->prawo_jazdy = prawo_jazdy;
    }


};

int main(){




  return 0;
}
