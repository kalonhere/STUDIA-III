#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

typedef struct Node{
  int id;
  double OX;
  double OY;
} Node;

struct Tree{
  vector<Node> node_list;



  int add_node(){
    //open file
    ifstream file("data.csv");

    //check if file opened properly
    if(!file.is_open()){
      cout << "Blad odczytu pliku\n";
      return 0;
    }
    //read first line to skip it
    string null_buffer;
    getline(file,null_buffer);
    
    //fill nodes 
    int id;
    double ox;
    double oy;
    Node input_node;
    while(file >> id >> ox >> oy){
      input_node.id = id;
      input_node.OX = ox;
      input_node.OY = oy;
      node_list.push_back(input_node);

    }
    return 1;
  }
};




int main(){
  Tree tree;
  if(tree.add_node()){
    cout << "Dodano node'y\n";
  }


  return 0;
}
