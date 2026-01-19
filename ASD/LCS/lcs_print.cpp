#include<iostream>
#include <ostream>
#include<string>
using namespace std;





int main(){
  
  string X;
  string Y;
  cin >> X;
  cin >> Y;

  //length - 1 = [max_index];
  int x_array = X.length()+1;
  int y_array = Y.length()+1;
  int array[x_array][y_array];
  for(int i = 0; i<=X.length(); i++){
    array[i][0] = 0;
  }
  for(int i = 0; i<=Y.length(); i++){
    array[0][i] = 0;
  }

  for(int i = 1; i <= X.length(); i++){
    for(int j = 1; j <= Y.length(); j++){
      if(X[i-1] == Y[j-1]){
        array[i][j] = (array[i-1][j-1] + 1);
      }else{
        array[i][j] = max(array[i-1][j],array[i][j-1]);
      }
      
    }
  }
  cout << array[x_array-1][y_array-1] << endl;

  string result = "";
  int current_x = (x_array-1);
  int current_y = (y_array-1);
  while(current_x != 0 && current_y != 0){
    if(X[current_x-1] == Y[current_y-1]){
      result = X[current_x-1] + result;
      current_y--;
      current_x--;
    }else{
      if(array[current_x-1][current_y] > array[current_x][current_y-1]){
        current_x --;
      }else{
        current_y --;
      }
    }

  }
  cout << "subsequence: " << result << endl;
  return 0;
}
