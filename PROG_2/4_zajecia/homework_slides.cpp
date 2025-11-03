#include <ctime>
#include<iostream>
#include <ostream>
#include<string>
#include<cstdlib>
#include<time.h>
using namespace std;

class Movie{
public:
  string movie_title;
  int movie_premiere_date;
  int movie_length;
  float chapter_length;
  float *float_pointer;

  bool XXIcent(){
    return this->movie_premiere_date > 2000;
  }

  void printData(){
    cout << "Title: " << this->movie_title << "| ";
    cout << "Premiere Date: " << this->movie_premiere_date << "| ";
    cout << "Length (minutes): " << this->movie_length << "| ";
    cout << "Chapter Length (minutes): " << this->chapter_length;
    if(float_pointer != nullptr){
      cout << "| Float Pointer Address: " << float_pointer;
    }else {cout << endl;}
  }


  Movie(){
    movie_title = "Movie";
    movie_premiere_date = 0;
    movie_length = 0;
    chapter_length=0;
    float_pointer = nullptr;
  }
  Movie(string new_title){
    movie_title = new_title;
    movie_length = rand() % 160 + 1;
    movie_premiere_date = rand() % 51 +1971;
    chapter_length = movie_length /10.f;
    float_pointer = new float[movie_premiere_date];
  }
  Movie(string new_title, int new_length, int new_premiere_date){
    movie_title = new_title;
    movie_length = new_length;
    movie_premiere_date = new_premiere_date;
    chapter_length = movie_length /10.f;
    float_pointer = new float[movie_premiere_date];
  }
  ~Movie(){
    cout << "DESTRUCTOR CALLED: deleting - " << float_pointer << "\n";
    delete[] float_pointer; 
  }
};

class BankingAccount{
public:
  int current_funds;

  int checkFunds(){
    return this->current_funds;
  };
  void deposit(int deposit_amount){
    if(this->current_funds += deposit_amount){
      cout << "Deposit Success\n";
    }else {cout << "Deposit Error\n";}
  };
  int withdrawal(int withdrawal_amount){
    if((withdrawal_amount * 1.05) <= this->current_funds){
      current_funds -= (withdrawal_amount*1.05);
      cout << "Withdrawal Success" << endl;
      return withdrawal_amount;
    }else{cout << "Withdrawal failure" << endl; return 0;}
  };
};

int main(){
  srand(time(NULL));
  //set movie 
  cout << "=====TEST MOVIE =====\n";
 // Movie movie_example;
 // movie_example.movie_title = "Essa";
 // movie_example.movie_premiere_date = 2004;
 // movie_example.movie_length = 120;
 // //methods
 // movie_example.printData();
 // movie_example.XXIcent();
  
  cout << "=====TEST BANKING ACCOUNT=====\n";
  BankingAccount acc_ex;
  acc_ex.current_funds = 500;
  acc_ex.deposit(100);
  cout << acc_ex.withdrawal(450) << "\n";

  cout << "=====TEST MOVIE ARRAY=====\n";
 // Movie movies_array[101];
 // for (int i = 0; i <100; i++){
 //   movies_array[i].movie_title = "Movie_" + (to_string(i));
 //   movies_array[i].movie_length = rand() % 160 + 1;
 //   movies_array[i].movie_premiere_date = rand() % 51 +1971;
 //   movies_array[i].chapter_length = movies_array[i].movie_length / 10.f;
 //   movies_array[i].float_pointer = new float(movies_array[i].movie_premiere_date);
 //   movies_array[i].printData();
 // }
 // cout << "=====TEST CONSTRICTOR USAGE=====\n";
 // Movie mov_ex_1;
 // mov_ex_1.printData();
 // Movie mov_ex_2("custom_title");
 // mov_ex_2.printData();
 // Movie mov_ex_3("CUSTOM_TITLE",135,1998);
 // mov_ex_3.printData();
  


  cout << "=====TEST MEMORY ISSUES=====\n";
 // Movie *movie_ptr = new Movie("idk",40,2025);
 // movie_ptr->printData();
 // delete movie_ptr;


//niewieeeeeem
  Movie *movie_ptr = new Movie[20];
  for(int i = 0;i<20;i++){
    
  }
  return 0;
}
