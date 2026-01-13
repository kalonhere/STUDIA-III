#include<iostream>
using namespace std;


class wyjatek : public exception{
  public:
    char znaczek;
    wyjatek(char znaczek){
      this->znaczek = znaczek;
  }
    virtual const char* what() const noexcept{
      return "Niepoprawna literka. Zakres: a-z\n";
    }
};

int przyjmijZnak(char literka){
  int liczba = (int)literka;
  if((liczba >= 97) && (liczba<=122)){
    return liczba;
  }else{
    throw wyjatek(literka);
  }
}


int main(){


  char a = 'a';
  char Z = 'Z';
  try{
    int liczebka = przyjmijZnak(a);
    printf("znak: %c, wartosc ascii: %d\n",liczebka,liczebka);
    liczebka = przyjmijZnak(Z);
    printf("znak: %c, wartosc ascii: %d\n",liczebka,liczebka);
  }catch(wyjatek &essa){
    cout << "Wyjatek: " << essa.what() << "\n"; 
  };


  return 0;
}
