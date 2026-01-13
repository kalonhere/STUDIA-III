#include<iostream>
#include<memory>
using namespace std;
//automatyzacja zwalniania pamieci
//klasa automatycznie alokujaca bufor i niszcaca go

class Pointer{//w podobny sposob sa zaprojektowane smart pointery
  public:
    int n;
    int *ptr;
    Pointer(int n) : n(n){
      ptr = new int[n];
    }

    ~Pointer(){
      delete[] ptr;
    }
};

class Test {
  public:
    mutable int x; //ej to moze sie zmieniac nawet w const lol, niezalecane ale do testow
    int y;
};

//dynamic cast objekty
//

class Base {
  public:
    virtual void funkcja() const{}

};

class D1 : public Base{

};


class D2 : public Base{

};


//tutaj const pozwala na przedluzenie zycia dziala z l-value i r-value 
int func(const Test& x){
  return 2;
}

int main(){

  //template
  unique_ptr<Test> ptr = make_unique<Test>();
  ptr->x = 10;
  cout << ptr->x << endl;
  //blad ponizej 
  //unique_ptr<Test> ptr2 = ptr;
  //ale mozna: std::move;
  shared_ptr<Test> ptr_shared = make_shared<Test>();
  ptr_shared->x = 20;
  cout << ptr_shared->x << endl;
  cout << "use count: " << ptr_shared.use_count() << endl;

  weak_ptr<Test> wptr = ptr_shared;
  cout << "use count after shared pointer: " << ptr_shared.use_count() << endl;



  //rzutowanie w stylu cpp
  
  //classic rzutowanie
  float f = 3.14;
  int x0 = (int)f;
  int x = static_cast<int>(f);

  cout << "x0 = "<<x0 << endl;
  cout << "x = "<<x << endl;
  
  //const cast dodaje lub usuwa tag const
  const int *ptr_const = &x;
  int *ptr2 = const_cast<int*>(ptr_const);
  
  //dynamic cast
  Base *b = new D1();
  
  D1 *d1 = dynamic_cast<D1*>(b);
  
  //tutaj dostajemy adres na obiekt = rzutowanie pomyslne
  cout << d1 << endl;

  D2 *d2 = dynamic_cast<D2*>(b);
  //tutaj dostajemy nullptr bo rzutujemy D1 na D2
  cout << d2 << endl << "\n\n\n";

  
  //reinterpret cast najmniej zalecany najbardziej niebezpieczny

  //formatowanie cout
  cout << "COUT FORMATTING" << "\n";
  cout.flags();
  cout.setf(ios::hex, ios::basefield);

  cout << 15 << endl;
  cout << dec  << 15 << endl;
  cout << 15 << endl;

  //CONST

  //const przed nazwa zmiennej sprawie ze zmienna nie moze byc modyfikowana
  const int x_const = 5;
  // ne dziala lol, 
  //x_const = 10;
  int var = 1000;
  int varson = 12212;
  const int* ptr1 = &var; // nie mozna zmodyfikowac wartosci na ktora ten wskaznik wskazuje
  //*ptr1 = varson;
  int* const ptra2 = &var; //nie mozna zmienic adresu wskaznika
  const int* const ptra3 = &var; //nie mozna zmienic ani adresu ani wartosci

  int xessa = 10; // x = l-value, 10 = r-value

  //const jako referencja
  Test t;
  func(t);
  func(Test());

  //const do metody
  //patrz linia 31
  //zaznacza ze funkcja nie zmieni wartosci obiektu
  //jezeli ovverrideujemy metode ktora jest const to trzeba tez uzyc const, jest to element sygnatury
  return 0;
}
