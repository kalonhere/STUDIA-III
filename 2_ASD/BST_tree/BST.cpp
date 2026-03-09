#include<iostream>
using namespace std;

typedef struct node{
  node *leftptr;
  node *rightptr;
  int value;
}node;

class tree{
  public:
    node *root = nullptr;
  


    node *createNode(int value){
      node *nodeptr = new node;
      nodeptr->leftptr = nullptr;
      nodeptr->leftptr = nullptr;
      nodeptr->value = value;
      return nodeptr;
    }

    tree(int x){
      this->root = createNode(x);
    }

    node *insertNode(node *parent_ptr, int new_value){
      if((parent_ptr->value) > new_value){
        if(parent_ptr->leftptr == nullptr){
          parent_ptr->leftptr = createNode(new_value);
          return parent_ptr->leftptr;
        }else{
          insertNode(parent_ptr->leftptr, new_value);
        }//left
      }
      if((parent_ptr->value) < new_value){
        if(parent_ptr->rightptr == nullptr){
          parent_ptr->rightptr = createNode(new_value);
          return parent_ptr->rightptr;
        }else{
          insertNode(parent_ptr->rightptr, new_value);
        }//right
      }
      cout << "Podana wartosc juz jest w drzewie elo\n";
      return nullptr;
    }//insertNode
    
    node *findNode(node * parent_ptr,int searched){
      if((parent_ptr->value) == searched){
        return parent_ptr;
      }else if((parent_ptr -> value) > searched){
        return findNode(parent_ptr->leftptr, searched);
      }else{
        return findNode(parent_ptr->rightptr, searched);
      }
    }//find node

    void printInorder(node *parent_ptr){
      //left
      if(parent_ptr->leftptr != nullptr){
        printInorder(parent_ptr->leftptr);
      }
      cout << "Value:" << parent_ptr->value << endl;

      if(parent_ptr->rightptr != nullptr){
        printInorder(parent_ptr->rightptr);
      }

    }
      
};

int main(){
  tree drzewko(10);
  cout << "adres roota: "<< drzewko.root << endl;
  cout << "lewy child roota: "<< drzewko.root->leftptr << endl;
  cout << "prawy child roota: "<< drzewko.root->rightptr << endl;
  cout << "wartosc roota: "<< drzewko.root->value << endl;
  drzewko.insertNode(drzewko.root, 40);
  cout << "DODANO NODE 40\n";
  cout << "adres roota: "<< drzewko.root << endl;
  cout << "lewy child roota: "<< drzewko.root->leftptr << endl;
  cout << "prawy child roota: "<< drzewko.root->rightptr << endl;
  cout << "wartosc roota: "<< drzewko.root->value << endl;
  
  cout << "PRINT INORDER\n";
  drzewko.insertNode(drzewko.root, 8);
  drzewko.insertNode(drzewko.root, 4);
  drzewko.insertNode(drzewko.root, 23);
  drzewko.insertNode(drzewko.root, 50);
  drzewko.insertNode(drzewko.root, 1);
  drzewko.printInorder(drzewko.root);

  return 0;
}
