#include <iostream>
#include <string>



int main(){
  int menu = 0;
  bool debug;
  char debug_input;
  std::cout << "DEBUG? Y/N: "; std::cin >> debug_input;
  if(debug_input == 'Y' | debug_input == 'y'){debug = true;}
  if(debug_input == 'N' | debug_input == 'n'){debug = false;}
  std::cout << "1==most used letter ";
  std::cin >> menu;


  switch(menu){
    case 1:{
      std::string word;
      std::cout << "Type word: "; std::cin>>word;
      int alphabet[60] = {0};

      for (int i =0; i<(word.length()); i++){
        alphabet[ (int)(word[i]-65) ]++;
      }
       
      if(debug == true){
        for(int i = 0; i < 60; i++){
          std::cout << (char)(i+65) << ": " << alphabet[i] << "|    ";
          if((i+1)%5==0){
            std::cout << std::endl;
          }//newline if
        }//for
      }//if debug
      
      //find highest value
      int max_index = 0,max = 0,buffer = 0;
      for(int i = 0; i < 60; i++){
        if(alphabet[i] > max ){
        max_index = i;
        max = alphabet[i];
          if(debug == true){
          std::cout<< "new highest: " << (char)(i+65) << std::endl;
          }//debug
        }//new max
      }//for
      
      std::cout<<"most used letter: " << (char)(max_index+65) << ". It appeared "<<max<<" times." << std::endl;


      break;
    }//case1
  }//switch


  return 0;
}//main
