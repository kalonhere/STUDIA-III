#include <iostream>
using namespace std;

//mozna zamienic struct na class bez problemow kompilacji na tym etapie :3
/*struct Film {
    string tytul;
    int czasTrwania;
};*/


//klasy w odroznieniu od struktur maja rowniez metody
//w strukturze wszystko jest domyslnie publiczne, a w klasie prywatne
//nie chcemy czasami dawac pelnej swobody uzytkownikowi, mozemy dac interfejs ale nie bezposrednia wladze
// zmienne w klasie z bomby sa prywatne 
//klasy potrafia wywolywac pewne metody
class Film {
//private jest z bomby 

public:
    string tytul;
    int czasTrwania;
    int rok_premiery;
    float dlugosc_rozdzialu;
    float *tab;
//tworzenie konstruktora klasy Film bezargumentowy
//najczesciej uzywany by zainicjowac obiekt w oczywistym stanie nie mozna zostawiac smieci przy inizjalizacji obiektu
    Film(){
        tytul = "--brak--";
        czasTrwania = 0;
        rok_premiery = 0;
        dlugosc_rozdzialu = 0;
        tab = nullptr;
        cout << "NO ARG KONSTRUKTOR" << endl;
    }
    
    Film(string tytul){ //przeciazenie metody, zachowuje ona sie inaczej w zaleznosci od argumentu (rodzaju)
        this->tytul = tytul;
        czasTrwania = 30 + rand() % 91;
        rok_premiery = 1980 + rand() % 50;
        dlugosc_rozdzialu = czasTrwania / 10.f;
        tab = new float(rok_premiery);
        cout << "1 ARG KONSTRUKTOR" << endl;
    }
    
    Film(string tytul, int czasTrwania, int rok_premiery){
        this->tytul = tytul;
        this->czasTrwania = czasTrwania;
        this->rok_premiery = rok_premiery;
        dlugosc_rozdzialu = czasTrwania / 10.f;
        tab = new float(rok_premiery);
        cout << "3 ARG KONSTRUKTOR" << endl;
    }


    //DESTRUKTOR
    ~Film(){ //zadaniem jego jest sprzatanie po sobie
        delete[] tab;
        cout << "DESTRUKTOR" << endl;

    }


        bool isFromXXICentury(){
        //zwroc true jezeli wiadomo
        return rok_premiery > 2000;
    }
    void printData(){
        cout << "Tytul: " << tytul << "| Czas trwania: " << czasTrwania << "| Rok premiery: " << rok_premiery << endl;
    }
};

class KontoBankowe{
    private:
        int kwota = 0;
    public:
        int sprawdzKwote(){
            return kwota;
        }
        void wplac(int kwota){
            //this wskazuje na pole kwota dla konkretnego obiektu, mozna zmienic income kwote na inna nazwe zmiennej
            //to wtedy nie trzeba pisac this
            this->kwota += kwota;
        }
        int wyplac(int kwota){
            int zProwizja = kwota *1.05;
            if(this->kwota >= zProwizja){
                this->kwota -= zProwizja;
                //ponizszy return zwraca wybrane pieniadze wprowadzone przez uzytkownika 
                return kwota;
            }
            return 0;

        }

};//class konto




int main(){
    Film f;
    //f jest OBIEKTEM KLASY film
    
    //jak jest klasa to nie mozna ustawiac tak pol ( bo z bomby sa prywatne )
    //tera mozemy bo sa pod public
    //ustawienie danych
    //f.tytul = "abc";
    //f.czasTrwania = 10;
    //f.rok_premiery = 2008;

    //wywolanie klasy
    
    Film f2;
    f2.tytul = "xyz";
    f2.czasTrwania = 180;
    f2.rok_premiery = 1993;

    f.printData();
    f2.printData();

    //zamiast tego tragicznego zapisu kopiujemy to do konstruktora
    /*
    Film tab[100];
    for(int i = 0; i< 100; i++){
        tab[i].tytul = "Film_" + to_string(i);
        tab[i].czasTrwania = 30 + rand() % 91;
        tab[i].rok_premiery = 1980 + rand() % 50;
        //ponizsze rzeczy to gowno es
        //tab[i].dlugosc_rozdzialu = tab[i].czasTrwania / 10.f;
        //tab[i].tab = new float(tab[i].rokPremiery);
        //powyzsze rzeczy to gowno es
        tab[i].printData();
    }
    */

    /*
    Film tab[100]; // tutaj tworzy sto filmow, z bezargumentowym konstruktorem
    for(int i = 0; i< 100; i++){
        tab[i] = Film("Film_" + to_string(i)); // tutaj korzystamy z argumentowego
        tab[i].printData();
    }//tutaj tez sie dzieje cos tragicznego ale nie wiem jeszcze bo trzyma w napieciu;
     */

    Film *pf = new Film("ABCD",120,2020);

    pf->printData();
    //delete[] pf->tab; niepotrzebne teraz bo mamy destruktor
    delete pf;//ten delete niszczy pamiec zaalokowana dla klasy film, a nie to co film zaalokowal

    Film *tab = new Film[100];
    delete[] tab;


    
    //operacje na koncie
    /*
    KontoBankowe account2;
    KontoBankowe account;
    
    account.wplac(100);
    cout << "aktualna kwota: " << account.sprawdzKwote() << endl;

    cout << "Wyplacenie " << account.wyplac(50) << " zeta \n";

    cout << "aktualna kwota: " << account.sprawdzKwote() << endl;
    */


    return 0;
}
