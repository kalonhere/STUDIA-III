#include<iostream>
#include<vector>
#include<fstream>
#include<utility>
#include<algorithm>
#include<stack>
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
    cout << "\nPrinting node_list\n";
    for(int i = 0; i < node_list.size(); i++){
      cout << "ID: " << node_list[i].id << ", OX: " << node_list[i].OX << ", OY: " << node_list[i].OY << endl;
    }
    cout << "\n\n";
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


  void sortNodesAngle(){
    vector<Node> sorted_vectors = node_list;
    Node p0 = lowest_point;
    cout << "enter\n";
    sort(sorted_vectors.begin() + 1,sorted_vectors.end(),[p0](Node pi, Node pj){
          double determinant = (((pi.OX - p0.OX)*(pj.OY - p0.OY)) - ((pj.OX - p0.OX)*(pi.OY - p0.OY)));
          //return a < b sorts in ascending order 
          if(determinant > 0){
            cout << "determinant: " << determinant << endl;
            return true;
          }else {
            cout << "determinant: " << determinant << endl;
            return false;
          }
        });
    cout << "exit\n";
    for(int i = 0; i < sorted_vectors.size(); i++){
      cout << "ID: " << sorted_vectors[i].id << ", OX: " << sorted_vectors[i].OX << ", OY: " << sorted_vectors[i].OY << endl;
    }
    cout << "\n\n";
    node_list = sorted_vectors;
  }
  
  double calculateDeterminant(Node p0, Node pi, Node pj){
    double determinant = (((pi.OX - p0.OX)*(pj.OY - p0.OY)) - ((pj.OX - p0.OX)*(pi.OY - p0.OY)));
    return determinant;
  }

  void createOtoczka(){
    vector<Node> node_stack;
    node_stack.push_back(node_list[0]);
    node_stack.push_back(node_list[1]);
    node_stack.push_back(node_list[2]);
    cout << " size of stack: " << node_stack.size() << endl; //3
    cout << "-1 element: "  << node_stack.at(node_stack.size()-2).id << endl;
    for(int i = 3; i < node_list.size(); i++){
      while((double determinant = calculateDeterminant(node_stack.at(node_stack.size()-2), node_stack.back(), node_list.at(i))) > 0){
        node_stack.pop_back();
      }
      if (determinant < 0){
        node_stack.push_back(node_list.at(i));
      }
    }
  }

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
  tree.sortNodesAngle();
  tree.createOtoczka();
  return 0;
}
