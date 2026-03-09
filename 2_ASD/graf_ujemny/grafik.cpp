#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

typedef struct node{
  map<int,int> mapa;

  node(){
    mapa[0] = 0;
  }
}node;

class graf{
  public:
    vector<node> lista;

    graf(){
      lista.push_back(node());
    }
};



int main(){
  graf grafik;
  

  return 0;
}
