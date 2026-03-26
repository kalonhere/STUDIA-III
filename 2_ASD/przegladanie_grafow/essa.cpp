#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<queue>
using namespace std;


typedef enum COLOUR{
  WHITE = 0,
  GRAY = 1,
  BLACK = 2
} COLOUR;

#define TXT_GREEN "\033[32m"
#define TXT_YELLOW "\033[33m"
#define TXT_RESET "\033[m"

typedef struct edge{
  int source;
  int target;
  int weight;
  int flow;
    edge(int src, int trgt, int wght){
      source = src;
      target = trgt;
      weight = wght;
      flow = 0;
    }

} edge;

typedef struct node{
  int id;
  int colour;
  vector<edge> edges;

  node(int ajdi){
    id = ajdi;
    colour = WHITE;
  }
} node;


class graph{
  public:
  
    vector<node> node_list;
    vector<int> parent_vector;
    graph(){
      node_list.push_back(node(0));
    }

    void insertEdge(int src, int trgt, int wght){
        for(int i = 0; i < node_list.size(); i++){
          if(node_list.at(i).id == src){
            node_list.at(i).edges.push_back(edge(src,trgt,wght));
            //printf("dodawanie:\t\t (%d)\t-- %d -->\t(%d)\n",src,wght,trgt);
            cout << TXT_GREEN << "add:\t\t (" << src << ")\t-- " << wght << " -->\t(" << trgt << ")\n" << TXT_RESET;
            return;
          }
        }
        cout << TXT_YELLOW << "create:\t\t (" << src << ")\t-- " << wght << " -->\t(" << trgt << ")\n" << TXT_RESET;
        node_list.push_back(node(src));
        parent_vector.push_back(-1);
        node_list.back().edges.push_back(edge(src,trgt,wght));
    }

    void printStats(){
      cout << "node count: " << node_list.size() << endl;
      cout << "node IDs: ";
      for(int i = 0; i < node_list.size(); i++){
        cout << node_list.at(i).id;
      }
      cout << endl;
      cout << "edges count: ";
      int count = 0;
      for(int i = 0; i < node_list.size(); i++){
        count += node_list.at(i).edges.size();
      }
      cout << count << endl;

      cout << "Parent array: " << endl;
      for(int i = 0; i < parent_vector.size(); i++){
        cout << i << "<" << parent_vector.at(i);
      }
    }
    
    

    void BFS(int target){

      queue<int> q;
      int v;
      node_list.at(0).colour = GRAY;
      q.push(node_list.at(0).id);
      
      while(q.empty() == false){
        v = q.front();
        for(int i = 0; i < node_list.at(v).edges.size(); i++){
          int current_adj_id = node_list.at(v).edges.at(i).target;
          if(node_list.at(current_adj_id).colour == WHITE){
            node_list.at(current_adj_id).colour = GRAY;
            parent_array[current_adj_id] = v;
            q.push(current_adj_id);
          }
        }
        q.pop();
        node_list.at(v).colour = BLACK;
      }
    }

    ~graph(){
      delete[] parent_array;
    }
};


int main(){

  graph grafik; 
  //cout << grafik.node_list.size() << "node list size" << endl;
  //cout << grafik.node_list[0].edges.size() << "node list size" << endl;
  //cout << grafik.node_list[0].edges[0].source << "source" <<endl;
  //cout << grafik.node_list[0].edges[0].target << "target" <<endl;
  
  ifstream plik;
  plik.open("dane.txt");
  string buffer;
  while(getline(plik,buffer)){
    int src;
    int trgt;
    int weight;
    stringstream number(buffer);
    number >> src;
    number >> trgt;
    number >> weight;
    
    //printf("(%d)\t-- %d -->\t(%d)\n",src,weight,trgt);
    grafik.insertEdge(src,trgt,weight);
  }
  grafik.printStats();
  grafik.BFS(0);


  return 0;
}
