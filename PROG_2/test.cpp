#include<iostream>





int main(){
  int size = 5;
  int *arr_ptr = new int[size];
  std::cout << sizeof(*arr_ptr);



  return 0;
}
