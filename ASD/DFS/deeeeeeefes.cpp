#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

typedef enum kolor{
  BIALY = 1,
  SZARY = 2,
  CZARNY = 3
}kolor;


int skladowe = 0;

void dfsVisit(vector<vector<int>> &macierz, int rozmiar, int teraz, int poprzedni){
  //cout<<"Visiting: "<<teraz+1<<" from "<<poprzedni+1<<endl;
  for(int sasiad{}; sasiad < rozmiar; sasiad++){
    if(macierz[teraz][sasiad] == BIALY){
      macierz[teraz][sasiad] = SZARY;
      macierz[sasiad][teraz] = SZARY;
      dfsVisit(macierz, rozmiar, sasiad, teraz);
      macierz[teraz][sasiad] = CZARNY;
      macierz[sasiad][teraz] = CZARNY;
    }
  }
}

int main(){
  int n, wierz;
  cin >> n;
  string linia;
  getline(cin, linia);

  vector<int> wiersz;
  vector<vector<int>> macierz;

  for(int i{}; i < n; i++){
      wiersz.push_back(0);
  }
  for(int i{}; i < n; i++){
      macierz.push_back(wiersz);
  }

  for(int i{}; i < n; i++){
      getline(cin, linia);
      stringstream ss(linia);

      while((ss >> wierz) && (wierz > 0)){
          macierz[i][wierz - 1] = BIALY;
          macierz[wierz - 1][i] = BIALY;
      }
  }


  for(int i{}; i < n; i++){
      for(int j{}; j < n; j++){
          if(macierz[i][j] == 1){
              dfsVisit(macierz, n, i, j);
              skladowe++;
          }
      }
  }

  for(int i{}; i < n; i++){
      int polaczony = 0;
      for(int j{}; j < n; j++){
          if(macierz[i][j] > 0){
              polaczony = 1;
              break;
          }
      }
      if(!polaczony) skladowe++;
  }

  cout << skladowe << endl;

  return 0;
}
