#include<iostream>
using namespace std;
class Rok{
public:
  int v;

  Rok(){
    this->v = 1950;
  }

  explicit Rok(int new_rok){
    this->v = new_rok;
  }
};

int main(){
  Rok Data1;
  Rok Data2(2000);

  cout << "Data 1: "<<Data1.v << "\n";
  cout << "Data 2: "<<Data2.v << "\n";

  Data1 = 2005;
  cout << "Data 1: "<<Data1.v << "\n";

  


}
