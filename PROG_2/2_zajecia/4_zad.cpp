#include<iostream>
#include<string>
using namespace std;

int main(){
  cout << "Podaj napis:";
  string buffer;
  getline(cin,buffer);
  bool word_flag = false;
  int word_start;
  #ifdef DEBUG
    cout << "Podany napis: " << buffer << endl;
    cout << "dlugosc napisu: "<< buffer.length() << endl;
  #endif
  for(int i = 0;i < (buffer.length()-1); i++){
    if(word_flag == false && buffer[i] != ' '){
      word_flag = true;
      word_start = i;
    }
    if((word_flag == true && buffer[i] == ' ') || (word_flag == true && buffer[i+1] == 0)){
      cout << buffer.substr(word_start,(i-word_start)) << endl;
      word_flag = false;
    }

  }
  
  cout << buffer.substr(word_start,((buffer.length())-word_start)) << endl;
  

  return 0;
}
