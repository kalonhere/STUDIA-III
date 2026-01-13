#include<iostream>
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



int main(){




  return 0;
}
