#include<iostream>
using namespace std;
int main(){
  int menu;
  cout << "1==silnia" << endl;
  cin >> menu;
  if(menu == 1){
    int n = 9;
    int es = 1;
    for(int i = 1; i <= n; i ++){
      es = es * i;
    }
    cout << es << endl;
  }
}
