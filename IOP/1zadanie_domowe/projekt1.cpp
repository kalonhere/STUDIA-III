#include<iostream>
using namespace std;

int main(){
  int menu;
  cout << "1==silnia" << endl << "2==prime";
  cin >> menu;
  if(menu == 1){
    int n = 9;
    int es = 1;
    for(int i = 1; i <= n; i ++){
      es = es * i;
    }
    cout << es << endl;
  }

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
