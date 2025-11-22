#include<iostream>
using namespace std;
int *array_copy;

void merge(int array[], int left_index, int middle_index, int right_index){
  int left_copy = left_index;
  int middle_copy = middle_index+1;

  for (int i = left_index; i<=right_index;i++){
    array_copy[i] = array[i];
  } 
  
  for(int i = left_index;i<=right_index;i++){
    if(left_copy<=middle_index){
      if(middle_copy <= right_index){
        if(array_copy[middle_copy] < array_copy[left_copy]){
          array[i] = array_copy[middle_copy++];
        }else{
          array[i] = array_copy[left_copy++];
        }
      }else {
        array[i] = array_copy[left_copy++];
      }
    }else{
      array[i] = array_copy[middle_copy++];
    }
  }
}
void mergeSort(int array[], int left_index, int right_index){
  if (left_index == right_index){
    return;
  }
  int middle_index = (left_index+right_index)/2;

  mergeSort(array, left_index, middle_index);
  mergeSort(array, middle_index+1, right_index);

  merge(array,left_index,middle_index,right_index);
}



int main(){
  int number_of_elements;
  cout << "Number of elements: ";
  cin >> number_of_elements;

  int *array = new int[number_of_elements];
  array_copy = new int[number_of_elements];
  
  cout << "Type elements of the array\n";
  for(int i = 0;i<number_of_elements;i++){
    cin >> array[i];
  }

  mergeSort(array,0,number_of_elements-1);

  for(int i = 0;i<number_of_elements;i++){
    cout << array[i] << " ";
  }

  return 0;
}
