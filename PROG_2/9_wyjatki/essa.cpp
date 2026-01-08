#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;


class ujemnaLiczbaException : public exception{
  private:
    float v;
    string s;
  public:
    ujemnaLiczbaException(float v){
      this->v = v;
      s = "Liczba jest ujemna: " + to_string(v);
    }

    const char* what() const noexcept override{
      return s.c_str();
    }
};

float pierwiastek(float wartosc){
  if(wartosc < 0){
    //throw string("Ujemna liczba");
    throw ujemnaLiczbaException(wartosc);
  }
  return sqrt(wartosc);
}



void f1(){

  int value = rand()%10;
  if(value<5) throw string("Masz pecha");
}

void f2(){
  f1();
  int x = 5;
  throw x;
}


int main(){
  srand(time(NULL));
    
  vector<int> v = {1,2,3};

  try{
    v.at(10) = 123;
  }
  catch(out_of_range &e){
    cout << e.what() << endl;
  }



  cout << "\n\n\n";
  try{
    f2();
  }
  catch(int e){
    cout << "blad typu int: "<<e << endl;

  }
  catch(string e){
    cout << "blad typu string: "<<e << endl;
  }
  catch(...){
    cout << "Blad typu nie wiadomo: " << endl;
  }



  cout << "\n\n\n";
  try{
    cout << pierwiastek(10) << endl;
    cout << pierwiastek(-10) << endl;
  }
  catch(string &e){
    cout << "Wystapil blad: " << e << endl;
  }
  catch(ujemnaLiczbaException &e){
    cout << "Wystapil blad: " << e.what() << endl;
  }


  return 0;


}
