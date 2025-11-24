#include <cstdlib>
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(){
  //ifstream file("./liczby.txt");
  ifstream file;
  file.open("./liczby.txt");
  int number_count;
  float number;
  float *number_array = nullptr;
  while(file >> number){
    //if number is integer
    if(number == (int)number){
      //if array is existing
      if(number_array != nullptr){
        // cout << "Znaleziono nowa linie:" << number;
        // exit(EXIT_SUCCESS);
        delete[] number_array;
      }//delete array if existing
      //print out numebr of elements and assign
      cout << "Ilosc elementow: "<<number << " ";
      number_count = number;
     // cout << "number count: "<<number_count << endl;
     // continue;
     // float *number_array = new float[number_count];
    }
    //if number is float
    if(number != (int)number){
      number_array = new float[number_count];
      for(int i = 0; i <= number_count; i++){
        if(i == (number_count-1)){number_array[i] = number; break;}
        number_array[i] = number;
        file >> number;
      }
      //find lowest value
      float minimum_value;
      int minimum_index;
      for(int i = 0; i< number_count;i++){
        if(i == 0){
          minimum_value = number_array[i];
          minimum_index = i;
        }
        if(i != 0){
          if(minimum_value > number_array[i]){
            minimum_value = number_array[i];
            minimum_index = i;
          }
        }
      }//FIND LOWEST VALUE 

      //print begin of array
      cout << "Array: {";
      for(int i = 0; i < number_count; i++){
        if(i == minimum_index){
          cout << "\033[1;34m" << number_array[i] << "\033[m ";
        }
        cout << number_array[i] << " ";
      }
      cout << "}";
      //print end of array
    }
    cout << endl;
  }

  return 0;
}
