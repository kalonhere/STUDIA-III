#include<iostream>
using namespace std;

int main(){
  int number_of_floors;
  //cout << "number of floors: \n";
  cin >> number_of_floors;
  int numbers_limit = 0 ; 
  for(int i = 1; i <=number_of_floors;i++){numbers_limit = numbers_limit + i;}
  //cout << "numbers limit: "<<numbers_limit << endl;

  //cout << "type numbers: ";
  int *number_array = new int[numbers_limit+1];
  for(int i = 0; i <numbers_limit;i++){ cin >> number_array[i];}
  
  //for(int i = 0;i<numbers_limit;i++){
  //  cout << number_array[i] << " ";
  //}
  //cout << endl;
  int starting_index = numbers_limit-(number_of_floors+1);
  int current_floor = number_of_floors-1;

  while(1){

    for(int i = 0; i < current_floor;i++){
      if(number_array[starting_index+(current_floor)] > number_array[starting_index+(current_floor+1)]){
        //cout << "left: " << number_array[starting_index+(current_floor)] << " right: " << number_array[starting_index+(current_floor+1)] << endl;
        //cout << "starting index: " << starting_index << endl;
        //cout << "adding " << number_array[starting_index] << " and " << number_array[starting_index+(current_floor)] << "\n";
        number_array[starting_index] = number_array[starting_index] + number_array[starting_index+(current_floor)];
        //cout << "current value: " << number_array[starting_index];
        //cout << endl;
      }else{
        //cout << "left: " << number_array[starting_index+(current_floor)] << " right: " << number_array[starting_index+(current_floor+1)] << endl;
        //cout << "starting index: " << starting_index << endl;
        //cout << "adding " << number_array[starting_index] << " and " << number_array[starting_index+(current_floor+1)] << "\n";
        number_array[starting_index] = number_array[starting_index] + number_array[starting_index+(current_floor+1)];
        //cout << "current value: " << number_array[starting_index];
        //cout << endl;
      }
      //cout << endl;
      starting_index--;
      if(starting_index == -1){break;}
    }
    current_floor--;
    if(starting_index == -1 || current_floor == -1){break;}
  }
  cout << number_array[0];
  delete[] number_array;

  //for(int i = 0;i<numbers_limit;i++){
  // cout << number_array[i] << " ";
  //}

  //while(1){
  //  if(number_array[starting_index+(current_floor)] > number_array[starting_index+(current_floor+1)]){
  //    cout << "left: " << number_array[starting_index+(current_floor)] << " right: " << number_array[starting_index+(current_floor+1)] << endl;
  //    cout << "starting index: " << starting_index << endl;
  //    cout << "adding " << number_array[starting_index] << " and " << number_array[starting_index+(current_floor)] << "\n";
  //    number_array[starting_index] = number_array[starting_index] + number_array[starting_index+(current_floor)];
  //    cout << "current value: " << number_array[starting_index];
  //    cout << endl;
  //  }else{
  //    cout << "left: " << number_array[starting_index+(current_floor)] << " right: " << number_array[starting_index+(current_floor+1)] << endl;
  //    cout << "starting index: " << starting_index << endl;
  //    cout << "adding " << number_array[starting_index] << " and " << number_array[starting_index+(current_floor+1)] << "\n";
  //    number_array[starting_index] = number_array[starting_index] + number_array[starting_index+(current_floor+1)];
  //    cout << "current value: " << number_array[starting_index];
  //    cout << endl;
  //  }
  //  cout << endl;
  //  starting_index--;
  //  if(starting_index == -1){break;}
  //}

  return 0;
}
