#include<iostream>
using namespace std;

int main(){
  cout << "2 == prime";
  int menu;
  cin >> menu;
  if(menu == 2){
    int number = 29;
    for(int i = 2; i*i <=number;i++){
      if(number%i == 0){
        cout << "number is not prime";
        return 0;
      }
    }
    cout << "number is prime";
  }
  return 0;
}
