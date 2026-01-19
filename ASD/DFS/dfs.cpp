#include<iostream>
#include <ostream>
using namespace std;

typedef enum KOLOR{
  BIALY,
  SZARY,
  CZARNY
}KOLOR;


int main(){
  int wierzcholki;
  cin >> wierzcholki; 
  string buffer;
  int array[wierzcholki-1][wierzcholki-1];
  for (int i = 0; i <= wierzcholki-1; i++){
    for (int j = 0; j <= wierzcholki-1; j++){
      array[i][j] = 0;
    }
  }
  for (int i = 0; i <= wierzcholki-1; i++){
      cin >> buffer;
    for (int j = 0; j <= buffer.length()-1; j++){

      if(buffer[j] > '0' || buffer[j] <= '9'){
        cout << "znaleziono cyferke " << buffer[j] << endl;
        array[i][(buffer[j] - '0')] = 1;
      }
    }
  }
  for (int i = 0; i <= wierzcholki-1; i++){
    for (int j = 0; j <= wierzcholki-1; j++){
      cout << array[i][j] << " ";
    }
    cout << endl;
  }





  return 0;
}
