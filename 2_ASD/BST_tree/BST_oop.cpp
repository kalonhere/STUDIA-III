#include<iostream>
using namespace std;

typedef struct node{
  node *leftptr;
  node *rightptr;
  int value;
}node;

class tree{
  public:
    node *root;
  
    node *createTree(int x){
      this->root->leftptr = nullptr;
      this->root->leftptr = nullptr;
      this->root->value = x;
      return root;
    }

    node *insertNode(node *parent_ptr, int new_value){
      if((parent_ptr->value) > new_value){
        if((parent_ptr->leftptr) != nullptr){cout << "Blad dodania wezla\n";};
        parent_ptr->leftptr = new node;
        parent_ptr->leftptr->value = new_value;
        return (parent_ptr->leftptr);


      }else if((parent_ptr->value) < new_value){
        if((parent_ptr->rightptr) != nullptr){cout << "Blad dodania wezla\n";};
        parent_ptr->rightptr = new node;
        parent_ptr->rightptr->value = new_value;
        return (parent_ptr->rightptr);


      }else{
        cout << "Blad dodania wezla (wezel posiada taka sama wartosc)";
      }
    }
};

int main(){



  return 0;
}
