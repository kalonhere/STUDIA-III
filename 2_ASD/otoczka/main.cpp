#include<iostream>
#include<vector>
#include<fstream>
#include<utility>
#include<algorithm>
using namespace std;

typedef struct Node{
  int id;
  double OX;
  double OY;
} Node;

struct Tree{

  //vektor nodeow
  vector<Node> node_list;
  Node lowest_point;


  //print nodes in terminal
  void print_nodes(){
    for(int i = 0; i < node_list.size(); i++){
      cout << "ID: " << node_list[i].id << ", OX: " << node_list[i].OX << ", OY: " << node_list[i].OY << endl;
    }
  }

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
    while(file>>id>>ox>>oy){
      Node input_node;
      input_node.id = id;
      input_node.OX = ox;
      input_node.OY = oy;
      node_list.push_back(input_node);

    }
    return 1;
  }

  Node findStartingPoint(){
    lowest_point.OX = node_list[0].OX;
    lowest_point.OY = node_list[0].OY;
    for (int i = 1; i < node_list.size(); i++){
      if(node_list[i].OY < lowest_point.OY){ // y mniejsze
        lowest_point = node_list[i];
      }else if ((node_list[i].OY == lowest_point.OY) && (node_list[i].OX < lowest_point.OX)){
        lowest_point = node_list[i];
      }
    }//for
    
    cout << "Possible lowest point X: " << lowest_point.OX << " Y: " << lowest_point.OY << " ID: " << lowest_point.id << endl;
    swap(node_list[0],node_list[(lowest_point.id-1)]);
    return lowest_point;
  }//find starting point


  //void sortNodesAngle(){
  //  vector<Node> sorted_vectors = node_list;
  //  Node lowest_point_copy = lowest_point;    
  //  sort(node_list.begin(),node_list.end(),[lowest_point_copy](Node pi, Node pj){

  //      
  //      });

  //}
  
};//tree




int main(){
  Tree tree;
  if(tree.add_node()){
    cout << "Dodano node'y\n";
  }
  cout << "ilosc nodeo'w: " << tree.node_list.size() << endl;

  tree.print_nodes();
  tree.findStartingPoint(); 
  tree.print_nodes();
  return 0;
}
