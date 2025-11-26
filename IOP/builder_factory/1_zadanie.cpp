#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Postac{
  private:
    string nazwa;
    int sila;
    int zrecznosc;
    int inteligencja;
    vector<string> umiejetnosci;
  public:
    void setNazwa(string nazwa){
      this->nazwa = nazwa;
    }
    void setSila(int sila){
      this->sila = sila;
    }
    void setZrecznosc(int zrecznosc){
      this->zrecznosc = zrecznosc;
    }
    void setInteligencja(int inteligencja){
      this->inteligencja = inteligencja;
    }
    void setUmiejetnosci(string umiejetnosc){
      this->umiejetnosci.push_back(umiejetnosc);
    }

    void printStats(){
      cout<<"NAZWA:"<<nazwa << endl;      
      cout<<"SILA:"<<sila << endl;      
      cout<<"ZRECZNOSC:"<<zrecznosc << endl;      
      cout<<"INTELIGENCJA:"<<inteligencja << endl;      
      cout<<"UMIEJETNOSCI:"<< endl;
      for(string umiejetnosc : umiejetnosci){
        cout << umiejetnosc << endl;
      }
    }//printstats

};//Postac

class Budowniczy{
  protected:
    //klasa gotowej postaci w sensie pointer na niom
    Postac *current_postac;

  public:
    void nowaPostac(){
      current_postac = new Postac;
    }
    Postac utworzPostac(){
      return *current_postac;
    }

    virtual void buildNazwa()=0;
    virtual void buildSila()=0;
    virtual void buildZrecznosc()=0;
    virtual void buildInteligencja()=0;
    virtual void buildUmiejetnosci()=0;
};


class budowniczyRycerza:public Budowniczy{
  public:
    //current_postac (ptr) = aktualny obiekt
    budowniczyRycerza():Budowniczy(){}

    void buildNazwa(){
      current_postac->setNazwa("Rycerz");
    }
    void buildSila(){
      current_postac->setSila(20);
    }
    void buildZrecznosc(){
      current_postac->setZrecznosc(10);
    }
    void buildInteligencja(){
      current_postac->setInteligencja(5);
    }
    void buildUmiejetnosci(){
      current_postac->setUmiejetnosci("Pierdolniecie w leb");
      current_postac->setUmiejetnosci("Dzien dobry bileciki do kontroli");
      current_postac->setUmiejetnosci("punch pelen essy");
    }
};//dla siebie ess

class budowniczyLucznika:public Budowniczy{
  public:
    //current_postac (ptr) = aktualny obiekt
    budowniczyLucznika():Budowniczy(){}

    void buildNazwa(){
      current_postac->setNazwa("Lucznik");
    }
    void buildSila(){
      current_postac->setSila(10);
    }
    void buildZrecznosc(){
      current_postac->setZrecznosc(20);
    }
    void buildInteligencja(){
      current_postac->setInteligencja(5);
    }
    void buildUmiejetnosci(){
      current_postac->setUmiejetnosci("strzala w kolano");
      current_postac->setUmiejetnosci("pa tera XD");
      current_postac->setUmiejetnosci("nacharanie na pysk");
    }
};//dla siebie ess

class budowniczyMaga:public Budowniczy{
  public:
    //current_postac (ptr) = aktualny obiekt
    budowniczyMaga():Budowniczy(){}

    void buildNazwa(){
      current_postac->setNazwa("Magger");
    }
    void buildSila(){
      current_postac->setSila(5);
    }
    void buildZrecznosc(){
      current_postac->setZrecznosc(10);
    }
    void buildInteligencja(){
      current_postac->setInteligencja(20);
    }
    void buildUmiejetnosci(){
      current_postac->setUmiejetnosci("cast spermball");
      current_postac->setUmiejetnosci("summon zul");
      current_postac->setUmiejetnosci("call jesus");
      current_postac->setUmiejetnosci("dopraw potrawe (uzyj magi)");
    }
};//dla siebie ess

class Director{
  private:
    Budowniczy* budowniczy;
  public:
    void setBudowniczy(Budowniczy *b){
      this->budowniczy = b;
    }
    Postac utworzPostac(){
      return budowniczy ->utworzPostac();
    } 

    void tworzenie(){
      budowniczy->
    }
}

int main(){
  

  return 0;
}
