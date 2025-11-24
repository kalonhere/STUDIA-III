#include<iostream>
#include<fstream>
using namespace std;
int main(){
  ifstream file;
  file.open("./liczby.txt");
  int number_count;
  float number;
  float *array_ptr = nullptr;
  if((file >> number) == (int)number){
    if(array_ptr != nullptr){delete[] array_ptr;};
    number_count = number;
  }else{
    array_ptr = new float[number_count];
  }

  return 0;
}
