#include<iostream>
#include <stdexcept>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

typedef struct edge{
  int target;
  int weight;
}edge;


typedef struct node{
  //dodac id wierzcholka bo nie ma jak dodac
  vector<edge> lista_krawedzi;
}node;


//vector od vector od edge (int int)
class graf{
  public:
    vector<node> lista;

    graf(){
      lista.push_back(node());
    }
};


void insertNode(graf grafik,int node_index, int target, int weight){
  try{
    grafik.lista[node_index].lista_krawedzi.push_back({target,weight});
  } catch (out_of_range){
    grafik.lista.push_back();
  }
}

int main(){
  graf grafik;
  string bufor;
  ifstream pliczek;
  pliczek.open("dane.txt");

  while(getline(pliczek, bufor)){

    stringstream ss(bufor);
    int node_index;
    int target;
    int weight;
    ss >> node_index;
    ss >> target;
    ss >> weight;
    
    insertNode(grafik,node_index,target,weight);


    //grafik.lista[0].lista_krawedzi.push_back({1,1});
    //cout << grafik.lista[0].lista_krawedzi[0].weight;
    //cout << "Node index: " << node_index << " target: " << target << " weight: " << weight << endl;
    
  }

   cout << " lista size: " << grafik.lista.size();
  return 0;
}
