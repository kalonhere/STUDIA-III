#include<iostream>

using namespace std;

typedef struct node{
  node *leftptr = nullptr;
  node *rightptr = nullptr;
  int value = 0;
} node;

node *insertNode(node *parent_ptr, int x){
  if((parent_ptr->value) < x){
    parent_ptr->rightptr = 
  }
};
int main(){
  node *root;


  return 0;
}
